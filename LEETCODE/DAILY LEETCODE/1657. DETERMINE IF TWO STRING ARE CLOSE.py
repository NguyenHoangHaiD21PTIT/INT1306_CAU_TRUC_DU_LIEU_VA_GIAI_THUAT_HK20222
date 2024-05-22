class Solution(object):
    def closeStrings(self, word1, word2):
        s1 = set(); s2 = set()
        d1 = dict(); d2 = dict()
        
        #Xác định tập các ký tự trong 2 xâu
        for x in word1: 
            s1.add(x)
            if x in d1: d1[x]+=1
            else: d1[x] = 1
        for x in word2: 
            s2.add(x)
            if x in d2: d2[x]+=1
            else: d2[x] = 1
        l1 = list(s1); l2 = list(s2);
        l1.sort(); l2.sort();
        if(l1!=l2): return False 
        
        #Đếm tần suất
        fr1 = []; fr2 = []
        d11 = list(d1.items()); d22 = list(d2.items())
        for x in d11: fr1.append(x[1])
        for x in d22: fr2.append(x[1])
        fr1.sort(); fr2.sort();
        if(fr1==fr2): return True
        return False

solution = Solution()
print(solution.closeStrings("cabbba", "abbccc"))