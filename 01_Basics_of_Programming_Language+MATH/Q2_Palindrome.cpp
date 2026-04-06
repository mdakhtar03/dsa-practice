#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int main()
{   
    int num,reverse=0,digit=0;
    cin>>num;
    int copy=num;
    while(copy){
        digit=copy%10;
        reverse=reverse*10+digit;
        copy=copy/10;
    }
    if(reverse == num){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}