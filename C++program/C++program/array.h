#pragma once

void initial(int* a,int size,int content);//�����鸳��ͬ��ֵ����ʼ����
void merge(int* a, int size_a, int* b, int size_b, int* c);//�����鰴����˳��鲢
void index(int* a,int size_a,int key);//����ֵ����λ��
int erase(int* a, int size_a,int key);//ɾ�������Ԫ��
void select(int* list, int m);//�������е���ֵ����С�����˳������
void merge_plus(int* a, int size_a, int* b, int size_b, int *c);//�����鰴��ֵ��С�鲢
void choose(int* m,int size_m);//ѡ�����������