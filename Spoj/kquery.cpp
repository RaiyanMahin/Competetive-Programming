//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
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
int a,b,c,d;
}ar[2000005];
int tr[200005],id[200005];
void update(int x,int n)
{
    while(x<=n)
    {
        tr[x]++;
        x=x+(x&-x);
    }
}
int query(int x)
{
    int s=0;
    while(x>0)
    {
        s+=tr[x];
        x=x-(x&-x);
    }
    return s;
}
bool cmp1(T x,T y)
{
    if(x.a==y.a)
        return x.d>y.d;
        return x.a>y.a;
}
int ans[2000005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&n);
    for(i=0;i<n;i++)
    {
        sn("%d",&ar[i].a);
        ar[i].b=i+1;
        ar[i].d=0;
    }
    sn("%d",&m);
    for(j=0;j<m;j++,i++)
    {
        sn("%d %d %d",&ar[i].b,&ar[i].c,&ar[i].a);
        ar[i].d=j+1;
    }
    memset(tr,0,sizeof(tr));
    sort(ar,ar+n+m,cmp1);
    for(i=0;i<n+m;i++)
    {
        if(ar[i].d==0)
        {
            update(ar[i].b,n);
        }
        else
        {
            ans[ar[i].d]=query(ar[i].c)-query(ar[i].b-1);
        }
    }
    for(i=1;i<=m;i++)
    {
        pf("%d\n",ans[i]);
    }
    return 0;

}
