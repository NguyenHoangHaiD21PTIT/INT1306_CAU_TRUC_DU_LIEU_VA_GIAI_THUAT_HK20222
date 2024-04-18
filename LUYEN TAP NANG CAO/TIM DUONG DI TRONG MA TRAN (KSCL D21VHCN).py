# Hàm đọc ma trận từ input
def read_matrix(size):
    matrix = []
    for _ in range(size):
        row = list(map(int, input().split()))
        matrix.append(row)
    return matrix

# Hàm tính xâu đường đi nhỏ nhất từ đầu đến các ô còn lại
def min_path(matrix):
    size = len(matrix)
    for i in range(size):
        for j in range(size):
            if i == 0 and j != 0:
                matrix[i][j] = matrix[i][j - 1] * 2 + matrix[i][j]
            elif i != 0 and j == 0:
                matrix[i][j] = matrix[i - 1][j] * 2 + matrix[i][j]
            elif i != 0 and j != 0:
                matrix[i][j] = min(matrix[i - 1][j] * 2 + matrix[i][j], matrix[i][j - 1] * 2 + matrix[i][j])
    return matrix[size - 1][size - 1]

def main():
    hang = int(input())
    matrix = read_matrix(hang)
    result = min_path(matrix)
    print(str(oct(result))[2::])

if __name__ == "__main__":
    main()
