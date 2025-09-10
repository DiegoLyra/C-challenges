//1)

int maior(int n1, int n2, int n3){
    int maior_n = n1;
    if (n2 > maior_n){
        maior_n = n2;
    }
    if (n3 > maior_n){
        maior_n = n3;
    }
    return maior_n;
}
