//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int main()
{
   int i,c,j,k,t,r,a,b,d,e,f,s,aa[5],ar[20];
   char st[2000];
   scanf("%d",&t);
   for(r=1;r<=t;r++)
   {
       scanf("%s",&st);
       a=strlen(st);
       s=c=0;memset(ar,0,sizeof(ar));
       for(i=0;i<a;i++)
        {
            b=st[i]-'0';
            b=(b%3==0)?3:b%3;
            s+=b;
            ar[b]++;
        }
     if(a==1)
        k=1;
       else
       {
           k=0;
           while(s>0)
           {
               b=s%3;
               aa[0]=b;
               if(b==0)
               aa[0]=3;
              for(i=0;i<1;i++)
              {
                  if(ar[aa[i]]>0)
                  {
                      s=s-aa[i];
                      ar[aa[i]]--;
                      break;
                  }
              }
              if(i==1)
                break;
               k++;
           }
       }
       pf("Case %d: ",r);
       if(k%2==1)
        pf("S\n");
       else
        pf("T\n");
   }
    return 0;
}

