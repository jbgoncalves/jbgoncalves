/*2. Fa�a um programa que leia uma string e passe a string para uma FUN��O que calcule o n�mero de vogais, de consoantes e de outros caracteres
(espa�o, sinais de pontua��o, etc.) da string. Dentro da fun��o main deve ser gerada uma mensagem informando os totais contados.
Para simplificar, ignore as letras com acentos. N�o use vari�veis globais.*/


#include<stdio.h>
#include<locale.h>

void contarcaracteres(char *p, int *a, int *b, int *c){
    char tabela;
    int i=0;
    for( ;*p != '\0'; p++){
        if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
                    (*a)++;

            for(tabela = 'b'; tabela <= 'z'; tabela++){
                if(tabela == 'e' || tabela == 'i' || tabela == 'o' || tabela == 'u')
                    tabela++;
                if(*p == tabela){
                    (*b)++;
                    printf("%d--",*b);
                                 }                                   //cav_lo
                }
        i++;
            }
    *c = i- ((*a)+(*b));
}


main(){
    char str[30];
    int a = 0,b = 0,c = 0;

    printf("Digite uma palavra: ");
    gets(str);
    contarcaracteres(str, &a, &b, &c);
    printf("Esta funcao tem %d vogais, %d consoantes e %d simbolos especiais.",a,b,c);

}
