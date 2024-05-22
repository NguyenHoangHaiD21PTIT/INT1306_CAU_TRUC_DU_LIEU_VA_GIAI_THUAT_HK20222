#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char>left, right;
    for(char x: s){
        if(x=='<'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        } else if(x=='>'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        } else if (x=='-'){
            if(!left.empty()) left.pop();
        } else {
            left.push(x);
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout<<right.top();
        right.pop();
    }
}