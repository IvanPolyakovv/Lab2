#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
int main()
{
	time_point < steady_clock,
		duration<__int64, ratio<1, 1000000000 >>>
		start, end;
	nanoseconds result;

	const int N = 100;
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 200 - 100;
	}
	cout << endl;
	cout << "Unsorted array: \n";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	start = steady_clock::now();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	cout << endl;
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "Sorted array: \n";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	cout << "The time of sort is " << result.count() << " nanoseconds\n\n";

	start = steady_clock::now();
	cout << "The max element: " << arr[N-1] << '\n';
	cout << "The min element: " << arr[0] << endl;
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of search min and max is " << result.count() << " nanoseconds\n\n";

	start = steady_clock::now();
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	cout << "The average value: " << sum / N << '\n';
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of search the average value is " << result.count() << " nanoseconds\n\n";

	cout << "Enter the number: ";
	int a;
	cin >> a;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < a)
		{
			k += 1;
		}
	}
	cout << "The number of numbers is less than entered number: " << k << endl;

	cout << "Enter the number: ";
	int b;
	cin >> b;
	k = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > b)
		{
			k += 1;
		}
	}
	cout << "The number of numbers is more than entered number: " << k << endl;

	cout << "Enter the number: ";
	int c;
	cin >> c;
	k = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == c)
		{
			k += 1;
		}
	}
	if (k == 0)
	{
		cout << "This number is not in the array." << endl;
	}
	else
		cout << "This number is in the array." << endl;

	start = steady_clock::now();
	cout << "Enter the indexes of the numbers you want to change: ";
	int ind1;
	int ind2;
	cin >> ind1 >> ind2;
	swap(arr[ind1], arr[ind2]);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of swap is " << result.count() << " nanoseconds\n\n";
}


