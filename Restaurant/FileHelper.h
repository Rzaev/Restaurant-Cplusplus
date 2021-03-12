#pragma once
#include<iostream>
#include<fstream>
#include"Client.h"
#include"Notification.h"
using namespace std;
class FileHelper
{
public:
	static string filename;
	static void saveIngredient(Stock stock)
	{
		ofstream fout(filename, ios::app);
		if (fout.is_open())
		{
			fout <<"Ingredient count:"<<stock.getIngredientSize() << endl;
			for (int i=0;i<stock.getIngredientSize();i++)
			{
				stock.getIngredientById(i).getId();
			}
		}
		else
		{
			cout << "ERROR!" << endl;
		}
	}

};


//static void saveNotf(NotfIngredient notf)
//{
//	ofstream fout(filename, ios::app);
//	if (fout.is_open())
//	{
//		notf.getId();
//		notf.getText();
//		notf.getCreatedTime();
//	}
//}
