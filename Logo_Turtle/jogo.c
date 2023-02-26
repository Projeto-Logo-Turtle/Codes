/*Pre processamento para linkedi��o do codigo pelo linker, programa auxiliar que funciona junto ao processo de compila��o (Build do CodeBlocks).*/
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
//Optei por tirar as defini��es e coloca-las no jogo.h. para facilitar mas mudan�as entre os desenvolvedores.
///S
//n�o tem signatures. aqui ficam os blocos dos codigos.
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


void primeira_position(char I_G[largura][altura])// so ser� usada 1 vez
{
/*
    I_G[(largura/2)][(altura/2)+1] = '#';  //+1 em altura vai pra frente,
    I_G[(largura/2)+1][(altura/2)] = '#';  //+1 em largura vai pra baixo
    */
    I_G[largura/2][altura/2] = 1;
}


int board(char I_G[largura][altura]) {
    // fecha a primeira linha e a �ltima linha
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



///------------------Fun��o principal - Dividir-------------------------------------------------------------------------
int movimenta_tartaruga(char matriz[largura][altura], entr quantidade[20])
{
    ///Var

    int indice;
    int x = largura / 2; // Define a posi��o inicial da tartaruga no meio da matriz
    int y = altura / 2;
    matriz[x][y] = 1; // Imprime a tartaruga no centro da matriz
    char backup [largura][altura];
    int bck_X, bck_Y;


    ///codigos

    for (indice = 0; indice < 20; indice++)
    {
        //bloco de substitui��o do backup
        /*
           for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        */
        //------------


    //aqui a fun��o das regras

        ALOCATION_COMANDO:
        printf("\nDigite o Comando %d: ", indice+1); // acredito que posso colocar as contagens
        scanf("%s", quantidade[indice].comando);

        if(strcmp(quantidade[indice].comando, "fim") == 0)
        {
           goto MOVIMENTATION;
           // break; // sai do loop for
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
            //indice--; // n�o precisa decrementar o indice pra voltar, vasta colocar um if na mesma linha.
            printf("\nRepita:");
            goto ALOCATION_COMANDO;
        }

        ALOCATION_VALOR:
        printf("Valor %d: ", indice+1);
        scanf("%d", &quantidade[indice].passos); // com o valor inteiro ela est� bugando

///----------fim da coleta inicio do desenho-------------------------------------------------------------


        MOVIMENTATION:



        if (strcmp(quantidade[indice].comando, "fim") == 0) {
                // n�o est� chegando aqui
                /*debug
                system("cls");
                printf("chegou. o comando foi: %s", quantidade[indice-1].comando);
                system("pause");
                */
                //condi��es encadeadas para substituir o ultimo caractere, para n imprimir a tartaruga
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
                //bloco de substitui��o do backup
                bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------


                matriz[x][y] = '-';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (y + 1 < altura) {
                    y++;
                    matriz[x][y] = '-';
                }
            }
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;



        }
        else if (strcmp(quantidade[indice].comando, "oeste") == 0) {
                 //bloco de substitui��o do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
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
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;


        }
        else if (strcmp(quantidade[indice].comando, "norte") == 0) {

                 //bloco de substitui��o do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
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
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;

        }
        else if (strcmp(quantidade[indice].comando, "sul") == 0) {

                //bloco de substitui��o do backup
                bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
            backup[i][j] = matriz[i][j];
            }
        }
        //------------

                matriz[x][y] = '|';

            for (int j = 0; j < quantidade[indice].passos; j++) {
                if (x + 1 < largura) {
                    x++;
                    matriz[x][y] = '|';
                }
            }
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;



        }
        else if (strcmp(quantidade[indice].comando, "noroeste") == 0) {

                 //bloco de substitui��o do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
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
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;


        }
        else if (strcmp(quantidade[indice].comando, "nordeste") == 0) {

                 //bloco de substitui��o do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
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
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;


        }
        else if (strcmp(quantidade[indice].comando, "sudoeste") == 0) {

                 //bloco de substitui��o do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
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
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;


        }
        else if (strcmp(quantidade[indice].comando, "sudeste") == 0) {

                 //bloco de substitui��o do backup
                 bck_X = x; bck_Y = y;
            for (int i = 0; i < largura; i++) {
                for (int j = 0; j < altura; j++) {
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
            // Atualiza a posi��o da tartaruga
            matriz[x][y] = 1;


        }

        else if (strcmp(quantidade[indice].comando, "move") == 0) {

            matriz[x][y] = ' ';
            int novo_X, novo_y;
            //if(){}
            //coordenadas trocadas e retirado 1 pois a matriz come�a em [0][0]
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
    //matriz[x][y] = ' '; // � esperado que fiquem duas tartarugas, ent essa primeira vai apagar

    x = bck_X;
    y = bck_Y;
    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {
            matriz[i][j] = backup[i][j];
        }
    }
    //matriz[x][y] = 1;e aqui vai trazer de volta

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
