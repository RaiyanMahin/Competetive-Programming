//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 1000000
long long int ar[3000000]={0},pr[100000];
int main()
{
    long long int i,j,k,n;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
    k=1;pr[0]=2;
    for(i=3;i<=N;i+=2)
        if(ar[i]==0)
    {
       pr[k]=i;k++;

    }
    long long int m,l,a,b,c,d1,d2,e,f,lg1,lg2,sm1,sm2;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
         c=1;d1=10000000;d2=0;f=0;
         lg1=lg2=sm2=sm1=0;
         memset(ar,0,sizeof(ar));
         if(a==1||a==0)
            a=2;
        for(i=0;i<k;i++)
        {
            if(pr[i]>sqrt(b))
                break;
            c=a/pr[i];

            for(j=pr[i]*c;j<=b;j+=(pr[i]))
                if(j!=pr[i]&&j%pr[i]==0)
            {
                e=j%1100000;
                ar[e]=1;
            }
        }
        f=0;
        if(a==2)
            f=2;
        if(a%2==0)
            a++;
        for(i=a;i<=b;i+=2)
        {
            e=i%1100000;
             if((ar[e]==0&&i%2!=0)||i==2)
            {
                if(f!=0)
                {
                    if(i-f<d1)
                    {
                        sm1=f;sm2=i;d1=i-f;
                    }
                    if(i-f>d2)
                    {
                        lg1=f;lg2=i;d2=i-f;
                    }
                    f=i;
                }
                else
                {
                    f=i;
                }
            }
        }
        if(sm1==0)
            printf("There are no adjacent primes.\n");
        else
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",sm1,sm2,lg1,lg2);
    }
    return 0;
}


