class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n= grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited = grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==1) q.push({i,j});
            }
        }
        
        if(q.empty() || q.size()==n*n) return -1;
        int distance =-1;
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy]: dir){
                    int i = x+dx, j = y+dy;
                    if(i>=0 and i<n and j>=0 and j<n and visited[i][j]==0){
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};