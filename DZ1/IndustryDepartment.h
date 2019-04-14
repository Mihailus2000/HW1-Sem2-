#pragma once
#include "Department.h"
#include <vector>

class IndustryDepartment : public Department {
private:
	std::string PATH;
	std::string nameOfDepartment;
	std::string SaEC;			 //Scientific and educational complex
	int numOfSubdepartments;

	struct InfoOfDisciplineBySubdepartments {
		std::string name;
		int numberOfTeachers;
	};
	struct InfoOfSubdepartment {

		std::vector<InfoOfDisciplineBySubdepartments> Disciplines;
	};
	std::vector <InfoOfSubdepartment> Subdepartments; // вектор кафедръ


	struct InfoOfDisciplinesByOrganizations {
		std::string name;
		int numberOfTeachers;
	};
	struct Info {
		std::vector<InfoOfDisciplinesByOrganizations> Disciplines;
	};
	std::vector <Info> Organizations;


public:
	virtual void WriteToFile();
	virtual void readFromFile();
	int calcNumOfSubjects();

	IndustryDepartment(std::string path) : PATH(path) {};

};