#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short a, r;
	cout << "Введите десятичное число а = ";
	cin >> a;
	cout << "Исходное число: ";
	for (int i = 15; i >= 0; i--) {
		cout << ((a >> i) & 1 ? "1" : "0");
	}
		cout << endl;
		_asm {
			mov ecx, 8
			mov ax, a
			mov bl, al
			xor al, al
			lp:
			mov bh, bl
				and bh, 1
				shl al, 1
				or al, bh
				shr bl, 1
				loop lp
			and al, ah
			mov ah, 0
			mov r, ax
		}
		cout << "Результат: ";
		for (int i = 7; i >= 0; i--) {
			cout << ((r >> i) & 1 ? "1" : "0");
		}
	cout << endl;
	system("pause");
    return 0;
}

