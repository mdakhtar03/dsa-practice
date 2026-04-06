#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int number;
    cin>>number;
    if(number<=0){
            cout<<"No";
        }
    else if((number& (number-1)) == 0){
        cout<<" yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}