///libs
#include <stdio.h>
///archives
#include "menu.h"
#include "jogo.h"
#include "registro.h"
#include "movimento.h"
//arquivo para as funçoes de registro

void salvar_matriz(char matriz[largura][altura]) {
    FILE *arquivo = fopen("save.txt", "w");
    if (arquivo == NULL) {
      criar_arquivo();

    }
    fputc('\n', arquivo);
    fprintf(arquivo, "\t\tSeu desenho:");
     fputc('\n', arquivo);fputc('\n', arquivo);

    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {

                fputc(matriz[i][j], arquivo);
            /*
                if (matriz[i][j] != ' ') {
            fputc(matriz[i][j], arquivo);
        }
        else if (matriz[i][j] = ' ') {
            fputc(matriz[i][j], arquivo);
        }
            */

        }
        fputc('\n', arquivo);
    }
    fputc('\n', arquivo);
    fputc('\n', arquivo);
    fprintf(arquivo, "\t\tObrigado por Jogar!");
    fclose(arquivo);

}



void criar_arquivo() {
    FILE *arquivo = fopen("save.txt", "r");
    /*if (arquivo == NULL) {
        arquivo = fopen("save.txt", "w");*/
        fclose(arquivo);
    }
