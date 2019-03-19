#include "toCNF.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#define WHITE 0x7
#define GREEN 0x2

/* =====================================
 *               MENU
 * =====================================
 *
 *      1. SUDOKU    2.SAT   3.EXIT
 *
 * -------------------------------------
 * Please input your option:
 *
 *
 * 1:           LEVEL CHOICE
 *
 *      1.very easy  2.easy      3.medium
 *      4.hard       5.very hard 6.exit
 *
 *      Please choose the level:
 *
 *          1,2,3,4,5:  GAME
 *                  //数独//
 *
 *          1.fill blanks    2.tips
 *          3.answer         4.exit
 *
 *              1:
 *              Please input the row column and the value
 *              [example:4 1 4(fill the forth row and the first column with 4)]
 *
 *              2:
 *              Please input the position you want to check
 *              [example:3 4(check the third row and the forth column)]
 *
 *              3:  //数独//
 *
 *              4: MENU
 *
 *          6: MENU
 *
 * 2:  SAT TEST
 *
 *      1.function test 2.performance test
 *      3.sudoku test   4.other test    5.exit
 *
 *      Please input your option:
 *
 *          1:  FUNCTION TEST
 *
 *              1.sat-20.cnf    2.unsat-5cnf-30.cnf 3.exit
 *
 *              Please input your option:
 *
 *                  1,2:    xxx.cnf
 *                      show clauses,answers,time(Before and after optimization) and the optimization rate
 *                  3: back
 *
 *          2: PERFORMANCE TEST
 *
 *              1.ais10.cnf    2.sud00009.cnf       3.exit
 *
 *              Please input your option:
 *
 *                  ...
 *
 *
 *          3: SUDOKU TEST
 *
 *              show the sudoku, write/load file and use dpll to solve
 *
 *  3:  EXIT
 *
 * */
void display() {
	int opt = 1;
	while (1) {
		switch (opt) {
			case 1:
				opt = MENU();
				continue;
			case 2:
				opt = SUDOKU();
				continue;
			case 3:
				opt = SAT();
				continue;
			default:
				break;
		}
		break;
	}
}

