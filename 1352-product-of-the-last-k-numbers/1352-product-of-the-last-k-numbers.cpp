class ProductOfNumbers {
public:
    vector<unsigned int> nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
       
        if(num == 0){
            nums.clear();
        }
        else if(nums.size() == 0){

            nums.push_back(num);
        }
        else{
            nums.push_back(num*nums.back());
        }
        
    }
    
    int getProduct(int k) {
        int ans = 1;
        int n = nums.size();
        if(n==k){
            return nums.back();
        }
        if(n < k){
            return 0;
        }
        ans = (nums.back())/nums[n-k-1];
        
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */