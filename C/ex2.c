#include <stdio.h>
#include <string.h>
//ex2 de hazin

int main (void)

{
        int vezes,i,totalCapsulas = 0;
        char tamanho[1];
        for (i=0;i<7;i++){
                scanf("%d %s",&vezes,&tamanho);
                if (strcmp(tamanho,"p") == 0 || strcmp(tamanho,"P") == 0)
                        totalCapsulas = totalCapsulas + 10*vezes;
                else
                        totalCapsulas = totalCapsulas +16*vezes;
        }
        printf("%d\n%d\n",totalCapsulas,totalCapsulas/7*2);
        return 0; 
}