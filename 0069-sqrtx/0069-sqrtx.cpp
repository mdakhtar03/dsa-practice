class Solution {
public:
    int mySqrt(int x) {
        if (x==0)return 0;
        int s=1, e=x;double ans;
        while(s<=e){
            double mid = s+(e-s)/2;
            if(mid*mid == x){return mid;}
            else if(mid*mid > x){
                e=mid-1;
            }
            else {
                ans=mid;
                s=mid+1;
            }
        }
        int ouput = floor(ans);
        return ouput;
    }
};