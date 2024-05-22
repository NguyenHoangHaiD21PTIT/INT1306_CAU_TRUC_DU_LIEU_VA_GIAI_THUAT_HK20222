class Solution:
    def findLatestTime(self, s: str) -> str:
        time = list(s)

        # Xác định giờ
        if time[0] == '?':
            if time[1] == '1' or time[1] == '0': time[0] = '1'
            elif time[1] >= '2' and time[1] <= '9': time[0] = '0'
            else:
                time[0] = '1'
                time[1] = '1'
        
        # Xác định chữ số hàng đơn vị của giờ
        if time[1] == '?':
            if time[0] == '1': time[1] = '1'
            elif time[0] == '0': time[1] = '9'
        
        # Xác định phút
        if time[3] == '?':
            if time[4] >= '0' and time[4] <= '9': time[3] = '5'
            else:
                time[3] = '5'
                time[4] = '9' 
        
        # Xác định chữ số hàng đơn vị của phút
        if time[4] == '?':
            if time[3] >= '0' and time[3] <= '5': time[4] = '9'

        return ''.join(time)

sol = Solution()
print(sol.findLatestTime("??:1?"))
print(sol.findLatestTime("0?:5?"))