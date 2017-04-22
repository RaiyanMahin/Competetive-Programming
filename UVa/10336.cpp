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

struct T{
char ln;
int rn;
}ar[50];

void dfs(int x,int y,int n,char ch)
{
    st[x][y]='0';
    int i,v,xx,yy,C[]={0,0,-1,1},R[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
         if(xx>=0&&yy>=0&&xx<n&&yy<strlen(st[xx])&&st[xx][yy]==ch)
         {
             dfs(xx,yy,n,ch);
         }
    }
}

bool cmp(T x,T y)
{
    if(x.rn==y.rn)
        return x.ln<y.ln;
    return x.rn>y.rn;
}

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h;
    char ch;
    scanf("%d",&t);getchar();
    while(t--)
    {
       scanf("%d %d",&n,&m);
       for(i=0;i<n;i++)
       {
           scanf("%s",&st[i]);
       }
       memset(ar,0,sizeof(ar));
       a=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<strlen(st[i]);j++)
            {
                if(st[i][j]!='0')
                {

                    ch=st[i][j];
                    ar[ch-'a'].ln=st[i][j];
                    ar[ch-'a'].rn++;
                    dfs(i,j,n,ch);
                }
            }

        }

        sort(ar,ar+50,cmp);
       i=0;
       printf("World #%d\n",r++);
       while(ar[i].rn!=0)
       {
           printf("%c: %d\n",ar[i].ln,ar[i].rn);
           i++;
       }


    }
    return 0;
}






