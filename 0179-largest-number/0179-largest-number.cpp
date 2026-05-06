class Solution {
public:
    static bool myComp(string a,string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        for(auto num:nums){
            numbers.push_back(to_string(num));
        }
        sort(numbers.begin(),numbers.end(), myComp);
        if(numbers[0] == "0"){
            return "0";
        }
        string ans;
        for(auto ch:numbers){
            ans=ans+ch;
        }
        return ans;
    }
};