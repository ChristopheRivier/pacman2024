#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include "point.h"
#include "element.h"
#include "carte.h"
#include "actions.h"
#include "game.h"


/**
 * Grab the pellets as fast as you can!
 **/

int main()
{
    int width; // size of the grid
    int height; // top left corner is (x=3, y=0)
    cin >> width >> height; cin.ignore();
    cerr << width << " " << height << endl;
    Game g;
    g.initCarte(width, height);

    for (int i = 0; i < height; i++) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall
        g.addCarteLine(i, row);
    }
    g.printCarte();

    // game loop
    while (1) {
        int my_score;
        int opponent_score;
        cin >> my_score >> opponent_score; cin.ignore();
        int visible_pac_count; // all your pacs and enemy pacs in sight
        cin >> visible_pac_count; cin.ignore();
        for (int i = 0; i < visible_pac_count; i++) {
            int pac_id; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string type_id; // ROCK, PAPER, SCISSORS, or DEAD
            cin >> pac_id >> mine >> x >> y >> type_id; cin.ignore();
        }
        int visible_pellet_count; // all pellets in sight
        cin >> visible_pellet_count; cin.ignore();
        for (int i = 0; i < visible_pellet_count; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "MOVE 0 15 10" << endl; // MOVE <pacId> <x> <y>
    }
}