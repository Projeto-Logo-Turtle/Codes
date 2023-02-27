///libs
#include <stdio.h>
#include <time.h>
///archives
#include "menu.h"
#include "jogo.h"
#include "registro.h"
#include "movimento.h"
//arquivo para as funçoes de registro

void salvar_matriz(char matriz[largura][altura]) {

/// Bloco de codigo realizado com auxilio do ChatGPT
   time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);
    info = gmtime(&rawtime);
    info->tm_hour -= 3;  // Subtrai 3 horas para obter o horário de Brasília

    if (info->tm_hour < 0) {
        info->tm_hour += 24;  // Adiciona 24 horas para compensar a subtração
        info->tm_mday -= 1;   // Diminui um dia para ajustar a data
    }

    strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", info);



///


    FILE *arquivo = fopen("save.txt", "a");
    if (arquivo == NULL) {
      criar_arquivo();

    }
    fputc('\n', arquivo);
    fprintf(arquivo, "\t\tSeu desenho:\n");
    fprintf(arquivo, "Feito em: %s\n\n", buffer);
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
    fprintf(arquivo, "\t\tObrigado por Jogar!\n\n####################################################################################################\n");
    fclose(arquivo);

}


void criar_arquivo() {
    FILE *arquivo = fopen("save.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("save.txt", "w");
        fclose(arquivo);
    }
}

