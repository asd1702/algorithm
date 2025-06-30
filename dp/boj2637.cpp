#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>indeg(n+1, 0);

    for (int i = 0; i < m; i++){
        int x, y, k;
        cin >> x >> y >> k;
        adj[y].push_back({x, k});
        indeg[x]++;
    }
    
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    queue<int>q;
    for (int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            dp[i][i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int part = q.front(); q.pop();

        for(auto& edge : adj[part]){
            int next = edge.first;
            int cnt = edge.second;

            for (int basic = 1; basic < n; basic++){
                if(dp[part][basic] > 0){
                    dp[next][basic] += dp[part][basic]*cnt;
                }
            }
            indeg[next]--;
            if(indeg[next] == 0){
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if(dp[n][i] > 0){
            cout << i << ' ' << dp[n][i] << '\n';
        }
    }
    
}