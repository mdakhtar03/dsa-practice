#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    string ans="";
    int n;
    cin>>n;
    while(n){
            if((n & 1)==1){
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
            }
            n=n>>1;
        }
        int j=ans.size()-1;
        for(int i=0;i<j;j--){
            swap(ans[i],ans[j]);
            i++;
        }
        cout<<ans;
return 0;
}