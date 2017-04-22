//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <iostream>
#include<queue>
#include<set>
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
int vis[128][1025]={0};

void precal()
{
    int i,mask,k,j,l,a,b,c,d;
    int viss[11];
    for(i=1;i<=100;i++)
    {
         if(i<10)
         {
             vis[i][1<<i]=1;
         }
         else if(i<100)
         {
             a=i%10;b=i/10;
             if(a!=b)
             vis[i][(1<<a)|(1<<b)]=1;
         }
         for(j=1;j<=i;j++)
         {
             memset(viss,0,sizeof(viss));
             a=j;b=i-j;mask=0;l=0;
             if(a<10)
             {
                 mask|=(1<<a);
                 viss[a]++;
                 if(viss[a]>1)l=1;
             }
             else
             {
                 c=a%10;d=a/10;
                 mask|=(1<<c);
                  viss[c]++;
                 if(viss[c]>1)l=1;
                 mask|=(1<<d);
                 viss[d]++;
                 if(viss[d]>1)l=1;
             }
             if(b<10)
             {
                 mask|=(1<<b);
                 viss[b]++;
                 if(viss[b]>1)l=1;
             }
             else
             {
                 c=b%10;d=b/10;
                 mask|=(1<<c);
                 viss[c]++;
                 if(viss[c]>1)l=1;
                 mask|=(1<<d);
                 viss[d]++;
                 if(viss[d]>1)l=1;
             }
             if(!l)
                vis[i][mask]=1;
         }
    }
    for(i=1;i<=100;i++)
    {
        for(j=0;j<(1<<10);j++)
        {
            for(k=j;k;k=k&(k-1))
            {
               vis[i][j]|=vis[i][j&(k-1)];
            }
        }
    }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    memset(vis,0,sizeof(vis));
    precal();
   while(sn("%d",&n)==1&&n)
   {
       int ar[11];
       for(i=0;i<n;i++)
       {
           sn("%d",&ar[i]);
       }
       int ret=(1<<10)-1;
       for(i=0;i<(1<<10);i++)
       {
           if(__builtin_popcount(i)>=__builtin_popcount(ret))
            continue;
            t=1;
           for(j=0;j<n;j++)
           {
               t=t&vis[ar[j]][i];
           }
           if(t)
            ret=i;
       }
       pf("Case %d: ",cs++);
       for(i=9;i>=0;i--)
       {
           if(ret&(1<<i))
            pf("%d",i);
       }
       pf("\n");
   }
    return 0;

}


/*#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int able[128][1024];
void build() {
	int d1, d2, d3, d4;
	for(int i = 1; i <= 100; i++) {
		if(i < 100) {
			if(i < 10) {
				d1 = i;
				able[i][1<<d1] = 1;
			} else {
				d1 = i%10, d2 = i/10;
				if(d1 != d2)
					able[i][(1<<d1)|(1<<d2)] = 1;
			}
		}
		for(int j = 1; j < i; j++) {
			int a = j, b = i - j, mask = 0;
			if(a < 10) {
				mask |= 1<<a;
			} else {
				d1 = a%10, d2 = a/10;
				if(d1 == d2)
					continue;
				mask |= (1<<d1)|(1<<d2);
			}
			if(b < 10) {
				if(mask&(1<<b))
					continue;
				mask |= 1<<b;
			} else {
				d1 = b%10, d2 = b/10;
				if(d1 == d2)
					continue;
				if(mask&((1<<d1)|(1<<d2)))
					continue;
				mask |= (1<<d1)|(1<<d2);
			}
			able[i][mask] = 1;
		}
	}
	for(int i = 0; i < 128; i++) {
		for(int j = 0; j < 1024; j++) {
			for(int k = j; k; k = k&(k-1))
				able[i][j] |= able[i][j&(k-1)];
		}
	}
}
int main() {
	build();
//	freopen("in.txt", "r+t", stdin);
//	freopen("out.txt", "w+t", stdout);
	int n, A[10], cases = 0;
	while(scanf("%d", &n) == 1 && n) {
		//map<int, int> R;
		for(int i = 0; i < n; i++)
			scanf("%d", &A[i]);

		int ret = (1<<10)-1;
		for(int i = 0; i < (1<<10); i++) {
			if(__builtin_popcount(i) >= __builtin_popcount(ret))
				continue;
			int f = 1;
			for(int j = 0; j < n && f; j++)
				f &= able[A[j]][i];
			if(f) {
				ret = i;
			}
		}
		printf("Case %d: ", ++cases);
		for(int i = 9; i >= 0; i--) {
			if((ret>>i)&1)
				printf("%d", i);
		}
		puts("");
	}
	return 0;
}
*/
