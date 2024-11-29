#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
// ������ ���������:
// � ����� �++ ������ ��������� ��� ��������� �������, ��� ������ ��� ������ ���� ����������� ������ � � �++
// � ��������� ������������� ��������� ������� ������ ������ �������, ������������� �������� ������������ ���������� � ������ ������� ��� ������������� ����������
// � ������ ��������� ���� ���� ����������� ��� ������. ��� �� ������� � ������ ��� ������ ��������� � ����� ��������
// �� �� ���� ������������� ����� ���� �������� ��������� ������
// [������ ���������](���������)->Type{����;}
//

class MyNum {
public:
	MyNum() = default;
	MyNum(int val):var(val) {}
	int var;
};

int main() {
	int var{};
	auto func = [&](int a, int b) -> void {
		var = a + b;
		};
	func(3, 0x14);
	
	std::cout << var;
	MyNum a(2), b(1);
	auto max_val = std::max(a, b,
	[](const MyNum& first, const MyNum& second) {return first.var < second.var; }
 );
	std::vector<MyNum> arrays;
	for (size_t i = 0; i < 26; i++)
	{
		arrays.push_back(26 - i);
	}
	std::cout << "\n";
	for (auto& el : arrays)
	{
		std::cout << el.var << ' ';

	}
	 
	std::sort(arrays.begin(), arrays.end(),
		[](const MyNum& first, const MyNum& second) {return first.var < second.var; }
	);

	std::cout << "\n";
	for (auto& el : arrays)
	{
		std::cout << el.var << ' ';

	}

	return 0;
}