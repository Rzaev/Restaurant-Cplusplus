#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;
#include"Client.h"
#include"Admin.h"
#include"Order.h"
#include"FileHelper.h"



int main()
{
	Ingredient mushroom("Mushroom", 1, 1, 1, 1, 10,1);
	Ingredient meat("Meat", 2, 2, 2, 2, 8,2);
	Ingredient cheese("Cheese", 3, 3, 3, 3, 7,6);
	Ingredient olive("Olive", 4, 4, 4, 4, 5,3);
	Ingredient spice("Spice", 5, 5, 5, 5, 8,2);
	
	Stock s;
	s.addIngredient(mushroom);
	s.addIngredient(meat);
	s.addIngredient(cheese);
	s.addIngredient(olive);
	s.addIngredient(spice);

	//s.findIngredientByName("pizza");


	//s.deleteIngredientById(2);

	//s.increment(2, 3);

	//s.showAllIngredients();

	//s.showIngredientById(2);

	//s.increment(2, 3);
	//s.decrement(2, 3);
	/*s.deleteAllIngredients();
	s.showAllIngredients();*/
	//s.showIngredientById(2);

	//s.updateIngredientById(2);
	//s.showIngredientById(2);


	


	Meal pizza("Pizza", "Fast Food", 8.5, 15, 2,10);
	Meal dolma("Dolma", "Milli Yemek", 5.5, 5, 1,8);
	Meal kabab("Kabab", "Category", 9.9, 30, 3,5);
	
	pizza.addIngredient(mushroom);
	pizza.addIngredient(olive);

	dolma.addIngredient(spice);
	dolma.addIngredient(cheese);

	kabab.addIngredient(meat);
	kabab.addIngredient(mushroom);



	Kitchen k;
	k.addMeal(pizza);
	k.addMeal(dolma);
	k.addMeal(kabab);

	//k.showAllMeals();
	//FileHelper::saveIngredient(s);
	
	Admin a(s, k);
	Order o(k, s);
	int num, select;
	while (1)
	{
		system("cls");
		cout << "1)Admin\n2)Order\n3)Close Tab\n";
		cin >> num;
		while (num != 1 && num != 2 && num!=3)
		{
			cout << "Input again:";
			cin >> num;
		}

		
			if (num == 1)
			{
				a.signin();
				while (1)
				{

					system("cls");
					cout << "1)Stock control\n2)Meal Control\n";
					cout << "3)Show Notification\n4)Back\n";
					cin >> select;
					while (select != 1 && select != 2 && select !=3 && select !=4)
					{
						cout << "Input again:";
						cin >> select;
					}
					if (select == 1)
					{
						a.stockControl();
					}
					else if (select == 2)
					{
						a.mealControl();
					}
					else if (select == 3)
					{
						a.showNotf();
						cin.ignore();
						cin.get();
					}
					else if (select == 4)
					{
						break;
					}
				}
			}
			else if (num == 2)
			{
				while (1)
				{
					int o_num;
					cout << "1)Go Order" << endl;
					cout << "2)Back" << endl;
					cin >> o_num;
					while (o_num != 1 && o_num != 2)
					{
						cout << "Input again:";
						cin >> o_num;
					}
					if (o_num == 1)
						o.Menu();
					else if (o_num == 2)
						break;
				}
			}
			else if (num == 3)
			{
				system("pause");
				return 0;
			}
	}



	cout << "After while" << endl;


	//system("pause");
	cin.ignore();
	cin.get();
	return 0;
}