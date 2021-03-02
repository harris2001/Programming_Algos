#include<bits/stdc++.h>

using namespace std;

int main(){

int t,n;
scanf("%d",&t);
while(t--){
    string s;
    cin>>s;
    //listing all the possible mappings of A,B, and C.
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
    //Try each of the above combinations
    for(int i=0; i<8; i++){
        int open=0,close=0;
        bool solve = true;
        string ss="";
        for(int j=0; j<s.size(); j++){
            //If the the current letter c(=s[j]) maps to an open parenthesis(pin[i][c-'A']), increase the number of open parenthesis
            if(pin[i][s[j]-'A']=='('){
                open++;
            }
            else{   //Otherwise increase the number of closed parenthesis
                close++;
            }
            //If the number we have more closed parenthesis than open ones, or if the number of open parenthesis are more than half the number of characters, the combination is not valid -> break
            if(close>open || open>s.size()/2){
                solve=false;
                break;
            }
        }
        //If there above condition is not met, then the combination is valid -> Print YES
        if(solve==true){
            printf("YES\n");
            done=true;
            break;
        }
    }
    //If there was no valid solution for any combination -> Print NO
    if(done==false){
        printf("NO\n");
    }
}

return 0;
}
