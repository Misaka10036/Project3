#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//输出所有同时符合下列条件的整数（15分）
/*
该数是4位整数；
该数是完全平方根；
该数减去 1111 后，结果仍是一个完全平方数。
（完全平方是一个整数，它数另一个数的平方，例如 15、36 等）
*/
int main1()
{
	int num;
	for (int i = 1111; i < 10000; i++) {
		num = i;
		if (num == (int)sqrt(i) * (int)sqrt(i) ){
			num-=1111;
			if((int)sqrt(num) * (int)sqrt(num) == num)
				 printf("%d\n",i);
		}
	}
	return 0;
}
//字符串内容检测
int main2()
{
	char ch[100];
	int num = 0, numC = 0, numc = 0, numo = 0;
	scanf("%s", ch);
	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] >= '0' && ch[i] <= '9')
			num++;
		if (ch[i] >= 'a' && ch[i] <= 'z')
			numc++;
		if (ch[i] >= 'A' && ch[i] <= 'Z')
			numC++;
		numo = strlen(ch) - num - numc - numC;
	}
	printf("num=%d numc=%d numC=%d numo=%d", num, numc, numC, numo);
	return 0;
}


//判断素数
int ifsu(int n)
{
	if (n == 1 || n == 2)
		return 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
//输入正数 m 和 n，输出 m 和 n 之间的所有素数（m < n，包括 m 和 n）。
int main3()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (ifsu(i) == 1)
			printf("%d\n", i);
	}
	return 0;
}
//自定义函数，判断该数是否是完全数（如果一个数恰好等于它的因子之和，则称该数为“完全数”）
int ifquan(int n)
{
	if (n == (int)sqrt(n) * (int)sqrt(n))
		return 1;
	return 0;
}

//数组元素去重。假设某数组有 10 个整数，要求对于相同的元素，仅保留第一次出的元素，删除其余的重复元素。保持数组的整体顺序不变。
int main112()
{
	int num1[10],sum = 10;
	for (int i = 0; i < sum;i++ )
		scanf("%d", &num1[i]);
	for (int i = 0; i < sum; i++) {
		for (int j = 0; j < i; j++){
			if (num1[j] == num1[i]) {
				for (int k = i; k < sum - 1; k++)
					num1[k] = num1[k + 1];
				sum--;
				i--;
			}
		}
	}
	for (int i = 0; i < sum; i++)
		printf("%d\n", num1[i]);
	return 0;
}

int ifrun(int year) {
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	else if (year % 400 == 0)
		return 1;
	return 0;
}
struct data {
	int month;
	int day;
}da[2];

data min1(data a, data b) {
	return a.month < b.month ? a : b;
}
data max1(data a, data b) {
	return a.month > b.month ? a : b;
}


