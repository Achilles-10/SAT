#ifndef SAT_SUDOKU_H
#define SAT_SUDOKU_H

typedef struct sudoku_ {
	int field[9][9];
	int row[9][10];
	int column[9][10];
	int block[9][10];
} sudoku;

sudoku *sudoku_init();//初始化一个数独

sudoku *sudoku_copy(sudoku *sudo);//拷贝一个数独

void swap_row(sudoku *sudo, int r1, int r2);//交换两行

void swap_column(sudoku *sudo, int c1, int c2);//交换两列

void sudoku_show(sudoku *sudo);//输出数独

void sudoku_free(sudoku *sudo);//释放一个数独空间

void set_value(sudoku *sudo, int i, int j, int value);//给数独赋值

int sudoku_solve(sudoku *sudo);//求解数独

int lasVegas(sudoku *sudo, int n);//用拉斯维加斯算法生成一个完整数独, n为初始随机填充的数目

//void sequence_dig(sudoku *sudo, int level);//挖洞生成数独初始局面，level为剩余数字数目

void random_dig(sudoku *sudo, int level);//随机挖洞,level>24时使用

int unique(sudoku *sudo, int i, int j);//挖掉(i,j)位置是否有唯一解，若(i,j)为空则返回false

int block_num(int i, int j);//第几个方块

#endif //SAT_SUDOKU_H
