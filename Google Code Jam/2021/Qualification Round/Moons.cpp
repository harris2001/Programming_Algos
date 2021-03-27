#include<bits/stdc++.h>

using namespace std;

int main(){

        int t;
        scanf("%d",&t);
        int cost;
        string s;
        for(int tt=1; tt<=t; tt++){
                cost=0;
                int cj,jc;
                scanf("%d%d",&cj,&jc);
                cin>>s;
                //cout<<s;
                char prev=s[0];
                char curr;
                for(int i=1; i<s.size(); i++){
                        curr=s[i];
                        //cout<<"("<<prev<<" "<<curr<<")"<<endl;
                        if(prev==curr){continue;}
                        if(prev=='C'&&curr=='J'){cost+=cj;prev=s[i];continue;}
                        if(prev=='J'&&curr=='C'){cost+=jc;prev=s[i];continue;}
                        if(prev=='?'){
                                if(curr=='C' &&jc<0){cost+=jc;}
                                else if(curr=='J' &&cj<0){cost+=cj;}
                        }
                        if(s[i]!='?'){prev=curr;continue;}
                        while(s[i]=='?'){
                                if(i==s.size()-1){break;}
                                i++;
                        }
                        if(prev==s[i]&&min(cj,jc)<0){cost+=min(cj,jc);cout<<"cost:"<<cost<<endl;}
                        else if(prev==s[i] or s[i]=='?' or prev=='?'){continue;}
                        else if(prev=='C'){
                                cost+=cj;
                        }
                        else{
                                cost+=jc;
                        }
                        //cout<<"cost: "<<cost<<endl;
                        prev=s[i];

                }
                printf("Case #%d: %d\n",tt,cost);
        }
        return 0;
}⏎
