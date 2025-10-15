#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct caracteristicasPessoa{
    char nome[100];
    int idade;
    long RG;
}Pessoa;

int menu_RG() {
    int op;  // Vari�vel para armazenar a escolha do usu�rio
    printf("Ol�, seja bem-vindo!\n1) Iniciar Cadastro\n2) Pesquisar por RG\n3) Remover RG\n0) Sair\n\nEscolha uma op��o: ");
    if (scanf("%d", &op) != 1) {  // scanf retorna 1 se leu um inteiro com sucesso
        printf("Entrada inv�lida. Por favor, digite um n�mero.\n");
        op = -1;  // Define um valor inv�lido para for�ar o caso default
        while (getchar() != '\n');  // Limpa o buffer de entrada para evitar problemas
    }
    return op;
}

Pessoa *dobrandoVetor(Pessoa **vetorAtual, int *tamanhoAtual) { // Essa fun��o evita overflow ao dobrar o vetor dinamicamente e usa realloc para otimizar.
    *tamanhoAtual *= 2;

    Pessoa *novoVetor = realloc(*vetorAtual, (*tamanhoAtual) * sizeof(Pessoa));// Usa realloc para redimensionar o vetor, o que � mais eficiente que criar um novo

    if (novoVetor == NULL) {  // Verifica se a realoca��o falhou
        printf("Erro: Falha na realoca��o de mem�ria. Encerrando o programa.\n");
        exit(1);  // Sai do programa para evitar vazamentos ou crashes
    }
    *vetorAtual = novoVetor;
    return novoVetor;  // Atualiza o ponteiro e retorna o vetor redimensionado
}

int existeDuplicata(Pessoa *vetor, int tamanho, Pessoa novaPessoa) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(vetor[i].nome, novaPessoa.nome) == 0 &&  // Compara nomes
            vetor[i].RG == novaPessoa.RG &&                // Compara RGs
            vetor[i].idade == novaPessoa.idade) {          // Compara idades
            return 1;  // Duplicata encontrada
        }
    }
    return 0;  // Nenhuma duplicata encontrada
}

Pessoa *cadastroRG(Pessoa *vetor, int *capacidade, int *tamanho) {// Essa fun��o adiciona um novo RG � lista e gerencia o crescimento do vetor.
    if(*tamanho >= 10){
        printf("Erro: Limite atingido (10 cadastros).\n");
        return vetor;
    }

    Pessoa novaPessoa;

    printf("Digite o RG da pessoa que deseja cadastrar: \n");
    if (scanf("%ld", &novaPessoa.RG) != 1) { // L� o RG e verifica se a entrada foi bem-sucedida
        printf("Entrada inv�lida. Cadastro cancelado.\n");
        while (getchar() != '\n');  // Limpa o buffer
        return vetor;
    }
    while (getchar() !='\n');

    printf("Digite o nome da pessoa que deseja cadastrar: \n");
    if (fgets(novaPessoa.nome, 100, stdin) == NULL) { // L� o RG e verifica se a entrada foi bem-sucedida
        printf("Entrada inv�lida. Cadastro cancelado.\n");
        while (getchar() != '\n');  // Limpa o buffer
        return vetor;
    }
    novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = 0;

    printf("Digite a idade da pessoa que deseja cadastrar: \n");
    if (scanf("%d", &novaPessoa.idade) != 1) { // L� o RG e verifica se a entrada foi bem-sucedida
        printf("Entrada inv�lida. Cadastro cancelado.\n");
        while (getchar() != '\n');  // Limpa o buffer
        return vetor;
    }

    if (existeDuplicata(vetor, *tamanho, novaPessoa)) {
        printf("Erro: Essa pessoa j� est� cadastrada no sistema.\n");
        return vetor;  // N�o adiciona
    }

    vetor[*tamanho] = novaPessoa;
    printf("Pessoa cadastrada com sucesso!\n");
    (*tamanho)++;  // Incrementa o contador de elementos

    if (*tamanho == *capacidade) {// Verifica se o vetor est� cheio e dobra se necess�rio
        vetor = dobrandoVetor(&vetor, capacidade);  // Chama a fun��o para redimensionar
    }
    return vetor;  // Retorna o vetor (possivelmente redimensionado)
}

