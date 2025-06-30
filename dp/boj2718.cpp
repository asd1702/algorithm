#include<bits/stdc++.h>
using namespace std;

int t;
int dp[1000001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    dp[0] = 1, dp[1] = 1, dp[2] = 5, dp[3] = 11;
    for (int i = 4; i < 1000001; i++){
        
    }
    

    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}

// n == 홀수
// dp[3]= dp[2] * dp[1] * 2 - 중복 1 + odd(2) = 11
// 

// n == 짝수
// dp[4] = 