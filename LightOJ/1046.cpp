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
struct T{
int a,x,y;
}temp;
queue<int>Q;
vector<T>ar;
int dis[30][30];
int R[]={1,1,2,2,-1,-1,-2,-2},C[]={2,-2,1,-1,2,-2,1,-1};

void F()
{
    return;
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v,x,y,z,mn;
    char st[50];
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
           for(i=0;i<n;i++)
            {
                scanf("%s",&st);
                for(j=0;j<m;j++)
                {
                    if(st[j]!='.')
                    {
                        temp.x=i;temp.y=j;temp.a=st[j]-'0';
                        ar.push_back(temp);
                    }
                }
            }
        mn=N;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                for(c=0;c<=n;c++)
                  for(d=0;d<=m;d++)
                    dis[c][d]=N;
                Q.push(i);Q.push(j);dis[i][j]=0;
                while(!Q.empty())
                {
                    a=Q.front();Q.pop();
                    b=Q.front();Q.pop();
                    for(k=0;k<8;k++)
                    {
                        x=a+R[k];y=b+C[k];

                        if(x>=0&&y>=0&&x<n&&y<m&&dis[x][y]>dis[a][b]+1)
                        {
                            dis[x][y]=dis[a][b]+1;
                            Q.push(x);Q.push(y);
                        }
                    }
                }

                s=0;
                for(k=0,f=ar.size();k<f;k++)
                {
                    x=ar[k].x;y=ar[k].y;a=ar[k].a;
                    if(dis[x][y]==N)
                    {
                        s=-1;break;
                    }
                    else
                    {
                        s=s+(dis[x][y]/a);
                        if(dis[x][y]%a>0)
                            ++s;
                    }
                }
                if(s>=0&&s<mn)
                    mn=s;
            }
        }
        if(mn==N)
            printf("Case %d: -1\n",r);
        else
            printf("Case %d: %d\n",r,mn);
            ar.clear();
    }
    return 0;
}



