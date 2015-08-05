#include<iostream>
#include<vector>
#include<algorithm>

#define ull unsigned long long

using namespace std;

ull solve(ull n, ull m)
{
	vector<ull> firstNumber,secondNumber;
	ull digit;
	
	while(n != 0)
	{
		digit = n % 10;
		n = n/10;
		firstNumber.push_back(digit);
	}
	while(m != 0)
	{
		digit = m % 10;
		m = m/10;
		secondNumber.push_back(digit);
	}
	
	ull numberOfDigit1 = firstNumber.size();
	ull numberOfDigit2 = secondNumber.size();
	
	if(numberOfDigit1 > numberOfDigit2)
	{
		while(secondNumber.size() != firstNumber.size())
		{
			secondNumber.push_back(0);
		}
	}
	
	if(numberOfDigit1 < numberOfDigit2)
	{
		while(secondNumber.size() != firstNumber.size())
		{
			firstNumber.push_back(0);
		}
	}
	
	int count = firstNumber.size();
	
	/*for(int i=count-1; i>=0; --i)
	{
		cout<<"First Number"<<firstNumber[i]<<'\n';
		cout<<"Second Number"<<secondNumber[i]<<'\n';
	}*/
	
	ull answer = 0;
	bool allnine = false;
	
	for(int i=count-1; i>=0; --i)
	{
		if(allnine)
		{
			answer = answer*10 +9;
		}
		else
		{
			if(firstNumber[i] + secondNumber[i] < 10)
			{
				answer = answer*10 + firstNumber[i] + secondNumber[i];
			}
			else
			{
				answer = answer*10 + 9;
				allnine = true;
			}
		}
	}
	return answer;
}

int main()
{
	int t;
	unsigned long long int n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<solve(n,m)<<'\n';
	}
	return 0;
}