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
char st[205][205];
int R[]={1,-1,0,0},C[]={0,0,1,-1},dis[205][205],diss[205][205];
queue<int>Q;
struct T{
int x,y;
}ar[40005];
int main()
{
    int i,j,k,mn,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v,x1,y1,x2,y2,x,y;
   // freopen("Input.txt","r",stdin);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        for(i=0,c=0;i<n;i++)
        {
            scanf("%s",&st[i]);
            for(j=0;j<m;j++)
            {
                if(st[i][j]=='*')
                {
                    ar[c].x=i;ar[c].y=j;c++;
                }
                dis[i][j]=N;diss[i][j]=N;
                if(st[i][j]=='P')x1=i,y1=j;
                if(st[i][j]=='D')x2=i,y2=j;
            }
        }
        int mx=0;
        Q.push(x1);
        Q.push(y1);dis[x1][y1]=0;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            v=Q.front();Q.pop();
            if(st[u][v]!='*')
            for(i=0;i<4;i++)
            {
                a=u+R[i];b=v+C[i];
                if(a>=0&&b>=0&&a<n&&b<m&&st[a][b]!='#'&&dis[a][b]>dis[u][v]+1)
                {
                    dis[a][b]=dis[u][v]+1;
                    Q.push(a);Q.push(b);
                }
            }
        }
         Q.push(x2);
        Q.push(y2);diss[x2][y2]=0;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            v=Q.front();Q.pop();
            if(st[u][v]!='*')
            for(i=0;i<4;i++)
            {
                a=u+R[i];b=v+C[i];
                if(a>=0&&b>=0&&a<n&&b<m&&st[a][b]!='#'&&diss[a][b]>diss[u][v]+1)
                {
                    diss[a][b]=diss[u][v]+1;
                    Q.push(a);Q.push(b);
                }
            }
        }
        a=b=f=g=u=v=-1;
        int xx=N,yy=N,xx1=N,yy1=N,xx2=N,yy2=N;
        mx=dis[x2][y2];
        for(i=0;i<c&&c>1;i++)
        {
            if(dis[ar[i].x][ar[i].y]<=xx)
            {
                xx2=xx1;u=f;
                xx1=xx;f=a;
                xx=dis[ar[i].x][ar[i].y];a=i;
            }
            if(diss[ar[i].x][ar[i].y]<=yy)
            {
                yy2=yy1;v=g;
                yy1=yy;g=b;
                yy=diss[ar[i].x][ar[i].y];b=i;
            }
        }
        xx++;xx1++;xx2++;
        if(a==b&&xx!=xx1&&yy!=yy1)
            xx+=1;
        if(a>=0&&b>=0&&xx+yy<mx)
            mx=xx+yy;
        if(f>=0&&g>=0&&xx1+yy1<mx)
            mx=xx1+yy1;
//        if(u>=0&&v>=0&&xx2+yy2<mx)
//            mx=xx2+yy2;
        printf("Case %d: ",r);
       if(mx>=N)printf("impossible\n");
        else
        printf("%d\n",mx);
       // pf("%d\n",mx);

    }
    return 0;
}
/*
4 4
*##D
#.*.
P.#.
####
*/
