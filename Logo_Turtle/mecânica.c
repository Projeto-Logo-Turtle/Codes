///L
#include <iso646.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
///A
#include "menu.h"
#include "jogo.h"
#include "registro.h"
#include "mecânica.h"


int input_movimento (char matriz[largura][altura], entr quantidade[20], int ordem){
 ///Var
    int indice;
    indice = ordem;
      ALOCATION_COMANDO:
        printf("\nDigite o Comando %d: ", indice+1); // acredito que posso colocar as contagens
        scanf("%s", quantidade[indice].comando);

        if(strcmp(quantidade[indice].comando, "fim") == 0)
        {
           return; // msm ideia do break; mas só são usados em loop
        }

        else if (strcmp(quantidade[indice].comando, "save") == 0){
            char *matriz_point = &matriz;
            salvar_matriz(matriz_point);
            printf("\nSalvo!\n");
            return; // msm ideia do continue;
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

}



int movimenta_tartaruga(char matriz[largura][altura], entr quantidade[20], int ordem)
{


    ///Var
    int indice;
    int x = largura / 2; // Define a posição inicial da tartaruga no meio da matriz
    int y = altura / 2;
    ///Atribuições
    matriz[x][y] = 1; // Imprime a tartaruga no centro da matriz
    indice = ordem;
    ///codigos


        if (strcmp(quantidade[indice].comando, "fim") == 0) {
                return matriz[x][y];

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
    //dentro do for, fora dos ifs
    system("cls");
    imprimir_tabuleiro(matriz);
    }

