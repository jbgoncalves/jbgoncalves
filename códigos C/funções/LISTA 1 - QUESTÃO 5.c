/*Escreva um programa que leia uma string e chame uma fun��o, passando a string como
par�metro para calcular o seu tamanho (n�mero de letras). O valor calculado deve ser
retornado para a fun��o main, e ent�o exibido na tela.*/

#include<stdio.h>
#include<locale.h>

char func1(char str[30]){
    int j;
    for(j = 0; str[j] != '\0'; j++);
    return j;
    }


main(){
setlocale(LC_ALL, "portuguese");

    int n;
    char str[30];

    printf("Digite uma string: ");
    gets(str);
    n = func1(str);
    printf("N�mero de letras � %d", n);


    /*for(i = 0; str[i] != '\0'; i++)
        printf("%c", str[i]);*/

}
