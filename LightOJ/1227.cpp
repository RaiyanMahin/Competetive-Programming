#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,t,k,r,j,n,p,q,ar[1000];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(ar,ar+n);j=0;
        for(i=0,k=0;i<n;i++)
        {
            j=j+ar[i];
            if(j<=q)
            k++;
        }
        if(k>p)
            k=p;
        printf("Case %d: %d\n",r,k);
    }
    return 0;
}
