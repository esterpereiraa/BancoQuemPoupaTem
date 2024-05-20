#ifndef BANCO_H
#define BANCO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 1000
#define MAX_OPERACOES 100

typedef struct {
    char nome[100];
    char cpf[15];
    char tipo_de_conta[10];
    float saldo;
    char senha[20];
} Cliente;

typedef struct {
    char data[30];
    char descricao[200];
    float valor;
} Operacao;

void addCliente();
void apagar();
void listando();
void debito();
void deposito();
void extrato();
void transferencia();
void salvar();
void carregar();

#endif
