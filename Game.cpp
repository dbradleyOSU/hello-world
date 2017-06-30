/*********************************************************************
 * Name: Dan Bradley
 * Date: 10.16.16
 * Description: This is the function definition file for the Game class.
 *********************************************************************/



#include "Game.hpp"

/***************************************************************************************************
 * Description: The constructor for Game Class. It intakes an int value of 1 or 2 to determine what
 * type of die each player will have. These will provided by a user selection in main.
 *************************************************************************************************/

Game::Game(int player1, int player2) {

    int player1Sides, player2Sides;
    int loaded1, loaded2;

    int gameRounds;

    //If both players are regular Die
    if(player1 == 1 && player2 == 1) {

       do {

           std::cout << "How many sides would you like for player 1?" << std::endl;
           std::cin >> player1Sides;
           valInt(player1Sides);

           p1.setSides(player1Sides);

       } while(player1Sides < 3);

        do {
            std::cout << "How many sides would you like for player 2?" << std::endl;
            std::cin >> player2Sides;
            valInt(player1Sides);

            p2.setSides(player2Sides);

        } while(player2Sides < 3);

        std::cout <<"Player 1 is using a regular die with " << p1.getSides() << " sides." << std::endl;
        std::cout <<"Player 2 is using a regular die with " << p2.getSides() << " sides." << std::endl;

    }

    //If player 1 is a regular die and player 2 is a loaded die
    else if(player1 == 1 && player2 == 2) {

        do {

            std::cout << "How many sides would you like for player 1?" << std::endl;
            std::cin >> player1Sides;
            valInt(player1Sides);

            p1.setSides(player1Sides);

        } while (player1Sides < 3);

        do {

            std::cout << "How many sides would you like for player 2?" << std::endl;
            std::cin >> player2Sides;
            valInt(player2Sides);

            lp2.setSides(player2Sides);

        } while (player2Sides < 3);

        std::cout << "Which side would you like to be loaded?" << std::endl;
        std::cout << "WARNING: Pick a number greater than or equal to the middle number in the range or the loaded"
                  << std::endl;
        std::cout << "side will the highest possible number." << std::endl;

        std::cin >> loaded2;
        valInt(loaded2);

        lp2.setLoaded(loaded2);

        std::cout <<"Player 1 is using a regular die with " << p1.getSides() << " sides." << std::endl;
        std::cout <<"Player 2 is using a loaded die with " << lp2.getSides() << " sides." << std::endl;
    }

    //If player 1 is a loaded die and player 2 is a regular die
    else if(player1 == 2 && player2 == 1) {

        do {
            std::cout << "How many sides would you like for player 1?" << std::endl;
            std::cin >> player1Sides;
            valInt(player1Sides);

            lp1.setSides(player1Sides);

        } while(player1Sides < 3);

        std::cout << "Which side would you like to be loaded?" << std::endl;
        std::cout << "WARNING: Pick a number greater than or equal to the middle number in the range or the loaded"
                  << std::endl;
        std::cout << "side will the highest possible number." << std::endl;

        std::cin >> loaded1;
        valInt(loaded1);

        lp1.setLoaded(loaded1);


        do {
            std::cout << "How many sides would you like for player 2?" << std::endl;
            std::cin >> player2Sides;
            valInt(player2Sides);

            p2.setSides(player2Sides);

        } while(player2Sides < 3);

        std::cout <<"Player 1 is using a loaded die with " << lp1.getSides() << " sides." << std::endl;
        std::cout <<"Player 2 is using a regular die with " << p2.getSides() << " sides." << std::endl;

    }

    //If both players are loaded die.
    else{

        do {
            std::cout << "How many sides would you like for player 1?" << std::endl;
            std::cin >> player1Sides;
            valInt(player1Sides);

            lp1.setSides(player1Sides);

        } while(player1Sides < 3);


        std::cout << "Which side would you like to be loaded?" << std::endl;
        std::cout << "WARNING: Pick a number greater than or equal to the middle number in the range or the loaded"
                  << std::endl;
        std::cout << "side will the highest possible number." << std::endl;

        std::cin >> loaded1;
        valInt(loaded1);

        lp1.setLoaded(loaded1);

        do {
            std::cout << "How many sides would you like for player 2?" << std::endl;
            std::cin >> player2Sides;
            valInt(player1Sides);

            lp2.setSides(player2Sides);
        } while(player2Sides < 3);

        std::cout << "Which side would you like to be loaded?" << std::endl;
        std::cout << "WARNING: Pick a number greater than or equal to the middle number in the range or the loaded"
                  << std::endl;
        std::cout << "side will the highest possible number." << std::endl;

        std::cin >> loaded2;
        valInt(loaded2);

        lp2.setLoaded(loaded2);

        std::cout <<"Player 1 is using a loaded die with " << lp1.getSides() << " sides." << std::endl;
        std::cout <<"Player 2 is using a loaded die with " << lp2.getSides() << " sides." << std::endl;

    }

    //Set the amount of rounds to play
    do {

        std::cout << "How many rounds would you like to play?" << std::endl;
        std::cin >> gameRounds;
        valInt(gameRounds);

        setRounds(gameRounds);

    } while(gameRounds < 1);

    //Start scores at 0
    setScore1(0);
    setScore2(0);
}


