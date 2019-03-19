#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define true (1)
#define false (0)

/* 初始化一个数独
 * row[1][7] = true => 第二行已存在7这个数
 * */
sudoku *sudoku_init() {
	sudoku *sudo = (sudoku *) malloc(sizeof(sudoku));
	for (int i = 0; i < 9; ++i) {//初始化数组
		for (int j = 0; j < 9; ++j) {
			sudo->field[i][j] = 0;
			sudo->row[i][j + 1] = false;
			sudo->column[i][j + 1] = false;
			sudo->block[i][j + 1] = false;
		}
	}
	return sudo;
}

//拷贝一个数独
sudoku *sudoku_copy(sudoku *sudo) {
	sudoku *new_sudo = (sudoku *) malloc(sizeof(sudoku));
	for (int i = 0; i < 9; ++i) {//初始化数组
		for (int j = 0; j < 9; ++j) {
			new_sudo->field[i][j] = sudo->field[i][j];
			new_sudo->row[i][j + 1] = sudo->row[i][j + 1];
			new_sudo->column[i][j + 1] = sudo->column[i][j + 1];
			new_sudo->block[i][j + 1] = sudo->block[i][j + 1];
		}
	}
	return new_sudo;
}

/* 交换两行
 * 三四行禁止交换，六七行禁止交换 */
void swap_row(sudoku *sudo, int r1, int r2) {
	if ((r1 == 2 && r2 == 3) || (r1 == 3 && r2 == 2) || (r1 == 5 && r2 == 6) ||
	    (r1 == 6 && r2 == 5)) {
		return;
	}
	int temp_value;//临时存储一行
	int temp_row[10];
	int temp_column[10];
	int temp_block[10];
	for (int j = 0; j < 9; ++j) {
		temp_value = sudo->field[r2][j];
		sudo->field[r2][j] = sudo->field[r1][j];
		sudo->field[r1][j] = temp_value;
	}
	for (int n = 1; n < 10; ++n) {
		temp_row[n] = sudo->row[r2][n];
		sudo->row[r2][n] = sudo->row[r1][n];
		sudo->row[r1][n] = temp_row[n];
	}
}

/* 交换两列
 * 三四列禁止交换，六七列禁止交换 */
void swap_column(sudoku *sudo, int c1, int c2) {
	if ((c1 == 2 && c2 == 3) || (c1 == 3 && c2 == 2) || (c1 == 5 && c2 == 6) ||
	    (c1 == 6 && c2 == 5)) {
		return;
	}
	int temp_value;//临时存储一行
	int temp_column[10];
	for (int i = 0; i < 9; ++i) {
		temp_value = sudo->field[i][c2];
		sudo->field[i][c2] = sudo->field[i][c1];
		sudo->field[i][c1] = temp_value;
	}
	for (int n = 1; n < 10; ++n) {
		temp_column[n] = sudo->column[c2][n];
		sudo->column[c2][n] = sudo->column[c1][n];
		sudo->column[c1][n] = temp_column[n];
	}
}

/* 输出数独
 * -------------------
 * |0 0 0|0 0 0|0 0 0|
 * |0 0 0|0 0 0|0 0 0|
 * |0 0 0|0 0 0|0 0 0|
 * -------------------
 * |0 0 0|0 0 0|0 0 0|
 * |0 0 0|0 0 0|0 0 0|
 * |0 0 0|0 0 0|0 0 0|
 * -------------------
 * |0 0 0|0 0 0|0 0 0|
 * |0 0 0|0 0 0|0 0 0|
 * |0 0 0|0 0 0|0 0 0|
 * -------------------
 * */
