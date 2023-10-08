#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc, char *argv[])
{
	if (argc != 4)
		return 1;
	else
	{
		double a = atoi(argv[1]);
		double b = atoi(argv[2]);
		double c = atoi(argv[3]);
		if (a == 0)
		{
			if (b == 0)
			{
				if( c == 0)
					cout<<"Phuong trinh co vo so nghiem";
				else
					cout<<"Phuong trinh vo nghiem";
			}
			else
			{
				if (c == 0)
					cout << "Phuong trinh co nghiem duy nhat x = 0";
				else
					cout << "Phuong trinh co nghiem x = " << -c/b;
			}
		}
		else
		{
			double delta = b*b - 4*a*c;
			if (delta < 0 )
				cout << "Phuong trinh vo nghiem";
			else if (delta == 0)
				cout << "Phuong trinh co nghiem kep x = " << -b/2*a;
			else
			{
				double x1 = (-b + sqrt(delta))/(2*a);
				double x2 = (-b - sqrt(delta))/(2*a);
				cout << "Phuong trinh co 2 nghiem phan biet x1 = " << x1 << " va x2 = " << x2;
			}
		}
	}

	return 0;	
}
