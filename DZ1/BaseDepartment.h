#pragma once
#include "Department.h"
#include <vector>

class BaseDepartment : public Department {
private:

	std::string SaEC;			 //Scientific and educational complex
	std::string nameOfDepartment;
	int numOfSubdepartments;
	Subdepartment D;


	std::vector<Subdepartment> vecSubDep; // ������ ������
public:

	//std::vector <InfoOfSubdepartment> Subdepartments; // ������ ������


	BaseDepartment(std::string name) : nameOfDepartment(name) {}


	virtual Subdepartment getVecSubDep(int index) { return (vecSubDep[index]); };
	virtual std::string getNOD() { return nameOfDepartment; }
	virtual int getnumOfSub() { return numOfSubdepartments; }
	virtual std::string getSaEC() { return SaEC; }
	virtual void readFromFile(/*std::string*/);
	virtual void WriteToFile(/*std::string*/);
	virtual int calcNumOfSubjects();
};
#pragma once
