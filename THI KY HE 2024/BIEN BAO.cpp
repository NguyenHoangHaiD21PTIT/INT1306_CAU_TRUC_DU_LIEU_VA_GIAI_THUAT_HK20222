#include <bits/stdc++.h>
using namespace std;
int main() {
    string N;
    int K;
    cin >> N >> K;
    stack<char> s;
    //Với mỗi chữ số ta đang xét, ta sẽ xóa tất cả những chữ số bên tay trái nó mà nhỏ hơn nó
    for (char c : N) {
        while (!s.empty() && s.top() < c && K > 0) {
            s.pop();
            K--;
        }
        s.push(c);
    }
	//Trong trường hợp chạy đến hết xâu rồi mà vẫn chưa hết số lần cắt 
	//Lúc này, đỉnh stack lưu số bé nhất, tăng dần cho đến số cuối
    while (K > 0) {
        s.pop();
        K--;
    }

    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}
//Submit: https://www.spoj.com/PTIT/problems/PTIT125I/
