
/*********************************************************************
 * Name: Dan Bradley
 * Date: 10.16.16
 * Description: This is the function definition file for the Die class.
 *********************************************************************/

#include "Die.hpp"
#include <cstdlib>
#include <time.h>


Die::Die() {

    sides = 6;
}

Die::Die(int s) {

    sides = s;

}

int Die::getSides() {

    return sides;
}

void Die::setSides(int s) {

    sides = s;
}

/***************************************************************************************************
 * Description: The die's roll function will output a random number from 1-sides.
 *************************************************************************************************/

int Die::roll() {

    return (rand() % getSides()) + 1;
}
