import heapq

def sum_of_unmarked(nums, queries):
    n = len(nums)
    m = len(queries)
    marked = [0] * n #marked[i] = 1 tức là số thứ i đã xét
    min_heap = []
    for i in range (len(nums)): heapq.heappush(min_heap, (nums[i], i))
    result = []
    unmarked_sum = sum(nums) #Ban đầu chưa có số nào được đánh dấu nên tổng là tổng cả mảng

    #Xét từng truy vấn
    for x in queries:
        index, k = x[0], x[1]
        #Đánh dấu phần tử thứ index nếu chưa đánh dấu
        #Chọn k phần tử nhỏ nhất chưa đánh dấu. Cùng giá trị thì chọn chỉ số
        if not marked[index]:
            marked[index] = 1
            unmarked_sum -= nums[index]

        for _ in range(k):
            while min_heap and marked[min_heap[0][1]]: heapq.heappop(min_heap)
            if not min_heap: break
            _, smallest_index = heapq.heappop(min_heap)
            marked[smallest_index] = 1
            unmarked_sum -= nums[smallest_index]

        result.append(unmarked_sum)

    return result

# Example usage:
nums1 = [1,2,2,1,2,3,1]
queries1 = [[1,2],[3,3],[4,2]]
print(sum_of_unmarked(nums1, queries1))  # Output: [8, 3, 0]

nums2 = [1,4,2,3]
queries2 = [[0,1]]
print(sum_of_unmarked(nums2, queries2))  # Output: [7]
