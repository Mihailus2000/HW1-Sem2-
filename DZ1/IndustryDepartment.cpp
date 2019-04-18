#include "IndustryDepartment.h"

void IndustryDepartment::WriteToFile() {

}
void IndustryDepartment::readFromFile() {};

int IndustryDepartment::calcNumOfSubjects() {
	int sumOfSub = 0;
		std::cout << "-> " << nameOfDepartment;
		for (int j = 0; j < numOfSubdepartments; j++) {
			sumOfSub += SubAndOrgan->getVecSubDep(j).getNumOfDisciplines();
			if (classOfDepartment == "IND") {
				sumOfSub += SubAndOrgan->getVecOrganizations(j).getNumOfDisciplines();
			}
		}
		std::cout << "sum: " << sumOfSub;
		std::cout << std::endl;
	return 0;
};