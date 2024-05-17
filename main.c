#include <stdio.h>

int main(){

    while(1){
        int opcao;
        printf("\nMENU PRINCIPAL\n");
        printf("1 - Novo cliente\n");
        printf("2 - Apaga cliente\n");
        printf("3 - Listar clientes\n");
        printf("4 - Débito\n");
        printf("5 - Depósito\n");
        printf("6 - Extrato\n");
        printf("7 - Transferência entre contas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d",&opcao);
    switch (opcao)

    {
    case 1:
        printf("Novo cliente\n");
        break;
     case 2:
        printf("Apagar cliente\n");
        break;
    case 3:
        printf("Listar clientes\n");
        break;
    case 4:
        printf("Débito\n");
        break;
    case 5:
        printf("Depósito\n");
        break;
    case 6:
        printf("Extrato\n");
        break;
    case 7:
        printf("Transferência entre contas\n");
        break;
    case 0:  
        printf("Sair\n");
        return 0; 
    default:
        printf("OPÇÂO INVALIDA\n\n");
        break;
    }
    }
    return 0;
}