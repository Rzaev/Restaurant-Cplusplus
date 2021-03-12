#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include"Notification.h"
#include"Exception.h"
//using namespace std;


class Ingredient
{
protected:
	string name;
	double fats;
	double protein;
	double carbogydrates;
	int kcal;
	int amount;
	double ingPrice;
	int ing_id;
public:
	static int id;
	Ingredient() = default;
	Ingredient(const string& name, double fats, double protein, double carbogydrates,
		int kcal, double ingPrice, int amount)
	{
		this->ing_id = ++id;
		setName(name);
		setFat(fats);
		setProtein(protein);
		setCarbogydrates(carbogydrates);
		setKcal(kcal);
		setingPrice(ingPrice);
		setAmount(amount);

	}

	Ingredient(const Ingredient& other)
	{
		this->ing_id = other.ing_id;
		setName(other.name);
		setFat(other.fats);
		setProtein(other.protein);
		setCarbogydrates(other.carbogydrates);
		setKcal(other.kcal);
		setingPrice(other.ingPrice);
		setAmount(other.amount);
	}

	string getName() const
	{
		return name;
	}

	void setName(const string& name)
	{
		this->name = name;
	}

	double getFat() const
	{
		return fats;
	}

	void setFat(double fats)
	{
		this->fats = fats;
	}


	double getProtein() const
	{
		return protein;
	}

	void setProtein(double protein)
	{
		this->protein = protein;
	}


	double getCarbogydrates() const
	{
		return carbogydrates;
	}

	void setCarbogydrates(double carbogydrates)
	{
		this->carbogydrates = carbogydrates;
	}


	int getKcal() const
	{
		return kcal;
	}

	void setKcal(int kcal)
	{
		this->kcal = kcal;
	}


	int getAmount() const
	{
		return amount;
	}

	void setAmount(int amount)
	{
		this->amount = amount;
	}

	double getingPrice() const
	{
		return ingPrice;
	}

	void setingPrice(double ingPrice)
	{
		this->ingPrice = ingPrice;
	}


	static int ingredientId()
	{
		return id;
	}

	int getId()
	{
		return ing_id;
	}

	void show() const
	{
		cout << "****Ingredient****" << endl;
		cout << "ID:" << ing_id << endl;
		cout << "Name:" << getName() << endl;
		cout << "Fat:" << getFat() << endl;
		cout << "Protein:" << getProtein() << endl;
		cout << "Carbogydrates:" << getCarbogydrates() << endl;
		cout << "Kcal:" << getKcal() << endl;
		cout << "Ingredient Price:" << getingPrice() << endl;
		cout << "Amount:" << getAmount() << endl;
	}


	friend ostream& operator<<(ostream& out, const Ingredient& ingredient);
	friend istream& operator>>(istream& in, Ingredient& ingredient);

};

int Ingredient::id = 0;

ostream& operator<<(ostream& out, const Ingredient& ingredient)
{
	out << "Ingredient:" << endl;
	out << "ID:" << ingredient.ing_id << endl;
	out << "Name:" << ingredient.getName() << endl;
	out << "Fat:" << ingredient.getFat() << endl;
	out << "Protein:" << ingredient.getProtein() << endl;
	out << "Carbogydrates:" << ingredient.getCarbogydrates() << endl;
	out << "Kcal:" << ingredient.getKcal() << endl;
	out << "Amount:" << ingredient.getAmount() << endl;
	out << "Price:" << ingredient.getingPrice() << endl;
	return out;
}

istream& operator>>(istream& in, Ingredient& ingredient)
{
	string name;
	double fat, protein, carbohidrat, price;
	int kcal, amount;
	cout << "Name:";
	in >> name;
	ingredient.setName(name);
	cout << "Fat:";
	in >> fat;
	ingredient.setFat(fat);
	cout << "Protein:";
	in >> protein;
	ingredient.setProtein(protein);
	cout << "Carbohidrat:";
	in >> carbohidrat;
	ingredient.setCarbogydrates(carbohidrat);
	cout << "Amount:";
	in >> amount;
	ingredient.setAmount(amount);
	cout << "Price:";
	in >> price;
	ingredient.setingPrice(price);
	++ingredient.id;
	return in;
}


class Meal
{
	string name;
	string category;
	double rating;
	double price;
	double tax;
	vector<Ingredient> ingredients;
	int meal_id;
	int amount;
public:
	static int id;
	Meal() = default;
	Meal(const string& name, const string& category, double rating, double price,
		double tax, int amount)
	{
		meal_id = ++id;
		setName(name);
		setCategory(category);
		setRating(rating);
		setPrice(price);
		setTax(tax);
		setAmount(amount);
	}

