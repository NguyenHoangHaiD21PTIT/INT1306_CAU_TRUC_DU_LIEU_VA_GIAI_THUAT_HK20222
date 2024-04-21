#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[k];
        for(int i = 0;i<k;i++) cin>>a[i];
        int pos = k - 1;
        while(pos>=1 && a[pos - 1]==a[pos] - 1) pos--;
        if(pos||(pos==0&&a[0]!=1)){
            a[pos]--;
            for(int i = pos + 1;i<k;i++) a[i] = n - k + (i + 1);
            for(int i = 0;i<k;i++) cout<<a[i]<<" ";
        } else {
            for(int i = 0;i<k;i++) cout<<n - k + (i + 1)<<" ";
        }
        cout<<endl;
    }
}
/* Làm xuôi: Tìm vị trí đầu tiên chưa đạt max từ phải lại, gọi là pos, a[pos]++; for(int i = pos + 1;i<=k;i++) a[i] = a[i - 1] + 1 (3)
Như vậy từ pos + 1 đổ về cuối là những số mà tổ hợp trước đó đã đạt cực đại, và cũng chính trong khoảng này: mỗi số = số liền trước + 1 (1)
--> Vị trí đầu tiên từ bên phải lại mà không bằng liền trước +1 tổ hợp hiện tại chính là vị trí đầu tiên chưa đạt max tổ hợp trước đó (2)

Từ đó ta giải bài toán sinh ngược
Phải tìm Vị trí đầu tiên từ bên phải lại mà không bằng liền trước +1, gọi là Pos
Sinh xuôi tăng 1 --> Sinh ngược bớt 1
Từ ấy về sau là những vị trí mà tổ hợp trước đó đạt MAX --> Gán MAX cho toàn bộ dãy về sau

Xử lý các trường hợp đặc biệt:
TH1: Không tồn tại Pos nhưng phần tử đầu tiên khác 1 --> Giảm phần tử đầu xuống bình thường, gán cực đại cho dãy còn lại
TH2: Phần tử đầu tiên bằng 1 --> Không thể giảm, cấu hình đầu --> Gán cực đại cho cả dãy để tính cấu hình cuối */

