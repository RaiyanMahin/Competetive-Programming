#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

struct T{
int u,w;
bool operator<(const T & b)const
{
    return (u>b.u);
}
}temp;

vector<int>arr[900];
vector<T>ar[900];
priority_queue<T>Q;
int inf=1000000000,dis[905],vis[905];

int main()
{
    int i,j,k,l,m,n,s,d,a,b,c,u,w,v,tm[10];
    char ch;
    while(scanf("%d %d",&n,&d)==2)
    {
        s=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&tm[i]);
        }
        for(i=1;i<=n;i++)
        {
            j=0;
            while(scanf("%d%c",&a,&ch)!=EOF)
            {
               if(j!=0)
               {
                   c=i*100;
                   temp.u=a+c;temp.w=(a-u)*tm[i];
                   ar[u+c].push_back(temp);
                   temp.u=u+c;
                   ar[a+c].push_back(temp);
                   vis[a+c]=vis[u+c]=1;
               }
               u=a;
               j++;
               if(ch=='\n')
                break;
            }
        }
        for(i=0;i<=100;i++)
        {
            for(j=1;j<5;j++)
            {
                for(k=j+1;k<=5;k++)
                {
                    a=i+j*100;
                    u=i+k*100;
                   if(vis[u]&&vis[a])
                   {
                       temp.u=a;temp.w=60;
                       if(i==0)
                        temp.w=0;
                   ar[u].push_back(temp);
                   temp.u=u;
                   ar[a].push_back(temp);
                   }
                }
            }
        }
         for(i=100;i<=500;i+=100)
            if(vis[i])
        {
            s=i;break;
        }
        for(i=0;i<=905;i++)
        {
            dis[i]=inf;vis[i]=0;
        }

        temp.u=s;dis[s]=temp.w=0;
        Q.push(temp);
        while(!Q.empty())
        {
            temp=Q.top();
            Q.pop();
            u=temp.u;
            if(!vis[u])
            {
                vis[u]=1;

                for(i=0;i<ar[u].size();i++)
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
                        vis[v]=0;
                       // printf("%d %d\n",v,dis[v]);
                    }
                }
            }
        }
        s=inf;
        for(i=100;i<=500;i+=100)
        {
            c=i+d;
            if(dis[c]<s)
                s=dis[c];
        }
        if(s==inf)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",s);
     for(i=0;i<=805;i++)
        ar[i].clear();

    }
   return 0;
}


