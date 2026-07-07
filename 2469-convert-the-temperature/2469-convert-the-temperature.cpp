class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kevlin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;
        return {kevlin,fahrenheit};
    }
};