//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) {
	    
	    if(X==0)
	    return 0;
	    
	    vector<int> vis(V,0);
	    queue<pair<int, int>>q;
	    q.push({0,0});
	    vis[0] = 1;
	    
	    while(q.size() > 0) {
	        pair<int, int> p = q.front();
	        q.pop();
	        
	        int curr = p.first;
	        int level = p.second;
	        
	        for(auto child : adj[curr]) {
	            
	            if(vis[child] == 0) {
	                
	                if(child == X) {
	                    return level+1;
	                }
	                
	                vis[child] = 1;
	                q.push({child, level+1});
	            }
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends