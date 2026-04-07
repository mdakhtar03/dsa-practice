#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<limits.h>
#include<limits>
#include <sstream>
using namespace std;
vector<int> getMinMax(vector<int> &arr) {
        vector<int> values;
        int min=INT_MAX, max=INT_MIN;
        for(int i=0; i<arr.size();i++){
            //Min case
            if(arr[i]<min){
                min=arr[i];
            }
            //max case
            if(arr[i]>max){
                max=arr[i];
            }
        }
        
        //push min
        values.push_back(min);
        values.push_back(max);
        
        return values;
    }
int main()
{
    vector<int> arr;
    string line;
    getline(cin,line);
    stringstream ss(line);
    int num;
    
    while(ss >> num){
    arr.push_back(num);
    }
    vector<int> ans = getMinMax(arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}