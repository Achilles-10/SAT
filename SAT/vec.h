#ifndef SAT_VEC_H
#define SAT_VEC_H

typedef struct vector_ {
	int *data;
	int size;
} vector;


vector *vec_init();//初始化一个vector

void vec_resize(vector *v, int l, int x);//调整vector长度为l，若l>size，则填充元素为x，若l<size，则删除末尾元素

vector *vec_copy(const vector *v);//拷贝vector

void vec_clear(vector *v);//清空vector数据

//int vec_size(vector *v);//返回vector的size

void vec_add(vector *v, int x);//添加x到vector末尾

//void vec_set(vector *v, int i, int x);//将位置i的元素置为x

//int vec_get(const vector *v, int i);//返回位置为i的元素,若超出size则返回0

int vec_getMax(const vector *v);//返回最大元素的第一个索引,若为空vector返回-1

void vec_erase(vector *v, int i);//删除位置为i的元素

//void vec_show_base(const vector *v);//遍历输出vector

void vec_show_formula(const vector *v);//遍历输出vector

void vec_free(vector *v);//释放vector空间

#endif //SAT_VEC_H