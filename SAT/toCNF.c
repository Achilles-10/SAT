#include "toCNF.h"
#include <math.h>
#include <stdlib.h>

//将九进制数转化为十进制数（仅限三位九进制数）
int nine_to_ten(int nine) {
	int ten = 0;
	for (int i = 0; i < 3; ++i) {
		ten += (nine % 10) * pow(9, i);
		nine /= 10;
	}
	return ten;
}

/* 对一个数字编码
 * 111 => 000 => 0 => 1
 * 999 => 888 => 728 => 729
 * */
int encoding(int n) {
	int result = nine_to_ten(n - 111);
	return result + 1;
}

//对整个数独编码
sudoku *sudoku_encoding(sudoku *sudo) {
	sudoku *new_s = sudoku_init();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (sudo->field[i][j] == 0) continue;
			new_s->field[i][j] = encoding(
					(i + 1) * 100 + (j + 1) * 10 + sudo->field[i][j]);
		}
	}
	return new_s;
}

//将一个数独转化为cnf方程
formula *sudoku_to_formula(sudoku *sudo) {
	formula *f = sudoku_base_formula();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (sudo->field[i][j] == 0) continue;
			vector *v = vec_init();
			int value = sudo->field[i][j];
			vec_add(v, 2 * (value - 1));
			f->frequency->data[value - 1]++;
			f->polarity->data[value - 1]++;
			clau_add(f->clauses, v);
		}
	}
	return f;
}

//用八个约束方程生成数独基本cnf方程
formula *sudoku_base_formula() {
	formula *f = form_init();
	f->literal_num = 729;
	f->clause_num = 11988;
	f->answers = vec_init();
	f->frequency = vec_init();
	f->polarity = vec_init();
	vec_resize(f->answers, f->literal_num, -1);
	vec_resize(f->frequency, f->literal_num, 0);
	vec_resize(f->polarity, f->literal_num, 0);
	f->clauses = clau_init();
	exist_entry(f);
	unique_entry(f);
	exist_row(f);
	unique_row(f);
	exist_column(f);
	unique_column(f);
	exist_block(f);
	unique_block(f);
	return f;
}

//每个格子至少有一个数
void exist_entry(formula *f) {
	for (int x = 1; x < 10; ++x) {
		for (int y = 1; y < 10; ++y) {
			vector *v = vec_init();
			for (int z = 1; z < 10; ++z) {
				int value = encoding(x * 100 + y * 10 + z);//临时储存编码后的值
				vec_add(v, 2 * (value - 1));//按储存map加入vec
				f->frequency->data[value - 1]++;
				f->polarity->data[value - 1]++;
			}
			clau_add(f->clauses, v);
		}
	}
}

//每个格子至多一个数
void unique_entry(formula *f) {
	for (int x = 1; x < 10; ++x) {
		for (int y = 1; y < 10; ++y) {
			for (int z = 1; z < 9; ++z) {
				for (int i = z + 1; i < 10; ++i) {
					vector *v = vec_init();
					int value1 = -encoding(x * 100 + y * 10 + z);
					int value2 = -encoding(x * 100 + y * 10 + i);
					vec_add(v, 2 * (-value1 - 1) + 1);
					vec_add(v, 2 * (-value2 - 1) + 1);
					f->frequency->data[value1 - 1]++;
					f->polarity->data[value1 - 1]--;
					f->frequency->data[value2 - 1]++;
					f->polarity->data[value2 - 1]--;
					clau_add(f->clauses, v);
				}
			}
		}
	}
}

//每行至少有一个数
void exist_row(formula *f) {
	for (int y = 1; y < 10; ++y) {
		for (int z = 1; z < 10; ++z) {
			vector *v = vec_init();
			for (int x = 1; x < 10; ++x) {
				int value = encoding(x * 100 + y * 10 + z);
				vec_add(v, 2 * (value - 1));
				f->frequency->data[value - 1]++;
				f->polarity->data[value - 1]++;
			}
			clau_add(f->clauses, v);
		}
	}
}

//每行至多一个数
void unique_row(formula *f) {
	for (int y = 1; y < 10; ++y) {
		for (int z = 1; z < 10; ++z) {
			for (int x = 1; x < 9; ++x) {
				for (int i = x + 1; i < 10; ++i) {
					vector *v = vec_init();
					int value1 = -encoding(x * 100 + y * 10 + z);
					int value2 = -encoding(i * 100 + y * 10 + z);
					vec_add(v, 2 * (-value1 - 1) + 1);
					vec_add(v, 2 * (-value2 - 1) + 1);
					f->frequency->data[value1 - 1]++;
					f->polarity->data[value1 - 1]--;
					f->frequency->data[value2 - 1]++;
					f->polarity->data[value2 - 1]--;
					clau_add(f->clauses, v);
				}
			}
		}
	}
}

