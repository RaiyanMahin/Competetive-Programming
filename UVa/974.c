#include<stdio.h>
int main()
{
    long long int n,m,i,k,l,g,p1,p2,ten;
    int t,r;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld",&n,&m);k=0;
        printf("case #%d\n",r);
        for(i=n;i<=m;i++)
        {
           g=l=i*i;
           ten=10;p1=0;p2=0;
            while(l!=0)
            {
                p1=g/ten;
                p2=g%ten;
                l=l/10;
                if((p1+p2==i)&&p1!=0&&p2!=0)
               {
                   printf("%lld\n",i);k=2;
               }
               ten*=10;
            }
        }
        if(k==0)
            printf("no kaprekar numbers\n");
        if(r!=t)
        printf("\n");
    }
    return 0;
}
