#include "menu.h"
#include "jogo.h" // precisei incluir o cabeçalho do jogo pois mandei o novo tipo de variável pra lá e ficará disponivel pra todos que acessarem.
game()
{
    system("cls");
    deadline();
    printf("\n\t\t\tLets play!\n\n");
    intpus();
    teste_inputs();
}



inputs(entr quantidade[20])
{




    for (int indice = 0; indice < 20; indice++)
    {
        printf("\nDigite o Comando: ");
        scanf("%s", quantidade[indice].comando);
        printf(" Valor: ");
        scanf("%d", &quantidade[indice].passos);

    }
}

teste_inputs(entr quantidade[])
{
    //função para exibir as entradas da matriz quantidade
    printf("Respostas:");
    int contagem;
    for (contagem = 0; contagem < 20; contagem++)
    {
        printf("Entrada %d: Comando=%s, Passos=%d\n", contagem, quantidade[contagem].comando, quantidade[contagem].passos);
    }
}
deadline();

