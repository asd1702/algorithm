#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct State{
    int i, x, y, z, cost;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    string init, target;

    cin >> n >> init >> target;
    vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(10, INF))));
    queue<State> q;
    
    auto push_state = [&](int i, int x, int y, int z, int cost, queue<State>&q){
        if(cost < dp[i][x][y][z]){
            dp[i][x][y][z] = cost;
            q.push({i, x, y, z, cost});
        }
    };

    int init0 = init[0]-'0';
    push_state(0, init0, 0, 0, 0, q);

    while(!q.empty()){
        State cur = q.front(); q.pop();
        int i = cur.i, x = cur.x, y = cur.y, z = cur.z, cost = cur.cost;
        if(cost != dp[i][x][y][z]) continue;

        if(i == n){
            cout << cost;
            return 0;
        }

        int targetVal = target[i]-'0';
        if(x == targetVal){
            if(i == n-1){
                if(cost < dp[n][0][0][0]){
                    dp[n][0][0][0] = cost;
                    q.push({n, 0, 0, 0, cost});
                }
            }
            else{
                int nextVal = ((init[i+1]-'0') + y) % 10;
                push_state(i+1, nextVal, z, 0, cost, q);
            }
            continue;
        }
        for (int r = -3; r <= 3; r++){
            if(r == 0) continue;
            if(i < n){
                int newX = (x + r + 10) % 10;
                push_state(i, newX, y, z, cost+1, q);
            }
            if(i+1 < n){
                int newX = (x + r + 10) % 10;
                int newY = (y + r + 10) % 10;
                push_state(i, newX, newY, z, cost+1, q);
            }
            if(i+2 < n){
                int newX = (x + r + 10) % 10;
                int newY = (y + r + 10) % 10;
                int newZ = (z + r + 10) % 10;
                push_state(i, newX, newY, newZ, cost+1, q);
            }
        }
    }
}