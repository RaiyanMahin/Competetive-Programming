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
int a;
};
int tree[800005],ar[200005];

void build(int p,int l,int r,int n)
{
    if(l==r)
    {
        if(l>=n)
            tree[p]=0;
        else
            tree[p]=1;
        return;
    }
   int md=(l+r)/2;
   build(2*p,l,md,n);
   build(2*p+1,md+1,r,n);
   tree[p]=tree[2*p]+tree[2*p+1];
}

void update(int p,int l,int r,int ps,int val)
{
    if(r<ps||l>ps)
        return;
    if(l==ps&&l==r)
    {
        tree[p]=1;
        return;
    }
    int mid=(l+r)/2;
    update(2*p,l,mid,ps,val);
    update(2*p+1,mid+1,r,ps,val);
    tree[p]=tree[2*p]+tree[2*p+1];
}

int query(int p,int l,int r,int ps,int cnt)
{
    if(tree[p]+cnt==ps&&l==r)
    {
        tree[p]=0;
        return ar[l];
    }
    int mid=(l+r)/2,a;
    if(tree[2*p]+cnt>=ps)
    {
        a=query(2*p,l,mid,ps,cnt);
    }
    else
    {
        cnt+=tree[2*p];
        a=query(2*p+1,mid+1,r,ps,cnt);
    }
    tree[p]=tree[2*p]+tree[2*p+1];
    return a;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,q,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        m=n+q-1;
        build(1,0,m,n);
        printf("Case %d:\n",cs++);
        while(q--)
        {
            char st[20];
            scanf("%s %d",&st,&u);
            if(st[0]=='a')
            {
               ar[n++]=u;
               update(1,0,m,n-1,u);
            }
            else if(st[0]=='c')
            {
                if(tree[1]>=u)
                {
                    printf("%d\n",query(1,0,m,u,0));

                }
                else
                    printf("none\n");
            }
        }
    }
    return 0;
}
