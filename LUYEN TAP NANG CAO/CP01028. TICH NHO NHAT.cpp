#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long min_product(long long a, long long b, long long x, long long y, long long n) {
    // Try reducing a first, then b
    long long a1 = a, b1 = b, n1 = n;
    long long reduce_a = min(n1, a1 - x);
    a1 -= reduce_a;
    n1 -= reduce_a;
    long long reduce_b = min(n1, b1 - y);
    b1 -= reduce_b;
    long long product1 = a1 * b1;
    
    // Try reducing b first, then a
    long long a2 = a, b2 = b, n2 = n;
    reduce_b = min(n2, b2 - y);
    b2 -= reduce_b;
    n2 -= reduce_b;
    long long reduce_a2 = min(n2, a2 - x);
    a2 -= reduce_a2;
    long long product2 = a2 * b2;
    
    // Return the minimum product of both approaches
    return min(product1, product2);
}

int main() {
    int T;
    cin >> T;
    vector<long long> results;
    
    for (int i = 0; i < T; ++i) {
        long long a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        results.push_back(min_product(a, b, x, y, n));
    }
    
    for (auto result : results) {
        cout << result << endl;
    }
    
    return 0;
}
