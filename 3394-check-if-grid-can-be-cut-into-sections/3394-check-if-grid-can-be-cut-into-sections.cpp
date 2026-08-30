class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int row = rectangles.size();
        int column = rectangles[0].size();
        vector<vector<int>> xAxis;
        vector<vector<int>> yAxis;

        for(auto rectangle:rectangles){
            int X1 = rectangle[0];
            int X2 = rectangle[2];
            // cout<< "X1 "<< X1 << " X2 "<<X2 <<" ";
            xAxis.push_back({X1,X2});
        }

        for(auto &rectangle:rectangles){
            int Y1 = rectangle[1];
            int Y2 = rectangle[3];
            // cout<< "Y1 "<< Y1 << " Y2 "<<Y2<<" ";
            yAxis.push_back({Y1,Y2});
        }
        vector<vector<int>> xAxisInterval;
        //Merge xAxis interval
        sort(xAxis.begin(), xAxis.end());
        xAxisInterval.push_back(xAxis[0]);
        // cout<<"X ";
        // for(auto axis:xAxis){
        //     cout<<axis[0]<<" "<<axis[1]<<" ";
        // }


        for(int i=1; i<xAxis.size(); i++){
            int firstElement = xAxis[i][0];
            int secondElement = xAxis[i][1];
            
            if(firstElement<xAxisInterval.back()[1]){
                xAxisInterval.back()[1] =  max(xAxisInterval.back()[1], secondElement);
            }
            else{
                xAxisInterval.push_back({firstElement,secondElement});
            }
        }

        //Merge yAxis interval
        sort(yAxis.begin(), yAxis.end());
        vector<vector<int>> yAxisInterval;
        yAxisInterval.push_back(yAxis[0]);
        // cout<<"Y ";
        // for(auto axis:yAxis){
        //     cout<<axis[0]<<" "<<axis[1]<<" ";
        // }

        for(int i=1; i<yAxis.size(); i++){
            int firstElement = yAxis[i][0];
            int secondElement = yAxis[i][1];
            if(firstElement<yAxisInterval.back()[1]){
                yAxisInterval.back()[1] = max(yAxisInterval.back()[1],secondElement);
            }else{
                yAxisInterval.push_back({firstElement, secondElement});
            }
        }
        // cout<<"YIN ";
        // for(auto in:yAxisInterval){
        //     cout<<in[0]<<" "<< in[1]<<" ";
        // }

        // cout<<"XIN ";
        // for(auto in:xAxisInterval){
        //     cout<<in[0]<<" "<< in[1]<<" ";
        // }

        if(yAxisInterval.size()>=3 || xAxisInterval.size()>=3){
            return true;
        }
        return false;

    }
};