class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> st;
        for(vector<int> &i:edges){
            st.insert(i[0]);
            st.insert(i[1]);
        }
        int n = st.size();
       vector<int> djs(n+1,-1); 
       for(vector<int> &i:edges){
        int p0 = find(i[0], djs);
        int p1 = find(i[1], djs);
        if(p0==p1) return i;
        djs[p0] += djs[p1];
        djs[p1] = p0;
       }
       return edges[0];
    }

    int find(int i, vector<int>& djs){
        vector<int> child;
        while(djs[i]>=0){
            child.push_back(i);
            i = djs[i];
        }
        for(int j: child){
            djs[j] = i;
        }
        return i;
    }
};
