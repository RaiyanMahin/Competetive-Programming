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
char st[30][30];
int dis[30][30],px[5],py[5],h1,h2,R[]={0,0,1,-1},C[]={1,-1,0,0};
queue<int>Q;
int main()
{
    int i,j,x,y,mn,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d %d",&n,&m);c=0;
         for(i=0;i<n;i++)
         {
             scanf("%s",&st[i]);
             for(j=0;j<m;j++)
             {
                 if(st[i][j]>='a'&&st[i][j]<='c')
                    px[c]=i,py[c]=j,c++;
                 if(st[i][j]=='h')
                    h1=i,h2=j;
             }
         }
         mn=0;
        // printf("%d %d\n",h1,h2);
        for(i=0;i<3;i++)
        {
           // printf("%d %d\n",px[i],py[i]);
             for(a=0;a<n;a++)
                for(b=0;b<m;b++)
                  dis[a][b]=N;
            Q.push(px[i]);Q.push(py[i]);dis[px[i]][py[i]]=0;
            while(!Q.empty())
            {
                u=Q.front();Q.pop();
                v=Q.front();Q.pop();
                for(k=0;k<4;k++)
                {
                    x=u+R[k];y=v+C[k];
                    if(x>=0&&y>=0&&x<n&&y<m&&st[x][y]!='m'&&st[x][y]!='#'&&dis[x][y]>dis[u][v]+1)
                    {
                        dis[x][y]=dis[u][v]+1;
                        Q.push(x);
                        Q.push(y);
                    }
                }
            }
           // printf("%d\n",dis[h1][h2]);
            if(dis[h1][h2]>mn)
                mn=dis[h1][h2];
        }
        printf("Case %d: %d\n",r,mn);
     }
    return 0;
}

