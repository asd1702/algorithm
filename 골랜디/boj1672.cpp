#include <bits/stdc++.h>
using namespace std;

int n;
string s;

char table[4][4] = {
    {'A','C','A','G'},
    {'C','G','T','A'},
    {'A','T','C','G'},
    {'G','A','G','T'}
};
int idx(char c){
    if(c=='A') return 0;
    if(c=='G') return 1;
    if(c=='C') return 2;
    return 3;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;

    int len = n;
    while(len > 1){
        int i = idx(s[len-2]);
        int j = idx(s[len-1]);
        s[len-2] = table[i][j];
        --len;
    }
    cout << s[0];
    return 0;
}
