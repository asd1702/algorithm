#include<bits/stdc++.h>
#define mod 1000007
using namespace std;

int n, m ,c;
int board[51][51];
int dp[51][51][51][51]; // dp[x][y][최대 오락실 번호][거친 오락실 수]


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> c;

    for (int i = 1; i <= c; i++){
        int x, y;
        cin >> x >> y;

        board[x][y] = i;
    }
    if(board[1][1] == 0) dp[1][1][0][0] = 1;
    else dp[1][1][board[1][1]][1] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(i == 1 && j == 1) continue;
            int oRock = board[i][j];

            if(oRock == 0){
                for (int k = 0; k <= c; k++){
                    for (int l = 0; l <= c; l++){
                        dp[i][j][l][k] += dp[i-1][j][l][k] % mod;
                        dp[i][j][l][k] += dp[i][j-1][l][k] % mod;    
                    }
                }
            }
            else{
                for (int k = 1; k <= c; k++){
                    for (int l = 0; l < oRock; l++){
                        dp[i][j][oRock][k] += dp[i-1][j][l][k-1] % mod;
                        dp[i][j][oRock][k] += dp[i][j-1][l][k-1] % mod;    
                    }
                }
            }
        }
    }
    
    for (int i = 0; i <= c; i++){
        int ans = 0;
        for (int j = 0; j <= c; j++){
            ans += dp[n][m][j][i] % mod;    
        }
        ans %= mod;
        cout << ans << ' ';
    }
}