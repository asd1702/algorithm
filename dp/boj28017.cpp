#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, m, a[501][501], dp[501][501];

int solve(int num, int choice){
    if(num >= n) return 0; 
    int& ret = dp[num][choice];
    if(ret != -1) return ret;

    ret = INF;
    
    for (int i = 0; i < m; i++){
        if(i == choice) continue;
        ret = min(ret, solve(num + 1, i) + a[num][i]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = INF;
    for (int i = 0; i < m; i++){
        ans = min(ans, solve(1, i) + a[0][i]);
    }
    cout << ans;
}