#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1001], dp[1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = n-1; i >= 0; i--){
        int curMax = arr[i];
        int curMin = arr[i];
        dp[i] = 0;
        for (int j = i; j < n; j++){
            curMax = max(curMax, arr[j]);
            curMin = min(curMin, arr[j]);
            dp[i] = max(dp[i], dp[j+1] + curMax - curMin);
        }
    }
    cout << dp[0];
}