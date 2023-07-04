#include <iostream>
#include <Windows.h>
#include <string> 
#include <stack>

bool Nesting_Check(std::string&);

int main() 
{
	std::string str;
	std::cout << "Enter string: "; std::getline(std::cin, str);

	if (Nesting_Check(str))
	{
		std::cout << "\nNo problems found";
	}
	else 
	{ 
		std::cout << "\nERROR!!!";
		for (int i = 0; i < 3; i++)
		{
			Beep(500, 600);
		}
	}

	return 0;
}

bool Nesting_Check(std::string& str)
{
	std::stack<char> st1;
	std::stack<char> st2;

	for (char i : str)
	{
		if (i == '(' || i == ')' || i == '{' || i == '}' || i == '[' || i == ']')
		{
			if (st1.size() && ((st1.top() == '(' && i == ')') || (st1.top() == '{' && i == '}') || (st1.top() == '[' && i == ']')))
			{
				st1.pop();
			}
			else st1.push(i);
		}
	}

	int Size = st1.size() / 2;

	if (st1.size() % 2) return false;

	for (int i = 0; i < Size; i++)
	{
		st2.push(st1.top());
		st1.pop();
	}

	char first, second;
	while (Size)
	{
		first = st1.top();
		second = st2.top();

		if (!((first == '(' && second == ')') || (first == '{' && second == '}') || (first == '[' && second == ']'))) return false;

		st1.pop();
		st2.pop();

		Size--;
	}

	return true;
}