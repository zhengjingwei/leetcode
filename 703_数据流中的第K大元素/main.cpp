class KthLargest {
    multiset<int, less<int>> m;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i = 0; i < nums.size(); ++i) {
            if(m.size()<k)
                m.insert(nums[i]);
            else if(nums[i] > *m.begin()){
                m.erase(m.begin());
                m.insert(nums[i]);
            }
        }
    }

    int add(int val) {
        if(m.size() < K)
            m.insert(val);
        else if(val > *m.begin()){
            m.erase(m.begin());
            m.insert(val);
        }
        return *m.begin();
    }
};