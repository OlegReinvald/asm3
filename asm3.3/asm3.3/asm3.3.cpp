#include<iostream>
using namespace std;
int main() {
    int series[48];
    series[0] = 0;
    series[1] = 1;
    _asm {
        mov ecx, 2
        mov eax, 0
        mov ebx, 1
        iter:
        mov edx, 0
        add edx, eax
        add edx, ebx
        jo exit
        mov series[ecx*4], edx
        inc ecx
        mov eax, ebx
        mov ebx, edx
        jmp iter
        exit:
 
    }
    for (int i = 0; i < 47; i++) {
        cout << series[i] << " ";
    }
}