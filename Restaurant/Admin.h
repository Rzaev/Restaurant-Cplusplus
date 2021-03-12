#pragma once
#include<iostream>
#include"Client.h"
#include"Notification.h"
#include"Exception.h"
#include"NotfStock.h"
#include <synchapi.h>
//using namespace std;


//enum StockControl
//{
//	DeleteIngredients = 1, ShowAllIngredient, ShowIngedientById, Increase, Decrease,
//	UpdateIngredient, Back
//};
//
//enum MealControl
//{
//	DeleteMeal = 1, DeleteAllMeal, UpdateMeal, ShowMealById, ShowAllMeals, BackMeal
//};


enum StockControl
{
	DeleteIngredients = 1, ShowAllIngredient, ShowIngedientById, Increase, Decrease,
	UpdateIngredient,Back
};

enum MealControl
{
	DeleteMeal = 1, DeleteAllMeal, UpdateMeal, ShowMealById, ShowAllMeals,
	FindMealById, BackMeal
};



class Admin
{

	Stock s;
	Kitchen k;
	const string sys_username = "admin";
	const string sys_password = "admin12";
	vector<NotfIngredient> notf_ingredients;
public:
	Admin(Stock s, Kitchen k)
	{
		this->s = s;
		this->k = k;
	}


	void deleteNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient deleted"));
	}

	void increaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredined increase"));
	}

	void decreaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient decrease:"));
	}

	void updateIngNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient Updated:"));
	}


	void deletenotNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient cant be deleted"));
	}

	void increasenotNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient cant be increased"));
	}

	void decreasenotNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient cant be decrease:"));
	}

	void updateIngnotNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient cant be Updated:"));
	}

	void deleteMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Meal deleted"));
	}

	void deleteNotMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Meal cant be deleted"));
	}

	void updateMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Meal updated"));
	}

	void updateNotMealNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Meal cant be updated"));
	}

	void showNotfIngredient()
	{
		for (auto i = notf_ingredients.begin();
			i != notf_ingredients.end(); i++)
		{
			i->printMessage();
		}
	}

	bool login(string username, string password)
	{
		/*const string sys_username = "admin";
		const string sys_password = "admin12";*/

		if (username == sys_username && password == sys_password)
		{
			cout << "::::Log in::::" << endl;
			Sleep(400);
			return true;
		}
		else if (username == sys_username && password != sys_password)
		{
			cout << "Password is incorrect:" << endl;
			return false;
		}
		else if (username != sys_username && password == sys_password)
		{
			cout << "Username is incorrect:" << endl;
			return false;
		}
		else if (username != sys_username && password != sys_password)
		{
			cout << "Username and password are incorrect:" << endl;
			return false;
		}
	}

	void signin()
	{
		while (1)
		{
			system("cls");
			string username, password;
			cout << "Input username:";
			cin >> username;
			cout << "Password:";
			cin >> password;

			if (login(username, password))
				break;
			else
			{
				cout << "Input again" << endl;
			}
			cin.ignore();
			cin.get();

		}
	}

	void stockControl()
	{
		//showNotfIngredient();
		while (1)
		{
			system("cls");
			cout << "1)Delete Ingredient:" << endl;
			cout << "2)Show All Ingredients:" << endl;
			cout << "3)Show Ingredient by id:" << endl;
			cout << "4)Increase ingredient:" << endl;
			cout << "5)Decrease ingredient:" << endl;
			cout << "6)Update ingredient:" << endl;
			cout << "7)Back:" << endl;

			int choice;
			cout << "Choice:";
			cin >> choice;

			switch (choice)
			{
			case DeleteIngredients:
			{
				try
				{
					int id_delete;
					cout << "Input id:";
					cin >> id_delete;
					s.deleteIngredientById(id_delete);
					deleteMealNotf();
				}
				catch (Exception ex)
				{
					deletenotNotfIngredient();
					ex.print();
				}
				//s.deleteNotfIngredient();
				//s.showNotfIngredient();
				cin.ignore();
				cin.get();
				break;
			}
			case ShowAllIngredient:
				try
				{
					s.showAllIngredients();
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			case ShowIngedientById:
			{
				try
				{
					int id_s_m;
					cout << "Input id:";
					cin >> id_s_m;
					s.showIngredientById(id_s_m);
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Increase:
				try
				{

					int id_increase, amount_increase;
					cout << "Input id:";
					cin >> id_increase;
					cout << "Amount:";
					cin >> amount_increase;
					s.increment(id_increase, amount_increase);
					increaseNotf();
				}
				catch (Exception ex)
				{
					increasenotNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			case Decrease:
				try
				{
					int id_decrease, amount_decrease;
					cout << "Input id:";
					cin >> id_decrease;
					cout << "Amount:";
					cin >> amount_decrease;
					s.decrement(id_decrease, amount_decrease);
					decreaseNotf();
				}
				catch (Exception ex)
				{
					decreasenotNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			case UpdateIngredient:
			{
				try
				{
					int id_update;
					cout << "Input id:";
					cin >> id_update;
					s.updateIngredientById(id_update);
					updateIngNotf();
				}
				catch (Exception ex)
				{
					updateIngnotNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Back:
				return;
				break;
			

			}

		}
	}


	void mealControl()
	{
		while (1)
		{
			system("cls");
			cout << "1)Delete Meal:" << endl;
			cout << "2)Delete All Meal:" << endl;
			cout << "3)Update Meal:" << endl;
			cout << "4)Show Meal by ID:" << endl;
			cout << "5)Show All Meal:" << endl;
			cout << "6)Search meal by name:" << endl;
			cout << "7)Back:" << endl;

			int choice;
			cout << "Choice:";
			cin >> choice;



			switch (choice)
			{
			case DeleteMeal:
			{
				try
				{
					int id_d_m;
					cout << "Input id:";
					cin >> id_d_m;
					k.deleteMealById(id_d_m);
					deleteMealNotf();
				}
				catch (Exception ex)
				{
					deleteNotMealNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case DeleteAllMeal:
			{
				k.deleteAllMeals();
				cout << "\nAll meals Deleted:\n";
				cin.ignore();
				cin.get();
				break;
			}
			case UpdateMeal:
			{
				try
				{
					int id_u_m;
					cout << "Input id:";
					cin >> id_u_m;
					k.updateMealById(id_u_m);
					updateMealNotf();
				}
				catch (Exception ex)
				{
					updateNotMealNotf();
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowMealById:
			{
				try
				{
					int id_s_m;
					cout << "Input id:";
					cin >> id_s_m;
					k.showMealById(id_s_m);
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowAllMeals:
			{
				try
				{
					k.showAllMeals();

				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case FindMealById:
			{
				string ss_name;
				cout << "Input name:";
				cin >> ss_name;
				k.findMealByName(ss_name);
				cin.ignore();
				cin.get();
				break;
			}
			case BackMeal:
				return;
				break;
			}
		}

	}

	void showNotf()
	{
		showNotfIngredient();
	}
};
