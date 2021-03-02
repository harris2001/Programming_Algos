#include<bits/stdc++.h>

using namespace std;

int main(){

int t,n;
scanf("%d",&t);
while(t--){
    string s;
    cin>>s;
    char pin[8][3]={
        {'(','(','('},
        {'(','(',')'},
        {'(',')','('},
        {'(',')',')'},
        {')','(','('},
        {')','(',')'},
        {')',')','('},
        {')',')',')'}
    };

    bool done=false;
    for(int i=0; i<8; i++){
        int open=0,close=0;
        bool solve = true;
        string ss="";
        for(int j=0; j<s.size(); j++){
            ss+=pin[i][s[j]-'A'];
            if(pin[i][s[j]-'A']=='('){
                open++;
            }
            else{
                close++;
            }
            if(close>open || open>s.size()/2){
                //cout<<ss<<endl;
                solve=false;
                break;
            }
        }
        if(solve==true){
            printf("YES\n");
            done=true;
            break;
        }
    }
    if(done==false){
        printf("NO\n");
    }
}

return 0;
}
