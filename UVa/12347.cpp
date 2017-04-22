//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int ar[100000];
map<int,int>Br;


 void Postorder(int n)
 {
     if(Br[n-1]>0)
     {

         Postorder(2*n);
         Postorder(2*n+1);
         printf("%d\n",Br[n-1]);
     }
 }


void Binarytree(int n,int k,int m)
{
    if(k>=m)
        return;
    if(Br[n-1]==0)
    {
        Br[n-1]=ar[k];
    }
    else
    {
       if(ar[k]>Br[n-1])
       {
           Binarytree(2*n+1,k,m);
       }
       else
       {
           Binarytree(2*n,k,m);
       }
       if(n==1)
       Binarytree(n,k+1,m);
    }

}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,u,v;

         memset(ar,-1,sizeof(ar));
       //  memset(Br,-1,sizeof(Br));
       i=0;
       while(scanf("%d",&ar[i])==1)
         {
             i++;
         }
         Br[0]=ar[0];n=i;
         Binarytree(1,1,n);
//         for(i=0;i<n*2+2;i++)
//            pf(" %d",Br[i]);
//         pf("\n");
         Postorder(1);
        // pf("\n");

    return 0;
}



