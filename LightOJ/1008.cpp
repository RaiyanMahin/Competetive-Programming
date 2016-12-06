#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    long long int i,j,k,l,m,s,n,x,y,t,r;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&s);
        k=sqrt(s);
        if(k*k==s)
           {
               if(k%2==0)
               {
                   x=k;y=1;

               }
               else
               {
                   y=k;x=1;
               }
           }
        else
        {
            k+=1;
            m=(k*k)-k+1;
            i=k;
            j=m-s;
            if(k%2==0)
            {
                if(j>=0)
                {
                    y=k;
                    x=k-(m-s);
                }
                else
                {
                    x=k;
                    y=k-abs(m-s);
                }
            }
            else
            {
                 if(j>=0)
                {
                    x=k;
                    y=k-(m-s);
                }
                else
                {
                    y=k;
                    x=k-abs(m-s);
                }
            }
        }
        printf("Case %lld: %lld %lld\n",r,x,y);

    }
    return 0;
}