	string getName() const
	{
		return name;
	}

	void setName(const string& name)
	{
		this->name = name;
	}

	string getCategory() const
	{
		return category;
	}

	void setCategory(const string& category)
	{
		this->category = category;
	}


	double getRating() const
	{
		return rating;
	}

	void setRating(double rating)
	{
		this->rating = rating;
	}

	double getPrice() const
	{
		return price;
	}

	void setPrice(double price)
	{
		this->price = price;
	}

	double getTax() const
	{
		return tax;
	}

	void setTax(double tax)
	{
		this->tax = tax;
	}

	int getAmount() const
	{
		return amount;
	}

	void setAmount(int amount)
	{
		this->amount = amount;
	}




	void addIngredient(Ingredient& ingredient)
	{
		/*for (int i = 0; i < count; i++)
		{
			ingredients.push_back(ingredient);
		}*/
		ingredients.push_back(ingredient);
	}

	void deleteMeal(int id)
	{
		ingredients.erase(ingredients.begin() + id);
	}

	void deleteAll()
	{
		ingredients.clear();
	}

	static int getMealId()
	{
		return id;
	}


	vector<Ingredient> getIngredientById(int id)
	{
		vector<Ingredient> ing;
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			if (id == i->getId())
			{
				return ing;
			}
		}
	}

	void printRecipe()
	{
		for (auto i = ingredients.begin(); i != ingredients.end(); i++)
		{
			i->show();
		}
	}

	friend ostream& operator<<(ostream& out, const Meal& meal);
	friend istream& operator>>(istream& in, Meal& meal);


	void showMeal() const
	{
		cout << "ID:" << meal_id << endl;
		cout << "Name:" << getName() << endl;
		cout << "Category:" << getCategory() << endl;
		cout << "Rating:" << getRating() << endl;
		cout << "Price:" << getPrice() << endl;
		cout << "Tax:" << getTax() << endl;
		cout << "Amount:" << getAmount() << endl;
	}

};
int Meal::id = 0;


ostream& operator<<(ostream& out, const Meal& meal)
{
	out << "ID:" << meal.meal_id << endl;
	out << "Name:" << meal.getName() << endl;
	out << "Category:" << meal.getCategory() << endl;
	out << "Rating:" << meal.getRating() << endl;
	out << "Price:" << meal.getPrice() << endl;
	out << "Tax:" << meal.getTax() << endl;
	out << "Amount:" << meal.getAmount() << endl;
	return out;
}

istream& operator>>(istream& in, Meal& meal)
{
	string name, category;
	double rating, price, tax;
	int amount;
	cout << "Name:";
	in >> name;
	meal.setName(name);
	cout << "Category:";
	in >> category;
	meal.setCategory(category);
	cout << "Rating:";
	in >> rating;
	meal.setRating(rating);
	cout << "Price:";
	in >> price;
	meal.setPrice(price);
	cout << "Tax:";
	in >> tax;
	meal.setTax(tax);
	cout << "Amount:";
	in >> amount;
	meal.setAmount(amount);
	return in;
}

//class Kitchen
//{
//	vector<Meal> meals;
//	Meal* meal;
//	list<Meal> lists;
//public:
//
//	Kitchen() = default;
//	Meal* getMealById(int id)
//	{
//		Meal* meal;
//		for (auto i = meals.begin(); i != meals.end(); i++)
//		{
//			if (id == Meal::getMealId())
//			{
//				return meal;
//			}
//		}
//		return NULL;
//	}
//
//
//
//
//	void deleteMeal(int id)
//	{
//		meals.erase(meals.begin() + id);
//	}
//
//	void deleteAllMeal()
//	{
//		meals.clear();
//	}
//
//	void updateMeal(int id)
//	{
//		int n;
//		string name, category;
//		double rating, price, tax;
//		cout << "1)Name:" << endl;
//		cout << "2)Category:" << endl;
//		cout << "3)Meal Rating:" << endl;
//		cout << "4)Price:\n";
//		cout << "5)Tax:\n\n";
//		cout << "Which field do you want to update:";
//		cin >> n;
//		while (n < 1 || n>5)
//		{
//			cout << "Input again:" << endl;
//			cin >> n;
//		}
//		while (1)
//		{
//
//			switch (n)
//			{
//			case 1:
//				cout << "Updating name:" << endl;
//				cout << "Name:";
//				cin >> name;
//				meals[id - 1].setName(name);
//				break;
//			case 2:
//				cout << "Updating Category:" << endl;
//				cout << "Category:";
//				cin >> category;
//				meals[id - 1].setCategory(category);
//				break;
//			case 3:
//				cout << "Updating Meal Rating:" << endl;
//				cout << "Rating:";
//				cin >> rating;
//				meals[id - 1].setRating(rating);
//				break;
//			case 4:
//				cout << "Updating Price:" << endl;
//				cout << "Price:";
//				cin >> price;
//				meals[id - 1].setPrice(price);
//				break;
//			case 5:
//				cout << "Updating Tax:" << endl;
//				cout << "Tax:";
//				cin >> tax;
//				meals[id - 1].setTax(tax);
//				break;
//			}
//			char s;
//			cout << "Do you want to update again:y/n";
//			cin >> s;
//			if (s != 'y' || s != 'Y')
//				return;
//
//		}
//	}
//
//};


