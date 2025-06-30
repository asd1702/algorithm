#include<bits/stdc++.h>
using namespace std;

int n, m, a[5001];

bool chk(int mid){
    int segments = 1;
    int curMax = a[0], curMin = a[0];
    for (int i = 1; i < n; i++){
        curMax = max(curMax, a[i]);
        curMin = min(curMin, a[i]);

        if(curMax-curMin > mid){
            segments++;
            curMax = a[i];
            curMin = a[i];
        }
    }
    return segments <= m;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int Max = a[0], Min = a[0];
    for (int i = 0; i < n; i++){
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }
    int st = 0, en = Max-Min;
    while(st <= en){
        int mid = st+(en-st)/2;
        if(chk(mid)) en = mid-1;
        else st = mid+1;
    }
    cout << en+1;
}