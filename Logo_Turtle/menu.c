///Arquivo .c para modularizar as fun��es do menu.

///Bibliotecas
#include <conio.h> //para ultilizar o getch()

///Pr�-processamento
#include "menu.h"

///Defini��es nescess�rias no arquivo
#define Largura 100 //Tamanho para o console

design(){

    for(int i = 0; i<= Largura; i++){printf("#");}
    printf("\n\n\t\t\t\t\tBem-vindo ao Logo Trutle!\n\n");
    printf("\t\t\t1. Iniciar Jogo\n");
    printf("\t\t\t2. About\n");
    printf("\t\t\t3. Exit\n\n");
    for(int i = 0; i<= Largura; i++){printf("#");}

}

menu()
{
    char indicador;
options:

    indicador = getch();
    switch (indicador)
    {
    case '1':
        jogo();
        break;
    case '2':
        about();
        break;
    case '3':
        return 0;
        break;
    default:
        goto options;
    }
}

jogo(){ system("cls");printf("\n Op��o 1 selecionada.\n");}
about(){ system("cls");printf("Op��o 2 selecionada.\n");}
