#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main(){
   
   const double MAX_HAND_TOTAL = 7.5;
	const double DEALER_TOTAL = 5.5;
	const int MAX_DEALER_LOSSES = 900;
	Player player(100);
	Hand my_hand;
	Hand dealer_hand;
	int dealer_losses = 0;
	int bet = 0;
	ofstream gamelog;
   
   return 0;
}
