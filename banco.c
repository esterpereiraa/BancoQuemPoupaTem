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
   
  printf("          LISTANDO CLIENTES\n");
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
     char cpf[15];
  printf("Digite o CPF: ");
  scanf(" %s", cpf);

  for (int i = 0; i < num_clientes; i++) {
    if (strcmp(clientes[i].cpf, cpf) == 0) {
      for (int j = i; j < num_clientes - 1; j++) {
        clientes[j] = clientes[j + 1];
      }
      num_clientes--;
      salvar();
      printf("Cliente apagado!\n");
      return;
    }
  }
  printf("Cliente não encontrado!\n");
}

void deposito(){
    char cpf[15];
  float deposito;
  printf("Digite o CPF: ");
  scanf(" %s", cpf);
  printf("Digite o valor do deposito: ");
  scanf(" %f", &deposito);

  for (int i = 0; i < num_clientes; i++) {
    if (strcmp(clientes[i].cpf, cpf) == 0) {
      clientes[i].saldo += deposito;
      Operacao nova_operacao;
      time_t t = time(NULL);
      struct tm tm = *localtime(&t);
      sprintf(nova_operacao.data, "%d-%02d-%02d %02d:%02d:%02d",
              tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
              tm.tm_min, tm.tm_sec);
      sprintf(nova_operacao.descricao, "Deposito de R$ %.2f", deposito);
      nova_operacao.valor = deposito;
      operacoes[i][num_operacoes[i]] = nova_operacao;
      num_operacoes[i]++;
      salvar();
      printf("Deposito realizado com sucesso! Saldo atual: %.2f\n",
             clientes[i].saldo);
      return;
    }
  }
  printf("CLIENTE NAO ENCONTRADO!\n");
}
void debito(){
  char cpf[15], senha[20], tipo_conta[10];
  float debito;
  printf("Digite o CPF: ");
  scanf(" %s", cpf);
  printf("Digite a senha: ");
  scanf(" %s", senha);
  printf("Digite o tipo de conta (comum/plus): ");
  scanf(" %s", tipo_conta);

  for (int i = 0; i < num_clientes; i++) {
    if (strcmp(clientes[i].cpf, cpf) == 0 &&
        strcmp(clientes[i].senha, senha) == 0 &&
        strcmp(clientes[i].tipo_de_conta, tipo_conta) == 0) {
      printf("Digite o valor a debitar: ");
      scanf(" %f", &debito);

      float taxa =
          (strcmp(clientes[i].tipo_de_conta, "comum") == 0) ? 0.05 : 0.03;
      float valor_final = clientes[i].saldo - debito - (debito * taxa);
      float limite_negativo =
          (strcmp(clientes[i].tipo_de_conta, "comum") == 0) ? -1000.0 : -5000.0;

      if (valor_final < limite_negativo) {
        printf("Saldo insuficiente! A conta não pode ser negativada além do "
               "limite permitido.\n");
      } else {
        clientes[i].saldo = valor_final;
        Operacao nova_operacao;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(nova_operacao.data, "%d-%02d-%02d %02d:%02d:%02d",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
                tm.tm_min, tm.tm_sec);
        sprintf(nova_operacao.descricao, "Debito de R$ %.2f, Taxa de %.2f%%",
                debito, taxa * 100);
        nova_operacao.valor = -debito - (debito * taxa);
        operacoes[i][num_operacoes[i]] = nova_operacao;
        num_operacoes[i]++;
        salvar();
        printf("Débito realizado com sucesso! Saldo atual: %.2f\n",
               clientes[i].saldo);
      }
      return;
    }
  }
  printf("CLIENTE NAO ENCONTRADO!\n");
}
void extrato(){
    printf("EXTRATO\n");
}
void transferencia(){
    printf("TRANSFERENCIA\n");
}