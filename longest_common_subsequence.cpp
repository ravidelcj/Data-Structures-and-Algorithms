#include<iostream>
#include<algorithm>
#include<cstring>

#define MAX 1002

using namespace std ;

int main ()
{
        int lena , lenb , i , j ; 
        char a[MAX] , b[MAX] ; 
        
        cin>> a ; 
        cin >> b ; 
        cout << a <<" " << b; 


        lena = strlen(a) ; 
        lenb = strlen(b) ;

        int lcs[lena][lenb] ;  

        for (i = 0 ;i<=lena ; i++) {
                for (j = 0 ; j<=lenb ; j++){
			
                        if (i == 0 || j == 0){
                                lcs[i][j] = 0 ;
                        }
                        else {
                                cout << "In else construct ";
                                cout << lcs[i-1][j] << "  "<< lcs[i][j-1] << endl;
                                lcs[i][j] = max(lcs[i][j-1] ,lcs[i-1][j]) ; 
                                cout <<lcs[i][j]  << endl ; 
				cout << a[i-1] <<"  "<< b[i-1] << endl;
                                if (a[i-1] == b[i-1]){
                                        lcs[i][j] = max (lcs[i-1][j-1] +1 , lcs[i][j]) ;
                                }
                                cout << lcs[i][j] << endl ;
                                       
                        }
                }
        }

	cout << "ans = " << lcs[i][j] << "\n" ;

return 0 ; 
}
