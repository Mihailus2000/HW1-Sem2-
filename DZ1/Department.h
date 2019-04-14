#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>


class Department {
	struct InfoOfDisciplineBySubdepartments {
		std::string name;
		int numberOfTeachers;
	};
	struct InfoOfSubdepartment {
		std::string nameOfSubdep;
		int numOfDisciplines;
		std::vector<InfoOfDisciplineBySubdepartments> Disciplines;
	};


	struct InfoOfDisciplinesByOrganizations {
		std::string name;
		int numberOfTeachers;
	};
	struct Info {
		std::vector<InfoOfDisciplinesByOrganizations> Disciplines;
	};
	




public:
	Department() = default;
	~Department() = default;

	virtual InfoOfSubdepartment getVector(int index) = 0;
	virtual std::string getSaEC() = 0;
	virtual int getnumOfSub() = 0;
	virtual std::string getNOD() = 0;
	virtual int calcNumOfSubjects() = 0;
	virtual void readFromFile() = 0;
	virtual void WriteToFile() = 0;
private:

};
