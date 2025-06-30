#include<bits/stdc++.h>
using namespace std;

int arr[101];
int dp[10001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            if(j >= arr[i]){
                dp[j] += (dp[j-arr[i]]);
            }
        }
    }
    cout << dp[k];
}