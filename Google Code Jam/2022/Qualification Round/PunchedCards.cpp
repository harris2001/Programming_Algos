#include<bits/stdc++.h>

using namespace std;

int main(){
    //Reading testcases                                                                               
    int t;
    scanf("%d",&t);
    //For every testcase
    for (int tt=1; tt<=t; tt++){
	//Read dimentions
        int r,c;
	scanf("%d%d",&r,&c);
	printf("Case #%d:\n",tt);
	for (int i=0; i<=2*r; i++){
		for (int j=0; j<=2*c; j++){
			//If we are at the first square print dot
			if(i<2 and j<2){
				printf(".");
			}	
			//If we are in an even row
			else if(i%2==0){
				if(j%2==0){
					//And even column
					printf("+");
				}
				else{
					//And odd column
					printf("-");
				}
			}
			else{
				//If we are in an odd row
				if(j%2==0){
					//And even column
					printf("|");
				}
				else{
					//And odd column
					printf(".");
				}
			}
		}
		cout<<endl;
	}
    }
    return 0;
}
