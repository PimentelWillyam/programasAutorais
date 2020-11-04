#include <stdio.h>
//ex3 de hazin
int mdc(int a,int d)
{
        if (a%d == 0){
                return d;
        }
        else{
                mdc(d,a%d);
        }
}
int main (void)
{
        int a,d,num,i,resul;
        scanf("%d",&num);
        for (i=0;i<num;i++){
                scanf("%d %d",&a,&d);
                resul = mdc(a,d);
                printf("MDC(%d,%d) = %d\n",a,d,resul);
        }

        return 0;
}