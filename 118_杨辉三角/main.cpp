class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows < 1) return ret;
        ret.push_back({1});
        if(numRows == 1) return ret;
        ret.push_back({1,1});
        if(numRows == 2) return ret;
        for (int i = 3; i <= numRows; ++i) {
            vector<int> last = ret.back();
            vector<int> tmp = {1};
            for (int j = 1; j < last.size(); ++j)
                tmp.push_back(last[j]+last[j-1]);
            tmp.push_back(1);
            ret.push_back(tmp);
        }
        return ret;
    }
};