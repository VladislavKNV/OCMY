#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	setlocale(LC_ALL, "ru");

	int fibonacci_number;
	cout << "Введите число Фибоначчи: ";
	cin >> fibonacci_number;
	cout << endl;

	for (int i = 1; i <= fibonacci_number; i++)
	{
		if (i == fibonacci_number)
		{
			cout << "Число Фибоначчи = " << fibonacci(i);
		}
	
	}

	cout << endl << endl;
	return 0;
}