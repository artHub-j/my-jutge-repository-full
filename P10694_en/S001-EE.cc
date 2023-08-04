#include<iostream>
using namespace std;

//Enunciat: Multiple de 3 o 7 amb potències parelles o 0. 

bool esCorrecte(int n){
	
	//dividir entre 3:
	bool correcte = false;
	int tres= 0, set=0;
	
	if(n%3>0 and n%7>0) return correcte = false;
	
	while(n!=1){
		
		if(n%3==0){
			n=n/3;
			tres++;
		}
		if(n%7==0){
			n=n/7;
			set++;
		}	
		
	}
	
	if(tres%2==0 and set%2==0){
		correcte = true;
	}
	
	return correcte;
}
int main(){
	
		int n;
		cout<<endl;
		while(cin>>n){
			
			if(esCorrecte(n)==true or n==1) cout<<n<<" Es un quadrat perfecte."<<endl;
			else cout<<n<<" No es un quadrat perfecte. "<<endl;
			esCorrecte(n);
		}
		
		
		
		
		
	
}

//ERRORS: 1 també es un quadrat perfecte: 3^0*7^0 = 1. 
