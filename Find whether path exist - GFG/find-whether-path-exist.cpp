//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        int sr, sc;
        
        //find source
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
            }
        }
        
        q.push({sr, sc});
        
        while(q.size() > 0) {
            pair<int, int> p = q.front();
            q.pop();
            
            int i = p.first;
            int j = p.second;
            
            // all direction
            int di[4] = {-1, 0, 1, 0};
            int dj[4] = {0, 1, 0, -1};
            
            for(int k=0; k<4; k++) {
                // direction 
                int ni = i + di[k];
                int nj = j + dj[k];
                
                if(ni >= 0 and ni < n and nj >= 0 and nj < m) {
                    
                    // destination
                    if(grid[ni][nj] == 2)
                    return true;
                    
                    // blank space
                    else if(grid[ni][nj] == 3){
                        q.push({ni, nj});
                        grid[ni][nj] = 0;
                    }   
                }
            }
        }
        
        return false;
    }
};













//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends