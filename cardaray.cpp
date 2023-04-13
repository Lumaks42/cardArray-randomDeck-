// cardaray.cpp 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
// 2 to 10 regular numbers
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card
{
private:
    int number;
    Suit suit;
public:
    card()                              // constructor
        { }
    void set(int n, Suit s)             // value seting
        { suit = s, number = n; }
    void display();                     // show card
};

void card::display()
{
    if (number >= 2 && number <= 10)
        cout << number;
    else
    {
        switch (number)
        {
            case jack:  cout << "J"; break;
            case queen: cout << "Q"; break;
            case king:  cout << "K"; break;
            case ace:   cout << "A"; break;
        }
    }

    switch (suit) 
    {
        case clubs:         cout << static_cast<char>(5); break;
        case diamonds:      cout << static_cast<char>(4); break;
        case hearts:        cout << static_cast<char>(3); break;
        case spades:        cout << static_cast<char>(6); break;
    }
}

int main()
{
    card deck[52];
    int a;
    cout << endl;
    for (a = 0; a < 52; a++)        // create an ordered deck of cards
    {
        int num = (a % 13) + 2;
        Suit su = Suit(a / 13);
        deck[a].set(num, su);
    }

    // show original deck of cards
    cout << "original deck: \n";
    for (a = 0; a < 52; a++) 
    {
        deck[a].display();
        cout << " ";
        if (!((a + 1) % 13))        // start new string after 13 card
            cout << endl;
    }
    srand(time(NULL));              // initialize random number generator
    for (a = 0; a < 52; a++)
    {
        int c = rand() % 52;        // choises random cards
        card temp = deck[a];        // and change it from the current one
        deck[a] = deck[c];
        deck[c] = temp;
    }

    // show shuffled deck
    cout << "\nshuff deck: \n";
    for (a = 0; a < 52; a++)
    {
        deck[a].display();
        cout << " ";
        if (!((a + 1) % 13))           // start new string after 13 card
            cout << endl;
    }

    return 0;
}

