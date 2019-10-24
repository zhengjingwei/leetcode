// DFS深度优先搜索
// 时间复杂度：O(n^2) 空间复杂度：O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()||M[0].empty()) return 0;
        vector<bool> visited(M.size(), false);
        int ret = 0;    // 块数
        // 以节点i为起始节点dfs访问
        for(int i = 0; i < M.size(); ++i){
            if(!visited[i]){
                dfs(M,visited,i);
                ++ ret;
            }
        }
        return ret; 
    }
private:
    // j代表当前被访问节点
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int j){
        if(visited[j]) return;
        visited[j] = true;  // 标记该节点被访问
        for(int k = 0; k < M.size(); ++k){
            if(j == k) continue;
            if(M[j][k] == 1 && !visited[k]) // 联通并且未被访问过
                dfs(M, visited, k);
        }
    }
};

// 并查集
// 时间复杂度：O(n^3) 空间复杂度：O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> parent(M.size(), -1);
        for(int i = 0; i < M.size(); ++ i){
            for(int j = i+1; j < M.size(); ++ j){
                if(M[i][j] == 1)
                    union_op(parent, i, j);
            }
        }
        int ret = 0;
        // 统计parent为-1的节点
        // 父节点的值没有改变过，其他的对应值都在union里改动过了。有几个父节点，就有几个圈子 。
        for(int i = 0; i<M.size(); ++i){
            if(parent[i] == -1)
                ret ++;
        }
        return ret;
    }
private:
    // 找到节点i的parent编号
    int find(vector<int>& parent, int i){
        if(parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // union操作：将x和y的parent置为同一个
    void union_op(vector<int>& parent, int x, int y){
        int xset = find(parent, x);
        int yset = find(parent, y);
        if(xset != yset)
            parent[xset] = yset;
    }
};