#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s, e;
        cin>>n>>s>>e;
        unordered_set<string>wordSet;//Để tra cứu xem từ được biến đổi có trong tập từ đã cho không
        for(int i = 0;i<n;i++){
            string x;
            cin>>x;
            wordSet.insert(x);
        }
        if(s==e){
            cout<<1<<endl;
            continue;
        }
        //Tiến hành BFS
        queue<pair<string, int>> q; // Hàng đợi lưu trạng thái của từ và số bước biến đổi
        q.push({s, 0});
        unordered_set<string>visited;//Xem từ biến đổi đã từng biến đổi chưa
        visited.insert(s);
        //Bước 2: Lặp
        while(!q.empty()){
            pair<string, int> current = q.front();
	        q.pop();
            // Tìm thấy đường đi ngắn nhất
	        if (current.first == e) {
                cout<< current.second + 1<<endl; 
                break;
            }
	        for (int i = 0; i < current.first.size(); ++i) {
                //Để loang, ta thay từng chữ cái trong xâu gốc rồi xem thay xong
                //thì có trong tập từ đề cho không
	            char originalChar = current.first[i];
	            for (char c = 'A'; c <= 'Z'; ++c) {
	                current.first[i] = c;
                    //Nếu biến đổi ra từ chưa từng biến đổi và từ đó có trong tập từ đề cho
	                if (wordSet.find(current.first) != wordSet.end() && visited.find(current.first) == visited.end()) {
	                    q.push({current.first, current.second + 1});
	                    visited.insert(current.first);
	                }
	            }
	            current.first[i] = originalChar; // Khôi phục lại ký tự gốc đã thay đổi sau khi dùng xong
	        }
	    }
    }
}