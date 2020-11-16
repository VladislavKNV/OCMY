#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int process_A();
int process_B();

int main()
{
	setlocale(LC_ALL, "ru");
	unsigned int time1, time2, time3, time4;
	
	time1 = clock();
	process_A();
	Sleep(2000);
	time2 = clock();
	time3 = clock();
	process_B();
	Sleep(4000);
	time4 = clock();

	cout << "Время выполнения первого процесса: " << time2 - time1 - 2000 << endl;
	cout << "Время выполнения второго процесса " << time4 - time3 - 4000 << endl;
	cout << "Время выполнения всего приложения: " << time4 - time1 - 6000 << endl;

	cout << endl;
	return 0;
}

int process_A()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(cif));
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	TCHAR buf[] = TEXT("C:\\Users\\Артем\\source\\repos\\OS labs, 3SEM\\lab1(factorial)\\Debug\\lab1(factorial).exe");

	if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
	{
		std::wcout << "Error " << '\n';
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}

int process_B()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(cif));
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	TCHAR buf[] = TEXT("D:\\OCMY\\labs\\1_lab\\lab1(fibonacci)\\Debug\\Debug\\lab1(fibonacci).exe");

	if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
	{
		std::wcout << "Error " << '\n';
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}

