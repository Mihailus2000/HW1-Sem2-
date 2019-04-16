#pragma once
#include "Department.h"

#include <vector>



class BaseDepartment : public Department {
private:
	const std::string classOfDepartment = "BASE";
	std::string SaEC;			 //Scientific and educational complex
	std::string nameOfDepartment;
	int numOfSubdepartments;
	InIt* Subdep = new InIt;

	//std::vector<Subdepartment> vecSubDep; // вектор кафедр
public:
	
	BaseDepartment(std::string name) : nameOfDepartment(name) {}

	//virtual Subdepartment getVecSubDep(int index) { return (vecSubDep[index]); }
	virtual InIt* getInfo() { return Subdep; }
	
	virtual int getnumOfSub() { return numOfSubdepartments; }

	virtual std::string getSaEC() { return SaEC; }
	virtual std::string getNameOfDep() { return nameOfDepartment; }
	virtual std::string getClass() { return classOfDepartment; }
	virtual int getNumOfOrganizations() { return -1; } //CODE ERROR
	virtual void readFromFile(/*std::string*/);
	virtual int calcNumOfSubjects();
};

