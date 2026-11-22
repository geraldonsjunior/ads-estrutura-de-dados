#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 4

// Estrutura que representa a lista sequencial estática[cite: 6]
struct lista
{
    int qtd;        // Número atual de elementos armazenados[cite: 6]
    int dados[MAX]; // Array contíguo na memória[cite: 6]
};

typedef struct lista Lista;

// Protótipos das funções do TAD
Lista *cria_lista();
void libera_lista(Lista *minha_lista);
int tamanho_lista(Lista *minha_lista);
int lista_vazia(Lista *minha_lista);
int lista_cheia(Lista *minha_lista);
int insere_lista(Lista *minha_lista, int pos, int valor);
int remove_lista(Lista *minha_lista, int pos);
void imprime_lista(Lista *minha_lista);

#endif // LISTA_SEQUENCIAL_H