//每列至少有一个数
void exist_column(formula *f) {
	for (int x = 1; x < 10; ++x) {
		for (int z = 1; z < 10; ++z) {
			vector *v = vec_init();
			for (int y = 1; y < 10; ++y) {
				int value = encoding(x * 100 + y * 10 + z);
				vec_add(v, 2 * (value - 1));
				f->frequency->data[value - 1]++;
				f->polarity->data[value - 1]++;
			}
			clau_add(f->clauses, v);
		}
	}
}

//每列至多一个数
void unique_column(formula *f) {
	for (int x = 1; x < 10; ++x) {
		for (int z = 1; z < 10; ++z) {
			for (int y = 1; y < 9; ++y) {
				for (int i = y + 1; i < 10; ++i) {
					vector *v = vec_init();
					int value1 = -encoding(x * 100 + y * 10 + z);
					int value2 = -encoding(x * 100 + i * 10 + z);
					vec_add(v, 2 * (-value1 - 1) + 1);
					vec_add(v, 2 * (-value2 - 1) + 1);
					f->frequency->data[value1 - 1]++;
					f->polarity->data[value1 - 1]--;
					f->frequency->data[value2 - 1]++;
					f->polarity->data[value2 - 1]--;
					clau_add(f->clauses, v);
				}
			}
		}
	}
}

//每个小方格至少有一个数
void exist_block(formula *f) {
	for (int z = 1; z < 10; ++z) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				vector *v = vec_init();
				for (int x = 1; x < 4; ++x) {
					for (int y = 1; y < 4; ++y) {
						int value = encoding((3 * i + x) * 100 + (3 * j + y) * 10 + z);
						vec_add(v, 2 * (value - 1));
						f->frequency->data[value - 1]++;
						f->polarity->data[value - 1]++;
					}
				}
				clau_add(f->clauses, v);
			}
		}
	}
}

//每个小九宫格至多一个数
void unique_block(formula *f) {
	for (int z = 1; z < 10; ++z) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int x = 1; x < 4; ++x) {
					for (int y = 1; y < 4; ++y) {
						for (int k = y + 1; k < 4; ++k) {
							vector *v = vec_init();
							int value1 = -encoding(
									(3 * i + x) * 100 + (3 * j + y) * 10 + z);
							int value2 = -encoding(
									(3 * i + x) * 100 + (3 * j + k) * 10 + z);
							vec_add(v, 2 * (-value1 - 1) + 1);
							vec_add(v, 2 * (-value2 - 1) + 1);
							f->frequency->data[value1 - 1]++;
							f->polarity->data[value1 - 1]--;
							f->frequency->data[value2 - 1]++;
							f->polarity->data[value2 - 1]--;
							clau_add(f->clauses, v);
						}
						for (int k = x + 1; k < 4; ++k) {
							for (int l = 1; l < 4; ++l) {
								vector *v = vec_init();
								int value1 = -encoding(
										(3 * i + x) * 100 + (3 * j + y) * 10 + z);
								int value2 = -encoding(
										(3 * i + k) * 100 + (3 * j + l) * 10 + z);
								vec_add(v, 2 * (-value1 - 1) + 1);
								vec_add(v, 2 * (-value2 - 1) + 1);
								f->frequency->data[value1 - 1]++;
								f->polarity->data[value1 - 1]--;
								f->frequency->data[value2 - 1]++;
								f->polarity->data[value2 - 1]--;
								clau_add(f->clauses, v);
							}
						}
					}
				}
			}
		}
	}
}

//将cnf方程写入文件
void form_write(formula *f, const char *filename) {
	FILE *fp;
	if ((fp = fopen(filename, "w+")) == NULL) {//打开文件失败
		printf("Fail to load file:\"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "c\np cnf %d %d", f->literal_num, f->clauses->size);
	for (int i = 0; i < f->clauses->size; ++i) {
		fprintf(fp, "\n");
		for (int j = 0; j < f->clauses->clause[i]->size; ++j) {
			int temp = f->clauses->clause[i]->data[j];
			fprintf(fp, "%d ", (temp % 2) ? (-temp) / 2 - 1 : temp / 2 + 1);
		}
		fprintf(fp, "0");
	}
	fclose(fp);
}

/* 将结果写入同名.res文件
 * s 求解结果    1表示满足，0表示不满足，-1未定
 * v -1 2 -3 …  满足时，每个变元的赋值序列，-1表示第一个变元1取假，2表示第二个变元取真，用空格分开。
 * t 17         以毫秒为单位的DPLL执行时间，可增加分支规则执行次数信息
 * */
void result_write(formula *f, const char *filename, double time) {
	FILE *fp;
	if ((fp = fopen(filename, "w+")) == NULL) {//打开文件失败
		printf("Fail to load file:\"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}
	fprintf(fp,"s %d\n",f->result);
	if (f->result == true) {
		fprintf(fp,"v ");
		for (int i = 0; i < f->answers->size; ++i) {
			if (i) fprintf(fp," ");
			if (f->answers->data[i] != -1)
				fprintf(fp,"%d", -(int) pow(-1, f->answers->data[i]) * (i + 1));
			else fprintf(fp,"%d", i + 1);//此时该变元真值可任取
		}
		fprintf(fp,"\nt %fms",time);
	}
	fclose(fp);
}