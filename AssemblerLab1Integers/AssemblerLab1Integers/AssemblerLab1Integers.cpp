// AssemblerLab1Integers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	int x;
	short res = 0;
	cout << "Enter a natural number: ";
	cin >> x;
	while (x > 65535 || x < 0)
	{
		cout << "Please, enter a natural number up to 65 535 (16-bit): ";
		cin >> x;
	}

	_asm {
		mov eax, x
		mov ecx,16
		mov bx,0
	l1:
		shr eax,1
		adc bx,0
		loop l1
	mov res, bx
	}
	cout << "Number of unit digits: " << res << "\n";
}
