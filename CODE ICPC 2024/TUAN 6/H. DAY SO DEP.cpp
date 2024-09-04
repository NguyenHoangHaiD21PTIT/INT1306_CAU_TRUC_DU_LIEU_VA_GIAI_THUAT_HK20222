#include <bits/stdc++.h>
using namespace std;
int minPrime[20000001], cnt[20000001], a[2000006];
void pTich(int n){//Phân tích ra thừa số nguyên tố
    while (n != 1) {
		int tmp = minPrime[n];
		n /= tmp;
		cnt[tmp]++;
	}
}
int main(){
    int n;
    cin>>n;
    int K = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        K = max(K, a[i]);
    }
    /*Các trường hợp sau không bao giờ tạo được
    1. a[i] = 1. Khi a[i] khác 0 thì b[i] = a[i], không thoả mãn điều kiện mọi số > 1
    2. 2 phần tử kề nhau dãy A = 0. Khi đó, 2 phần tử dãy B tương ứng là X --> UCLN(b[i], b[i + 1]) = UCLN(x, x) = x. 
       a. Nếu x = 1 thì: UCLN 2 phần tử kề nhau = 1 NHƯNG không thoả mãn đk mọi số > 1
       b. Nếu x khác 1 thì UCLN 2 phần tử kề nhau khác 1. Loại
    3. 2 phần tử kề nhau dãy A khác 0 nhưng UCLN khác 1: Khác 0 thì dãy B phải sao y chang sang, nên X không tác động được --> Sai
    */
    K+=200;
    for (int i = 2; i * i <=K; ++i) {
		if (minPrime[i] == 0) { //if i is prime
			for (int j = i * i; j <=K; j += i) {
				if (minPrime[j] == 0) minPrime[j] = i;
			}
		}
	}
	for (int i = 2; i <=K; ++i) {
		if (minPrime[i] == 0) minPrime[i] = i;
	}
    
    //Tư duy: Phân tích tung hết N số ra thừa số nguyên tố. Những chỗ có 0 ta thay bằng SNT nhỏ nhất mà chưa có
    int validCount = 0;//Số lượng số > 1 và kề nó là số 0
    for (int i = 1; i <= n; ++i) {
        // Kiểm tra điều kiện không hợp lệ
        if (a[i] == 1 || 
            (i > 1 && a[i] == 0 && a[i - 1] == 0) || 
            (i > 1 && a[i] != 0 && a[i - 1] != 0 && __gcd(a[i], a[i - 1]) != 1)) {
            cout<<-1;
            return 0;
        }
        // Nếu a[i] > 1 và có ít nhất một phần tử 0 liền kề
        if (a[i] > 1 && ((i > 1 && a[i - 1] == 0) || (i < n && a[i + 1] == 0))) {
            pTich(a[i]);  
            validCount++; 
        }
    }
    if (validCount == 0) {
        cout << 1;  // Nếu không có phần tử 0 liền kề nào, giá trị nhỏ nhất của X là 1
    } else {
        // Tìm số nguyên tố nhỏ nhất chưa xuất hiện trong các thừa số nguyên tố của dãy số
        for (int i = 2; i <=K; ++i) {
            if (cnt[i] == 0 && minPrime[i]==i) {
                cout << i;  
                break;
            }
        }
    }
}
