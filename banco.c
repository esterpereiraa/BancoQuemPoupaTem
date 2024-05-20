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
    if (num_clientes >= MAX_CLIENTES) {
    printf("MAXIMO DE CLIENTES ATINGIDO\n");
    return;
  }

  Cliente novo_cliente;
  printf("BEM VINDO NOVO CLIENTE \n");
  printf("NOME: ");
  scanf(" %[^\n]%*c", novo_cliente.nome);
  printf("CPF: ");
  scanf(" %s", novo_cliente.cpf);
  printf("CONTA (comum/plus): ");
  scanf(" %s", novo_cliente.tipo_de_conta);
  printf("SALDO INCIAL: ");
  scanf(" %f", &novo_cliente.saldo);
  printf("SENHA: ");
  scanf(" %s", novo_cliente.senha);

  clientes[num_clientes] = novo_cliente;
  num_clientes++;
  salvar();
  printf("Novo cliente cadastrado!!!\n");
}
void listando(){
    printf("       LISTANDO CLIENTES\n");
  for (int i = 0; i < num_clientes; i++) {
    printf("============ CLIENTE %d ==================\n\n", i + 1);
    printf("Nome: %s\n", clientes[i].nome);
    printf("CPF: %s\n", clientes[i].cpf);
    printf("Tipo de conta: %s\n", clientes[i].tipo_de_conta);
    printf("Saldo: %.2f\n", clientes[i].saldo);
    printf("Senha: %s\n", clientes[i].senha);
    printf("==========================================\n\n");
  }
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