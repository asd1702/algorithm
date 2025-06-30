#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int n, m;
int board[1002][1002];
int gae[8][1002][1002];

int can(int mid){

    for(int i = mid; i <= n; i++){
        for(int j = mid; j <= n; j++){
            int jongryu = 0;

            int test = gae[0][i][j] - gae[0][i-mid][j] - gae[0][i][j-mid] + gae[0][i-mid][j-mid];

            if(test > 0) continue;

            for(int k = 1; k <= 7; k++){
                int now = gae[k][i][j] - gae[k][i-mid][j] - gae[k][i][j-mid] + gae[k][i-mid][j-mid];
                if(now > 0) jongryu++;
            }

            if(jongryu <= 2){
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    while(m--){
        int a, b, c, d; cin >> a >> b >> c >> d;

        for(int i = a+1; i < a+1+c; i++){
            for(int j = b+1; j < b+1+c; j++){
                board[i][j] = d;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k <= 7; k++){
                if(board[i][j] == k){
                    gae[k][i][j] = gae[k][i-1][j] + gae[k][i][j-1] - gae[k][i-1][j-1] + 1;
                }else{
                    gae[k][i][j] = gae[k][i-1][j] + gae[k][i][j-1] - gae[k][i-1][j-1];
                }
            }
        }
    }

    int st = 0;
    int en = 1000;

    while(st < en){
        int mid = (st + en + 1)/2;

        if(can(mid)) st = mid;
        else en = mid-1;
    }
    cout << st*st;
}