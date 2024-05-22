class Solution(object):
    def minSteps(self, s, t):
        # Check if the lengths of the strings are not equal
        if len(s) != len(t):
            return -1  # Strings are not of the same length, invalid input

        # Initialize a dictionary to store character frequencies
        freq = {}

        # Update frequencies for string s
        for char in s:
            freq[char] = freq.get(char, 0) + 1

        # Update frequencies for string t and count the common characters
        common_chars = 0
        for char in t:
            if char in freq and freq[char] > 0:
                freq[char] -= 1
                common_chars += 1

        # Return the total number of steps needed
        return len(s) - common_chars

# Example usage
solution_instance = Solution()
print(solution_instance.minSteps("bab", "aba"))        # Output: 1
print(solution_instance.minSteps("leetcode", "practice"))  # Output: 5
print(solution_instance.minSteps("anagram", "mangaar"))   # Output: 0
