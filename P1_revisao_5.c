//5)

int indicePrimeiraRepeticao(char vetor[15]){
    for(int i = 0; i < 14; i++){
        if(vetor[i] == vetor[i + 1]){
            return i;
        }
    }
    return -1
}
