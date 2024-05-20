#include "banco.h"

Cliente clientes[MAX_CLIENTES];
Operacao operacoes[MAX_CLIENTES][MAX_OPERACOES];
int num_clientes = 0;
int num_operacoes[MAX_CLIENTES] = {0};

void salvar(){
   FILE *file = fopen("clientes.bin", "wb");
    if (file != NULL) {
        fwrite(&num_clientes, sizeof(int), 1, file);
        fwrite(clientes, sizeof(Cliente), num_clientes, file);
        fwrite(num_operacoes, sizeof(int), num_clientes, file);
    for (int i = 0; i < num_clientes; i++) {
      fwrite(operacoes[i], sizeof(Operacao), num_operacoes[i], file);
    }
    fclose(file);
  }
}
void carregar(){
    FILE *file = fopen("clientes.bin", "rb");
     if (file != NULL) {
        fread(&num_clientes, sizeof(int), 1, file);
        fread(clientes, sizeof(Cliente), num_clientes, file);
        fread(num_operacoes, sizeof(int), num_clientes, file);
    for (int i = 0; i < num_clientes; i++) {
      fread(operacoes[i], sizeof(Operacao), num_operacoes[i], file);
    }
    fclose(file);
  }
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