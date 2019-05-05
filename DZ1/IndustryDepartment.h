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
	
	IndustryDepartment(std::string name) : nameOfDepartment(name) {
		 FillDepartment();
	}
	IndustryDepartment() {};

	virtual ~IndustryDepartment() {
		delete SubAndOrgan;
	};
	
	
	virtual void setSaEC(std::string info) { SaEC = info; }
	virtual void setNameDep(std::string name) { nameOfDepartment = name; }
	virtual void setnumOfSub(int num) { numOfSubdepartments = num; }
	virtual void setnumOfOrgan(int num) { numOfOrganizations = num; }

	virtual void setSub(InIt* element) { SubAndOrgan = element; }

	/*virtual Organization getVecOrganizations(int index) { return vecOrganizations[index]; }
	virtual Subdepartment getVecSubDep(int index) { return vecSubDep[index]; }*/
	virtual InIt* getInfo() { return SubAndOrgan; }
	virtual void setInfo(int mode) { 
		if(mode == 1)
			SubAndOrgan->FillSubDep(nameOfDepartment);
		else
			SubAndOrgan->FillOrgaiz(nameOfDepartment);
	}
	virtual std::string getClass() { return classOfDepartment; }
	virtual std::string getSaEC() { return SaEC; }
	void FillDepartment();
	virtual std::string getNameOfDep() { return nameOfDepartment; }
	virtual int getNumOfSub() { return numOfSubdepartments; }
	virtual int getNumOfOrganizations() { return numOfOrganizations; }
	virtual void WriteToFile() {};
	virtual void readFromFile() {};
	virtual void printInfo();
	virtual int calcNumOfSubjects() { return SubAndOrgan->calcSumCount(classOfDepartment); };

	

};