#include<bits/stdc++.h>
using namespace std;

int n, w;
pair<int, int> events[1001];
int dp[1001][1001];
int choice[1001][1001];

int dist(int from, int to, bool isFirst){
    pair<int, int> start, dest;
    if(from == 0){
        start = isFirst ? make_pair(1, 1) : make_pair(n, n);
    }
    else{
        start = events[from];
    }
    dest = events[to];
    return abs(start.first - dest.first) + abs(start.second - dest.second);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> w;

    for (int i = 1; i <= w; i++){
        cin >> events[i].first >> events[i].second;
    }
    
    for (int i = 0; i <= w; i++){
        for (int j = 0; j <= w; j++){
            dp[i][j] = 0;
        }
    }
    
    for (int i = w; i >= 0; i--){
        for (int j = w; j >= 0; j--){
            int k = max(i, j) + 1;
            if(k > w) continue;
            int cost1 = dp[k][j] + dist(i, k, true);
            int cost2 = dp[i][k] + dist(j, k, false);

            if(cost1 < cost2){
                choice[i][j] = 1;
                dp[i][j] = cost1;
            }
            else{
                choice[i][j] = 2;
                dp[i][j] = cost2;
            }
        }
    }
    
    cout << dp[0][0] << '\n';

    int i = 0, j = 0;
    for (int k = 1; k <= w; k++){
        if(choice[i][j] == 1){
            cout << 1 << '\n';
            i = k;
        }
        else{
            cout << 2 << '\n';
            j = k;
        }
    }
}