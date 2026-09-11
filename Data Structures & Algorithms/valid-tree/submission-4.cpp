class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if((n-1)!=edges.size()) return false;
        if(edges.size()<=1) return true;
        unordered_map<int,vector<int>> al;
        for(vector<int> &i : edges){
            al[i[0]].push_back(i[1]);
            al[i[1]].push_back(i[0]);
        }
        set<int> visited;
        stack<pair<int,int>> stk;
        stk.push({0,-1});
        while(!stk.empty()){
            int tn = stk.top().first;
            int tp = stk.top().second;
            stk.pop();
            if(visited.count(tn)) return false;
            visited.insert(tn);
            for( int i: al[tn]){

            if(i==tp) continue;
            stk.push({i,tn});
            }
        }
        return visited.size()==n;
    }
};
