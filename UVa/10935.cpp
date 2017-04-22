//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
int ar[500009];
int main()
{
    int i,j,k,l,n,m,r[100000];

    while(scanf("%d",&n)!=EOF)
    {
        memset(ar,-1,sizeof(ar));
        if(n==0)
            break;
        for(i=1;i<=n;i++)
            ar[i]=i;
            m=n;k=0;

    printf("Discarded cards:");
      for(i=1,j=1;;i++)
      {
          if(ar[i+1]==-1)
            break;
          if(i%2==1)
          {
              if(i!=1)
                printf(",");
              printf(" %d",ar[i]);
          }
          else
          {
              ar[n+j]=ar[i];j++;
          }
      }
        printf("\nRemaining card: %d\n",ar[i]);
    }
return 0;
}


