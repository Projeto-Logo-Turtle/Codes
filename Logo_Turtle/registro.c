///libs
#include <stdio.h>
///archives
#include "registro.h"
//arquivo para as funçoes de registro

void salvar_matriz(int matriz[largura][altura]) {
    FILE *arquivo = fopen("save.txt", "w");
    if (arquivo == NULL) {
      criar_arquivo();

    }

    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);

}



void criar_arquivo() {
    FILE *arquivo = fopen("save.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("save.txt", "w");
        if (arquivo == NULL) {
            printf("Erro ao criar arquivo.\n");
            return;
        }
        fclose(arquivo);
    }
}
