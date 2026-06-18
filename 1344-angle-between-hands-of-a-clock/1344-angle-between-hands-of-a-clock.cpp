class Solution {
public:
    double angleClock(int hour, int minutes) {
      //hour hand degree

      double HR_Move = (hour*1.0)*30;
      double MM_Move = (minutes*1.0)*0.5;

      double hourDegree = HR_Move+MM_Move;

      //minute hand degree

      double minuteDegree = (minutes*1.0)*6;

      double ans = abs(hourDegree-minuteDegree);
      if(ans > 180){
        ans = abs(360-ans);
      }
      return ans;

    }
};