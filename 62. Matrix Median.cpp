int countSmallerThanMid(vector<int> arr,int x,int m){
    int low = 0;
    int high = m-1;
    while(low<=high){
        int mid = (low + high)>>1;
        if(arr[mid]<=x) low = mid+1;
        else    high = mid - 1;
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 1;
    int high = 1e5;
    int m = matrix[0].size();
    int n = matrix.size();
    while(low<=high){
        int mid = (low + high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++) cnt += countSmallerThanMid(matrix[i],mid,m);

        if(cnt<=(m*n)/2)    low = mid+1;
        else    high = mid - 1;
    }

    return low;
    

}