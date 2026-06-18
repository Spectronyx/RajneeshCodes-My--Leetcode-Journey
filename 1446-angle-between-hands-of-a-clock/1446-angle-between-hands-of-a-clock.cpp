class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 60 mins = 360 degrees; 1 min = 6 degress;
        double angleByMin = 6*minutes;
        // 12 hrs = 360 degrees; 1 hr = 30 degrees;
        // 60 mins = 30 degrees; 1 min = 1/2 degrees;

        double angleByHour = hour*30+minutes*(0.5);

        double ans = abs(angleByHour-angleByMin);
        return min(ans,360-ans);
    }
};