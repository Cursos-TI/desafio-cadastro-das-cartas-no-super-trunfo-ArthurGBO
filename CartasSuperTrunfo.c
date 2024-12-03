#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

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

// Função para calcular o "Super Poder"
double calcular_super_poder(float populacao, double area, double pib, int pontos_turisticos) {
    return fabs(populacao) + fabs(area) + fabs(pib) + fabs(pontos_turisticos);
}

// Função para comparar duas cidades
void comparar_cartas(int i, int j, char codigo[MAX_CARTAS][5], float populacao[], double area[], double pib[], int pontos_turisticos[]) {
    printf("\nComparando cartas %s e %s\n", codigo[i], codigo[j]);
    
    // Comparação das propriedades
    double densidade_populacional_i = populacao[i] / area[i];
    double densidade_populacional_j = populacao[j] / area[j];
    double pib_per_capita_i = pib[i] * 1e9 / populacao[i];
    double pib_per_capita_j = pib[j] * 1e9 / populacao[j];
    double super_poder_i = calcular_super_poder(populacao[i], area[i], pib[i], pontos_turisticos[i]);
    double super_poder_j = calcular_super_poder(populacao[j], area[j], pib[j], pontos_turisticos[j]);

    int pontos_i = 0, pontos_j = 0;

    if (densidade_populacional_i < densidade_populacional_j) {
        printf("Densidade Populacional: Carta %s ganhou (%.2f vs %.2f)\n", codigo[i], densidade_populacional_i, densidade_populacional_j);
        pontos_i++;
    } else if (densidade_populacional_i > densidade_populacional_j) {
        printf("Densidade Populacional: Carta %s ganhou (%.2f vs %.2f)\n", codigo[j], densidade_populacional_j, densidade_populacional_i);
        pontos_j++;
    } else {
        printf("Densidade Populacional: Empate (%.2f vs %.2f)\n", densidade_populacional_i, densidade_populacional_j);
    }

    if (populacao[i] > populacao[j]) {
        printf("População: Carta %s ganhou (%.2f milhões vs %.2f milhões)\n", codigo[i], populacao[i], populacao[j]);
        pontos_i++;
    } else if (populacao[i] < populacao[j]) {
        printf("População: Carta %s ganhou (%.2f milhões vs %.2f milhões)\n", codigo[j], populacao[j], populacao[i]);
        pontos_j++;
    } else {
        printf("População: Empate (%.2f milhões vs %.2f milhões)\n", populacao[i], populacao[j]);
    }

    if (area[i] > area[j]) {
        printf("Área: Carta %s ganhou (%.2lf km² vs %.2lf km²)\n", codigo[i], area[i], area[j]);
        pontos_i++;
    } else if (area[i] < area[j]) {
        printf("Área: Carta %s ganhou (%.2lf km² vs %.2lf km²)\n", codigo[j], area[j], area[i]);
        pontos_j++;
    } else {
        printf("Área: Empate (%.2lf km² vs %.2lf km²)\n", area[i], area[j]);
    }

    if (pib[i] > pib[j]) {
        printf("PIB: Carta %s ganhou (R$ %.1lf bilhões vs R$ %.1lf bilhões)\n", codigo[i], pib[i], pib[j]);
        pontos_i++;
    } else if (pib[i] < pib[j]) {
        printf("PIB: Carta %s ganhou (R$ %.1lf bilhões vs R$ %.1lf bilhões)\n", codigo[j], pib[j], pib[i]);
        pontos_j++;
    } else {
        printf("PIB: Empate (R$ %.1lf bilhões vs R$ %.1lf bilhões)\n", pib[i], pib[j]);
    }

    if (pontos_turisticos[i] > pontos_turisticos[j]) {
        printf("Pontos turísticos: Carta %s ganhou (%d vs %d)\n", codigo[i], pontos_turisticos[i], pontos_turisticos[j]);
        pontos_i++;
    } else if (pontos_turisticos[i] < pontos_turisticos[j]) {
        printf("Pontos turísticos: Carta %s ganhou (%d vs %d)\n", codigo[j], pontos_turisticos[j], pontos_turisticos[i]);
        pontos_j++;
    } else {
        printf("Pontos turísticos: Empate (%d vs %d)\n", pontos_turisticos[i], pontos_turisticos[j]);
    }

    // Comparação do Super Poder
    if (super_poder_i > super_poder_j) {
        printf("Super Poder: Carta %s ganhou (%.2f vs %.2f)\n", codigo[i], super_poder_i, super_poder_j);
        pontos_i++;
    } else if (super_poder_i < super_poder_j) {
        printf("Super Poder: Carta %s ganhou (%.2f vs %.2f)\n", codigo[j], super_poder_j, super_poder_i);
        pontos_j++;
    } else {
        printf("Super Poder: Empate (%.2f vs %.2f)\n", super_poder_i, super_poder_j);
    }

    // Determinando a carta vencedora
    if (pontos_i > pontos_j) {
        printf("\nA Carta %s foi a vencedora geral!\n", codigo[i]);
    } else if (pontos_j > pontos_i) {
        printf("\nA Carta %s foi a vencedora geral!\n", codigo[j]);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    char codigo[MAX_CARTAS][5];  
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
        codigo[contador][strcspn(codigo[contador], "\n")] = 0;{
        getchar();}


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
        printf("Insira a população da cidade (em milhões): ");
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
        printf("Insira o PIB da cidade (em bilhões de reais): ");
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
        // Densidade populacional e PIB per capita
        double densidade_populacional = populacao[i] * 1e6 / area[i];
        double pib_per_capita = pib[i] * 1e3 / populacao[i];

        printf("\nCarta %d:\n", i + 1);
        printf("Código: %s\n", codigo[i]);
        printf("Nome: %s\n", nome[i]);
        printf("População: %.2f milhões de habitantes\n ", populacao[i]);
        printf("Área: %.2lf km²\n", area[i]);
        printf("PIB: %.1lf bilhões de reais\n", pib[i]);
        printf("Número de pontos turísticos: %d\n", pontos_turisticos[i]);
        printf("Densidade Populacional: %.2f habitantes por km²\n", densidade_populacional);
        printf("PIB per Capita: R$ %.2f\n", pib_per_capita);
    }

// Loop para comparar cartas
char comparar_mais;
do {
    // Escolher duas cartas para comparar
    if (contador > 1) {
        char codigo1[5], codigo2[5];
        int carta1 = -1, carta2 = -1;

        printf("\nEscolha duas cartas para comparar\n");

        printf("Digite o código da primeira carta: ");
        scanf("%4s", codigo1);  // %4s limita a leitura a 4 caracteres, evitando overflow

        printf("Digite o código da segunda carta: ");
        scanf("%4s", codigo2);

        // Encontrar índices correspondentes aos códigos
        for (int i = 0; i < contador; i++) {
            if (strcmp(codigo[i], codigo1) == 0) {
                carta1 = i;
            }
            if (strcmp(codigo[i], codigo2) == 0) {
                carta2 = i;
            }
        }

        // Verifica se os códigos são válidos
        if (carta1 != -1 && carta2 != -1) {
            comparar_cartas(carta1, carta2, codigo, populacao, area, pib, pontos_turisticos);
        } else {
            printf("Escolhas de cartas inválidas. Tente novamente.\n");
        }
    } else {
        printf("Não há cartas suficientes para comparação.\n");
    }

    printf("\nDeseja comparar mais cartas? (s/n): ");
    scanf(" %c", &comparar_mais);  // Lê a resposta do usuário
    getchar();  // Limpa o buffer de entrada

} while (comparar_mais == 's' || comparar_mais == 'S');

    return 0;
}
