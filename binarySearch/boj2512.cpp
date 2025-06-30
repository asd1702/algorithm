#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, sum, a[10001];

bool chk(int target){
    ll sum = 0;
    for (int i = 0; i < n; i++){
        if(a[i] <= target) sum += a[i];
        else sum += target;
    }
    if(sum > m) return 0;
    return 1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    sort(a, a+n);
    if(sum <= m){
        cout << a[n-1];
        return 0;
    }

    int st = 0, en = 100001;
    while(st < en){
        int mid = (st+en+1)/2;
        if(chk(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}