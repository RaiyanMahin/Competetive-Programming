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
struct T{
int w,q,p;

}ar[1005];
int lis[1008],P[1005],mx,mp;
int liss(int n)
{
    int i,j;
   for(i=0;i<n;i++)
   {
       for(j=i;j>=0;j--)
       {
          if(ar[i].w>ar[j].w&&ar[i].q<ar[j].q)
            {
                if(lis[i]<lis[j]+1)
                {
                    lis[i]=lis[j]+1;
                    P[i]=j;
                    if(lis[i]>mx)
                    {
                        mx=lis[i];mp=i;
                    }
                }
            }
       }
   }
}

void path(int p)
{
    if(P[p]==-1)
      {
          printf("%d\n",ar[p].p);
          return;
      }
    path(P[p]);
    printf("%d\n",ar[p].p);
}

bool cmp(T x,T y)
{
    if(x.w==y.w)
        return x.q>y.q;
    return x.w<y.w;
}

int main()
{
    int i=0,j,k,l,m,n,a,b,u;
    while(scanf("%d %d",&ar[i].w,&ar[i].q)!=EOF)
    {
        ar[i].p=i+1;
        i++;
    }

    n=i;
    sort(ar,ar+n,cmp);

    memset(lis,0,sizeof(lis));
    memset(P,-1,sizeof(P));
    mx=0;
    liss(n);
    printf("%d\n",mx+1);
    path(mp);
    return 0;
}
//7
//1 5 2 6 3 4 7



