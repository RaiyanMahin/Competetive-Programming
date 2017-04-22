
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
int text[200016];
const int maxlen = 200015;
const int alphabet = 200012;
struct TT{
int p,indx;
}arr[maxlen];
bool cmp(TT x,TT y)
{
    if(x.p==y.p)
        return x.indx<y.indx;
        return x.p<y.p;
}
int Rank[20][maxlen],LCP[maxlen],step;
  int pn[maxlen], cn[maxlen],p[maxlen], cnt[maxlen];
void build_suffix_array(int len,int stp)
{
    int n;
    n=len+1;
    memset (cnt, 0, alphabet * sizeof(int));
    for (int i=0; i<n; ++i)
        ++cnt[text[i]];
    for (int i=0; i<alphabet; ++i)
        cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i)
        p[--cnt[text[i]]] = i;
    Rank[0][p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (text[p[i]] != text[p[i-1]])  ++classes;
        Rank[0][p[i]] = classes-1;
    }
    for(int i=0;i<n;i++)
    {
        arr[i].p=Rank[0][i],arr[i].indx=i;
    }
    step=1;

    for (int h=0; (1<<h)<stp; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        memset (cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[Rank[h][pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[Rank[h][pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (Rank[h][p[i]] != Rank[h][p[i-1]] || Rank[h][mid1] != Rank[h][mid2])
                ++classes;
            cn[p[i]] = classes-1;
        }
       for(int i=0;i<n;i++)
        Rank[h+1][i]=cn[i],arr[i].p=cn[i],arr[i].indx=i;
        step=h+2;
    }
    sort(arr,arr+n,cmp);
    for(int i=1;i<n;i++) arr[i-1]=arr[i];
}
void build_LCP_array(int len)
{
    LCP[0] = 0;
    int n = len, i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i-1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        for(j = step-1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]!=-1)
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
       // cout << arr[i-1] << ' ' << arr[i] << ' ' << LCP[i] << endl;
    }
}
int vis[200005],viss[200005];
int main()
{
    int i,j,t,l,m,n,cs=1,u,f,a,s;

    //freopen("in.txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        memset(Rank,-1,sizeof(Rank));
        sn("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            sn("%d",&text[i]);
            //text[i]++;
        }
        text[n]=0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++)
        {
            sn("%d",&u);
            vis[u]++;
        }
        if(m>n)
        {
            pf("Case %d: 0\n",cs++);
            continue;
        }
        build_suffix_array(n,n+1);
        build_LCP_array(n);
        memset(viss,0,sizeof(viss));
        memset(cnt,0,sizeof(cnt));
        f=1;a=0;s=0;
        for(i=0;i<n;i++)
        {
            if(vis[text[i]]==0)
            {
                while(s<i)
                {
                    cnt[text[s]]--;
                    s++;
                }
                s=i+1;
            }
            else
            {
                if(cnt[text[i]]==vis[text[i]])
                {
                    while(s<i&&cnt[text[i]]==vis[text[i]])
                    {
                        cnt[text[s]]--;
                        s++;
                    }

                }
                cnt[text[i]]++;
            }
            if(i-s+1==m)
            {
               // pf("%d\n",s);
                viss[s]=1;
                cnt[text[s]]--;
                s++;
            }
        }
        int ans=0;
        u=m;
        //for(i=0;i<n;i++)
          //  pf("%d\n",LCP[i]);
        for(i=0;i<n;i++)
        {
            if(u<m)
                break;
            if(ans)
            {
                u=min(LCP[i],u);
            }
            if(viss[arr[i].indx]==1)
            {
                if(ans==0)
                  ans=arr[i].indx+1;
                else if(u>=m)
                {
                    ans=min(ans,arr[i].indx+1);
                }
            }

        }
        pf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}


