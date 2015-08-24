#include<iostream>

#define MAX 1000 

using namespace std ; 

int lis(int arr[] , int n){
	
	int i , j , max ;
	int dp[n] ;

	//initialize the dp array
	for (i = 0 ; i <n ; i++ ) {
		dp[i]= 1 ;
	}

	//compute lis at each index
	for (i = 1 ;  i<n ; i++){
		for (j = 0 ;j<i ; j++){

			// we are looking for max value of dp[i] that can be obtained
			if (dp[i] < (dp[j] + 1)&& arr[i] > arr[j]){
				dp[i] = dp[j] + 1 ; 
			}
		}
	}

	max =  0 ; 

	for (i = 0 ; i<n ; i++){
		if (dp[i] > max)
			max = dp[i] ;
	}

return max ;
	
}


int main ()
{
	int n , arr[MAX]  , i ;   
	cin >> n ; 
	for (i = 0 ;i<n ; i++){
		cin >> arr[i] ; 	
	}
	int ans = lis (arr , n ) ;
	cout << "The answer is " << ans << endl ;
return 0 ; 
}