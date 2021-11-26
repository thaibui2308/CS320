#include "fraction.h"

int main()
{
	 Fraction f1, f2;					// 0/1
	 Fraction f3(1,-7);					// -1/7
	 Fraction f5, f6, f7, f8;			// Default constructor
	 f6=f3;								// Overloaded assignment operator

	//Arithmetic operators
	f7=f1+f3;
	f8=f2-f3;
	f3=f1*f7;
	f5=f6/f3;
	f2=f1+3;

	f1+=f5; 
	f6-=f7; 
	f8*=f1; 
	f8/=f2;

	// Realtional operators
	cout<<(f2==f3)<<endl;
	cout<<(f3!=f1)<<endl;
	cout<<(f2>=f5)<<endl;
	cout<<(f2>f5)<<endl;
	cout<<(f5<=f3)<<endl;
	cout<<(f5<f3)<<endl;

	float f=f3.getFloat();	
	cout << f << endl;		

	//Divison by zero
	try
	{
		Fraction f(3,0);
		cout << f;
	}
	catch(exception& e)
	{
		cout << e.what() << '\n';
	}

	try
	{
		Fraction f1(3,2);
		Fraction f2;
		cout << f1/f2;
	}
	catch(exception& e)
	{
		cout << e.what() << '\n';
	}

	return 0;
}