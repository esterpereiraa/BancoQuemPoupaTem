#include "banco.h"

Cliente clientes[MAX_CLIENTES];
Operacao operacoes[MAX_CLIENTES][MAX_OPERACOES];
int num_clientes = 0;
int num_operacoes[MAX_CLIENTES] = {0};

void salvar(){
    printf("SALVANDO");
}
void carregar(){
    printf("CARREGANDO\n");
}
void addCliente(){
    printf("ADD CLIENTES\n");
}
void listando(){
    printf("LISTANDO CLIENTES\n");
}
void apagar(){
    printf("APAGANDO CLIENTES\n");
}
void deposito(){
    printf("DEPOSITANDO\n");
}
void debito(){
    printf("DEBITO\n");
}
void extrato(){
    printf("EXTRATO\n");
}
void transferencia(){
    printf("TRANSFERENCIA\n");
}