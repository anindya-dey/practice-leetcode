class Solution:
    def intToRoman(self, num: int) -> str:
        m = [
            (1000, 'M'),
            (900, 'CM'),
            (500, 'D'),
            (400, 'CD'),
            (100, 'C'),
            (90, 'XC'),
            (50, 'L'),
            (40, 'XL'),
            (10, 'X'),
            (9, 'IX'),
            (5, 'V'),
            (4, 'IV'),
            (1, 'I')
        ]
        
        ans = ''
        
        for i, r in enumerate(m):
            count = num // r[0];
            
            while count > 0:
                ans += r[1]
                count -= 1
                
            num = num % r[0]
            
            if num == 0:
                break
            
        return ans
        