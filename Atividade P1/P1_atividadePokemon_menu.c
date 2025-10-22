#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct caracteristicasDoPokemon {
    char name[50], type[50];
    int level, color;
} pokemon;

void printPokemon(pokemon p) {
    printf("\033[%dm%s | %s | N�vel: %-3d\033[0m\n", p.color, p.name, p.type, p.level);
}

void lePokemon(pokemon vetorPoke[], int *contadora) {
    FILE *ponteiroArq = fopen("entrada.txt", "r");
    if (ponteiroArq == NULL) {
        printf("Erro. N�o foi poss�vel abrir o arquivo!\n");
        return;
    }
    *contadora = 0;
    while (*contadora < 5 && fscanf(ponteiroArq, "%s %s %d %d", vetorPoke[*contadora].name, vetorPoke[*contadora].type,
           &vetorPoke[*contadora].level, &vetorPoke[*contadora].color) == 4) {
        (*contadora)++;
    }
    fclose(ponteiroArq);
}

void addPokemon(pokemon vetorPoke[], int *contadora) {
    if (*contadora >= 6) {
        printf("Limite atingido, n�o h� como adicionar mais.\n");
        return;
    }
    pokemon novoPokemon;
    printf("Digite o nome do Pok�mon: ");
    scanf("%s", novoPokemon.name);
    printf("Digite o tipo do Pok�mon: ");
    scanf("%s", novoPokemon.type);
    printf("Digite o n�vel do Pok�mon: ");
    scanf("%d", &novoPokemon.level);
    printf("Digite a cor do Pok�mon (c�digo ANSI): ");
    scanf("%d", &novoPokemon.color);

    vetorPoke[*contadora] = novoPokemon;
    (*contadora)++;

    FILE *ponteiroArq = fopen("entrada.txt", "a");
    if (ponteiroArq == NULL) {
        printf("Erro. N�o foi poss�vel abrir o arquivo para adicionar Pok�mon!\n");
        return;
    }
    fprintf(ponteiroArq, "%s %s %d %d\n", novoPokemon.name, novoPokemon.type, novoPokemon.level, novoPokemon.color);
    fclose(ponteiroArq);
}

void removerPokemon(pokemon vetorPoke[], int *contadora) {
    if (*contadora == 0) {
        printf("N�o h� Pok�mon para remover.\n");
        return;
    }
    char nome[50];
    printf("Digite o nome do Pok�mon que deseja remover: ");
    scanf("%s", nome);
    int i;
    for (i = 0; i < *contadora; i++) {
        if (strcmp(vetorPoke[i].name, nome) == 0) {
            break;
        }
    }
    if (i == *contadora) {
        printf("Pok�mon n�o encontrado.\n");
        return;
    }
    for (int j = i; j < *contadora - 1; j++) {
        vetorPoke[j] = vetorPoke[j + 1];
    }
    (*contadora)--;

    FILE *ponteiroArq = fopen("entrada.txt", "w");
    if (ponteiroArq == NULL) {
        printf("Erro. N�o foi poss�vel abrir o arquivo para salvar Pok�mon!\n");
        return;
    }
    for (int k = 0; k < *contadora; k++) {
        fprintf(ponteiroArq, "%s %s %d %d\n", vetorPoke[k].name, vetorPoke[k].type, vetorPoke[k].level, vetorPoke[k].color);
    }
    fclose(ponteiroArq);
}

void menu() {
    printf("\n=== Menu da Pok�dex ===\n");
    printf("1. Adicionar Pok�mon\n");
    printf("2. Remover Pok�mon\n");
    printf("3. Pok�dex colorida\n");
    printf("4. Sair\n");
}

int main() {
    pokemon vetorPoke[5];
    int contadora = 0, opcao; // Corrigido: adicionado ponto e v�rgula
    printf("\n=== Pok�dex Colorida ===\n\n");

    lePokemon(vetorPoke, &contadora); // Passando vetor e contador
    for (int i = 0; i < contadora; i++) {
        printPokemon(vetorPoke[i]);
    }

    do {
        menu();
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                addPokemon(vetorPoke, &contadora);
                break;

            case 2:
                removerPokemon(vetorPoke, &contadora);
                break;

            case 3:
                printf("\nPok�mon na Pok�dex:\n");
                for (int i = 0; i < contadora; i++) {
                    printPokemon(vetorPoke[i]);
                }
                break;

            case 4:
                printf("Finalizando o programa...\n");
                break;

            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    }while (opcao != 4);

    return 0;
}
