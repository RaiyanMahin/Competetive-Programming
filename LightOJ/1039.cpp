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
queue<int>Q;
int vis[30][30][30],dis[30][30][30];
int R1[]={1,-1,0,0,0,0},R2[]={0,0,1,-1,0,0},R3[]={0,0,0,0,1,-1};
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v,x,y,z;
    char s1[50],s2[50],s3[50],en[50],st[50];
    char Ch='a';
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%s %s %d",&st,&en,&n);
        for(i=0;i<30;i++)
            {
                for(j=0;j<30;j++)
                {
                    for(k=0;k<30;k++)
                    {
                        vis[i][j][k]=0;
                        dis[i][j][k]=N;
                    }
                }
            }
        for(a=0;a<n;a++)
        {
            scanf("%s%s%s",&s1,&s2,&s3);
            for(i=0;i<strlen(s1);i++)
            {
                for(j=0;j<strlen(s2);j++)
                {
                    for(k=0;k<strlen(s3);k++)
                    {
                        vis[s1[i]-Ch][s2[j]-Ch][s3[k]-Ch]=1;
                    }
                }
            }
        }
        Q.push(st[0]-Ch);Q.push(st[1]-Ch);Q.push(st[2]-Ch);

        if(vis[st[0]-Ch][st[1]-Ch][st[2]-Ch]!=1)
            dis[st[0]-Ch][st[1]-Ch][st[2]-Ch]=0;
        while(!Q.empty())
        {
            a=Q.front();Q.pop();
            b=Q.front();Q.pop();
            c=Q.front();Q.pop();
            for(i=0;i<6;i++)
            {
                x=a+R1[i];y=b+R2[i];z=c+R3[i];
                 if(x<0)
                 x=25;
                 if(y<0)
                 y=25;
                 if(z<0)
                 z=25;
                 if(x>25)
                    x=0;
                 if(y>25)
                    y=0;
                 if(z>25)
                    z=0;
                if(vis[x][y][z]!=1&&dis[x][y][z]>dis[a][b][c]+1)
                {
                    dis[x][y][z]=dis[a][b][c]+1;
                    Q.push(x);Q.push(y);Q.push(z);
                }
            }
        }
        if(dis[en[0]-Ch][en[1]-Ch][en[2]-Ch]==N)
            printf("Case %d: -1\n",r);
        else
            printf("Case %d: %d\n",r,dis[en[0]-Ch][en[1]-Ch][en[2]-Ch]);
    }
    return 0;
}

