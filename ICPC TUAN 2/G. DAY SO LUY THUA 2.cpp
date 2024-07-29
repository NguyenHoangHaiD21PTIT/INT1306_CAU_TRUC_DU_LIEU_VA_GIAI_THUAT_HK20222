#include<bits/stdc++.h>

using namespace std;

string sum(const string a, const string b) {
    int lenA = a.length();
    int lenB = b.length();
    int carry = 0;
    string result;
    for (int i = 0; i < lenA; i++) {
        int digitA = a[lenA - i - 1] - '0';
        int digitB = (i < lenB) ? b[lenB - i - 1] - '0' : 0;
        int sumDigits = digitA + digitB + carry;
        carry = sumDigits / 10;
        result.insert(result.begin(), '0' + (sumDigits % 10));
    }
    if (carry > 0) {
        result.insert(result.begin(), '0' + carry);
    }
    return result;
}

bool isLessThan(const string& a, const string& b) {
    int lenA = a.length();
    int lenB = b.length();

    // So sánh độ dài của hai xâu
    if (lenA < lenB) {
        return true;
    }
    else if (lenA > lenB) {
        return false;
    }

    // So sánh từng kí tự
    for (int i = 0; i < lenA; i++) {
        if (a[i] < b[i]) {
            return true;
        }
        else if (a[i] > b[i]) {
            return false;
        }
    }

    // Nếu đến đây, hai xâu bằng nhau
    return false;
}

int main() {
	//boi vi deu la luy thua cua 2, nen neu so a b a voi b lon hon a thi chac chan a * 2 se be hon hoac bang b, do do cu nham vao so be hon ma loai bo no
	int n;
	cin >> n;
	vector<string> a(n);
	for (auto& x : a) cin >> x;
	stack<string> st;      //tao 1 stack luu gia tri tu lon den be  va giu lai cac gia tri tiem nang trong nay
	for (auto x : a) {
		while (!st.empty() && isLessThan(st.top(), x)) st.pop();         //neu gia tri x lon hon dinh cua stack thi loai bo (vi dinh be hon x)
		while (!st.empty() && x == st.top()) {      //neu dinh cua stack bang x 
			st.pop();      //loai bo no di
			x = sum(x,x);          // nhan doi len (hieu don gian la gop 2 so giong nhau vao ay
		}
		st.push(x);         //sau khi ket thuc thi push thg x vao
		// hieu don gian thi st.top = 4 va x = 4 thi x = 8 va st pop 4 ra roi thi phai them 8 vao ay
	}
	while (st.size() > 1) st.pop();          //vi no giu lai cac gia tri tiem nang nen gia tri o day moi la lon nhat, loai bo toi khi con 1 phan tu
	//vi du 16 8
	cout << st.top() << endl;  //in ra gia tri con lai
}
