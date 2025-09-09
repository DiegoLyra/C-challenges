#include <stdio.h>

int main()
{
    int n1, n2;
    float total;
    char operador;
    printf("Digite o calculo que voce deseja realizar:\n");
    scanf("%d%c%d", &n1, &operador, &n2);
    switch(operador){
        case '+':
            total = n1 + n2;
            break;

        case '-':
            total = n1 - n2;
            break;

        case '*':
            total = n1 * n2;
            break;

        case '/':
            if(n2==0){
                printf("Nao ha divisao por 0. Digite novamente:\n");
                scanf("%d%c%d", &n1, &operador, &n2);
                total = n1 / n2;
            }else{
                total = n1 / n2;
            break;
            }
        default:
            printf("Erro! Operador invalido\n");
    }

    printf("Resultado: %.2f", total);

    return 0;
}
