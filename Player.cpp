#include "Player.h"
#include "Card.h"
using namespace std;

bool Player::play(Card& current_card) {
    int num_choice;
    bool is_legal_choice = false;
    bool player_put_card = false; // false player takes new card, true- player put legal card
    cout << "current: " << current_card << endl;
    cout << name << ",your turn - " << endl;
    cout << "Your cards: : ";
    for (int i = 1; i < this->num_of_cards + 1; i++) cout << "(" << i << ")" << vec[i - 1] << " " ;
    cout << "  "<<endl;

    while (!is_legal_choice) {
        cin >> num_choice;
        if (num_choice <= 0 || num_choice > vec.size()) {
            Card new_card = Card::generate_card();
            vec.push_back(new_card);
            ++num_of_cards;
            break;
        } else {
            Card &choice = vec[num_choice - 1];
            is_legal_choice = current_card.is_legal(choice);
            if (is_legal_choice) {
                current_card=choice;
                player_put_card = true;
                vec.erase(vec.begin() + num_choice - 1);
                --num_of_cards;
                break;
            }
            cout << "You can't put " << choice << " on " << current_card << endl;

        }

    }
    return player_put_card;
}



