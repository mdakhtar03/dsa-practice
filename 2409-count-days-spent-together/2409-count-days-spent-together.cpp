class Solution {
public:


    int totalDays(int &month, unordered_map<int,int> &calMonthDates){
        int daySum = 0;
        for(int i=1 ; i< month ; i++){
            daySum += calMonthDates[i];
        }
        return daySum;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        unordered_map<int,int> calMonthDates = {
            {1, 31}, {2, 28}, {3,31},{4,30}, 
            {5,31}, {6,30}, {7,31}, {8,31}, 
            {9,30}, {10,31}, {11,30}, {12,31}
        };

        int aliceArrivalMonth = stoi(arriveAlice.substr(0,2));
        int bobArrivalMonth = stoi(arriveBob.substr(0,2));
        int aliceLeaveMonth = stoi(leaveAlice.substr(0,2));;
        int bobLeaveMonth = stoi(leaveBob.substr(0,2));


        int aliceADays = totalDays(aliceArrivalMonth , calMonthDates) + stoi(arriveAlice.substr(3,2));
        int bobADays =  totalDays(bobArrivalMonth , calMonthDates) + stoi(arriveBob.substr(3,2));
        int aliceLDays  = totalDays(aliceLeaveMonth , calMonthDates) + stoi(leaveAlice.substr(3,2));
        int bobLDays =  totalDays(bobLeaveMonth , calMonthDates) + stoi(leaveBob.substr(3,2));

        
        int start = max(aliceADays, bobADays);
        int end = min(aliceLDays, bobLDays);

        if (start > end) {
            return 0;
        }

        return end - start + 1;

        
    }
};