#include <iostream>
using namespace std;
auto main()->int
{
	int a;

	cout<<"podaj liczbe calkowita: ";
	cin>>a;
	
	for(int i=1;i<=a; ++i)
	{
		for(int j=1;j<=i;++j)
		{
			cout<<"#";
		}
		for(int j=a-1; j>=i;--j)
		{
			cout<<"-";
		}
	cout<<"\n";
	}
	for(int i=a;i>=1; --i)
	{
		for(int j=1;j<=i;++j)
		{
			cout<<"#";
		}
		for(int k=a; k>i;--k)
		{
			cout<<"-";
		}
	cout<<"\n";
	}
	
	return 0;
}
