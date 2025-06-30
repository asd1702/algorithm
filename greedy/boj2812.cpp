#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

string solve(int n, int k, string& s){
    stack<char> st;
    
    int remove = k;
    for (int i = 0; i < n; i++){
        char cur = s[i];

        while(!st.empty() && remove > 0 && st.top() < cur){
            st.pop();
            remove--;
        }
        st.push(cur);
    }
    while (remove > 0 && !st.empty()){
        st.pop();
        remove--;
    }

    string ans = "";

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> s;
    
    string ans = solve(n, k, s);

    cout << ans;
}