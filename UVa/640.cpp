#include<stdio.h>
#include<string.h>
#define N 1000000
int ar[N];
int dn(int n)
{
    int s=0;
    while(n!=0)
    {
        s=s+n%10;
        n/=10;
    }
    return s;
}
int main()
{
    int i,j,k,m,n;
    memset(ar,-1,sizeof(ar));
    for(i=1;i<=N;i++)
    {
        n=i+dn(i);
        ar[n]=0;
        if(ar[i]==-1)
            printf("%d\n",i);
    }
    printf("1000000\n");
  return 0;
}
