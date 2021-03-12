#pragma once
#include"Client.h"
#include"Notification.h"

double last_price = 0;

enum ClientControl
{
	ShawAllMeals = 1, Detail, Search, Buy, CBack
};

class Order
{
	Kitchen k;
	Stock s;
	vector<Notification> notf;
public:
	Order(Kitchen k, Stock s)
	{
		this->k = k;
		this->s = s;
	}

	void notfAddIng()
	{
		notf.push_back(NotfIngredient("Customer add new ingredient"));
	}

	bool checkAmount(int id, int amount)
	{

		Meal item = k.getMealById(id);


		//vector<Meal> item = k.getMealById(id);
		if (id > k.getMeal().size())
		{
			throw Exception("There is not meal here", __FILE__, __LINE__, __TIME__);
		}
		else
		{
			if (amount > item.getAmount())
			{
				return false;
			}
			return true;
		}
	}

	void buyProduct(int id, int amount)
	{
		Meal item = k.getMealById(id);
		last_price = last_price + item.getPrice() * amount;
		item.setAmount(item.getAmount() - amount);
	}

	void addMoreIngredient(int id)
	{
		Ingredient item = s.getIngredientById(id);
		if (item.getId() == NULL || item.getAmount() == 0)
		{
			throw DatabaseException("We can't add this ingredient", __FILE__, __LINE__, __TIME__);
		}
		else
		{
			last_price = last_price + item.getingPrice();
			item.setAmount(item.getAmount() - 1);
			notfAddIng();
		}

	}

	void Menu()
	{
		while (1)
		{
			system("cls");

			cout << "1)Show all Meals:" << endl;
			cout << "2)Show detail:" << endl;
			cout << "3)Find Meal:" << endl;
			cout << "4)Buy:" << endl;
			cout << "5)Back:" << endl;
			int choice;
			cout << "Choice:";
			cin >> choice;
			switch (choice)
			{
			case ShawAllMeals:
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
			case Detail:
			{
				int id;
				cout << "Input ID:";
				cin >> id;
				try
				{
					k.getRecipe(id);
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Search:
			{
				string name;
				cout << "Input name:";
				cin >> name;
				k.findMealByName(name);
				cin.ignore();
				cin.get();
				break;
			}
			case Buy:
			{

				int id, amount;
				cout << "Meal id:";
				cin >> id;
				while (id > k.getMealSize())
				{
					cout << "Input again:";
					cin >> id;
				}
				cout << "Amount:";
				cin >> amount;
				try
				{
					if (checkAmount(id, amount) == true)
					{
						while (1)
						{
							char choice;
							cout << "Do you want add more ingredient:y or n";
							cin >> choice;
							try
							{
								if (choice == 121 || choice == 89)
								{
									int i_id;
									cout << "ID:";
									cin >> i_id;
									addMoreIngredient(i_id);
								}
								else
								{
									break;
								}
							}
							catch (Exception ex)
							{
								ex.print();
							}

						}
						buyProduct(id, amount);
						cout << "Congratulations.You buy meal succesfully!" << endl;
						cout << "Last Price:" << last_price << endl;
						char select;
						int rate;
						cout << "Do you want to Rate?Y or N:";
						cin >> select;
						if (select == 89 || select == 121)
						{
							cout << "Input Rate (0-9)!";
							cin >> rate;
							while (rate < 0 || rate>9)
							{
								cout << "Rate 0-9 please:";
								cin >> rate;
							}
							cout << "Thank you for your rate!Your rate is " << rate << endl;
						}

					}
					else
					{
						cout << "There is not enought meal in Kitchen:";
					}
				}
				catch (Exception ex)
				{
					ex.print();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ClientControl::CBack:
			{
				return;
			}
			}
		}
	}

};
