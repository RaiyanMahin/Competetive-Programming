#include "stdio.h"

#define sz 100010
#define sz2 262164

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}


int arr[sz], node[sz2];

void build(int nod, int b, int e)
{
    if(b==e)
    {
        node[nod]=1;
        return;
    }

    int mid=(b+e)>>1, lft=nod<<1, rht=lft|1;

    build(lft, b, mid);
    build(rht, mid+1, e);

    node[nod]=node[lft]+node[rht];

    return;

}


int query(int nod, int b, int e, int x)
{
    if(b==e)
        return b;

    int mid=(b+e)>>1, lft=nod<<1, rht=lft|1;

    if(x<=node[lft])
        return query(lft, b, mid, x);
    else
        return query(rht, mid+1, e, x-node[lft]);

}


void update (int nod, int b, int e, int f)
{
    if(b==e)
    {
        node[nod]=0;
        return ;
    }

    int mid=(b+e)>>1, lft=nod<<1, rht=lft|1;

    if(f<=mid)
        update(lft, b, mid, f);
    else
        update(rht, mid+1, e, f);

    node[nod]=node[lft]+node[rht];

}


int main()
{
    int ts, n, i, t=1, f, m, x;
//    scanf("%d",&ts);
    inp(ts);

    while(ts--)
    {
        scanf("%d",&n);

        for(i=1;i<=n;i++)
//            scanf("%d",&arr[i]);
            inp(arr[i]);

        build(1, 1, n);
        m=n;

        for(i=n;i>=1;i--)
        {
            x = m-arr[i];
            f = query(1, 1, n, x);
            update(1, 1, n, f);
            m--;
        }
        printf("Case %d: %d\n", t++, f);

    }

    return 0;
}
