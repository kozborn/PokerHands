#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Card{
public:
    string value;
    string color;
};

struct deal{
    vector<Card> player1Cards;
    vector<Card> player2Cards;
};

vector<string> split(const string& s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}

int main()
{
    int player1Wins = 0;
    int player2Wins = 0;
    string line = "" ;
    string cardTemp;
    vector<deal> deals;
    vector <string> cards;
    cout << "Poker Hands!" << endl;
    fstream infile("poker_hands_short.txt");
    int counter = 1;
    if (infile.is_open())
    {
        while ( getline (infile,line) )
        {
            cards = split(line, ' ');
            deal currentDeal;
            for(vector<string>::iterator it = cards.begin(); it != cards.end(); ++it) {
                Card *c = new Card();
                c->value = (*it).at(0);
                c->color = (*it).at(1);
                if(counter < 5)
                    currentDeal.player1Cards.push_back(*c);
                else
                    currentDeal.player2Cards.push_back(*c);
                counter++;
                if(counter == 10)
                    counter = 0;
            }
            deals.push_back(currentDeal);
        }

        infile.close();
    }
    else cout << "Unable to open file" << endl;

    cout << deals.size() << endl;

    for(vector<deal>::iterator id = deals.begin(); id != deals.end(); ++id) {
//        cout << (*id).player1Cards.size() << " " << (*id).player2Cards.size() << endl;
        for(vector<Card>::iterator ic = (*id).player1Cards.begin(); ic != (*id).player1Cards.end(); ++ic) {
//            cout << (*ic).value << " " << (*ic).color;
        }
    }

    return 0;
}

