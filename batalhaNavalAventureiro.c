#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Imprime o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se pode posicionar navio horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0;
    }
    return 1;
}

// Verifica se pode posicionar navio verticalmente
int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    return 1;
}

// Verifica se pode posicionar navio na diagonal principal (↘)
int podePosicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0;
    }
    return 1;
}

// Verifica se pode posicionar navio na diagonal secundária (↙)
int podePosicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - (TAMANHO_NAVIO - 1) < 0) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != 0) return 0;
    }
    return 1;
}

// Posicionamento das quatro orientações
void posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

void posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

void posicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
}

void posicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos 4 navios
    int l1 = 0, c1 = 1; // horizontal
    int l2 = 5, c2 = 4; // vertical
    int l3 = 2, c3 = 2; // diagonal ↘
    int l4 = 1, c4 = 7; // diagonal ↙

    // Posicionamento horizontal
    if (podePosicionarHorizontal(tabuleiro, l1, c1)) {
        posicionarHorizontal(tabuleiro, l1, c1);
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    // Posicionamento vertical
    if (podePosicionarVertical(tabuleiro, l2, c2)) {
        posicionarVertical(tabuleiro, l2, c2);
    } else {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Posicionamento diagonal principal
    if (podePosicionarDiagonalPrincipal(tabuleiro, l3, c3)) {
        posicionarDiagonalPrincipal(tabuleiro, l3, c3);
    } else {
        printf("Erro ao posicionar navio diagonal principal.\n");
    }

    // Posicionamento diagonal secundária
    if (podePosicionarDiagonalSecundaria(tabuleiro, l4, c4)) {
        posicionarDiagonalSecundaria(tabuleiro, l4, c4);
    } else {
        printf("Erro ao posicionar navio diagonal secundária.\n");
    }

    // Exibe o resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
