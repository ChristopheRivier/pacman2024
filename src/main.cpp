#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool param = true;
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
    g.calculInit();
    g.printCarte();

    // game loop
    while (1) {
        g.init();
        int my_score;
        int opponent_score;
        cin >> my_score >> opponent_score; cin.ignore();
        g.addSCore(my_score, opponent_score);
        int visible_pac_count; // all your pacs and enemy pacs in sight
        cin >> visible_pac_count; cin.ignore();
        for (int i = 0; i < visible_pac_count; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string typeId; // ROCK, PAPER, SCISSORS, or DEAD
            cin >> pacId >> mine >> x >> y >> typeId; cin.ignore();
            PacMan e(Point(x, y), Element::Pac, pacId, mine, typeId);
			if (param) {
				e.print();
				cerr << pacId << " " << mine << " " << x << " " << y << " " << typeId << endl;
			}
			g.addPac(e);

        }
        int visible_pellet_count; // all pellets in sight
        cin >> visible_pellet_count; cin.ignore();
        for (int i = 0; i < visible_pellet_count; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
			Element e(Point(x, y), Element::Bouffe, value, false);

			if (param) {
				cerr << x << " " << y << " " << value << endl;
				e.print();
			}
			g.addPillule(e);
        }
        cout << g.calculDeplacement() << endl;
    }
}