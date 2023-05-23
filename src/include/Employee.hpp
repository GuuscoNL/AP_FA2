#pragma once

#include <string>

class Employee {

private:
	const std::string name;
	bool busy;
	bool forkliftCertificate;

public:

	/**
	 * @brief Get name of Employee
	 * 
	 * @return Name of Employee
	 */
	const std::string getName();

	/**
	 * @brief Get busy status of Employee
	 * 
	 * @return busy status of Employee
	 */
	bool getBusy();

	/**
	 * @brief Set busy status of Employee
	 * @param busy The busy status of the Employee
	 */
	void setBusy(bool busy);

	/**
	 * @brief Set ForkliftCertificate of Employee
	 * @param forkliftCertificate The certification of the Employee
	 */
	bool getForkliftCertificate();

	/**
	 * @brief Set ForkliftCertificate of Employee
	 * @param forkliftCertificate The certification of the Employee
	 */
	void setForkliftCertificate(bool forkliftCertificate);

	/**
	 * @brief Employee class
	 * @param name Name of Employee
	 * @param forkliftCertificate Is the Employee certified?
	*/
	Employee(std::string name, bool forkliftCertificate);
};

