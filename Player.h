#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include<iostream>
#include "Card.h"
using namespace std;
class Player {
	private:
		string name;
		int num_of_cards;
		vector<Card> vec;


	//private members

	public:
		//public members

		Player(string name , int num_of_cards) : name{name}, num_of_cards{num_of_cards} {for (int i = 0; i < num_of_cards; i++) vec.push_back(Card::generate_card()); }; //default construtor and init list constructor
		Player(const Player& player) : name{player.name}, num_of_cards{player.num_of_cards},vec{player.vec} {}; //copy constructor
		Player& operator=(const Player& player) {name = player.name; num_of_cards = player.num_of_cards; vec=player.vec; return *this;}; //operator=
		string get_name() const { return name; }
		int get_num_of_cards() const { return num_of_cards; }
		vector<Card> get_vec() const { return vec; }

	bool play(Card&);


};
#endif



