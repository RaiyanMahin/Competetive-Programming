//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int main()
{
    ll i,t,j,k,l,m,n,a,b,c,d,e,f,g,h;
     sn("%lld",&t);
     while(t--)
     {
         sn("%lld",&n);
         n=(n<0)?-n:n;
        for(i=1;;i++)
        {
            a=(i*(i+1))/2;
            b=a-n;
            if(b>=0&&b%2==0)
                break;
        }

        printf("%lld\n",i);

        if(t!=0)
            printf("\n");
     }
    return 0;
}

