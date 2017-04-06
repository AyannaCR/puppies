
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Seat { //use of classes defines a Seat class whose data members are a person's first name, last name, and the amount paid for the seat.
public:
   void Reserve(string resfirstName, string resLastName, int resAmountPaid);
   void MakeEmpty();
   bool IsEmpty() const;
   void Print() const;
   
private:
   string firstName;
   string lastName;
   int    amountPaid;
};

void Seat::Reserve(string resfirstName, string resLastName, int resAmountPaid) {
   firstName  = resfirstName;
   lastName   = resLastName;
   amountPaid = resAmountPaid;
   
   return;
}

void Seat::MakeEmpty() { 
   firstName  = "empty"; //initializes all seats to being empty (indicated by a first name of "empty"), 
   lastName   = "empty";
   amountPaid = 0;
   
   return;
}

bool Seat::IsEmpty() const {
   return(firstName == "empty");
}

void Seat::Print() const {
   cout << firstName << " " << lastName  << ", ";
   cout << "Paid: "  << amountPaid << endl;
   
   return;
}

void SeatsMakeEmpty(vector<Seat>& seats) { //use of vectors and functions together
   unsigned int i = 0;
   
   for (i = 0; i < seats.size(); ++i) {
      seats.at(i).MakeEmpty();
   }
   
   return;
}

void SeatsPrint(vector<Seat> seats) { //use of vectors and functions together
   unsigned int i = 0;
   
   for (i = 0; i < seats.size(); ++i) {
      cout << i << ": ";
      seats.at(i).Print();
   }
   
   return;
}

void SeatsCreateReservation(vector<Seat>& seats) { //use of vectors and functions together
   string firstName, lastName;                     //allows a reservations agent to reserve seats for people, useful for a theater, an airplane, etc.
   int amountPaid = 0;
   unsigned int seatNum = 0;
   Seat seat;
   
   cout << "Enter seat number (0..";
   cout << seats.size() - 1 << "): ";
   cin  >> seatNum;
   
   if (seatNum > (seats.size() - 1)) {
      cout << "Seat number too large." << endl;
   }
   else if ( !(seats.at(seatNum).IsEmpty()) ) {
      cout << "Seat already occupied." << endl;
   }
   else {
      cout << "Enter first name: ";
      cin >> firstName;
      cout << "Enter last name: ";
      cin >> lastName;
      cout << "Enter amount paid: ";
      cin >> amountPaid;
      
      seat.Reserve(firstName, lastName, amountPaid);
      seats.at(seatNum) = seat;
      
      cout << "Completed." << endl;
   }
   
   return;
}


int main() {
   char   userKey = '-';
   vector<Seat> seats(5); //The program defines a vector of 5 seats to represent the theater, airplane, etc., 
   
   SeatsMakeEmpty(seats);
   
   while (userKey != 'q') {
      cout << endl << "Enter command (p/r/q): "; //allows a user to enter commands to print all seats, reserve a seat, or quit.
      cin >> userKey;
      
      if (userKey == 'p') { // Print seats
         SeatsPrint(seats);
      }
      else if (userKey == 'r') { // Reserve seat
         SeatsCreateReservation(seats);
      }
      else if (userKey == 'q') { // Quit
         cout << "Quitting." << endl;
      }
      else {
         cout << "Invalid command." << endl;
      }
   }
   
   return 0;
}