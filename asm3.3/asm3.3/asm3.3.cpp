#include<iostream>
using namespace std;
int main() {
    int series[47];
    series[0] = 0;
    series[1] = 1;
    _asm {
        mov esi, 8
        mov ecx, 0
        mov ebx, 1
        iter:
        mov eax, ecx
            add eax, ebx
            jo exit1
            mov series[esi], eax
            add esi, 4
            mov ecx, ebx
            mov ebx, eax
            jmp iter
            exit1 :

    }
    for (int i = 0; i < 47; i++) {
        cout << series[i] << " ";
    }
}
