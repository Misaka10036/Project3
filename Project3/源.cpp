#include<stdio.h>
#include<string.h>
#define ElemType int
#define n 20
//线性表
typedef struct {
	ElemType data[n];
	int length;

}SqList;

int ListInsert(SqList& L, int i, ElemType e) {
	if (L.length >= n)
		return 0;
	if (i<0 || i>L.length + 1)
		return 0;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return 1;
}

int InsertSql(SqList& L, int i, ElemType e)
{
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return 0;
}
//大整数加减法

int add(int num1, int num2)
{
	int a[2] = { 0 }, b[2] = { 0 }, c[3] = { 0 }, flag = 0;
	for (int i = 0; i < 2; i++) {
		a[i] = num1 % 10;
		num1 /= 10;
	}
	for (int i = 0; i < 2; i++) {
		b[i] = num2 % 10;
		num2 /= 10;
	}
	for (int i = 0; i < 2; i++) {
		c[i] = a[i] + b[i] + c[i];
		if (c[i] >= 10) {
			c[i] -= 10;
			c[i + 1]++;
		}
	}
	for (int i = 2; i >= 0; i--) {
		if (c[i] != 0 || flag == 1) {
			flag = 1;
			printf("%d", c[i]);
		}
	}
	if (flag == 0)
		printf("0");
	return 0;
}



int main()
{
	int a[2] = { 0 }, b[2] = { 0 }, c[3] = { 0 }, num1, num2, flag = 0;
	scanf("%d %d", &num1, &num2);
	add(num1, num2);

	return 0;
}



/*
int main()
{
	int M;
	char ch[100][100];
	int jug[100] = { 0 }, num[100] = { 0 };
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%s", &ch[M]);
	}
	for (int i = 0; i < M; i++) {
		for (int j = i; i < M; j++) {
			if (strcmp(ch[i], ch[j]) == 0 && jug[j] != 1) {
				jug[j] = 1;
				num[i]++;
			}
		}
	}

}
*/