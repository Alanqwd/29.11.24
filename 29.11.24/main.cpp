#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
// ЛЯМБДА ВЫРАЖЕНИЯ:
// В ЯЗЫКЕ С++ ЛЯМБДА ВЫРАЖЕНИЯ ЭТО АНОНИМНЫЕ ФУНКЦИИ, ОНИ СЛУЖАТ ДЛЯ ОБХОДА РЯДА ОГРАНИЧЕНИЯ ЯЗЫКОВ С И С++
// В ЧАСТНОСТИ НЕВОЗМОЖНОСТЬ СОЗДАВАТЬ ФУНКЦИИ ВНУТРИ ДРУГИХ ФУНКЦИЙ, НЕВОЗМОЖНОСТЬ ПЕРЕДАЧИ НЕГЛОБАЛЬНЫХ ПЕРЕМЕННЫХ В ДРУГИЕ ФУНКЦИИ БЕЗ ИСПОЛЬЗОВАНИЯ АРГУМЕНТОВ
// У ЛЯМБДА ВЫРАЖЕНИЙ ЕСТЬ СВОЙ СОБСТВЕННЫЙ ТИП ДАННЫХ. ЭТО НЕ ФУНКЦИЯ И ДАННЫЙ ТИП НЕЛЬЗЯ УПОМИНАТЬ В ПРОГЕ НАПРЯМУЮ
// ИЗ ЗА ЭТОЙ СОБСТВЕННОСТИ ТАКИЕ ТИПЫ НАЗЫВАЮТ ВОЛДЕМОРТ ТИПАМИ
// [захват контекста](аргументы)->Type{тело;}
//

class MyNum {
public:
	MyNum() = default;
	MyNum(int val):var(val) {}
	int var;
};

void main2() {
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


}


int main() {
	int a{};
	int b{};
	int c{};

	//void EnterNum(std::string propt, int& var) {
	//  такую функцию нельзя создать внутри др функции
	//}
	
	auto func = [](std::string propt, int& var) {
		std::cout << propt;
		std::string tmp;
		std::cin >> tmp;
		bool is_correct{ true };
		for (auto& i : tmp)
		{
			is_correct = ::isdigit(i);
			if (!is_correct)break;
		}
		if (is_correct) {
            std::cin >> var;
		}
        
		};
	func("Enter first num: ", a);
	func("Enter second num: ", b);
    // лямбда выражения в качестве анонимной функции
	// можно использовать как инструмент сокращения
	// размера кодовой базы
	// в тех случаях когда блок кода сильно засорил бы
	// проект при выделении его в отдельной функции
	
	auto getResult = [&c](int a, int b) {
		c = a + b;

		};
	getResult(a, b);
	std::cout << "Result of action " << c;

	return 0;
}