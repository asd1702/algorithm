#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;

    int n = s.size();

    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    vector<int> dp(n, INT_MAX);

    for (int i = 0; i < n; i++){
        isPal[i][i] = true;
    }
    
    for (int i = 0; i < n-1; i++){
        isPal[i][i+1] = (s[i] == s[i+1]);
    }
    
    for (int len = 3; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
        }
    }
    
    for (int i = 0; i < n; i++){
        if(isPal[0][i]){
            dp[i] = 1;
        }
        else{
            for (int j = 1; j <= i; j++){
                if(isPal[j][i]){
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
    }
    cout << dp[n-1];
}