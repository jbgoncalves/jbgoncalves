/*1. Fa�a um programa que compara dois arquivos, letra por letra, e escreve na tela a posi��o da
primeira diferen�a. O programa deve informar tamb�m se um dos arquivos est� contido no
outro, ou seja, se eles t�m tamanho diferente, mas n�o h� diferen�a at� que o menor termine.*/

#include<stdio.h>
#include<stdlib.h>

main(){

    FILE *arq, *arqtwo;

    char c, ctwo;
    int i, j;
    i = j = 0;

    if(((arq = fopen("arquivo1.txt","r")) == NULL) || (arqtwo = fopen("arquivo2.txt", "r")) == NULL){
        puts("Erro ao abrir o arquivo");
        exit(1);
    }
    c = getc(arq);
    ctwo = getc(arqtwo);
    while(!feof(arq) && !feof(arqtwo)) {
        if(c == ctwo){
            i++;
          }
        c = getc(arq);
        ctwo = getc(arqtwo);
        j++;
    }

    printf("A primeira diferenca ocorreu na posicao %d\n", i);
    if(i == j)
        puts("Um arquivo esta contido no outro");
    else
        puts("Um arquivo nao esta contido no outro");

    fclose(arq);
    fclose(arqtwo);

}
