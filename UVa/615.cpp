//BISMILLAHIR RAHMANIR RAHIM
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

typedef long long int ll;
using namespace std;

vector<int>ar[1000000];
int vis[1000000];
map<int,int>viss;
void check(int n)
{

int i,v;
    for( i=0;i<ar[n].size();i++)
    {
        v=ar[n][i];
        vis[v]++;
      //  pf("%d %d\n",v,vis[v]);
        check(ar[n][i]);
    }
}
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h;
    int arr[100000];
    while(1)
    {
        memset(vis,0,sizeof(vis));
        j=0;c=0;d=0;
        while(scanf("%d %d",&a,&b)!=EOF)
        {
            if(a==0||b==0)
                break;
            if(a<0||b<0)
                return 0;
            if(a==b)
                c=3;
            vis[a]++;vis[b]++;
            if(vis[a]==1)
            {
                arr[j++]=a;
            }
            if(vis[b]==1)
            {
                arr[j++]=b;

            }
            viss[b]=1;
            ar[a].push_back(b);
        }
           memset(vis,0,sizeof(vis));
            for(i=0;i<j;i++)
            {
                if(viss[arr[i]]==0)
                    check(arr[i]);
            }
        for(i=0;i<j;i++)
        {
           // pf(" %d",vis[arr[i]]);
            if(vis[arr[i]]==0)
                c++;
            else if(vis[arr[i]]>1)
                d++;
        }
        if((c==1&&d==0)||(c==0&&d==0))
        {
            pf("Case %d is a tree.\n",r);
        }
        else
        {
            pf("Case %d is not a tree.\n",r);
        }
        r++;

    for(i=0;i<j;i++)
        ar[arr[i]].clear();
        viss.clear();
    }
    return 0;
}