void acharRG(int tamanho, Pessoa *vetor) {// Essa fun��o realiza uma busca linear no vetor e lida com entradas inv�lidas.
    long procurador = 0;  // Vari�vel para armazenar o RG a ser procurado
    int encontrado = 0;   // Flag para indicar se o RG foi encontrado
    printf("Digite o RG que deseja encontrar: \n");

    if (scanf("%ld", &procurador) != 1) {
        printf("Entrada inv�lida. Opera��o cancelada.\n");
        while (getchar() != '\n');
        return;  // Sai da fun��o
    }
    for (int i = 0; i < tamanho; i++) {  // Percorre o vetor at� o tamanho atual
        if (procurador == vetor[i].RG) {  // Compara o RG procurado com o elemento atual
            printf("Pessoa encontrada!\n");
            printf("Nome: %s\n", vetor[i].nome);
            printf("RG: %ld\n", vetor[i].RG);  // Usando %ld para long
            printf("Idade: %d\n", vetor[i].idade);
            encontrado = 1;  // Marca como encontrado
            break;  // Sai do loop
        }
    }
    if (!encontrado) {  // Se n�o encontrado
        printf("RG n�o encontrado.\n");
    }
}
Pessoa *removerRG(Pessoa *vetor, int *tamanho) { // Essa fun��o remove o primeiro ocorr�ncia de um RG e ajusta o vetor, com verifica��o de entradas.
    long remover = 0;  // Vari�vel para armazenar o RG a ser removido
    int encontrado = 0;  // Flag para indicar se o RG foi encontrado
    printf("Digite o RG que voc� deseja remover: \n");

    if (scanf("%ld", &remover) != 1) {
        printf("Entrada inv�lida. Opera��o cancelada.\n");
        while (getchar() != '\n');
        return vetor;  // Sai sem remover
    }

    for (int i = 0; i < *tamanho; i++) {  // Percorre o vetor
        if (remover == vetor[i].RG) {  // Encontra o RG
            for (int j = i + 1; j < *tamanho; j++) {
                vetor[j - 1] = vetor[j];  // Move os elementos para preencher o espa�o
            }
            (*tamanho)--;  // Decrementa o tamanho do vetor
            encontrado = 1;  // Marca como removido
            printf("RG removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("RG n�o encontrado!\n");
    }
    return vetor;  // Retorna o vetor atualizado
}
int main() { //A fun��o main gerencia o fluxo principal, inicializa recursos e libera mem�ria no final.
    int capacidade = 10;  // Capacidade inicial do vetor
    int tamanhoAtual = 0;  // Tamanho atual da lista de RGs
    int escolha;  // Vari�vel para a escolha do usu�rio no menu

    Pessoa *vetor = calloc(capacidade, sizeof(Pessoa));  // Aloca mem�ria inicial para o vetor
    if (vetor == NULL) {  // Verifica se a aloca��o falhou
        printf("Erro: Falha na aloca��o de mem�ria inicial. Encerrando o programa.\n");
        return 1;
    }
    do {
        escolha = menu_RG();  // Exibe o menu e obt�m a escolha

        switch (escolha) {
            case 0:  // Op��o para sair
                printf("Finalizando o programa...\n");
                free(vetor);  // Libera a mem�ria alocada
                break;
            case 1:  // Op��o para cadastrar
                vetor = cadastroRG(vetor, &capacidade, &tamanhoAtual);
                break;
            case 2:  // Op��o para pesquisar
                acharRG(tamanhoAtual, vetor);
                break;
            case 3:  // Op��o para remover
                vetor = removerRG(vetor, &tamanhoAtual);
                break;
            default:  // Op��o inv�lida
                printf("N�o existe essa op��o. Tente novamente!\n");
                break;
        }
    } while (escolha != 0);  // Continua o loop at� o usu�rio escolher sair
    return 0;  // Fim do programa
}
