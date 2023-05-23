#include "include/Employee.hpp"
// @brief Get name of Employee
// @return Name of Employee
const std::string Employee::getName() {
	return this->name;
}

// @brief Get busy status of Employee
// @return busy status of Employee
bool Employee::getBusy() {
	return this->busy;
}

// @brief Set busy status of Employee
// @param busy The busy status of the Employee
void Employee::setBusy(bool busy) {
	this->busy = busy;
}

// @brief Get ForkliftCertificate of Employee
// @return ForkliftCertificate of Employee
bool Employee::getForkliftCertificate() {
	return this->forkliftCertificate;
}

// @brief Set ForkliftCertificate of Employee
// @param forkliftCertificate The certification of the Employee
void Employee::setForkliftCertificate(bool forkliftCertificate) {
	this->forkliftCertificate = forkliftCertificate;
}
// @brief Employee class
// @param name Name of Employee
// @param forkliftCertificate Is the Employee certified?
// @return The Employee
Employee::Employee(std::string name, bool forkliftCertificate) :
	name(name),
	busy(false),
	forkliftCertificate(forkliftCertificate)
{
}
