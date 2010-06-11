#include "Main_Game_State.h"

////////////////////////////////////////////////////
/////////////Game Play State////////////////////////
////////////////////////////////////////////////////

GamePlay* GamePlay::Ins()
{
	static GamePlay instance;
	return & instance;
}

void GamePlay::begin()
{
	//TODO: get player 1 and player 2 characters from char_selection
	//TODO: load in drop patterns for player 1 and 2
	//TODO: if player2 is a computer, setup AI for that character
	screen = GDH::Ins()->getScreen();
	boardSize[0].x = boardSize[0].y = boardSize[1].x = boardSize[1].y = 0;
	pieceSize.h = pieceSize.w = 25;
	boardSize[0].h = boardSize[1].h = BOARDHEIGHT * pieceSize.h;
	boardSize[0].w = boardSize[1].w = BOARDWIDTH * pieceSize.w;
	boardSize[1].x += boardSize[1].w + 50;
}

void GamePlay::update(int msPassed)
{
	//TODO: update game board
	//TODO: move piece while checking for collision
	if(msPassed > 1000)
	{
		for(int p = 0; p < 2; p++)
		{
			if(pieceCanMove(eDown, p))
				piecePointer[p]->moveDown();
		}
	}
	//TODO: check for piece destruction
	//TODO: update AI if player 2 is an AI
}

void GamePlay::draw()
{
	//TODO: draw background
	//TODO: draw characters
	//TODO: draw UI (conveyer belt, score, difficulty?, names of characters, etc)
	for(int p = 0; p < 2; p++)
	{
		//TODO: draw game board
		SDL_FillRect(screen,&boardSize[p],0x000000);
		//TODO: draw pieces
		for(int y = 0; y < BOARDHEIGHT; y++)
		{
			for(int x = 0; x < BOARDWIDTH; x++)
			{
				drawPieceInPosition(gameBoard[p][x][y], x, y, 1);
			}
		}
		//TODO: draw held pieces
		drawPieceInPosition(piecePointer[p]->getMainPiece(), piecePointer[p]->getX(), piecePointer[p]->getY(), p);
		drawPieceInPosition(piecePointer[p]->getOffPiece(), piecePointer[p]->getOffX(), piecePointer[p]->getOffY(), p);
	}
	//TODO: draw anything that would cover pieces
}

void GamePlay::input(SDL_Event e)
{
	//TODO: get input from player, if player is computer, get input from computer
	//TODO: input should set flags for the update to handle
}

void GamePlay::exit()
{
	//TODO: clean up
}

void GamePlay::drawPieceInPosition(int piece, int x, int y, int boardNumber) //TODO: This function needs to be revised later
{
	if(piece == 0)
		return;
	SDL_Rect boardPosition = boardSize[boardNumber];
	Uint32 color;
	if(piece & eRedPiece)
		color = 0xff0000;
	if(piece & eBluePiece)
		color = 0x0000ff;
	if(piece & eGreenPiece)
		color = 0x00ff00;
	if(piece & eYellowPiece)
		color = 0xff00ff;
	pieceSize.x = (x * pieceSize.w) + boardPosition.x;
	pieceSize.y = (y * pieceSize.h) + boardPosition.y;
	SDL_FillRect(screen,&pieceSize,color);
}

bool GamePlay::pieceCanMove(int direction, int player)
{
	//TODO: fill in this function. use direction enums for simplicity
	return true;
}