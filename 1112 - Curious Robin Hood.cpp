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
    
    tree[at] = tree[lft] + tree[rgt];
}

void update (int at, int st, int ed, int pos, int u)
{
    if(st == ed) {
        tree[at] += u;// use tree[at] += u if value is increased by u;
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
        return 0;
    if(l<=st && r>=ed)//( l <= L && R <= r ) 
        return tree[at];
        
    int lft = at*2;
    int rgt = lft + 1;
    int mid = (st + ed)/2;
    int sumL = query(lft, st, mid, l, r);
    int sumR = query(rgt, mid + 1, ed, l, r);
    
    return sumL + sumR;
}


int main()
{
    freopen("1112.txt","r",stdin);
    int n,q,t,l,r,op,v,idx;
    scanf("%d",&t);
    for(int j = 1; j<=t; j++) {
        scanf("%d %d",&n,&q);
        for(int i = 1; i<=n; i++)
           scanf("%d",&arr[i]);
        build(1, 1, n);
        printf("Case %d:\n",j);
        for(int i = 1; i<=q; i++) {
            scanf("%d",&op);
            if(op == 1) {
               scanf("%d",&idx);
               update(1,1,n,idx + 1,-arr[idx + 1]);
               printf("%d\n",arr[idx + 1]);
               arr[idx + 1] = 0;
            }
            else if(op == 2) {
                scanf("%d %d",&idx,&v);
                update(1,1,n,idx + 1,v);
                arr[idx + 1] += v;
            }
            else {
                scanf("%d %d",&l,&r);
                int res = query(1,1,n,l+1,r+1);
                printf("%d\n",res);
            }
        } 
    }
    return 0;
}
