#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;
   void sort012(vector<int>& arr) {
        int i=0, left=0, right=arr.size()-1;
        while(left<=right){
            if(arr[left]==0){
                swap(arr[i],arr[left]);
                ++i;
                ++left;
            }
            else if(arr[left]==2){
                swap(arr[left],arr[right]);
                --right;
            }
            else{
                ++left;
            }
        }
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
    sort012(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}