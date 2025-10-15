#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct caracteristicasDoPokemon {//O typedef � para criar um apelido para a struct. Em vez de escrever 'struct caracteristicasDoPokemon' toda vez, podemos simplesmente usar pokemon.
        char name[50], type[50];
        int level, color;
    }pokemon;

void printPokemon(pokemon p) {//Ela recebe uma vari�vel do tipo pokemon e imprime os dados desse Pok�mon na tela
    printf("\033[%dm%s | %s | N�vel: %-3d\033[0m\n", //"\033[0m\n": Isso reseta a cor do texto de volta ao normal e adiciona uma quebra de linha.
           p.color, p.name, p.type, p.level);
}

void lePokemon() {//Abre um arquivo chamado "entrada.txt", l� os dados de Pok�mon dali, armazena-os em um array de structs e, por fim, imprime cada um
    FILE *ponteiroArq = fopen("entrada.txt", "r");
    int cont = 0; //contar quantos pokemon foram lidos
    if (ponteiroArq == NULL) printf("Erro. N�o foi poss�vel abrir o arquivo!");
    else {
        pokemon vetorP[5];//m�ximo de pokemons
         while (cont < 5 &&
            fscanf(ponteiroArq, "%s %s %d %d", vetorP[cont].name, vetorP[cont].type,
            &vetorP[cont].level, &vetorP[cont].color) == 4);// Adicionado para limitar ao tamanho do array

            cont++;
        }
        fclose(pontArquivo);//Fecha o arquivo para liberar recursos do sistema. � importante fazer isso para evitar vazamentos de mem�ria.
        for (int i = 0 ; i < cont ; i++){
            printPokemon(vetorP[i]);
        }
    }
}

int main() {
    printf("\n=== Pok�dex Colorida ===\n\n");
    lePokemon();//loop para imprimir
    return 0;
}
