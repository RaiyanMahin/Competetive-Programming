#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;


int main()
{
    int k,r=1,i,m,h,l,n,ar[10009],q,a[10009];
    int arr[10009]={0};
    for(;;)
    {
        scanf("%d %d",&n,&q);
        if(n==0&&q==0)
            break;
      for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
      for(i=0;i<q;i++)
        scanf("%d",&a[i]);
        sort(ar,ar+n);
        printf("CASE# %d:\n",r);
        memset(arr,0,sizeof(arr));
      for(i=0;i<n;i++)
      {
         if(arr[ar[i]]==0)
         arr[ar[i]]=i+1;
      }
      for(i=0;i<q;i++)
      {
          if(arr[a[i]]==0)
            printf("%d not found\n",a[i]);
          else
            printf("%d found at %d\n",a[i],arr[a[i]]);
      }
       r++;
    }
    return 0;
}

