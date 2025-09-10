//7)
#include <stdio.h>

void rotacaoDeVetor(int vetor[], int tamanho, int posicoes){
    posicoes = posicoes % tamanho;
    if (posicoes == 0) return;

    int vet_temporario[posicoes];

    for(int i = 0; i < posicoes; i++){
        vet_temporario[i] = vetor[tamanho - posicoes + i];
    }
    for (int i = tamanho - posicoes - 1; i >= 0; i--){
        vetor[i + posicoes] = vetor[i];
    }
    for (int i = 0; i < posicoes; i++){
        vetor[i] = vet_temporario[i];
    }
}
int main(){
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int posicoes = 2;

    rotacaoDeVetor(vetor, tamanho, posicoes);
    printf("Vetor rotacionado: ");
    for (int i = 0; i < tamanho; i++){
        printf("%d", vetor[i]);
    }
    printf("\n");
    return 0;
}
