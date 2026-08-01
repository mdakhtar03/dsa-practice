class StockSpanner {
public:
    stack<pair<int,int>> st;
    int j=1;
    int ans = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price, j});
        }
        else{
             j=1;
            while(!st.empty() && st.top().first<= price){
                j += st.top().second;
                if(!st.empty())
                st.pop();
            }
            
            st.push({price,j});
            
        }
        return j;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */