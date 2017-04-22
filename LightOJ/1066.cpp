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

struct TT{
int x,y;
}temp;
queue<int>Q;
TT ar[200];
char st[20][20];
int dis[20][20],R[]={1,-1,0,0},C[]={0,0,1,-1};



int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,xx,yy,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);k=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",&st[i]);
            for(j=0;j<n;j++)
            {
                if(st[i][j]>='A'&&st[i][j]<='Z')
                {
                    temp.x=i;temp.y=j;
                    ar[st[i][j]-'A']=temp;
                    k++;
                }
            }
        }
        s=0;
        for(i=0;i<k-1;i++)
        {
            temp=ar[i];
            st[temp.x][temp.y]='.';
            temp=ar[i+1];
            st[temp.x][temp.y]='.';
            for(a=0;a<n;a++)
            {
                for(b=0;b<n;b++)
                {
                    dis[a][b]=N;
                }
            }
            temp=ar[i];
            Q.push(temp.x);Q.push(temp.y);
            dis[temp.x][temp.y]=0;

            while(!Q.empty())
            {
                u=Q.front();Q.pop();
                v=Q.front();Q.pop();
                for(j=0;j<4;j++)
                {
                    xx=u+R[j];
                    yy=v+C[j];
                    if(xx>=0&&yy>=0&&xx<n&&yy<n&&st[xx][yy]=='.'&&dis[xx][yy]>dis[u][v]+1)
                    {
                        dis[xx][yy]=dis[u][v]+1;
                        Q.push(xx);Q.push(yy);
                    }
                }
            }

            temp=ar[i+1];

            if(dis[temp.x][temp.y]==N)
                break;
            s+=dis[temp.x][temp.y];
        }
        printf("Case %d: ",r);
        if(i==k-1)
            printf("%d\n",s);
        else
            printf("Impossible\n");
    }
    return 0;
}