//给定同一年当中的任意两个日期，计算间隔的天数（模块接收 5 个参数：year-年、month1-月份1、day1-日期1、month2-月份2、day2-日期2）
int main121()
{
	int num[12] = { 31 ,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month1, day1, month2, day2 ,sum = 0;
	scanf("%d %d %d %d %d", &year, &da[0].month, &da[0].day, &da[1].month, &da[1].day);
	for (int i = min1(da[0], da[1]).month; i < max1(da[0], da[1]).month - 1;i++) {
		sum += num[i];
	}
	if (da[0].month == da[1].month)
		sum = sum + (da[0].day > da[1].day ? da[0].day : da[1].day) - (da[1].day > da[0].day ? da[0].day : da[1].day);
	else {
		sum = sum + (num[min1(da[0], da[1]).month - 1] - min1(da[0], da[1]).day);
		sum += max1(da[0], da[1]).day;
	}
	if (ifrun(year) == 1 && min1(da[0],da[1]).month<=2)
		sum++;

	printf("%d", sum);
	return 0;
}

//输入 5 名学生的信息（学号、成绩、年龄）、按照学生的成绩进行排序，然后输出这 5 名学生的信息（用结构体来存储学生信息）。
#include<algorithm>
using namespace std;

struct student {
	int num;
	int score;
	int age;
}stu[5];

bool cmp(student a, student b) {
	return a.score > b.score;
}

/*
int cmp(void const* a, void const* b)
{
	student* _a = (student*)a;
	student* _b = (student*)b;
	return _a->score - _b->score;
}
*/
int main()
{
	for (int i = 0; i < 5; i++) 
		scanf("%d %d %d", &stu[i].num, &stu[i].score, &stu[i].age);
	sort(stu,stu+5*sizeof(student),cmp);
	return 0;
}

//输入一个合理的年、月、日，计算日期距离 1970.1.1 的天数（20分）
int main8()
{
	time_t timep;
	time(&timep);
	int num;
	num = timep / (60 * 60 * 24);
	printf("%d", num);
	return 0;
}

//编写程序实现大整数的加法和减法运算。（25分）（大整数为 40 到 100 位之间的十进制数）contrast

int main9()
{
	char a[101] = { 0 }, b[101] = { 0 };
	int num1[101] = { 0 }, num2[101] = { 0 },len;
	int num3[101];
	scanf("%s %s", &a, &b);

	//大数相加
	int len1 = strlen(a);
	for (int i = strlen(a) - 1; i >= 0; i--)
		num1[i] = a[len1-i-1] - '0';
	/*while (a != 0) {
		num1[len1] = a % 10;
		a /= 10;
		len1++;
	}
	*/
	int len2 = strlen(b);
	for (int i = strlen(b) - 1; i >= 0; i--)
		num2[i] = b[len2-i-1] - '0';
	/*
	while (b != 0) {
		num2[len2] = b % 10;
		b/= 10;
		len2++;
	}
	*/
	if (len1 > len2)
		len = len1;
	else
		len = len2;

	for (int i = 0; i < len; i++) 
		num3[i] = (num1[i] + num2[i]);

	for (int i =0; i < len - 1; i++) {
		if (num3[i] >= 10) {
			num3[i + 1]++;
			num3[i] -= 10;
		}
	}
	for (int i = len-1; i >= 0; i--)
		printf("%d", num3[i]);
	return 0;
}

/*
【问题描述】输入两个整数m和n，分别输入m和n个浮点数，取m个浮点数中的前4个数据和n个浮点数中的后3个数据重新组成一组新数据，并将新数据按升序输出。（3 < m < 10, 2 < n < 10）
	【输入形式】输入整数m和n，并分别输入m和n个浮点数。
	【输出形式】输出新组成的数据，输出保留一位小数。
	【样例输入】6 5 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0 11.0
	【样例输出】1.0 2.0 3.0 4.0 9.0 10.0 11.0

	【样例输入】4 3 5.2 1.2 4.6 2.0 1.9 8.7 5.4

	【样例输出】1.2 1.9 2.0 4.6 5.2 5.4 8.7
	*/
int main10() 
{
	float a[10], b[10];
	int N,M;
	scanf("%d %d", &N,&M);
	return 0;
}


//设有两个动态实现的顺序表 L1， L2 各存储递增有序的一组整形数。现要求将 L2 合并到 L1 ，且合并后的 L1 仍然保持递增有序。请编程实现。（15分）
#define MAXSIZE 100
struct Link {
	int num[100];
	int lenth;
};



bool merge(Link a, Link b, Link& c) {
	if (a.lenth + b.lenth > MAXSIZE)
		return false;
	int i = 0, j = 0, k = 0;
}


int link()
{
	Link link[3] = { 0 };
	for (int i = 0; i < 3; i++)
		scanf("%d", &link[0].num[i]);
	for (int i = 0; i < 5; i++)
		scanf("%d", &link[1].num[i]);
	link[0].lenth = 3;
	link[1].lenth = 5;
	int i = 0, j = 0, k = 0;
	for (; i < link[0].lenth && j < link[1].lenth;k++) {
		if (link[0].num[i] > link[1].num[j]) {
			link[2].num[k] = link[1].num[j];
			link[2].lenth++;
			j++;
		}
		else {
			link[2].num[k] = link[0].num[i];
			link[2].lenth++;
			i++;
		}
	}
	while (i < link[0].lenth) {
		link[2].num[k++] = link[0].num[i++];
		link[2].lenth++;
	}
	while (j < link[1].lenth) {
		link[2].num[k++] = link[1].num[j++];
		link[2].lenth++;
	}
	for (int i = 0; i < link[2].lenth; i++)
		printf("%d ", link[2].num[i]);
	return 0;
}
#define Element int

struct SqLink {
	int num[100] = {1,3,4,5};
	int lenth = 4;
}a;
//设线性表 L 以顺序存储结构存储，请编程实现在表 L 中的第 i 个元素前插入一个新的数据元素 e。 （1 <= i <= n+1）（10分）
int Insert(SqLink* a, int n, Element e) {
	if (n > a->lenth)
		return 1;
	for (int i = a->lenth; i >= n; i--)
		a->num[i] = a->num[i - 1];
	a->num[n - 1] = e;
	return 0;
}
int main111()
{
	int n, e;
	scanf("%d %d", &n, &e);
	Insert(&a, n, e);
	return 0;
}

//输入一个 3 x 3 的矩阵，将每行中最大的数字放到该行的第一的位置上，然后输出该矩阵
int juzhen()
{
	double num[3][3],max,temp;
	int k=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%lf", &num[i][j]);
	}
	for (int i = 0; i < 3; i++) {
		k = 0;
		max = num[i][0];
		for (int j = 1; j < 3; j++) {
			if (num[i][j] > max) {
				max = num[i][j];
				k = j;
			}
		}
		temp = num[i][0];
		num[i][0] = max;
		num[i][k] = temp;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%.1lf ", num[i][j]);
		printf("\n");
	}
	return 0;
}
struct lian {
	Element num;
	lian* next;
};
//在一个升序的链表中插入一个元素，要求插入任意元素后使得链表依然保存升序（假设链表有 5 个元素）
#define MAXsize 5
int insert(lian *head,Element e)
{
	lian* Node = head->next,*temp;
	for (int i = 0; i < MAXsize-1; i++) {
		if (Node->next->num >= e) {
			temp = Node->next;
			Node->next = (lian*)malloc(sizeof(lian));
			Node = Node->next;
			Node->num = e;
			Node->next = temp;
			return 1;
		}
		Node = Node->next;
	}
	Node->next = (lian*)malloc(sizeof(lian));
	Node = Node->next;
	Node->num = e;
	Node->next = NULL;
}

