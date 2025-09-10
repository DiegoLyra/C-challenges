//3)
int ehIdentidade(int matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (i == j){
                if(matriz[i][j] != 1){
                    return 0;
                }
            }else{
                if (matriz[i][j] != 0)+{
                    return 0;
                }
            }
        }
    }
    return 1;
}
