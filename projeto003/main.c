#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int codigo;
    char nome[50];
    char email[50];
    char cpf[20];
    char nascimento[20];
    char dataCadastro[20];
}User;
typedef struct {
    int numeroConta;
    User cliente;
    float limete;
    float saldo;
    float saldoTotal; //limite + saldo
}Accont;

void menu();
void infoCliente(User cliente);
void infoConta(Accont conta);
void criarConta();
void efetuarSaque();
void efetuarDeposito();
void efetuarTransferencia();
void listarContas();
float atualizaSaldoTotal(Accont conta);
Accont buscarContaPorNumero();
void sacar(Accont conta, float valor);
void depositar(Accont conta, float valor);
void trasferir(Accont contaOrigem, Accont contaDestino, float valor);

static Accont contas[50];
static int contador_contas = 0;
static int contador_clientes = 0;


int main(void) {
    menu();
    return 0;
}


void menu(){
    int opcao;
    printf("\n\n================================\n"
           "=========== Bem-vindo ===========\n"
           "============== ATM ==============\n"
           "========== Muscle Bank ==========\n"
           "================================\n"
           "\n");

    printf("Selecione uma das opcoes abaixo:\n"
       "1 - Criar conta\n"
       "2 - Efetuar saque\n"
       "3 - Efetuar deposito\n"
       "4 - Efetuar transferencia\n"
       "5 - Listar contas\n"
       "6 - Sair do sistema\n");
    scanf("%i", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            criarConta();
            break;

        case 2:
            efetuarSaque();
            break;

        case 3:
            efetuarDeposito();
            break;

        case 4:
            efetuarTransferencia();
            break;

        case 5:
            listarContas();
            break;
        case 6:
            printf("Ate logo!\n");
            Sleep(2000);
            exit(0);

        default:
            printf("Opcao invalida\n");
        Sleep(2000);
        menu();
        break;
    }
}

void infoCliente(User cliente){
    printf("Codigo: %i\n"
           "Nome: %s\n"
           "Email: %s\n"
           "CPF: %s\n"
           "Data de Nascimento: %s\n"
           "Data de Cadastro: %s\n", cliente.codigo, strtok(cliente.nome, "\n"), strtok(cliente.email, "\n"),
           strtok(cliente.cpf, "\n"), strtok(cliente.nascimento, "\n"), strtok(cliente.dataCadastro, "\n"));
}

void infoConta(Accont conta){
    printf("Numero da Conta: %i\n"
       "Cliente: %s\n"
       "Data de Nascimento: %s\n"
       "Data de Cadastro: %s\n"
       "Limete: %.2f\n"
       "Saldo: %.2f\n"
       "Saldo Total: %.2f\n", conta.numeroConta, strtok(conta.cliente.nome, "\n"),
       strtok(conta.cliente.nascimento, "\n"), strtok(conta.cliente.dataCadastro, "\n"),
       conta.limete, conta.saldo, conta.saldoTotal);
}

void criarConta(){

}

void efetuarSaque(){

}

void efetuarDeposito() {

}

void efetuarTransferencia(){

}

void listarContas(){

}

float atualizaSaldoTotal(Accont conta){

}

Accont buscarContaPorNumero(int numero){

}

void sacar(Accont conta, float valor){

}

void depositar(Accont conta, float valor){

}

void trasferir(Accont contaOrigem, Accont contaDestino, float valor){

}
