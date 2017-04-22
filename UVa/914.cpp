#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 1000000
int ar[n]={0};
int main()
{
    int i,t,d,m,r,j,q,k,kl,pr[80000],l,u,jm[1000];
    for(i=3;i<=sqrt(n)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=n;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }k=0;pr[0]=2;j=1;
    for(i=3;i<=n;i+=2)
        if(ar[i]==0)
    {
        pr[j++]=i;
    }
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&l,&u);
        i=0;j=0;q=0;
        if(u==1000000)
            u=999983;
       while(pr[i]<l)
        i++;
        while(pr[j]<u)
        j++;
      if(pr[j]>u)
        j=j-1;
      k=0;m=0;
      memset(jm,0,sizeof(jm));
      q=j-i;
      for(i=i+1;i<=j;i++)
      {
            d=abs(pr[i-1]-pr[i]);

            jm[d]++;
            if(jm[d]>k)
            {
                k=jm[d];
                m=d;
            }
      }

      kl=0;
      for(i=1;i<100;i++)
      {
          if(jm[i]==k)
            kl++;
      }
      if(q==1)
         printf("The jumping champion is %d\n",m);
     else if(jm[m]>1&&q>1&&kl==1)
           printf("The jumping champion is %d\n",m);
       else
         printf("No jumping champion\n");
    }
    return 0;
}

