/*Escreva um programa que leia uma string e passe esta string para uma fun��o na qual s�o trocadas de lugar a primeira e a �ltima letras.
A fun��o deve receber a string atrav�s de um ponteiro, e fazer a manipula��o sem usar �ndices.
Exiba a string original e a string resultante atrav�s de um printf na fun��o main.*/

#include<stdio.h>
#include<locale.h>

void *trocaletra(char *p){      //to passando endere�o
    char aux,*paux;
    paux = p;                   //1� endere�o;
    aux = *p;
    for( ;*p != '\0'; p++);
    p--;
    *paux = *p;
    *p = aux;
                                      //cavalo
}
main(){

    char str1[30];

    printf("Digite uma palavra ou frase: ");
    gets(str1);
    trocaletra(str1);
    printf("String resultante %s", str1);           //endere�o &88

}
