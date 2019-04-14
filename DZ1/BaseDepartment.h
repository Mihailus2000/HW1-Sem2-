#pragma once
#include "Department.h"
#include <vector>

class BaseDepartment : public Department {
private:
	
	std::string SaEC;			 //Scientific and educational complex
	std::string nameOfDepartment;
	int numOfSubdepartments;

	struct InfoOfDisciplineBySubdepartments {
		std::string name;
		int numberOfTeachers;
	};
	struct InfoOfSubdepartment {
		std::string nameOfSubdep;
		int numOfDisciplines;
		std::vector<InfoOfDisciplineBySubdepartments> Disciplines;
	};
	
	std::vector <InfoOfSubdepartment> Subdepartments; // вектор кафедр
public:
	BaseDepartment(std::string name) : nameOfDepartment(name) {}
	virtual InfoOfSubdepartment getVector(int index) { return (Subdepartments[index]); };
	virtual std::string getNOD() { return nameOfDepartment; }
	virtual int getnumOfSub() {	return numOfSubdepartments; }
	virtual std::string getSaEC() { return SaEC;  }
	virtual void readFromFile(/*std::string*/);
	virtual void WriteToFile(/*std::string*/);
	virtual int calcNumOfSubjects();
};
#pragma once
