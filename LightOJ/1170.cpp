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
map<ll,ll>s;
ll aa[1300000],uu=10000000000;
ll md=100000007;
ll ar[100009];

ll binry(ll a,ll b,ll k)
{
    ll l=0,h=k-1,u,v;
    while(l<=h)
    {
        md=(l+h)/2;
        if(aa[md]>=a)
        {
            if(md!=0&&aa[md-1]>=a)
                h=md-1;
            else
                break;
        }
        else if(aa[md]<a)
            l=md+1;
    }
    u=md;
    l=0,h=k-1;
    while(l<=h)
    {
        md=(l+h)/2;
        if(aa[md]<=b)
        {
            if(md!=k-1&&aa[md+1]<=b)
                l=md+1;
            else
                break;
        }
        else if(aa[md]>a)
            h=md-1;
    }
    if(l>h)
        v=-3;
    else
    v=md;
    if(v-u<0)
        return -1;
    else
        return v-u+1;
}
ll C(ll n)
{
    if(n<0)
        return 0;
    if(ar[n]!=-1)
        return ar[n];
    ll ans=0;
    if(n==0)
        ans=1;
    for(ll i=1;i<=n;i++)
    {
        ans=((ans%md)+((C(i-1)%md)*(C(n-i)%md))%md)%md;
    }
    return ar[n]=ans;
}
int main()
{
    ll i,a,b,j,c,d,k=0,t,r;
    memset(ar,-1,sizeof(ar));
    for( i=2;i<=sqrt(uu);i++)
    {
        a=i;
        if(s[a]==0)
        for(j=2;;j++)
        {
            a=a*i;
            if(a>uu)
                break;

                s[a]=1;
               aa[k++]=a;
        }
    }
    r=C(1200);
    sort(aa,aa+k);
   scanf("%lld",&t);
   for(r=1;r<=t;r++)
   {
       scanf("%lld %lld",&a,&b);
       c=binry(a,b,k);
        printf("Case %lld: %lld\n",r,C(c));
   }
    return 0;
}


