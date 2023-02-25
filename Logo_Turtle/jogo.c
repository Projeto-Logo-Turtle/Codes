/*Pre processamento para linkedição do codigo pelo linker, programa auxiliar que funciona junto ao processo de compilação (Build do CodeBlocks).*/
///L
#include <iso646.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
///A
#include "menu.h"
#include "jogo.h"
///D
//Optei por tirar as definições e coloca-las no jogo.h. para facilitar mas mudanças entre os desenvolvedores.
///S
//não tem signatures. aqui ficam os blocos dos codigos.
  void chamada_game()
{
    ///Variables
    char canva[largura][altura];
    entr quantidade[20];

    ///Code
    system("cls");
    //printf("chegou");

    ///Calls
    chama_print_tabu(canva);
    inputs(quantidade);

    //sleep(5);
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

inputs(entr quantidade[20])
{
    //ou o tabuleiro vem aqui, antes dos comandos

    // melhor vir a recursão dele

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



/*
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
*/

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
    default:
        system("cls");
        tela_fim();
        system("pause");
        return 0;
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

void tela_fim(){
deadline();
printf("\n\n\tObrigado por ter jogado! se voce salvou o jogo, abra a pasta do executvel\n\n");
deadline();
}

//I_G = Identificador_Generico

int board(char I_G[largura][altura]) {
    // fecha a primeira linha e a última linha
    for (int i = 0; i < altura; i++) {
        I_G[0][i] = '#';
        I_G[largura-1][i] = '#';
    }

    // fecha as linhas do meio
    for (int i = 1; i < largura-1; i++) {
        I_G[i][0] = '#';
        I_G[i][altura-1] = '#';
        for (int j = 1; j < altura-1; j++) {
            I_G[i][j] = ' ';
        }
    }
    return 0;
}

void imprimir_tabuleiro(char I_G[largura][altura]) {
    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {
            printf("%c", I_G[i][j]);
        }
        printf("\n");
    }
}

int chama_print_tabu(char I_G[largura][altura]) {
    board(I_G);
    imprimir_tabuleiro(I_G);
    return 0;
}

