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
int main4()
{
	int num1[10], num2[10],sum = 10;
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
int data1()
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

struct student {
	int num;
	int score;
	int age;
}stu[5];

int cmp(void const* a, void const* b)
{
	student* _a = (student*)a;
	student* _b = (student*)b;
	return _a->score > _b->score;
}

int main6()
{
	for (int i = 0; i < 5; i++) 
		scanf("%d %d %d", &stu[i].num, &stu[i].score, &stu[i].age);
	qsort(stu, 5, sizeof(student), cmp);
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

}


//设有两个动态实现的顺序表 L1， L2 各存储递增有序的一组整形数。现要求将 L2 合并到 L1 ，且合并后的 L1 仍然保持递增有序。请编程实现。（15分）

struct Link {
	int num[100];
	int lenth;
};

int main()
{
	Link link[3] = { 0 };
	for (int i = 0; j = 0; i < link[0].lenth && j < link[1].lenth;) {
		if()
	}
}