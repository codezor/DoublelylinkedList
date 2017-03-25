// constructor file
//add other notes here
/*
Class PlayerListDL :  PlayerListDL.cpp Implements the bodies of the methods used in PlayerListDL
The methods maintain the Player objects as a doubly linked list.
PlayerListDL requires interations with the following methods of Player:

Methods bodies contained in this file are :
bool isEmpty();
bool isFull();
bool add(Player &);
void remove(Player &);
int getSize();
void moveToHead();
bool getNext(Player &);
bool getTrailing(Player &);
void findPlayer(Player&, ostream&);
void clearList();

*/
 
#include "PlayerListDL.h"
using namespace std;

// Default Contructor
PlayerListDL::PlayerListDL()
{
	m_length = 0;
	pFirst = NULL;
	pLast = NULL;
	pCurrent = NULL;
}

// bool isEmpty retuns true if the player list is empty and false if it is not
bool PlayerListDL::isEmpty()
{
	if (pFirst == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}

}
/// bool add: adds a player to the list and returns true when the player is sucessfully added
bool PlayerListDL::add(Player &PlayerIn)
{
	Node *pNewPlayer; 
	Node *pPrevious;	
	pCurrent = pFirst; //p 
	pPrevious = NULL; //q
	pNewPlayer = new Node(PlayerIn);

	//The List is empty
	if (isEmpty())
	{
		pFirst = pNewPlayer;
		pLast = pNewPlayer;
		m_length++;
		return true;
	}
	
	//The list is not empty. Find where player needs to beadded
	while (pCurrent != NULL && pCurrent->item.lessThan(PlayerIn))
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	//Adding a new player to the front of the list
	if (pPrevious == NULL)
	{
		pNewPlayer->pNext = pFirst;
		pFirst->pTrailing = pNewPlayer; // what am I doing
		pFirst = pNewPlayer;// reasign the first node in the list 
		
	}
	// Adding player to the end of the list
	else if (pCurrent== NULL)
	{
		pLast->pNext = pNewPlayer;
		pNewPlayer->pTrailing = pLast;
		pLast = pNewPlayer;
	}
	//Adding a player to the part of the list
	else
	{
		pNewPlayer->pNext = pCurrent;
		pNewPlayer->pTrailing = pPrevious;
		pPrevious->pNext = pNewPlayer;
		pCurrent->pTrailing = pNewPlayer;
	}

	// Adding player to the rest of the list
	m_length++;
	return true; 
}

//  removes player from list (perhaps return a statemet if the player was not found or if the player is sucessfully removed
void PlayerListDL::remove(Player &PlayerOut)
{	
	Node *pPrevious;	// Previous Location pointer loacation
	pCurrent = pFirst; //p // Set current location pointer to first location	
	pPrevious = NULL; //q // Set Trailing  location to NULL
	Node *temp;  //temp node

	while ((pCurrent != NULL) && (!pCurrent->item.isEqual(PlayerOut)))
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	
	// Removing the first player from the List 
	if (pPrevious == NULL) 
	{	
		pFirst = pCurrent->pNext; // Move the head of the list
		pFirst->pTrailing = NULL; // making pFirst point to NULL
		delete pCurrent;
	}

	//Last Node in the list
	if (pCurrent->pNext == NULL) 
	{
		pLast = pPrevious;
		pLast->pNext = NULL; // making the end of the List point to NULL
		delete pCurrent;
	}

	else
	{	
		temp = pCurrent;
		pCurrent = temp ->pNext;
		pPrevious->pNext = pCurrent;
		pCurrent->pTrailing= pPrevious;
		delete temp;
	}

	m_length--;
}
//Get the Size of the List
int PlayerListDL::getSize() 
{
	return m_length;
}
//Move the pCurrent to the begining 
void PlayerListDL::moveToHead()
{
	pCurrent = pFirst;
}
// Move pCurrent to the End of the List for backwards traversing
/*
void PlayerListDL::moveToTail()
{
	pCurrent =pLast;
	pPrevious=pCurrent-> pTrailing;
}
*/
//Get Next Function 
bool  PlayerListDL::getNext(Player &playerCall)
{
	bool found;
	if (pCurrent != NULL)
	{
		playerCall = pCurrent->item;
		pCurrent = pCurrent->pNext;
		found = true;
	}
	else
	{
		found = false;
	}

	return found;
}
//Get the Trailing Node function
/*
bool PlayerListDL::getTrailing (Player &playerCall)
{
	bool found;

	if(isEmpty){
		found =false;
		return found;
	}

	if(pCurrent !=NULL)
	{
		playerCall=pCurrent ->item;
		pCurrent =pPrevious;
		pPrevious= pCurrent->pTrailing;
		found =true;
	}
	else{
	found=false;
	}
return found;
}
*/
// findPlayer : finds a player in the list
void PlayerListDL::findPlayer(Player &foundPlayer, ostream &output)
{
	Node *pPrevious;		// trailing pointer loacation
	pCurrent = pFirst;		// Set current location pointer to first location
	pPrevious = pFirst;	// Set previous location to NULL

	if (isEmpty()) {
		output << "There are no players in the list" << endl;	
	}
	
	while ((pCurrent->pNext != NULL) && pCurrent->item.lessThan(foundPlayer))
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	
	//Player is found
	if (pCurrent->item.isEqual(foundPlayer))
	{
		output << "Your player was found" << endl;
		pCurrent->item.WriteString(output);
		return;	
	}
	//PLayer is not found
	else 
	{
		output << "Your player was not found the closest two players are:" << endl;
		pPrevious->item.WriteString(output);
		pCurrent->item.WriteString(output);
		return;
	}

}

//Clear list deallocates all of the pointers and emptys the list
void PlayerListDL::clearList() {

	// Set  current nodes to NULL
	Node *pPrevious = NULL;
	pCurrent = pFirst;
	//Clear out list one node at a time
	while (pCurrent != NULL) {
		pPrevious = pCurrent->pNext;
		delete pCurrent;
		pCurrent = pPrevious;
	}
	pFirst = NULL;
	pLast = NULL;
	pCurrent = NULL;
}

//Destruct the list
PlayerListDL::~PlayerListDL() {
	clearList();
}