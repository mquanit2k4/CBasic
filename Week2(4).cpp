#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main()
{
	string result = "";
	vector <string> article = {"The" , "A" , "One" , "Some" , "Any"};
	vector <string> noun = {"boy", "girl" , "dog" , "town" , "car"};
	vector <string> verb = {"drove" , "jumpred" , "ran" , "walked" , "skipped"};
	vector <string> preposition = {"to" , "from" , "over" , "under" ,"on"};
	vector <string> article2 = {"the" , "a" , "one" , "some" , "any" };
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(0, 4);
	
	for ( int i = 1; i <= 10 ; i++)
	{
		int ran_num1 = distribution(gen);
		int ran_num2 = distribution(gen);
		int ran_num3 = distribution(gen);
		int ran_num4 = distribution(gen);
		int ran_num5 = distribution(gen);
		int ran_num6 = distribution(gen);
		result = article[ran_num1]+" "+noun[ran_num2]+" "+verb[ran_num3]+" "+preposition[ran_num4]+" "+article2[ran_num5]+" "+noun[ran_num6]+".";
		cout<<result<<endl;
	}
	return 0;	
}
