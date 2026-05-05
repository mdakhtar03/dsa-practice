class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;int prevChar = chars[0];
        int count =1;
        for(int i=1;i<chars.size();i++){
            if(chars[i]==prevChar){
                ++count;
            }
            else{
                chars[index]=prevChar;
                index++;
                if(count>1){
                    int start=index;
                    while(count){
                        chars[index] = (count%10) + '0';
                        index++;
                        count=count/10;
                    }
                    reverse(chars.begin()+start,chars.begin()+index);
                }
                count=1;
                prevChar=chars[i];
            }
            
        }
        chars[index]=prevChar;
        index++;
        if(count>1){
                int start =index;
            while(count){
                        chars[index] = (count%10) + '0';
                        index++;
                        count=count/10;
                    }
            reverse(chars.begin()+start,chars.begin()+index);

        }
       
    return index;
    }
};