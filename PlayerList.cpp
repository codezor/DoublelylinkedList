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
#include "PlayerList.h" 
//#include "Player.h"
using namespace std;


//Node for PlayerList Building 

Node::Node(const Player &playerIn)
{
	item = playerIn;
	pNext = NULL;
}


//Declare PlayerList

//Constructor 
PlayerList::PlayerList()
{
	m_length = 0;
	pFirst = NULL;
	pLast = NULL;
	pCurrent = NULL;
}

//Destructor
PlayerList::~PlayerList()
{
	clearList();
}

//Operators 

/// isEmpty(): bool Retuns true if the list is currently empty
bool PlayerList::isEmpty()
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

/// add() : void  adds a new player in to the linked list while sorted
bool PlayerList::add(Player &playerIn)
{
	Node *pPrevious;			//trailing pointer loacation
	Node *pNewPlayer;					//new player node
	pCurrent = pFirst;					// Set current location pointer to first location
	pPrevious = NULL;			// Set previous location to NULL
	pNewPlayer = new Node(playerIn);	// assign information to the newPlayer
										// isEmpty();
	if (isEmpty()) // then the allocate did not succeed which would be a critical  memory failure!
	{
		pNewPlayer->pNext = NULL;   //set the pointer from the new node to the current first address 
		pFirst = pNewPlayer;
		m_length++;
		return true;  // did not succeed
	}

	while ((pCurrent != NULL) && (pCurrent->item.lessThan(playerIn)))
	{
		pPrevious = pCurrent;		//move 
		pCurrent = pCurrent->pNext;
	}

	if (pPrevious == NULL)
	{
		pNewPlayer->pNext = pFirst;		//set the pointer from the new node to the current first address 
		pFirst = pNewPlayer;			//set the new first node to be the begining of the new item
	}

	else
	{
		pPrevious->pNext = pNewPlayer;
		pNewPlayer->pNext = pCurrent;
		

	}

	m_length++;
	return true;
}

//  removes player from list (perhaps return a statemet if the player was not found or if the player is sucessfully removed
void PlayerList::remove(Player &newPlayer)
{
	Node *pPrevious;		// trailing pointer loacation
	pCurrent = pFirst;				// Set current location pointer to first location
	pPrevious = NULL;		// Set previous location to NULL


	while ((pCurrent != NULL) && (!pCurrent->item.Equal(newPlayer)))
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	// can add nested if to not remove if player is not found in the List
	if (pPrevious == NULL) // First Node in the list
	{
		pFirst = pCurrent->pNext;
		pPrevious->pNext = pCurrent->pNext;
		delete pCurrent;
	}

	if (pCurrent->pNext == NULL) //Last Node in the list
	{
		pLast = pPrevious;
		delete pCurrent;
	}

	else
	{
		pPrevious->pNext = pCurrent->pNext;
		delete pCurrent;
	}

	m_length--;
}

/// Retuns number of players in the list
int PlayerList::getSize()
{
	return m_length;
}

/// moves the the node position back to the begining of the list
void PlayerList::moveToStart()
{
	pCurrent = pFirst;
}

/// Modifies location in the list
bool  PlayerList::getNext(Player &playerCall)
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

// findPlayer : finds a player in the list
bool PlayerList::findPlayer(Player &findPlayer)
{
	bool found = false;
	Node *pPrevious;		// trailing pointer loacation
	pCurrent = pFirst;				// Set current location pointer to first location
	pPrevious = pCurrent;	// Set previous location to NULL

	while ((pCurrent != NULL) && (!pCurrent->item.Equal(findPlayer)))
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	if ((pCurrent != NULL) && (pCurrent->item.Equal(findPlayer)))
	{
		found = true;
	}

	return found;
}

//Clear the list
void PlayerList::clearList()
{
	Node *pPrevious;	// trailing pointer loacation
	pCurrent = pFirst;			// Set current location pointer to first location
	pPrevious = NULL;	// Set previous location to NULL

	while (pCurrent != NULL)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
		delete pPrevious;
	}

	if (pCurrent != NULL)
	{
		delete pCurrent;
	}

}
void PlayerList::printpcurrent(ostream &outfile)
{
	pCurrent->item.WriteString(outfile);
}

