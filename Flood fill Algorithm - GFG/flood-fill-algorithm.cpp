//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int take[5] = {0,1,0,-1,0};
void dfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &vis, int orgCol, int newCol) {
    vis[sr][sc] = newCol;
    int n=image.size();
        int m=image[0].size();
    for(int i=0; i<4; i++) {
        int nr = sr+take[i];
        int nc = sc+take[i+1];
        if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==orgCol && vis[nr][nc]!=newCol){
            dfs(nr,nc, image, vis, orgCol, newCol);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        int orgCol = image[sr][sc];
        vector<vector<int>> vis = image;
        dfs(sr, sc, image, vis, orgCol, newColor);
        return vis;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends