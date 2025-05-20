#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Exemplo de navios (representado por 3)
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[6][6] = 3;
}

// Função para imprimir o tabuleiro com valores numéricos
void imprimirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Gera a matriz de habilidade em forma de cone (triângulo)
void gerarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Gera a matriz de habilidade em forma de cruz
void gerarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Gera a matriz de habilidade em forma de octaedro (losango)
void gerarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Aplica a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + i - TAM_HAB / 2;
                int colunaTab = origemColuna + j - TAM_HAB / 2;

                // Verifica se a posição está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM_TAB && colunaTab >= 0 && colunaTab < TAM_TAB) {
                    if (tabuleiro[linhaTab][colunaTab] != 3) {
                        tabuleiro[linhaTab][colunaTab] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int habilidade[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    printf("=== Habilidade: CONE ===\n");
    gerarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 2);
    imprimirTabuleiro(tabuleiro);

    printf("\n=== Habilidade: CRUZ ===\n");
    inicializarTabuleiro(tabuleiro);
    gerarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    imprimirTabuleiro(tabuleiro);

    printf("\n=== Habilidade: OCTAEDRO ===\n");
    inicializarTabuleiro(tabuleiro);
    gerarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 7, 7);
    imprimirTabuleiro(tabuleiro);

    return 0;
}
