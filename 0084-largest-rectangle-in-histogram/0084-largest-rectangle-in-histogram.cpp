class Solution {
public:
    //First Smaller Element 
     void nextSmallerElement(vector<int>& heights,vector<int> &firstSE){
        int n = heights.size()-1;
        stack<int> st;
        for(int i=n;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
               firstSE[i] = n+1;
               st.push(i);
            }
            else{
                firstSE[i] = st.top();
                st.push(i);
            }
        }
    }

    void prevSmallerElement(vector<int>& heights, vector<int>& prevSE){
        int n = heights.size()-1;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                prevSE[i] = -1;
                st.push(i);
            }
            else{
                prevSE[i] = st.top();
                st.push(i);
            }
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> firstSE = heights;
        vector<int> prevSE = heights;
        nextSmallerElement(heights,firstSE);
        prevSmallerElement(heights,prevSE);
        int Maxarea = INT_MIN ;
        for(int i=0;i<heights.size();i++){
            int height = heights[i];
            int width = firstSE[i] - prevSE[i] - 1;
            Maxarea = max(Maxarea ,width*height);
        }
        return Maxarea;
    }
};