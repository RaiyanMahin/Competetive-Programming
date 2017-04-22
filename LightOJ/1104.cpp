
//BISMILLAHIR RAHMANIR RAHIM
//#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
double eps=1e-9;
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a=1;double p=1.0;
         while(1)
         {
             p*=(1.0-(double)a/(double)n);
             if(p-0.5<=eps)
             {
                 break;
             }
             a++;
         }
         printf("Case %d: %d\n",r++,a);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);

  using namespace std;

  int main() { _

    return 0;
  }
*/

