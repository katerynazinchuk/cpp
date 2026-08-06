
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string	_name;
    bool				_isSigned;
    const int			_gradeToSign;
    const int			_gradeToExec;

public:
    AForm(const std::string& name, int gradeToSign, int gradeToExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

	class FormNotSignedException : public std::exception
	{
	public:
    	const char* what() const throw();
	};

	virtual void execute(Bureaucrat const& executor) const = 0;

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
