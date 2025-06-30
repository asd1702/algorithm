#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dp[101][10][10][10];
int n;
string init, target;

int solve(int i, int x, int y, int z){
    if(i == n){
        return 0;
    }
    int& ret = dp[i][x][y][z];
    if(ret != -1){
        return ret;
    }
    ret = INF;
    int targetVal = target[i]-'0';
    int getVal = ((init[i]-'0') + x) % 10;

    if(getVal == targetVal){
        ret = min(ret, solve(i+1, y, z, 0)); // 현재 인덱스와 타깃 인덱스의 값이 일치하더라도 더 최적의 선택이 있을 수 있음
    }
    for (int r = -3; r <= 3; r++){
        if(r == 0) continue;
        ret = min(ret, solve(i, (x + r + 10) % 10, y, z) + 1);
        ret = min(ret, solve(i, (x + r + 10) % 10, (y + r + 10) % 10, z) + 1);
        ret = min(ret, solve(i, (x + r + 10) % 10, (y + r + 10) % 10, (z + r + 10) % 10) + 1);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> init >> target;
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0, 0);
} 