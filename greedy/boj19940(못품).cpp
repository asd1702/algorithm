#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    // 60분 단위는 반드시 ADDH 버튼 사용
    int a1 = n / 60;
    int r = n % 60;
    
    // Down 전략: r 이하로 만들기
    int a2_down = r / 10;       // ADDT
    int a4_down = r % 10;       // ADDO
    int cost_down = a2_down + a4_down;
    
    // Up 전략: r를 초과하여 10의 배수로 만들기
    int a2_up = (r + 9) / 10;     // ceil(r/10)
    int a3_up = a2_up * 10 - r;     // MINO
    int cost_up = a2_up + a3_up;
    
    int a2, a3, a4, a5;
    // 총 버튼 누름 횟수가 더 적거나, 같다면 사전 순 (여기서는 ADDT의 횟수가 적은 것이 우선)
    if(cost_down < cost_up || (cost_down == cost_up && a2_down < a2_up)){
        a2 = a2_down; 
        a3 = 0;
        a4 = a4_down;
        a5 = 0;
    } else {
        a2 = a2_up;
        a3 = a3_up;
        a4 = 0;
        a5 = 0;
    }
    
    cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
