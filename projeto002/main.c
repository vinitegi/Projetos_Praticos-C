#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> // usado no Windows

typedef struct {
    int SKU;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    int quantidade;
    Produto produto;
} Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProduto();
void comprarProduto();
void vizualizarCarrinho();
void fecharPedido();
Produto buscaSKU(int codigo);
int *temNoCarrinho(int codigo);

static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main(void) {
    menu();
    return 0;
}

void infoProduto(Produto prod) {
    printf("Codigo: %d\n"
           "Nome: %s\n"
           "Valor: %.2f\n",
           prod.SKU, strtok(prod.nome, "\n"), prod.preco);
}

void menu() {
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
            Sleep(2000); // Em milissegundos
            exit(0);


        default:
            printf("Opcao invalida!\n");
            Sleep(2000);
            menu();
            break;
    }
}

void cadastrarProduto() {
    printf("\nCadastro de Produto\n"
           "===================\n");

    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produto].nome, 30, stdin);

    printf("Informe o valor do produto: \n");
    scanf("%f", &produtos[contador_produto].preco);
    getchar();

    produtos[contador_produto].SKU = (contador_produto + 1);

    printf("O produto '%s' foi cadastrado com sucesso\n",
           strtok(produtos[contador_produto].nome, "\n"));

    contador_produto++;
}

void listarProduto() {
    if (contador_produto == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        menu();
        return;
    }

    printf("Produtos cadastrados: \n");
    for (int i = 0; i < contador_produto; i++) {
        printf("================================\n");
        infoProduto(produtos[i]);
        printf("================================\n");
        Sleep(1000);
    }
}

void comprarProduto() {
    if (contador_produto > 0) {
        printf("Informe o codigo do prduto que deseja adicionar ao carrinho: \n");

        printf("======== Codigos disponiveis ========\n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produtos[i]);
            printf("-----------------------------\n");
            Sleep(1000);
        }

        int codigo;
        scanf("%i", &codigo);
        getchar();

        int tem_mercado = 0; //verifica se o codigo esta cadastrado
        for (int i = 0; i < contador_produto; i++) {
            if (produtos[i].SKU == codigo) { //verifica se o produto esta cadastrado no sistema
                tem_mercado = 1;

                //carrinho
                if (contador_carrinho > 0) { //verifica se existe carrinho
                    int *retorno = temNoCarrinho(codigo);


                    if (retorno[0] == 1) { //verifica se o produto ja esta no carrinho (se retorno[0] == 1 -> existe no carrinho
                        carrinho[retorno[1]].quantidade++;
                        printf("Produto ja existente no carrinho. Quantidade do produtos %s aumentada para %d.\n",
                        strtok(carrinho[retorno[1]].produto.nome, "\n"), carrinho[retorno[1]].quantidade);
                        Sleep(2000);
                        menu();
                    }else{ //nao existe no carrinho
                        Produto p = buscaSKU(codigo);
                        carrinho[contador_carrinho].produto = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O produto %s foi adicionado ao carrinho!\n", strtok(p.nome, "\n"));
                        Sleep(2000);
                        menu();
                    }
                } else {
                    Produto p = buscaSKU(codigo);
                    carrinho[contador_carrinho].produto = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi adicionado ao carrinho!\n", strtok(p.nome, "\n"));
                    Sleep(2000);
                    menu();
                }
            }
        }
        if (tem_mercado < 1) {
            printf("Codigo %d nao encontrado no sistema.\n", codigo);
            Sleep(2000);
            menu();
        }



    } else {
        printf("Nao existem produtos cadastrados.\n");
        Sleep(2000);
        menu();
    }
}

void vizualizarCarrinho(){
    if (contador_produto == 0) {
        printf("Nenhum produto no carrinho ainda.\n");
        menu();
        return;
    }

    printf("Produtos no carrinho: \n");

    for (int i = 0; i < contador_carrinho; i++) {
        printf("================================\n");
        infoProduto(carrinho[i].produto);
        printf("Quantidade: %i\n", carrinho[i].quantidade);
        printf("================================\n");
        Sleep(1000);
    }
}


void fecharPedido(){
    if (contador_carrinho > 0) {
        float valorTotal = 0.0;
        printf("Produtos do carrinho\n");
        printf("--------------------\n");
        for (int i = 0; i < contador_carrinho; i++) {
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;
            valorTotal += p.preco * quantidade;
            infoProduto(p);
            printf("Quantidade: %i\n", quantidade);
            printf("--------------------\n");
            Sleep(1000);
        }
        printf("Sua fatura eh de: R$%.2f\n", valorTotal);
        //limpar o carrinho
        contador_carrinho = 0;
        printf("Obrigado pela preferencia!\n");
        Sleep(5000);
        menu();
    } else {
        printf("O carrinho esta vazio!");
        Sleep(3000);
        menu();
    }
}

Produto buscaSKU(int codigo) {
    Produto p;
    for (int i = 0; i < contador_produto; i++){
        if (produtos[i].SKU == codigo) {
            p = produtos[i];
        }
    }
    return p;
}

int *temNoCarrinho(int codigo){
    int static retorno[] = {0, 0};
    for (int i = 0; i < contador_carrinho; i++) {
        if (carrinho[i].produto.SKU == codigo) {
            retorno[0] = 1; //tem o produto com esse codigo no carrinho
            retorno[1] = i; //o indice do produto no carrinho
        }
    }
    return retorno;
}
