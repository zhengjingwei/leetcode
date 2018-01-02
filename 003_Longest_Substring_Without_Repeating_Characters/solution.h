class Solution{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> char_map;
        int maxlen= 0;
        int start = -1;
        for(int i = 0; i<s.length(); i++)
        {
            if(char_map.count(s[i])!=0)
            {
                start = max(start,char_map[s[i]]);
            }
            char_map[s[i]]=i;
            maxlen = max(maxlen,i-start);
        }
        return maxlen;
    }
};
