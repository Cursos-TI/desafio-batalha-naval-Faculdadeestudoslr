#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + NAVIO > TAMANHO) return 0;  // Verifica limites horizontais
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) return 0;  // Verifica sobreposição
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'V') {
        if (linha + NAVIO > TAMANHO) return 0;  // Verifica limites verticais
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) return 0;  // Verifica sobreposição
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else {
        return 0;  // Orientação inválida
    }
    return 1;
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e orientações predefinidas
    if (!posicionarNavio(tabuleiro, 2, 3, 'H')) {
        printf("Falha ao posicionar navio horizontal!\n");
    }
    if (!posicionarNavio(tabuleiro, 5, 5, 'V')) {
        printf("Falha ao posicionar navio vertical!\n");
    }

    printf("Tabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}