#include <stdio.h>
#include <stdlib.h>
#define Largura 100
#define Altura 50
///usarei
deadline() {
  for (int i = 0; i < Largura; i++) {
    printf("#");
  }
  printf("\n");
}
///usarei
paredes() {
  printf("#");
  for (int i = 1; i < Largura - 1; i++) {
    printf(" ");
  }
  printf("#\n");
}

int main()
///não entendi{
  char board[Altura][Largura];
  int player;
  int row, col;
///não entendi
  // inicializa a matriz com espaços em branco
  int i;
  for (i =0 ; i < Altura; i++) {
    for (int j = 0; j < Largura; j++) {
      board[i][j] = ' ';
    }
  }

  while (1) {
    // Imprime a barreira
    system("cls");
    deadline();
    for(int medida = 0; medida< Altura; medida++){
      paredes();
    }


    // Lê a jogada do jogador atual
    deadline();
    printf("Jogador %d, digite a linha e a coluna para a sua jogada: ", player);
    scanf("%d %d", &row, &col);

    // Verifica se a jogada é válida
    if (row < 0 || row >= Altura || col < 0 || col >= Largura) {
      printf("Jogada inválida. Tente novamente.\n");
      continue;
    }
    if (board[row][col] != ' ') {
      printf("Essa posição já está ocupada. Tente novamente.\n");
      continue;
    }

    // Atualiza a matriz com a jogada do jogador atual
    if (player == 1) {
      board[row][col] = 'X';
      player = 2;
    } else {
      board[row][col] = 'O';
      player = 1;
    }
  }

  return 0;
}

