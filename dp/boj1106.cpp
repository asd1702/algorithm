#include<bits/stdc++.h>
using namespace std;

int n, c;
int city[21], cost[21];
int dp[21][1001];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> c >> n;
    for (int i = 1; i <= n; i++){
        cin >> cost[i] >> city[i];
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= c; j++){
            dp[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= city[i]; j++){
            dp[i][j] = cost[i];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= c; j++){
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-city[i]] + cost[i]));
        }
    }

    cout << dp[n][c];
}