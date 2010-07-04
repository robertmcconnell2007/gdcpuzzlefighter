#pragma once
#include "World_States Core.h"
#include <iostream>
using namespace std;

#define BOARDHEIGHT		14
#define BOARDWIDTH		6
#define NORESULT        -1
#define PIECEDROPTIME   800

enum inputFlags
{
	eNoInput			= 0x0000,
	eInputRight			= 0x0001,
	eInputDown			= 0x0002,
	eInputLeft			= 0x0004,
	eInputSpecial		= 0x0008,
	eInputRotateC		= 0x0010,
	eInputRotateCC		= 0x0020,
};

enum colorFlags
{
	eBlack			= 0x0000,
	eRed			= 0x0001,
	eBlue			= 0x0002,
	eGreen			= 0x0004,
	eYellow			= 0x0008,
	eBomb			= 0x0010,
	eTimered		= 0x0020,
};

enum direction
{
	eUp = 0,
	eLeft = 1,
	eDown = 2,
	eRight = 3,
	eNone = 4,
	eDirs,
};

static const int xCtr[] = {0,-1,0,1,0};
static const int yCtr[] = {-1,0,1,0,0};

class pieceClass
{
private:
	//x/y position of center, and direction of side
	int x, y, d;
	//center color and side color
	int CC, SC;
	//int testerInt;
public:
	pieceClass(): x(0), y(0), d(eNone), 
		CC(0), SC(0)//, testerInt(0)
	{}
	void resetPiece(int a_baseX, int a_baseY);
	void movePiece(int a_dir);
	void rotateClockwise();
	void rotateCounterClockwise();

	inline int getX() {return x;}
	inline int getY() {return y;}
	inline int getD() {return d;}
	inline int getCC() {return CC;}
	inline int getSC() {return SC;}
	bool operator==(pieceClass other)
	{
		if(x == other.getX() && y == other.getY() && d == other.getD())
			return true;
		return false;
	}
};

struct area_block
{
	//X1 and Y1 track the upper left corner
	//X2 and Y2 track the lower right corner
	//together they give you the block rect
	int m_X1, m_Y1, m_X2, m_Y2, m_color;
	area_block():m_X1(NORESULT), m_Y1(NORESULT), m_X2(NORESULT), m_Y2(NORESULT), m_color(eBlack){}
	void addpoint(int a_x, int a_y);
	bool containsPoint(int a_x, int a_y);
};

struct blockListNode
{
	area_block * m_block;
	blockListNode * m_next;
	blockListNode(): m_block(NULL), m_next(NULL){}
};

class blockList
{
private:
	blockListNode * m_first;
	blockListNode * m_last;
	int m_size;
public:
	blockList(): m_first(NULL), m_last(NULL), m_size(0) {}
	~blockList() {killAllBlocks();}
	int blockPartOf(int a_x, int a_y);
	void removeBlock(int a_index);
	blockListNode * getBlock(int a_index);
	void killAllBlocks();
	void addBlock(area_block * newBlock);
};

struct timerPieceNode
{
	int m_count, m_x, m_y;
	timerPieceNode * m_next;
	timerPieceNode(): m_count(0), m_x(0), m_y(0), m_next(NULL) {}
};

class timerList
{
private:
	timerPieceNode * m_first;
	timerPieceNode * m_last;
	int m_size;
public:
	timerList(): m_first(NULL), m_last(NULL), m_size(0) {}
	~timerList() {killAllTimers();}
	int timerIn(int a_x, int a_y);
	int getClockOf(int a_x, int a_y);
	void decrementTimers();
	void removeTimerOn(int a_x, int a_y);
	void moveXYtoNew(int x1, int y1, int x2, int y2);
	void addTimerToXY(int a_count, int a_x, int a_y);
	void killAllTimers();
};

class gameBoard
{
private:
	int ** board;
	int m_h, m_w;
	pieceClass * piece;
	blockList * blocks;
	timerList * timers;
	bool resolvingBoard;
	int movePieceTimer;
public:
	gameBoard(): movePieceTimer(0), resolvingBoard(false), 
		m_h(0), m_w(0), board(NULL), piece(NULL), 
		blocks(NULL), timers(NULL) 
	{}
	void init();
	void cleanUp();
	void updateBoard(int msPassed);
	void drawBoard(int a_x, int a_y, SDL_Rect pieceSize);
	void handleInput(int flag);
	bool checkNoCollision(int a_dir);
	void setPieceToBackground();
	bool resolveBoard();
	bool resolveBombs();
	pieceClass* getPiece(){return piece;}
	void explodeColor(int a_color, int a_x, int a_y);
	bool isColorAround(int a_color, int a_x, int a_y);
	void resetBlocks();
};

//this is the main function, that will handle all the gameplay stuff
//this is going to be the most complex by far
class GamePlay : public World_State
{
protected:
	Character * player[2];
	SDL_Rect pieceSize;
	gameBoard * boards[2];
	int p1Flag, p2Flag;
	int flags, downflags, oldflags;
public:
	static GamePlay * Ins();
	void begin();
	void update(int msPassed);
	void draw();
	void input(SDL_Event e);
	void exit();
	gameBoard* getBoard(int i) {return boards[i];}
};

////this is the main function, that will handle all the gameplay stuff
////this is going to be the most complex by far
//class GamePlay : public World_State
//{
//protected:
//	//these hold pointers to the two characters to be played this round 
//	Character * player[2];
//	//TODO: add sdl_surfaces and rects for the background and border art, etc
//	SDL_Rect pieceSize;
//	//TODO: add custom classes to handle the tetris games
//	gameBoard * boards[2];
//	int flags, downflags, oldflags;
//	//TODO: custom private functions
//	void drawPieceInPosition(int piece, int x, int y, int boardNumber);
//	bool pieceCanMove(int direction, int p);
//	//TODO: add animation variables to hold whatever animations the design team comes up with
//public:
//	static GamePlay * Ins();
//	void begin();
//	void update(int msPassed);
//	void draw();
//	void input(SDL_Event e);
//	void exit();
//	//TODO: custom public functions
//	pieceClass* getPiece(int i) {return piecePointer[i];};
//	int getBoardPos(int i, int x, int y) {return gameBoard[i][x][y];};
//};

//class pieceClass
//{
//public:
//	int getX() {return x;}
//	int getY() {return y;}
//	int getD() {return d;}
//	int getOffX() {if(d == 3) return xNORESULT; else if(d == 1) return x+1; else return x;}
//	int getOffY() {if(d == 0) return yNORESULT; else if(d == 2) return y+1; else return y;}
//	int getMainPiece() {return piece1Val;}
//	int getOffPiece() {return piece2Val;}
//	void setMainPiece(int p) {piece1Val = p;}
//	void setOffPiece(int p) {piece2Val = p;}
//	void setX(int nx) {x = nx;}
//	void setY(int ny) {y = ny;}
//	void setD(int nd) {d = nd;}
//	void moveDown() {y += 1;}
//	void moveLeft() {x -= 1;}
//	void moveRight() {x += 1;}
//	void rotateLeft() {d -= 1; if(d < 0) d = 3;}
//	void rotateRight() {d += 1; d = d%4;}
//private:
//	int piece1Val;
//	int piece2Val;
//	int x;
//	int y;
//	int d;  // direction of the second piece, 0 is up 1 is right 2 is down 3 is left;
//};