void sudoku_show(sudoku *sudo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x7);
	printf("\t");
	for (int i = 0; i < 13; ++i) {
		if (i == 0 || i == 4 || i == 8 || i == 12)
			printf("-------------------\n\t");
		else if (i < 4) {
			for (int j = 0; j < 9; ++j) {
				int value = sudo->field[i - 1][j];
				if (j == 0 || j == 3 || j == 6) {
					if (value) printf("|%d", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf("|+");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
				else if (j == 8) {
					if (value) printf(" %d|\n\t", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf(" +|\n\t");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
				else {
					if (value) printf(" %d", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf(" +");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
			}
		}
		else if (i < 8) {
			for (int j = 0; j < 9; ++j) {
				int value = sudo->field[i - 2][j];
				if (j == 0 || j == 3 || j == 6) {
					if (value) printf("|%d", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf("|+");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
				else if (j == 8) {
					if (value) printf(" %d|\n\t", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf(" +|\n\t");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
				else {
					if (value) printf(" %d", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf(" +");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
			}
		}
		else {
			for (int j = 0; j < 9; ++j) {
				int value = sudo->field[i - 3][j];
				if (j == 0 || j == 3 || j == 6) {
					if (value) printf("|%d", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf("|+");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
				else if (j == 8) {
					if (value) printf(" %d|\n\t", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf(" +|\n\t");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
				else {
					if (value) printf(" %d", value);
					else {
						SetConsoleTextAttribute(hConsole, 0xC);
						printf(" +");
						SetConsoleTextAttribute(hConsole, 0x7);
					}
				}
			}
		}
	}
	printf("\n");
}

/* 将第i行j列设置为value
 * */
void set_value(sudoku *sudo, int i, int j, int value) {
	if (!value) {
		sudo->row[i][sudo->field[i][j]] = false;
		sudo->column[j][sudo->field[i][j]] = false;
		sudo->block[block_num(i, j)][sudo->field[i][j]] = false;
	}
	else {
		sudo->row[i][value] = true;
		sudo->column[j][value] = true;
		sudo->block[block_num(i, j)][value] = true;
	}
	sudo->field[i][j] = value;
}

/* 用dfs求解一个数独
 * */
int sudoku_solve(sudoku *sudo) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (sudo->field[i][j] == 0) {
				int b = i / 3 * 3 + j / 3;
				// 尝试填入1~9
				for (int n = 1; n < 10; n++) {
					if (!sudo->row[i][n] && !sudo->column[j][n] && !sudo->block[b][n]) {
						// 尝试填入一个数
						set_value(sudo, i, j, n);
						// 检查是否满足数独解
						if (sudoku_solve(sudo))
							return true;
						// 不满足则回溯
						set_value(sudo, i, j, 0);
					}
				}
				// 尝试所有数字都不满足则回溯
				return false;
			}
	return true;
}

//用拉斯维加斯算法生成一个完整数独, n为初始随机填充的数目
int lasVegas(sudoku *sudo, int n) {
	int i, j, b, value;

	while (n > 0) { //随机填入数字
		i = rand() % 9;
		j = rand() % 9;
		if (sudo->field[i][j] == 0) {
			b = block_num(i, j);
			value = rand() % 9 + 1;//填入数字
			if (!sudo->row[i][value] && !sudo->column[j][value] &&
			    !sudo->block[b][value]) {
				set_value(sudo, i, j, value);
				n--;
			}
		}
	}
	if (sudoku_solve(sudo)) {
		for (int k = 0; k < 4; ++k) {
			i = rand() % 8;
			j = i + 1;
			swap_row(sudo, i, j);
			i = rand() % 8;
			j = i + 1;
			swap_column(sudo, i, j);
		}
		return true;
	}
	else
		return false;
}

//挖洞生成数独初始局面，level为剩余数字数目
//void sequence_dig(sudoku *sudo, int level) {//level:剩余数字
//	int dig_num = 81 - level;//挖掉的数目
//	for (int i = 0; i < 9; ++i) {
//		for (int j = 0; j < 9; ++j) {
//			if (unique(sudo, i, j)) {
//				set_value(sudo, i, j, 0);
//				dig_num--;
//				if (!dig_num) return;
//			}
//		}
//	}
//}

//随机挖洞生成数独初始局面，level为剩余数字的数目,level>24时使用
void random_dig(sudoku *sudo, int level) {
	int a, b;
	int dig_num = 81 - level;//还需要挖掉的数目
	while (dig_num) {
		if (dig_num > 25) {
			a = rand() % 9;
			b = rand() % 9;
			if (unique(sudo, a, b)) {
				set_value(sudo, a, b, 0);
				dig_num--;
			}
		}
		else {
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					if (unique(sudo, (i + a) % 9, (j + b) % 9)) {
						set_value(sudo, (i + a) % 9, (j + b) % 9, 0);
						dig_num--;
						if (!dig_num) return;
					}
				}
			}
		}
	}
}

//判断挖掉(i,j)位置是否有唯一解，若(i,j)为空则返回false
int unique(sudoku *sudo, int i, int j) {
	if (sudo->field[i][j] == 0) return false;//若(i,j)为空则返回false
	int b = block_num(i, j);
	int temp = sudo->field[i][j];//暂存(i,j)的值
	for (int n = 1; n < 10; ++n) {
		if (n != temp) {
			sudoku *new_sudo = sudoku_copy(sudo);
			set_value(new_sudo, i, j, 0);//假设挖掉这个数字
			if (!new_sudo->row[i][n] && !new_sudo->column[j][n] &&
			    !new_sudo->block[b][n]) {
				set_value(new_sudo, i, j, n);
				if (sudoku_solve(new_sudo)) {//发现有另一解
					sudoku_free(new_sudo);
					return false;
				}
			}
			free(new_sudo);
		}
	}
	return true;//无其他解
}


/*
 *-----------*
 * 0 * 3 * 6 *
 *-----------*
 * 1 * 4 * 7 *
 *-----------*
 * 2 * 5 * 8 *
 *-----------*
 */
int block_num(int i, int j) {
	int temp = i / 3 * 3 + j / 3;
	return temp;
}

//释放一个数独空间
void sudoku_free(sudoku *sudo) {
	free(sudo);
}