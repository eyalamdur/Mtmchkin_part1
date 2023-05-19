#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include "utilities.h"

const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;
const int MAX_LEVEL = 10;

class Player {
public:
    /* C'tor of Player class - 2-3 param.
    * @param name - The name of the player.
    * @param maxHP - The maximum healt points the player can have.
    * @param force - The force points the player posses.
    * @return a new instance of Player. */
    Player(std::string name, const int maxHP, const int force = DEFAULT_FORCE);
    

    /* C'tor of Player class - 1 param.
    * @param name - The name of the player.
    * @param maxHP - The maximum healt points the player can have.
    * @return a new instance of Player. */
    Player(std::string name);


    /* C'tor of Player class - 0 param: name & hp.
     * @return a new instance of Player with default values. */
    Player() = default;


    /* D'tor of Player class. */
    ~Player() = default;


    /* Copy of Player class.
    * @param Player& - reference to another Player object.
    * @return a new instance of Player with copied values as the given Player. */
    Player(const Player&) = default;

    
    /* Prints the Player info*/
    void printInfo() const;


    /* Level up player level by one (up to a maximum of level 10).
     * If player level is 10 does nothing. */
    void levelUp();


    /* Returns the player level.
     * @return an int that represent the level of the Player. */
    int getLevel() const;


    /* Raise the player force by given ammount
     * If invalid variable is given nothing changes. */
    void buff(int forcePoints);


    /* Increase the player HP by given ammount (up to the maximum allowed HP - maxHP)
     * @param healthPoints - The intented health points to give to the player.
     * If player has full HP or gets invalid param - nothing changed. */
    void heal(int healthPoints);


    /* Decrease the player HP by given ammount (up to the minimum allowed HP - 0)
     * @param healthPoints - The intented health points to decrese from the player.
     * If given healthPoints is bigger than player current HP reduce current HP to 0. */
    void damage(int healthPoints);


    /* Checks if the player HP has reached to 0.
     * @return true if 0 and false if otherwise.  */
    bool isKnockedOut();


    /* Increase the player coins by given ammount.
     * @param coins - The intented coins points to add to the player. */
    void addCoins(int coins);


    /* Checks if player has the given ammount of coins in his coin bag.
     * if so decrease the player coins by given ammount and returns true.
     * else returns false
     * @param coins - The intented coins points to decrease from the player.
     * @return true if payment succeeded and false if otherwise.  */
    bool pay(int coins);


    /* Calculate the player attack strength (force + level).
     * @return the calculated attack strngth. */
    int getAttackStrength();


    /* Here we are explicitly telling the compiler to use the default methods */
    Player& operator=(const Player& other) = default;

private:
    std::string m_name;
    int m_maxHP;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
    CardStats m_stats;

};


#endif //EX2_PLAYER_H
