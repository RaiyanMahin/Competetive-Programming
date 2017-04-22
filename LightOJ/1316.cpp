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
 int nd,vv;
   T(int nd=0,int vv=0) : nd(nd),vv(vv)
   {
       ;
   }
   bool operator <(const T &b) const
   {
          return (vv<b.vv);
   }
}temp;

int Inf=1000000000;
priority_queue<T>Q;

vector <int > E[503],cst[503];
int dis[503][503],vis[600],ar[25];

struct TT{
 int x,y;
 TT(int x=0,int y=0) :x(x),y(y){
 ;
 }
}tep;
int dp[17][(1<<15)+1],arr[20],des,Tb;
int rec(int u,int msk)
{
    if(msk==0)
    {
        return dis[arr[u]][des];
    }
    int &ret=dp[u][msk];
    if(ret!=-1)
        return ret;
    ret=Inf;
    for(int i=0;i<Tb;i++)
    {
        if((msk&(1<<i)))
        {
            ret=min(ret,dis[arr[u]][arr[i]]+rec(i,msk^(1<<i)));
        }
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,sp,w,d,e,f,g,h,u,v,pd,pm,shop;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&sp);
        memset(vis,0,sizeof(vis));
        Tb=shop=sp;des=n-1;
        for(i=0;i<sp;i++)
        {
            scanf("%d",&ar[i]);
            arr[i]=ar[i];
            vis[ar[i]]=1;
        }
        if(vis[0]==0)
            ar[sp++]=0;
        if(vis[n-1]==0)
            ar[sp++]=n-1;
        sort(ar,ar+sp);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            E[u].pb(v);
            cst[u].pb(w);
        }
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                dis[j][i]=Inf;
            }
            dis[i][i]=0;
        }
        sort(arr,arr+shop);
        for(l=0;l<sp;l++)
        {

               a=ar[l];dis[a][a]=0;
              Q.push(T(a,0));
            while(!Q.empty())
            {
                temp=Q.top();Q.pop();
                u=temp.nd;
                pd=dis[a][u];
                for(i=0,j=E[u].size();i<j;i++)
                {
                    v=E[u][i];
                    d=cst[u][i];
                    if(dis[a][v]>pd+d)
                    {
                       dis[a][v]=pd+d;
                        Q.push(T(v,dis[a][v]));
                    }

                }
            }
        }
        int ans=Inf,anx=0;
        memset(dp,-1,sizeof(dp));
        arr[16]=0;
        for(i=shop;i>=0;i--)
        {
            for(j=(1<<shop)-1;j>=0;j--)
            {
                if(__builtin_popcount(j)==i)
                {
                       if(arr[0]==0&&(j&1)==0)
                        continue;
                       if(arr[0]==0){
                          j=j^1;
                          u=rec(0,j);
                       }
                       else
                       {
                           u=rec(16,j);
                       }
                        if(u<Inf)
                        {
                            ans=min(ans,u);
                            anx=i;
                        }
                }
            }
            if(ans<Inf)
                break;
        }
        if(ans<Inf)
        {
            printf("Case %d: %d %d\n",r++,anx,ans);
        }
        else
        {
            printf("Case %d: Impossible\n",r++);
        }
        for(i=0;i<=n;i++)
        {
            E[i].clear();
            cst[i].clear();
        }
    }
    return 0;
}
