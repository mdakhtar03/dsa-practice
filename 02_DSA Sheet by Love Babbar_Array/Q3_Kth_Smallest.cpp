#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;
    int kthSmallest(vector<int> &arr, int k) {
        //sort
        sort(arr.begin(),arr.end());
        int ans;
        return ans=arr[k-1];
    }
int main()
{
    vector<int> arr;
    string line;
    getline(cin,line);
    stringstream ss(line);
    int num;
    while(ss>>num){
        arr.push_back(num);
    }
    int k=arr.back();
    arr.pop_back();
    int ans=kthSmallest(arr,k);
    cout<<ans;
return 0;
}