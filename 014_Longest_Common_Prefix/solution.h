class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        int min_len = strs[0].length(); //strings' min length 
        string prefix = "";
        for(int i =0; i < min_len; i++){		
        	for(int j=0; j < strs.size(); j++){
        		if (strs[0][i] != strs[j][i])
        			return prefix;
        		if (strs[j].size()<min_len)
					min_len = strs[j].size();       		
			}
			prefix += strs[0][i];
		}
		return prefix;
    }
};