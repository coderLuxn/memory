#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//char类型
//地址是从 低地址->高地址      0x 00 00 00 01
//大端存储模式（高位数->低位数）  00 00 00 01
//小端存储模式（低位数->高位数）  01 00 00 00
//如何知道当前机器的字节序
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;//强制把int型转换成char型
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//调用函数
//int check_sys()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//		return 1;
//	else
//		return 0;
//}
// //更简便的方法
//int check_sys()
//{
//	int a = 1;
//	//char* p = (char*)&a;
//	//return *p;
//
//	return *(char*)&a;
//}
//int main()
//{
//	//返回1 小端
//	//返回0 大端
//	int ret = check_sys();
//	if (ret == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}

//int main()
//{
//	int a = 0x11223344;
//	//int* p = &a;
//	//*p = 0;
//	char* p = &a;
//	*p = 0;
//	return 0;
//}

//int main()
//{
//	//a 10000000000000000000000000000001 原码
//	//  11111111111111111111111111111110 反码
//	//  11111111111111111111111111111111 补码
//	//char型一个字节 11111111
//	char a = -1;
//	//11111111
//	signed char b = -1;
//	//11111111
//	unsigned  char c = -1;
//	//11111111
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	//整形提升  有符号数补符号位 无符号数补0
//	//a11111111111111111111111111111111
//	//b11111111111111111111111111111111
//	//c00000000000000000000000011111111
//	return 0;
//}

//int main()
//{
//	char a = -128;
//  char a=128;//127+1
//	//10000000000000000000000010000000 原码
//	//11111111111111111111111101111111 反码
//	//11111111111111111111111110000000 补码
//	//10000000
//	printf("%u\n", a);
//	//%d 打印十进制的有符号数字
//	//%u 打印十进制的无符号数字
//	//整形提升 11111111111111111111111110000000 无符号位 原码 反码 补码一样
//	return 0;
//}

//int main()
//{
//	int i= -20;
//	//10000000000000000000000000010100 原码
//	//11111111111111111111111111101011 反码
//	//11111111111111111111111111101100 补码
//	//00000000000000000000000000001010
//	//11111111111111111111111111110110 结果
//	//11111111111111111111111111110101
//	//10000000000000000000000000001010 原码
//	unsigned int j = 10;
//	printf("%d", i + j);//-10
//	return 0;
//}

//#include <windows.h>
//int main()
//{
//	unsigned int i;
//	for (i = 10; i>=0; i--)//i是无符号数(unsigned)，不可能小于0
//	{
//		printf("%u\n", i);
//		Sleep(100);//暂停0.1S
//	}
//	return 0;
//}

//#include <string.h>
//int main()
//{
//	//char 有符号的char范围是-128到127
//	//     无符号的char范围是0到255
//	char a[1000];
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{                  //-1-128=127 -1-129=126
//		a[i] = -1 - i;//-1 -2 -3....-128 127 126 125 ....1 0
//		             //128+127
//	}
//	printf("%d", strlen(a));//255
//	return 0;
//}

//unsigned char i=0;//无符号的char范围是0到255
//int main()
//{
//	for (i = 0; i <= 255; i++)//255+1=0
//	{
//		printf("hello word\n");//死循环
//	}
//	return 0;
//}

//float浮点型
//(-1)^s*M*2^E
int main()
{
	int n = 9;
	//00000000000000000000000000001001
	//char* p = (char*)&n;
	//printf("%d", *p);//9
	float* pfloat = (float*)&n;
	//00000000000000000000000000001001 补码
	printf("n的值：%d\n", n);//9
	printf("ploat的值：%f\n", *pfloat);//E为全0时，E=1-127或1-1023 M第一位不用写，直接写成0.xxxx
	//0 00000000 00000000000000000001001 E全0 1-127=-126
	//(-1)^0 0.00000000000000000001001 2^-126
	*pfloat = 9.0;//1001
	//(-1)^0*1.001*2^3 E=3+127 130->10000010
	//0 10000010 00100000000000000000000
	//1091567616
	printf("n的值：%d\n", n);//109...
	printf("ploat的值：%f\n", *pfloat);//9.0
	return 0;
}