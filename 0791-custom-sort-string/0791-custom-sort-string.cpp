    static string orderCopy;
class Solution {
public:
    static bool cmp(char ch1, char ch2){
        return (orderCopy.find(ch1)<orderCopy.find(ch2));
    }

    string customSortString(string order, string s) {
        orderCopy=order;
       sort(s.begin(),s.end(),cmp); 
       return s;
    }
};