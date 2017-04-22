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
int cnt=0,ar[10][10],u,aa[10],arr[100][100];
int C[]={-1,0,-1,-1},R[]={0,-1,-1,1};
void check(int x,int y,int r,int m)
{
    u=(u<ar[x][y])?ar[x][y]:u;
    int xx,yy;
    xx=x+C[r];
   yy=y+R[r];
   if(xx>=m||yy>=m||xx<0||yy<0)
    return;
   else
    {
        check(xx,yy,r,m);
    }

}
void way(int r,int m)
{
    if(r>=m)
    {
        for(int k=0;k<m;k++)
           arr[cnt][k]=aa[k];
        cnt++;
    }
  for(int i=0;i<m;i++)
  {
      u=0;
      for(int j=0;j<4;j++)
        if(u==0)
            check(r,i,j,m);
      if(u==0)
      {
          aa[r]=i;
          ar[r][i]=1;
          way(r+1,m);
          ar[r][i]=0;
      }
  }
}
int main()
{
    int i,j,k,l,M[9],t,r=1,s,m,n,Q[9],a,b,c,d,e,f,g,h,u,v;
    memset(ar,0,sizeof(ar));
    way(0,8);
    while(scanf("%d %d %d %d %d %d %d %d",&Q[0],&Q[1],&Q[2],&Q[3],&Q[4],&Q[5],&Q[6],&Q[7])!=EOF)
    {
        m=10000;

        for(i=0;i<cnt;i++)
        {
            a=8;
            for(j=0;j<8;j++)
            {

                  if(Q[j]==arr[i][j]+1)
                    a--;
            }
            if(a<m)
                m=a;
 //           printf("  %d\n",a);
        }
            printf("Case %d: %d\n",r,m);
            r++;
    }
    return 0;
}


