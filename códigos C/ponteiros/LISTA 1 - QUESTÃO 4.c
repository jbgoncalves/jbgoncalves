/*Escreva um programa que leia uma string e chame uma fun��o que receba essa string como par�metro (a fun��o pode ter outros par�metros).
A fun��o deve verificar quais as vogais que n�o aparecem na string lida, e essas letras devem ser exibidas na fun��o main, ap�s o retorno da fun��o.
A manipula��o de strings dentro da fun��o deve ser feita com ponteiros, sem o uso de �ndices. Por simplicidade, considere apenas letras n�o acentuadas.*/

#include<stdio.h>
#include<locale.h>

void *vogaisfalta(char *p1, char *p2)   {
    for( ; *p1 != '\0'; p1++){          //errado    6
        if(*p1 == 'a' ){
            *p2 = ' ';                 //aeiou
        }
        else if(*p1 == 'e' ){
            *(p2 +1)= ' ';
        }
        else if(*p1 == 'i' ){
            *(p2 +2)= ' ';
        }
        else if(*p1 == 'o' ){
            *(p2 +3)= ' ';
        }
        else if(*p1 == 'u' ){
            *(p2 +4)= ' ';
        }
}
        *(p2 +5) = '\0';
}

main(){
setlocale(LC_ALL, "portuguese");

    char str1[30],str2[5];

    str2[0] = 'a';
    str2[1] = 'e';
    str2[2] = 'i';
    str2[3] = 'o';
    str2[4] = 'u';
    printf("Digite uma string: ");
    gets(str1);
    vogaisfalta(str1, str2);
    printf("As vogais que est�o faltando s�o '%s'", str2);





}
