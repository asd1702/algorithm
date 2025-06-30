#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, r, c;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> r(n), c(n);
    vector<vector<ll>> dp(n, vector<ll>(n, INT_MAX));

    for (int i = 0; i < n; i++){
        cin >> r[i] >> c[i];
    }
    
    for (int i = 0; i < n; i++){
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + r[i] * c[k] * c[j]);
            }
        }
    }
    cout << dp[0][n-1];
}