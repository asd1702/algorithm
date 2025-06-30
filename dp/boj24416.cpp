#include<bits/stdc++.h>
using namespace std;

int n, dp[41], cnt1, cnt2;

int solve(int n){
    if(n == 1 || n == 2){
        cnt1++;
        return 1;
    }
    return solve(n-1)+solve(n-2);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= n; i++){
        dp[i]=dp[i-1]+dp[i-2];
        cnt2++;
    }
    solve(n);
    cout << cnt1 << ' ' << cnt2;
}