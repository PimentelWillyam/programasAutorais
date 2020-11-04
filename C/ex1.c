#include <stdio.h>
//ex1 de hazin
int main (void)
{
                int n,x,i,cont = 0;
                scanf("%d %d",&x,&n);
                for (i=n-1;i>0;i--){
                                if(i%x == 0)
                                                cont++;
                }
                printf("O numero %d tem %d multiplos menores que %d.\n",x,cont,n);
                return 0;
}