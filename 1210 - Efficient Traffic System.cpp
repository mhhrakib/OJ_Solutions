#include <bits/stdc++.h>
using namespace std;
#define MS(array, value) memset(array, value, sizeof array)


const int Max = 20002;
vector <int> adj1 [Max*2];
vector <int> adj2 [Max*2];
//vector <int> SCC[Max];
int scc[Max];
bool vis[Max];
bool vis2[Max];
stack <int> stk;
int cnt = 0;

struct edge {
    int u,v;
    edge() {}
    edge (int _u, int _v) {
        u = _u;
        v = _v;
    }
};
vector <edge> E;

void dfs (int u)
{
    if(vis[u] == true)
        return;
    vis[u] = true;
    int sz = adj1[u].size();
    for(int i = 0; i<sz; i++) {
        int v = adj1[u][i];
        dfs(v);
    }
    stk.push(u);
}

void dfs2 (int u)
{
    if(vis2[u] == true)
        return;
    vis2[u] = true;
    //SCC[cnt].push_back(u);
    scc[u] = cnt;
    //cout<< "vstd "<<u<<" ";
    int sz = adj2[u].size();
    for(int i = 0; i<sz; i++) {
        int v = adj2[u][i];
        dfs2(v);
    }
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++) {
        memset(vis,false, sizeof vis);
        memset(vis2, false, sizeof vis2);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int j = 0; j<m; j++) {
            int u,v;
            scanf("%d %d",&u,&v);
            adj1[u].push_back(v);
            adj2[v].push_back(u);
            E.push_back(edge(u,v));
        }
        
        for(int k = 1; k<=n; k++) {
                if(vis[k] == false) 
                    dfs(k);
        }
        //int cnt = 0;
        while(!stk.empty()) {
            int u = stk.top();
            stk.pop(); 
            //printf("%d ",u);
            if(vis2[u] == false) {
                dfs2(u);
                cnt++;
            }
        }
        int in[cnt];
        int out[cnt];
        MS(in,0);
        MS(out,0);
        for (int it = 0; it<m; it++) {
            int su = scc[E[it].u];
            int sv = scc[E[it].v];
            if(su != sv) {
                out[su]++;
                in[sv]++;
            }
            
        }
        int ain, bout;
        ain = bout = 0;
        for (int it = 0; it<cnt; it++) {
            if(in[it] == 0)
                ain++;
            if(out[it] == 0)
                bout++;
        }
        printf("Case %d: %d\n",i, max(ain,bout));
        for(int x = 1; x<=n; x++) {
            adj1[x].clear();
            adj2[x].clear();
        }
        cnt = 0;
        MS(scc,0);
    }
    return 0;
}
