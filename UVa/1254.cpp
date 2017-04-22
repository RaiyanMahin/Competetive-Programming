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
const int MAX =200004;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
    bool operator<(const info &a)const
    {
        return tup[0] != a.tup[0]? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
}arr[MAX];
int Rank[18][MAX], LCP[MAX], step;
string text;

void build_suffix_array(void)
{
    int n = text.size(), jump,m;
    for(int j = 0; j < n; j++)
    {
        Rank[0][j] = text[j]; ///rank suffixes according to 1st char
        memset(arr[j].tup, 0,sizeof(arr[j].tup));
    }
    for(step = 1, jump = 1; jump <=n/2; step++, jump <<= 1)
    {
        for(int j = 0; j <=n; j++)
        {
            arr[j].indx = j;
            arr[j].tup[0] = Rank[step - 1][j]; /// what i was in prev step
           arr[j].tup[1] = j + jump < n? Rank[step - 1][j + jump] :-1;
        }
        sort(arr, arr + n);
        Rank[step][arr[0].indx] = 0;
        for(int j = 1; j < n; j++)
            Rank[step][arr[j].indx] = arr[j].tup[0] == arr[j - 1].tup[0] &&
            arr[j].tup[1] == arr[j - 1].tup[1] ? Rank[step][arr[j - 1].indx] : j;
    }

}
struct TT
{
    string st;
    int pos;
}ar[20005];
bool cmp(TT x,TT y)
{
    if(x.st.size()<y.st.size())
    {
        return true;
    }
    else if(x.st.size()==y.st.size())
    {
        if(x.st==y.st)
            return x.pos < y.pos;
        return x.st<y.st;
    }
    else
        return false;
}
int poss[20005],len[20005],vis[200005],ser[200005];
vector<int>ary;
vector<int>tr[1000000];
void build(int p,int l,int r)
{
    if(l==r)
    {
        if(vis[ser[l]]!=-1)
        {
            tr[p].pb(vis[ser[l]]);
        }
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    int a=0,b=0;
    vector<int>temp;
    for(int i=0;i<tr[2*p].size();i++)
    {
        tr[p].pb(tr[2*p][i]);
    }
    for(int i=0;i<tr[2*p+1].size();i++)
    {
        tr[p].pb(tr[2*p+1][i]);
    }
    sort(tr[p].begin(),tr[p].end());
    for(int i=0;i<tr[p].size()&&temp.size()<10;i++)
    {
        if(i==0)
            temp.pb(tr[p][i]);
        else if(tr[p][i]!=tr[p][i-1])
            temp.pb(tr[p][i]);
    }
    tr[p]=temp;
}
vector<int>ans;
string ss;
void query(int p,int l,int r,int x,int y)
{
    if(r<x||l>y)
    {
        return;
    }
    if(l>=x&&r<=y)
    {
        for(int i=0;i<tr[p].size();i++)
        {
            ans.pb(tr[p][i]);
        }
        return;
    }
    int mid=(l+r)/2;
    query(2*p,l,mid,x,y);
    query(2*p+1,mid+1,r,x,y);
}

int check(int p,int n)
{
    int i,j,l=ss.size();
    p=ser[p];
    for(i=0;i<n&&i<l;i++)
    {
        if(ss[i]<text[p+i])
            return -1;
        else if(ss[i]>text[p+i])
            return 1;
    }
    if(l==i)
       return 0;
    return 1;
}
int main()
{
    int i,j,k,a,b,c,d,n,m,cs=1,t,u,v,l;
    sn("%d",&n);
    text="";
    for(i=0;i<n;i++)
    {
        cin >> ar[i].st;
        ar[i].pos=i+1;
    }
    sort(ar,ar+n,cmp);
    a=0;
    memset(vis,-1,sizeof(vis));
    for(i=0;i<n;i++)
    {
        poss[i]=ar[i].pos;
        text=text+ar[i].st+'#';
        len[i]=ar[i].st.size();
        for(j=a;j<a+len[i];j++)
        {
            vis[j]=i;
        }
        a+=len[i]+1;
    }
    build_suffix_array();
    l=text.size();
    for(i=0;i<l;i++)
    {
        ser[i]=arr[i].indx;
    }
    build(1,0,l-1);
    sn("%d",&m);

    while(m--)
    {
        cin >> ss;
        int lw=0,hi=l-1,mid;
        while(lw<=hi)
        {
            mid=(lw+hi)/2;
            c=check(mid,l);
            if(c==0)
            {
                if(mid-1>=0&&check(mid-1,l)==0)
                    hi=mid-1;
                else
                break;
            }
            else if(c==1)
            {
                lw=mid+1;
            }
            else hi=mid-1;
        }
        if(lw<=hi)
        {
            a=mid;
            lw=0;hi=l-1;
            while(lw<=hi)
            {
                mid=(lw+hi)/2;
                c=check(mid,l);
                if(c==0)
                {
                    if(mid+1<l&&check(mid+1,l)==0)
                        lw=mid+1;
                    else
                    break;
                }
                else if(c==1)
                {
                    lw=mid+1;
                }
                else hi=mid-1;
            }
            if(lw<=hi)
            {
                ans.clear();
                query(1,0,l-1,a,mid);
                sort(ans.begin(),ans.end());
                for(i=c=0;i<ans.size()&&c<10;i++)
                {
                    if(i==0)
                    {
                        pf("%d",poss[ans[i]]);
                        c++;
                    }
                    else if(i!=0&&ans[i-1]!=ans[i])
                    {
                        pf(" %d",poss[ans[i]]);c++;
                    }

                }
                pf("\n");
            }
            else
            {
                pf("-1\n");
            }
        }
        else
        {
            pf("-1\n");
        }
    }
    return 0;
}


