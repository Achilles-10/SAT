#include "vec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化一个vector
vector *vec_init() {
	vector *v = (vector *) malloc(sizeof(vector));
	v->data = NULL;
	v->size = 0;
	return v;
}

//清空vector数据
void vec_clear(vector *v) {
	free(v->data);
	v->data = NULL;
	v->size = 0;
}

//调整vector长度为l，若l>size，则填充元素为x，若l<size，则删除末尾元素
void vec_resize(vector *v, int l, int x) {
	if (v->size == l) return;
	if (v->size < l) {
		int *new_data = (int *) malloc(sizeof(int) * l);
		memcpy(new_data, v->data, sizeof(int) * v->size);
		for (int i = v->size; i < l; ++i) new_data[i] = x;
		free(v->data);
		v->data = new_data;
	}
	else {
		int *new_data = (int *) malloc(sizeof(int) * l);
		memcpy(new_data, v->data, sizeof(int) * l);
		free(v->data);
		v->data = new_data;
	}
	v->size = l;
}

//拷贝vector
vector *vec_copy(const vector *v) {
	vector *new_v = vec_init();
	new_v->size = v->size;
	new_v->data = (int *) malloc(sizeof(int) * new_v->size);
	memcpy(new_v->data, v->data, sizeof(int) * v->size);
	return new_v;
}

//int vec_size(vector *v) {
//	return v->size;
//}

//添加x到vector末尾
void vec_add(vector *v, int x) {
	//惰性扩容
	if (v->size == 0) {//分配空间
		v->data = (int *) malloc(sizeof(int));
	}
	else {
		int *new_data = (int *) realloc(v->data, (v->size + 1) * sizeof(int));
		if (!new_data) {//扩容失败
			printf("Add %d to vector failed!\n", x);
			exit(EXIT_FAILURE);
		}
		else v->data = new_data;
	}
	v->data[v->size] = x;
	v->size++;
}

//将位置i的元素置为x
//void vec_set(vector *v, int i, int x) {
//	if (i >= v->size) return;
//	v->data[i] = x;
//}

//返回位置为i的元素,若超出size则返回0
//int vec_get(const vector *v, int i) {
//	if (i >= v->size) return 0;
//	return v->data[i];
//}

//返回最大元素的第一个索引,若为空vector返回-1
int vec_getMax(const vector *v) {
	if (v->size == 0) return -1;
	int max = 0;
	for (int i = 1; i < v->size; ++i)
		if (v->data[max] < v->data[i]) max = i;
	return max;
}

//删除位置为i的元素
void vec_erase(vector *v, int i) {
	if (i >= v->size) return;
	int *new_data = (int *) malloc(sizeof(int) * (v->size - 1));
	int count = 0;
	for (int j = 0; j < v->size; ++j) {
		if (j == i) continue;
		new_data[count++] = v->data[j];
	}
	free(v->data);
	v->data = new_data;
	v->size--;
}


/*基础版本*/
//void vec_show_base(const vector *v) {
//	if (v->size == 0) printf("<empty>\n");
//	else {
//		printf("<");
//		for (int i = 0; i < v->size; ++i) {
//			if (i != 0) printf(" ");
//			printf("%d", v->data[i]);
//		}
//		printf(">\n");
//	}
//}

/*formula版本*/
//遍历输出vector
void vec_show_formula(const vector *v) {
	if (v->size == 0) printf("<empty>\n");
	else {
		printf("<");
		for (int i = 0; i < v->size; ++i) {
			if (i != 0) printf(" ");
			printf("%d", (v->data[i] % 2) ? (-v->data[i]) / 2 - 1 : v->data[i] / 2 + 1);
		}
		printf(">\n");
	}
}

//释放vector空间
void vec_free(vector *v) {
	free(v->data);
	free(v);
}