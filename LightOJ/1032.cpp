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
ll ar[50],u;
void couut()
{
    ll i,j=0,k=0,a=3,b;
    k=1;j=4;ar[0]=0;ar[1]=0;ar[2]=1;
    for(i=3;i<=31;i++)
    {
        a=a*2+1;
        b=j+(j/2);
        ar[i]=k+k+(a-b+1);
      //  pf("%lld %lld %lld\n",a,k,ar[i]);
        j=j*2;
        k=ar[i];
    }
}
int main()
{
    ll i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,v;
       couut();
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&n);
        u=n;s=0;
        //s=rec(3,n);
      for(i=31;i>=1;i--)
      {
          if(n&(1<<i))
          {
              s=s+ar[i];
              a=1<<i;a=a+(a/2);a--;
              b=n;
              if(b>a)
              {
                 s=s+(b-a);
              }
              n=n^(1<<i);
          }
      }
        printf("Case %lld: %lld\n",r,s);
    }
    return 0;
}



