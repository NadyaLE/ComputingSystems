#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char sentence[250];
	char res[250];
	cout << "Введите текст: " << endl;
	cin.get(sentence, 250);
	strcat_s(sentence, " ");
	int l = strlen(sentence);
	strcpy_s(res,sentence);
	_asm {
		mov al, ' '
		mov esi, 0
		mov edi, 0
		mov ecx, l
		cycle1:
		cmp al, sentence[esi]
			jne noneq
			mov ebx, ecx
			mov ecx, esi
			sub ecx, edi
			cycle2:
			dec esi
            mov dl, sentence[esi]
            mov res[edi], dl
			inc edi
            loop cycle2
				mov res[edi], al
				mov esi, edi
				inc edi
				mov ecx, ebx
			noneq:
		inc esi
		loop cycle1
   	}
	cout << res << endl;
	system("pause");
    return 0;
}

