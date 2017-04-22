//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(a%b==0)
        return b;
    else
        gcd(b,a%b);
}
int main()
{
    long long int t,r,i,j,k,m,n,ar[300];
    char ch[10000],*c;
    scanf("%lld",&t);getchar();
    for(r=1;r<=t;r++)
    {
        gets(ch);k=0;
        c=strtok(ch," \n.,;:()[]{}!@#$%^&*+_-|\\?<>//");
        while(c!=NULL)
        {
            ar[k]=atoll(c);
            k++;
            c=strtok(NULL," \n.,;:()[]{}!@#$%^&*+_-|\\?<>//");
        }
        m=0;
        sort(ar,ar+k);
        for(i=0;i<k-1;i++)
           {
               for(j=i+1;j<k;j++)
                 {
                      n=gcd(ar[i],ar[j]);
                      if(n>m)
                       m=n;
                 }
           }
           if(k!=0)
           printf("%lld\n",m);
           else
            r--;
    }
    return 0;
}
