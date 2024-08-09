#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef vector<vector<int>> Matrix;

Matrix matrixMul(const Matrix &A, const Matrix &B, int n) {
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++) C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
        }
    }
    return C;
}

Matrix matrixAdd(const Matrix &A, const Matrix &B, int n) {
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) C[i][j] = (A[i][j] + B[i][j]) % MOD;
    }
    return C;
}

Matrix matrixPow(const Matrix &A, int k, int n) {
    if (k == 1) return A;
    if (k % 2 == 0) {
        Matrix half = matrixPow(A, k / 2, n);
        return matrixMul(half, half, n);
    } else {
        return matrixMul(A, matrixPow(A, k - 1, n), n);
    }
}

//Tao ma tran don vi
Matrix identityMatrix(int n) {
    Matrix I(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) I[i][i] = 1;
    return I;
}

Matrix B(int k, const Matrix &A, int n) {//B(k) = A + A^2 + ... + A^k
    if (k == 1) return A;
    Matrix halfB = B(k / 2, A, n); //B(k/2)
    Matrix Ak2 = matrixPow(A, k / 2, n); //A^(k/2)
    Matrix result = matrixMul(matrixAdd(identityMatrix(n), Ak2, n), halfB, n);//(I + A^(k/2))*B(k/2)
    if (k % 2 != 0) {
        Matrix Ak = matrixPow(A, k, n);//A^k
        result = matrixAdd(result, Ak, n);
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    Matrix A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];
    Matrix result = B(k, A, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << result[i][j] << " ";
        cout << endl;
    }
}
