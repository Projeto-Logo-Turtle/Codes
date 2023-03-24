/*Pre processamento para linkedição do codigo pelo linker, programa auxiliar que funciona junto ao processo de compilação (Build do CodeBlocks).*/
///L
#include <iso646.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
///A
#include "menu.h"
#include "jogo.h"
#include "registro.h"
#include "movimento.h"
#include "about.h"
///D
//Optei por tirar as definições e coloca-las no jogo.h. para facilitar mas mudanças entre os desenvolvedores.
///S
//não tem signatures. aqui ficam os blocos dos codigos.
  void chamada_game()
{
    ///Variables
    char canva[altura][largura];
    entr quantidade[20];
    char color;

    ///Code
    system("cls");
    //printf("chegou");

    ///Calls

    primeira_chamada(canva);
    movimenta_tartaruga(canva, quantidade);
    sleep(2);
    transition(canva);
    chamada_menu();

}




int transition(char matriz[altura][largura])
{

    char start = '1';
    switch(start)
    {
    case '1':
        system("cls");
        printf("0---");
        sleep(1);
    case '2':
        system("cls");
        printf("-0--");
        sleep(1);
    case '3':
        system("cls");
        printf("--0-");
        sleep(1);
    case '4':
        system("cls");
        printf("---0");
        sleep(1);
    default:
        system("cls");
        tela_fim(matriz);
        system("pause");
        return 0;
    }
}

void tela_fim(char matriz [altura][largura]){
deadline();
printf("\n\n\tObrigado por ter jogado! Se voce salvou o jogo, abra a pasta do executavel\n\n\tVeja como ficou seu desenho\n\n");
imprimir_tabuleiro(matriz);
printf("\n");
deadline();
}

//I_G = Identificador_Generico


void primeira_position(char I_G[altura][largura])// so será usada 1 vez
{
/*
    I_G[(altura/2)][(largura/2)+1] = '#';  //+1 em largura vai pra frente,
    I_G[(altura/2)+1][(largura/2)] = '#';  //+1 em altura vai pra baixo
    */
    I_G[altura/2][largura/2] = 1;
}


int board(char I_G[altura][largura]) {
    // fecha a primeira linha e a última linha
    for (int i = 0; i < largura; i++) {
        I_G[0][i] = '#';
        I_G[altura-1][i] = '#';
    }

    // fecha as linhas do meio
    for (int i = 1; i < altura-1; i++) {
        I_G[i][0] = '#';
        I_G[i][largura-1] = '#';
        for (int j = 1; j < largura-1; j++) {
            I_G[i][j] = ' ';
        }
    }

    return 0;
}

void imprimir_tabuleiro(char I_G[altura][largura]) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            printf("%c", I_G[i][j]);
        }
        printf("\n");
    }
}

int chama_print_tabu(char I_G[altura][largura]) {
    board(I_G);
    imprimir_tabuleiro(I_G);
    return 0;
}

void primeira_chamada(char I_G[altura][largura]){

    board(I_G);
    primeira_position(I_G);
    imprimir_tabuleiro(I_G);

}
 int colorir(){

unsigned int cor;
printf("Digite um numero:\n 1 - Azul \n 2 - Verde \n 3 - Verde Agua \n 4 - Vermelho \n 5 - Roxo \n 6 - Amarelo \n 7 - Branco\n\n  ");

do{
scanf("%d", &cor);
}while(cor < 1 || cor > 7);

if(cor == 1){
    system("COLOR 01");
}
else if (cor == 2){
    system("COLOR 02");
}
else if (cor == 3){
    system("COLOR 03");
}
else if (cor == 4){
    system("COLOR 04");
}
else if (cor == 5){
    system("COLOR 05");
}
else if (cor == 6){
    system("COLOR 06");
}
else if (cor == 7){
    system("COLOR 07");
}
}







