///L
#include <conio.h>
///A
#include "menu.h"
#include "jogo.h"
///D
///S

///CALL
int chamada_menu()
{
    inicial(); // adicionado para chamar a função
}

///FUNCTIONS
void inicial()
{
    //função na tentativa de concatenar design e switch. seria melhor uma terceira fun ou simplesmente concatenar os blocos?
    design();
    switch_menu();
    //talvez eu possa colocar tudo em um unico block, mas seguindo Djikstra² "Divide et Impera". "Dividir e reinar".
}

void deadline(){for(int i = 0; i<= largura*2; i++){printf("#");}printf("\n");}

void design(){  //void, pois eh uma function de print.

    deadline();
    printf("\n\n\t\t\t\t\tBem-vindo ao Logo Trutle!\n\n");
    printf("\t\t\t1. Iniciar Jogo\n");
    printf("\t\t\t2. About\n");
    printf("\t\t\t3. Exit\n\n");
    deadline();
}

void switch_menu()
{

    char indicador; //Variáveis locais optarei por padronizar

options:

    indicador = getch();
    switch (indicador)
    {
    case '1':
        printf("chamou");
        chamada_game();
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


void about()
{
    system("cls");
    //
    deadline();
    printf("\nAlunos:\nPedro Bulle\nVinicius Jose\n\n");
    deadline();
    //

   system("pause");
   system("cls");
   inicial();
        }



/*paredes()
{
    printf("#");
    for (int i = 1; i < largura - 1; i++)
    {
        printf(" ");
    }
    printf("#\n");
}

// que tal tentar encaixar tudo isso numa matriz, ao inves de varios printf? o melhor manter assim?
*/
