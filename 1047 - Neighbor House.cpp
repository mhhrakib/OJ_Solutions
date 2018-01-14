#include <bits/stdc++.h>
using namespace std;
int arr[20][3];
int dp[20][3];
int n;
int minn(int x, int y, int z)
{
    int a = min(x,y);
    int b = min(y,z);
    return min(a,b);
}

int solve(int i, int j)
{
    if(i<n) {
        if(dp[i][j] != -1)
            return dp[i][j];
        else {
            int tmp = arr[i][j];
            if(j == 0)
                return dp[i][j] = min(tmp + solve(i+1,1), tmp + solve(i+1,2));
            else if(j == 1)
                return dp[i][j] = min(tmp + solve(i+1,0), tmp + solve(i+1,2));
            else
                return dp[i][j] = min(tmp + solve(i+1,0), tmp + solve(i+1,1));
        }
    }
    else
        return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d", &t);

    int i;
    for(i = 1; i<=t; i++) {
        scanf("%d", &n);
        int j,k;
        memset(dp,-1, sizeof dp);
        for(j = 0; j<n; j++) {
            for(k = 0; k<3; k++) {
                scanf("%d",&arr[j][k]);
                //printf("%d \n",arr[j][k]);
            }
        }
        int res1 = solve(0,0);
        int res2 = solve(0,1);
        int res3 = solve(0,2);
        int res = minn(res1, res2, res3);

        printf("Case %d: %d\n",i,res);
    }
    return 0;
}
