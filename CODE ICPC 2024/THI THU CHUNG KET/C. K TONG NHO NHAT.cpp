#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
typedef pair<int, int> ii;
const int MAXK = 750 + 3;

void merge(int a[], int b[], int c[], int k) { 
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < k; ++i) pq.push(ii(a[i] + b[0], 0));
    int idx = 0;
    //Tịnh tiến theo vị trí của b. Ghép a với b vào c
    while (!pq.empty() && idx < k) {
        ii t = pq.top();  
        pq.pop();   
        c[idx++] = t.ff;  
        if (t.ss + 1 < k) pq.push(ii(t.ff - b[t.ss] + b[t.ss + 1], t.ss + 1));
    }
}

int main() {
    int k, arr1[MAXK], arr2[MAXK];
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> arr1[i];
    sort(arr1, arr1 + k);  
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < k; ++j) cin >> arr2[j];
        sort(arr2, arr2 + k); 
        merge(arr1, arr2, arr1, k);  
    }
    cout << arr1[0];  
    for (int i = 1; i < k; ++i) cout << " " << arr1[i];  
    cout << endl;
}
//https://basecamp.eolymp.com/en/problems/2057
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3148
