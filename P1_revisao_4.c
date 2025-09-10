//4)
#include <stdio.h>

void matrizes(int matrizInicial[4][4], int matriz1[2][2], int matriz2[2][2], int matriz3[2][2], int matriz4[2][2]){
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            matriz1[i][j] = matrizInicial[i][j];
        }
    }
    for (int i = 0; i < 2; i++){
        for(int j = 2; j < 4; j++){
            matriz2[i][j - 2] = matrizInicial[i][j];
        }
    }
    for (int i = 2; i < 4; i++){
        for(int j = 0; j < 2; j++){
            matriz3[i - 2][j] = matrizInicial[i][j];
        }
    }
    for (int i = 2; i < 4; i++){
        for(int j = 2; j < 4; j++){
            matriz4[i - 2][j - 2] = matrizInicial[i][j];
        }
    }

}

int maiorNumero(int maiorElemento[2][2]){
    int maior = maiorElemento[0][0];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <2; j++){
            if (maior < maiorElemento[i][j]){
                maior = maiorElemento[i][j];
            }
        }

    }
    return maior;

}

int main(){
    int matriz1[2][2], matriz2[2][2], matriz3[2][2], matriz4[2][2], matrizFinal[2][2]= {{0,0},{0,0}};

    int matrizInicial[4][4] = {
        {3,7,2,5},
        {1,6,9,3},
        {4,4,8,2},
        {3,5,6,1}
    };

    matrizes(matrizInicial, matriz1, matriz2, matriz3, matriz4);

    matrizFinal[0][0] = maiorNumero(matriz1);
    matrizFinal[0][1] = maiorNumero(matriz2);
    matrizFinal[1][0] = maiorNumero(matriz3);
    matrizFinal[1][1] = maiorNumero(matriz4);

    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d", matrizFinal[i][j]);
        }
        printf("\n");
    }
}
