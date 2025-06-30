#include<bits/stdc++.h>
#define ll long long
#define INF 1e16
using namespace std;

int n, m;
int board[201][201];
ll psum[202][202];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            psum[i+1][j+1] += (psum[i+1][j] + psum[i][j+1] - psum[i][j]) + board[i][j];
        }
    }

    ll ans = -INF;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = 1; k <= n-i; k++){
                for(int l = 1; l <= m-j; l++){
                    ans = max(ans, psum[i+k][j+l] - psum[i+k][j] - psum[i][j+l] + psum[i][j]);
                }   
            }
        }
    }
    
    cout << ans;
}