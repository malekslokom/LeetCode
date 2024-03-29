# An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

# Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

# Example 1:

# Input: low = 100, high = 300
# Output: [123,234]
# Example 2:

# Input: low = 1000, high = 13000
# Output: [1234,2345,3456,4567,5678,6789,12345]
 

# Constraints:

# 10 <= low <= high <= 10^9

class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        numbers=["1","2","3","4","5","6","7","8","9"]
        output=[]
        lenLow=len(str(low))
        lenHigh=len(str(high))
        for x in range(lenLow,lenHigh+1):
            for i in range(len(numbers)):
                numberStr=""
                for j in range(x):
                    if i+j<9:
                        numberStr+=numbers[i+j]
                print(numberStr)
                if (len(numberStr)==x):
                    number=int(numberStr)
                    if number>=low and number<=high:
                        output.append(number)
        return output