#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;
#include "../src/point.h"
#include "../src/element.h"
#include "../src/carte.h"
#include "../src/actions.h"
#include "../src/game.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {

  Game g;
  g.initCarte(35, 13);
  g.addCarteLine(0,"###################################");
	g.addCarteLine(1,"### # #   # #   # #   # #   # # ###");
	g.addCarteLine(2,"### # # ### ### # # ### ### # # ###");
	g.addCarteLine(3,"      #     #         #     #      ");
	g.addCarteLine(4,"##### # ### # ### ### # ### # #####");
	g.addCarteLine(5,"    #   ###   #     #   ###   #    ");
	g.addCarteLine(6,"### # # ### # # ### # # ### # # ###");
	g.addCarteLine(7,"      #       #     #       #      ");
	g.addCarteLine(8,"### # ##### # # ### # # ##### # ###");
	g.addCarteLine(9,"    #       #         #       #    ");
	g.addCarteLine(10,"### # ### # # ### ### # # ### # ###");
	g.addCarteLine(11,"### #   # # #   # #   # # #   # ###");
	g.addCarteLine(12,"###################################");

  PacMan e=PacMan(Point(19,6), Element::Pac, 0 ,true, "ROCK");
  g.addPac(e);
  e=PacMan(Point(5,3), Element::Pac, 1 ,true, "PAPER");
  g.addPac(e);
  e=PacMan(Point(29,3), Element::Pac, 1 ,false, "PAPER");
  g.addPac(e);
  e=PacMan(Point(0,3), Element::Pac, 2 ,true, "SCISSORS");
  g.addPac(e);
  e=PacMan(Point(34,3), Element::Pac, 2 ,false, "SCISSORS");
  g.addPac(e);
  e=PacMan(Point(29,8), Element::Pac, 3 ,true, "ROCK");
  g.addPac(e);
  e=PacMan(Point(5,8), Element::Pac, 3 ,false, "ROCK");
  g.addPac(e);
  Element el=Element(Point(19,5), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(19,8), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(19,9), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(4,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(3,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(2,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(1,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(33,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(32,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(31,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(30,3), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,2), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,1), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,4), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,5), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,6), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,7), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,9), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,10), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(5,11), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,7), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,6), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,5), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,4), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,2), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,1), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,9), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,10), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(29,11), Element::Bouffe, 1 ,false);
  g.addPillule(el);
  el=Element(Point(15,7), Element::Bouffe, 10 ,false);
  g.addPillule(el);
  el=Element(Point(16,7), Element::Bouffe, 10 ,false);
  g.addPillule(el);
  el=Element(Point(18,7), Element::Bouffe, 10 ,false);
  g.addPillule(el);
  el=Element(Point(19,7), Element::Bouffe, 10 ,false);
  g.addPillule(el);


  // Expect two strings not to be equal.
  EXPECT_STREQ("MOVE 0 19 7|MOVE 1 5 5|MOVE 2 2 3|MOVE 3 29 10", g.calculDeplacement().c_str());
  g.init();


  e=PacMan(Point(19,7), Element::Pac, 0 ,true, "ROCK");
g.addPac(e);
e=PacMan(Point(15,7), Element::Pac, 0 ,false, "ROCK");
g.addPac(e);
e=PacMan(Point(5,4), Element::Pac, 1 ,true, "PAPER");
g.addPac(e);
e=PacMan(Point(29,4), Element::Pac, 1 ,false, "PAPER");
g.addPac(e);
e=PacMan(Point(1,3), Element::Pac, 2 ,true, "SCISSORS");
g.addPac(e);
e=PacMan(Point(33,3), Element::Pac, 2 ,false, "SCISSORS");
g.addPac(e);
e=PacMan(Point(29,9), Element::Pac, 3 ,true, "ROCK");
g.addPac(e);
e=PacMan(Point(5,7), Element::Pac, 3 ,false, "ROCK");
g.addPac(e);
el=Element(Point(17,7), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(19,5), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(19,8), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(19,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,2), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,1), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,5), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,6), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,10), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,11), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(32,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(31,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(30,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(2,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(3,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(4,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(28,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(27,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(26,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(25,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(24,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(23,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,7), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,6), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,5), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,2), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,1), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,10), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,11), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(16,7), Element::Bouffe, 10 ,false);
g.addPillule(el);
el=Element(Point(18,7), Element::Bouffe, 10 ,false);
g.addPillule(el);
  EXPECT_STREQ("MOVE 0 17 7|MOVE 1 4 3|MOVE 2 34 3|MOVE 3 27 9", g.calculDeplacement().c_str());
  g.init();

e=PacMan(Point(18,7), Element::Pac, 0 ,true, "ROCK");
g.addPac(e);
e=PacMan(Point(5,3), Element::Pac, 1 ,true, "PAPER");
g.addPac(e);
e=PacMan(Point(0,3), Element::Pac, 2 ,true, "SCISSORS");
g.addPac(e);
e=PacMan(Point(32,3), Element::Pac, 2 ,false, "SCISSORS");
g.addPac(e);
e=PacMan(Point(28,9), Element::Pac, 3 ,true, "ROCK");
g.addPac(e);
el=Element(Point(17,7), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(4,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(3,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(2,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(31,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(30,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,2), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,1), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,5), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,6), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,10), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,11), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(27,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(26,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(25,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(24,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(23,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(16,7), Element::Bouffe, 10 ,false);
g.addPillule(el);
  EXPECT_STREQ("MOVE 0 19 8|MOVE 1 5 1|MOVE 2 2 3|MOVE 3 29 8", g.calculDeplacement().c_str());
  g.init();
  e=PacMan(Point(19,7), Element::Pac, 0 ,true, "ROCK");
g.addPac(e);
e=PacMan(Point(5,2), Element::Pac, 1 ,true, "PAPER");
g.addPac(e);
e=PacMan(Point(1,3), Element::Pac, 2 ,true, "SCISSORS");
g.addPac(e);
e=PacMan(Point(31,3), Element::Pac, 2 ,false, "SCISSORS");
g.addPac(e);
e=PacMan(Point(29,9), Element::Pac, 3 ,true, "ROCK");
g.addPac(e);
el=Element(Point(17,7), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(19,5), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(19,8), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(19,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,1), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,5), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,6), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,10), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(5,11), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(30,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(2,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(3,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(4,3), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(27,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(26,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(25,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(24,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(23,9), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,7), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,6), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,2), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,1), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,10), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(29,11), Element::Bouffe, 1 ,false);
g.addPillule(el);
el=Element(Point(16,7), Element::Bouffe, 10 ,false);
g.addPillule(el);
 EXPECT_STREQ("MOVE 0 17 7|MOVE 1 5 1|MOVE 2 2 3|MOVE 3 29 8", g.calculDeplacement().c_str());
 
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
