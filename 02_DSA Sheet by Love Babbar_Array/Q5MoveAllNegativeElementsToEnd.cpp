#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;
void segregateElements(vector<int>& arr) {
        
    vector<int> positive;
    vector<int> negative;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }
    for(int i=0;i<positive.size();i++){
        arr[i]=positive[i];
    }
    int j=0;
    for(int i=positive.size();i<arr.size();i++){
        arr[i]=negative[j];j++;
    }
        
    }
int main()
{
    vector<int> arr;
    string line;
    getline(cin,line);
    stringstream ss(line);
    int num;
    while (ss>>num)
    {
        arr.push_back(num);
    }

    segregateElements(arr);
    cout<<arr.size()<<" ................."<<endl;
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}