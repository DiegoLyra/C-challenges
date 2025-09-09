#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y;
    for(x=0, y=10; x <= 10; x++, y--){
        printf("%d - %d = %d\n", x, y, x-y);
    }

    return 0;
}
