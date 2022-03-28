#include <iostream>
#include <random>
#include <omp.h>
#include <vector>
#include <chrono>

int scalarMul(const std::vector<int> &a, const std::vector<int> &b)
{
	int res = 0;

#pragma omp parallel for reduction(+:res)
	for (int i = 0; i < a.size(); i++)
	{
		res += a[i] * b[i];
	}
	return res;
}
void printVector(const std::vector<int> &vec)
{
	for (auto& it : vec)
		std::cout << it <<" ";
	std::cout << "\n";
}
int main()
{
	std::random_device();
	size_t size = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rg(1, 10);
	std::cout << "Enter vector size:";
	std::cin >> size;
	//auto begin = std::chrono::steady_clock::now();
	std::vector<int> a(size), b(size);
	for (size_t i = 0; i < size; ++i)
	{
		a[i] = rg(gen);
		b[i] = rg(gen);
	}
	printVector(a);
	printVector(b);
	std::cout<<"Result="<<scalarMul(a, b)<<"\t";
	/*auto end = std::chrono::steady_clock::now();;
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout <<"Time:" << elapsed_ms.count();*/
}
