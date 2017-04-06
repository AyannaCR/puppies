#include "ItemType.h"
#include <iostream>
using namespace std;

class NodeType {
public:
   NodeType(int dataInit = 0, NodeType* nextLoc = 0);
   void InsertAfter(NodeType* nodePtr);
   NodeType* GetNext();
   void PrNodeTypeData();
private:                       // The class' private internal data members
   int dataVal;
   NodeType* nextNodePtr;
};
NodeType* GetNext()
{
	
}
/*NodeType::NodeType(int dataInit, NodeType* nextLoc) //Constructor
{
	//this->dataVal = dataInit;
	this->nextNodePtr = nextLoc;
	return; 
}*/
void InsertAfter(NodeType* nodePtr);
class  UnsortedType {		    // Declares a class data type						
public:     			        // 8 public member functions
  UnsortedType();               // Constructor
  void MakeEmpty( );
  bool IsFull();              
  int  GetLength();             // returns length of list - Observer
  void RetrieveItem(ItemType& item, bool&  found );
  void InsertItem (ItemType item); 	 
  void DeleteItem (ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item); 	 
private:                        // The class' private internal data members
	NodeType* listData;
  	int length;
  	NodeType* currentPos;
};
UnsortedType::UnsortedType()
{
	listData = NULL;
	length = 0;
	currentPos = listData;
}
void UnsortedType::MakeEmpty()  //  When LinkedList isEmpty , listData is NULL
{
  NodeType* tempPtr;
  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->nextNodePtr;
    delete tempPr;
  }
  length = 0;
}
bool UnsortedType::IsFull()    // Member Function
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (std::bad_alloc exception)
  {
    return true;
  }
}

int UnsortedType::GetLength()     // Member Function
{
	return length;
}
void  UnsortedType::RetrieveItem( ItemType&  item, bool&  found )      // Member Function
// Pre: Key member of item is initialized.
// Post: If found, item’s key matches an element’s key in the list 
//	and a copy of that element has been stored in item; otherwise,
// item is unchanged.
{  bool  moreToSearch;
	NodeType*  location;
   location = listData;
	found = false ;
	moreToSearch = ( location  !=  NULL ) 
	while ( moreToSearch  &&  !found ) 
	{  
     if ( item  == location->info )            // match here
     { found = true;
	    item  = location->info;
	  }
	  else				    // advance pointer 
	  { location = location->next;
	    moreToSearch = ( location  !=  NULL );
     }   
   }     
}

void UnsortedType::InsertItem ( ItemType  item )     // Member Function
// Pre: list is not full and item is not in list.
// Post: item is in the list; length has been incremented.
{    
  NodeType* location;
 	// obtain and fill a node
  location = new  NodeType;
  location->info = item;      //
  location->next = listData;
  listData = location;
  length++;
}

NodeType* tempLocation;
NodeType* location;

location=listData;

// Find the item
if (item.ComparedTo(location->info == EQUAL)
{ // item in first location
  tempLocation = location;
  listData = listData->next;
}
else
{ 
  while (item.ComparedTo((location->next)->info) != EQUAL)
    location = location->next;
  tempLocation = location->next;
  location->next = (location ->next)->next;
}
delete tempLocation;
location--;


void UnsortedType::ResetList()
{ 
  currentPos = NULL;
}
void UnsortedType::GetNextItem(ItemType& item)
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
}
