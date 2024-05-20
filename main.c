#include <stdio.h>
#include "banco.h" 

int main(){
 
    carregar();
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
        // CHAMANDO AS FUNCOES
    case 1:
        addCliente();
        break;
     case 2:
        apagar();
        break;
    case 3:
        listando();
        break;
    case 4:
        debito();
        break;
    case 5:
        deposito();
        break;
    case 6:
        extrato();
        break;
    case 7:
        transferencia();
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