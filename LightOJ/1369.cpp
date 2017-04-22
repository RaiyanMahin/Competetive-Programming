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

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll ar[100005],arr[100005];
int main()
{
    ll i,j,k,l,t,r,s,m,n,q,a,b,c,d,e,f,g,h,u,v;
     scanf("%lld",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%lld %lld",&n,&q);s=0;
         for(i=0,b=n-1;i<n;i++,b--)
         {
             scanf("%lld",&a);

             ar[i]=b-i;
             s=s+(ar[i]*a);
             arr[i]=(ar[i]*a);
         }
         printf("Case %lld:\n",r);
         while(q--)
         {
             scanf("%lld",&b);
             if(b==1)
                printf("%lld\n",s);
             else
             {
                 scanf("%lld %lld",&a,&v);
                 s=s-arr[a];
                 arr[a]=(ar[a]*v);
                 s=s+(ar[a]*v);
             }
         }
     }
    return 0;
}

