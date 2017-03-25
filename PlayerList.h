/*Player List Class header File
//Supported Operations:
1. Default Contructor
2. Destructor
3. Add a Player to the List
4. Iterate the List (enables list traversing)
5. Clear out the List to make empty
6. Test if the List is empty
7. Get the Size of the List
8. Find a player in the List (get)
*/

#include <string>
#include "Player.h"
using namespace std;


//Node for PlayerList Building 
class Node {
public:
	Player item;	//Create space in Memory for the data to be added
	Node *pNext;	// point to the next Node
	Node(const Player &);
};

//Declare PlayerList
class PlayerList
{
	//Private Class Members
	Node *pFirst;	// Pointer that always points to the first item in the list
	Node *pLast;
	int m_length;
	Node *pCurrent;
public:

	//Constructor 
	PlayerList();

	//Destructor
	~PlayerList();


	//Operators 
	/// isEmpty(): bool Retuns true if the list is currently empty
	bool isEmpty();
	
	/// add() :  adds a new player in to the linked list while sorted
	bool add(Player &);
	//  removes player from list (perhaps return a statemet if the player was not found or if the player is sucessfully removed
	void remove(Player &);
	/// Retuns number of players in the list
	int getSize();
	/// moves the the node position back to the begining of the list
	void moveToStart();
	/// Modifies location in the list
	bool  getNext(Player &);
	// findPlayer : finds a player in the list
	bool findPlayer(Player &);
	//Clear the list
	void clearList();
	void printpcurrent(ostream &);

};
