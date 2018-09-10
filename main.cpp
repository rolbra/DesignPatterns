#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <set>

using namespace std;

class MyCircle {
private:
	int x, y, radius;
	string color;

public:
	MyCircle() {};
	MyCircle( int x, int y, int radius, string color ) {
		this->x = x;
		this->y = y;
		this->radius = radius;
		this->color = color;
	};
	void setX( int x ) { this->x = x; };
	void setyY( int y ) { this->y = y; };
	void setRadius( int radius ) { this->radius = radius; };
	void setColor( string color ) { this->color = color; };
	int getX() { return x; };
	int getY() { return y; };
	int getRadius() { return radius; };
	string getColor() { return color; };
};

//=======================================================

class SharedAttributes {
private:
	set<string>colors;
	set<string>::iterator it;
	array<int, 10>numbers;

public:
	void insertColor( string color ) {
		colors.insert( color );
	};

	string findColor( string color ) {
		it = colors.find( color );
		if (it != colors.end())
		{
			cout << *it;
			return *it;
		}
		else
		{
			return nullptr;
		}
	};

	void insertNumber( int value ) {
		int size = numbers.size();
		numbers[size] = value;
	};
	int findValue( int value ) {
		for (int i = 0; i < 10; i++)
		{
			if (numbers[i] == value)
			{
				return numbers[i];
			}
		}
	};
};

class SmartCircle {
private:
	int x, y, radius;
	string *color;

public:
	SmartCircle() {};
	SmartCircle( int x, int y, int radius, string *color ) {
		this->x = x;
		this->y = y;
		this->radius = radius;
		this->color = color;
	};
	void setX( int x ) { this->x = x; };
	void setyY( int y ) { this->y = y; };
	void setRadius( int radius ) { this->radius = radius; };
	void setColor( string *color ) { this->color = color; };
	int getX() { return x; };
	int getY() { return y; };
	int getRadius() { return radius; };
	string *getColor() { return color; };
};

class Factory {
private:

public:
	Factory() {
	};

	SmartCircle* getObject( int x, int y, int radius, string *color ) {
		SharedAttributes circleAtttributes();

		SmartCircle* smartCircle = new SmartCircle( x, y, radius, color );
		if (smartCircle == nullptr)
		{
			return nullptr;
		}
		else
		{
			return smartCircle;
		}
	}
};


int main()
{
	vector<MyCircle*> myCircles{
		new MyCircle{ 4, 1, 10, "white" },
		new MyCircle{ 2, 2, 10, "blue" },
		new MyCircle{ 2, 3, 10, "white" },
		new MyCircle{ 3, 3, 10, "red" },
		new MyCircle{ 1, 5, 10, "white" },
		new MyCircle{ 4, 5, 10, "blue" }
	};

	vector<SmartCircle*> mySmartCircles;
	Factory objectFactory;
	mySmartCircles.push_back( objectFactory.getObject( 5, 5, 10, new string( "smart" ) ) );

	SharedAttributes test;
	test.insertColor( "test" );
	string rc = test.findColor( "test" );

	test.insertNumber( 1 );
	int value = test.findValue( 1 );

	std::cout << "Hello World!\n";
	std::cout << "here are my objects" << endl;

	for (MyCircle* circle : myCircles) {
		std::cout << circle->getX() << ", " << circle->getY() << ", " << circle->getRadius() << ", " << circle->getColor() << endl;
	}

	std::cout << endl << "here are my smart objects" << endl;
	for (SmartCircle* circle : mySmartCircles) {
		std::cout << circle->getX() << ", " << circle->getY() << ", " << circle->getRadius() << ", " << *circle->getColor() << endl;
	}
}