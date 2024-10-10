#include <stdio.h>
#include <string.h>

void fazerReserva();
void listarReserva();
void listarPessoasPorDia();
void sair();

struct reserva 
{
    char nome[50];
    int cpf;
    int diaReserva;
    int qtdPessoas;
};

struct reserva reservas[100];

void mostrarMenu();

int main() {
    int opcao = 0;

    do {

        mostrarMenu();

    } while (opcao != 0);

}

void fazerReserva() {

    struct reserva reserva;

    char nome[50];
    int cpf;
    int diaReserva;
    int qtdPessoas;

    printf("Digite seu nome: \n");
    scanf("%s", &nome);

    printf("Digite cpf nome: \n");
    scanf("%d", &cpf);

    printf("Digite o dia da reserva: \n");
    scanf("%d", &diaReserva);

    while (diaReserva < 1 || diaReserva > 5) {
        printf("Valor inválido! Por favor, tente novamente. \n");
        printf("Digite o dia da reserva: \n");
        scanf("%d", &diaReserva);
    }

    printf("Digite a quantidade de pessoas: \n");
    scanf("%d", &qtdPessoas);

    while (qtdPessoas < 1) {
        printf("Valor inválido! Por favor, tente novamente. \n");
        printf("Digite a quantidade de pessoas: \n");
        scanf("%d", &qtdPessoas);
    }

    strcpy(reserva.nome, nome);
    reserva.cpf = cpf;
    reserva.diaReserva = diaReserva;
    reserva.qtdPessoas = qtdPessoas;

}

void listarReserva() {
    printf("listarReserva");
}

void listarPessoasPorDia() {
    printf("listarPessoasPorDia");
}

void sair() {
    printf("sair");
}

void mostrarMenu() {
    int escolha;
    
    printf("Bem-vindo(a) ao restaurante.");
    printf("\nPara seguirmos, escolha uma das opções abaixo: \n");
    
    printf("1 - Fazer Reserva. \n");
    printf("2 - Listar Reserva. \n");
    printf("3 - Total de Pessoas Por Dia. \n");
    printf("4 - Sair. \n");

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
        break;
    }

}