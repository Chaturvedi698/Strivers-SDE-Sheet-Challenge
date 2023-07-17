bool isvalid(vector<int>adj[],int index,vector<int>&colors,int color){
    for(auto it : adj[index]){
        if(colors[it]==color) return false;
    }
    return true;
}

bool solve(int n , vector<int>adj[],vector<int>&color,int index,int m){
    if(index==n){
        return true;
    }
    for(int i = 1; i<=m; i++){
        if(isvalid(adj,index,color,i)){
            color[index] = i;
            if(solve( n,adj, color,index+1,  m)==true) return true;
            color[index] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>adj[n];

    for(int i  = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j])
            adj[i].push_back(j);
        }
    }
    vector<int>color(n,0);
     return solve(n,adj,color,0,m)==true?"YES":"NO";
}