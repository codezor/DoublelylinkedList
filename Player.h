/*Player 
Operations:
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//
class Player
{
	// Class Members 
	string m_FName; // First Name
	string m_LName; // Last Name
	string m_Pos;   // Batters position
	float  m_Bavg;  // Batters Average

	public:
	/// default Player Contructor
	Player();

	// Public member functions
	void initialize(string, string, string, float);	// Initializes Data	
	void ReadFile(istream &);						// Reads one line of Player information from input file
	void WriteString(ostream &);					// Writes Player information to output file

	//Adding functionality to compare items to support search functions
	bool Greater(const Player &);	//Greater(): bool returns true if the player is greater than the one passed in
	bool lessThan(const Player &);	// lessThan() : bool True if the date is less than the on Passed in
	bool isEqual(const Player &);		// Equal() : Bool Returns true if the player is equal to the one passed in

	// Define gets and sets for Debugging or future use 
	double getBattingAverage();
	string getFirstName();
	string getLastName();
	string getFullName();
	string getPosition();
};

