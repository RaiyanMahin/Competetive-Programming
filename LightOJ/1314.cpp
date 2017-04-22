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
const int MAX =10004;
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
  //  cout << "Suffix Array : \n\n";
    //for(int i = 0; i < n; i++)
      //  cout<<arr[i].indx<<' '<<text.substr(arr[i].indx)<<endl;
}

void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]!=-1)
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
       // cout << arr[i - 1].indx << ' ' << arr[i].indx << ' ' << LCP[i] << endl;
    }
   // for(i = 0; i < n; i++)
     //   cout << i << ' ' << LCP[i] << endl;
}

int main()
{
    int i,j,k,a,b,t,cs=1,s,n;
    sn("%d",&t);
    while(t--)
    {
        cin >> text;
        memset(Rank,-1,sizeof(Rank));
        sn("%d %d",&a,&b);
        build_suffix_array();
        build_LCP_array();
        n=text.size();
        s=0;

        for(i=0;i<n;i++)
        {
            j=min(b,n-arr[i].indx);
            s=s+max(0,(j-max(a-1,LCP[i])));
//            for(k=arr[i].indx;k<n;k++)
//                pf("%c",text[k]);
//            pf(" %d %d %d\n",LCP[i],j,max(0,(j-LCP[i])));
        }
        pf("Case %d: %d\n",cs++,s);
    }
    return 0;
}


