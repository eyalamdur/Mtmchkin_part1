#include "Mtmchkin.h"

const int STARTING_CARD = 0;

/* C'tor of the game:
 * @param playerName - The name of the player.
 * @param cardsArray - A ptr to the cards deck.
 * @param numOfCards - Num of cards in the deck.
 * @result An instance of Mtmchkin. */
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    this->player = Player(playerName);
    this->cardsArray = new Card[numOfCards] ;
    for (int cardIdx = STARTING_CARD; cardIdx < numOfCards; cardIdx++){
        this->cardsArray[cardIdx] = cardsArray[cardIdx];
    }
    this->deckSize = numOfCards;
    this->currentCardIdx = STARTING_CARD;
    this->status = GameStatus::MidGame;
    return;
}

/* Play the next Card - according to the instruction in the exercise document
 * @return void. */
void Mtmchkin::playNextCard(){
    this->cardsArray[this->currentCardIdx].printInfo();
    this->cardsArray[this->currentCardIdx].applyEncounter(this->player);
    
    this->player.printInfo();
    this->currentCardIdx+=1;
    if (this->currentCardIdx == this->deckSize){
        this->currentCardIdx = STARTING_CARD;
    }
    if (this->player.getLevel() == MAX_LEVEL){
        this->status = GameStatus::Win;
    }
    return;
}

/* Check if the game ended:
 * @return True if the game ended False otherwise */
bool Mtmchkin::isOver() const{
    if (this->status == GameStatus::MidGame){
        return false;
    }
    return true;
}

/* Get the status of the game:
 * @return GameStatus - the current status of the running game. */
GameStatus Mtmchkin::getGameStatus() const{
    return this->status;
}