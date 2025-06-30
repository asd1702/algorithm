#include<bits/stdc++.h>
using namespace std;

int p[1000001];

int ret_pos(int x, int y){
    return x*1000 + y;
}

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return 0;
    if(p[x] == p[y]) p[x]--;
    if(p[x] < p[y]) p[y] = x;
    else p[x] = y;

    return 1;
}

int n, m;
string board[1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    memset(p, -1, sizeof(p));

    for (int i = 0; i < n; i++){
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur_node = ret_pos(i, j);
            int next_i = i, next_j = j;

            if(board[i][j] == 'D') next_i = i + 1;
            else if(board[i][j] == 'U') next_i = i - 1;
            else if(board[i][j] == 'L') next_j = j - 1;
            else next_j = j + 1;
            
            int next_node = ret_pos(next_i, next_j);
            merge(cur_node, next_node);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int node_idx = ret_pos(i, j);
            if (p[node_idx] < 0) {
                cnt++;
            }
        }
    }
    cout << cnt;
}