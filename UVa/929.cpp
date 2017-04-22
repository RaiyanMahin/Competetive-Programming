#include<stdio.h>
#include<vector>
#define sz 1000008
#define inf 2147483000
using namespace std;

struct T
{
int u,v,w;
}temp,H[2*sz];
int dis[1000][1000],vis[1000][1000],M[1000][1000];

void Min_Heapify(int p,int n)
{
    if(n==0||p==0) return;
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
    if(l<=n&&H[v].w>H[l].w)
    {
        v=l;
    }
    if(r<=n&&H[v].w>H[r].w)
    {
        v=r;
    }

    if(v!=p)
    {
        T a;
        a=H[p];
        H[p]=H[v];H[v]=a;
        update_Min_Heapify(v,n);
    }
}

int main()
{
    int n,m,i,j,k,u,v,w,t,aa,b,s,hs,d,sx,sy,dx,dy;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=1,k=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
               scanf("%d",&M[i][j]);
               dis[i][j]=inf;vis[i][j]=0;
            }
        }
        sx=1;sy=1;dx=n;dy=m;
        temp.u=sx;temp.v=sy;temp.w=0;
        dis[sx][sy]=M[sx][sy];H[1]=temp;hs=1;
        while(hs)
        {
            temp=H[1];H[1]=H[hs--];
            update_Min_Heapify(1,hs);
            u=temp.u;v=temp.v;
            if(!vis[u][v])
            {

                   // printf("%d\n",dis[k-1]);
                vis[u][v]=1;
                int x,y,R[]={0,0,1,-1},C[]={1,-1,0,0};
                for(i=0;i<4;i++)
                {
                    x=u+C[i];y=v+R[i];
                    if(x>=1&&y>=1&&x<=n&&y<=m)
                    {
                        w=M[x][y];
                        if(dis[x][y]>dis[u][v]+w)
                        {
                            dis[x][y]=dis[u][v]+w;
                            temp.u=x;temp.v=y;temp.w=dis[x][y];
                            H[++hs]=temp;
                            Min_Heapify(hs/2,hs);
                        }
                    }

                }

            }

        }
//for(i=0;i<k;i++)
//    printf(" %d",dis[i]);
        printf("%d\n",dis[dx][dy]);

    }
    return 0;
}
