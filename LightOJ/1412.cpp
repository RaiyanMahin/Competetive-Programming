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
int r,n;
}ary[100005];
vector<int>ar[100005];
int vis[100005],dis[100005],diss[100005],nd;
queue<int>Q;
int bfs(int u,int c)
{
    int v,i,j,k,mx=0;
    if(ar[u].size()==0)return 0;
    Q.push(u);dis[u]=0;
    while(!Q.empty())
    {

        u=Q.front();Q.pop();
        if(vis[u]==-1)nd++;
        vis[u]=c;
        j=ar[u].size();
        for(i=0;i<j;i++)
        {
            v=ar[u][i];
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                if(dis[v]>mx||k==v)
                {
                    mx=dis[v];k=v;
                }
                Q.push(v);
            }
        }
    }
     Q.push(k);diss[k]=0;mx=0;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        j=ar[u].size();
        for(i=0;i<j;i++)
        {
            v=ar[u][i];
            if(diss[v]>diss[u]+1)
            {
                diss[v]=diss[u]+1;
                if(diss[v]>mx||k==v)
                {
                    mx=diss[v];k=v;
                }
                Q.push(v);
            }
        }
    }
    return mx;
}

bool cmp(T x,T y)
{
    return x.r>y.r;
}

int main()
{
    int i,j,k,l,t,r,q,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        memset(vis,-1,sizeof(vis));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            ar[u].push_back(v);
            ar[v].push_back(u);
            dis[u]=dis[v]=N;
            diss[u]=diss[v]=N;
        }
        c=0;int mnd=0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                nd=0;
                d=bfs(i,c);
                ary[c].n=nd;ary[c].r=d;
                if(nd>mnd)mnd=nd;
                c++;
            }
        }
        sort(ary,ary+c,cmp);
        scanf("%d",&q);
        pf("Case %d:\n",r);
//        for(i=0;i<c;i++)
//            pf("%d %d\n",ary[i].n,ary[i].r);
        while(q--)
        {
            scanf("%d",&b);
            g=0;
            if(b<=mnd)
            for(i=0;i<c;i++)
            {
                if(b<=ary[i].n)
                {
                    if(b>ary[i].r+1)
                    {
                        h=ary[i].r;b-=(ary[i].r+1);
                        h=h+2*b;
                    }
                    else
                        h=b-1;
                    printf("%d\n",h);g=1;
                    break;
                }
            }
            else pf("impossible\n");
        }
        for(i=1;i<=n;i++)
            ar[i].clear();
    }
    return 0;
}

