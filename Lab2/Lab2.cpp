#include <iostream>
using namespace std;
int main()
{
	const int N = 100;
int arr[N];
for (int i = 0; i < N; i++)
{
	arr[i] = rand() % 200 - 100;
}
cout << endl;

auto begin = std::chrono::steady_clock::now();
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
auto end = std::chrono::steady_clock::now();
auto elapsed_ms = std::chrono::duration_cast < std::chrono::milliseconds > (end - begin);
std::cout << "The time of sort: " << elapsed_ms.count() << " ms\n";
cout << endl;

cout << "The max element: " << arr[N-1] << '\n';
cout << "The min element: " << arr[0] << '\n';



}
