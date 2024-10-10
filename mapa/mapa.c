#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fazerReserva();
void listarReserva();
void listarPessoasPorDia();
void sair();
void mostrarMenu();

struct reserva 
{
    char nome[50];
    char cpf[14];
    int diaReserva;
    int qtdPessoas;
};

struct reserva reservas[100];

int arrayIndex = 0;


int main() {
    int opcao = 0;

    do {
        mostrarMenu();

    } while (opcao != 0);

    return 0;

}

void fazerReserva() {

    struct reserva reserva;

    char nome[50];
    char cpf[14];
    int diaReserva;
    int qtdPessoas;

    printf("Digite seu nome: \n");
    scanf("%s", &nome);

    printf("Digite cpf nome: \n");
    scanf("%s", &cpf);

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
    strcpy(reserva.cpf, cpf);
    reserva.diaReserva = diaReserva;
    reserva.qtdPessoas = qtdPessoas;

    reservas[arrayIndex] = reserva;
    arrayIndex++;

    // printf("=========================================\n");
    // printf("reserva.nome = %s \n", reserva.nome);
    // printf("reserva.cpf = %d \n", reserva.cpf);
    // printf("reserva.diaReserva = %d \n", reserva.diaReserva);
    // printf("reserva.qtdPessoas = %d \n", reserva.qtdPessoas);
    // printf("=========================================\n");

    // printf("=========================================\n");
    // printf("reservas[0].nome = %s \n", reservas[0].nome);
    // printf("reservas[0].cpf = %d \n", reservas[0].cpf);
    // printf("reservas[0].diaReserva = %d \n", reservas[0].diaReserva);
    // printf("reservas[0].qtdPessoas = %d \n", reservas[0].qtdPessoas);
    // printf("=========================================\n");

    // if (reservas[0].diaReserva == 1) {
    //     printf("=========================================\n");
    //     printf("reservas[0].diaReserva == 1 eh verdadeiro\n");
    //     printf("=========================================\n");
    // }
    
    printf("Reserva efetuada com sucesso!\n");

    mostrarMenu();

}

void listarReserva() {
    for (int i = 0; i < arrayIndex; i++) {
        printf("\n");
        printf("Nome: %s \n", reservas[i].nome);
        printf("CPF: %d \n", reservas[i].cpf);
        printf("Dia: %d \n", reservas[i].diaReserva);
        printf("Numero de Pessoas: %d \n", reservas[i].qtdPessoas);
        printf("===============================");
    }
}

void listarPessoasPorDia() {
    printf("listarPessoasPorDia");
    mostrarMenu();
}

void sair() {
    printf("Saindo do programa!");
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