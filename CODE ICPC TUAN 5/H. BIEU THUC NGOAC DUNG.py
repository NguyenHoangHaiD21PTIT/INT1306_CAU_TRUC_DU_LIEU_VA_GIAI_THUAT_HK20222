def dp(n, k):
    f = [[[0 for _ in range(2)] for _ in range(k + 1)] for _ in range(n + 1)]
    f[n][0][0] = 1
    for x in range(n, 0, -1):
        for y in range(k, -1, -1):
            for c in range(2):
                if y > 0:
                    f[x-1][y-1][c] += f[x][y][c]
                if y < k:
                    f[x-1][y+1][(y+1 == k) | c] += f[x][y][c]
    return f[0][0][1]

def format_output(result):
    result_str = str(result)
    if len(result_str) > 10:
        print(f"{result_str[:5]}...{result_str[-5:]}")
    else:
        print(result_str)

def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        result = dp(n, k)
        format_output(result)

if __name__ == "__main__":
    main()
