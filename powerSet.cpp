#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int i_n;
	cout << "enter the size:";
	cin >> i_n;
	
	int a_nos[i_n];
	int i_run,x,i,u;
	cout << "enter the numbers:";
	
	for( i_run = 0; i_run < i_n; i_run++)
	{
		cin >> a_nos[i_run];
	}
	
	cout << "the power set nos: \nNULL_SET"<< endl;
	for(i_run = 1; i_run < pow(2,i_n); i_run++)
	{
		x = i_run;
		i = i_n - 1;
		cout << "set#" << i_run <<":";
		do
		{
			(x % 2) ? cout << a_nos[i] : cout<<"" ;
			i--;
			x = x / 2;
		}while(i >= 0);
		cout << endl;
	}
	
	return 0;
}
