# [15. 3Sum ](https://leetcode.com/problems/3sum/description/)

Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

**Note:**

The solution set must not contain duplicate triplets.

**Example:**

```
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

 

# 思路

要求要找到所有 和等于0的三元组，要求三元组要唯一，不能有重复的三元组。

思路和 `2Sum` 的题目相似，通过固定第一个数，通过设置一个头指针和一个尾指针，分别从首部和尾部找，判断三个数之和是否为0。其中注意要跳过重复元素。



# 复杂度

$O(n^2)$

（排序$O(nlogn)$ + 双重循环$O(n^2)$）




# solution

```c++
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() ;i++){ //固定第一个数 
        	int front = i + 1;
			int back = nums.size() -1;
			int target = -nums[i]; //两个数的和 
			while(front < back){
				if(nums[front] + nums[back] < target)
					front ++;
				else if(nums[front] + nums[back] > target)
					back --;
				else {
					vector<int> turple(3,0);
					turple[0] = nums[i];
					turple[1] = nums[front];
					turple[2] = nums[back];
					ret.push_back(turple);
					while(front < back && nums[front] == turple[1]) 
						front++; //跳过重复的元素 
					while(front < back && nums[back] == turple[2]) 
						back--; //跳过重复的元素 
				}
			} 
			while(i + 1 < nums.size() && nums[i+1] == nums[i])
				i++; //跳过重复的第一个元素 
		}
		return	ret;
    }
};
```

