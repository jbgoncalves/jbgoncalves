/*3. Fa�a um programa para copiar um arquivo de texto. O arquivo de destino deve ser criado.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


main(){
setlocale(LC_ALL, "portuguese");

    FILE *arq, *arqtwo;
    char str[20], strtwo[20];
    char c, ctwo;

    puts("Digite o nome do arquivo que voc� deseja copiar o conte�do, para um novo arquivo criado(DIGITE .txt NO FINAL):");
    gets(str);
    puts("Digite o nome do arquivo a ser criado(DIGITE .txt NO FINAL");
    gets(strtwo);

    if((arq = fopen(str,"r")) == NULL){
        puts("Arquivo n�o encontrado!!!");
        exit(1);
    }
    arqtwo = fopen(strtwo,"w");


    c = getc(arq);
    while(!feof(arq)){
        putc(c, arqtwo);
        c = getc(arq);
    }

    fclose(arq);
    fclose(arqtwo);






}
