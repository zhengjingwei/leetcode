class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,0);
        res[0]=1;
        for(int i=1;i<rowIndex+1;i++)
        {
            for(int j=i;j>=1;j--)
                res[j]+=res[j-1];
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        if(rowIndex < 0) return ret;
        ret.push_back(1);
        if(rowIndex == 0) return ret;
        ret.push_back(1);
        if(rowIndex == 1) return ret;
        for (int i = 2; i <= rowIndex; ++i) {
            vector<int> tmp = {1};
            for (int j = 1; j < ret.size(); ++j)
                tmp.push_back(ret[j]+ret[j-1]);
            tmp.push_back(1);
            ret = tmp;
        }
        return ret;
    }
};