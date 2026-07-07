class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int delayedArrival = arrivalTime+delayedTime;
        return delayedArrival%24;
    }
};