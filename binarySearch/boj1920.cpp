#include<bits/stdc++.h>
using namespace std;

int n, m, a[100001];

bool chk(int target){
    int st = 0, en = n-1;

    while (st <= en){
        int mid = (st + en) >> 1;
        if(a[mid] == target) return true;
        else if(a[mid] > target) en = mid - 1;
        else st = mid + 1;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    cin >> m;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(chk(x)) cout << "1\n";
        else cout << "0\n";
    }
}