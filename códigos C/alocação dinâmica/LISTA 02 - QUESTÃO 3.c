/*3. Escrever um programa que leia uma string e crie uma nova string na qual as letras s�o
replicadas de acordo com sua posi��o na string lida, ou seja, a primeira letra � copiada uma
vez, a segunda duas vezes, a terceira tr�s vezes, e assim por diante. Se for lida a string �hora�,
por exemplo, a string criada deve ser �hoorrraaaa�. A string resultante deve ser colocada em
�rea de mem�ria alocada para este fim, com o tamanho exato necess�rio.
Obs: essa opera��o de replicar as letras j� foi tema de outro exerc�cio. Mas nesse exerc�cio
acima foi acrescentada a aloca��o din�mica.*/


#include<stdio.h>
#include<stdlib.h>

char *strnova(char *str){

    char *p;
    int i,j,k, cont;
    i = j = k = cont = 0;

    for(i = 0; str[i]; i++){                //hora// 11
       cont += i +1;
    }
    cont++;

    p = (char *) malloc(sizeof(char) * cont);

    for(i = 0; str[i]; i++){
        while(k < (i+1)){
            p[j] = str[i];                  //hora//  //hoorrraaaa\0//
            j++;
            k++;
        }
        k = 0;
    }
    p[j] = '\0';
    return p;

}

main(){

    char str[50], *p;

    puts("Digite uma palavra:");
    gets(str);

    p = strnova(str);

    printf("A nova string e %s", p);
    free(p);
}
