#include<stdio.h>
int main()
{
    long long int n,m,t,r,i,j,k;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld",&n,&m);
        k=0;
         if(n%3!=0)
         {

             for(;;)
             {
                 if(n%3==0)
                    {
                        k++;break;
                    }
                if((n+1)%3==0)
                    k++;
                 n++;
             }
         }
         else
            k=1;
         if(m%3!=0)
         {
             m++;
             for(;;)
             {
                 if(m%3==0)
                    {
                        k--;break;
                    }
                if((m+1)%3==0)
                    k--;
                    m++;

             }
         }
         j=(m-n)/3;
         k=k+(j*2);
        printf("Case %lld: %lld\n",r,k);

    }
    return 0;
}

