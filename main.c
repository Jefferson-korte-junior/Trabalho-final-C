#include <stdio.h>
#include <windows.h>

#define QTD_PRODUTOS 5  // Define a quantidade de produtos a serem cadastrados

// Estrutura que define as características de um produto
struct produto {
    char nome[50];        // Nome do produto
    float valorCompra;    // Valor de compra do produto
    float valorVenda;     // Valor de venda do produto
    float lucro;          // Lucro obtido com a venda do produto
    int qtdVendas;        // Quantidade de vendas do produto
};

int main() {
    // Array para armazenar os produtos
    struct produto produtos[QTD_PRODUTOS];

    // Cabeçalho inicial
    printf("=============================================\n");
    printf("             CADASTRO DE PRODUTOS            \n");
    printf("=============================================\n");
    printf("\n-> Iniciando cadastro de %d produto(s)...\n\n", QTD_PRODUTOS);
    Sleep(2000);  // Pausa de 2 segundos
    system("cls");  // Limpa a tela

    // Loop para cadastrar os produtos
    for (int i = 0; i < QTD_PRODUTOS; i++) {
        float valorCompra = -1;  // Inicializa/reseta a variável de valor de compra
        float valorVenda = -1;   // Inicializa/reseta a variável de valor de venda
        float qtdVf = -1;        // Inicializa/reseta a variável de quantidade vendida como float
        int qtd = -1;            // Inicializa/reseta a variável de quantidade vendida como inteiro

        // Cabeçalho de cadastro de cada produto
        printf("=============================================\n");
        printf("                 PRODUTO %d/%d               \n", i + 1, QTD_PRODUTOS);
        printf("=============================================\n");

        // Entrada do nome do produto
        printf(" > Digite o nome do produto:");
        if (fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin) != NULL) {
            size_t len = strlen(produtos[i].nome);
            if (len > 0 && produtos[i].nome[len - 1] == '\n') {
                produtos[i].nome[len - 1] = '\0';  // Remove a nova linha no final da string
            }
        }

        // Loop para obter os valores de compra, venda e quantidade
        while (valorCompra < 0 || valorVenda < 0 || qtd < 0) {
            // Entrada do valor de compra
            if (valorCompra < 0) {
                printf(" > Digite o valor de compra do(a) %s:", produtos[i].nome);
                if (scanf("%f", &valorCompra) == 1 && valorCompra >= 0) {
                    produtos[i].valorCompra = valorCompra;
                } else {
                    printf("\n -> Valor de compra invalido!\n\n");
                    valorCompra = -1;  // Reinicia o valor para forçar nova entrada
                }
                while (getchar() != '\n');  // Limpa o buffer de entrada
            }
            // Entrada do valor de venda
            else if (valorVenda < 0) {
                printf(" > Digite o valor de venda do(a) %s:", produtos[i].nome);
                if (scanf("%f", &valorVenda) == 1 && valorVenda >= 0) {
                    produtos[i].valorVenda = valorVenda;
                } else {
                    printf("\n -> Valor de venda invalido!\n\n");
                    valorVenda = -1;  // Reinicia o valor para forçar nova entrada
                }
                while (getchar() != '\n');  // Limpa o buffer de entrada
            }
            // Entrada da quantidade vendida
            else if (qtd < 0) {
                printf(" > Digite a quantidade vendida de %s(s):", produtos[i].nome);
                if (scanf("%f", &qtdVf) == 1 && qtdVf >= 0) {
                    qtd = qtdVf;
                    if (qtd == qtdVf) {
                        produtos[i].qtdVendas = qtd;
                    } else {
                        printf("\n -> Digite um numero inteiro!\n\n");
                        qtd = -1;  // Reinicia a quantidade para forçar nova entrada
                    }
                } else {
                    printf("\n -> Quantidade vendida invalida!\n\n");
                    qtd = -1;  // Reinicia a quantidade para forçar nova entrada
                }
                while (getchar() != '\n');  // Limpa o buffer de entrada
            }
        }

        // Calcula o lucro do produto
        produtos[i].lucro = produtos[i].valorVenda - produtos[i].valorCompra;
        printf("\n");
        system("cls");  // Limpa a tela antes de cadastrar o próximo produto
    }

    Sleep(1000);  // Pausa de 1 segundo antes de mostrar os produtos cadastrados
    system("cls");

    // Exibe os produtos cadastrados
    printf("=============================================\n");
    printf("             PRODUTOS CADASTRADOS            \n");
    printf("=============================================\n");

    for (int i = 0; i < QTD_PRODUTOS; i++) {
        printf(" -> NOME: %s\n", produtos[i].nome);
        printf(" -> VALOR DE COMPRA: %.2f\n", produtos[i].valorCompra);
        printf(" -> VALOR DE VENDA: %.2f\n", produtos[i].valorVenda);
        printf(" -> QUANTIDADE VENDAS: %d\n", produtos[i].qtdVendas);
        printf("_____________________________________________\n");
        Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
    }

    printf("\n-> %d Produto(s) foi/foram cadastrados!\n\n", QTD_PRODUTOS);
    system("pause");  // Pausa até que o usuário pressione uma tecla
    system("cls");

    // Ordena os produtos por lucro em ordem decrescente
    for (int i = 0; i < QTD_PRODUTOS - 1; i++) {
        if (produtos[i].lucro < produtos[i + 1].lucro) {
            struct produto aux = produtos[i + 1];
            produtos[i + 1] = produtos[i];
            produtos[i] = aux;
            i = -1;  // Reinicia o loop para garantir que a lista esteja corretamente ordenada
        }
    }

    // Exibe os produtos ordenados por lucro
    printf("=============================================\n");
    printf("                     LUCRO                   \n");
    printf("=============================================\n");

    for (int i = 0; i < QTD_PRODUTOS; i++) {
        printf(" %d. R$%.2f - %s\n", i + 1, produtos[i].lucro, produtos[i].nome);
        Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
    }

    printf("\n");

    // Verifica se todos os produtos têm o mesmo lucro
    if (produtos[0].lucro == produtos[QTD_PRODUTOS - 1].lucro) {
        printf(" Mesmo lucro:\n");
        for (int i = 0; i < QTD_PRODUTOS; i++) {
            printf(" -> R$%.2f - %s\n", produtos[i].lucro, produtos[i].nome);
            Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
        }
    } else {
        // Exibe o produto com menor lucro
        printf(" Menor lucro:\n -> R$%.2f - %s\n", produtos[QTD_PRODUTOS - 1].lucro, produtos[QTD_PRODUTOS - 1].nome);
        for (int i = 0; i < QTD_PRODUTOS - 1; i++) {
            if (produtos[i].lucro == produtos[QTD_PRODUTOS - 1].lucro) {
                printf(" -> R$%.2f - %s\n", produtos[i].lucro, produtos[i].nome);
                Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
            }
        }
        Sleep(300);
        // Exibe o produto com maior lucro
        printf(" Maior lucro:\n -> R$%.2f - %s\n", produtos[0].lucro, produtos[0].nome);
        for (int i = 1; i < QTD_PRODUTOS; i++) {
            if (produtos[i].lucro == produtos[0].lucro) {
                printf(" -> R$%.2f - %s\n", produtos[i].lucro, produtos[i].nome);
                Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
            }
        }
    }

    printf("_____________________________________________\n +\n");
    Sleep(300);  // Pausa de 0,3 segundos antes de ordenar os produtos por quantidade vendida

    // Ordena os produtos por quantidade vendida em ordem decrescente
    for (int i = 0; i < QTD_PRODUTOS - 1; i++) {
        if (produtos[i].qtdVendas < produtos[i + 1].qtdVendas) {
            struct produto aux = produtos[i + 1];
            produtos[i + 1] = produtos[i];
            produtos[i] = aux;
            i = -1;  // Reinicia o loop para garantir que a lista esteja corretamente ordenada
        }
    }

    Sleep(500);  // Pausa de 0,5 segundos antes de exibir os produtos com menor e maior quantidade de vendas
    printf("=============================================\n");
    printf("                    VENDAS                   \n");
    printf("=============================================\n");

    for (int i = 0; i < QTD_PRODUTOS; i++) {
        printf(" %d. %d unidade(s) - %s\n", i + 1, produtos[i].qtdVendas, produtos[i].nome);
        Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
    }

    printf("\n");

    // Verifica se todos os produtos têm a mesma quantidade de vendas
    if (produtos[0].qtdVendas == produtos[QTD_PRODUTOS - 1].qtdVendas) {
        printf(" Mesma quantidade:\n");
        for (int i = 0; i < QTD_PRODUTOS; i++) {
            printf(" -> %d unidade(s) - %s\n", produtos[i].qtdVendas, produtos[i].nome);
            Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
        }
    } else {
        // Exibe o produto com menor quantidade de vendas
        printf(" Menor quantidade:\n -> %d unidade(s) - %s\n", produtos[QTD_PRODUTOS - 1].qtdVendas, produtos[QTD_PRODUTOS - 1].nome);
        for (int i = 0; i < QTD_PRODUTOS - 1; i++) {
            if (produtos[i].qtdVendas == produtos[QTD_PRODUTOS - 1].qtdVendas) {
                printf(" -> %d unidade(s) - %s\n", produtos[i].qtdVendas, produtos[i].nome);
                Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
            }
        }
        Sleep(300);
        // Exibe o produto com maior quantidade de vendas
        printf(" Maior quantidade:\n -> %d unidade(s) - %s\n", produtos[0].qtdVendas, produtos[0].nome);
        for (int i = 1; i < QTD_PRODUTOS; i++) {
            if (produtos[i].qtdVendas == produtos[0].qtdVendas) {
                printf(" -> %d unidade(s) - %s\n", produtos[i].qtdVendas, produtos[i].nome);
                Sleep(300);  // Pausa de 0,3 segundos entre a exibição dos produtos
            }
        }
    }

    printf("_____________________________________________\n");
    Sleep(300);  // Pausa de 0,3 segundos antes de finalizar o programa

    return 0;
}