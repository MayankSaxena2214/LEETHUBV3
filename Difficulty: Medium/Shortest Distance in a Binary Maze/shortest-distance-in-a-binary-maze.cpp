// User function Template for C++

class Solution {
  public:
  vector<vector<int>> directions = {
    {0,1},{1,0},{-1,0},{0,-1}
};

bool isPossible(int x, int y, int n, int m, vector<vector<int>>& grid){
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1);
}

int shortestPath(vector<vector<int>> &grid, pair<int,int> source,
                 pair<int,int> destination) {
    int n = grid.size();
    int m = grid[0].size();

    int srcx = source.first, srcy = source.second;
    int destx = destination.first, desty = destination.second;

    if(grid[srcx][srcy] == 0 || grid[destx][desty] == 0){
        return -1;
    }

    queue<pair<int,int>> q;
    q.push({srcx, srcy});
    grid[srcx][srcy] = 0; // mark visited
    int count = 0;

    while(!q.empty()){
        int queueSize = q.size();
        while(queueSize--){
            auto [x,y] = q.front();
            q.pop();

            if(x == destx && y == desty) return count;

            for(auto &vec : directions){
                int newx = x + vec[0];
                int newy = y + vec[1];

                if(isPossible(newx, newy, n, m, grid)){
                    q.push({newx,newy});
                    grid[newx][newy] = 0; // mark visited
                }
            }
        }
        count++;
    }
    return -1;
}

};
