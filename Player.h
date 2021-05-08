#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>


using namespace std;

class Player
{
    public:
        Player(){};
        Player(int,string);
        ~Player();
        int getPos();

        string name;

        protected:
        int color;
        int score;

    friend class Board;
};

class PlayerAI: Player
{
    public:
        PlayerAI():name("CPU"){PLUS_INFINITY=512; MINUS_INFINITY=-512; finalDepth=6; nbreNoeuds=0;}
        minimax(int state[6][7], int currentDepth, bool isMax, int i, int j);
        alpha_beta(int state[6][7], int currentDepth, bool isMax, int i, int j, int alpha, int beta);

    private:
        std::string const name="Com";
        int finalDepth;
        int PLUS_INFINITY;
        int MINUS_INFINITY;
        int nbreNoeuds;

    friend class Board;

};

#endif // PLAYER_H

