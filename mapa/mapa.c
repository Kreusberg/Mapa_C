#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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

    // Limpa o buffer antes de solicitar as informações ao usuário
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite cpf nome: ");
    fgets(cpf, sizeof(cpf), stdin);

    printf("Digite o dia da reserva: ");
    scanf("%d", &diaReserva);

    while (diaReserva < 1 || diaReserva > 5) {
        printf("Valor inválido! Por favor, tente novamente. \n");
        printf("Digite o dia da reserva: ");
        scanf("%d", &diaReserva);
    }

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &qtdPessoas);

    while (qtdPessoas < 1) {
        printf("Valor inválido! Por favor, tente novamente. \n");
        printf("Digite a quantidade de pessoas: ");
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

    printf("Digite o dia para verificar quantas pessoas estão reservadas: ");
    scanf("%d", &dia);

    while (dia < 1 || dia > 5) {
        printf("Valor inválido! Por favor, tente novamente. \n");
        printf("Digite o dia da reserva: \n");
        scanf("%d", dia);
    }

    for (int i = 0; i < arrayIndex; i++) {
        printf("sum = %d \n \n", sum);
        sum += reservas[i].qtdPessoas;
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