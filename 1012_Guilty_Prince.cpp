#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pi;
const int MX = 21;
int w,h,cnt;
char cell[MX][MX];
bool vis[MX][MX];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void reset()
{
    memset(vis, false, sizeof vis);
    cnt = 0;
}

bool invalidCell(int x, int y)
{
    return (x<0 || x>=h || y<0 || y>=w);
}
int BFS(int x, int y)
{
    queue < pi > Q;
    Q.push(pi(x,y));
    vis[x][y] = true;

    while(!Q.empty()) {
        int ux = Q.front().first;
        int uy = Q.front().second;
        Q.pop();

        for(int i = 0; i<4; i++) {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vis[vx][vy] || invalidCell(vx, vy) || cell[vx][vy] == '#')
                continue;
            else {
                cnt++;
                vis[vx][vy] = true;
                Q.push(pi(vx,vy));
            }
        }
    }
    return cnt;
}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
    freopen("1012.txt","r",stdin);
    int t,x,y;
    scanf("%d",&t);

    for(int i = 1; i<=t; i++) {
        scanf("%d %d",&w, &h);
        for(int j = 0; j<h; j++) {
            for(int k = 0; k<w; k++) {
                //scanf("%c",&cell[j][k]);
                cin>>cell[j][k];
                if(cell[j][k] == '@') {
                    x = j, y = k;
                    //printf("%d %d",x,y);
                }
            }
        }
        reset();
        int res = BFS(x,y);
        printf("Case %d: %d\n",i,res);
    }
    return 0;
}
