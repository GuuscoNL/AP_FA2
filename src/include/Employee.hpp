#pragma once

#include <string>

class Employee {

private:
	const std::string name;
	bool busy;
	bool forkliftCertificate;

public:
	const std::string getName();

	bool getBusy();

	void setBusy(bool busy);

	bool getForkliftCertificate();

	void setForkliftCertificate(bool forkliftCertificate);

	Employee(std::string name, bool forkliftCertificate);
};

