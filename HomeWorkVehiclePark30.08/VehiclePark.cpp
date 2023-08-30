#include<iostream>
#include<vector>
#include<string>

class Vehicle
{
private: 
	std::string make;
    std::string model;
	int year;
public:
	Vehicle():model("no model"), make("no make"),year(0){}
	Vehicle(std::string make, std::string model, int year): make(make), model(model),year(year){}

	void setMake(std::string make)
	{
		this->make = make;
	}
	void setModel(std::string model)
	{
		this->model = model;
	}
	void setYeat(int year)
	{
		this->year = year;
	}
	std::string getMake()const 
	{
		return make;
	}
	std::string getModel()const
	{
		return model;
	}
	int getYear()const
	{
		return year;
	}
	virtual bool start()
	{
		std::cout << "The Vihicle movement has begun." << std::endl;
		return true;
	}
};

class Car :public Vehicle
{
private: 
	std::string engineType;
	int numDoors;
public:
	Car() : engineType("no type"), numDoors(0){}
	Car(std::string make, std::string model, int year, std::string engineType, int numDoors)
		: Vehicle(make, model, year), engineType(engineType), numDoors(numDoors) {}

	std::string getEngineType()const
	{
		return engineType;
	}
	int getNumDoors()const
	{
		return numDoors;
	}
	bool start() override
	{
		std::cout << "The Car's engine has started." << std::endl;
		return true;
	}
};
class Motorcycle : public Vehicle
{
private:
	std::string engineType;
	int numWheels;
public:
	Motorcycle(): engineType("no type"), numWheels(0){}
	Motorcycle(std:: string make,std::string model, int year, std:: string engineType, int numWheels)
		: Vehicle (make,model,year), engineType(engineType),numWheels(numWheels){}

	std::string getEngineType()const
	{
		return engineType;
	}
	int getNumWheels()const
	{
		return numWheels;
	}
	bool start() override
	{
		std::cout << "Motorcycle's engine has started." << std::endl;
		return true;
	}
};
class Bycicle : public Vehicle
{
private:
	int numGears;
	bool hasBasket;
public:
	Bycicle(): numGears(0), hasBasket(false){}
	Bycicle(std:: string make,std:: string  model, int year, int numGears,bool hasBasker)
		:Vehicle(make,model,year), numGears(numGears),hasBasket(hasBasket){}
	int getNumGears()const
	{
		return numGears;
	}
	bool getHasBasket()const
	{
		return hasBasket;
	}
	bool start()override
	{
		std::cout << "Starting the bycicle ride." << std::endl;
		return true;
	}
};
int main()
{
	std::vector<Vehicle*> transportPark;

	Car car("Toyota", "Camry", 2023, "Gasoline", 4);
	Bycicle bycicle("Trek", "Mountein Bike", 2023, 21, true);
	Motorcycle motorcycle("Harley Davidson", "fat boy", 2023, "Gasoline", 2);

	transportPark.push_back(&car);
	transportPark.push_back(&bycicle);
	transportPark.push_back(&motorcycle);

	for (const auto vehile : transportPark)
	{
		vehile->start();
	}
	return 0;
}