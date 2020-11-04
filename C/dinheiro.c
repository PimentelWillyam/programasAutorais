#include <stdio.h>
int main (void)
{
        int n,grana,n100,n50,n20,n10,n5,n2,n1;
        scanf("%d",&n);
        grana = n;
        n100 = n/100;
        n = n - n100*100;
        n50 = n/50;
        n = n - n50*50;
        n20 = n/20;
        n = n - n20*20;
        n5 = n/5;
        n = n - n5*5;
        n2 = n/2;
        n = n - n2*2;
        n1 = n/1;
        n = n - n1*1;
        printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n",grana,n100,n50,n20,n10,n5,n2,n1);
        return 0;
}