#include <iostream>
using namespace std;

int main() {
	long int a, result;
	cin >> a;
	_asm {
		mov eax, a
		mov ebx, 1
		mov edx, 1
		mov ecx, 8
		a_8:
			imul ebx, a
			dec ecx
			cmp ecx, 0
			jne a_8
		add eax, ebx
		mov ecx, 12
		cmp eax, eax
		a_12:
			imul edx, a
			dec ecx
			cmp ecx, 0
			jne a_12
		add eax, edx
		mov result, eax
	}
	cout << result;
	return 0;
}
