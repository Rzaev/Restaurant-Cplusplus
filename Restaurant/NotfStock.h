#pragma once
#include"Client.h"
#include"Notification.h"
class Notf
{
	vector<Notification> notfs;
public:
	Notf():notfs(NULL) {}

	void addNotf(Notification notf)
	{
		notfs.push_back(notf);
	}

	void show()
	{
		for (auto i=notfs.begin();i!=notfs.end();i++)
		{
			i->printMessage();
		}
	}

	void deleteAll()
	{
		notfs.clear();
	}
};
