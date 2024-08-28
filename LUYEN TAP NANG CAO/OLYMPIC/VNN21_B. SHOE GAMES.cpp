#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, sum = 0;
    cin>>n;
    while(n--){
        int x; cin>>x;
        sum+=x;
    }
    cout<<-sum;
}