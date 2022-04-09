//Complexity = O(2*((n/2)^2)+n*logn)
//ISSUE N=100 => 2^100 is VERY LARGE number to be printed in C++ :(
#include<bits/stdc++.h>

using namespace std;
 long long int X[2000005],Y[2000005];
pair<long long int, vector<long long int> >solution[2000005];

//MEET IN THE MIDDLE
void calcsubarray( long long int a[],  long long int x[], long long int n, long long int c)
{
    for (long long int i=0; i<(1<<n); i++){
        vector<long long int> vi;
        long long int s = 0;
        for (long long int j=0; j<n; j++){
            if (i & (1<<j)){
                s += a[j+c];
                vi.push_back(a[j+c]);
            }
        }
        x[i] = s;
        solution[i] = make_pair(s,vi);
    }
}

//FIND CLOSEST SUM TO THE MEAN
pair<long long int,vector<long long int> > solveSubsetSum( long long int a[], long long int n, long long int S)
{
    calcsubarray(a, X, n/2, 0);
    calcsubarray(a, Y, n-n/2, n/2);

    long long int size_X = 1<<(n/2);
    long long int size_Y = 1<<(n-n/2);

    sort(Y, Y+size_Y);

    long long int maxn = 0;
    vector<long long int>vi;
    for (long long int i=0; i<size_X; i++){
        if (X[i] <= S){
            long long int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;
            if (p == size_Y || Y[p] != (S-X[i]))
                p--;

            if ((Y[p]) > maxn){
                maxn = Y[p];
                for(long long int k=0; k<n; k++){
                    if(solution[k].first==Y[p]){
                        vi = solution[k].second;
                        break;
                    }
                }
            }
        }
    }
    return make_pair(maxn,vi);
}
int main(){

long long int t;
scanf("%lld",&t);
for(long long int tt=1; tt<=t; tt++){
    long long int n;
    scanf("%lld",&n);
    long long int arr[2*n];
    //2^i numbers can cover any difference up to 2(n-1)
    printf("1 ");
    long long int total = 1;
    arr[0]=1;
    for(long long int i=1; i<n; i++){
        printf("%lld ",2<<(i-1));
        arr[i]=2<<(i-1);
        total += arr[i];
    }printf("\n");
    long long int total2 = 0;
    for(long long int i=0; i<n; i++){
        scanf("%lld",&arr[n+i]);
        total2+=arr[n+i];
    }
    pair<long long int,vector<long long int> > ans = solveSubsetSum(arr,2*n,total2/2);

    long long int smallest_diff = abs(ans.first-(total2-ans.first));
    long long int set1 = (smallest_diff+total)/2;
    long long int countt = 0;
    long long int set2[n];
    //printf("Case #%lld: ",tt);
    for(long long int i=0; i<ans.second.size(); i++){
        printf("%lld ",ans.second[i]);
    }
    //COMPLETE THE LIST WITH THE COMBINATION OF NUMBERS SUMMING INTO THE DIFFERENCE
    for(long long int i=n-1; i>=0; i--){
        long long int k = max(2<<(i-1),1);
        if(k <= set1){
            set1-=k;
            printf("%lld ",arr[i]);
        }
    }
    printf("\n");
}

return 0;
}

