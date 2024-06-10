// balanced brackets
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<char, int> symbols = {
            {'[', -1}, {'(', -2}, {'{', -3},
            {']', 1}, {')', 2}, {'}', 3}
        };

string isbalanced(string s){
    stack<char> st;

    for(char bracket : s){
        if(symbols[bracket] < 0){
            st.push(bracket);
        } else {
            if(st.empty()){
                return "NO\n";
            }
            char top = st.top();
            st.pop();

            if(symbols[top] + symbols[bracket] != 0){
                return "NO\n";
            }
        }
    }

    if(st.empty()) return "YES\n";
    return "NO\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << isbalanced(s) << '\n';
    }

    return 0;
}
