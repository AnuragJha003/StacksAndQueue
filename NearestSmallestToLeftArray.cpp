
int n=arr.size();
stack<int>st;
vector<int> ans;
for(int i=0;i<n;i++){
  if(st.size()==0){
    ans.pb(-1);
  }
  else if(st.size()>0 && st.top()<arr[i]){
    ans.pb(st.top());
  }
  else if(st.size()>0 && st.top()>=arr[i]){
    while(st.size()>0 && st.top()>=arr[i])st.pop();
    if(st.size()==0)ans.pb(-1);
    else ans.pb(st.top());
  }
  st.push(arr[i]);
}
//reverse(ans.begin(),ans.end());
