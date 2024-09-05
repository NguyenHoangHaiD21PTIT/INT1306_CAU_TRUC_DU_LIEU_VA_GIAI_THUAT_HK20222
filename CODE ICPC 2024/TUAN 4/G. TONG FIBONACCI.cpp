#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
struct Matrix {
    int matrix[2][2];
    Matrix() {
        memset(matrix, 0, sizeof matrix);
    } 
    Matrix(int x) {
        memset(matrix, 0, sizeof matrix);
        matrix[0][0] = matrix[1][1] = x;
    }
};
Matrix multiply(Matrix A, Matrix B) {
    Matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) result.matrix[i][j] = (result.matrix[i][j] + A.matrix[i][k] * (ll)B.matrix[k][j]) % MOD;
        }
    }
    return result;
}
Matrix add(Matrix A, Matrix B) {
    Matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) result.matrix[i][j] = (A.matrix[i][j] + B.matrix[i][j]) % MOD;
    }
    return result;
}
Matrix power(Matrix A, ll exponent) {
    Matrix result(1);
    while (exponent) {
        if (exponent & 1) result = multiply(result, A);
        A = multiply(A, A);
        exponent >>= 1;
    }
    return result;
}
Matrix fibonacciMatrix(ll exponent) {
    Matrix fibMatrix;
    fibMatrix.matrix[0][0] = 1;
    fibMatrix.matrix[0][1] = 1;
    fibMatrix.matrix[1][0] = 1;
    return power(fibMatrix, exponent);
}
const int MAX_N = 1 << 17;
Matrix segmentTree[MAX_N * 2];
Matrix lazyUpdate[MAX_N * 2];
void applyLazy(int nodeIndex) {
    segmentTree[2 * nodeIndex] = multiply(segmentTree[2 * nodeIndex], lazyUpdate[nodeIndex]);
    segmentTree[2 * nodeIndex + 1] = multiply(segmentTree[2 * nodeIndex + 1], lazyUpdate[nodeIndex]);
    lazyUpdate[2 * nodeIndex] = multiply(lazyUpdate[2 * nodeIndex], lazyUpdate[nodeIndex]);
    lazyUpdate[2 * nodeIndex + 1] = multiply(lazyUpdate[2 * nodeIndex + 1], lazyUpdate[nodeIndex]);
    lazyUpdate[nodeIndex] = Matrix(1);
}
void updateRange(int nodeIndex, int leftBound, int rightBound, int queryLeft, int queryRight, Matrix value) {
    if (queryLeft <= leftBound && rightBound <= queryRight) {
        lazyUpdate[nodeIndex] = multiply(lazyUpdate[nodeIndex], value);
        segmentTree[nodeIndex] = multiply(segmentTree[nodeIndex], value);
        return;
    }
    if (leftBound >= queryRight || queryLeft >= rightBound) return;
    applyLazy(nodeIndex);
    int middle = (leftBound + rightBound) / 2;
    updateRange(2 * nodeIndex, leftBound, middle, queryLeft, queryRight, value);
    updateRange(2 * nodeIndex + 1, middle, rightBound, queryLeft, queryRight, value);
    segmentTree[nodeIndex] = add(segmentTree[2 * nodeIndex], segmentTree[2 * nodeIndex + 1]);
}
Matrix querySum(int nodeIndex, int leftBound, int rightBound, int queryLeft, int queryRight) {
    if (queryLeft <= leftBound && rightBound <= queryRight) return segmentTree[nodeIndex];
    if (leftBound >= queryRight || queryLeft >= rightBound) return Matrix();
    applyLazy(nodeIndex);
    int middle = (leftBound + rightBound) / 2;
    return add(querySum(2 * nodeIndex, leftBound, middle, queryLeft, queryRight), querySum(2 * nodeIndex + 1, middle, rightBound, queryLeft, queryRight));
}
int main() {
    int arraySize, queryCount;
    cin >> arraySize >> queryCount;
    for (int i = 0; i < 2 * MAX_N; i++) lazyUpdate[i] = Matrix(1);
    for (int i = 0; i < arraySize; i++) {
        int value;
        scanf("%d", &value);
        segmentTree[i + MAX_N] = fibonacciMatrix(value);
    }
    for (int i = MAX_N - 1; i >= 0; i--) segmentTree[i] = add(segmentTree[2 * i], segmentTree[2 * i + 1]);
    for (int i = 0; i < queryCount; i++) {
        int queryType;
        scanf("%d", &queryType);
        if (queryType == 1) {
            int left, right, x;
            scanf("%d%d%d", &left, &right, &x);
            updateRange(1, 0, MAX_N, left - 1, right, fibonacciMatrix(x));
        } else {
            int left, right;
            scanf("%d%d", &left, &right);
            Matrix result = querySum(1, 0, MAX_N, left - 1, right);
            printf("%d\n", result.matrix[0][1]);
        }
    }
}
