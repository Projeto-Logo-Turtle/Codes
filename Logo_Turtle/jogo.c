#include "menu.h"
#include "jogo.h" // precisei incluir o cabeçalho do jogo pois mandei o novo tipo de variável pra lá e ficará disponivel pra todos que acessarem.
#include <iso646.h> //biblioteca de operadores logicos
game()
{
    system("cls");
    deadline();
    printf("\n\t\t\tLets play!\n\n\t\tMovimentos: frente, tras, cima, baixo\n\t\tValores de 1 ate 10\n\n");

    entr quantidade[20];
    inputs(quantidade);
    teste_inputs(quantidade);
}

inputs(entr quantidade[20])
{
    int indice; //optei por tirar a declaração do parametro do for.
    for (indice = 0; indice < 20; indice++)
    {
        ALOCATION_COMANDO:
        printf("\nDigite o Comando %d: ", indice); // acredito que posso colocar as contagens
        scanf("%s", quantidade[indice].comando);


        if(not (strcmp(quantidade[indice].comando, "frente") == 0 or
                strcmp(quantidade[indice].comando, "tras") == 0 or
                strcmp(quantidade[indice].comando, "cima") == 0 or
                strcmp(quantidade[indice].comando, "baixo") == 0))
        {
            //indice--; // não precisa decrementar o indice pra voltar, vasta colocar um if na mesma linha.
            printf("\nRepita:");
            goto ALOCATION_COMANDO;
        }

        ALOCATION_VALOR:

        printf(" Valor %d: ", indice);
        scanf("%d", &quantidade[indice].passos);

        if (quantidade[indice].passos < 1 or quantidade[indice].passos > 10)
        {
            printf("Repita:\n");
            goto ALOCATION_VALOR;
        }


    }
}

teste_inputs(entr quantidade[])
{
    //função para exibir as entradas da matriz quantidade
    system("cls");
    deadline();
    printf("\n\n\t\tSeus comandos foram:");
    int contagem;
    for (contagem = 0; contagem < 20; contagem++)
    {
        printf("Entrada %d: Comando=%s, Passos=%d\n", contagem, quantidade[contagem].comando, quantidade[contagem].passos);

    }
    system("pause");system("pause");system("pause");system("pause");system("pause");system("pause");system("pause");system("pause");system("pause");system("pause");
}

deadline();
