//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
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
int a,p;
}ar[100005],arr[100005];
int mod=1000000007;
bool cmp(T x,T y)
{
    return x.a<y.a;
}
int vis[1000005],mx,bit[100005];
void update(int idx,int val)
{
    while(idx<=mx)
    {
        bit[idx]=(bit[idx]+val)%mod;
        idx+=(idx&-idx);
    }
}

int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum=(sum+bit[idx])%mod;
        idx-=(idx&-idx);
    }
    return sum%mod;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i].a);ar[i].p=i;
            arr[i]=ar[i];
        }
        sort(ar,ar+n,cmp);
        memset(bit,0,sizeof(bit));
        k=0;
        vis[ar[0].p]=++k;
        for(i=1;i<n;i++)
        {
            if(ar[i-1].a==ar[i].a)
                vis[ar[i].p]=k;
            else
                vis[ar[i].p]=++k;
        }
         mx=k;
        for(i=0;i<n;i++)
        {
            b=read(vis[arr[i].p]-1);
            update(vis[arr[i].p],b+1);
        }
        a=b=s=0;
        for(i=1;i<=mx;i++)
        {
            a=read(i);
            if(b>a)
            {
                u=a-b+mod;
                s=(s+u)%mod;
            }
            else
                s=(s+(a-b)%mod)%mod;
            b=a;
        }
        printf("Case %d: %d\n",cs++,s%mod);
    }
    return 0;
}