int main123()
{
	lian* head = (lian*)malloc(sizeof(lian)),*Node=head;
	int num;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num);
		Node->next = (lian*)malloc(sizeof(lian));
		Node = Node->next;
		Node->num = num;
		Node->next = NULL;
	}
	insert(head, 6);
	int a = 2;
	printf("%d", ((3>5)&&(4>5)));
	return 0;
}

//输入一个 3 x 3 的矩阵，将每行中最大的数字放到该行的第一的位置上，然后输出该矩阵
int mainzoom()
{
	double a[3][3], max;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%lf", &a[i][j]);
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			max = a[i][0];
			if (max < a[i][j]) {
				a[i][0] = a[i][j];
				a[i][j] = max;
				max = a[i][0];
			}
		}

	}		
	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				printf("%lf", a[i][j]);
			printf("\n");
		}
	return 0;
}

//在一个升序的链表中插入一个元素，要求插入任意元素后使得链表依然保存升序（假设链表有 5 个元素）。
struct data1 {
	Element num;
	data1* next;
};

void insert(data1* L, Element e)
{
	while (L->next!=NULL && L->next->num < e) {
		L = L->next;
	}
	data1* temp = (data1*)malloc(sizeof(data1));
	temp -> num = e;
	temp->next = L->next;
	L->next = temp;

}
int main456()
{
	data1* head = (data1*)malloc(sizeof(data1)), * Node = head;
	int num;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num);
		Node->next = (data1*)malloc(sizeof(data1));
		Node = Node->next;
		Node->num = num;
		Node->next = NULL;
	}
	insert(head, 6);
	return 0;
}


//2．输入20个数，将它们按照从小到大的次序输出。（20分）
int cmp12(const void* a, const void* b) {
	int* _a = (int*)a;
	int* _b = (int*)b;
	return *_a  - *_b;
}

bool cmp13(int a,int b){
	return a > b;
}
/*
#include<algorithm>
int main()
{
	int num[20];
	for (int i = 20; i > 0; i--)
		num[20 - i] = i;
	qsort(&num[0], 20, sizeof(int),cmp12);
	std::sort(num, num + 20, cmp13);
	for(int i=0;i<20;i++)
	printf("%d ", num[i]);
	return 0;
}
*/

int del(int* num) {
	int n = 10;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (num[i] == num[j]) {
				for (int k = j; k < n; k++)
					num[k] = num[k + 1];
				n--;
				i--;
			}
		}
	}
	return n;
}

int main233()
{
	int num[10] = {1,6,2,3,2,3,3,5,6,3};
	int n = del(num);
	for (int i = 0; i < n; i++)
		printf("%d\n", num[i]);
	return 0;
}