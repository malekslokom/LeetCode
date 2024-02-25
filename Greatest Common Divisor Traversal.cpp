# class Solution(object):
    
#     def canTraverseAllPairs(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: bool
#         """
#         def pgcd(a,b):
#             """pgcd(a,b): calcul du 'Plus Grand Commun Diviseur' entre les 2 nombres   entiers a et b"""
#             if b==0:
#                 return a
#             else:
#                 r=a%b
#                 return pgcd(b,r)
#         if len(nums)<2: return True
#         if all(i == nums[0] for i in nums) and nums[0]>1: return True
#         visites=[False]*len(nums)
#         graph = defaultdict(list)
#         for i in range(len(nums)):
#             graph[i]=[]
#             if nums[i] in nums[:i]:
#                 graph[i] = graph[nums.index(nums[i])]

#             else:
#                 for j in range(len(nums)):
#                     if (i!=j):
#                         if (pgcd(nums[i],nums[j])>1):
#                             graph[i].append(j)
#             if (len(graph[i])==0): return False
#         n=len(nums)-1
#         file = [n]
#         print(graph)
#         while file:
#             # supprimer le sommet supérieur de la pile et marqué comme visité
#             courant = file.pop(0)
#             visites[courant] = True
    
#             # visiter les sommets adjacents
#             for i in graph[courant]:
#                 # s'il existe et qu'un bord entre u et i et
#                 # le sommet i n'est pas encore visité
#                 if visites[i] == False:
#                     # ajouter i à la file marqué comme visité
#                     file.append(i)
#                     visites[i] = True
#             print(visites)
#             if sum(visites) == len(visites):
#                 return True 
    
#         return False

# You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

# Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

# Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

 

# Example 1:

# Input: nums = [2,3,6]
# Output: true
# Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
# To go from index 0 to index 1, we can use the sequence of traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1.
# To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.
# Example 2:

# Input: nums = [3,9,5]
# Output: false
# Explanation: No sequence of traversals can take us from index 0 to index 2 in this example. So, we return false.
# Example 3:

# Input: nums = [4,3,12,8]
# Output: true
# Explanation: There are 6 possible pairs of indices to traverse between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals exists for each pair, so we return true.
 

# Constraints:

# 1 <= nums.length <= 105
# 1 <= nums[i] <= 105

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        for (auto num : nums)
            if (num == 1)
                return false;
        
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> factors(maxValue+1, 0);
        for (int d = 2; d <= maxValue; ++d) {
            if (factors[d])
                continue;
            for (int f = d; f <= maxValue; f += d) {
                factors[f] = d;
            }
        }

        vector<int> groups(maxValue * 2 + 1, 0);
        for (int i = 1; i < groups.size(); ++i) {
            groups[i] = i;
        }
        for (auto num : nums) {
            int d = num;
            while (d > 1) {
                int factor = factors[d];
                int f_i = factor + maxValue;
                if (find(num, groups) != find(f_i, groups)) {
                    merge(find(num, groups), find(f_i, groups), groups);
                }
                while (d % factor == 0) {
                    d /= factor;
                }
            }
        }
        int g = find(nums[0], groups);
        for (auto num : nums) {
            if (g != find(num, groups))
                return false;
        }
        return true;
    }
    int find(int a, vector<int>& g) {
        return g[a] == a ? a : g[a] = find(g[a], g);
    }
    void merge(int a, int b, vector<int>& g) {
        g[a] = b;
    }
};