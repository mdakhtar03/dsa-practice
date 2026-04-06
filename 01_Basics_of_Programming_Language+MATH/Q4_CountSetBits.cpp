#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int number,count=0;
    cin>>number;
    while(number){
        if((number & 1)==1){
            count=count+1;
        }
        number=number>>1;
    }
    cout<<"Set Bits "<< count;
    return 0;
}