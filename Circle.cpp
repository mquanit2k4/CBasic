#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
struct circle {
	double x;
	double y;
	double radius;
};

int intersect ( struct circle *h1 , struct circle *h2)
{
	double distance = sqrt(pow(h2->x - h1->x,2) + pow(h2->y - h1->y,2));
	double sumR = h1->radius + h2->radius;
	if ( distance < sumR )
		return 1; //Giao nhau;
	else
		return 0; //Khong giao nhau
}
int main()
{
	int n;
	cout << "Nhap so luong hinh tron: ";
	cin >> n;
	char c;
	struct circle *list = (struct circle*)malloc(n * sizeof(struct circle ));
	cout << "Ban co muon nhap thong tin cho moi hinh tron [Y]/[N]: ";
	cin >> c;
	if (c == 'Y')
	{
		for (int i = 0 ; i < n ; i++)
		{
			cout << "Nhap thong tin cho hinh tron " << i+1 << endl;
			cout << "Nhap toa do x: ";
			cin >> list[i].x;
			cout << "Nhap toa do y: ";
			cin >> list[i].y;
			cout << "Nhap ban kinh: ";
			cin >> list[i].radius;
		}
	}
	else if (c == 'N')
	{
		printf("Da tao thanh cong thong tin cho %d hinh tron\n",n);
		for (int i = 0 ; i < n ; i++)
		{
			list[i].x =  (double)rand() / RAND_MAX * 20.0 - 10.0;
			list[i].y =  (double)rand() / RAND_MAX * 20.0 - 10.0; 
			list[i].radius = (double)rand() / RAND_MAX * 5.0 + 1.0;
		}
	}
	for (int i = 0 ; i < n ; i++)
		printf("Hinh tron %d: (%.2lf, %.2lf), Ban kinh: %.2lf\n", i+1 , list[i].x , list[i].y , list[i].radius);
	bool check = 0;
	for (int i = 0 ; i < n ; i++)
	{
		printf("Hinh tron %d giao nhau voi:\n", i + 1);
		for ( int j = 0 ; j < n ; j++ )
			if (i !=j && intersect(&list[i], &list[j]) == 1)
			{
				check = 1;
				printf("Hinh tron %d\n", j + 1);
			}
		if (check == 0)
			cout << "0 hinh tron\n";
		check = 0;
	}	
	free(list);
	return 0;	
}
