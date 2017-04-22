
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
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
const int MAX =1000004;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
    bool operator<(const info &a)const
    {
        return tup[0] != a.tup[0]? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
}arr[MAX];
int Rank[19][MAX], LCP[MAX], step;
string text;
string st[105];
vector<int>ar[305];
int len[105],lenn[105],vis[1000005],viss[1000005],dp[1000005],cur[105];
void build_suffix_array(int m)
{
    int n = text.size(), jump;
    for(int j = 0; j < n; j++)
    {
        Rank[0][j] = text[j]; ///rank suffixes according to 1st char
        memset(arr[j].tup, 0,sizeof(arr[j].tup));
    }
    for(step = 1, jump = 1; jump <= m; step++, jump <<= 1)
    {
        for(int j = 0; j <=n; j++)
        {
            arr[j].indx = j;
            arr[j].tup[0] = Rank[step - 1][j]; /// what i was in prev step
            arr[j].tup[1] = j + jump <len[viss[j]]? Rank[step - 1][j + jump] : -1;
        }
        sort(arr, arr + n);
        Rank[step][arr[0].indx] = 0;
        for(int j = 1; j < n; j++)
            Rank[step][arr[j].indx] = arr[j].tup[0] == arr[j - 1].tup[0] &&
            arr[j].tup[1] == arr[j - 1].tup[1] ? Rank[step][arr[j - 1].indx] : j;
    }
//    cout << "Suffix Array : \n\n";
//    for(int i = 0; i < n; i++)
//        cout<<arr[i].indx<<' '<<text.substr(arr[i].indx)<<endl;
}

int Count_LCP(int id1,int id2,int n,int m)
{
    int  i, j,lc=0;
      n=n-id1;
      m=m-id2;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]!=-1)
            {
                lc += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        lc=min(n,lc);
        lc=min(m,lc);
      return lc;
}

int main()
{
    int i,j,n,m,k,a,c,b,s,h,g,e,f,cs=1,t,u,v;
 //    freopen("out.txt","w",stdout);
    while(sn("%d",&t)!=EOF&&t!=0)
    {
        if(cs>1)
            pf("\n");
        cs++;
        memset(Rank,-1,sizeof(Rank));
       // memset(vis,0,sizeof(vis));
        //memset(viss,0,sizeof(viss));
         m=0;text="";
        for(i=j=0;i<t;i++)
        {
            cin >> st[i];
            text=text+st[i];
            len[i]=st[i].size();m=max(m,len[i]);lenn[i]=len[i];
            if(i>0)
                len[i]+=len[i-1];
            cur[i]=0;
            for(;j<len[i];j++)
                viss[j]=i;
        }
        n=text.size();
        build_suffix_array(m);
        s=0;
        for(i=0;i<n;i++)
        {
            vis[i]=arr[n-i-1].indx;
        }
        for(i=0;i<n;i++)
        {
            arr[i].indx=vis[i];
        }
        for(i=0;i<n;i++)
        {
            u=arr[i].indx;s=0;
            for(j=0;j<t;j++)
            {
                s=len[j];
                if(u<s)
                {
                    ar[j].pb(i);
                    viss[u]=j;
                    break;
                }
            }
            dp[i]=-1;vis[i]=0;
        }
        s=0;
        e=(t/2)+1;
        vis[viss[arr[0].indx]]=1;s=1;
        for(i=0,j=0;i<n;i++)
        {
            for(;j<n;)
            {
                if(s>=e)
                {
                    dp[i]=j;
                    break;
                }
                j++;
                if(j<n&&vis[viss[arr[j].indx]]==0)
                {
                    vis[viss[arr[j].indx]]=1;s++;
                }
                else if(j<n)
                {
                    vis[viss[arr[j].indx]]++;
                }
            }
            if(vis[viss[arr[i].indx]]==1)
                 s--;
                vis[viss[arr[i].indx]]--;
        }
        s=0;
        for(i=0;i<n;i++)
        {
            h=100000;g=0;
            for(j=0;j<t;j++)
            {
                while(cur[j]<lenn[j]&&ar[j][cur[j]]<i)
                    cur[j]++;
                if(cur[j]<lenn[j]&&ar[j][cur[j]]<=dp[i])
                {
                    h=min(h,Count_LCP(arr[i].indx,arr[ar[j][cur[j]]].indx,len[viss[arr[i].indx]],len[viss[arr[ar[j][cur[j]]].indx]]));
                    g++;
                }
            }
            if(g==e)
            {
                dp[i]=h;
                s=max(h,s);
            }
        }
        if(s==0)
            pf("?\n");
        else
        {
            u=-1;
            for(i=n-1;i>=0;i--)
            {
                if(dp[i]==s)
                {
                    j=u;
                    if(u!=-1)
                    h=(Count_LCP(arr[i].indx,arr[j].indx,len[viss[arr[i].indx]],len[viss[arr[j].indx]]));
                    if((u!=-1&&h<s)||u==-1){
                    for(j=arr[i].indx;j<arr[i].indx+s;j++)
                        pf("%c",text[j]);
                    pf("\n");
                     u=i;
                    }
                }
            }
        }
        for(i=0;i<302;i++)ar[i].clear();
    }
    return 0;
}



