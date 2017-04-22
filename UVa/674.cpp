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
int ar[10000];
int main()
{
    int i,j,k,l,m,n,a,b,c,d,e,f,g,h,aa[10];

           memset(ar,0,sizeof(ar));
            aa[0]=1;aa[1]=5;aa[2]=10;aa[3]=25;aa[4]=50;
            for(i=0;i<5;i++)
            {
                ar[0]=1;
                for(j=0;j<8000;j++)
                {
                    if(ar[j]!=0&&j+aa[i]<=8000)
                    {
                        ar[j+aa[i]]+=ar[j];
                    }
                    if(j+aa[i]>8000)
                        break;
                }
            }
        while(scanf("%d",&n)!=EOF)
        {
            ar[0]=0;
            printf("%d\n",ar[n]);
        }
    return 0;
}

