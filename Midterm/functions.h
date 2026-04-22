#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

struct StudentInfo
{
	std::string name;
	std::vector<int> grades;
	double average;
};

double calculateAverage(std::vector<int> grades);
int readNumber(const std::string& prompt);
void readStudent(StudentInfo& student, int studentNumber);
bool compareByName(const StudentInfo& x, const StudentInfo& y);
bool isExellent(double average);
void printSummary(const std::vector<StudentInfo>& students);
void printSortedSummary(std::vector<StudentInfo> students);
void printTopStudent(const std::vector<StudentInfo>& students);

#endif
