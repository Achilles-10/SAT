#ifndef SAT_MENU_H
#define SAT_MENU_H

#include "sudoku.h"

void display();//主界面逻辑

int MENU();//菜单主界面

int SUDOKU();//数独主界面

void GAME(int level);//数独游戏界面

void fill_blank(sudoku *sudo);//填充数独

void tips(sudoku *sudo, sudoku *answer_sudo);//数独提示

void answer(sudoku *answer_sudo);//数独答案

int SAT();//SAT求解主界面

void function_test();//功能测试

void performance_test();//性能测试

void sudoku_test();//数独测试

void other_test();//其他文件测试

#endif //SAT_MENU_H