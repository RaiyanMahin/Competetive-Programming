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
#define N 100000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
queue<int>Q;
int R[]={1,-1,0,0},C[]={0,0,-1,1},n;
char st[20][20];
vector<int>th,ex;
int dis[11][11][11][11][11][11],vis[11][11];
int isp(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<n&&st[x][y]!='#'&&vis[x][y]==0)
        return 1;
    return 0;
}
int main()
{
    int i,j,k,l,t,r,s,m,a,b,c,d,e,f,g,h,u1,v1,u2,v2,u3,v3,x1,y1,x2,y2,x3,y3;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&st[i]);
            for(j=0;j<n;j++)
            {
                if(st[i][j]>='A'&&st[i][j]<='C')
                {
                    th.push_back(i);th.push_back(j);
                }
                if(st[i][j]=='X')
                {
                    ex.push_back(i);ex.push_back(j);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(a=0;a<n;a++)
                {
                    for(b=0;b<n;b++)
                    {
                       for(c=0;c<n;c++)
                            {
                                for(d=0;d<n;d++)
                                {
                                   dis[i][j][a][b][c][d]=N;vis[c][d]=0;
                                }
                            }
                    }
                }
            }
        }
        for(i=0;i<6;i++)
        {
            Q.push(th[i]);
        }
        dis[th[0]][th[1]][th[2]][th[3]][th[4]][th[5]]=0;
        while(!Q.empty())
        {
            u1=Q.front();Q.pop();v1=Q.front();Q.pop();
            u2=Q.front();Q.pop();v2=Q.front();Q.pop();
            u3=Q.front();Q.pop();v3=Q.front();Q.pop();
            for(i=0;i<4;i++)
            {
                if(isp(u1+R[i],v1+C[i])==1)
                  x1=u1+R[i],y1=v1+C[i];
                else x1=u1,y1=v1;
                vis[x1][y1]=1;
                if(isp(u2+R[i],v2+C[i])==1)
                  x2=u2+R[i],y2=v2+C[i];
                else if(isp(u2,v2)==1)
                    x2=u2,y2=v2;
                else
                {  vis[x1][y1]=0;
                    x1=u1,y1=v1;x2=u2,y2=v2;
                }
                vis[x2][y2]=1;vis[x1][y1]=1;
                if(isp(u3+R[i],v3+C[i])==1)
                  x3=u3+R[i],y3=v3+C[i];
                else if(isp(u3,v3)==1)
                    x3=u3,y3=v3;
                else {
                          vis[x2][y2]=0;vis[x1][y1]=0;
                        if(u1==u3-R[i]&&v1==v3-C[i])
                        {
                            if(u1==x2&&v1==y2)
                                x1=u1,y1=v1,x2=u2,y2=v2,x3=u3,y3=v3;
                            else
                                x1=u1,y1=v1,x3=u3,y3=v3;
                        }
                        if(u2==u3-R[i]&&v2==v3-C[i])
                        {
                            if(u2==x1&&v2==y1)
                                x1=u1,y1=v1,x2=u2,y2=v2,x3=u3,y3=v3;
                            else
                                x2=u2,y2=v2,x3=u3,y3=v3;
                        }

                }
                vis[x3][y3]=0; vis[x2][y2]=0;vis[x1][y1]=0;

                if(dis[x1][y1][x2][y2][x3][y3]>dis[u1][v1][u2][v2][u3][v3]+1)
                {
                    dis[x1][y1][x2][y2][x3][y3]=dis[u1][v1][u2][v2][u3][v3]+1;
                    Q.push(x1);Q.push(y1);
                    Q.push(x2);Q.push(y2);
                    Q.push(x3);Q.push(y3);
                }
            }
        }g=0;
        int mn=N;
        x1=ex[0];y1=ex[1];x2=ex[2];y2=ex[3];x3=ex[4];y3=ex[5];

            if(dis[x1][y1][x2][y2][x3][y3]<mn)
                mn=dis[x1][y1][x2][y2][x3][y3];
            if(dis[x1][y1][x3][y3][x2][y2]<mn)
                mn=dis[x1][y1][x3][y3][x2][y2];
            if(dis[x2][y2][x1][y1][x3][y3]<mn)
                mn=dis[x2][y2][x1][y1][x3][y3];
            if(dis[x2][y2][x3][y3][x1][y1]<mn)
                mn=dis[x2][y2][x3][y3][x1][y1];
            if(dis[x3][y3][x2][y2][x1][y1]<mn)
                mn=dis[x3][y3][x2][y2][x1][y1];
            if(dis[x3][y3][x1][y1][x2][y2]<mn)
                mn=dis[x3][y3][x1][y1][x2][y2];
            if(mn==N)
                printf("Case %d: trapped\n",r);
            else
                 printf("Case %d: %d\n",r,mn);
        th.clear();ex.clear();
    }
    return 0;
}

