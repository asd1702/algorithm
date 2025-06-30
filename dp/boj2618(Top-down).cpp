#include <bits/stdc++.h>
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

int solve(int i, int j){
    int k = max(i, j) + 1;
    if(k > w) return 0;

    int &ret = dp[i][j];
    if(ret != -1) return ret;

    int cost1 = solve(k, j) + dist(i, k, true);
    int cost2 = solve(j, k) + dist(j, k, false);

    if(cost1 < cost2){
        choice[i][j] = 1;
        ret = cost1;
    }
    else{
        choice[i][j] = 2;
        ret = cost2;
    }
    return ret;
}

void reconstruct(int i, int j){
    int k = max(i, j) + 1;
    if(k > w) return;

    if(choice[i][j] == 1){
        cout << 1 << '\n';
        reconstruct(k, j);
    }
    else{
        cout << 2 << '\n';
        reconstruct(i, k);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> w;    
    for (int i = 1; i <= w; i++){
        cin >> events[i].first >> events[i].second;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
    reconstruct(0, 0);
}
