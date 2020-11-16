#include <iostream>
#include <thread>
#include <ctime>
#include <Windows.h>
using namespace std;


DWORD WINAPI myThread1(void* lpParameter)
{
	int* factorialP = new int();
	factorialP = (int*)lpParameter;
	int factorial = *factorialP;

	unsigned int time;
	long int result = 1;

	for (int i = 1; i <= factorial; i++)
	{
		time = clock();
		result = result * i;
		
		if (time % 1 == 0)
		{
			cout << "\n1) = " << result;
		}
	}
	return 0;
}

int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

DWORD WINAPI myThread2(void* lpParameter)
{
	int* fibonacci_numberP = new int();
	fibonacci_numberP = (int*)lpParameter;
	int fibonacci_number = *fibonacci_numberP;

	unsigned int time;

	time = clock();
	for (int i = 1; i <= fibonacci_number; i++)
	{
		time = clock();
		fibonacci(i);
		
		if (time % 1 == 0)
		{
			cout << "\n2) = " << fibonacci(i);
		}
	}
	return 0;
}

int thread_func()
{
	unsigned time1, time2, time3, time4, start;
	start = clock();
	long int factorial, fibonacci_number;

	cout << "Введите факториал: ";
	cin >> factorial;
	cout << "Введите число Фибоначчи: ";
	cin >> fibonacci_number;
	cout << endl;

	DWORD myThreadID1;
	DWORD myThreadID2;
	HANDLE myHandle1;
	HANDLE myHandle2;

	time1 = clock();
	myHandle1 = CreateThread(0, 0, myThread1, (void*)&factorial, 0, &myThreadID1);
	time3 = clock();
	myHandle2 = CreateThread(0, 0, myThread2, (void*)&fibonacci_number, 0, &myThreadID2);

	Sleep(20);
	TerminateThread(myHandle1, 0);
	time2 = clock();
	Sleep(60);
	TerminateThread(myHandle2, 0);
	time4 = clock();

	cout << "\n\nВремя выполнения первого потока: " << time2 - time1;
	cout << "\nВремя выполнения второго потока: " << time4 - time3;
	cout << "\nВремя выполнения всего приложения: " << time4 - start;


	cout << endl << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	thread_func();

	return 0;
}

