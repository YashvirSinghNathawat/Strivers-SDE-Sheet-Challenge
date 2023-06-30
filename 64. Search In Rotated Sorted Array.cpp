int search(int* arr, int n, int x) {
    // Write your code here.
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==x) return mid;
        if (arr[low]<=arr[mid]) {
          // Left Half
          if(x>=arr[low] and x<arr[mid])    high = mid - 1;
          else          low = mid + 1;
        }
        else{
            //Right Half
            if(x>arr[mid] and x<=arr[high])            low = mid+1;
            else        high = mid - 1;
        }
    }
    return -1;
}