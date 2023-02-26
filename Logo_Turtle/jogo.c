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

    primeira_chamada(canva);
    movimenta_tartaruga(canva, quantidade);
    sleep(2);
    transition(canva);
    chamada_menu();

}




int transition(char matriz[largura][altura])
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

void tela_fim(char matriz [largura][altura]){
deadline();
printf("\n\n\tObrigado por ter jogado! Se voce salvou o jogo, abra a pasta do executavel\n\n\tVeja como ficou seu desenho\n\n");
imprimir_tabuleiro(matriz);
printf("\n");
deadline();
}

//I_G = Identificador_Generico


void primeira_position(char I_G[largura][altura])// so será usada 1 vez
{
/*
    I_G[(largura/2)][(altura/2)+1] = '#';  //+1 em altura vai pra frente,
    I_G[(largura/2)+1][(altura/2)] = '#';  //+1 em largura vai pra baixo
    */
    I_G[largura/2][altura/2] = 1;
}


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

void primeira_chamada(char I_G[largura][altura]){

    board(I_G);
    primeira_position(I_G);
    imprimir_tabuleiro(I_G);

}
///------------------Função principal - Dividir-------------------------------------------------------------------------
int movimenta_tartaruga(char matriz[largura][altura], entr quantidade[20])
{
    ///Var
    int indice;
    int x = largura / 2; // Define a posição inicial da tartaruga no meio da matriz
    int y = altura / 2;
    matriz[x][y] = 1; // Imprime a tartaruga no centro da matriz


    ///codigos

    for (indice = 0; indice < 20; indice++)
    {

    //aqui a função das regras

        ALOCATION_COMANDO:
        printf("\nDigite o Comando %d: ", indice+1); // acredito que posso colocar as contagens
        scanf("%s", quantidade[indice].comando);

        if(strcmp(quantidade[indice].comando, "fim") == 0)
        {
            break; // sai do loop for
        }

        else if (strcmp(quantidade[indice].comando, "save") == 0){
            char *matriz_point = &matriz;
            salvar_matriz(matriz_point);
            printf("\nSalvo!\n");
            continue;
            }
        else if (strcmp(quantidade[indice].comando, "move") == 0){
            goto MOVIMENTATION;
        }
        else if(not (strcmp(quantidade[indice].comando, "sudoeste") == 0 or
                     strcmp(quantidade[indice].comando, "sudeste") == 0 or
                     strcmp(quantidade[indice].comando, "noroeste") == 0 or
                     strcmp(quantidade[indice].comando, "nordeste") == 0 or
                     strcmp(quantidade[indice].comando, "leste") == 0 or
                     strcmp(quantidade[indice].comando, "oeste") == 0 or
                     strcmp(quantidade[indice].comando, "norte") == 0 or
                     strcmp(quantidade[indice].comando, "sul") == 0))
        {
            //indice--; // não precisa decrementar o indice pra voltar, vasta colocar um if na mesma linha.
            printf("\nRepita:");
            goto ALOCATION_COMANDO;
        }

        ALOCATION_VALOR:
        printf("Valor %d: ", indice+1);
        scanf("%d", &quantidade[indice].passos); // com o valor inteiro ela está bugando

///----------fim da coleta inicio do desenho-------------------------------------------------------------


        MOVIMENTATION:

        if (strcmp(quantidade[indice].comando, "fim") == 0) {
                return matriz[x][y];
            break;
        }
        else if (strcmp(quantidade[indice].comando, "leste") == 0) { matriz[x][y] = '-';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y + 1 < altura) {
                    y++;
                    matriz[x][y] = '-';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;
        }
        else if (strcmp(quantidade[indice].comando, "oeste") == 0) { matriz[x][y] = '-';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y - 1 >= 0) {
                    y--;
                    matriz[x][y] = '-';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;
        }
        else if (strcmp(quantidade[indice].comando, "norte") == 0) { matriz[x][y] = '|';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (x - 1 >= 0) {
                    x--;
                    matriz[x][y] = '|';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;
        }
        else if (strcmp(quantidade[indice].comando, "sul") == 0) { matriz[x][y] = '|';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (x + 1 < largura) {
                    x++;
                    matriz[x][y] = '|';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;

        }
        else if (strcmp(quantidade[indice].comando, "noroeste") == 0) { matriz[x][y] = '\\';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y - 1 >= 0) {
                    x--; //norte
                    y--; //oeste
                    matriz[x][y] = '\\';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;
        }
        else if (strcmp(quantidade[indice].comando, "nordeste") == 0) { matriz[x][y] = '/';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y - 1 >= 0) {
                    x--; //norte
                    y++; //leste
                    matriz[x][y] = '/';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;
        }
        else if (strcmp(quantidade[indice].comando, "sudoeste") == 0) { matriz[x][y] = '/';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y - 1 >= 0) {
                    x++; //sul
                    y--; //oeste
                    matriz[x][y] = '/';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;
        }
        else if (strcmp(quantidade[indice].comando, "sudeste") == 0) { matriz[x][y] = '\\';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y - 1 >= 0) {
                    x++; //sul
                    y++; //leste
                    matriz[x][y] = '\\';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;
        }

        else if (strcmp(quantidade[indice].comando, "move") == 0) {

            matriz[x][y] = ' ';
            int novo_X, novo_y;
            printf("\nDigite a coordenada em X: ");
            scanf("%d", &novo_X);
            printf("\nDigite a coordenada em Y: ");
            scanf("%d", &novo_y);
            x=novo_X;
            y=novo_y;
            matriz[x][y] = 1;

        }
    //dentro do for, fora dos ifs
    system("cls");
    imprimir_tabuleiro(matriz);
    }
}
