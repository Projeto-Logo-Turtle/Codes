/*
game()
{
    system("cls");
     entr quantidade[20];
    imprime_board();



criar_matriz();
    ir_para_meio();
    imprime_board();





    inputs(quantidade);
    teste_inputs(quantidade);
sleep(5);
transition();







}

criar_matriz() {
    char matriz[largura][altura];
    int i, j;
    for (i = 0; i < largura; i++) {
        for (j = 0; j < altura; j++) {
            matriz[i][j] = ' ';
        }
    }
}


gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

ir_para_meio() {
    int meio_x = largura / 2;
    int meio_y = altura / 2;
    gotoxy(meio_x, meio_y);
}


movimentar(char matriz[largura][altura], int *eixo_x, int *eixo_y, entr quantidade[], int indice) {
    indice =0;
    int contagem = 0;
    int i; // indice do for
    switch(quantidade[indice].comando[0]) {
        case 'f': // frente
            for (i = 0; i < quantidade[contagem].passos; i++) {
                matriz[*eixo_x][*eixo_y] = '-';
                (*eixo_x)++;
            }
            break;
        case 't': // tras
            for (i = 0; i < quantidade[contagem].passos; i++) {
                matriz[*eixo_x][*eixo_y] = '-';
                (*eixo_x)--;
            }
            break;
        case 'c': // cima
            for (i = 0; i < quantidade[contagem].passos; i++) {
                matriz[*eixo_x][*eixo_y] = '|';
                (*eixo_y)--;
            }
            break;
        case 'b': // baixo
            for (i = 0; i < quantidade[contagem].passos; i++) {
                matriz[*eixo_x][*eixo_y] = '|';
                (*eixo_y)++;
            }
            break;
        default:
            printf("Direcao invalida!");
    }
    gotoxy(*eixo_x, *eixo_y);
    printf("%c", matriz[*eixo_x][*eixo_y]);
}

*/
