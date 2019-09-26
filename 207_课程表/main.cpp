#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
 * 题目描述：现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
 *
 * 拓扑排序是对 DAG 的顶点进行排序，使得对每一条有向边 (u, v)，
 * 均有 u（在排序记录中）比 v 先出现。亦可理解为对某点 v 而言，
 * 只有当 v 的所有源点均出现了，v 才能出现。
 */

/*
 * 本题可约化为：课程安排图是否是 有向无环图(DAG)。
 * 思路：通过拓扑排序判断此课程安排图是否是有向无环图
 * （1）入度表-BFS
 * 1.统计课程安排图中每个节点的入度，生成 入度表 indegree。
 * 2.借助一个队列 queue，将所有入度为 0 的节点入队。
 * 3.当 queue 非空时，依次将队首节点出队，在课程安排图中删除此节点 pre：
 * 4.并不是真正从邻接表中删除此节点 pre，而是将此节点对应所有邻接节点cur的入度-1，即indegree[cur]-=1
 * 5.当入度 −1后邻接节点 cur 的入度为 0，说明 cur 所有的前驱节点已经被 “删除”，此时将 cur 入队。
 * 如果整个课程表是有向无环图，则所有节点都将入队、出队一次；若课程安排图中存在环，一定有节点的入度始终不为 0。
 */
class SolutionI {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree = vector<int>(numCourses);
        for(auto v : prerequisites)
            indegree[v[0]] ++;  // 目标节点入度+1
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0)
                q.push(i);      // 利用队列将入度为0的节点入队
        }
        while (!q.empty()){
            int pre = q.front();
            q.pop();
            numCourses--;
            for(auto req: prerequisites){
                int src = req[1], dest = req[0];
                if(src != pre)   // 源节点如果不为pre
                    continue;
                if(--indegree[dest] == 0)
                    q.push(dest);
            }
        }

        return numCourses == 0;
    }
};
/*
 * DFS-通过 DFS 判断图中是否有环
 * 借助一个标志列表 flags，用于判断每个节点 i （课程）的状态：
 * 1.未被 DFS 访问：i == 0；
 * 2.已被其他节点启动的DFS访问：i == -1；
 * 3.已被当前节点启动的DFS访问：i == 1。
 *
 * 对 numCourses 个节点依次执行 DFS，判断每个节点起步 DFS 是否存在环，若存在环直接返回 False。DFS 流程；
 * 1.终止条件：
 *      当 flag[i] == -1，说明当前访问节点已被其他节点启动的 DFS 访问，无需再重复搜索，直接返回 True。
 *      当 flag[i] == 1，说明在本轮 DFS 搜索中节点 i 被第 2 次访问，即 课程安排图有环，直接返回 False。
 * 2.将当前访问节点 i 对应 flag[i] 置 1，即标记其被本轮 DFS 访问过；
 * 3.递归访问当前节点 i 的所有邻接节点 j，当发现环直接返回 False；
 * 4.当前节点所有邻接节点已被遍历，并没有发现环，则将当前节点 flag 置为 −1 并返回 True。
 * 若整个图 DFS 结束并未发现环，返回 TrueTrue。
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses,0));
        vector<int> flags(numCourses);
        for (auto v:prerequisites)
            adj[v[1]][v[0]] = 1;    // 邻接矩阵
        for (int i = 0; i < numCourses; ++i) {
            if(!dfs(adj, flags, i))
                return false;
        }
        return true;
    }

private:
    // 返回值为true表示
    bool dfs(vector<vector<int>> &adj, vector<int> &flags, int i){
        if(flags[i] == 1) return false; // 说明在本轮DFS搜索中节点i被第2次访问，即 课程安排图有环，直接返回false。
        if(flags[i] == -1) return true; // 当前节点已被其他节点启动的DFS访问，无需重复搜索
        flags[i] = 1;
        for (int j = 0; j < adj.size(); ++j) {
            if(adj[i][j] == 1 && !dfs(adj, flags, j))
                return false;
        }
        flags[i] = -1;
        return true;
    }
};

int main(){
    Solution sol;
    int n = 2;
    vector<vector<int>> nums = {{1,0}};
    cout << sol.canFinish(n, nums) <<endl;
}