#include <bits/stdc++.h>
using namespace std;
int main() {
    string S; cin >> S;
    long long ans = 0, e = 0;//e: Số nhóm rỗng
    long long sA = 0, sB = 0, sC = 0; //sA: Số nhóm chỉ có 1 ký tự A, sB, sC tương tư
    long long pAB = 0, pAC = 0, pBC = 0; //pAB: Số nhóm đang có sẵn 1A và 1B
    for (char ch : S) {
        if (ch == 'A') {
            if (pBC > 0) { //Nhóm đang có 2 ký tự B và C, giờ có thêm A --> Thành 1 nhóm hoàn chỉnh
                pBC--; //Đã dùng 1 nhóm BC ghép với A rồi
                e++; //Dùng xong thì reset lại thành nhóm rỗng
            } else if (sB > 0) { 
                sB--; //Đã dùng 1 nhóm type có 1 B để ghép với A rồi, và cái nhóm này sẽ trở thành AB
                pAB++; 
            } else if (sC > 0) { 
                sC--; 
                pAC++; 
            } else if (e > 0)  { 
                e--;  
                sA++;  
            } else { //Không còn nhóm 2 ký tự, k còn nhóm 1 ký tự, k còn nhóm rỗng thì phải tạo nhóm mới hoàn toàn
                ans++; 
                sA++; 
            }
        } else if (ch == 'B') {
            if (pAC > 0) { 
                pAC--; 
                e++; 
            } else if (sA > 0) { 
                sA--; 
                pAB++; 
            } else if (sC > 0) { 
                sC--; 
                pBC++; 
            } else if (e > 0)  { 
                e--;  
                sB++; 
            } else { 
                ans++; 
                sB++; 
            }
        } else if (ch == 'C') {
            if (pAB > 0) { 
                pAB--; 
                e++; 
            } else if (sA > 0) { 
                sA--; 
                pAC++; 
            } else if (sB > 0) { 
                sB--; 
                pBC++; 
            } else if (e > 0)  { 
                e--;  
                sC++;  
            } else { 
                ans++; 
                sC++; 
            }
        }
    }
    cout << ans;
    return 0;
}
