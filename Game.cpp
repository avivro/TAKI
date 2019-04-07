#include "Game.h"
#include "Player.h"
#include "Card.h"
#define forward 1
#define backwards -1
using namespace std;

//enum class direction { NAC, forward,backwards }; //enumartion of direction. NAC - is not avaiable direction

int Game::skip(const Card& card , const int num_of_players ){
    switch(card.get_sign()) {
        case sign::PLUS :
            return 0;
        case sign::CD :
            if (num_of_players==2) return 2;
            return 1;
        case sign::STOP :
            return 2;
        default :
            return 1;
    }
}

void Game::winner(const Player& player) {
    if (player.get_vec().size() == 0) {
        cout << player.get_name() << " wins! ";
        exit(EXIT_SUCCESS);
    }
}

void Game::start() {
        int num_players, num_cards = 0;
        bool player_put_card;

        cout << "How many players? " << endl;
        cin >> num_players;
        cout << "How many cards? " << endl;
        cin >> num_cards;

        if (num_cards <= 0 || num_players <= 0) {
            cout << "wrong input!!!" << endl;
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i<(num_players); ++i){
            string name;
            cout << "player number name " <<(i+1)<<"? " << endl;
            cin >> name;
            players.push_back(Player(name,num_cards));
        }

      current_card=Card::generate_card();

         while(true){
             player_put_card=players[current_turn].play(current_card);
             if(player_put_card){
                 //if(!((num_players==2)&& (current_card.get_sign()==sign::CD||current_card.get_sign()==sign::PLUS||current_card.get_sign()==sign::PLUS)))
                 Game::winner(players[current_turn]);
                 if(current_card.get_sign()==sign::CD) set_direc();
                 current_turn=(current_turn+get_direc()*skip(current_card,num_players))%num_players;
             }
             else current_turn=(current_turn+get_direc()*1)%num_players;

         }
    }


