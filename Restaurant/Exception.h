#pragma once
#include<iostream>
using namespace std;
class Exception
{
	string message;
	string source;
	string error_time;
	int line;
public:
	Exception(const string& message,const string& source,int line,string error_time)
	{
		setMessage(message);
		this->source = source;
		this->line = line;
		setErrorTime(error_time);
	}

	string getMessage()
	{
		return message;
	}

	void setMessage(const string& message)
	{
		this->message = message;
	}

	void setErrorTime(string error_time)
	{
		this->error_time = error_time;
	}

	void print()
	{
		cout << "Error text:" << getMessage() << endl;
		cout << "Source:" << this->source << endl;
		cout << "Line:" << this->line << endl;
		cout << "Time:" << this->error_time << endl;
	}


};

class DatabaseException :public Exception
{
public:
	DatabaseException(string message, string source, int line,string error_time):
		Exception(message, source, line, error_time) {}

	
};


