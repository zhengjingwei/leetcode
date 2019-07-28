class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret; 
        int l = 0, h = numbers.size() -1;
        while( l < h){
            if(numbers[l] + numbers[h] < target)
                ++l;
            else if(numbers[l] + numbers[h] > target)
                --h;
            else{
                ret.push_back(l+1);
                ret.push_back(h+1);
                break;
            }
        }
        return ret;
    }
};