#include <bits/stdc++.h>

using namespace std;

int n = pow(2,16);

class poli {
       protected:
         int u[9];
         
         
       public:
         int& operator [] (int k);
         int  operator [] (int k) const;

            poli(int a0 = 0, int a1 = 0, int a2 = 0, int a3 = 0,
		         int a4 = 0, int a5 = 0, int a6 = 0, int a7 = 0,
				 int a8 = 0);
				 
         poli(const poli& a);
         int a0() const { return u[0]; };
         int a1() const { return u[1]; };
         int a2() const { return u[2]; };
         int a3() const { return u[3]; };
         int a4() const { return u[4]; };
         int a5() const { return u[5]; };
         int a6() const { return u[6]; };
         int a7() const { return u[7]; };
         int a8() const { return u[8]; };

         poli& operator =  (const poli&);
        };
        
poli::poli(      int a0, int a1, int a2, int a3,
		         int a4, int a5, int a6, int a7,
				 int a8)
{
	int a[9] = {a0, a1, a2, a3, a4, a5, a6, a7, a8};
	
	for(int i = 0; i < 9; i++) if( (n-1) < a[i] ) a[i] = a[i]%n;

	
   u[0]= a[0];
   u[1]= a[1];
   u[2]= a[2];
   u[3]= a[3];
   u[4]= a[4];
   u[5]= a[5];
   u[6]= a[6];
   u[7]= a[7];
   u[8]= a[8];
}  

poli::poli(const poli& f)
{
   u[0]= f.a0();
   u[1]= f.a1();
   u[2]= f.a2();
   u[3]= f.a3();
   u[4]= f.a4();
   u[5]= f.a5();
   u[6]= f.a6();
   u[7]= f.a7();
   u[8]= f.a8();
}   

int& poli::operator [] (int k)
{
   if (k == 8)
      return u[8] = 1;
   else
      return u[k];
}

poli& poli::operator = (const poli& f)
{
   u[0] = f.a0();
   u[1] = f.a1();
   u[2] = f.a2();
   u[3] = f.a3();
   u[4] = f.a4();
   u[5] = f.a5();
   u[6] = f.a6();
   u[7] = f.a7();
   u[8] = f.a8();
   return *this;
}

int POW(int x, int k) {

	int aux = 1;

	for (int i = 0; i < k; i++)
	aux *= x;
	
	if( (n-1) < aux) aux = aux%n;

	return aux;
}

int MULT(int x, int k){
      
   int  aux = x*k;

   if((n-1) < aux) aux = aux%n;
     
	   return aux;
} 


int evalP(const poli& f, int x) {
	
	if( (n-1) < x ) x %= n;
	
	int c[9] = {f.a0(), f.a1(), f.a2(), f.a3(), f.a4(), f.a5(), f.a6(), f.a7(), f.a8()};
	unsigned int v = 0;
	
	for (int i = 0; i < 9; i++){ 
	v += MULT(c[i],POW(x, i));
	}
	
	if(  v > (n-1) ) v %=n;

	return v;
}     
        
int main() 
{
	
    poli f = poli(21234, 56847, 55004,  58836, 32331, 4274, 60882, 19908,16469);

    
    cout<<"a0 ="<<f.a0()<<endl;
    cout<<"a1 ="<<f.a1()<<endl;
    cout<<"a2 ="<<f.a2()<<endl;
    cout<<"a3 ="<<f.a3()<<endl;
    cout<<"a4 ="<<f.a4()<<endl;
    cout<<"a5 ="<<f.a5()<<endl;
    cout<<"a6 ="<<f.a6()<<endl;
    cout<<"a7 ="<<f.a7()<<endl;
    cout<<"a8 ="<<f.a8()<<endl;
    cout<<"\n"<<endl;
    	
cout<<"P(x) = ("<<f.a8()<<")x^8 + ("<<f.a7()<<")x^7 + ("<<f.a6()<<")x^6 + ("<<f.a5()<<")x^5 + ("<<f.a4()<<")x^4 + ("<<f.a3()<<")x^3 + ("<<f.a2()<<")x^2 + ("<<f.a1()<<")x + ("<<f.a0()<<")"<<endl;

	  cout<<"\n"<<endl;
	  cout<<"P( 12826 ) = "<<evalP(f,12826)<<endl;
	  cout<<"P( 44573 ) = "<<evalP(f,44573)<<endl;
	  cout<<"P( 22249 ) = "<<evalP(f,22249)<<endl;
	  cout<<"P( 17176 ) = "<<evalP(f,17176)<<endl;
	  cout<<"P( 33624 ) = "<<evalP(f,33624)<<endl;
	  cout<<"P( 15706 ) = "<<evalP(f,15706)<<endl;
	  cout<<"P( 40284 ) = "<<evalP(f,40284)<<endl;
     	  cout<<"P( 61982 ) = "<<evalP(f,61982)<<endl;
     	  cout<<"P( 48749 ) = "<<evalP(f,48749)<<endl;


    
	return EXIT_SUCCESS;
}
        
