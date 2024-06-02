void init_sparse(vector<int>&a,vector<vector<int>>&dp){
    int n = a.size();
    for(int i=0;i<n;i++) 
        dp[i][0]=a[i];
    for(int j=1;j<30;j++)
        for(int i=0;i+(1LL<<j)-1<n;i++)
            dp[i][j]=max(dp[i][j-1],dp[i+(1LL<<(j-1))][j-1]);
}

int query(int l,int r,vector<vector<int>>&dp){
    int j=log2(r-l+1);
    return max(dp[l][j],dp[r-(1LL<<j)+1][j]);
}