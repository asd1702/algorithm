#include<bits/stdc++.h>
#define pii pair<int, int>
#define X first
#define Y second
#define ll long long
#define INF 1e18
using namespace std;

int n;

int dx[5] = {1,0,-1,0, 0};
int dy[5] = {0,1,0,-1, 0};
pii event[100001], fisrtPos, temp;

int dist(pii a, pii b){
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> fisrtPos.X >> fisrtPos.Y;
    for (int i = 0; i < n; i++){
        cin >> event[i].X >> event[i].Y;
    }
    vector<vector<ll>> dp(n, vector<ll>(5, INF));

    for (int j = 0; j < 5; j++){
        int candX = event[0].X + dx[j];
        int candY = event[0].Y + dy[j];
        dp[0][j] = dist(fisrtPos, {candX, candY});
    }
    
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < 5; j++){
            if(dp[i][j] == INF) continue;
            int curX = event[i].X + dx[j];
            int curY = event[i].Y + dy[j];

            for (int k = 0; k < 5; k++){
                int nextX = event[i+1].X + dx[k];
                int nextY = event[i+1].Y + dy[k];
                
                ll cost = dist({curX, curY}, {nextX, nextY});
                dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost);
            }
        }
    }
    ll ans = dp[n-1][0];
    for (int j = 0; j < 5; j++){
        ans = min(ans, dp[n-1][j]);
    }
    cout << ans;
}