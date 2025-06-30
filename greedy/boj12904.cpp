#include<bits/stdc++.h>
using namespace std;

string s, t;

string Swap(string t){
    string temp;
    for (int i = 0; i < t.size(); i++){
        temp += t[t.size()-1-i];        
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    
    int tsize = t.size() - 1;
    for (int i = t.size() - 1; i >= 0; i--){
        if(tsize == s.size()-1){
            if(t == s){
                cout << 1;
                return 0;
            }
            cout << 0;
            return 0;
        }
        if(t[i] == 'A'){
            t.pop_back();
        }
        else{
            t.pop_back();
            t = Swap(t);
        }
        tsize--;
    }
}