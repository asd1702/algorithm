#include<bits/stdc++.h>
using namespace std;

int dp[10001][10];
int n;
string init, target;

int solve(int i, int offset){
    if(i == n) return 0;
    int& ret = dp[i][offset];
    
    if(ret != -1) return ret;

    int current = ((init[i]-'0') + offset) % 10;
    int diff = ((target[i]-'0') - current + 10) % 10;

    int left_turn = diff + solve(i+1, (diff + offset) % 10);
    int right_turn = ((10 - diff) % 10) + solve(i+1, offset);
    
    ret = min(left_turn, right_turn);
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> init >> target;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}