///Arquivo .c para modularizar as fun��es do menu.

///Bibliotecas
#include <conio.h> //para ultilizar o getch()

///Pr�-processamento
#include "menu.h"
#include "jogo.h"

///Defini��es nescess�rias no arquivo
#define largura 100 //Tamanho para o console



design(){           //fun��o com o design de exibi��o de texto

    deadline();
    printf("\n\n\t\t\t\t\tBem-vindo ao Logo Trutle!\n\n");
    printf("\t\t\t1. Iniciar Jogo\n");
    printf("\t\t\t2. About\n");
    printf("\t\t\t3. Exit\n\n");
    deadline();

}

menu()          //fun��o de sele��o e troca de itens do menu
{

    char indicador;
options:

    indicador = getch();
    switch (indicador)
    {
    case '1':
        game();
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


about()
{
    system("cls");
    deadline();
    printf("\nAlunos:\nPedro Bulle\nVinicius Jose\n\n");
    deadline();

   system("pause");
   system("cls");
   design();
   menu();
        }


deadline(){for(int i = 0; i<= largura; i++){printf("#");}printf("\n");}
