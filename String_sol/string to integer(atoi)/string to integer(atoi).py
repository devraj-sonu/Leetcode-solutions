class Solution:
    def myAtoi(self, s: str) -> int:
        # Edge case: empty string
        if len(s) == 0:
            return 0

        i = 0
        n = len(s)

        # 1. Skip leading spaces
        while i < n and s[i] == ' ':
            i += 1

        # Cut off leading spaces
        s = s[i:]
        if not s:   # If string became empty after trimming spaces
            return 0

        # 2. Handle sign
        sign = 1
        if s[0] == '-':
            sign = -1

        # Integer range (32-bit signed)
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # 3. Skip sign char if present
        i = 1 if s[0] in ['+', '-'] else 0

        ans = 0

        # 4. Read digits
        while i < len(s):
            if not s[i].isdigit():   # Stop if non-digit encountered
                break

            # Convert char to int (e.g., '7' → 7)
            digit = ord(s[i]) - ord('0')

            ans = ans * 10 + digit   # Build number

            # 5. Check for overflow/underflow
            if sign == -1 and -ans < INT_MIN:
                return INT_MIN
            if sign == 1 and ans > INT_MAX:
                return INT_MAX

            i += 1

        # 6. Apply sign and return
        return sign * ans
