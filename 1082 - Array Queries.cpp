#include <bits/stdc++.h>
using namespace std;

const int Max = 100001;
int arr[Max], tree[Max<<2];

void build (int at, int st, int ed)
{
    if(st == ed) {
        tree[at] = arr[st];
        return;
    }
    int lft = at * 2;
    int rgt = lft + 1;
    int mid = (st + ed)/2;
    
    build(lft, st, mid);
    build(rgt, mid + 1, ed);
    
    tree[at] = min(tree[lft], tree[rgt]);
}

void update (int at, int st, int ed, int pos, int u)
{
    if(st == ed) {
        tree[at] = u;// use tree[at] += u if value is increased by u;
        return;
    }
    int lft = at*2;
    int rgt = lft + 1;
    int mid = (st + ed)/2;
    
    if(pos <= mid) 
        update(lft, st, mid, pos, u);
    else
        update(rgt, mid + 1, ed, pos, u);
        
    tree[at] = tree[lft] + tree[rgt];
    
}

int query(int at, int st, int ed, int l, int r)
{
    if(r < st || l > ed)
        return 44777778;
    if(l<=st && r>=ed)//( l <= L && R <= r ) 
        return tree[at];
        
    int lft = at*2;
    int rgt = lft + 1;
    int mid = (st + ed)/2;
    int sumL = query(lft, st, mid, l, r);
    int sumR = query(rgt, mid + 1, ed, l, r);
    
    return min(sumL, sumR);
}


int main()
{
    int n,q,t,l,r;
    //cin >> t;
    scanf("%d",&t);
    for(int j = 1; j<=t; j++) {
        //cin >> n >> q;
        scanf("%d %d",&n,&q);
        for(int i = 1; i<=n; i++)
           scanf("%d",&arr[i]); //cin>> arr[i];
        build(1, 1, n);
        printf("Case %d:\n",j);
        for(int i = 1; i<=q; i++) {
            //cin >> l >> r;
            scanf("%d %d",&l,&r);
            int x = query(1, 1, n, l, r);
            printf("%d\n",x);
        }
    }
    return 0;
}
