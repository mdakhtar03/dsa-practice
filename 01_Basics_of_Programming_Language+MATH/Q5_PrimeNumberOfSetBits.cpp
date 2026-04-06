#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
   void checkForPirme( int count, int &ans){
        if(count <= 1) return;
        for(int i=2 ; i<count; i++)
        {
            if(count%i==0)
            {
                return;
            }
            
        }
        ans = ans + 1;
    }


    void countSetBits( int number,int &ans){
        int count=0;
         while(number){
            if((number & 1) == 1){
                count++;
            }
          number=number>>1;
        }
        checkForPirme(count, ans);
        
    }
    int countPrimeSetBits(int left, int right) {
        int number=left; 
        int ans=0;
        while(number<=right){
            countSetBits(number, ans);
            number=number+1;
        }
       return ans;

    }
int main()
{
    int left, right;
    cin>>left>>right;
   int ans =  countPrimeSetBits(left,right);
   cout<<"countPrimeSetBits "<<ans;
    return 0;
}