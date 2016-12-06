#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct T{
  int a;
  char st[30];
}ar[200];
bool cmp(T x,T y)
{
    return x.a<y.a;
}
int main()
{
    int i,j,k,l,m,n,t,r;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
              scanf("%s %d %d %d",&ar[i].st,&k,&m,&l);
              ar[i].a=k*m*l;
        }
          sort(ar,ar+n,cmp);
         if(ar[0].a<ar[n-1].a)
        printf("Case %d: %s took chocolate from %s\n",r,ar[n-1].st,ar[0].st);
        else
            printf("Case %d: no thief\n",r);
    }
    return 0;
}
