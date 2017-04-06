#include <iostream>
using namespace std;

class NodeType {
public:
   NodeType(int dataInit = 0, NodeType* nextLoc = 0);
   void InsertAfter(NodeType* nodePtr);
   NodeType* GetNext();
   void PrNodeTypeData();
private:
   int dataVal;
   NodeType* nextNodePtr;
};

// Constructor
NodeType::NodeType(int dataInit, NodeType* nextLoc) {
   this->dataVal = dataInit;
   this->nextNodePtr = nextLoc;
   return;
}

/* Insert node after this node.
 * Before: this -- next
 * After:  this -- node -- next
 */
void NodeType::InsertAfter(NodeType* nodeLoc) {
   NodeType* tmpNext = 0;
   
   tmpNext = this->nextNodePtr;    // Remember next
   this->nextNodePtr = nodeLoc;    // this -- node -- ?
   nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
   return;
}

// Print dataVal
void NodeType::PrNodeTypeData() {
   cout << this->dataVal << endl;
   return;
}

// Grab location pointed by nextNodePtr
NodeType* NodeType::GetNext() {
   return this->nextNodePtr;
}

int main() {
   NodeType* headObj  = 0; // Create NodeType objects
   NodeType* nodeObj1 = 0;
   NodeType* nodeObj2 = 0;
   NodeType* nodeObj3 = 0;
   NodeType* currObj  = 0;
   
   // Front of nodes list
   headObj = new NodeType(-1);
   
   // Insert nodes
   nodeObj1 = new NodeType(555);
   headObj->InsertAfter(nodeObj1);
   
   nodeObj2 = new NodeType(999);
   nodeObj1->InsertAfter(nodeObj2);
   
   nodeObj3 = new NodeType(777);
   nodeObj1->InsertAfter(nodeObj3);
   
   // Print linked list
   currObj = headObj;
   while (currObj != 0) {
      currObj->PrNodeTypeData();
      currObj = currObj->GetNext();
   }
   
   return 0;
}