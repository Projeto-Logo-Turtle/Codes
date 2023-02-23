#include <stdio.h>
#include <stdlib.h>

#define Largura 100
#define Altura 50

void deadline() {
    for (int i = 0; i < Largura; i++) {
        printf("#");
    }
    printf("\n");
}

void paredes() {
    printf("#");
    for (int i = 1; i < Largura - 1; i++) {
        printf(" ");
    }
    printf("#\n");
}

void Imprime_Board() {
    while (1) {
        system("cls");
        deadline();
        for (int medida = 0; medida < Altura; medida++) {
            paredes();
        }
        deadline();
    }
}

int main() {
    Imprime_Board();
    return 0;
}
