//main.cpp
#include "functions.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	//학생 수 입력
	int studentCount = readNumber("Enter number of students: ");

	while (studentCount <= 0)
	{// positive number 입력
		cout << "Please enter a positive number of students." << endl;
		studentCount = readNumber("Enter number of students: ");
	}

	//학생 전체 정보 저장할 vector
	vector<StudentInfo> students;

	//학생 수만큼 반복 입력
	for (int i = 0; i != studentCount; i++)
	{
		StudentInfo student;
		readStudent(student, i + 1);
		students.push_back(student);
	}

	printSummary(students); //입력 순서대로 출력
	printSortedSummary(students); // 이름순 정렬
	printTopStudent(students); // 최고 평균 점수 학생 출력

	return 0;
}
