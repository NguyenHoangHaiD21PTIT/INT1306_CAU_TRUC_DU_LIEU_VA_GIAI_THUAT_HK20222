#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

int main(){
    ll A, B, K;
    cin >> A >> B >> K;
    for (int i = 1; i <= K; i++){
        if (i % 2 != 0) { // Lượt của Tí (Lượt lẻ)
            if (A % 2) A--; // Ăn 1 chiếc nếu kẹo lẻ
            ll half = A / 2;
            A -= half; B += half;
        } else { // Lượt của Tèo (Lượt chẵn)
            if (B % 2 != 0) B--; // Ăn 1 chiếc nếu kẹo lẻ
            ll half = B / 2;
            B -= half; A += half;
        }
    }
    cout << A << " " << B;
}