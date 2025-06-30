#include<bits/stdc++.h>
using namespace std;

int n, open1, open2, m;
int arr[21];
int dp[21][21][21];

int solve(int i, int j, int cnt){
    if(cnt == m) return 0;

    int &ret = dp[i][j][cnt];
    if(ret != -1) return ret;

    int target = arr[cnt];

    if(i == target || j == target){
        return ret = solve(i, j, cnt + 1);
    }
    else{
        int cost1 = abs(i - target) + solve(target, j, cnt +1);
        int cost2 = abs(j - target) + solve(i, target, cnt +1);
        ret = min(cost1, cost2);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> open1 >> open2 >> m;

    for (int i = 0; i < m; i++){
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));

    cout << solve(open1, open2, 0) << '\n';
}