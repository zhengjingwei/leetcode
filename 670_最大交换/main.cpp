class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        // 从前往后遍历，遇到的第一个交换是最大交换
        for(int i = 0; i < s.size() - 1; i++){
            int index = i;
            for(int j = i+1; j < s.size(); j++){
                if(s[j] >= s[index]) // 此处不能为> 要尽可能将后面的数交换到前面
                    index = j;
            }
            // 存在更大元素
            if (index != i && s[index]!= s[i]){
                swap(s[i], s[index]);
                break;
            }
        }
        
        return stoi(s);
    }
};


class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string s_sort = s;
        sort(s_sort.begin(), s_sort.end(),greater<char>());
        // 从前往后遍历，遇到的第一个交换是最大交换
        for(int i = 0; i < s.size()-1 ; i++){
            if (s_sort[i] == s[i])
                continue;

            // 找到该数字
            char c = s_sort[i];
            int j = s.size() -1;
            while(j> i){
                if(c == s[j])
                    break;
                --j;
            }
            swap(s[i], s[j]);
            break;
        }

        return stoi(s);
    }
};