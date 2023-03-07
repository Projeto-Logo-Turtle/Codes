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





///------------------Função principal - Dividir------------------------------------------------------------------------
int movimenta_tartaruga(char matriz[altura][largura], entr quantidade[20])
{
    ///Var

    int indice;
    int x = altura / 2; // Define a posição inicial da tartaruga no meio da matriz
    int y = largura / 2;
    matriz[x][y] = 1; // Imprime a tartaruga no centro da matriz
    char backup [altura][largura];
    int bck_X, bck_Y;

    int coord_x, coord_y;
    ///codigos

    for (indice = 0; indice < 20; indice++)
    {

    coord_x = y;
    coord_y = x;

        instructions(coord_x, coord_y);

        //bloco de substituição do backup
        /*
           for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        */
        //------------


    //aqui a função das regras

        ALOCATION_COMANDO:
        printf("\nDigite o Comando %d: ", indice+1); // acredito que posso colocar as contagens
        scanf("%s", quantidade[indice].comando);

        if(strcmp(quantidade[indice].comando, "fim") == 0)
        {
           goto MOVIMENTATION;
           // break; // sai do loop for
        }

        else if (strcmp(quantidade[indice].comando, "save") == 0){
            //char *matriz_point = &matriz; ponteiro para ver a partir da main

            //condições encadeadas para substituir o ultimo caractere, para n imprimir a tartaruga
                if (strcmp(quantidade[indice-1].comando, "leste") == 0) { matriz[x][y] = '-';}
                else if (strcmp(quantidade[indice-1].comando, "oeste") == 0) { matriz[x][y] = '-';}
                else if (strcmp(quantidade[indice-1].comando, "norte") == 0) { matriz[x][y] = '|';}
                else if (strcmp(quantidade[indice-1].comando, "sul") == 0) { matriz[x][y] = '|';}

                else if (strcmp(quantidade[indice-1].comando, "nordeste") == 0) { matriz[x][y] = '/';}
                else if (strcmp(quantidade[indice-1].comando, "sudoeste") == 0) { matriz[x][y] = '/';}
                else if (strcmp(quantidade[indice-1].comando, "noroeste") == 0) { matriz[x][y] = '\\';}
                else if (strcmp(quantidade[indice-1].comando, "sudeste") == 0) { matriz[x][y] = '\\';}

                else if (strcmp(quantidade[indice-1].comando, "move") == 0) { matriz[x][y] = ' ';}

            salvar_matriz(matriz);

            system("cls");
            imprimir_tabuleiro(matriz);
            printf("\nSalvo!\n");
            continue;
            }
        else if (strcmp(quantidade[indice].comando, "move") == 0){
            goto MOVIMENTATION;
        }
        else if (strcmp(quantidade[indice].comando, "desfaz") == 0){
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

///----------fim da coleta inicio do desenho------------------------------------------------------------


        MOVIMENTATION:



        if (strcmp(quantidade[indice].comando, "fim") == 0) {
                // não está chegando aqui
                /*debug
                system("cls");
                printf("chegou. o comando foi: %s", quantidade[indice-1].comando);
                system("pause");
                */
                //condições encadeadas para substituir o ultimo caractere, para n imprimir a tartaruga
                if (strcmp(quantidade[indice-1].comando, "leste") == 0) { matriz[x][y] = '-';}
                else if (strcmp(quantidade[indice-1].comando, "oeste") == 0) { matriz[x][y] = '-';}
                else if (strcmp(quantidade[indice-1].comando, "norte") == 0) { matriz[x][y] = '|';}
                else if (strcmp(quantidade[indice-1].comando, "sul") == 0) { matriz[x][y] = '|';}

                else if (strcmp(quantidade[indice-1].comando, "nordeste") == 0) { matriz[x][y] = '/';}
                else if (strcmp(quantidade[indice-1].comando, "sudoeste") == 0) { matriz[x][y] = '/';}
                else if (strcmp(quantidade[indice-1].comando, "noroeste") == 0) { matriz[x][y] = '\\';}
                else if (strcmp(quantidade[indice-1].comando, "sudeste") == 0) { matriz[x][y] = '\\';}

                else if (strcmp(quantidade[indice-1].comando, "move") == 0) { matriz[x][y] = ' ';}



                return matriz[x][y];
            break;
        }
        else if (strcmp(quantidade[indice].comando, "leste") == 0) {
                //bloco de substituição do backup
                bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------


                matriz[x][y] = '-';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y + 1 < largura) {
                    y++;
                    matriz[x][y] = '-';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;



        }
        else if (strcmp(quantidade[indice].comando, "oeste") == 0) {
                 //bloco de substituição do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------


                matriz[x][y] = '-';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y - 1 >= 0) {
                    y--;
                    matriz[x][y] = '-';

                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;


        }
        else if (strcmp(quantidade[indice].comando, "norte") == 0) {

                 //bloco de substituição do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------


                matriz[x][y] = '|';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (x - 1 >= 0) {
                    x--;
                    matriz[x][y] = '|';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;

        }
        else if (strcmp(quantidade[indice].comando, "sul") == 0) {

                //bloco de substituição do backup
                bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------

                matriz[x][y] = '|';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (x + 1 < altura) {
                    x++;
                    matriz[x][y] = '|';
                }
            }
            // Atualiza a posição da tartaruga
            matriz[x][y] = 1;



        }
        else if (strcmp(quantidade[indice].comando, "noroeste") == 0) {

                 //bloco de substituição do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------

                matriz[x][y] = '\\';

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
        else if (strcmp(quantidade[indice].comando, "nordeste") == 0) {

                 //bloco de substituição do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------

                matriz[x][y] = '/';

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
        else if (strcmp(quantidade[indice].comando, "sudoeste") == 0) {

                 //bloco de substituição do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------

                matriz[x][y] = '/';

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
        else if (strcmp(quantidade[indice].comando, "sudeste") == 0) {

                 //bloco de substituição do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------

                matriz[x][y] = '\\';

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
            //if(){}
            //coordenadas trocadas e retirado 1 pois a matriz começa em [0][0]
            printf("\nDigite a coordenada em X: ");
            scanf("%d", &novo_y);
            printf("\nDigite a coordenada em Y: ");
            scanf("%d", &novo_X);

            x=novo_X-1;
            y=novo_y-1;
            matriz[x][y] = 1;

        }
        else if (strcmp(quantidade[indice].comando, "desfaz") == 0){
    // recupera os valores da matriz backup
    //matriz[x][y] = ' '; // é esperado que fiquem duas tartarugas, ent essa primeira vai apagar

    x = bck_X;
    y = bck_Y;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            matriz[i][j] = backup[i][j];
        }
    }
    //matriz[x][y] = 1; e aqui vai trazer de volta

    printf ("\nFeito!\n");
    goto FIM;
}

    //dentro do for, fora dos ifs
    FIM:
    system("cls");
    imprimir_tabuleiro(matriz);
    //imprimir_tabuleiro(backup);
    }
}
