#include<bits/stdc++.h>

using namespace std;

int main(){
	//Reading testcases
    int t;
    scanf("%d",&t);
	//For every testcase
    for (int tt=1; tt<=t; tt++){
		int colors[3][4];
		//Read the 4 colors of each of the 3 printers
		for (int i=0; i<3; i++){
			for(int j=0; j<4; j++){
				scanf("%d",&colors[i][j]);
			}
		}
		int total = 0;
		//Keep the answer in a 4x1 array (the ammount of color to be used from every printer
		int ans[4];
		for(int i=0; i<4; i++){
			//We take the maximum amount of color all printers can print (the minimum
			//among them
			int minn = min(colors[0][i],min(colors[1][i],colors[2][i]));
			// If the total amount of color exceeds 10^6 then just add the amount needed
			// to reach 10^6
			if(total+minn>1000000){
				ans[i]=1000000-total;
			}
			else{
				//Otherwise just add the amount in the ans array
				ans[i]=minn;
			}
			total+=ans[i];
		}
		printf("Case #%d: ",tt);
		//Return Impossible if you can't have a total of 10^6 units of paint overall
		if(total<1000000){
			printf("IMPOSSIBLE\n");
			continue;
		}
		//Otherwise print the ans array
		for(int i=0; i<4; i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
    }
return 0;
}
