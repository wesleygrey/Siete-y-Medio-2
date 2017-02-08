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
	
	gamelog.open("gamelog.txt");


newRound:
	if (player.get_rounds() != 0) {
		gamelog << "-----------------------------------------------" << std::endl << std::endl;
		gamelog << "Game number: " << player.get_rounds();
		gamelog << "          " << "Money left: $" << player.get_money()
			<< std::endl << std::endl;
		gamelog << "Your cards:" << std::endl;
		for (size_t pos = 0; pos != my_hand.get_cur_hand().size(); ++pos) {
			gamelog << "          "
				<< my_hand.get_cur_hand()[pos].get_spanish_rank() << " de " << my_hand.get_cur_hand()[pos].get_spanish_suit();
			gamelog << "          "
				<< "(" << my_hand.get_cur_hand()[pos].get_english_rank() << " of "
				<< my_hand.get_cur_hand()[pos].get_english_suit() << ")" << std::endl;
		}
		gamelog << "Your total: " << my_hand.get_total() << "." << std::endl << std::endl;

		gamelog << "Dealer's cards:" << std::endl;
		for (size_t pos = 0; pos != dealer_hand.get_cur_hand().size(); ++pos) {
			gamelog << "          "
				<< dealer_hand.get_cur_hand()[pos].get_spanish_rank() << " de " << dealer_hand.get_cur_hand()[pos].get_spanish_suit();
			gamelog << "          "
				<< "(" << dealer_hand.get_cur_hand()[pos].get_english_rank() << " of "
				<< dealer_hand.get_cur_hand()[pos].get_english_suit() << ")" << std::endl;
		}
		gamelog << "Dealer's total: " << dealer_hand.get_total() << "." << std::endl << std::endl;
	}
	
	my_hand.reshuffle(); dealer_hand.reshuffle();

	while ((player.get_money() > 0 && dealer_losses < MAX_DEALER_LOSSES) || player.get_rounds() == 0) {

		char another_card = 'y';

		do {
			std::cout << "You have $" << player.get_money() << ". Enter bet: ";
			std::cin >> bet;
			if (bet > player.get_money()) {
				std::cout << "You don't have $" << bet << " to bet. Try again." << std::endl;
				bet = 0;
			}
		} while (bet == 0);

		Card first_card;
		my_hand.push_back(first_card);
		my_hand.add_to_total(first_card.get_rank());

		while (another_card == 'y' && my_hand.get_total() <= MAX_HAND_TOTAL) {

			if (my_hand.get_cur_hand().size() != 1) {
				std::cout << "New card:" << std::endl;
				std::cout << std::setw(20)
					<< my_hand.get_cur_hand().back().get_spanish_rank() << " de " << my_hand.get_cur_hand().back().get_spanish_suit();
				std::cout << std::setw(20)
					<< "(" << my_hand.get_cur_hand().back().get_english_rank() << " of "
					<< my_hand.get_cur_hand().back().get_english_suit() << ")" << std::endl << std::endl;
				//std::sort(my_hand.get_cur_hand().begin(), my_hand.get_cur_hand().end());
			}
   
   return 0;
}
