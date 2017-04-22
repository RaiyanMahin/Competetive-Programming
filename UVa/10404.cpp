//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>

long long int gcd(long long int n,long long int m)
{
   long long int i=1,t,a;
    if(m>n)
    {
        t=n;n=m;m=t;
    }
    while(n%m!=0)
    {
        i++;
        t=m;
        m=n%m;n=t;
         if(m>n)
       {
        t=n;n=m;m=t;
       }
    }
    return i;
}
int main()
{
   long long int i,j,k,l,a,b,c,d,t,m,ar[20],n;
    while(scanf("%lld %lld",&n ,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        if(m>n)
        {
        t=n;n=m;m=t;
        }
       if(n!=0&&m!=0&&n!=m&&(n%m)!=0)
       {
            k=n/m;
            for(i=k;i>=1;i--)
            {
                j=gcd(m,(n-(m*i)));
                a=m;b=n-(m*i);
                if(j%2==0)
                {
                    if(b>a)
                    {
                        t=a;a=b;b=t;
                    }
                    c=a/b;
                    for(l=c;l>=1;l--)
                    {
                        d=gcd(b,(a-(b*l)));
                        if(d%2==0)
                            break;
                    }
                    if(d%2==0)
                    {
                        j=1;
                    }
                    else
                        break;
                }

            }
       }
        if(n==m&&n!=0&&m!=0)
            printf("Stan wins\n");
        else if(j%2==0&&n!=0&&m!=0)
            printf("Stan wins\n");
        else if(n!=0&&m!=0&&n%m==0)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");

    }
 return 0;
}
