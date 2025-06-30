#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef struct arr{
    int day;
    int cost;
}arr;

int n, t, dp[1001][1001];
arr a[1001];

int solve(int idx, int day){
    if(idx >= n) return 0;
    if(day > t) return INF;
    
    int &ret = dp[idx][day];
    if(ret != -1) return ret;
    
    int skip = solve(idx + 1, day) + a[idx].cost;
    ret = INF;
    if(day + a[idx].day <= t){
        ret = min(ret, solve(idx + 1, day + a[idx].day));
    }
    return ret = min(ret, skip);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> a[i].day >> a[i].cost;
    }
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0);
}