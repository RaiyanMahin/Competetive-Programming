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
#define PI 2*acos(0)

typedef long long int ll;
using namespace std;
struct T{
int a;
};
char st[300];
double ar[500][500],vm[100005];
int viss[100000],vis[500][500],n,m,mov[500][500],R[]={0,0,1,-1},C[]={1,-1,0,0},D1[]={1,-1,1,-1},D2[]={-1,-1,1,1};
vector<int>arr[100005];
void dfs(int x,int y,int c)
{
    vm[c]+=ar[x][y];
    vis[x][y]=c;
    int i,xx,yy;
    for(i=0;i<4;i++)
    {
        xx=x+R[i];yy=y+C[i];
        if(xx>=0&&yy>=0&&xx<=2*n&&yy<=2*m&&ar[xx][yy]!=0&&vis[xx][yy]==0)
        {

            dfs(xx,yy,c);
        }
    }
    if(mov[x][y]!=0)
    for(i=0;i<4;i++)
    {
        xx=x+D1[i];yy=y+D2[i];
        if(xx>=0&&yy>=0&&xx<=2*n&&yy<=2*m&&ar[xx][yy]!=0&&vis[xx][yy]==0&&viss[mov[xx][yy]]==viss[mov[x][y]]&&viss[mov[xx][yy]]!=-1)
        {

            dfs(xx,yy,c);
        }
    }
}

void dfs1(int u,int c)
{
    viss[u]=c;
    int i,j=arr[u].size();
    for(i=0;i<j;i++)
    {
        if(viss[arr[u][i]]!=c)
            dfs1(arr[u][i],c);
    }
}

int main()
{
    int i,j,k,l,t,r,s,a,b,c,d,e,f,g,h,u,v;
    double cr;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
       for(i=0;i<=2*n;i++)
       {
           for(j=0;j<=2*m;j++)
           {
               ar[i][j]=mov[i][j]=vis[i][j]=0;
           }
       }
       memset(viss,-1,sizeof(viss));
       v=1;cr=PI/4.0;h=1;
       for(i=0,a=0;i<n;i++,a+=2)
        {
            scanf("%s",&st);
            for(j=0,b=0;j<m;j++,b+=2)
            {
                if(st[j]=='0')
                {
                    ar[a][b]+=cr; ar[a][b+1]+=0; ar[a][b+2]+=1;
                    ar[a+1][b]+=0; ar[a+1][b+1]+=(2*(1-cr)); ar[a+1][b+2]+=0;
                    ar[a+2][b]+=1; ar[a+2][b+1]+=0; ar[a+2][b+2]+=cr;
                    e=0;
                    if(mov[a][b+2]!=0)
                    {
                        arr[mov[a][b+2]].push_back(v);
                        arr[v].push_back(mov[a][b+2]);
                    }
                    if(mov[a+1][b+1]!=0)
                    {
                        arr[mov[a+1][b+1]].push_back(v);
                        arr[v].push_back(mov[a+1][b+1]);
                    }
                    if(mov[a+2][b]!=0)
                    {
                        arr[mov[a+2][b]].push_back(v);
                        arr[v].push_back(mov[a+2][b]);
                    }
                     mov[a][b+2]=mov[a+1][b+1]=mov[a+2][b]=v;
                    v++;
                }
                else
                {
                    ar[a][b]+=1;ar[a][b+1]+=0;ar[a][b+2]+=cr;
                    ar[a+1][b]+=0;ar[a+1][b+1]+=(2*(1-cr));ar[a+1][b+2]+=0;
                    ar[a+2][b]+=cr;ar[a+2][b+1]+=0;ar[a+2][b+2]+=1;
                    e=0;
                    if(mov[a][b]!=0)
                    {
                        arr[mov[a][b]].push_back(v);
                        arr[v].push_back(mov[a][b]);
                    }
                    if(mov[a+1][b+1]!=0)
                    {
                        arr[mov[a+1][b+1]].push_back(v);
                        arr[v].push_back(mov[a+1][b+1]);
                    }
                    if(mov[a+2][b+2]!=0)
                    {
                        arr[mov[a+2][b+2]].push_back(v);
                        arr[v].push_back(mov[a+2][b+2]);
                    }

                        mov[a][b]=mov[a+1][b+1]=mov[a+2][b+2]=v;
                        v++;

                }
            }
        }
        c=1;
        for(i=1;i<v;i++)
        {
            if(viss[i]==-1)
            {
                dfs1(i,c);c++;
            }
        }
        c=1;
        for(i=0;i<=2*n;i++)
        {
            for(j=0;j<=2*m;j++)
            {
                if(vis[i][j]==0&&ar[i][j]!=0)
                {
                    vm[c]=0;
                    dfs(i,j,c);c++;
                }
           //     pf("%3d ",mov[i][j]);
            }
         //   pf("\n");
        }
        u=0;
        int q; printf("Case %d:\n",r);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            if(vis[a][b]==0||ar[a][b]==0)
                printf("%.10lf\n",0);
            else
                 printf("%.10lf\n",vm[vis[a][b]]);
        }


         for(i=1;i<=v;i++)
            arr[i].clear();
    }
    return 0;
}

