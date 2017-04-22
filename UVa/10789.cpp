#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define N 10000
using namespace std;


int main()
{
   long i,j,a,b,t,freq[150]={0},f=0,c=0,p=0;
    char str[2020];
    scanf("%ld",&t);
    while(t>0)
  {
     p=0;
     f=0;
    long freq[150]={0};
    scanf("%s",&str);
    for(i=0;i<strlen(str);i++)
    {
        freq[str[i]]++;
    }
     c++;
      printf("Case %ld: ",c);
    for(j=48;j<=122;j++)
    {
        if(freq[j]!=0)
      {
        for(i=2;i<=sqrt(freq[j]);i++)
        {
            f=0;
          if(freq[j]%i==0)
            break;
          else
            f=1;
        }
        if(freq[j]==2||f==1||freq[j]==3)
        {
            printf("%c",j);
            p=1;
        }
      }

    }
    if(p==0)
      printf("empty");
    t--;
      printf("\n");
    }
return 0;
}
