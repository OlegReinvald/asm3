#include <iostream>
using namespace std;

int main2() {
	int x_solutions[8];
	int y_solutions[8];
	_asm {
	mov eax, 0
	mov ebx, 0
	mov edx, 0
	
	x_inc:
		inc eax
		mov ebx, 0
		mov edx, 0
		mov esi, eax
		imul esi, 2
		cmp esi, 50
		jg exit
		y_inc:
			inc ebx
			add edx, eax
			add edx, eax
			add edx, ebx
			add edx, ebx
			add edx, ebx
			cmp edx, 50
			je solution
			jl y_inc
			jg x_inc
			

	solution:
		mov x_solutions[ecx], eax
		mov y_solutions[ecx], ebx
		inc ecx
		jmp x_inc
	exit:
	}

	for (int i = 0; i < 8; i++) {
		cout << "x = " << x_solutions[i] << "	y = " << y_solutions << "\n";
	}
	return 0;
}