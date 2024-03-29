//CONSECUTIVE SMALLER OR EQUAL TO IT BEFORE THE PARTICULAR DAY(COUNT)====NEAREST GREATER ELMNT TO LEFT MEIN STOP KRNA H 
//COUNT OF A PARTICULAR DAY IS CURRENTINDEX-NGL INDEX + 1



class StockSpanner {
private:
    //FIRST PREVIOUS GREATER ELEMENT IS RETURNED IN HERE 
    stack< pair<int,int> > s;//STACK FORMED AS A PAIR WITH FIRST POINTING TO THE PRICE AND SECOND POINTING TO THE INDEX LOCATION
    int currentIndex;
public:
    StockSpanner() {
        currentIndex = 0;
    }//CURRENTINDEX INITILASED 0 GLOBAL INITILAISTION AT THIS SPOT
    
    int next(int price) {
        
        while(!s.empty() && s.top().first <= price){s.pop();}//REMOVE THE SMALLER ELEMENT PAIR AFTER COMPARING PRICE IF SMALLER THEN DELETE
        
        int width = s.empty() ? currentIndex+1 : currentIndex - s.top().second;//FOR 70 CI IS 3 AND TOP.SECOND IS 1==2
        //WIDTH IS THE ANSWER TO BE RETURNED IF EMPTY THEN CI+1 ELSE THE DIFFERENCE IS RETURN WHICH IS CURRENT-S.TOP() MEANS THE DISTANCE BETWEEN THE CURRENT ELEMENT AND THE FIRST PREVIOUS GREATER ELEMENT
        s.push({price,currentIndex});//PUSH IT IN THE STACK //100 - 0,80-1,70-3
        ++currentIndex;//INCREMENT IN CI FOR NEXT ITEM
        return width;//HAR EK ELEMENT KA INDIVUAL RETURN KR RHA H 
    }
};

https://leetcode.com/problems/online-stock-span/


M2:
NGL FIND OUT WITH ELMNT AND INDEX
int n=arr.size();
stack<pair<int,int>>st;//{ELMNT AND INDEX}
vector<int> ans;
for(int i=0;i<n;i++){
  if(st.size()==0){
    ans.pb(-1);
  }
  else if(st.size()>0 && st.top().first>=arr[i]){
    ans.pb(st.top().second);
  }
  else if(st.size()>0 && st.top().first<arr[i]){
    while(st.size()>0 && st.top().first<arr[i])st.pop();
    if(st.size()==0)ans.pb(-1);
    else ans.pb(st.top().second);
  }
  st.push({i,arr[i]});
}
//ANSWER STORES THE NGL INDEX 
for(int i=0;i<n;i++){
v[i]=i-v[i];
}
//INDEX -NGL INDEX COUNT HOGA NO OF DAYS CONSECUTIVE JOH BEFORE PEHLE SMALLER HOGA 
return v;
//reverse(ans.begin(),ans.end());
