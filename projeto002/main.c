#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> //-> usado no windows
//#include <unistd.h> -> usado no linux ou mac

typedef struct {
    int SKU;
    char nome[30];
    float preco;
}Produto;

typedef struct {
    int quantidade = 0;
    Produto pruduto;
} Carrinho;

void infoProduto(Produto prod);
void menu(); //gerar um menu qnd for inicializado
void cadastrarProduto();
void listarProduto();
void comprarProduto();
void vizualizarCarrinho();
void fecharPedido();
Produto buscaSKU(int codigo);
int *temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main(void) {
    menu();
    return 0;
}

void infoProduto(Produto prod){
    printf("Codigo: %d\n"
           "Nome: %s\n"
           "Valor: %.2f\n", prod.SKU, strtok(prod.nome, "\n"), prod.preco);
}

void menu(){
    int opcao;
    printf("================================\n"
           "========== Bem-vindo! ==========\n"
           "========= Muscle Store =========\n"
           "================================\n");

    printf("Selecione uma das opcoes abaixo:\n"
           "1 - Cadastro de produto\n"
           "2 - Listagem de produtos\n"
           "3 - Compra de produtos\n"
           "4 - Carrinho\n"
           "5 - Fechar pedido\n"
           "6 - Sair do sistema\n");
        scanf("%i", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            cadastrarProduto();
            break;

        case 2:
            listarProduto();
            break;

        case 3:
            comprarProduto();
            break;

        case 4:
            vizualizarCarrinho();
            break;

        case 5:
            fecharPedido();
            break;

        case 6:
            printf("Volte sempre!\n");
            Sleep(2);
            exit(0);
            break;

        default:
            printf("Opcao invalida!");
            Sleep(2);
            menu();
            break;
    }
}

void cadastrarProduto(){
    printf("Cadastro de Produto\n"
           "===================\n");

    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produto].nome, 30, stdin);

    printf("Informe o valor do produto: \n");
    scanf("%f", &produtos[contador_produto].nome);
    getchar();

    printf("O produto %s foi cadastrado com sucesso\n", strtok(produtos[contador_produto].nome, "\n"));

    produtos[contador_produto].SKU = (contador_produto + 1);
    contador_produto++;
}

void listarProduto(){
    for (int i = 0; i <= contador_produto; i++) {
        printf("========== Produto %i ==========\n"
               "Nome: %s\n"
               "Valor: %.2f\n"
               "SKU: %i \n", i, produtos[i].nome, produtos[i].preco, produtos[i].SKU);
    }

}

void comprarProduto(){
}

void vizualizarCarrinho(){
}

void fecharPedido(){
}

Produto buscaSKU(int codigo){
}

int *temNoCarrinho(int codigo){
}
