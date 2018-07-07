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