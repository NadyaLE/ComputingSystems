// ВычСис2лаба.cpp: определяет точку входа для консольного приложения.
//
#include <stdio.h>
#include <locale.h>
#include <cstdlib> 


int main()
{
	setlocale(LC_ALL, "Russian");
	int A[3], B[3], x, y, z = 0;
	printf("Данная программа вычисляет значение выражения: | Summ(Ai) * X + Summ(Bi) * Y | \n");
	for (int i = 0; i < 3; i++)
	{
		printf("Введите значение элемента A[%i]:\n", i + 1);
		scanf_s("%i", &A[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("Введите значение элемента B[%i]:\n", i + 1);
		scanf_s("%i", &B[i]);
	}
	printf("Введите число X:\n");
	scanf_s("%i", &x);
	printf("Введите число Y:\n");
	scanf_s("%i", &y);
	z = abs((A[0] + A[1] + A[2])*x + (B[0] + B[1] + B[2])*y);
//	z = abs(z);
	_asm
	{
		mov eax, 0
		mov esi, 0
		mov ecx, 3
		lea ebx, A
		cycl1 :
		    mov esi, [ebx]
			add eax, esi
			add ebx, 4
			loop cycl1
			imul x
			mov x, eax
			mov eax, 0
			mov esi, 0
			mov ecx, 3
			lea ebx, B
		cycl2 :
			mov esi, [ebx]
				add eax, esi
				add ebx, 4
				loop cycl2
				imul y
				mov y, eax
				mov eax, 0
				add eax, y
				add eax, x;
				cmp eax, 0
				jge m1
			    neg eax
			m1:
            mov x, eax
			
	}
	printf("Result on Asm: %i\n", x);
	printf("Result on C++: %i\n", z);
	system("pause");

	return 0;
}

