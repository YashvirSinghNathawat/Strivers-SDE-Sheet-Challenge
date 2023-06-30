double multiply(int m,int n){
  double res = 1;
  for(int i=1;i<=n;i++){
    res = res*1ll*m;
  }
  return res;
}
int NthRoot(int n, int m) {
  // Write your code here.
  double s = 1;
  double e = m;
  double eps = 1e-6;
  while((e-s)>eps){
    double mid = (s + e)/2.0;
    double res = multiply(mid,n);
    if(res==m) return mid;
    if(res<m) s=mid;
    else  e=mid;
  }
  return -1;
}