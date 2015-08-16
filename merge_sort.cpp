#include<iostream>
#include<algorithm>

using namespace std; 

#define MAX 1000


void merge(int a[] , int p , int q ,int r){
	
	int n1 = q-p+1 , n2 = r - q ; 	
	int left [n1+1] , right[n2+1] ;  
	
	int i , j , k ; //counters
	
	k = p ; 
	for (i = 0 ; i<n1 ; i++){
		left[i] = a[k] ; 
		k++ ;
	}

	for(j = 0 ; j<n2 ; j++){
		right[j] = a[k] ; 
		k++ ;
	}
	left [n1] = 65536; //its left[n1] = infinity 
	right[n2] = 65536;  // its right[n2] = infinity


	for (k=p,i=0,j=0 ; k<=r ; k++ ){
		if(left[i]<right[j]){
			a[k] = left[i];
			i++ ; 
		}
		else{
			a[k] =  right[j] ;
			j++ ; 
		}
	}
}


void merge_sort(int a [] , int p , int r){
	int  q ;
	
	if (p <r){
		q = (p+r)/2 ;
		merge_sort(a , p , q) ; 
		merge_sort(a , q+1 , r) ; 
		merge(a , p , q , r) ;
	}
}

int main ()
{
	int a [100] , i , n    ;
	cin >> n ;
	for (i =0 ; i<n ; i++){
		cin >> a[i] ;
	}	
	merge_sort(a , 0 , n-1) ; 

	for(i = 0 ; i< n ; i++)
		cout <<a[i]<<" "; 
return 0 ; 
}

