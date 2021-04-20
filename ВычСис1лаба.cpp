// ВычСис1лаба.cpp: определяет точку входа для консольного приложения.
//
//#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib> 

int main()
{   
	setlocale(LC_ALL, "Russian");
	printf("Данная программа вычисляет значение выражения A * X * Y * Z + B * X * Y + C * Y * Z + D * X * Z + A\n");
	int a, b, c, d, x, y, z, p;
	printf("Введите число A:\n");
	scanf_s("%i", &a);
	printf("Enter value B:\n");
	scanf_s("%i", &b);
	printf("Enter value C:\n");
	scanf_s("%i", &c);
	printf("Enter value D:\n");
	scanf_s("%i", &d);
	printf("Enter value X:\n");
	scanf_s("%i", &x);
	printf("Enter value Y:\n");
	scanf_s("%i", &y);
	printf("Enter value Z:\n");
	scanf_s("%i", &z);
	p = a * x * y * z + b * x * y + c * y * z + d * x * z + a;
	_asm
	{
		mov eax, a;
		imul x;
		imul y;
		imul z;
		add a, eax;
		mov eax, b;
		imul x;
		imul y;
		add a, eax;
		mov eax, c;
		imul y;
		imul z;
		add a, eax;
		mov eax, d;
		imul x;
		imul z;
		add a, eax;
	}
	printf("Result on Asm: %i\n", a);
	printf("Result on C++: %i\n", p);
	system("pause");

	return 0;
}

