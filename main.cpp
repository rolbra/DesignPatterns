#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <set>

using namespace std;



class SharedAttributes {
private:
	array<string*,10>colors;
	int numberOfColors=0;

	array<string*, 10 > bitmaps;
	int numberOfBitmaps;

public:
	SharedAttributes() {};

	int getAmountofColors() {
		return numberOfColors;
	}

	string* insertColor( string color ) {
		colors[numberOfColors] = new string( color );
		cout << "Color " << *colors[numberOfColors] << " created. Adress: " << colors[numberOfColors] << endl << endl;
		return colors[numberOfColors++];
	}

	string* findColor( string* color ) {
		for (int index = 0; index < numberOfColors; index++)
		{
			if (*color == *colors[index])
			{
				return colors[index];
			}
		}
		
		return new string("");
	}
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
	void setY( int y ) { this->y = y; };
	void setRadius( int radius ) { this->radius = radius; };
	void setColor( string *color ) { this->color = color; };
	int getX() { return x; };
	int getY() { return y; };
	int getRadius() { return radius; };
	string *getColor() { return color; };
};

class Factory {
private:
	SharedAttributes circleAtttributes;
public:
	Factory() {
	};

	SmartCircle* getObject( int x, int y, int radius, string *color ) {
		string* storedColor;
		//Is there one color at least?
		int amount = circleAtttributes.getAmountofColors();
		if( amount > 0)
		{ 
			string* rc = circleAtttributes.findColor( color );
			//Is the color not existing create it in the color array
			if (*rc == "")
			{
				storedColor = circleAtttributes.insertColor( *color );
			}
			//Is the color already existing than take this one
			else
			{
				storedColor = rc;
				cout << "color: " << *storedColor << " existing. Adress: " << storedColor << endl << endl;
			}
		}
		else
		{
			storedColor = circleAtttributes.insertColor( *color );
			cout << *storedColor;
		}

		SmartCircle* smartCircle = new SmartCircle( x, y, radius, storedColor );
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

int checkUserInput( const std::string& input ) {
	if (std::all_of( input.begin(), input.end(), ::isdigit ))
	{
		return stoi( input );
	}
	else return -1;
}

int main()
{
	//splashScreen
	cout << "//////////////////////" << endl;
	cout << "Flightweight Pattern" << endl;
	cout << "Sharing Attributes between simular Objects" << endl;
	cout << "to decrease memory consumption" << endl;
	cout << "//////////////////////";
	cout << endl;
	cout << endl;
	//factory manages the circles
	Factory objectFactory;

	//stores all created circles
	vector<SmartCircle*> mySmartCircles;
	
	//service overview
	int circleCreation = 0;
	string userInput;
	int option=0;
	//user input:
	int x, y, radius;
	string color;

	while(1)
	{
		cout << "[1] Create new circle" << endl;
		cout << "[2] Delete a circle (deactivated)" << endl;
		cout << "[3] Show all circles" << endl;
		cout << "[4] Show all attributes" << endl;
		cout << "[5] Show all colors" << endl;
		cout << "[6] Exit" << endl;
		cin >> userInput;
		option = checkUserInput(userInput);
		cin.clear();
		cin.ignore( 10000, '\n' );
		switch (option)
		{
		case 1:
			cout << endl << endl;
			cout << "=======================" << endl;
			cout << " CREATE NEW CIRCLE (" << ++circleCreation << ")" << endl;
			cout << "=======================" << endl << endl;
			cout << "set x: ";
			cin >> x;
			cout << "set y: 5" << endl;
			y = 5;
			cout << "set r: 5" << endl;
			radius = 5;
			cout << "set color: ";
			cin >> color;

			//user request to factory
			try
			{
				mySmartCircles.push_back( objectFactory.getObject( x, y, radius, &color));
			}
			catch (...)
			{
				cout << "circle creation failed" << endl;
			}
			break;
		case 3:
			//display all smart circles
			if (mySmartCircles.size() == 0)
			{
				cout << "No circles created yet" << endl << endl;
				break;
			}
			std::cout << endl << "here are my smart objects" << endl << endl;
			for (SmartCircle* circle : mySmartCircles) {
				std::cout << circle->getX() << ", " << circle->getY() << ", " << circle->getRadius() << ", " << *circle->getColor() << ", " << circle->getColor() << endl;
			}
			break;
		case 6:
			return 0;
		default:
			cout << endl << "Better try options 1 - 6" << endl << endl;
			continue;
		}
	}
	
	system( "PAUSE" );
}