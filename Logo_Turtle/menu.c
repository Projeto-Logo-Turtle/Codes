///L
#include <conio.h>
///A
#include "menu.h"
#include "jogo.h"
#include "about.h"
///D
///S

///CALL
int chamada_menu()
{   system("cls");
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

void deadline(){for(int i = 0; i<= altura*2; i++){printf("#");}printf("\n");}

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
        xau();
        break;
    default:
        goto options;
    }
}


        xau(){
        system("cls");
        deadline();
        printf("\n\n\t\t\Obrigado e ateh++\n\n");
        deadline();
            system("pause");
        }




        instructions(int coord_x, int coord_y){

           const char tartaruga= 1;

printf("\n   coord atual: x = %i\n                                               use the rose wind to move:\n", coord_x);
printf("                y = %i\n                                                                        |              norte\n", coord_y);
printf(" Instructions:                                                          |     noroeste   |   nordeste\n");
printf(" move - move a tartaruga para as coordenadas                            |              \\ | /\n");
printf(" save - Salva seu desenho atual num arquivo txt                         |    oeste  ---- %c --- leste\n", tartaruga);
printf(" desfaz - retorna ao estado anterior                                    |              / | \\ \n");
printf(" fim - finaliza seu desenho                                             |     sudoeste   |   sudeste\n");
printf("                                                                        |               sul\n\n");
deadline();

        }
