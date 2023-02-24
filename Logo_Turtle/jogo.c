#include "menu.h"
#include "jogo.h" // precisei incluir o cabeçalho do jogo pois mandei o novo tipo de variável pra lá e ficará disponivel pra todos que acessarem.
#include <iso646.h> //biblioteca de operadores logicos
#include <ctype.h>      //para uso da função "isdigit"
#include <time.h>  //para delay
#include <windows.h>    //cara gotoxy, equivalente a ncurses.h


///Definições


#define largura 100
#define altura 50


chamada_game()
{
    system("cls");
    //declaração de variáveis
    char tabuleiro[largura][altura];
entr quantidade[20];
    // chama a função para criar e preencher o tabuleiro
    board(tabuleiro);

    // chama a função para imprimir o tabuleiro
    imprimir_tabuleiro(tabuleiro);

    // chama a função para receber inputs do usuário
    inputs(quantidade);

    // chama a função para testar os inputs do usuário
    //teste_inputs(quantidade);

    sleep(5);
    transition();
}



/*int board (char tabuleiro[largura][altura]) {
    int linha, coluna;
    for (linha = 0; linha < largura; linha++) {
        if (linha == 0 || linha == largura-1) {
            // imprime a primeira e última linha com #
            for (coluna = 0; coluna < altura; coluna++) {
                tabuleiro[largura][altura];
            }
            printf("\n");
        } else {
            // imprime as linhas internas com # no começo e fim
            printf("#");
            for (coluna = 1; coluna < altura - 1; coluna++) {
                printf("%c", tabuleiro[linha][coluna]);
            }
            printf("#\n");
        }
    }



}
*/

board (char tabuleiro[largura][altura]) {
    // Inicializa a primeira linha e a última linha
    for (int i = 0; i < largura; i++) {
        tabuleiro[0][i] = '#';
        tabuleiro[altura-1][i] = '#';
    }

    // Inicializa as linhas do meio
    for (int i = 1; i < altura-1; i++) {
        tabuleiro[i][0] = '#';
        tabuleiro[i][largura-1] = '#';
        for (int j = 1; j < largura-1; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

imprimir_tabuleiro(char tabuleiro[altura][largura]) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}















inputs(entr quantidade[20])
{
    //ou o tabuleiro vem aqui, antes dos comandos










    int indice; //optei por tirar a declaração do parametro do for.
    for (indice = 0; indice < 20; indice++)
    {
ALOCATION_COMANDO:
        printf("\nDigite o Comando %d: ", indice); // acredito que posso colocar as contagens
        scanf("%s", quantidade[indice].comando);

        if (strcmp(quantidade[indice].comando, "fim") == 0)
        {
            break; // sai do loop for
        }
        else if(not (strcmp(quantidade[indice].comando, "frente") == 0 or
                     strcmp(quantidade[indice].comando, "tras") == 0 or
                     strcmp(quantidade[indice].comando, "cima") == 0 or
                     strcmp(quantidade[indice].comando, "baixo") == 0))
        {
            //indice--; // não precisa decrementar o indice pra voltar, vasta colocar um if na mesma linha.
            printf("\nRepita:");
            goto ALOCATION_COMANDO;
        }

ALOCATION_VALOR:
        printf("Valor %d: ", indice);
        scanf("%d", &quantidade[indice].passos); // com o valor inteiro ela está bugando

        /*if(not isdigit(quantidade[indice].passos) or (quantidade[indice].passos < 1 or quantidade[indice].passos > 10))
            {
                //indice--; // não precisa decrementar o indice pra voltar, vasta colocar um if na mesma linha.
                printf("\nRepita:");
                goto ALOCATION_VALOR;
            }*/


    }

    //Aqui vem o tabuleiro, enquanto n descubro como partir a função





}




teste_inputs(entr quantidade[])
{
    //função para exibir as entradas da matriz quantidade
    system("cls");
    deadline();
    printf("\n\n\t\tSeus comandos foram:\n\n\n");
    int contagem;
    for (contagem = 0; contagem < 20; contagem++)
    {
        if (strcmp(quantidade[contagem].comando, "fim") == 0)
        {
            break;
        }
        printf("Entrada %d: Comando=%s, Passos=%d\n\n", contagem, quantidade[contagem].comando, quantidade[contagem].passos);

    }
    deadline();
}

transition()
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
    }
}




/*imprime_board()
{
    //tirei o while

    system("cls");
    printf("\n\t\t\tLets play!\n\n\t\tMovimentos: frente, tras, cima, baixo (ou digite fim para sair).\n\t\tValores de 1 ate 10\n\n");
    deadline();
    for (int medida = 0; medida < altura; medida++)
    {
        paredes();
    }
    deadline();

}*/



teste_matriz(char tabuleiro[largura][altura]) {
    tabuleiro[10][10] = 'X';

}

