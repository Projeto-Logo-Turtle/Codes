#include <stdio.h>
#include <conio.h>

int main()
{
    const int WIDTH = 10;
    const int HEIGHT = 10;

    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    while (1) {
        clrscr();  // Limpa a tela

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == y && j == x) {
                    cprintf("*");
                } else {
                    cprintf(".");
                }
            }
            cprintf("\n");
        }

        char direction = getch();  // Lê um caractere sem precisar pressionar Enter

        if (direction == 'q') {
            break;
        } else if (direction == 'a' && x > 0) {
            x--;
        } else if (direction == 'd' && x < WIDTH - 1) {
            x++;
        } else if (direction == 'w' && y > 0) {
            y--;
        } else if (direction == 's' && y < HEIGHT - 1) {
            y++;
        }
    }

    return 0;
}
