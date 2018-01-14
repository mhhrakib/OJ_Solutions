/**
    @author mhhrakib
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#define MS(array, value) memset(array, value, sizeof array)
#define MX 10001
#define pi pair<int,int>
using namespace std;

bool compare(pi pi1,pi pi2){
     if(pi1.first == pi2.first)
        return pi1.second<pi2.second;
     return pi1.first<pi2.first;
}
struct graph
{
    vector <int> adj[MX];
    vector <pi> bridge;
    bool visited[MX];
    int dis_time[MX], parent[MX], low[MX], time,cnt;
    void init()
    {
        MS(visited,false);
        MS(parent,-1);
        MS(dis_time,0);
        MS(low,0);
        time = cnt = 0;
    }

    void Find_Bridge(int source)
    {
        int u = source;
        visited[u] = true;
        dis_time[u] = low[u] = ++time;
        for(int i = 0; i<adj[u].size(); i++)
        {
            int node = adj[u][i];

            if(parent[u] == node) continue;
            else if(visited[node] == true){
                low[u] = min(low[u], dis_time[node]);
            }

            else if(visited[node] == false){

                parent[node] = u;
                Find_Bridge(node);
                low[u] = min(low[node],low[u]);

                if(dis_time[u] < low[node]){
                    if(u>node)
                    bridge.push_back(make_pair(node,u));
                    else bridge.push_back(make_pair(u,node));
                    cnt++;
                }
            }
        }
        time++;
        return;
    }

    void Sort()
    {
        sort(bridge.begin(),bridge.end(),compare);
    }

};

int main(int argc, char **argv)
{
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc<=t; tc++){

        graph g;
        g.init();

        int nodes, edges, x, y;
        scanf("%d",&nodes);
        y = nodes;
        while(nodes--){
            int u,k;
            scanf("%d (%d)",&u,&k);
            while(k--){
                scanf("%d",&x);
                g.adj[u].push_back(x);

            }
        }
        for(int j = 0; j<y; j++)
           if(g.visited[j] == false)
            g.Find_Bridge(j);
        g.Sort();
        printf("Case %d:\n%d critical links\n",tc,g.cnt);
        for(int i = 0; i<g.cnt; i++)
            cout<<g.bridge[i].first<<" - "<<g.bridge[i].second<<endl;
    }
}

