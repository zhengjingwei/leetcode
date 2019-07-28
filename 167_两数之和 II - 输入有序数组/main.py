class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        h = len(numbers) -1
        while l < h:
            if numbers[l] + numbers[h] < target:
                l += 1
            elif numbers[l] + numbers[h] > target:
                h -= 1
            else:
                return [l+1, h+1]
        return None