#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int num,sum=0,digit=0;
    cin>>num;
    while(num){
        digit=num%10;
        sum=sum+digit;
        num=num/10;
    }
    cout<<"Sum "<<sum;
    return 0;
}