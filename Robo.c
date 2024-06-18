#include <stdio.h>

int main() {
    int L, C, A, B, i, j, linha = 0, coluna = 0, direcao = 0; // direcao: 0-Norte, 1-Leste, 2-Sul, 3-Oeste
    int mapa[1000][1000];

    scanf("%d %d", &L, &C);
    scanf("%d %d", &A, &B);
    linha = A;
    coluna = B;

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            scanf("%d", &mapa[i][j]);
        }
    }

    // Encontrar o próximo ladrilho preto
    while (1) {
        if (direcao == 0) { // Norte
            if (linha > 1 && mapa[linha - 1][coluna] == 1) {
                linha--;
                direcao = 0;
            } else if (coluna < C && mapa[linha][coluna + 1] == 1) {
                coluna++;
                direcao = 1;
            } else if (linha < L && mapa[linha + 1][coluna] == 1) {
                linha++;
                direcao = 2;
            } else if (coluna > 1 && mapa[linha][coluna - 1] == 1) {
                coluna--;
                direcao = 3;
            }
        } else if (direcao == 1) { // Leste
            if (coluna < C && mapa[linha][coluna + 1] == 1) {
                coluna++;
                direcao = 1;
            } else if (linha < L && mapa[linha + 1][coluna] == 1) {
                linha++;
                direcao = 2;
            } else if (coluna > 1 && mapa[linha][coluna - 1] == 1) {
                coluna--;
                direcao = 3;
            } else if (linha > 1 && mapa[linha - 1][coluna] == 1) {
                linha--;
                direcao = 0;
            }
        } else if (direcao == 2) { // Sul
            if (linha < L && mapa[linha + 1][coluna] == 1) {
                linha++;
                direcao = 2;
            } else if (coluna > 1 && mapa[linha][coluna - 1] == 1) {
                coluna--;
                direcao = 3;
            } else if (linha > 1 && mapa[linha - 1][coluna] == 1) {
                linha--;
                direcao = 0;
            } else if (coluna < C && mapa[linha][coluna + 1] == 1) {
                coluna++;
                direcao = 1;
            }
        } else if (direcao == 3) { // Oeste
            if (coluna > 1 && mapa[linha][coluna - 1] == 1) {
                coluna--;
                direcao = 3;
            } else if (linha > 1 && mapa[linha - 1][coluna] == 1) {
                linha--;
                direcao = 0;
            } else if (coluna < C && mapa[linha][coluna + 1] == 1) {
                coluna++;
                direcao = 1;
            } else if (linha < L && mapa[linha + 1][coluna] == 1) {
                linha++;
                direcao = 2;
            }
        }

        // Se o robô encontrar seu ponto de partida, ele está em um ciclo.
        if (linha == A && coluna == B) {
            printf("-1 -1\n");
            return 0;
        }
    }

    printf("%d %d\n", linha, coluna);
    return 0;
}