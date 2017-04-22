
#include<stdio.h>
#include<vector>
#include<queue>
#define sz 1000001
using namespace std;

struct T{

long long u,w;
bool operator <(const T & b)const
    {
        return (w>b.w);
    }
}temp;
vector<T>ar[sz];
priority_queue<T>Q;
long long dis[sz],vis[sz];

long long inf=100000000000000000;
int main()
{
    long long t,r,n,m,s,d,hs,u,v,w,i,j,k;
    //  freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&s,&d);
        for(i=0;i<n;i++)
         {
             ar[i].clear();
             dis[i]=inf;vis[i]=0;
         }
        for(i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            temp.u=v;temp.w=w;
            ar[u].push_back(temp);
            temp.u=u;
            ar[v].push_back(temp);
        }

        dis[s]=0;temp.u=s;temp.w=0;
        Q.push(temp);
        while(!Q.empty())
        {
            temp=Q.top();
            Q.pop();
            u=temp.u;
            if(!vis[u])
            {
                vis[u]=1;
                for(i=0,j=ar[u].size();i<j;i++)
                {
                    temp=ar[u][i];
                    v=temp.u;
                    w=temp.w;
                    if(dis[v]>dis[u]+w)
                    {
                        dis[v]=dis[u]+w;
                        temp.u=v;
                        temp.w=dis[v];
                        Q.push(temp);
                    }
                }
            }
        }
        printf("Case #%lld: ",r);
        if(dis[d]==inf)
            printf("unreachable\n");
        else
            printf("%lld\n",dis[d]);
    }
   // fclose(stdout);
   return 0;
}
