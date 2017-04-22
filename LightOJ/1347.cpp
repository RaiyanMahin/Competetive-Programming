
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
const int MAX =15004;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
    bool operator<(const info &a)const
    {
        return tup[0] != a.tup[0]? tup[0] < a.tup[0] : tup[1] < a.tup[1];
    }
}arr[MAX];
int Rank[18][MAX], LCP[MAX], step,l1,l2,l3;
string text;
void build_suffix_array(void)
{
    int n = text.size(), jump;
    for(int j = 0; j < n; j++)
    {
        Rank[0][j] = text[j]; ///rank suffixes according to 1st char
        memset(arr[j].tup, 0,sizeof(arr[j].tup));
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(int j = 0; j <=n; j++)
        {
            arr[j].indx = j;
            arr[j].tup[0] = Rank[step - 1][j]; /// what i was in prev step
            arr[j].tup[1] = j + jump < n? Rank[step - 1][j + jump] : -1;
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
string st,ss,su;
vector<int>ar[10];
int main()
{
    int i,j,n,m,k,a,c,b,s,h,g,e,f,cs=1,t,u,v;
    sn("%d",&t);
    while(t--)
    {
       // memset(Rank,-1,sizeof(Rank));
        cin >> st;
        cin >> ss;
        cin >> su;
        l1=st.size();
        l2=ss.size();
        l3=su.size();
        text = st+ss+su;
        n=text.size();
        build_suffix_array();
        s=0;
        for(i=0;i<n;i++)
        {
            j=arr[i].indx;
            if(j<l1)
            {
                ar[0].pb(j);
                ar[3].pb(ar[1].size()-1);
                ar[4].pb(ar[2].size()-1);
            }
            else if(j<l1+l2)
            {
                ar[1].pb(j);
            }
            else if(j<l1+l2+l3)
            {
                ar[2].pb(j);
            }
        }
        s=0;
        for(i=j=k=0;i<l1;i++)
        {
            h=0;g=0;
            if(ar[3][i]>=0)
            {
                a=(Count_LCP(ar[0][i],ar[1][ar[3][i]],l1,l1+l2));
                h=max(a,h);
            }
            if(ar[3][i]+1<ar[1].size())
            {
                a=(Count_LCP(ar[0][i],ar[1][ar[3][i]+1],l1,l1+l2));
                h=max(a,h);
            }
            if(ar[4][i]>=0)
            {
                b=(Count_LCP(ar[0][i],ar[2][ar[4][i]],l1,l1+l2+l3));
                g=max(g,b);
            }
            if(ar[4][i]+1<ar[2].size())
            {
                b=(Count_LCP(ar[0][i],ar[2][ar[4][i]+1],l1,l1+l2+l3));
                g=max(g,b);
            }
            s=max(s,min(h,g));
        }
        pf("Case %d: %d\n",cs++,s);
        for(i=0;i<5;i++)ar[i].clear();
    }
    return 0;
}



