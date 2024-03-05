#include <iostream>
using namespace std;

int main() {
	int num, den;
	bool sign;
	cin >> num >> den;
	if (num < 0) {
		sign = 1;
		num *= -1;
	}
	if (num == 0) {
		cout << "\n" << 0;
		return 0;
	}
	_asm {
		mov eax, num
		mov ebx, den
		cmp eax, ebx
		jg Evklid
		mov ecx, ebx
		mov ebx, eax
		mov eax, ecx
		Evklid :
		xor edx, edx
			cdq
			div ebx
			cmp edx, 0
			je reduce
			mov eax, ebx
			mov ebx, edx
			jmp Evklid
			reduce :
		mov eax, num
			cdq
			div ebx
			mov num, eax
			mov eax, den
			cdq
			div ebx
			mov den, eax
	}
	if (sign) {
		cout << "\n-" << num << "/" << den;
	}
	else
	{
		cout << "\n" << num << "/" << den;
	}
	return 0;
}
