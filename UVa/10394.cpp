
//BISMILLAHHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 1000006

int  ar[N]={0},sm[N];

int  sum(int n)
{
   int s=0;
   while(n!=0)
   {
       s+=n%10;n/=10;
   }
   return s;

}
int main()
{
    int i,j,t,r,k,n,m;
    ar[0]=1;ar[1]=1;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                ar[j]=1;
        }

    }
     j=0;
     ar[0]=1;ar[1]=1;
    for(i=0;i<=1000000;i++)
         {
             if(ar[i]==0&&(i%2==1||i==2))
             {
                 k=sum(i);
                 if(ar[k]==0&&(k%2==1||k==2))
                 {
                     sm[i]=j+1;j++;
                 }
                 else
                    sm[i]=j;
             }
             else
                sm[i]=j;
         }
        scanf("%d",&t);

     for(r=1;r<=t;r++)
     {
         j=0;
         scanf("%d %d",&n,&m);

             if(ar[n]==0&&(n%2==1||n==2))
             {
                 k=sum(n);
                 if(ar[k]==0&&(k%2==1||k==2))
                 {
                    j++;
                 }
             }

            j+=abs(sm[m]-sm[n]);

         printf("%d\n",j);
     }
    return 0;
}

