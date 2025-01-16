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
void saque();
void deposito();
void transferencia();




int main(void) {
    menu();
    return 0;
}