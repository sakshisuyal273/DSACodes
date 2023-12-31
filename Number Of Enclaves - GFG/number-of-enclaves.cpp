//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int take[5] = {0,1,0,-1,0};
  void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid){
      vis[r][c]=1;
      int n=grid.size();
        int m = grid[0].size();
      for(int i=0; i<4; i++) {
          int nr = r+take[i];
          int nc = c+take[i+1];
          if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
              dfs(nr,nc, vis, grid);
          }
      }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int cnt=0;
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0; i<n; i++) {
            if(grid[i][0]==1){
                dfs(i,0,vis, grid);
            }
            if(grid[i][m-1]==1){
                dfs(i, m-1, vis, grid);
            }
        }
        for(int i=0; i<m; i++) {
            if(grid[0][i]==1) {
                dfs(0, i, vis, grid);
            }
            if(grid[n-1][i]==1) {
                dfs(n-1, i, vis, grid);
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends