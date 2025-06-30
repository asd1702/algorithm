#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m;
string init[51];
int dp[51][51][4];
bool visited[51][51][4];

int solve(int x, int y, int direct){
    if(x > n-1 || y > m-1 || x < 0 || y < 0) return 0;
    if(visited[x][y][direct]){
        cout << -1;
        exit(0);
    }

    int& ret = dp[x][y][direct];
    if(dp[x][y][direct] != -1) return ret;

    visited[x][y][direct] = 1;
    ret = 0;
    if(init[x][y] == 'H'){
        visited[x][y][direct] = 0;
        return 0;
    }
   int move = init[x][y]-'0';
 
    ret = max(ret, solve(x+move, y, 0) + 1);
    ret = max(ret, solve(x-move, y, 1) + 1);
    ret = max(ret, solve(x, y+move, 2) + 1);
    ret = max(ret, solve(x, y-move, 3) + 1);

    visited[x][y][direct] = 0;
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> init[i];
    }
    memset(dp, -1, sizeof(dp));
    int move = init[0][0]-'0';
    
    cout << max(solve(0,0,0), solve(0,0,2));
}