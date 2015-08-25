#include<iostream>
#include<cstring> 
#include<algorithm>

#define MAX 2002
using namespace std ; 

int main ()
{
	int l1 , l2 , i , j;
	char s1[MAX] , s2[MAX] ; 

	cin >> s1 ;
	cin >> s2 ; 
	l1 = strlen(s1) ; 
	l2 = strlen(s2) ;
	
	int lcs[l1+1][l2+1] ;
	for (i = -1 ;i<l1 ;i++){
		for (j = -1 ; j<l2 ;j++){
			if (i == -1 || j == -1){
				lcs[i][j] = 0;
				cout << "in if condition loop => " << "lcs" << i << "," << j << " = " << lcs[i][j] << endl ; 
			}

			else{
				cout << "lcs[0][0]= " << lcs[0][0] << endl; 
				cout << "in else condition =>" << "lcs" << i << "," << j << " = " << lcs[i][j] << endl ; 
				cout << "lcs[0][0]= " << lcs[0][0] << endl; 
				lcs[i][j] = max (lcs[i-1][j] , lcs[i][j-1]) ; // if there is a mismatch between the string current characters 
				
				cout << "lcs[0][0]= " << lcs[0][0] << endl;
				//if the characters of the string gets matched
				if (s1[i-1] == s2[j-1]) {
					lcs[i][j] = (lcs[i-1][j-1] +1 ,lcs[i][j]) ; 
				}
			}

		}	
	}

	for (i = -1 ; i<l1 ; i++){
		for(j = -1 ; j<l2 ; j++){
			cout << lcs[i][j] << "  " ; 
			cout << "print loop " << "lcs" << i << "," << j << " = " << lcs[i][j] << endl ; 
		}
		cout << "\n" ; 
	}
	cout << "Answer = " << lcs[l1-1][l2-1] << endl; 
return 0 ;
}
