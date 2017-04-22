//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
int main()
{
   ll i,j,k,l,t,r=1,s,m,n,ans;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        ans=0;l=0;m=n;
        for(j=2;j<=sqrt(n);j++)
        {
            k=1;
            while(n%j==0)
            {
                k*=j;
                n=n/j;
            }
            if(k>1)
              {
                  ans=ans+k;
                  l++;
              }
        }
        if(n>1)
        {
            ans=ans+n;
            l++;
        }
        if(l<=1)
        {
            ans=m+1;
        }
        printf("Case %lld: %lld\n",r,ans);
        r++;
    }
    return 0;
}


