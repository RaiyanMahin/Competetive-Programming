#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,j,k,l,m,p,a,b,c,n,ar[40][40],pr[50],t,r;
    char ch[40],cr[40];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d %d",&n,&m,&k);
        memset(pr,0,sizeof(pr));
        for(i=0;i<n;i++)
        {
           for(j=0;j<k;j++)
           {
                scanf("%d",&ar[i][j]);
           }
        }
       scanf("%d",&p);
       for(i=0;i<p;i++)
       {
           scanf("%d",&l);
           pr[l]=1;
       }

       c=1;
      for(i=0;i<n;i++)
      {
          a=0;
          for(j=0;j<k;j++)
          {
              b=ar[i][j];
              if(b>0)
              {
                  if(pr[b]!=0)
                    a++;
              }
              else if(b<0)
              {
                  b*=-1;
                  if(pr[b]==0)
                    a++;
              }
          }
          if(a==0)
          {
              c=0;break;
          }

      }

      if(c==0)
        printf("Case %d: No\n",r);
    else
        printf("Case %d: Yes\n",r);
    }
    return 0;
}
