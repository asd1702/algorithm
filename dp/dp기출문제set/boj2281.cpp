#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll INF = 1e18;
int n, m;
int arr[1001];

ll Sqrt(int num){
    return num * num;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<ll> dp(n+1, INF);
    dp[n] = 0;
    for (int i = n-1; i >= 0; i--){
        int length = 0;
        for (int j = i; j < n; j++){
            if(i == j) length = arr[j];
            else length += arr[j] + 1;

            if(length > m) break;
            ll cost = (j == n-1 ? 0 : Sqrt(m - length));
            dp[i] = min(dp[i], dp[j+1] + cost);
        }
    }
    cout << dp[0];
}
