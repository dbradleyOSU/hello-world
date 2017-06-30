/*********************************************************************
 * Name: Dan Bradley
 * Date: 10.16.16
 * Description: This is the header file for the Game class
 *********************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include "LoadedDie.hpp"


class Game {

private:

    int score1;
    int score2;
    int rounds;

    LoadedDie lp1;
    LoadedDie lp2;

    Die p1;
    Die p2;

public:

    Game(int player1, int player2);

    void setScore1(int s);
    void setScore2(int s);
    void setRounds(int r);

    int getScore1();
    int getScore2();
    int getRounds();

    void play(int player1, int player2);
    void roundWin(int player1Attempt, int player2Attempt);
    void finalScore();

};


#endif //GAME_HPP
