#include <bits/stdc++.h>
//Segment tree + lazy update + mul matrix

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = 1.01e9;
const dbl eps = 1e-9;


const int mod = 1e9 + 7;

struct mat
{
    int a[2][2];
    mat()
    {
        memset(a, 0, sizeof a);
    }
    mat(int x)
    {
        memset(a, 0, sizeof a);
        a[0][0] = a[1][1] = x;
    }
};

inline mat operator * (mat A, mat B)
{
    mat C;
    forn(i, 2) forn(j, 2) forn(k, 2) C.a[i][j] = (C.a[i][j] + A.a[i][k] * (ll)B.a[k][j]) % mod;
    return C;
}
inline mat operator + (mat A, mat B)
{
    mat C;
    forn(i, 2) forn(j, 2) C.a[i][j] = (A.a[i][j] + B.a[i][j]) % mod;
    return C;
}

inline mat mpow(mat A, ll b)
{
    mat R(1);
    while (b)
    {
        if (b & 1) R = R * A;
        A = A * A;
        b >>= 1;
    }
    return R;
}

inline mat fib(ll b)
{
    mat A;
    A.a[0][0] = 1;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    return mpow(A, b);
}

const int N = 1 << 17;

mat t[N * 2];
mat s[N * 2];

void push(int x)
{
    t[2 * x] = t[2 * x] * t[x];
    t[2 * x + 1] = t[2 * x + 1] * t[x];
    s[2 * x] = s[2 * x] * t[x];
    s[2 * x + 1] = s[2 * x + 1] * t[x];
    t[x] = mat(1);
}

void upd(int x, int l, int r, int lq, int rq, mat val)
{
    if (lq <= l && r <= rq)
    {
        t[x] = t[x] * val;
        s[x] = s[x] * val;
        return;
    }
    if (l >= rq || lq >= r) return;
    push(x);
    int m = (l + r) >> 1;
    upd(2 * x, l, m, lq, rq, val);
    upd(2 * x + 1, m, r, lq, rq, val);
    s[x] = s[2 * x] + s[2 * x + 1];
}

mat sum(int x, int l, int r, int lq, int rq)
{
    if (lq <= l && r <= rq) return s[x];
    if (l >= rq || lq >= r) return mat();
    push(x);
    int m = (l + r) >> 1;
    return sum(2 * x, l, m, lq, rq) + sum(2 * x + 1, m, r, lq, rq);
}

int main()
{
    int n, m;
    cin>>n>>m;
    forn(i, 2 * N) t[i] = mat(1);
    forn(i, n)
    {
        int x;
        scanf("%d", &x);
        s[i + N] = fib(x);
    }
    for (int i = N - 1; i >= 0; --i) s[i] = s[2 * i] + s[2 * i + 1];
    forn(i, m)
    {
        int tp;
        scanf("%d", &tp);
        if (tp == 1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            upd(1, 0, N, l - 1, r, fib(x));
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            mat R = sum(1, 0, N, l - 1, r);
            printf("%d\n", R.a[0][1]);
        }
    }

    return 0;
}
