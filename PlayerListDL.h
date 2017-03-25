// Player List header file for a doubley linked list

#include <iostream>
#include <fstream>
#include "Player.h"
using namespace std;

//Nodes for doubley linked list
class Node
{
public:
	Player item; // Storage for my player information
	Node *pNext; // pointer to the next Node
	Node *pTrailing; // pointer to the previous Node

	Node(const Player &PlayerIn)
	{
		item = PlayerIn;
		pNext = NULL;
		pTrailing = NULL;
	}
};

class PlayerListDL
{
	Node *pFirst; // a pointer to the first item in the list
	Node *pLast; // a pointer to track the last item in the list
	Node *pCurrent;// cursor used to travers the list
	int m_length; // keep track of List length

public:
	// Constructor and Destructor
	PlayerListDL();
	~PlayerListDL();

	// Public Member functions 
	bool isEmpty();
	//bool isFull();
	bool add(Player &);
	void remove(Player &);
	
	int getSize();
	void moveToHead();
	//void moveToTail();
	bool getNext(Player &);
	//bool getTrailing(Player &);
	void findPlayer(Player&, ostream&);
	void clearList();
	
};
