//Lab_9.1.A
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Specialty { ComputerScience, Informatics, Mathematics, Physics, Work };
string specialtyStr[] = { "����'����� �����", "�����������", "�����.�� ������.","Գ���� �� ������.","������� ��������" };
struct Student
{
	string prizv;
	unsigned course;
	Specialty specialty;
	unsigned grades_in_physics;
	unsigned grades_in_mathematics;
	unsigned grades_in_informatic;
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void LineSearch_count(Student* p, const int N,int* count_3, int* count_4, int* count_5);
double LineSearch_proc(Student* p, const int N);
int main()
{
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

	int N;
	cout << "������ ������� �������� N: "; cin >> N;

	Student* p = new Student[N];
	double proc;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ʳ������ ������ � ���������������� �5�, �4�, �3�:" << endl;
		cout << " [4] - ������� ��������, �� �������� � � ������ � � ���������� ������ �4� ��� �5�:" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			int count_3;
			int count_4;
			int count_5;
			LineSearch_count(p, N, &count_3,&count_4,&count_5);
			cout << "ʳ������ ������ � ���������������� �3�:" << &count_3 << endl;
			cout << "ʳ������ ������ � ���������������� �4�:" << &count_4 << endl;
			cout << "ʳ������ ������ � ���������������� �5�:" << &count_5 << endl;
			break;
		case 4:
			proc = LineSearch_proc(p, N);
			cout << "������� ��������, �� �������� � � ������ � � ���������� ������ �4� ��� �5�:" << endl;
			cout << proc << "%" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].course;
		cout << "  ������������ (0 -����'����� ����� , 1 -�����������, 2 -�����. �� ������., 3 - Գ���� �� ������., 4 - ������� ��������): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << "  ������ � ������: "; cin >> p[i].grades_in_physics;
		cout << "  ������ � ����������: "; cin >> p[i].grades_in_mathematics;
		cout << "  ������ � �����������: "; cin >> p[i].grades_in_informatic;
	}
}
void Print(Student* p, const int N)
{
	cout << "=================================================================================================="
		<< endl;
	cout << "|�  |�������  |����|C�����������    |O����� � ������|O����� � ����������|O����� � ����������� |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1 << " ";
		cout << "|" << setw(10) << left << p[i].prizv;
		cout << "|" << setw(3) << right << p[i].course << " ";
		cout << "|" << setw(17) << left << specialtyStr[p[i].specialty];
		cout << "|" << setw(14) << right << p[i].grades_in_physics << " ";
		cout << "|" << setw(18) << right << p[i].grades_in_mathematics << " ";
		cout << "|" << setw(20) << right << p[i].grades_in_informatic << " " << " |" << endl;
	}
	cout << "=================================================================================================="
		<< endl;
	cout << endl;
}
void LineSearch_count(Student* p, const int N, int* count_3, int* count_4, int* count_5)
{
	/*int* count_3 = 0;
	int* count_4= 0;
	int* count_5= 0;*/
	for (int i = 0; i < N; i++)
	{
			if (p[i].grades_in_informatic == 3)
			{
				(*count_3)++;
			}
			else if (p[i].grades_in_informatic == 4)
			{
				(*count_4)++;
			}
			else if (p[i].grades_in_informatic == 5)
			{
				(*count_5)++;
			}
		
	}
	/*cout << "ʳ������ 3" << setw(3) << right << count_3
		<< " " << endl;
	cout << "ʳ������ 4" << setw(3) << right << count_4
		<< " " << endl;
	cout << "ʳ������ 5" << setw(3) << right << count_5
		<< " " << endl;*/
}
double LineSearch_proc(Student* p, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if ((p[i].grades_in_physics >= 4 && p[i].grades_in_physics <= 5) &&
			(p[i].grades_in_mathematics >= 4 && p[i].grades_in_mathematics <= 5))
		{
			count++;
		}
	}
	return 100.0 * count / N;
}