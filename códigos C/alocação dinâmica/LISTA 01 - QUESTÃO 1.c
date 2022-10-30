/*1. Escreva um programa que leia uma string e dois valores num�ricos a e b, chame uma
fun��o que copie para uma segunda string as letras colocadas entre os �ndices a e b (inclusive)
na primeira string. A segunda string deve ser criada de forma din�mica e ter o tamanho exato
para conter a string com os caracteres que receber�. Se um ou os dois �ndices forem
inadequados para a string lida (muito grandes, por exemplo), esta deve ser copiada inteira.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

char *copialetras(char *str, int a, int b){

    char *stri;
    char *strb;
    char *strp;
    int n;
    int aux;

    if(a > b){
        aux = a;
        a = b;
        b = aux;
    }

    stri = str;
    for(n = 0; *stri; n++,stri++);

    if(a < 0 || b >= n){
        //printf("teste1");
        strp = (char *) malloc(sizeof(char) * (n+1));
        stri = strp;
        while(*str){
            *strp = *str;
            str++;
            strp++;
        }
        *strp = '\0';
        return stri;
    }
    else{
        strp = (char *) malloc(sizeof(char) * (b-a+2));         // 7 bytes
        stri = strp;                                            // pos ini 7 bytes
        strb = str +b;                                          // posi��o do b
        str += a;
                                                                // posi��o do a
        for( ;str <= strb; str++,strp++){
            *strp = *str;
        }
        *strp = '\0';
        return stri;
    }
}


main(){
setlocale(LC_ALL, "portuguese");

    char str[50], *p;
    int a, b;

    printf("Digite uma string: ");
    gets(str);

    printf("Digite dois valores num�ricos: ");
    scanf("%d", &a);
    scanf("%d", &b);

    p = copialetras(str,a,b);

    printf("A palavra agora �: %s.", p);
    free(p);
}
