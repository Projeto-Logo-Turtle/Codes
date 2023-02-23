#include <stdio.h>
#include <stdlib.h>
#define Largura 100
#define Altura 50

///usarei
void deadline() {
  for (int i = 0; i < Largura; i++) {
    printf("#");
  }
  printf("\n");
}

///usarei
void paredes() {
  printf("#");
  for (int i = 1; i < Largura - 1; i++) {
    printf(" ");
  }
  printf("#\n");
}

int main() {
  char board[Altura][Largura];
  int player = 1;
  int row = 0, col = 0;

  // inicializa a matriz com espaços em branco
  for (int i = 0; i < Altura; i++) {
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

    // Imprime a matriz atualizada com as jogadas dos jogadores
    for (int i = 0; i < Altura; i++) {
      printf("#");
      for (int j = 0; j < Largura - 2; j++) {
        if (board[i][j] == ' ') {
          printf(" ");
        } else {
          printf("%c", board[i][j]);
        }
      }
      printf("#\n");
    }

    // Lê a jogada do jogador atual
    deadline();
    printf("Jogador %d, digite a linha e a coluna para a sua jogada: ", player);
    scanf("%d %d", &row, &col);


    // Atualiza a matriz com a jogada do jogador atual
    if (player == 1) {
      board[row][col] = '-';
      player = 2;
    } else {
      board[row][col] = '-';
      player = 1;
    }
  }

  return 0;
}
