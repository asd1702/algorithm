#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000000
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> dp(n+1, 0);

    dp[1] = 1 % MOD;
    dp[2] = 2 % MOD;
    dp[3] = 2 % MOD;

    for (int i = 4; i <= n; i++){
        if(i%2 != 0){
            dp[i] = dp[i-1] % MOD;
        }
        else{
            dp[i] = (dp[i-1] + dp[i/2]) % MOD;
        }
    }
    cout << dp[n] % MOD;
}