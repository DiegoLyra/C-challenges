#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct caracteristicasDoPokemon {//O typedef é para criar um apelido para a struct. Em vez de escrever 'struct caracteristicasDoPokemon' toda vez, podemos simplesmente usar pokemon.
        char name[50], type[50];
        int level, color;
    }pokemon;

void printPokemon(pokemon p) {//Ela recebe uma variável do tipo pokemon e imprime os dados desse Pokémon na tela
    printf("\033[%dm%s | %s | Nível: %-3d\033[0m\n", //"\033[0m\n": Isso reseta a cor do texto de volta ao normal e adiciona uma quebra de linha.
           p.color, p.name, p.type, p.level);
}

void lePokemon() {//Abre um arquivo chamado "entrada.txt", lê os dados de Pokémon dali, armazena-os em um array de structs e, por fim, imprime cada um
    FILE *ponteiroArq = fopen("entrada.txt", "r");
    int cont = 0; //contar quantos pokemon foram lidos
    if (ponteiroArq == NULL) printf("Erro. Não foi possível abrir o arquivo!");
    else {
        pokemon vetorP[5];//máximo de pokemons
         while (cont < 5 &&
            fscanf(ponteiroArq, "%s %s %d %d", vetorP[cont].name, vetorP[cont].type,
            &vetorP[cont].level, &vetorP[cont].color) == 4);// Adicionado para limitar ao tamanho do array

            cont++;
        }
        fclose(pontArquivo);//Fecha o arquivo para liberar recursos do sistema. É importante fazer isso para evitar vazamentos de memória.
        for (int i = 0 ; i < cont ; i++){
            printPokemon(vetorP[i]);
        }
    }
}

int main() {
    printf("\n=== Pokédex Colorida ===\n\n");
    lePokemon();//loop para imprimir
    return 0;
}
