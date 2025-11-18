#include<bits/stdc++.h>
using namespace std;

struct node{
	int d; 
	node *l, *r; // right -> r
	node(int x){
		d = x;
		l = r = NULL;
	}
};

int findI(const vector<int>& in, int val, int s, int e){ 
    for(int i = s; i <= e; i++){
        if(in[i] == val) return i;
    }
    return -1;
}

void postT(const vector<int>& in, const vector<int>& pre, int s, int e, int& preI){ 
    if(s > e) return;
    int rootI = findI(in, pre[preI], s, e); 
    preI++;
    postT(in, pre, s, rootI - 1, preI);
    postT(in, pre, rootI + 1, e, preI);
    cout << in[rootI] << " ";
}

int main(){
    int T; cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> in(N), pre(N); 
        for(int i = 0; i < N; i++) cin >> in[i];
        for(int i = 0; i < N; i++) cin >> pre[i];
        int preI = 0; 
        postT(in, pre, 0, N - 1, preI);
        cout << endl;
    }
}
