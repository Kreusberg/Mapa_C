#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void fazerReserva();
void listarReserva();
void listarPessoasPorDia();
void sair();
void mostrarMenu();

struct reserva 
{
    char nome[50];
    char cpf[12];
    int diaReserva;
    int qtdPessoas;
};

struct reserva reservas[100];

int arrayIndex = 0;


int main() {

    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;

    do {
        mostrarMenu();

    } while (opcao != 0);

    return 0;

}

void fazerReserva() {

    struct reserva reserva;
    char nome[50];
    char cpf[12];
    int diaReserva;
    int qtdPessoas = 0;
    bool validator = true;

    // Limpa o buffer antes de solicitar as informações ao usuário
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite cpf nome: ");
    fgets(cpf, sizeof(cpf), stdin);

    while (validator) {
        printf("Digite o dia da reserva: ");
        scanf("%d", &diaReserva);

        if (diaReserva < 1 || diaReserva > 5) {
           printf("Valor inválido! Por favor, tente novamente. \n"); 
        } else {
            validator = false;
        }
    }

    while (!validator) {
        printf("Digite a quantidade de pessoas: ");
        scanf("%d", &qtdPessoas);

        if (qtdPessoas < 1) {
           printf("Valor inválido! Por favor, tente novamente. \n"); 
        } else {
            validator = true;
        }
    }

    /*
        a variável validator foi declarada como true para realizar a primeira validação (dia da reserva). Caso seja informado um valor correto, seu valor passa a ser false.
        Logo, na segunda validação, fazemos a lógica ao contrário, reaproveitando a variável.
    */

    strcpy(reserva.nome, nome);
    strcpy(reserva.cpf, cpf);
    reserva.diaReserva = diaReserva;
    reserva.qtdPessoas = qtdPessoas;
    reservas[arrayIndex] = reserva;
    arrayIndex++;
    
    
    printf("Reserva efetuada com sucesso!\n\n");

    system("pause");
    mostrarMenu();

}

void listarReserva() {
    for (int i = 0; i < arrayIndex; i++) {
        printf("\n");
        printf("Nome: %s", reservas[i].nome);
        printf("CPF: %s \n", reservas[i].cpf);
        printf("Dia: %d \n", reservas[i].diaReserva);
        printf("Numero de Pessoas: %d \n", reservas[i].qtdPessoas);
        printf("===============================\n");
    }

    mostrarMenu();
}

void listarPessoasPorDia() {
    int dia;
    int sum = 0;
    bool validator = true;

    while (validator) {
        printf("Digite o dia para verificar quantas pessoas estão reservadas: ");
        scanf("%d", &dia);

        if (dia < 1 || dia > 5) {
            printf("Valor inválido! Por favor, tente novamente. \n");    
        } else {
            validator = false;
        }
    }

    printf("A quantidade de pessoas no dia %d é de %d \n", dia, sum);

    system("pause");    
    mostrarMenu();
}

void sair() {
    printf("Saindo do programa!");
}

void mostrarMenu() {
    int escolha;
    
    printf("\n Bem-vindo(a) ao restaurante.\n");
    
    printf("1 - Fazer Reserva. \n");
    printf("2 - Listar Reserva. \n");
    printf("3 - Total de Pessoas Por Dia. \n");
    printf("4 - Sair. \n");

    printf("\nPara seguirmos, escolha uma das opções abaixo: \n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        fazerReserva();
        break;
    case 2:
        listarReserva();
        break;
    case 3:
        listarPessoasPorDia();
        break;
    case 4:
        sair();
        break;
    default:
        printf("Opção inválida.");
        mostrarMenu();
        break;
    }

}