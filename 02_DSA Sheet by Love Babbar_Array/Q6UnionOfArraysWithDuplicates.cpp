#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<sstream>
using namespace std;
 vector<int> findUnion(vector<int> &a, vector<int> &b){
    set<int> s;
    for(auto x:a){
        s.insert(x);
    }
    for(auto x:b){
        s.insert(x);
    }
    return vector<int>(s.begin(), s.end());
 }
int main()
{
    string line1, line2;
vector<int> a, b;

// input for a
getline(cin, line1);
stringstream ss1(line1);

int num;
while(ss1 >> num){
    a.push_back(num);
}

// input for b
getline(cin, line2);
stringstream ss2(line2);

while(ss2 >> num){
    b.push_back(num);
}

 vector<int> ans= findUnion(a,b);
    for(const auto output:ans){
        cout<<output<<" ";
    }
    return 0;
}