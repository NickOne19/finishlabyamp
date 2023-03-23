#include "My_List.h"

/* Дан текстовый файл input.txt, в котором хранятся целые числа.Создать список по принципу
очереди.Найти первую подпоследовательность,образующую арифметическую прогрессию.
Вставить в начало этой подпоследовательности количество элементов в ней.Полученную последовательнсть
записать в текстовый файл output.txt . Если искомой подпоследовательности нет,то помимо последовательности
в файл записать соотвутсвующее сообщение*/

void print_txt(LIST& list)
{
	std::ofstream print("output.txt");
	ptrNODE p = list.get_head()->next;
	if (list.empty())
		print << "no elem\n";
	while (p)
	{
		print << p->info << ' ';
		p = p->next;
	}
	/*if (!flag)
		print << "\nthere is no subsequence\n";*/
	print.close();
}

bool task(LIST& list)
{
	ptrNODE beg = nullptr;
	ptrNODE end = nullptr;
	ptrNODE l = list.get_head();
	ptrNODE p = list.get_head()->next;
	bool flag = false;
	int d = 0;
	int count = 2;

	while (p->next->next->next) // 0 5 4 10 -2 30 32 34 50 52

	{
		d = (p->next->next->info) - (p->next->info);
		if (((p->next->next->next->info) - (p->next->next->info)) == d)
		{
			count++;
			if (!beg)
			{
				beg = p; // начало

			}
			end = p->next->next;
		}
		p = p->next;
	}
	list.add_after(beg, count);
	return beg;
}

void main()
{
	bool cont = true;
	do
	{
		LIST list;
		std::ifstream file("input.txt");
		if (file)
		{
			int mode;
			std::cout << "Enter mode\n 1)stack\n 2)queue\n 3)order\n";
			std::cin >> mode;
			switch (mode)
			{
			case 1:
			{
				list.create_by_stack(file);
				break;
			}
			case 2:
			{
				list.create_by_queue(file);
				break;
			}
			case 3:
				list.create_by_order(file);
				break;
			default:
			{
				std::cout << "Wrong enter. Create by default queue\n";
				list.create_by_queue(file);
				break;
			}
			}
			file.close();
			list.print();
			task(list);
			print_txt(list);
			std::cout << "\n";
			list.print();
		}
		std::cout << "continue? (1 - Yes, 0 - No): ";
		std::cin >> cont;
	} while (cont);
	std::cin.ignore();
	std::cin.get();
}