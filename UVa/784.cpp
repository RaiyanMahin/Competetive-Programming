//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

char st[1002][1002];

void dfs(int x,int y,int n)
{
    st[x][y]='#';
    int i,v,xx,yy,C[]={0,0,-1,1,-1,-1,1,1},R[]={1,-1,0,0,-1,1,-1,-1};
    for(i=0;i<8;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
         if(xx>=0&&yy>=0&&xx<n&&yy<strlen(st[xx])&&st[xx][yy]==' ')
         {
             dfs(xx,yy,n);
         }
    }
}

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h;
    scanf("%d",&t);getchar();
    while(t--)
    {
        for(n=0;;)
        {
           gets(st[n]);
            n++;
            if(st[n-1][0]=='_')
                break;
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<strlen(st[i]);j++)
            {
                if(st[i][j]=='*')
                {
                    dfs(i,j,n);
                }
            }

        }
        for(i=0;i<n;i++)
            puts(st[i]);

    }
    return 0;
}




