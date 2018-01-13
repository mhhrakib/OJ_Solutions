#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector <int> adj[10001];
bool vis[1001];
int karray[101];

void dfs (int u) {
    if(vis[u])
        return;
    vis[u] =  true;
    int sz = adj[u].size();
    for(int i = 0; i<sz; i++) {
        int v = adj[u][i];
        dfs(v);
    }
}

bool allvisited () {
    for(int i = 0; i<k; i++) {
        if(vis[karray[i]] == false)
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    
    for(int i = 1; i<=t; i++) {
        scanf("%d %d %d",&k,&n,&m);
        
        for(int j = 0; j<k; j++)
            scanf("%d",&karray[j]);
        
        int u,v,cnt = 0;
        for(int j = 0; j<m; j++) {
            scanf("%d %d",&v,&u); // reversing the graph;
            adj[u].push_back(v);
        }
        
        for(int j = n; j>0; j--) {
            dfs(j);
            if(allvisited() == true)
                cnt++;
            memset(vis, false, sizeof vis);
        }
        
        printf("Case %d: %d\n",i,cnt);
        
        for(int j = 1; j<=n; j++)
            adj[j].clear();
    }
    
    return 0;
}
