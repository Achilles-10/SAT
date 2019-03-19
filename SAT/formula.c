#include "formula.h"
#include <stdlib.h>
#include <math.h>
#include <windows.h>

//读取文件
FILE *load(const char *filename) {
	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL) {//打开文件失败
		printf("Fail to load file:\"%s\"\n", filename);
		printf("\nEnter to exit\n");
		getchar();
		exit(EXIT_FAILURE);
	}
	return fp;
}

//初始化formula
formula *form_init() {
	formula *f = (formula *) malloc(sizeof(formula));
	f->clause_num = 0;
	f->literal_num = 0;
	f->result = undecided;
	f->answers = NULL;
	f->frequency = NULL;
	f->polarity = NULL;
	f->clauses = NULL;
	return f;
}

/* 从文件初始化formula
 * 通过map来储存 literal: 1 -1 2 -2 3 -3   正数y=2x-2
 *                 储存: 0  1 2  3 4  5   负数y=-2x-1
 * */
formula *form_load(const char *filename) {
	FILE *fp = load(filename);
	int literal_num, clause_num;
	char buffer[BUFSIZ];//512
	while (!feof(fp)) {
		fgets(buffer, sizeof(buffer) - 1, fp);
		if (buffer[0] == 'c') continue;
		else if (buffer[0] == 'p') {
			sscanf(buffer, "%*s %*s %d %d", &literal_num, &clause_num);
//			printf("Successfully load the number of liters and claus\n");
			break;
		}
	}
	formula *f = form_init();
	f->clause_num = clause_num;
	f->literal_num = literal_num;
	f->answers = vec_init();
	f->frequency = vec_init();
	f->polarity = vec_init();
	vec_resize(f->answers, f->literal_num, -1);
	vec_resize(f->frequency, f->literal_num, 0);
	vec_resize(f->polarity, f->literal_num, 0);
	f->clauses = clau_init();
	while (!feof(fp)) {
		int literal;//暂存读入的数字
		vector *vec = vec_init();//临时子句
		while (1) {
			fscanf(fp, "%d", &literal);
			if (!literal) break;
			else if (literal > 0) {//改变频率和极性
				vec_add(vec, 2 * (literal - 1));
				f->frequency->data[literal - 1]++;
				f->polarity->data[literal - 1]++;
			}
			else {
				vec_add(vec, 2 * (-literal - 1) + 1);
				f->frequency->data[-literal - 1]++;
				f->polarity->data[-literal - 1]--;
			}
		}
		clau_add(f->clauses, vec);
		vec_free(vec);
	}
	clau_resize(f->clauses, clause_num);//删去末尾多读的子句
	fclose(fp);
	return f;
}

//拷贝formula
formula *form_copy(const formula *f) {
	formula *new_f = (formula *) malloc(sizeof(formula));
	new_f->clause_num = f->clause_num;
	new_f->literal_num = f->literal_num;
	new_f->result = f->result;
	new_f->answers = vec_copy(f->answers);
	new_f->frequency = vec_copy(f->frequency);
	new_f->polarity = vec_copy(f->polarity);
	new_f->clauses = clau_copy(f->clauses);
	return new_f;
}

//释放空间
void form_free(formula *f) {
	clau_free(f->clauses);
	vec_free(f->answers);
	vec_free(f->frequency);
	vec_free(f->polarity);
	free(f);
}

//单子句传递
int unit_propagate(formula *f) {
	int unit_found = false;//   0-false 1-true
	if (f->clauses->size == 0) return satisfied;//空集满足
	do {
		unit_found = false;
		for (int i = 0; i < f->clauses->size; ++i) {
			if (f->clauses->clause[i]->size == 1) {
				unit_found = true;
				int temp_literal = f->clauses->clause[i]->data[0];//临时储存文字
				f->answers->data[temp_literal / 2] = (temp_literal % 2) ? false
				                                                        : true; //temp_literal/2为变元索引
				f->frequency->data[temp_literal / 2] = -1;//一旦answer里对应变元真值确定，频率置为-1
				int result = apply_transform(f, temp_literal / 2);//用该单文字化简formula
				if (result == satisfied || result == unsatisfied) return result;
				break;//退出当前循环对下一单句进行相同操作
			}
			else if (f->clauses->clause[i]->size == 0) return unsatisfied; // 出现空句则不满足
		}
	} while (unit_found);
	return normal;//若执行到这一步，则单子句操作正常结束
}

//单文字操作
int apply_transform(formula *f, int literal) {
	int value = f->answers->data[literal];//value为对应变元真值
	int add_value = (value == true) ? 0 : 1;
	for (int i = 0; i < f->clauses->size; ++i) {//遍历每一子句
		for (int j = 0; j < f->clauses->clause[i]->size; ++j) {//遍历子句里的每一文字
			if (f->clauses->clause[i]->data[j] ==
			    2 * literal + add_value) {//单句里含有该文字,则去除当前单句
				clau_erase(f->clauses, i);
				i--;
				if (f->clauses->size == 0) return satisfied;//若此时为空集，则满足
				break;//对下一子句进行操作
			}
			else if (f->clauses->clause[i]->data[j] / 2 == literal) {//单句里对应文字真值为假，则删除该文字
				vec_erase(f->clauses->clause[i], j);
				j--;
				if (f->clauses->clause[i]->size == 0) return unsatisfied;//若此时为空句，则不满足
				break;
			}
		}
	}
	return normal;
}

//递归调用DPLL,flag=1顺序选取变元，否则选取频率最大的
int DPLL(formula *f, int flag) {
	int result = unit_propagate(f);
	if (result == satisfied) {//满足则显示结果并退出
		result_show(f, result);
		return completed;
	}
	else if (result == unsatisfied) return normal;//若不满足则退出
	int i;

	if (flag == 1) {
		for (int k = 0; k < f->literal_num; ++k) {
			if (f->frequency->data[k] > 0) {
				i = k;
				break;
			}
		}//依次选取变元,针对数独更快
	}
	else i = vec_getMax(f->frequency);//频率最大元素的索引

	for (int j = 1; j > -1; --j) {//真值为真和假两次操作
		formula *new_f = form_copy(f);
		if (new_f->polarity->data[i] > 0) new_f->answers->data[i] = j;//极性为正则true
		else new_f->answers->data[i] = (j + 1) % 2;//极性为负则false
		new_f->frequency->data[i] = -1;
		int transform_result = apply_transform(new_f, i);//利用频率最高的变元对formula化简
		if (transform_result == satisfied) {
			result_show(new_f, transform_result);
			form_free(new_f);
			return completed;
		}
		else if (transform_result == unsatisfied) {
			form_free(new_f);
			continue;
		}//改变真值回溯
		int dpll_result = DPLL(new_f,flag); //递归调用
		if (dpll_result == completed) {
			form_free(new_f);
			return completed;
		}
	}
	return normal;
}

//显示结果
void result_show(formula *f, int result) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,0x7);
	if (result == satisfied) {
		f->result = true;
		printf("SAT\n");
		for (int i = 0; i < f->answers->size; ++i) {
			if (i) printf(" ");
			if (f->answers->data[i] != -1)
				printf("%d", -(int) pow(-1, f->answers->data[i]) * (i + 1));
			else printf("%d", i + 1);//此时该变元真值可任取
		}
		printf(" 0\n");
	}
	else {
		f->result = false;
		printf("UNSAT\n");
	}
}

//求解formula
void solve(formula *f, int flag) {
	int result = DPLL(f,flag);
	if (result == normal) result_show(f, unsatisfied);
}