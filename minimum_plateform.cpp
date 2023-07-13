int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1, j = 0;
    int ans = 1, plateform = 1;
    while(i<n and j<n){
        if(at[i]<=dt[j]){
            i++;
            plateform++;
        }
        else{
            j++;
            plateform--;
        }
        ans = max(ans,plateform);
    }
    return ans;
}

