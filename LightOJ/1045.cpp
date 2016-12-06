  #include<stdio.h>
  #include<math.h>
  #define maxn 1000001
    double a[maxn];
    int main()
    {
        int i,t,n,m;
        double  ans;
        a[0]=0;
        for(i=1;i<=maxn;i++)
            a[i]=a[i-1]+log(i+0.0);
        scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
            scanf("%d%d",&m,&n);
            ans=floor((a[m]/log(n*1.0))+1);
            printf("Case %d: %.lf\n",i,ans);
        }
        return 0;
    }