class Stock
{
	vector<Ingredient> ingredients;
	vector<NotfIngredient> notf_ingredients;

public:
	Ingredient* ingredient;
	//Stock() = default;
	Stock() :ingredient(nullptr) {}


	//vector<Ingredient> getIngredientById(int id)
	//{
	//	vector<Ingredient> ing;
	//	for (auto i = ingredients.begin();
	//		i != ingredients.end(); i++)
	//	{
	//		if (id == i->getId())
	//		{
	//			return ing;
	//		}
	//	}
	//}

	Ingredient getIngredientById(int id)
	{
		return ingredients.at(id-1);
	}

	int getIngredientSize()
	{
		return ingredients.size();
	}

	void increment(int id, int amount)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("We cant increase amount!", __FILE__, __LINE__, __TIME__);
		}
		int new_amount = ingredients[id - 1].getAmount() + amount;
		ingredients[id - 1].setAmount(new_amount);
	}

	void decrement(int id, int amount)
	{
		if (id > ingredients.size() || amount > ingredients[id - 1].getAmount())
		{
			throw DatabaseException("We cant decrease amount!", __FILE__, __LINE__, __TIME__);

		}
		int new_amount = ingredients[id - 1].getAmount() - amount;
		ingredients[id - 1].setAmount(new_amount);
	}

	void deleteAllIngredients()
	{
		ingredients.clear();
	}

	void deleteIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("There is no ingredient here", __FILE__, __LINE__, __TIME__);
		}
		ingredients.erase(ingredients.begin() + id - 1);
	}

	void addNewIng()
	{
		
	}

	void addNotfStock()
	{
		//notf_ingredients.push_back(NotfIngredient("text"));

	}
	void findIngredientByName(string name)
	{
		//auto item = std::find(ingredients.begin(), ingredients.end(), name);
		//if (item != ingredients.end())
		//{
		//	int index = std::distance(ingredients.begin(), item);
		//	cout << index;
		//	//ingredients.at(index).show();
		//}

		//auto item = std::find(ingredients.begin(), ingredients.end(), name);


		for (auto i = ingredients.begin(); i != ingredients.end(); i++)
		{
			if (name == i->getName())
			{
				i->show();
			}
		}


	}




	void deleteNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient deleted"));
	}

	void increaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient increase"));
	}

	void decreaseNotf()
	{
		notf_ingredients.push_back(NotfIngredient("Ingredient decrease:"));
	}

	void showNotfIngredient()
	{
		for (auto i = notf_ingredients.begin();
			i != notf_ingredients.end(); i++)
		{
			i->printMessage();
		}
	}

	void updateIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("There is not ingredient here", __FILE__, __LINE__, __TIME__);
		}
		string name;
		double fats, protein, carbogydrates;
		int kcal, n;
		while (1)
		{
			cout << "1)Name:" << endl;
			cout << "2)Fats:" << endl;
			cout << "3)Protein:" << endl;
			cout << "4)Karbohidrat:\n";
			cout << "5)Kcal:\n";
			cout << "Which field do you want to update:";
			cin >> n;
			while (n < 1 || n>5)
			{
				cout << "Input again:" << endl;
				cin >> n;
			}


			switch (n)
			{
			case 1:
				cout << "Updating name:" << endl;
				cout << "Name:";
				cin >> name;
				ingredients[id - 1].setName(name);
				break;
			case 2:
				cout << "Updating Fat:" << endl;
				cout << "Fat:";
				cin >> fats;
				ingredients[id - 1].setFat(fats);
				break;
			case 3:
				cout << "Updating Protein:" << endl;
				cout << "Protein:";
				cin >> protein;
				ingredients[id - 1].setProtein(protein);
				break;
			case 4:
				cout << "Updating Karbohidrat:" << endl;
				cout << "Karbohidrat:";
				cin >> carbogydrates;
				ingredients[id - 1].setCarbogydrates(carbogydrates);
				break;
			case 5:
				cout << "Updating Kcal:" << endl;
				cout << "Kcal:";
				cin >> kcal;
				ingredients[id - 1].setKcal(kcal);
				break;
			}
			char s;
			cout << "Do you want to update again:y/n";
			cin >> s;
			if (s != 121 && s != 89)
				return;
		}

	}


	void addIngredient(Ingredient ing)
	{
		ingredients.push_back(ing);
	}

	void showIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("There is no product here", __FILE__, __LINE__, __TIME__);

		}
		ingredients[id - 1].show();
	}

	void showAllIngredients()
	{
		/*for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			i->show();
		}*/

		int counter = 0;
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			i->show();
			++counter;
		}
		if (counter == 0)
		{
			throw DatabaseException("There is no ingredients here", __FILE__, __LINE__, __TIME__);
		}
	}

};


