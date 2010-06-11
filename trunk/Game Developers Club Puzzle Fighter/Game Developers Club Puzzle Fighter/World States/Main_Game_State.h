#pragma once
#include "World_States Core.h"

#define BOARDHEIGHT		14
#define BOARDWIDTH		6

class pieceClass
{
public:
	int getX() {return x;}
	int getY() {return y;}
	int getD() {return d;}
	int getOffX() {if(d == 3) return x-1; else if(d == 1) return x+1; else return x;}
	int getOffY() {if(d == 0) return y-1; else if(d == 2) return y+1; else return y;}
	int getMainPiece() {return piece1Val;}
	int getOffPiece() {return piece2Val;}
	void setMainPiece(int p) {piece1Val = p;}
	void setOffPiece(int p) {piece2Val = p;}
	void setX(int nx) {x = nx;}
	void setY(int ny) {y = ny;}
	void setD(int nd) {d = nd;}
	void moveDown() {y += 1;}
	void moveLeft() {x -= 1;}
	void moveRight() {x += 1;}
	void rotateLeft() {d -= 1; if(d < 0) d = 3;}
	void rotateRight() {d += 1; d = d%4;}
private:
	int piece1Val;
	int piece2Val;
	int x;
	int y;
	int d;  // direction of the second piece, 0 is up 1 is right 2 is down 3 is left;
};

enum inputFlags
{
	eP1Right		= 0x0001,
	eP1Down			= 0x0002,
	eP1Left			= 0x0004,
	eP1Special		= 0x0008,
	eP2Right		= 0x0010,
	eP2Down			= 0x0020,
	eP2Left			= 0x0040,
	eP2Special		= 0x0080,
};
enum direction
{
	eUp = 0,
	eRight = 1,
	eDown = 2,
	eLeft = 3
};
//this is the main function, that will handle all the gameplay stuff
//this is going to be the most complex by far
class GamePlay : public World_State
{
protected:
	//these hold pointers to the two characters to be played this round 
	Character *player[2];
	//TODO: add sdl_surfaces and rects for the background and border art, etc
	SDL_Surface *screen;
	SDL_Rect boardSize[2];
	SDL_Rect pieceSize;
	//TODO: add custom classes to handle the tetris games
	int gameBoard[2][BOARDWIDTH][BOARDHEIGHT];
	pieceClass *piecePointer[2];
	int flags, downflags, oldflags;
	//TODO: custom private functions
	void drawPieceInPosition(int piece, int x, int y, int boardNumber);
	bool pieceCanMove(int direction, int p);
	//TODO: add animation variables to hold whatever animations the design team comes up with
public:
	static GamePlay * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
	//TODO: custom public functions
	pieceClass* getPiece(int i) {return piecePointer[i];};
	int getBoardPos(int i, int x, int y) {return gameBoard[i][x][y];};
};