#include "Player.h"
#include "Board.h"
#include <conio.h>
#include <vector>
#include <algorithm>
#include <SDL/SDL.h>

using namespace std;

Player::Player(int hisColor,string hisName)
{
    score=0;
    color=hisColor;
    name=hisName;
}

Player::~Player(){}

int Player::getPos()
{

       int j,continuer=1;
         while (continuer)
 {
    SDL_Event event; SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
        for (j = 0; j < 7; j++)
            {

            				if ( event.button.x > j*77+206 && event.button.x <j*77+51+206
                    			 && event.button.y > 91&& event.button.y < (91+429)) {
                                  return j;


  }
}
break;
}
     }
        }


int PlayerAI::minimax(int state[6][7], int currentDepth, bool isMax, int i, int j)
{

    Board Table(state);

	if (Table.isWin(i, j, 2) && !isMax)
		return PLUS_INFINITY * (finalDepth - currentDepth + 1);


	else if (Table.isWin(i, j, 1) && isMax)
		return MINUS_INFINITY * (finalDepth - currentDepth + 1);


    else if (currentDepth == finalDepth)
		return Table.heuristic(1);

    int save[6][7];
    int scores[7];
    for (int i=0;i<6;i++)for(int j=0;j<7;j++) save[i][j]=state[i][j];
    for(int j=0;j<7;j++) scores[j]=-9999;
    if (isMax)
        {
            vector <int> fils;
            for (int C=0; C<7; C++)
            {
                int L = Table.emptyPlace(C);
                if (L!=-1)
                {
                    state[L][C]= 2;
                    int son = minimax(state,currentDepth+1,false,L,C);
                    fils.push_back(son);
                    nbreNoeuds++;
                    state[L][C] = save[L][C];
                    scores[C]=son;

                }
            }

            for(int j=0;j<7;j++)
                if ( scores[j]==  *max_element(fils.begin(), fils.end()) )
                {
                    if (currentDepth==0) return j;
                    else return scores[j];
                }
        }

    else if (!isMax)
        {
            vector <int> fils;
            for (int C=0; C<7; C++)
            {
                int L = Table.emptyPlace(C);
                if (L!=-1)
                {
                    state[L][C]= 1;
                    int son = minimax(state,currentDepth+1,true,L,C);
                    fils.push_back(son);
                    nbreNoeuds++;
                    state[L][C] = save[L][C];
                    scores[C]=son;

                }
            }

            for(int j=0;j<7;j++)
                if ( scores[j]==  *min_element(fils.begin(), fils.end()) )
                {
                    if (currentDepth==0) return j;
                    else return scores[j];
                }
        }
}


int PlayerAI::alpha_beta(int state[6][7], int currentDepth, bool isMax, int i, int j, int alpha, int beta)
{

    Board Table(state);

	if (Table.isWin(i, j, 2) && !isMax)
		return PLUS_INFINITY * (finalDepth - currentDepth + 1);


	else if (Table.isWin(i, j, 1) && isMax)
		return MINUS_INFINITY * (finalDepth - currentDepth + 1);


    else if (currentDepth == finalDepth)
		return Table.heuristic(1);


    int save[6][7];
    int scores[7];
    for (int i=0;i<6;i++)for(int j=0;j<7;j++) save[i][j]=state[i][j];
    for(int j=0;j<7;j++) scores[j]=-9999;
    if (isMax)
        {
            int bestValue = -10000000; // MOINS INFINI
            vector <int> fils;
            for (int C=0; C<7; C++)
            {
                int L = Table.emptyPlace(C);
                if (L!=-1)
                {
                    state[L][C]= 2;
                    int value = alpha_beta(state,currentDepth+1,false,L,C,alpha,beta);
                    fils.push_back(value);
                    nbreNoeuds++;
                    state[L][C] = save[L][C];
                    scores[C]=value;

                    bestValue = max( bestValue, value);
                    alpha = max( alpha, bestValue);
                    if (beta<alpha)
                        break;

                }
            }

            for(int j=0;j<7;j++)
                if ( scores[j]==  *max_element(fils.begin(), fils.end()) )
                {
                    if (currentDepth==0) return j;
                    else return scores[j];
                }
        }

    else if (!isMax)
        {
            int bestValue = +10000000; // PLUS INFINI
            vector <int> fils;
            for (int C=0; C<7; C++)
            {
                int L = Table.emptyPlace(C);
                if (L!=-1)
                {
                    state[L][C]= 1;
                    int value = alpha_beta(state,currentDepth+1,true,L,C,alpha,beta);
                    fils.push_back(value);
                    nbreNoeuds++;
                    state[L][C] = save[L][C];
                    scores[C]=value;

                    bestValue = min( bestValue, value);
                    beta = min( beta, bestValue);
                    if (beta<alpha)
                        break;

                }
            }

            for(int j=0;j<7;j++)
                if ( scores[j]==  *min_element(fils.begin(), fils.end()) )
                {
                    if (currentDepth==0) return j;
                    else return scores[j];
                }
        }



}
