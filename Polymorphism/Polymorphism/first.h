#pragma once
#include <iostream>

class Employer {
protected:
	std::string name;

public:
	Employer();
	Employer(std::string name);

	virtual void Show() = 0;
};

class President : public Employer {
public:
	President();
	President(std::string name);

	void Show();
};

class Manager : public Employer {
public:
	Manager();
	Manager(std::string name);

	void Show();
};

class Worker : public Employer {
public:
	Worker();
	Worker(std::string name);

	void Show();
};

Employer::Employer() : name("") {}

Employer::Employer(std::string name) : name(name) {}

President::President() {}

President::President(std::string name) : Employer(name) {}

void President::Show() { std::cout << "this is president " << name << std::endl; }

Manager::Manager() {}

Manager::Manager(std::string name) : Employer(name) {}

void Manager::Show() { std::cout << "this is manager " << name << std::endl; }

Worker::Worker() {}

Worker::Worker(std::string name) : Employer(name) {}

void Worker::Show() { std::cout << "this is worker " << name << std::endl; }