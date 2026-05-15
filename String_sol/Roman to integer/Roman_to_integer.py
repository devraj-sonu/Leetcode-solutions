class Solution:
    def romanToInt(self, s: str) -> int:
        val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        sym = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]

        total = 0
        i = 0
        for i in range(len(sym)):
            while s.startswith[sym[i]]:
                val += val[i]
                s = s[len(sym[i]):]
            i += 1
        return total