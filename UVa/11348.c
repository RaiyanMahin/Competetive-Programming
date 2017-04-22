#include<stdio.h>
int main()
{
    int i,j,k,r,t,b,a,c,n,m[100][1002],ar[50060],s,ss[100],d[1001];
    double f;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {

        scanf("%d",&n);s=0;k=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&m[i][0]);
            ss[i]=0;
            for(j=1;j<=m[i][0];j++)
            {
                 scanf("%d",&m[i][j]);
                 ar[k]=m[i][j];
                 k++;
            }
        }
        d[0]=ar[0];a=0;
        for(i=0;i<k;i++)
        {
            b=0;
            for(j=0;j<=a;j++)
            {
                if(ar[i]==d[j])
                    b++;
            }
            if(b==0)
            {
                a=a+1;
                d[a]=ar[i];
            }
        }
        for(i=0;i<=a;i++)
            {
                b=0;
                for(j=0;j<n;j++)
              {
                    for(k=1;k<=m[j][0];k++)
                    {
                        if(d[i]==m[j][k])
                        {
                             b++;c=j;
                             break;
                        }
                    }
             }
             if(b==1)
                ss[c]+=1;
            }

         for(i=0;i<n;i++)
        {
            s=s+ss[i];
        }
        printf("Case %d:",r);
        for(i=0;i<n;i++)
        {
            f=(double)ss[i]/s;
            f=f*100.00;
           printf(" %.6f%%",f);
        }
        printf("\n");
    }
    return 0;
}


