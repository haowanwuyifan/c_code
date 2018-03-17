#pragma once

void initial(int* a,int size,int content);//给数组赋相同的值（初始化）
void merge(int* a, int size_a, int* b, int size_b, int* c);//将数组按数组顺序归并
void index(int* a,int size_a,int key);//按数值查找位置
int erase(int* a, int size_a,int key);//删除数组的元素
void select(int* list, int m);//将数组中的数值按从小到大的顺序排序
void merge_plus(int* a, int size_a, int* b, int size_b, int *c);//将数组按数值大小归并
void choose(int* m,int size_m);//选择操作的数组