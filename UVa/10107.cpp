 #include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,m=0,n,ar[100000];
    while(scanf("%d",&n)!=EOF)
    {
        ar[m]=n;
        j=m+1;
         sort(ar,ar+j);

         i=(m+1)/2;
        if((m+1)%2==0)
        {

            k=(ar[i]+ar[i-1])/2;
        }
        else
            k=ar[i];
            printf("%d\n",k);
        m++;
    }
    return 0;
}
