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

void infoProduto(Produto produto){
}

void menu(){
}

void cadastrarProduto(){
}

void listarProduto(){
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
