#include <stdio.h>

float calcular_media();
int menor_elemento(), maior_elemento();

int main(){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int menor = menor_elemento(vetor), maior = maior_elemento(vetor);
    float media = calcular_media(vetor);
    printf("A média é: %.2f\n", media);
    printf("O menor elemento é: %d\n", menor);
    printf("O maior elemento é: %d\n", maior);
    return 0;
}

float calcular_media(int vetor[]){
    int soma = 0, i = 0;
    for (i; i < 10; i++){
        soma += vetor[i];
    }
    return (float)soma/10;
}

int menor_elemento(int vetor[]){
    int menor = vetor[0], i = 1;
    for (i; i < 10; i ++){
        if(vetor[i] < menor){
            menor = vetor[i];
        }else{
        menor = vetor[0];
        }
    }
    return menor;
}

int maior_elemento(int vetor[]){
    int maior = vetor[0], i = 1;
    for (i; i < 10; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;
}
