
#include <stdio.h>
#include "ListaSequencial.h"

int main()
{
    Lista *minha_lista = cria_lista();

    if (minha_lista == NULL)
    {
        printf("Erro ao alocar a lista.\n");
        return 1;
    }

    int opcao;
    int posicao;
    int valor;

    do
    {
        printf("\n=================================\n");
        printf("     MENU - LISTA SEQUENCIAL\n");
        printf("=================================\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Excluir elemento\n");
        printf("3 - Listar elementos\n");
        printf("4 - Consultar tamanho\n");
        printf("0 - Sair\n");
        printf("=================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
        {
            int tipo_insercao;

            // Verifica se a lista esta cheia
            if (lista_cheia(minha_lista))
            {
                printf("\nImpossivel inserir: a lista esta cheia!\n");
                break;
            }

            // Menu de insercao
            printf("\n--- INSERCAO DE ELEMENTO ---\n");
            printf("1 - Inserir no final da lista\n");
            printf("2 - Inserir em uma posicao especifica\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &tipo_insercao);

            // Define a posicao de insercao
            if (tipo_insercao == 1)
            {
                posicao = tamanho_lista(minha_lista);
            }
            else if (tipo_insercao == 2)
            {
                printf("\nQuantidade de elementos: %d\n",
                       tamanho_lista(minha_lista));

                printf("Digite a posicao (0 ate %d): ",
                       tamanho_lista(minha_lista));
                scanf("%d", &posicao);

                // Valida a posicao informada
                if (posicao < 0 ||
                    posicao > tamanho_lista(minha_lista))
                {
                    printf("Posicao invalida!\n");
                    break;
                }
            }
            else
            {
                printf("Opcao invalida!\n");
                break;
            }

            // Solicita o valor
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);

            // Realiza a insercao
            if (insere_lista(minha_lista, posicao, valor))
            {
                printf("Elemento inserido com sucesso na posicao %d!\n",
                       posicao);
            }
            else
            {
                printf("Nao foi possivel inserir o elemento.\n");
            }

            break;
        }

        case 2:
            // Exclusao

            if (minha_lista == NULL)
            {
                printf("\nErro: lista inexistente!\n");
                break;
            }

            if (lista_vazia(minha_lista) == 1)
            {
                printf("\nImpossivel excluir: a lista esta vazia!\n");
                printf("Insira um elemento antes de excluir.\n");
                break;
            }

            printf("\nElementos atuais da lista:\n");
            imprime_lista(minha_lista);

            printf("\nDigite a posicao do elemento a excluir: ");
            scanf("%d", &posicao);

            if (remove_lista(minha_lista, posicao))
            {
                printf("Elemento removido com sucesso!\n");
            }
            else
            {
                printf("Nao foi possivel remover o elemento.\n");
                printf("Verifique se a posicao informada e valida.\n");
            }

            break;

        case 3:
            // Listagem
            printf("\nElementos da lista:\n");

            if (lista_vazia(minha_lista))
            {
                printf("A lista esta vazia.\n");
            }
            else
            {
                imprime_lista(minha_lista);
            }
            break;

        case 4:
            // Consulta de estado
            printf("\nQuantidade de elementos: %d\n",
                   tamanho_lista(minha_lista));

            printf("Lista vazia? %s\n",
                   lista_vazia(minha_lista) ? "Sim" : "Nao");

            printf("Lista cheia? %s\n",
                   lista_cheia(minha_lista) ? "Sim" : "Nao");
            break;

        case 0:
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    // Liberacao da memoria
    libera_lista(minha_lista);
    minha_lista = NULL;

    printf("Memoria liberada com sucesso!\n");

    return 0;
}
