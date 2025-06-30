#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    
    int ans = arr[0][0];
    
    for (int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else if(i == j){
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else{
                dp[i][j] = max(dp[i][j], max(dp[i-1][j-1] + arr[i][j], dp[i-1][j] + arr[i][j]));
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}