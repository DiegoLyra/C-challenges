//2)
#include <math.h>

int ehQuadradoPerfeito(int n){
    if (n < 0){
        return 0;
    }
    if ((int)sqrt(n) * (int)sqrt(n) == n){
        return 1;
    } else {
        return 0;
    }
}
