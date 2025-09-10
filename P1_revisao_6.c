//6)
int func(int matriz[4][4], int alvo){
    int total = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if (matriz[i][j] == alvo && matriz[i][j + 1] == alvo) {
                total++;
            }
        }
    }
    return total;
}
