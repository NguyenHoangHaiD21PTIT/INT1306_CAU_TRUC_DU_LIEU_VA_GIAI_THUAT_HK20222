def bagOfTokensScore(tokens, power):
    tokens.sort()
    n = len(tokens)
    score, max_score, left, right  = 0, 0, 0, n - 1
    while left <= right:
        if power >= tokens[left]:
            power -= tokens[left]
            score += 1
            left += 1
            max_score = max(max_score, score)
        elif score > 0:
            power += tokens[right]
            score -= 1
            right -= 1
        else: break       
    return max_score

tokens = [100,200,300,400]; power = 200 
print(bagOfTokensScore(tokens, power))
    
