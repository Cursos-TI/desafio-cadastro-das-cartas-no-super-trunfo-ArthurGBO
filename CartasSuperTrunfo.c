//Nível Novato

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CARTAS 28

// Função para verificar se o nome da cidade contém apenas letras e espaços
int validar_nome(const char *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (isdigit(nome[i])) {  // Verifica se há números
            return 0; // Nome inválido (contém números)
        }
    }
    return 1; // Nome válido
}

int main() {
    char codigo[MAX_CARTAS][10];  
    char nome[MAX_CARTAS][30];
    float populacao[MAX_CARTAS];
    double area[MAX_CARTAS];
    double pib[MAX_CARTAS];
    int pontos_turisticos[MAX_CARTAS];
    char continuar;
    int contador = 0;

    do {
        // Código da cidade
        printf("\nInsira o código da cidade: ");
        fgets(codigo[contador], sizeof(codigo[contador]), stdin);
        // Remover o caractere de nova linha no final, caso exista
        codigo[contador][strcspn(codigo[contador], "\n")] = 0;

        // Nome da cidade (validação)
        int nome_valido = 0;
        while (!nome_valido) {
            printf("Insira o nome da cidade: ");
            fgets(nome[contador], sizeof(nome[contador]), stdin);
            // Remover o caractere de nova linha no final, caso exista
            nome[contador][strcspn(nome[contador], "\n")] = 0;

            // Verifica se o nome contém números
            nome_valido = validar_nome(nome[contador]);

            if (!nome_valido) {
                printf("O nome da cidade não pode conter números. Tente novamente.\n");
            }
        }

        // População da cidade
        printf("Insira a população da cidade: ");
        while (scanf("%f", &populacao[contador]) != 1) {
            printf("Por favor, insira um número válido para a população.\n");
            while(getchar() != '\n');
            printf("Insira a população da cidade: ");
        }
        getchar();

        // Área da cidade
        printf("Insira a área da cidade: ");
        while (scanf("%lf", &area[contador]) != 1) {
            printf("Por favor, insira um número válido para a área.\n");
            while(getchar() != '\n');
            printf("Insira a área da cidade: ");
        }
        getchar();

        // PIB da cidade
        printf("Insira o PIB da cidade (em bilhões): ");
        while (scanf("%lf", &pib[contador]) != 1) {
            printf("Por favor, insira um número válido para o PIB.\n");
            while(getchar() != '\n'); 
            printf("Insira o PIB da cidade: ");
        }
        getchar();

        // Pontos turísticos
        printf("Insira o número de pontos turísticos: ");
        while (scanf("%d", &pontos_turisticos[contador]) != 1) {
            printf("Por favor, insira um número válido para o número de pontos turísticos.\n");
            while(getchar() != '\n');
            printf("Insira o número de pontos turísticos: ");
        }
        getchar();

        contador++;

        // Pergunta ao usuário se deseja continuar
        printf("\nDeseja cadastrar outra carta? (s/n): ");
        scanf(" %c", &continuar);
        getchar();

    } while ((continuar == 's' || continuar == 'S') && contador < MAX_CARTAS);

    // Exibição de todas as cartas cadastradas
    printf("\n--- Total de cartas cadastradas: %d ---\n", contador);
    printf("\n--- Dados das Cidades Cadastradas ---\n");
    for (int i = 0; i < contador; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Código: %s\n", codigo[i]);
        printf("Nome: %s\n", nome[i]);
        printf("População: %.3f\n", populacao[i]);  // Usando %.3f para mostrar duas casas decimais
        printf("Área: %.2lf km²\n", area[i]);
        printf("PIB: %.1lf bilhões\n", pib[i]);
        printf("Número de pontos turísticos: %d\n", pontos_turisticos[i]);
    }

    return 0;
}