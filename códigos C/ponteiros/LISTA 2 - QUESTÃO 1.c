/*Escreva um programa que chame uma fun��o onde uma string recebe como conte�do as 26 letras do
alfabeto, em ordem. A string deve ser exibida na tela ap�s o retorno para a fun��o main, e apresentar o
conte�do �ABCDEFGHIJKLMNOPQRSTUVWXYZ�. A manipula��o na fun��o deve ser feita atrav�s de
ponteiros, sendo evitado o uso de �ndices, e a string deve ser mostrada ap�s o retorno para a fun��o main.*/


#include<stdio.h>
#include<locale.h>

void *alfabeto(char *p){
    char a;
    for(a = 'A'; a <= 'Z'; a++){
        *p = a;
        p++;
    }
    *p = '\0';

}

main(){
setlocale(LC_ALL, "portuguese");

    char str1[30];
    alfabeto(str1);     //&80
    printf("O conteudo da string  � %s", str1);






}


