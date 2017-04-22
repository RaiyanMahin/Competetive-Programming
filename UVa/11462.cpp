#include<stdio.h>
#include<algorithm>
#define N 2000005
int ar[N];
using namespace std;
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(ar,ar+n);
        for(i=0;i<n;i++)
        {
            i&&printf(" ");
            printf("%d",ar[i]);
        }
        printf("\n");
    }
    return 0;
}
