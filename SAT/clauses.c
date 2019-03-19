#include "clauses.h"
#include <stdlib.h>
#include <stdio.h>

//初始化一个clauses
clau *clau_init() {
	clau *c = (clau *) malloc(sizeof(clau));
	c->clause = NULL;
	c->size = 0;
}

//调整clauses长度为l，若l>size，则填充默认vector，若l<size，则删除末尾元素
void clau_resize(clau *c, int l) {
	if (c->size == l) return;
	if (c->size < l) {
		vector **new_clause = (vector **) malloc(sizeof(vector *) * l);
		for (int i = 0; i < c->size; ++i)
			new_clause[i] = vec_copy(c->clause[i]);
		for (int j = c->size; j < l; ++j)
			new_clause[j] = vec_init();
		clau_clear(c);
		c->clause = new_clause;
	}
	else {
		vector **new_clause = (vector **) malloc(sizeof(vector *) * l);
		for (int i = 0; i < l; ++i)
			new_clause[i] = vec_copy(c->clause[i]);
		clau_clear(c);
		c->clause = new_clause;
	}
	c->size = l;
}

//拷贝clauses
clau *clau_copy(const clau *c) {
	clau *new_c = clau_init();
	new_c->size = c->size;
	new_c->clause = (vector **) malloc(sizeof(vector *) * new_c->size);
	for (int i = 0; i < new_c->size; ++i)
		new_c->clause[i] = vec_copy(c->clause[i]);
	return new_c;
}

//清空clauses数据
void clau_clear(clau *c) {
	for (int i = 0; i < c->size; ++i)
		vec_clear(c->clause[i]);
	free(c->clause);
	c->clause = NULL;
	c->size = 0;
}

//添加v到clauses的末尾
void clau_add(clau *c, vector *v) {
	if (c->size == 0)
		c->clause = (vector **) malloc(sizeof(vector *));
	else {
		vector **new_clause = (vector **) realloc(c->clause,
		                                          (c->size + 1) * sizeof(vector *));
		if (!new_clause) {
			printf("Add vector to clauses failed!\n");
			exit(EXIT_FAILURE);
		}
		else c->clause = new_clause;
	}
	c->clause[c->size] = vec_copy(v);
	c->size++;
}

//vector *clau_get(const clau *c, int i) {
//	if (i >= c->size) return NULL;
//	return c->clause[i];
//}

//删除位置为i的子句
void clau_erase(clau *c, int i) {
	if (i > c->size) return;
	vector **new_clause = (vector **) malloc(sizeof(vector *) * (c->size - 1));
	int count = 0;
	for (int j = 0; j < c->size; ++j) {
		if (j == i) continue;
		new_clause[count++] = c->clause[j];
	}
	vec_free(c->clause[i]);
	free(c->clause);
	c->clause = new_clause;
	c->size--;
}

//遍历输出clauses
void clau_show(const clau *c) {
	printf("clauses:\n");
	for (int i = 0; i < c->size; ++i) {
		printf("<No.%d>\t", i + 1);
		vec_show_formula(c->clause[i]);
	}
}

//释放clauses空间
void clau_free(clau *c) {
	for (int i = 0; i < c->size; ++i)
		vec_free(c->clause[i]);
	free(c->clause);
	free(c);
}