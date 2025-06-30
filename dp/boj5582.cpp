#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[4001][4001];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s1 >> s2;

    int s1_size = s1.size() + 1;
    int s2_size = s2.size() + 1;

    int ans = 0;

    for (int i = 1; i < s1_size; i++){
        for (int j = 1; j < s2_size; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout << ans;   
}