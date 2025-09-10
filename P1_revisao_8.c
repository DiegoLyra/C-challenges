//8)
#include <stdio.h>

void somaVetores(int A[], int B[], int C[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        C[i] = A[i] + B[i];
    }
}

int main(){
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};
    int C[3];
    int tamanho = 3;

    somaVetores(A, B, C, tamanho);
    printf("C = [");
    for (int i = 0; i < tamanho; i++){
        printf("%d", C[i]);
        if (i < tamanho - 1){
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}
