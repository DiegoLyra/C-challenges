#include <stdio.h>
#include <stdlib.h>

int menu_RG() {
    int op;  // Variável para armazenar a escolha do usuário
    printf("Olá, seja bem-vindo!\n1)Iniciar Cadastro\n2)Pesquisar por RG\n3)Remover RG\n0)Sair\n\nEscolha uma opção: ");
    printf("Escolha uma opção: ");

    if (scanf("%d", &op) != 1) {  // scanf retorna 1 se leu um inteiro com sucesso
        printf("Entrada inválida. Por favor, digite um número.\n");
        op = -1;  // Define um valor inválido para forçar o caso default
        while (getchar() != '\n');  // Limpa o buffer de entrada para evitar problemas
    }
    return op;
}

long *dobrandoVetor(long **vetorAtual, int *tamanhoAtual) { // Essa função evita overflow ao dobrar o vetor dinamicamente e usa realloc para otimizar.
    *tamanhoAtual *= 2;

    long *novoVetor = realloc(*vetorAtual, (*tamanhoAtual) * sizeof(long));// Usa realloc para redimensionar o vetor, o que é mais eficiente que criar um novo

    if (novoVetor == NULL) {  // Verifica se a realocação falhou
        printf("Erro: Falha na realocação de memória. Encerrando o programa.\n");
        exit(1);  // Sai do programa para evitar vazamentos ou crashes
    }
    *vetorAtual = novoVetor;
    return novoVetor;  // Atualiza o ponteiro e retorna o vetor redimensionado
}
long *cadastroRG(long *vetor, int *capacidade, int *tamanho) {// Essa função adiciona um novo RG à lista e gerencia o crescimento do vetor.
    printf("Digite o RG da pessoa que deseja cadastrar: \n");

    if (scanf("%ld", &vetor[*tamanho]) != 1) { // Lê o RG e verifica se a entrada foi bem-sucedida
        printf("Entrada inválida. Cadastro cancelado.\n");
        while (getchar() != '\n');  // Limpa o buffer
        return vetor;  // Retorna sem adicionar
    }

    printf("Pessoa cadastrada com sucesso!\n");
    (*tamanho)++;  // Incrementa o contador de elementos

    if (*tamanho == *capacidade) {// Verifica se o vetor está cheio e dobra se necessário
        vetor = dobrandoVetor(&vetor, capacidade);  // Chama a função para redimensionar
    }
    return vetor;  // Retorna o vetor (possivelmente redimensionado)
}

void acharRG(int tamanho, long *vetor) {// Essa função realiza uma busca linear no vetor e lida com entradas inválidas.
    long procurador = 0;  // Variável para armazenar o RG a ser procurado
    int encontrado = 0;   // Flag para indicar se o RG foi encontrado
    printf("Digite o RG que deseja encontrar: \n");

    if (scanf("%ld", &procurador) != 1) {
        printf("Entrada inválida. Operação cancelada.\n");
        while (getchar() != '\n');
        return;  // Sai da função
    }
    for (int i = 0; i < tamanho; i++) {  // Percorre o vetor até o tamanho atual
        if (procurador == vetor[i]) {  // Compara o RG procurado com o elemento atual
            printf("Pessoa encontrada!\n");
            encontrado = 1;  // Marca como encontrado
            break;  // Sai do loop
        }
    }
    if (encontrado == 0) {  // Se não encontrado
        printf("RG não encontrado.\n");
    }
}
long *removerRG(long *vetor, int *tamanho) { // Essa função remove o primeiro ocorrência de um RG e ajusta o vetor, com verificação de entradas.
    long remover = 0;  // Variável para armazenar o RG a ser removido
    int encontrado = 0;  // Flag para indicar se o RG foi encontrado
    printf("Digite o RG que você deseja remover: \n");

    if (scanf("%ld", &remover) != 1) {
        printf("Entrada inválida. Operação cancelada.\n");
        while (getchar() != '\n');
        return vetor;  // Sai sem remover
    }

    for (int i = 0; i < *tamanho; i++) {  // Percorre o vetor
        if (remover == vetor[i]) {  // Encontra o RG
            for (int j = i + 1; j < *tamanho; j++) {
                vetor[j - 1] = vetor[j];  // Move os elementos para preencher o espaço
            }
            (*tamanho)--;  // Decrementa o tamanho do vetor
            encontrado = 1;  // Marca como removido
            printf("RG removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("RG não encontrado!\n");
    }
    return vetor;  // Retorna o vetor atualizado
}
int main() { //A função main gerencia o fluxo principal, inicializa recursos e libera memória no final.
    int capacidade = 10;  // Capacidade inicial do vetor
    int tamanhoAtual = 0;  // Tamanho atual da lista de RGs
    int escolha;  // Variável para a escolha do usuário no menu

    long *vetor = calloc(capacidade, sizeof(long));  // Aloca memória inicial para o vetor
    if (vetor == NULL) {  // Verifica se a alocação falhou
        printf("Erro: Falha na alocação de memória inicial. Encerrando o programa.\n");
        return 1;
    }
    do {
        escolha = menu_RG();  // Exibe o menu e obtém a escolha

        switch (escolha) {
            case 0:  // Opção para sair
                printf("Finalizando o programa...\n");
                free(vetor);  // Libera a memória alocada
                break;
            case 1:  // Opção para cadastrar
                vetor = cadastroRG(vetor, &capacidade, &tamanhoAtual);
                break;
            case 2:  // Opção para pesquisar
                acharRG(tamanhoAtual, vetor);
                break;
            case 3:  // Opção para remover
                vetor = removerRG(vetor, &tamanhoAtual);
                break;
            default:  // Opção inválida
                printf("Não existe essa opção. Tente novamente!\n");
                break;
        }
    } while (escolha != 0);  // Continua o loop até o usuário escolher sair

    return 0;  // Fim do programa
}
