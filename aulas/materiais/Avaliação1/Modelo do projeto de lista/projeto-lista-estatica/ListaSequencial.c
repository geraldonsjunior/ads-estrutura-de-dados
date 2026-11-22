#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

// Aloca a struct no Heap e inicializa o contador com 0
Lista *cria_lista()
{
    Lista *minha_lista = (Lista *)malloc(sizeof(Lista));
    if (minha_lista != NULL)
    {
        minha_lista->qtd = 0;
    }
    return minha_lista;
}

// Libera a memória alocada dinamicamente
void libera_lista(Lista *minha_lista)
{
    if (minha_lista != NULL)
    {
        free(minha_lista);
    }
}

// Retorna a quantidade de elementos armazenados em tempo constante O(1)
int tamanho_lista(Lista *minha_lista)
{
    if (minha_lista == NULL)
        return -1;
    return minha_lista->qtd;
}

// Retorna 1 se estiver vazia, 0 se tiver elementos
int lista_vazia(Lista *minha_lista)
{
    if (minha_lista == NULL)
        return -1;
    return (minha_lista->qtd == 0);
}

// Retorna 1 se atingiu a capacidade máxima MAX
int lista_cheia(Lista *minha_lista)
{
    if (minha_lista == NULL)
        return -1;
    return (minha_lista->qtd == MAX);
}

// Insere elemento na posição desejada deslocando os subsequentes para a direita
int insere_lista(Lista *minha_lista, int pos, int valor)
{
    if (minha_lista == NULL || lista_cheia(minha_lista))
        return 0;
    if (pos < 0 || pos > minha_lista->qtd)
        return 0;

    // Mover de trás para frente para abrir espaço sem sobrescrever
    for (int i = minha_lista->qtd - 1; i >= pos; i--)
    {
        minha_lista->dados[i + 1] = minha_lista->dados[i];
    }

    minha_lista->dados[pos] = valor;
    minha_lista->qtd++;
    return 1; // Sucesso
}

// Remove elemento na posição desejada puxando os elementos para a esquerda
int remove_lista(Lista *minha_lista, int pos)
{
    if (minha_lista == NULL || lista_vazia(minha_lista))
        return 0;
    if (pos < 0 || pos >= minha_lista->qtd)
        return 0;

    // Puxa elementos da direita para a esquerda
    for (int i = pos; i < minha_lista->qtd - 1; i++)
    {
        minha_lista->dados[i] = minha_lista->dados[i + 1];
    }

    minha_lista->qtd--;
    return 1; // Sucesso
}

// Imprime o conteúdo do vetor

void imprime_lista(Lista *minha_lista)
{
    if (minha_lista == NULL)
    {
        printf("\n[ ERRO ] Lista inexistente!\n");
        return;
    }

    if (lista_vazia(minha_lista) == 1)
    {
        printf("\n[ AVISO ] Lista esta vazia!\n");
        return;
    }

    printf("\n--- CONTEUDO DA LISTA ---\n");

    for (int i = 0; i < minha_lista->qtd; i++)
    {
        printf("[%d] -> %d\n",
               i, minha_lista->dados[i]);
    }

    printf("Tamanho atual: %d / %d\n",
           minha_lista->qtd, MAX);
}
