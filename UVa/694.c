#include<stdio.h>
 int recur(long long int n,long long int l,int j )
 {
   if(n==1)
        return j;
     if(n%2==0)
        n=n/2;
     else
        n=(3*n)+1;
    if(n>l)
        return j;

     recur(n,l,j=j+1);
 }
int main()
{
    long long int n,m,l,f;
    int i=1,j,k;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {

         if(n<0||l<0)
            break;

            j=recur(n,m,1);

        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",i,n,m,j);
        i++;
    }
    return 0;
}

