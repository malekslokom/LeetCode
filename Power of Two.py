import math
class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if (n > 0):
            num=math.log(n,2)
            num_str = str(num)
            decimal_index = num_str.find('.')
            if decimal_index != -1 and decimal_index + 1 < len(num_str):
                first_decimal_digit = int(num_str[decimal_index + 1:])
                if (first_decimal_digit==0):
                    return True
                return False
            else:
                return True
        else:
            return False