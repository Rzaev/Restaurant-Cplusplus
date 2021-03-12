#pragma once
#include<iostream>
using namespace std;

class Notification {
	string text;
	string created_date;
	int notf_id;

public:
	static int id;
	Notification() : text(""), created_date("") {}

	Notification(const string& text)
	{
		this->notf_id = ++id;
		setText(text);
		setCreatedTime();
	}



	void setText(const std::string& text)
	{
		this->text = text;
	}

	std::string getText() const { return this->text; }


	void setCreatedTime()
	{
		this->created_date = __TIME__;
	}

	int getId()
	{
		return notf_id;
	}

	std::string getCreatedTime() const { return this->created_date; }

	void printMessage();
	~Notification() {}
	



	friend std::ostream& operator<<(std::ostream& out, const Notification& notf);
};

int Notification::id = 0;
std::ostream& operator<<(std::ostream& out, const Notification& notf)
{
	out << "ID: " << notf.notf_id << std::endl;
	out << "Created time: " << notf.getCreatedTime() << std::endl;
	out << "Text: " << notf.getText() << std::endl;
	return out;
}



class NotfIngredient :public Notification
{
public:
	NotfIngredient(string text) :Notification(text) {}
	

	void printMessage() 
	{
		cout << "****Notf INFO****" << endl;
		cout << "ID:" << getId() << endl;
		cout << "Text:" << getText() << endl;
		cout << "Time:" << getCreatedTime() << endl;
	}
};
