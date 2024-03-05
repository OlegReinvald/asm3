#include<iostream>
using namespace std;
int main() {
    int x[8];
    int y[8];
    _asm {
        xor ecx, ecx
        mov ecx, 16
        mov esi, 0
        cycle1:
        push ecx
            mov eax, ecx
            mov ecx, 24
            cycle2 :
            mov ebx, ecx
            mov edx, 3
            imul edx, eax
            add edx, ebx
            add edx, ebx
            cmp edx, 50
            jne flag1
            mov y[esi], eax
            mov x[esi], ebx
            add esi, 4
            flag1 :
        loop cycle2
            pop ecx
            loop cycle1
    }
    for (size_t i = 0; i < 8; ++i)
    {
        if (2 * x[i] + 3 * y[i] == 50) {
            cout << "2*" << x[i] << " + 3 *" << y[i] << " = 50" << '\n';
        }
        else {
            cout << "Error";
            return 1;
        }
    }
}
