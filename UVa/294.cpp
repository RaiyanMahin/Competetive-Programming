#include<math.h>
#include<stdio.h>
#define N 10000000
bool ar[N];
int main()
{
    long long int i,j,t,k,l,m,n,u,r,a,dr;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    scanf("%lld",&t);
    for(r=0;r<t;r++)
    {
        scanf("%lld %lld",&n,&m);
        l=k=0;a=n;
        for(j=n;j<=m;j++)
        {
            l=0;
            if(j<=10000000&&ar[j]==1||j%2==0||j==1)
             for(i=1;i<=sqrt(j);i++)
           {
                if(j%i==0)
                    l++;
           }
            l=l*2;
            dr=sqrt(j);
           if(dr*dr==j)
            l--;
           if(l>k)
           {
               a=j;k=l;
           }
        }
        if(a==1)
            k==1;
        if(a!=0&&k==0)
            k=2;
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",n,m,a,k);
    }
    return 0;
}

