def minimumLength(s):
    left, right = 0, len(s) - 1
    while left < right and s[left] == s[right]:
        char = s[left]
        while left <= right and s[left] == char: left += 1
        while right >= left and s[right] == char: right -= 1
    return right - left + 1
print(minimumLength("aabccabba"))