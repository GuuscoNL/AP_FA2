#include "include/Employee.hpp"

const std::string Employee::getName() {
	return this->name;
}

bool Employee::getBusy() {
	return this->busy;
}

void Employee::setBusy(bool busy) {
	this->busy = busy;
}

bool Employee::getForkliftCertificate() {
	return this->forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
	this->forkliftCertificate = forkliftCertificate;
}

Employee::Employee(std::string name, bool forkliftCertificate) :
	name(name),
	busy(false),
	forkliftCertificate(forkliftCertificate)
	
{
}
