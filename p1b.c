#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct item
{
    char pergunta[100];
    char resposta[100];
    struct item *proximo;
} typedef pergunta;


struct f
{
    pergunta *primeiro;
} typedef fila;



fila* criarFilaPergunta(){
    fila *novaFilaPerguntas = (fila*)malloc(sizeof(fila));
    novaFilaPerguntas->primeiro = NULL;
    return novaFilaPerguntas;
}

bool semPerguntas(fila *f){
    return f->primeiro == NULL;
}

void adicionarPergunta(fila *f){
    
    pergunta *nova_pergunta = (pergunta*)malloc(sizeof(pergunta));

    printf("\nDigite uma pergunta: ");
    gets(nova_pergunta->pergunta);
    printf("\nDigite a resposta para a pergunta enviada: ");
    gets(nova_pergunta->resposta);
    nova_pergunta->proximo = NULL;

    if (semPerguntas(f)){
        f->primeiro = nova_pergunta;
    }else{
        pergunta *aux = f->primeiro;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = nova_pergunta;
    }
    printf("\nPergunta adicionada!\n");
}

void verPerguntas(fila *f){

    if (semPerguntas(f)){
        printf("\nNão tem perguntas!");
    }else{
        int n_pergunta = 1;
        pergunta *aux = f->primeiro;

        while(aux->proximo != NULL){
            printf("\nPergunta %d: %s \n", n_pergunta, aux->pergunta);
            n_pergunta++;
            aux = aux->proximo;
        }
        printf("\nPergunta %d: %s \n", n_pergunta, aux->pergunta);
    }
}

void responderPergunta(fila *f){
    char resposta[100];
    pergunta *pergunta_retirada = (pergunta*)malloc(sizeof(pergunta));

    pergunta_retirada = f->primeiro;
    
    printf("%s\n", pergunta_retirada->pergunta);
    fgets(resposta, sizeof(resposta), stdin);

    resposta[strcspn(resposta, "\n")] = 0;

    if (strcmp(resposta, pergunta_retirada->resposta) == 0){
        printf("\nResposta Correta!\n");
    }else{
        printf("\nResposta Errado!\n");
    }

    f->primeiro = pergunta_retirada->proximo;
    free(pergunta_retirada);

}

int main(){

    fila *perguntas;
    int opcao_escolhida;
    
    perguntas = criarFilaPergunta();

    do
    {
        printf("\nEscolha uma opcao abaixo: \n");
        printf("1 - Adicionar pergunta nova.\n");
        printf("2 - Ver perguntas.\n");
        printf("3 - Responder uma pergunta.\n");
        printf("0 - Sair.\n");
        scanf("%d", &opcao_escolhida);
        getchar();

        switch (opcao_escolhida)
        {
        case 1:
            adicionarPergunta(perguntas);
            break;
        
        case 2:
            verPerguntas(perguntas);
            break;

        case 3:
            responderPergunta(perguntas);
            break;
            
        }
    } while (opcao_escolhida != 0);
    


}