class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
       int m = grid.size(),n=grid[0].size();
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

        
        if(grid[i][j]==0){
                bfs(i,j,grid,m,n);
        }
        }
       } 
       return;
    }
    void bfs(int i,int j, vector<vector<int>>& grid,int m,int n){
       queue<vector<int>> que;
       que.push({i,j,0});
        while(!que.empty()){
              int a = que.front()[0];  
              int b = que.front()[1];  
              int s = que.front()[2]+1;
              if(a-1>=0){
                int x = a-1;
                if(grid[x][b]>=1 && grid[x][b]>s){
                grid[x][b] = s;
                que.push({x,b,s});
                }
              }
              if(a+1<m){
                int x = a+1;
                if(grid[x][b]>=1 && grid[x][b]>s){
                grid[x][b] = s;
                que.push({x,b,s});
                }
              }
              if(b-1>=0){
                int x = b-1;
                if(grid[a][x]>=1 && grid[a][x]>s){
                grid[a][x] = s;
                que.push({a,x,s});
                }
              }
              if(b+1<n){
                int x = b+1;
                if(grid[a][x]>=1 && grid[a][x]>s){
                grid[a][x] = s;
                que.push({a,x,s});
                }
              }
              que.pop();
        }
        return;
    }
};
