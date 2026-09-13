class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
            vector<int> djs(n,-1);    
            for(vector<int> &i:edges){
                int p0 =find(i[0],djs);
                int p1 =find(i[1],djs);
                if(p0==p1) continue;
                if(djs[p0]<djs[p1]){
                    djs[p0]+=djs[p1];
                    djs[p1] = p0;
                }else{
                    djs[p1]+=djs[p0];
                    djs[p0] = p1;
                }
            }
            int count = 0;
            for(int i: djs){
                if(i<0){
                    count++;
                }
            }
            return count;
    }
    int find(int i, vector<int> &djs){
        vector<int> childs;
        while(djs[i]>=0){
            childs.push_back(i);
            i = djs[i];
        }
        for(int j: childs){
            djs[j] = i;
        }
        return i;
    }
};