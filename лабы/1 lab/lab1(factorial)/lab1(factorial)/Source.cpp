#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int factorial, result = 1;

	cout << "Введите факториал: ";
	cin >> factorial;


	for (int i = 1; i <= factorial; i++)
	{
		result = result * i;
	}

	cout << "\nФакториал числа " << factorial << " = " << result;

	cout << endl << endl;
	return 0;
}