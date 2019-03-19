#ifndef SAT_TOCNF_H
#define SAT_TOCNF_H

#include "sudoku.h"
#include "clauses.h"
#include "formula.h"

int nine_to_ten(int nine);//将九进制数转化为十进制数（仅限三位九进制数）

int encoding(int n);//对一个数字编码

sudoku *sudoku_encoding(sudoku *sudo);//对整个数独编码

formula *sudoku_to_formula(sudoku *sudo);//将一个数独转化为cnf方程

formula *sudoku_base_formula();//用八个约束方程生成数独基本cnf方程

void exist_entry(formula *f);//每个格子至少有一个数

void unique_entry(formula *f);//每个格子至多一个数

void exist_row(formula *f);//每行至少有一个数

void unique_row(formula *f);//每行至多一个数

void exist_column(formula *f);//每列至少有一个数

void unique_column(formula *f);//每列至多一个数

void exist_block(formula *f);//每小方格至少有一个数

void unique_block(formula *f);//每个小九宫格至多一个数

void form_write(formula *f, const char *filename);//将cnf方程写入文件

void result_write(formula *f, const char *filename, double time);//将结果写入同名.res文件

#endif //SAT_TOCNF_H