//菜单主界面
int MENU() {
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int opt;
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("              MENU                   \n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("     1. SUDOKU    2.SAT   3.EXIT     \n\n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("-------------------------------------\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("Please input your option:");
	scanf("%d", &opt);
	getchar();
	if (opt == 1) return 2;//sudoku
	else if (opt == 2) return 3;//sat
	else return 0;
}

//数独主界面
int SUDOKU() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) {
		system("cls");
		int level;
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("          LEVEL CHOICE               \n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("1.very easy  2.easy      3.medium\n");
		printf("4.hard       5.very hard 6.exit\n\n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("-------------------------------------\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("Please choose the level:");
		scanf("%d", &level);
		getchar();
		if (level >= 6 || level <= 0) return 1;//返回主菜单
		GAME(level);
	}
}

//数独游戏界面
void GAME(int level) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int opt;
	sudoku *sudo = sudoku_init();
	lasVegas(sudo, 11);
	sudoku *answer_sudo = sudoku_copy(sudo);
	random_dig(sudo, 50 - level * 5);

	while (1) {
		system("cls");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("              GAME                   \n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n\n");
		sudoku_show(sudo);
		printf("\n\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("1.fill blanks    2.tips\n");
		printf("3.answer         4.exit\n\n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("-------------------------------------\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("Please input your option:");
		scanf("%d", &opt);
		getchar();
		switch (opt) {
			case 1:
				fill_blank(sudo);
				continue;
			case 2:
				tips(sudo, answer_sudo);
				continue;
			case 3:
				answer(answer_sudo);
				break;
			default:
				break;
		}
		break;
	}
}

//填充数独
void fill_blank(sudoku *sudo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int row, column, value;
	system("cls");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("              GAME                   \n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n\n");
	sudoku_show(sudo);
	printf("\n\n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("-------------------------------------\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("Please input the row column and the value:\n");
	printf("[example:4 1 4(fill the forth row and the first column with 4)]\n");
	scanf("%d %d %d", &row, &column, &value);
	getchar();
	set_value(sudo, row - 1, column - 1, value);
}

//数独提示
void tips(sudoku *sudo, sudoku *answer_sudo) {
	int row, column;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("              GAME                   \n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n\n");
	sudoku_show(sudo);
	printf("\n\n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("-------------------------------------\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("Please input the position you want to check:\n");
	printf("[example:3 4(check the third row and the forth column)]\n");
	scanf("%d %d", &row, &column);
	getchar();
	printf("row:%d column:%d value:%d\n\n", row, column,
	       answer_sudo->field[row - 1][column - 1]);
	printf("Enter to continue...\n");
	getchar();
}

//数独答案
void answer(sudoku *answer_sudo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("              GAME                   \n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n\n");
	sudoku_show(answer_sudo);
	printf("\n\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("Enter to the main menu...\n");
	getchar();
}

//SAT求解主界面
int SAT() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int test_opt;
	while (1) {
		system("cls");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("            SAT TEST                 \n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("1.function test 2.performance test\n");
		printf("3.sudoku test   4.other test    5.exit\n\n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("-------------------------------------\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("Please input your option:");
		scanf("%d", &test_opt);
		getchar();
		if (test_opt >= 5 || test_opt <= 0) return 1;//返回主菜单
		switch (test_opt) {
			case 1:
				function_test();
				continue;
			case 2:
				performance_test();
				continue;
			case 3:
				sudoku_test();
				continue;
			case 4:
				other_test();
			default:
				break;
		}
		break;
	}
	return 1;
}

//功能测试
void function_test() {
	int file_opt;
	const char *filename;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) {
		system("cls");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("          FUNCTION TEST              \n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("1.sat-20.cnf    2.unsat-5cnf-30.cnf 3.exit\n\n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("-------------------------------------\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("Please input your option:");
		scanf("%d", &file_opt);
		getchar();
		if (file_opt >= 3 || file_opt <= 0) return;
		if (file_opt == 1) filename = "sat-20.cnf";
		else filename = "unsat-5cnf-30.cnf";
		formula *f = form_load(filename);
		clau_show(f->clauses);

//优化前
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("\nEnter to use algorithm 1...\n");
		getchar();
		time_t begin, end;
		double time_optimization, time, optimization_rate;
		begin = clock();
		solve(f, 0);
		end = clock();
		time = (double) end - begin;

//优化后
		printf("\nEnter to use algorithm 2...\n");
		getchar();
		begin = clock();
		solve(f, 1);
		end = clock();
		time_optimization = (double) end - begin;
		optimization_rate = 100 * fabs(time - time_optimization) / time;

		printf("\n\nEnter to continue...\n");
		getchar();
		system("cls");
		printf("      before optimization  after optimization  optimization rate\n");
		printf("time: %6fms           %6fms          %.2f%%\n\n", time, time_optimization,
		       optimization_rate);
		printf("Now write the result into file: %s.res...\n", filename);
		int length = strlen(filename) - 3;
		char result_filename[40];
		strncpy(result_filename, filename, length);
		strcat(result_filename, "res");
		result_write(f, result_filename, time_optimization);
		printf("Finished! Enter to continue...\n");
		getchar();
	}
}

//性能测试
void performance_test() {
	int file_opt;
	const char *filename;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) {
		system("cls");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("         PERFORMANCE TEST            \n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("1.ais10.cnf    2.sud00009.cnf    3.exit\n\n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("-------------------------------------\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("Please input your option:");
		scanf("%d", &file_opt);
		getchar();
		if (file_opt >= 3 || file_opt <= 0) return;
		if (file_opt == 1) filename = "ais10.cnf";
		else filename = "sud00009.cnf";
		formula *f = form_load(filename);
		clau_show(f->clauses);

//优化前
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("\nEnter to use algorithm 1...\n");
		getchar();
		time_t begin, end;
		double time_optimization, time, optimization_rate;
		begin = clock();
		solve(f, 0);
		end = clock();
		time = (double) end - begin;

//优化后
		printf("\nEnter to use algorithm 2...\n");
		getchar();
		begin = clock();
		solve(f, 1);
		end = clock();
		time_optimization = (double) end - begin;
		optimization_rate = 100 * fabs(time - time_optimization) / time;

		printf("\n\nEnter to continue...\n");
		getchar();
		system("cls");
		printf("      before optimization  after optimization  optimization rate\n");
		printf("time: %6fms           %6fms          %.2f%%\n\n", time, time_optimization,
		       optimization_rate);
		printf("Now write the result into file: %s.res...\n", filename);
		int length = strlen(filename) - 3;
		char result_filename[40];
		strncpy(result_filename, filename, length);
		strcat(result_filename, "res");
		result_write(f, result_filename, time_optimization);
		printf("Finished! Enter to continue...\n");
		getchar();
	}
}

//数独测试
void sudoku_test() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n");
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("            SUDOKU TEST              \n");
	SetConsoleTextAttribute(hConsole,GREEN);
	printf("=====================================\n\n");
	sudoku *sudo = sudoku_init();
	lasVegas(sudo, 11);
	sudoku *answer_sudo = sudoku_copy(sudo);
	random_dig(sudo, 28);
	sudoku_show(sudo);
	sudoku *encoding_sudo = sudoku_encoding(sudo);
	formula *sudo_f = sudoku_to_formula(encoding_sudo);
	SetConsoleTextAttribute(hConsole,WHITE);
	printf("\nEnter to write the sudoku into file...\n");
	getchar();
	printf("\nNow write the sudoku into file: sudoku.cnf...\n");
	form_write(sudo_f, "sudoku.cnf");
	printf("\nFinished! Enter to solve the sudoku by dpll algorithm...\n");
	getchar();

	printf("\nNow solve the sudo by dpll...\n");

	time_t begin, end;
	double time;
	begin = clock();
	solve(sudo_f, 1);
	end = clock();
	time = (double) end - begin;
	printf("Time: %fms\n", time);

	printf("\nEnter to show the completed sudoku...\n");
	getchar();
	sudoku_show(sudo);
	printf("                 ||\n                 ||\n                 \\/\n\n");
	sudoku_show(answer_sudo);
	printf("\nEnter to write the result into file...\n");
	getchar();
	printf("\nNow write the result into file: sudoku.res...\n");
	result_write(sudo_f, "sudoku.res", time);
	printf("Finished! Enter to continue...\n");
	getchar();
}

//其他文件测试
void other_test(){
	char *filename;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) {
		system("cls");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("            OTHER TEST               \n");
		SetConsoleTextAttribute(hConsole,GREEN);
		printf("=====================================\n\n");
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("Please input filename:(q to quit)\n");
		scanf("%s", filename);
		getchar();
		if (filename[0] == 'q')
			return;
		formula *f = form_load(filename);
		clau_show(f->clauses);

//优化前
		SetConsoleTextAttribute(hConsole,WHITE);
		printf("\nEnter to use algorithm 1...\n");
		getchar();
		time_t begin, end;
		double time_optimization, time, optimization_rate;
		begin = clock();
		solve(f, 0);
		end = clock();
		time = (double) end - begin;

//优化后
		printf("\nEnter to use algorithm 2...\n");
		getchar();
		begin = clock();
		solve(f, 1);
		end = clock();
		time_optimization = (double) end - begin;
		optimization_rate = 100 * fabs(time - time_optimization) / time;

		printf("\n\nEnter to continue...\n");
		getchar();
		system("cls");
		printf("      before optimization  after optimization  optimization rate\n");
		printf("time: %6fms           %6fms          %.2f%%\n\n", time, time_optimization,
		       optimization_rate);
		printf("\nEnter to continue...\n");
		getchar();
	}
}