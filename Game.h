#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
#include<iostream>

using namespace std;

enum class direction {forward, backwards }; //enumartion of direction. //

class Game {
    private:
    //private members and functions
    Card current_card;
    vector<Player> players;
    direction direc;
    int  current_turn;

    Game(const Game& game) : current_card{game.current_card}, players{game.players},direc{game.direc},current_turn{game.current_turn} {}; //copy constructor
    Game& operator=(const Game& game) {current_card = game.current_card; players= game.players; direc=game.direc; current_turn=game.current_turn ;return *this;}; //operator=



public:
    //public members and functions
    //Game(Card current_card=Card(),  vector<Player> players = {0},int direc=forward,int  current_turn=0) : current_card{current_card}, players{players},direc{direc},current_turn{current_turn} {}; //default construtor and init list constructor
   // Game(Card current_card=Card(),  vector<Player> players = {0},direction direc = direction::forward, int  current_turn=0) : current_card{current_card}, players{players},direc{direc},current_turn{current_turn} {}; //default construtor and init list constructor
    Game():direc{direction::forward},current_turn{0}{};
    Card get_cuurent_card() const { return current_card; }
    vector<Player> get_players () const { return players ; }
    int get_direc() const {
        switch(this->direc) {
            case direction::forward :
                return 1;
            case direction::backwards :
                return -1;
        }
    }
    void set_direc()  {
        switch(direc) {
            case direction::forward :
                direc=direction::backwards ;
            case direction::backwards :
                direc=direction::forward ;
        }
    }
    int get_current_turn() const { return current_turn; }
    void start();
    int skip(const Card& card, const int num_of_players );
    void winner(const Player& player);
    };
#endif




