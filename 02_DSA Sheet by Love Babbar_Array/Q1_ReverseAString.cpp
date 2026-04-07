#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
   string reverseString(string& s) {
        
        int i=0,j=s.length()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
int main()
{
    string s;
    cin>>s;
    cout<<reverseString(s);
    return 0;
}