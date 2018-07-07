# [16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/description/)

Given an array `nums` of *n* integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

**Example:**

```
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

 

# 思路

与3Sum题目类似，通过固定第一个数，通过设置一个头指针和一个尾指针，分别从首部和尾部找，判断三个数之和与target的差值。



# 复杂度

$O(n^2)$

（排序$O(nlogn)$ + 双重循环$O(n^2)$）




# solution

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(),nums.end());
        int ret = nums[1] + nums[2] + nums[3];
        int sum ; 
        for(int i = 0 ; i < nums.size() ; i++){
        	int front = i + 1;
        	int back = nums.size() - 1;       	
        	
			while(front < back ){
				sum = nums[i] + nums[front] + nums[back] ;
				ret = abs(sum - target) < abs(ret - target) ? sum : ret;
				if(sum == target) return sum;
				else if(sum > target)
					back --;
				else
					front ++;
			}	
		}
		return ret;
    }
};
```

