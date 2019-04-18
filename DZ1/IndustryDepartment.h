#pragma once
#include "Department.h"

#include <vector>

class IndustryDepartment : public Department {
private:
	//std::string PATH;
	const std::string classOfDepartment = "IND";
	std::string nameOfDepartment;
	std::string SaEC;			 //Scientific and educational complex
	int numOfSubdepartments;
	int numOfOrganizations;
	InIt* SubAndOrgan = new InIt;
	//
	//std::vector<Subdepartment> vecSubDep; // вектор кафедр
	//std::vector<Organization> vecOrganizations; // вектор организаций
public:
	
	IndustryDepartment(std::string name) : nameOfDepartment(name) {}
	virtual ~IndustryDepartment() = default;

	/*virtual Organization getVecOrganizations(int index) { return vecOrganizations[index]; }
	virtual Subdepartment getVecSubDep(int index) { return vecSubDep[index]; }*/
	virtual InIt* getInfo() { return SubAndOrgan; }
	virtual std::string getClass() { return classOfDepartment; }
	virtual std::string getSaEC() { return SaEC; }


	virtual std::string getNameOfDep() { return nameOfDepartment; }
	virtual int getNumOfSub() { return numOfSubdepartments; }
	virtual int getNumOfOrganizations() { return numOfOrganizations; }
	virtual void WriteToFile() {};
	virtual void readFromFile() {};
	virtual void printInfo();
	int calcNumOfSubjects() { return 0; };

	

};