/***************************************************************************************************
 * Description: The play function for the game. It will take integer values to determine if the
 * players are regular die or loaded die. It will then roll each die for user's determined amount of rounds.
 * The player who has the higher number showing each round will get a point. The winner will be the player
 * with the most points at the end of user's chosen amount of rounds. Draws will gain no points to either player
 * but will still count as a played round.
 *************************************************************************************************/

void Game::play(int player1, int player2) {

    int counter = 1;
    int player1Attempt, player2Attempt;

    while(counter <= getRounds()) {

        //If both players are regular die
        if(player1 == 1 && player2 == 1) {

            player1Attempt = p1.roll();
            player2Attempt = p2.roll();

            //Calls a function to determine who won the round.
            roundWin(player1Attempt,player2Attempt);
            counter++;

        }

        //If player 1 is a regular die and player 2 is a loaded die.
        else if(player1 == 1 && player2 == 2) {

            player1Attempt = p1.roll();
            player2Attempt = lp2.loadedRoll();

            roundWin(player1Attempt,player2Attempt);
            counter++;
        }

        //If player 1 is a loaded die and player 2 is a regular die
        else if(player1 == 2 && player2 == 1) {

            player1Attempt = lp1.loadedRoll();
            player2Attempt = p2.roll();

            roundWin(player1Attempt,player2Attempt);
            counter++;
        }

        //If both players are loaded die
        else {

            player1Attempt = lp1.loadedRoll();
            player2Attempt = lp2.loadedRoll();

            roundWin(player1Attempt,player2Attempt);
            counter++;

        }


    }

    //Calls function to declare winner
    finalScore();

}

/***************************************************************************************************
 * Description: This function determines which player 1 the round or if the round ended in a draw.
 * It will output the results each round so that the user can follow the game.
 *************************************************************************************************/

void Game::roundWin(int player1Attempt, int player2Attempt) {

    if(player1Attempt > player2Attempt) {
        score1++;

        std::cout << "Player 1: " << player1Attempt << " vs. Player2: " << player2Attempt << std::endl;

    }

    else if(player1Attempt < player2Attempt) {
        score2++;

        std::cout << "Player 1: " << player1Attempt << " vs. Player2: " << player2Attempt << std::endl;
    }

    else {

        std::cout << "Player 1: " << player1Attempt << " vs. Player2: " << player2Attempt << std::endl;

    }
}

/***************************************************************************************************
 * Description: This function determines who won the game. It will compare player 1 and 2's final
 * scores. It will end in a draw if they are equal.
 *************************************************************************************************/

void Game::finalScore() {

    std::cout << "\n";
    std::cout << "Player 1 won " << getScore1() << " rounds." << std::endl;
    std::cout << "Player 2 won " << getScore2() << " rounds." << std::endl;
    std::cout << "\n";

    if(getScore1() > getScore2())
        std::cout << "Player 1 won the game " << getScore1() << " to " << getScore2() << "." << std::endl;
    else if(getScore1() < getScore2())
        std::cout << "Player 2 won the game " << getScore2() << " to " << getScore1() << "." << std::endl;
    else
        std::cout << "The game ended in a draw: " << getScore1() << " to " << getScore2() << "." << std::endl;
}



void Game::setRounds(int r) {

    rounds = r;

}

void Game::setScore1(int s) {

    score1 = s;
}

void Game::setScore2(int s) {

    score2 = s;
}


int Game::getRounds() {

    return rounds;
}

int Game::getScore1() {

    return score1;
}


int Game::getScore2() {

    return score2;
}



