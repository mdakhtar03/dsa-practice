class Solution {
public:
    void countNumberOfDevices(string row,vector<int>& devices){
        int count = 0;
        for(char ch:row){
            if(ch == '1'){
                count++;
            }
        }
        if(count>0)
        devices.push_back(count);
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;int beams=0;
        for(auto row:bank){
            countNumberOfDevices(row, devices);
        }
        for(int i=0;i<devices.size();i++){
            for(int j=i+1;j<devices.size();j++){
                beams = beams + devices[i]*devices[j];
                if(devices[j]==0){
                    j++;
                }
                else{
                    break;
                }
            }
        }
        return beams;
    }
};