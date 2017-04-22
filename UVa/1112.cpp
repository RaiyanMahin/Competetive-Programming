#include<stdio.h>
#include<vector>
#define sz 1000
#define inf 2000000
using namespace std;

int dis[200][200];

int main()
{
    int r,t,n,m,k,i,j,ti,E,hs,s,d,u,v,w,a,b,mice;

    scanf("%d\n",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d%d%d%d",&n,&E,&ti,&m);
        for(i=0;i<=105;i++)
        {
            for(j=0;j<=105;j++)
            {
                dis[i][j]=inf;
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&w);
           dis[a][b]=w;
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
        mice=0;
        for(i=1;i<=n;i++)
        {
            if(dis[i][E]<=ti||i==E)
                mice++;
        }
        printf("%d\n",mice);
        if(r!=t)
            printf("\n");
    }

    return 0;
}
/*
#include<stdio.h>
#include<vector>
#define sz 1000
#define inf 2000000
using namespace std;

struct T{
int u,w;

}temp,H[sz];
int dis[sz],vis[sz];
vector<T>ar[sz];

void Min_Heapify(int p,int n)
{
    if(n==0||p==0)return;
    if(H[p].w>H[n].w)
    {
        T a=H[p];
        H[p]=H[n];H[n]=a;
        Min_Heapify(p/2,p);
    }
}
void update_Min_Heapify(int p,int n)
{
    int l,r,v=p;
    l=2*p;
    r=2*p+1;
    if(l<=n&&H[l].w<H[v].w)
    {
        v=l;
    }
    if(r<=n&&H[r].w<H[v].w)
    {
        v=r;
    }
    if(v!=p)
    {
        T a=H[p];
        H[p]=H[v];H[v]=a;
        update_Min_Heapify(v,n);
    }
}
int main()
{
    int r,t,n,m,k,i,j,ti,E,hs,s,d,u,v,w,a,b,mice;

    scanf("%d\n",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d%d%d%d",&n,&E,&ti,&m);
        for(i=0;i<=n;i++)
        {
            ar[i].clear();
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&w);
            temp.u=b;temp.w=w;
            ar[a].push_back(temp);
        }
        mice=0;
        for(i=1;i<=n;i++)
        {
            for(k=0;k<=n;k++)
            {
                dis[k]=inf;vis[k]=0;
            }
            s=i;dis[s]=0;temp.u=i;
            temp.w=0;H[1]=temp;hs=1;
            while(hs)
            {
                temp=H[1];H[1]=H[hs--];
                update_Min_Heapify(1,hs);
                u=temp.u;
                if(!vis[u])
                {
                    vis[u]=1;
                    for(j=0,k=ar[u].size();j<k;j++)
                    {
                        temp=ar[u][j];
                        v=temp.u;w=temp.w;
                        if(dis[v]>dis[u]+w)
                        {
                            dis[v]=dis[u]+w;
                            T a;
                            a.u=v;a.w=dis[v];
                            H[++hs]=a;
                            Min_Heapify(hs/2,hs);
                        }
                    }
                }
            }

            if(dis[E]>=ti)
               mice++;

        }
        printf("%d\n",mice);
        if(r!=t)
            printf("\n");
    }

    return 0;
}
*/
