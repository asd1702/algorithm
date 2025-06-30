#include<bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int K;
    cin >> K;
    vector<int> file(K), sum(K, 0);
    vector<vector<int>> dp(K, vector<int>(K, INT_MAX));

    for (int i = 0; i < K; i++){
        cin >> file[i];
    }
    sum[0] = file[0];
    for (int i = 1; i < K; i++){
        sum[i] = sum[i-1] + file[i];
    }

    for (int i = 0; i < K; i++){
        dp[i][i] = 0;
    }
    
    for (int len = 2; len <= K; len++){
        for (int i = 0; i <= K - len; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (i == 0 ? sum[j] : sum[j] - sum[i-1]));
            }
        }
    }
    cout << dp[0][K-1] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;

    while(t--){
        solve();
    }
}