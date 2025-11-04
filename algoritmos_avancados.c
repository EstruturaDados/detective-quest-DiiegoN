#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// Estrutura da sala (nó da árvore)
// -----------------------------
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// -----------------------------
// Função: criarSala
// Cria dinamicamente uma sala e define o nome
// -----------------------------
Sala* criarSala(char nome[]) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// -----------------------------
// Função: montarMansao
// Cria automaticamente a árvore binária (mapa da mansão)
// -----------------------------
Sala* montarMansao() {
    Sala* hall = criarSala("Hall de Entrada");
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Biblioteca");

    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita = criarSala("Jardim");

    hall->direita->esquerda = criarSala("Escritorio");
    hall->direita->direita = criarSala("Porão");

    return hall; // Retorna o ponto inicial do mapa
}

// -----------------------------
// Função: explorarSalas
// Permite o jogador navegar pela mansão
// -----------------------------
void explorarSalas(Sala* atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Verifica se chegou em um nó-folha (sem caminhos)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou ao fim do caminho!\n");
            break;
        }

        printf("Escolha um caminho:\n");
        printf("[e] Ir para a esquerda\n");
        printf("[d] Ir para a direita\n");
        printf("[s] Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == 'e') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Não há caminho à esquerda!\n");
        } 
        else if (escolha == 'd') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Não há caminho à direita!\n");
        } 
        else if (escolha == 's') {
            printf("Você decidiu encerrar a exploração.\n");
            break;
        } 
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// -----------------------------
// Função principal: main
// Monta o mapa e inicia a exploração
// -----------------------------
int main() {
    printf("=== Detective Quest ===\n");
    printf("Bem-vindo à mansão misteriosa!\n");

    Sala* mansao = montarMansao();
    explorarSalas(mansao);

    printf("\nExploração encerrada. Obrigado por jogar!\n");
    return 0;
}
