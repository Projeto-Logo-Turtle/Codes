#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

#include "menu.h"
#include "jogo.h"
#include "registro.h"
#include "movimento.h"
#include "about.h"


void about()
{
    system("cls");
    //

    printf("\n\n\n\tAlunos:\n\t\t\tPedro Bulle\n\t\t\tVinicius Jose\n\n\n\n\n\t\tHold 'D' to exit or spam 'F' to go crazy");
    teto_cha1();
    //

   system("cls");
   inicial();
        }





void teto_cha1(){

    char indica;
    bool continuar = true;

    while (continuar){
        int teto = 0, muro = 0;

        if (kbhit()) { // verifica se há uma tecla disponível
            indica = getch(); // obtém o caractere digitado pelo usuário
            if (indica == 'd') {
                continuar = false;
                break; // sai do loop while
            }
        }

        for (int i = 0; i <= 100; i++) {
            gotoxy(teto, muro);
            printf("#");
            Sleep(1000/1000);
            teto++;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }

        for (int i = 0; i <= 10; i++) {
            gotoxy(teto, muro);
            printf("#");
            Sleep(1000/1000);
            muro++;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }

        for (int i = 0; i <= 100; i++) {
            gotoxy(teto, muro);
            printf("#");
            Sleep(1000/1000);
            teto--;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }

        for (int i = 0; i <= 10; i++) {
            gotoxy(teto, muro);
            printf("#");
            Sleep(1000/1000);
            muro--;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }

        /// apaga

        for (int i = 0; i <= 100; i++) {
            gotoxy(teto, muro);
            printf(" ");
            Sleep(1000/1000);
            teto++;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }

        for (int i = 0; i <= 10; i++) {
            gotoxy(teto, muro);
            printf(" ");
            Sleep(1000/1000);
            muro++;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }

        for (int i = 0; i <= 100; i++) {
            gotoxy(teto, muro);
            printf(" ");
            Sleep(1000/1000);
            teto--;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }

        for (int i = 0; i <= 10; i++) {
            gotoxy(teto, muro);
            printf(" ");
            Sleep(1000/1000);
            muro--;
            if (kbhit() && getch() == 'f') break;
            else if (kbhit() && getch() == 'd') goto loop_end;
        }
    }
    loop_end:
        system ("cls");
}





void gotoxy(int x, int y) {
    COORD coord;  // Estrutura que representa uma coordenada no console
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    // Define a posição do cursor na tela
}