class Kitchen
{
	vector<Meal> meals;
	Stock s;
	int amount;
	vector<NotfIngredient> notf_ingredients;
public:
	Kitchen() :meal(nullptr) {}
	Meal* meal;

	int getAmount() const
	{
		return amount;
	}

	void deleteAllMeals()
	{
		meals.clear();
	}

	void getRecipe(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("There is no meals here", __FILE__, __LINE__, __TIME__);

		}
		meals[id-1].printRecipe();
	}


	void deleteNotfIngredient()
	{
		notf_ingredients.push_back(NotfIngredient("MEal deleted"));
	}

	void deleteMealById(int id)
	{
		/*if (meals[id-1].getMealId() == NULL)
		{
			throw DatabaseException("There is not product here", __FILE__, __LINE__, __TIME__);
		}*/
		if (id > meals.size())
		{
			throw DatabaseException("There is no meal here", __FILE__, __LINE__, __TIME__);

		}
		meals.erase(meals.begin() + id - 1);
	}

	void updateMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("There is not meal here!", __FILE__, __LINE__, __TIME__);
		}
		string name, category;
		double rating, price, tax;
		int n;
		while (1)
		{
			cout << "1)Name:" << endl;
			cout << "2)Category:" << endl;
			cout << "3)Rating:" << endl;
			cout << "4)Price:\n";
			cout << "5)Tax:\n";
			cout << "Which field do you want to update:";
			cin >> n;
			while (n < 1 || n>5)
			{
				cout << "Input again:" << endl;
				cin >> n;
			}


			switch (n)
			{
			case 1:
				cout << "Updating name:" << endl;
				cout << "Name:";
				cin >> name;
				meals[id - 1].setName(name);
				break;
			case 2:
				cout << "Updating category:" << endl;
				cout << "category:";
				cin >> category;
				meals[id - 1].setCategory(category);
				break;
			case 3:
				cout << "Updating Rating:" << endl;
				cout << "Rating:";
				cin >> rating;
				meals[id - 1].setRating(rating);
				break;
			case 4:
				cout << "Updating Price:" << endl;
				cout << "Price:";
				cin >> price;
				meals[id - 1].setPrice(price);
				break;
			case 5:
				cout << "Updating Tax:" << endl;
				cout << "Tax:";
				cin >> tax;
				meals[id - 1].setTax(tax);
				break;
			}
			char s;
			cout << "Do you want to update again:y/n";
			cin >> s;
			if (s != 121 && s != 89)
				return;
		}

	}

	void findMealByName(string name)
	{
		int counter = 0;
		for (auto i = meals.begin(); i != meals.end(); i++)
		{
			if (name == i->getName())
			{
				i->showMeal();
				++counter;
			}
		}
		if (counter == 0)
			cout << "There is no meal in here:" << endl;
	}


	void addMeal(Meal meal)
	{
		meals.push_back(meal);
	}

	void showMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("There is no product here", __FILE__, __LINE__, __TIME__);

		}
		meals[id - 1].showMeal();
	}

	void showAllMeals()
	{
		int counter = 0;
		for (auto i = meals.begin();
			i != meals.end(); i++)
		{
			i->showMeal();
			++counter;
		}
		if (counter == 0)
		{
			throw DatabaseException("There is no meal here", __FILE__, __LINE__, __TIME__);
		}
	}


	Meal getMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("There is no product here", __FILE__, __LINE__, __TIME__);
		}
		else
		{
			return meals.at(id-1);
		}
	}

	int getMealSize()
	{
		return meals.size();
	}

	vector<Meal> getMeal()
	{
		return meals;
	}
	/*vector<Meal> getVectorMealById(int id)
	{
		return meals.at(id);
	}*/

};



