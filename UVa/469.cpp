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
int vis[105][105],a;
int ar[100000],aa[100000];
char st[105][105];
void dfs(int x,int y,int n,int m)
{
    vis[x][y]=1;
    int xx,yy,i,R[]={0,0,1,-1,-1,-1,1,1},C[]={1,-1,0,0,-1,1,-1,1};
    for(i=0;i<8;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]=='W'&&vis[xx][yy]==0)
        {
             a++;
            dfs(xx,yy,n,m);
        }
    }
   // return p;
}
int main()
{
    int i,j,k,l,t,r,s,m,n,b,c,d,e,f,g,h;
      char ch[10];
    scanf("%d",&t);
   scanf("\n");
    for(r=1;r<=t;r++)
    {
        n=0; k=0;
         while(gets(st[n])&&st[n][0]){
            if(st[n][0]!='L'&&st[n][0]!='W')
            {
                strcpy(ch,st[n]);
                i=0;ar[k]=0;
             for(i=0;;i++)
              {
                  if(ch[i]==' ')break;
                  ar[k]=ar[k]*10+(ch[i]-'0');
              }
              aa[k]=0;
              for(++i;i<strlen(ch);i++)
              {
                  aa[k]=aa[k]*10+(ch[i]-'0');
              }

                k++;
            }

            //if(k==0)
            n++;
        }
        m=strlen(st[0]);

        for(i=0;i<k;i++)
        {
            a=0;memset(vis,0,sizeof(vis));
               if(st[ar[i]-1][aa[i]-1]=='W')
                dfs(ar[i]-1,aa[i]-1,n-k,m),a++;
            printf("%d\n",a);
        }


         if(r!=t)
            printf("\n");
    }
    return 0;
}


