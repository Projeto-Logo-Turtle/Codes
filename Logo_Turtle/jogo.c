#include "menu.h"
#include "jogo.h" // precisei incluir o cabeçalho do jogo pois mandei o novo tipo de variável pra lá e ficará disponivel pra todos que acessarem.
#include <iso646.h> //biblioteca de operadores logicos
#include <ctype.h>      //para uso da função "isdigit"
#include <time.h>  //para delays
game()
{
    system("cls");
    deadline();
    printf("\n\t\t\tLets play!\n\n\t\tMovimentos: frente, tras, cima, baixo (ou digite fim para sair).\n\t\tValores de 1 ate 10\n\n");

    entr quantidade[20];
    inputs(quantidade);
    teste_inputs(quantidade);
sleep(5);
transition();
}

inputs(entr quantidade[20])
{
    int indice; //optei por tirar a declaração do parametro do for.
    for (indice = 0; indice < 20; indice++)
    {
        ALOCATION_COMANDO:
        printf("\nDigite o Comando %d: ", indice); // acredito que posso colocar as contagens
        scanf("%s", quantidade[indice].comando);

        if (strcmp(quantidade[indice].comando, "fim") == 0) {
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
       if (strcmp(quantidade[contagem].comando, "fim") == 0) {
        break;
    }
        printf("Entrada %d: Comando=%s, Passos=%d\n\n", contagem, quantidade[contagem].comando, quantidade[contagem].passos);

    }
    deadline();
}

transition() {

    char start = '1';
    switch(start) {
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





deadline();
