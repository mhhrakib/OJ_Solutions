#include <bits/stdc++.h>
using namespace std;
#define MS(array, value) memset(array, value, sizeof array)

const int MX = 10001;
vector < int > G[MX];
bool vis[MX];

bool DFS (int u) {
    vis[u] = true;
    int sz = G[u].size();
    for(int i = 0; i<sz; i++) {
        int v = G[u][i];
        if(vis[v] == false) {
            DFS(v);
        }
        else
            return true;        
    }
    return false;
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++) {
        int m, cnt = 0, flag = 1;
        MS(vis, false);
        scanf("%d",&m);
        string str1, str2;
        map <string, int> Map;
        for(int j = 0; j<m; j++) {
            cin>>str1>>str2;
            
            if(Map.count(str1) == 0) {
                Map.insert(pair < string , int > (str1, cnt + 1));
                cnt++;
            }
            if(Map.count(str2) == 0) {
                Map.insert(pair < string , int > (str2, cnt + 1));
                cnt++;
            }
                
            map < string, int > :: iterator u,v;
            u = Map.find(str1);
            v = Map.find(str2);
            //printf("%s %d %s %d\n",str1, u->second, str2, v->second );
            //cout << str1 << " " << u->second << str2 << " " << v->second << "\n";
            G[u->second].push_back(v->second);            
        }
        for(int j = 1; j<=cnt; j++) {
            if(vis[j] == false) {
                bool foo = DFS(j);
                if(foo == true) {
                    flag = 0;
                    //cout<< "false";
                    break;
                }
            }
        }
        
        if(flag)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
        for(int j = 1; j<=cnt; j++)
            G[j].clear();
    }
    return 0;
}


