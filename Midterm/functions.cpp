//functions.cpp

#include "functions.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::string;
using std::vector;


//평균 계산
double calculateAverage(vector<int> grades)
{
	int total = 0;

	for (vector<int>::size_type i = 0; i != grades.size(); i++)
	{
		total += grades[i];
	}
	return total * 1.0 / grades.size();
}

//숫자 입력함수, 숫자 아니면 오류메시지 출력하고 입력 받아요
int readNumber(const string& prompt)
{
	int value;
	cout << prompt;

	while (!(cin >> value))
	{
		cout << "Invalid input. Please enter a number: ";
		cin.clear();

		string bad;
		cin >> bad;
	}
	return value;
}


// 학생 1명 정보 입력
void readStudent(StudentInfo& student, int studentNumber)
{
	student.grades.clear();

	cout << "\n== Student " << studentNumber << " ==" << endl;
	cout << "Enter name: ";
	cin >> student.name;

	cout << "Enter 3 scores: ";
	for (int i = 0; i != 3; ++i)
	{
		int score;
		
		while (!(cin >> score))
		{
			cout << "Invalid input. Please enter a numeric score: ";
			cin.clear();

			string bad;
			cin >> bad;
		}
		student.grades.push_back(score);
	}
	student.average = calculateAverage(student.grades);
}

// sort에서 사용할 이름 비교 함수
bool compareByName(const StudentInfo& x, const StudentInfo& y)
{
	return x.name < y.name;
}

// 평균 90 이상이면 exellent
bool isExellent(double average)
{
	return average >= 90.0;
}

// 입력한 순서대로 결과 출력
void printSummary(const vector<StudentInfo>& students)
{
	cout << "\n--- Grade Summary (Input Order) ---" << endl << endl;

	for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name << ": " << setprecision(3) << students[i].average;

		if (isExellent(students[i].average))
		{
			cout << " Exellent!!!";
		}
		cout << endl;
	}
}

//이름순 정렬, 값 복사
void printSortedSummary(vector<StudentInfo> students)
{
	sort(students.begin(), students.end(), compareByName);

	cout << "\n--- Grade Summary (Sorted by Name) ---" << endl << endl;
	for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name << ": " << setprecision(3) << students[i].average;

		if (isExellent(students[i].average))
		{
			cout << "Exellent";
		}
		cout << endl;
	}
}

// 최고평균학생 찾기
void printTopStudent(const vector<StudentInfo>& students)
{
	if (students.empty())
	{
		return;
	}
	vector<StudentInfo>::size_type top = 0;

	for (vector<StudentInfo>::size_type i = 1; i != students.size(); ++i)
	{
		if (students[i].average > students[top].average)
		{
			top = i;
		}
	}

	cout << "\nTop student: " << students[top].name
		<< " (" << setprecision(3) << students[top].average << ")";

	if (isExellent(students[top].average))
	{
		cout << " Exellent";
	}

	cout << endl;
	
}
