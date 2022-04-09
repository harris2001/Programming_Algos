#include<bits/stdc++.h>

using namespace std;

int main(){

int t;
scanf("%d",&t);
for(int tt=1; tt<=t; tt++){
    string s;
    cin>>s;
    string ans = "";
    bool diff = false;
    stack<int> st;
    st.push(s[0]);
    for(int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]){
            st.push(s[i]);
        }
        else if(s[i]<s[i+1]){
            while(!st.empty()){
                ans+=s[i];
                st.pop();
            }
            st.push(s[i]);
        }
        else{
            while(!st.empty()){
                st.pop();
            }
            st.push(s[i]);
        }
        if(s[i]!=s[i+1]){
            diff=true;
        }
        ans+=s[i];
    }
    ans+=s[s.size()-1];
    if(!diff){
        ans=s;
    }
    bool ok = false;
    for(int i=0; i<s.size(); i++){
        if(ans[i]<s[i]){
            ok = true;
            break;
        }
    }
    if(!ok){
        ans = s;
    }

    printf("Case #%d: ",tt);
    cout<<ans<<endl;
}

return 0;
}
