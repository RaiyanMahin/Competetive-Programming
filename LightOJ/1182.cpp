#include<stdio.h>
int main()
{
    int i,j,k,o,n,t,r;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        k=0;
        while(n!=0)
        {
            if(n%2==1)
                k++;
            n/=2;
        }
        if(k%2==0)
            printf("Case %d: even\n",r);
        else
            printf("Case %d: odd\n",r);
    }
    return 0;
}
