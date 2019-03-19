#ifndef SAT_CLAUSES_H
#define SAT_CLAUSES_H

#include "vec.h"

typedef struct clauses_ {
	vector **clause;
	int size;
} clau;

clau *clau_init();//初始化一个clauses

void clau_resize(clau *c, int l);//调整clauses长度为l，若l>size，则填充默认vector，若l<size，则删除末尾元素

clau *clau_copy(const clau *c);//拷贝clauses

void clau_clear(clau *c);//清空clauses

void clau_add(clau *c, vector *v);//添加v到clauses的末尾

//vector *clau_get(const clau *c, int i);//返回位置为i的元素

void clau_erase(clau *c, int i);//删除位置为i的元素

void clau_show(const clau *c);//遍历输出clauses

void clau_free(clau *c);//释放clauses空间

#endif //SAT_CLAUSES_H