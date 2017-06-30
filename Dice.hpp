/*********************************************************************
 * Name: Dan Bradley
 * Date: 10.16.16
 * Description: This is the header file for the Die class.
 *********************************************************************/


#ifndef DIE_HPP
#define DIE_HPP


class Die {

protected:

    int sides;

public:

    Die();
    Die(int s);

    int getSides();
    void setSides(int s);

    int roll();
};


#endif //DIE_HPP
