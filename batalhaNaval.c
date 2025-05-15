#include <stdio.h>

#define TAMANHO_TABULEIRO 10   // Tamanho fixo do tabuleiro 10x10
#define TAMANHO_NAVIO 3        // Tamanho fixo dos navios

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Verifica se ultrapassa limite direito
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0; // Verifica sobreposição
    }
    return 1;
}

// Função para verificar se um navio pode ser posicionado verticalmente
int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Verifica se ultrapassa limite inferior
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0; // Verifica sobreposição
    }
    return 1;
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

int main() {
    // Declaração e inicialização do tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios (definidas diretamente no código)
    int linhaNavioH = 2, colunaNavioH = 4; // Navio horizontal
    int linhaNavioV = 5, colunaNavioV = 1; // Navio vertical

    // Verificações e posicionamentos
    if (podePosicionarHorizontal(tabuleiro, linhaNavioH, colunaNavioH)) {
        posicionarNavioHorizontal(tabuleiro, linhaNavioH, colunaNavioH);
    } else {
        printf("Erro: Não é possível posicionar o navio horizontal nas coordenadas (%d, %d).\n", linhaNavioH, colunaNavioH);
    }

    if (podePosicionarVertical(tabuleiro, linhaNavioV, colunaNavioV)) {
        posicionarNavioVertical(tabuleiro, linhaNavioV, colunaNavioV);
    } else {
        printf("Erro: Não é possível posicionar o navio vertical nas coordenadas (%d, %d).\n", linhaNavioV, colunaNavioV);
    }

    // Impressão final do tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}