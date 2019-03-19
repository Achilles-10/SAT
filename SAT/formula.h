#ifndef SAT_FORMULA_H
#define SAT_FORMULA_H

#include <stdio.h>
#include "vec.h"
#include "clauses.h"

#define true (1)
#define false (0)
#define undecided (-1)

enum flag {
	satisfied,      //满足条件
	unsatisfied,    //不满足条件
	normal,         //暂时不满足条件或DPLL正常退出
	completed       //DPLL操作完成
};

typedef struct formular_ {
	int clause_num;
	int literal_num;
	int result;
	vector *answers;    //  -1 - 待定
	//   0 - 真值为假
	//   1 - 真值为真
	vector *frequency;  //变元频率
	vector *polarity;   //变元极性：(正数)-(负数)
	clau *clauses;
} formula;

FILE *load(const char *filename);//读取文件

formula *form_init();//初始化

formula *form_load(const char *filename);//从文件初始化

formula *form_copy(const formula *f);//拷贝formula

void form_free(formula *f);//释放空间

int unit_propagate(formula *f);//单子句操作

int apply_transform(formula *f, int literal);//单文字操作

int DPLL(formula *f, int flag);//递归调用DPLL,flag=1顺序选取变元，否则选取频率最大的

void result_show(formula *f, int result);//显示结果

void solve(formula *f, int flag);//flag=1顺序选取变元，否则选取频率最大的

#endif //SAT_FORMULA_H
