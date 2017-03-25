// This file performs the functions for player
#include "Player.h"
using namespace std;
/// IConstructor with default players
Player::Player()
{
	m_FName = "Joe";
	m_LName = "DiMaggio";
	m_Pos = "OF";
	m_Bavg = 0.325F;
}
/// Initilize sets player items to variables
void Player::initialize(string FName, string LName, string Pos, float Bavg)
{
	m_FName = FName;
	m_LName = LName;
	m_Pos = Pos;
	// ensure batting average is positive
	if (Bavg < 0)
	{
		Bavg = -Bavg;
	}
	m_Bavg = Bavg;
}

/// Reads one line of Player information from input file
void Player::ReadFile(istream &inputFileName)
{
	// Read data from input file 
	inputFileName >> m_FName >> m_LName >> m_Pos >> m_Bavg;
}

/// Writes Player information to output file
void Player::WriteString(ostream &outputFileName)
{
	// Format and print information in the class one line at a time
	outputFileName << m_LName << ", " << m_FName << ": " << m_Pos + " (" << setprecision(3) << m_Bavg << ")" << endl;
}

///Greater(): bool  Returns true if the player is greater than the one passed in
bool Player::Greater(const Player &P)
{
	if (m_LName > P.m_LName)
	{
		return true;
	}

	else if (m_LName == P.m_LName && m_FName > P.m_FName)
	{
		return true;
	}

	else
	{
		return false;
	}
}

/// lessThan() : bool Returns true if the date is less than the on Passed in
bool Player::lessThan(const Player &P)
{
	if ((m_LName < P.m_LName) ||
		((m_LName == P.m_LName) && (m_FName < P.m_FName)))
	{
		return true;
	}

	else
	{
		return false;
	}
}

/// Equal() : Bool Returns true if the player is equal to the one passed in
bool Player::isEqual(const Player &P)
{
	if ((m_LName == P.m_LName) && (m_FName == P.m_FName))
	{
		return true;
	}

	else
	{
		return false;
	}
}

// define get / sets as needed
double Player::getBattingAverage()
{
	return m_Bavg;
}

string Player::getFirstName()
{
	return m_FName;
}

string Player::getLastName()
{
	return m_LName;
}

string Player::getFullName()
{
	return  m_FName + " " + m_LName;
}

string Player::getPosition()
{
	return m_Pos;
}
