#include <string>
#include "Player.h"
#include "utilities.h"

const int MINIMUM_VALUE = 0;
const int STARTING_LEVEL = 1;


/* C'tor of Player class - 2-3 param.
 * @param name - The name of the player.
 * @param maxHP - The maximum healt points the player can have.
 * @param force - The force points the player posses.
 * @return a new instance of Player. */
Player::Player(std::string name, const int maxHP, const int force){
    // Param validation
    this->m_force = force;
    this->m_maxHP = maxHP;
    if (force < MINIMUM_VALUE){
        this->m_force = DEFAULT_FORCE;
    }
    if (maxHP < MINIMUM_VALUE){
        this->m_maxHP = DEFAULT_MAX_HP;
    }

    this->m_name = name;
    this->m_level = STARTING_LEVEL;
    this->m_hp = m_maxHP;
    this->m_coins = MINIMUM_VALUE;
    return;
    }

/* C'tor of Player class - 1 param.
 * @param name - The name of the player.
 * @param maxHP - The maximum healt points the player can have.
 * @return a new instance of Player. */
Player::Player(std::string name){
    // Param validation
    this->m_name = name;
    this->m_level = STARTING_LEVEL;
    this->m_force = DEFAULT_FORCE;
    this->m_maxHP = DEFAULT_MAX_HP;
    this->m_hp = m_maxHP;
    this->m_coins = MINIMUM_VALUE;
    return;
    }

/* Prints the Player info:*/
void Player::printInfo() const{
    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force, this->m_hp, this->m_coins);
    return;
}

/* Level up player level by one (up to a maximum of level 10).
 * If player level is 10 does nothing. */
void Player::levelUp(){
    if (this->m_level < MAX_LEVEL){
        this->m_level +=1;
    }
    return;
}

/* Returns the player level.
 * @return an int that represent the level of the Player. */
int Player::getLevel() const{
    return this->m_level;
}

/* Raise the player force by given ammount
 * If player level is 10 does nothing. */
void Player::buff(int forcePoints){
    if (forcePoints > MINIMUM_VALUE){
        this->m_force += forcePoints;
    }
    return;
}

/* Increase the player HP by given ammount (up to the maximum allowed HP - maxHP)
 * @param healthPoints - The intented health points to give to the player.
 * If player has full HP or gets invalid param - nothing changed. */
void Player::heal(int healthPoints){
    if (healthPoints > MINIMUM_VALUE){
        if (healthPoints + this->m_hp < this->m_maxHP){
            this->m_hp += healthPoints;
        }
        else{
            this->m_hp = m_maxHP;
        }
    }
    return;
}

/* Decrease the player HP by given ammount (up to the minimum allowed HP - 0)
 * @param healthPoints - The intented health points to decrese from the player.
 * If given healthPoints is bigger than player current HP reduce current HP to 0. */
void Player::damage(int healthPoints){
    if (healthPoints > MINIMUM_VALUE){
        if (this->m_hp - healthPoints >= MINIMUM_VALUE){
            this->m_hp -= healthPoints;
        }
        else{
            this->m_hp = MINIMUM_VALUE;
        }
    }
    return;
}

/* Checks if the player HP has reached to 0.
 * @return true if 0 and false if otherwise.  */
bool Player::isKnockedOut(){
    if (this->m_hp == MINIMUM_VALUE){
        return true;
    }
    return false;
}

/* Increase the player coins by given ammount.
 * @param coins - The intented coins points to add to the player. */
void Player::addCoins(int coins){
    if (coins > MINIMUM_VALUE){
        this->m_coins += coins;
    }
    return;
}

/* Checks if player has the given ammount of coins in his coin bag.
 * if so decrease the player coins by given ammount and returns true.
 * else returns false
 * @param coins - The intented coins points to decrease from the player.
 * @return true if payment succeeded and false if otherwise.  */
bool Player::pay(int coins){
    if (this->m_coins >= coins){
        this->m_coins -= coins;
        return true;
    }
    return false;
}

/* Calculate the player attack strength (force + level).
 * @return the calculated attack strngth. */
int Player::getAttackStrength(){
    return this->m_force + this->m_level;
}


