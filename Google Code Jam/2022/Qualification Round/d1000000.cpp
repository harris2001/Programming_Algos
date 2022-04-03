#include<bits/stdc++.h>

using namespace std;

int main(){
	//Defining and reading testcases
	int t;
	scanf("%d",&t);
	//For every testacase
	for (int tt=1; tt<=t; tt++){
		//Read the size of the array
		int n;
		scanf("%d",&n);
		//Create an empty array of size n
		int S[n];
		//Fill the array from the input
		for(int i=0; i<n; i++){
			scanf("%d",&S[i]);
		}
		//Sort the array in increasing order
		sort(S,S+n);
		//Keep track of the maximum sequence we can form
		int ans = 1;
		for(int i=1; i<n; i++){
			//If the dice has less sides than what the accumulated sum is at the moment we can't
			//pick a number greater than ans and therefore ans is our maximum possible solution 
			//so far
			//	Example:
			//	1 2 3 4 4 4 10 10
			//	      ^
			//	max sequence until here is 4
			//
			//	The next 4s are useless since any side has a number less than 4 (which we have already
			//	selected so we disregard them and we continue to the next number (10)
			//
			//	Now since 10>4 (4<-ans) we can pick the number 5 which is in one of the sides of the
			//	10th dice
			//
			//	And finally 10>5 (a<-ans) we pick number 6 
			//	=> max sequence = 6
			if(S[i]<=ans){
				continue;
			}
			else{
				ans++;
			}
		}
		//Return our result
      	printf("Case #%d: %d\n",tt,ans); 
	}
return 0;
}
