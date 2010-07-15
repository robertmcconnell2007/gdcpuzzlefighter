#include "Main_Game_State.h"
#include "../AI/aiClass.h"

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
	AI::Ins()->setNewAI(1, eBasicBehavior);
	//begin Score tracking
	Score_States::Ins()->begin();
	boards[0] = new gameBoard;
	boards[0]->init();
	boards[1] = new gameBoard;
	boards[1]->init();
	pieceSize.h = 20;
	pieceSize.w = 20;
	p1Flag = eNoInput;
	p2Flag = eNoInput;
}

void GamePlay::update(int msPassed)
{
	boards[0]->handleInput(p1Flag);
	boards[1]->handleInput(p2Flag);
	p1Flag = eNoInput;
	p2Flag = eNoInput;
	boards[0]->updateBoard(msPassed);
	boards[1]->updateBoard(msPassed);
	AI::Ins()->update();
	//if (playing against computer)
	//{
		p2Flag = eNoInput;
		if(AI::Ins()->isReady())
		{
			p2Flag = AI::Ins()->getMove();
		}
	//}
		// updating the score happens here.
}

void GamePlay::draw()
{
	boards[0]->drawBoard(0,0, pieceSize);
	boards[1]->drawBoard((pieceSize.w * (BOARDWIDTH + 4)),0, pieceSize);
	// draw the score here
	Score_States::Ins()->draw();
}

void GamePlay::input(SDL_Event e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
		case SDLK_s:
			p1Flag = eInputDown;
			break;
		case SDLK_d:
			p1Flag = eInputRight;
			break;
		case SDLK_a:
			p1Flag = eInputLeft;
			break;
		case SDLK_q:
			p1Flag = eInputRotateCC;
			break;
		case SDLK_e:
			p1Flag = eInputRotateC;
			break;
		case SDLK_DOWN:
			p2Flag = eInputDown;
			break;
		case SDLK_RIGHT:
			p2Flag = eInputRight;
			break;
		case SDLK_LEFT:
			p2Flag = eInputLeft;
			break;
		case SDLK_1:
			p2Flag = eInputRotateCC;
			break;
		case SDLK_2:
			p2Flag = eInputRotateC;
			break;
		}
	}
}

void GamePlay::exit()
{
	boards[0]->cleanUp();
	boards[1]->cleanUp();
	delete boards[0];
	delete boards[1];
	Score_States::Ins()->exit();
}

//omg all the functions for the board classes etc

void pieceClass::resetPiece(int a_baseX, int a_baseY)
{
	newPiece = true;
	x = a_baseX;
	y = a_baseY;
	d = eLeft;
	switch(rand() & 3)
	{
	case 0:
		CC = eBlue;
		break;
	case 1:
		CC = eRed;
		break;
	case 2:
		CC = eGreen;
		break;
	case 3:
		CC = eYellow;
		break;
	}
	switch(rand() & 3)
	{
	case 0:
		SC = eBlue;
		break;
	case 1:
		SC = eRed;
		break;
	case 2:
		SC = eGreen;
		break;
	case 3:
		SC = eYellow;
		break;
	}
	if((rand() & 127) < 15)
		CC |= eBomb;
	if((rand() & 127) < 15)
		SC |= eBomb;

	//if(testerInt < 1)
	//{
	//	CC = eBlue;
	//	SC = eBlue;
	//}
	//else if(testerInt < 6)
	//{
	//	CC = eRed;
	//	SC = eRed;
	//}
	//else if(testerInt < 10)
	//{
	//}
	//testerInt++;
}

void pieceClass::movePiece(int a_dir)
{
	x += xCtr[a_dir];
	y += yCtr[a_dir];
}

void pieceClass::rotateClockwise()
{
	d++;
	d = d & 3;
}

void pieceClass::rotateCounterClockwise()
{
	d--;
	if(d < 0)
		d = 3;
}

void area_block::addpoint(int a_x, int a_y)
{
	if(m_X1 < 0 || a_x < m_X1)
		m_X1 = a_x;
	if(m_X2 < 0 || a_x > m_X2)
		m_X2 = a_x;
	if(m_Y1 < 0 || a_y < m_Y1)
		m_Y1 = a_y;
	if(m_Y2 < 0 || a_y > m_Y2)
		m_Y2 = a_y;
}

bool area_block::containsPoint(int a_x, int a_y)
{
	if(a_x >= m_X1 && a_x <= m_X2 && a_y >= m_Y1 && a_y <= m_Y2)
		return true;
	return false;
}

int blockList::blockPartOf(int a_x, int a_y)
{
	blockListNode * walker = m_first;
	int counter = 0;
	while(walker != NULL)
	{
		if(walker->m_block->containsPoint(a_x, a_y))
			return counter;
		counter++;
		walker = walker->m_next;		
	}
	return NORESULT;
}

void blockList::removeBlock(int a_index)
{
	blockListNode * walker = m_first;
	blockListNode * previous = m_first;
	int counter = 0;
	while(walker != NULL)
	{
		if(counter == a_index)
		{
			if(walker == m_last)
			{
				if(walker == m_first)
				{
					m_first = NULL;
					m_last = NULL;
					m_size = 1;
					delete walker->m_block;
					delete walker;
				}
				else
				{
					m_last = previous;
					m_last->m_next = NULL;
					delete walker->m_block;
					delete walker;
				}
			}
			else if(walker == m_first)
			{
				m_first = m_first->m_next;
				delete walker->m_block;
				delete walker;
			}
			else
			{
				previous->m_next = walker->m_next;
				delete walker->m_block;
				delete walker;
			}
			m_size--;
			return;
		}
		counter++;
		previous = walker;
		walker = walker->m_next;		
	}
}

blockListNode * blockList::getBlock(int a_index)
{
	blockListNode * walker = m_first;
	int counter = 0;
	while(walker != NULL)
	{
		if(counter == a_index)
			return walker;
		counter++;
		walker = walker->m_next;
	}
	return NULL;
}

void blockList::killAllBlocks()
{
	blockListNode * walker = m_first;
	while(m_first != NULL)
	{
		m_first = m_first->m_next;
		delete walker->m_block;
		delete walker;
		walker = m_first;
	}
	m_last = NULL;
	m_size = 0;
}

void blockList::addBlock(area_block * newBlock)
{
	if(m_first == NULL)
	{
		m_first = new blockListNode;
		m_last = m_first;
	}
	else
	{
		m_last->m_next = new blockListNode;
		m_last = m_last->m_next;
	}
	m_last->m_next = NULL;
	m_last->m_block = newBlock;
	m_size++;
}

int timerList::timerIn(int a_x, int a_y)
{
	timerPieceNode * walker = m_first;
	int counter = 0;
	while(walker != NULL)
	{
		if(walker->m_x == a_x && walker->m_y == a_y)
			return counter;
		walker = walker->m_next;
		counter++;
	}
	return NORESULT;
}

int timerList::getClockOf(int a_x, int a_y)
{
	timerPieceNode * walker = m_first;
	while(walker != NULL)
	{
		if(walker->m_x == a_x && walker->m_y == a_y)
			return walker->m_count;
		walker = walker->m_next;
	}
	return NORESULT;
}

void timerList::decrementTimers()
{
	timerPieceNode * walker = m_first;
	timerPieceNode * previous = m_first;
	while(walker != NULL)
	{
		walker->m_count--;
		if(walker->m_count <= 0)
		{
			removeTimerOn(walker->m_x, walker->m_y);
			walker = previous;
		}
		previous = walker;
		walker = walker->m_next;
	}
}

void timerList::removeTimerOn(int a_x, int a_y)
{
	timerPieceNode * walker = m_first;
	timerPieceNode * previous = m_first;
	while(walker != NULL)
	{
		if(walker->m_x == a_x && walker->m_y == a_y)
		{
			if(walker == m_last)
			{
				if(walker == m_first)
				{
					m_first = NULL;
					m_last = NULL;
					m_size = 1;
					delete walker;
				}
				else
				{
					m_last = previous;
					m_last->m_next = NULL;
					delete walker;
				}
			}
			else if(walker == m_first)
			{
				m_first = m_first->m_next;
				delete walker;
			}
			else
			{
				previous->m_next = walker->m_next;
				delete walker;
			}
			m_size--;
			return;
		}
		previous = walker;
		walker = walker->m_next;
	}
}

void timerList::moveXYtoNew(int x1, int y1, int x2, int y2)
{
	timerPieceNode * walker = m_first;
	while(walker != NULL)
	{
		if(walker->m_x == x1 && walker->m_y == y1)
		{
			walker->m_x = x2;
			walker->m_y = y2;
			return;
		}
		walker = walker->m_next;
	}
}

void timerList::addTimerToXY(int a_count, int a_x, int a_y)
{
	if(m_first == NULL)
	{
		m_first = new timerPieceNode;
		m_last = m_first;		
	}
	else
	{
		m_last->m_next = new timerPieceNode;
		m_last = m_last->m_next;
	}
	m_last->m_next = NULL;		
	m_last->m_count = a_count;
	m_last->m_x = a_x;
	m_last->m_y = a_y;
	m_size++;
}

void timerList::killAllTimers()
{
	timerPieceNode * walker = m_first;
	while(m_first != NULL)
	{
		m_first = m_first->m_next;
		delete walker;
	}
	m_last = NULL;
	m_size = 0;
}

void gameBoard::init()
{
	if(!board)
	{
		m_h = BOARDHEIGHT;
		m_w = BOARDWIDTH;
		board = new int*[m_h];
		for(int i = 0; i < m_h; ++i)
			board[i] = new int[m_w];
		for(int r = 0; r < m_h; ++r)
		{
			for(int c = 0; c < m_w; ++c)
				board[r][c] = eBlack;
		}
	}
	if(!piece)
	{
		piece = new pieceClass;
		piece->resetPiece((m_w / 2), 1);
	}
	if(!blocks)
	{
		blocks = new blockList;
	}
	if(!timers)
	{
		timers = new timerList;
	}
}

void gameBoard::cleanUp()
{
	if(board)
	{
		for(int i = 0; i < m_h; ++i)
			delete [] board[i];
		delete [] board;
	}
	if(piece)
	{
		delete piece;
	}
	if(blocks)
	{
		blocks->killAllBlocks();
		delete blocks;
	}
	if(timers)
	{
		timers->killAllTimers();
		delete timers;
	}
}

void gameBoard::updateBoard(int msPassed)
{
	movePieceTimer += msPassed;
	if(resolvingBoard)
	{
		if(resolveBoard())
		{
			piece->resetPiece((m_w / 2), 1);
			resetBlocks();
			resolvingBoard = resolveBombs();
			if(resolvingBoard)
				resetBlocks();
		}
	}
	else if(checkNoCollision(eDown))
	{
		if(movePieceTimer >= PIECEDROPTIME)
		{
			movePieceTimer = 0;
			piece->movePiece(eDown);
		}
	}
	else
	{
		resolvingBoard = true;
		setPieceToBackground();
		resetBlocks();
		timers->decrementTimers();
	}
}

void gameBoard::drawBoard(int a_x, int a_y, SDL_Rect pieceSize)
{
	SDL_Rect tempRect;
	Uint32 color = 0;
	tempRect.h = pieceSize.h;
	tempRect.w = pieceSize.w;
	for(int r = 0; r < m_h; ++r)
	{
		tempRect.y = (r * tempRect.h) + a_y;
		for(int c = 0; c < m_w; ++c)
		{
			tempRect.x = (c * tempRect.w) + a_x;
			switch(board[r][c] & ~eBomb)
			{
			case eBlue:
				color = 0x00000088;
				break;
			case eGreen:
				color = 0x00008800;
				break;
			case eRed:
				color = 0x00880000;
				break;
			case eYellow:
				color = 0x00888800;
				break;
			case eBlack:
				color = 0x00000000;
				break;
			}
			if(board[r][c] & eBomb)
			{
				switch(board[r][c] & ~eBomb)
				{
				case eBlue:
					color = 0x000000CC;
					break;
				case eGreen:
					color = 0x0000CC00;
					break;
				case eRed:
					color = 0x00CC0000;
					break;
				case eYellow:
					color = 0x00CCCC00;
					break;
				case eBlack:
					color = 0x00000000;
					break;
				}
			}
			int bpo = blocks->blockPartOf(c, r);
			if(bpo != -1)
			{
				switch(blocks->getBlock(bpo)->m_block->m_color & ~eBomb)
				{
				case eBlue:
					color = 0x00000044;
					break;
				case eGreen:
					color = 0x00004400;
					break;
				case eRed:
					color = 0x00440000;
					break;
				case eYellow:
					color = 0x00444400;
					break;
				case eBlack:
					color = 0x00000000;
					break;
				}
			}
			SDL_FillRect(GDH::Ins()->getScreen(), &tempRect, color);
		}
	}
	if(!resolvingBoard)
	{
		tempRect.x = (piece->getX() * tempRect.w) + a_x;
		tempRect.y = (piece->getY() * tempRect.h) + a_y;
		switch(piece->getCC() & ~eBomb)
		{
		case eBlue:
			color = 0x00000088;
			break;
		case eGreen:
			color = 0x00008800;
			break;
		case eRed:
			color = 0x00880000;
			break;
		case eYellow:
			color = 0x00888800;
			break;
		case eBlack:
			color = 0x00000000;
			break;
		}
		if(piece->getCC() & eBomb)
		{
			switch(piece->getCC() & ~eBomb)
			{
			case eBlue:
				color = 0x000000CC;
				break;
			case eGreen:
				color = 0x0000CC00;
				break;
			case eRed:
				color = 0x00CC0000;
				break;
			case eYellow:
				color = 0x00CCCC00;
				break;
			case eBlack:
				color = 0x00000000;
				break;
			}
		}
		SDL_FillRect(GDH::Ins()->getScreen(), &tempRect, color);

		tempRect.x = ((piece->getX() + xCtr[piece->getD()]) * tempRect.w) + a_x;
		tempRect.y = ((piece->getY() + yCtr[piece->getD()]) * tempRect.h) + a_y;
		switch(piece->getSC() & ~eBomb)
		{
		case eBlue:
			color = 0x00000088;
			break;
		case eGreen:
			color = 0x00008800;
			break;
		case eRed:
			color = 0x00880000;
			break;
		case eYellow:
			color = 0x00888800;
			break;
		case eBlack:
			color = 0x00000000;
			break;
		}
		if(piece->getSC() & eBomb)
		{
			switch(piece->getSC() & ~eBomb)
			{
			case eBlue:
				color = 0x000000CC;
				break;
			case eGreen:
				color = 0x0000CC00;
				break;
			case eRed:
				color = 0x00CC0000;
				break;
			case eYellow:
				color = 0x00CCCC00;
				break;
			case eBlack:
				color = 0x00000000;
				break;
			}
		}
		SDL_FillRect(GDH::Ins()->getScreen(), &tempRect, color);
	}
}


void gameBoard::handleInput(int a_flag)
{
	switch(a_flag)
	{
	case eInputRight:
		if(checkNoCollision(eRight))
			piece->movePiece(eRight);
		break;
	case eInputLeft:
		if(checkNoCollision(eLeft))
			piece->movePiece(eLeft);
		break;
	case eInputDown:
		if(checkNoCollision(eDown))
			piece->movePiece(eDown);
		break;
	case eInputSpecial:
		break;
	case eInputRotateCC:
		piece->rotateCounterClockwise();
		if(!checkNoCollision(eNone))
			piece->rotateClockwise();
		break;
	case eInputRotateC:
		piece->rotateClockwise();
		if(!checkNoCollision(eNone))
			piece->rotateCounterClockwise();
		break;
	}
}

bool gameBoard::checkNoCollision(int a_dir)
{
	//if you're trying to go off the map, return false
	if( (piece->getX() + xCtr[a_dir] <  0	|| piece->getX() + xCtr[piece->getD()] + xCtr[a_dir] <  0) ||
		(piece->getX() + xCtr[a_dir] >= m_w || piece->getX() + xCtr[piece->getD()] + xCtr[a_dir] >= m_w) ||
		(piece->getY() + yCtr[a_dir] <  0	|| piece->getY() + yCtr[piece->getD()] + yCtr[a_dir] <  0) ||
		(piece->getY() + yCtr[a_dir] >= m_h || piece->getY() + yCtr[piece->getD()] + yCtr[a_dir] >= m_h))
		return false;
	//if you're trying to move onto an existing piece, return false
	if( board[piece->getY() + yCtr[a_dir]][piece->getX() + xCtr[a_dir]] != eBlack || 
		board[piece->getY() + yCtr[piece->getD()] + yCtr[a_dir]][piece->getX() + xCtr[piece->getD()] + xCtr[a_dir]] != eBlack)
		return false;
	//otherwise, you're in the clear
	return true;
}

void gameBoard::setPieceToBackground()
{
	int x1 = piece->getX();
	int y1 = piece->getY();
	int x2 = piece->getX() + xCtr[piece->getD()];
	int y2 = piece->getY() + yCtr[piece->getD()];
	board[y1][x1] = piece->getCC();
	board[y2][x2] = piece->getSC();
}

bool gameBoard::resolveBoard()
{
	bool settled = true;
	for(int r = 0; r < m_h - 1; ++r)
	{
		for(int c = 0; c < m_w; ++c)
		{
			int bpo = blocks->blockPartOf(c,r);
			if(bpo != NORESULT)
			{
				bool clearToDrop = true;
				area_block * block = blocks->getBlock(bpo)->m_block;
				for(int nc = block->m_X1; nc < block->m_X2; ++nc)
				{
					if(block->m_Y2 < m_h - 1 && board[block->m_Y2 + 1][nc] != eBlack)
						clearToDrop = false;
				}
				if(clearToDrop)
				{
					settled = false;
					blocks->removeBlock(bpo);
				}
			}
			else if(board[r][c] != eBlack && board[r + 1][c] == eBlack)
			{
				settled = false;
				board[r + 1][c] = board[r][c];
				if(timers->timerIn(c, r))
					timers->moveXYtoNew(c, r, c, r + 1);
				board[r][c] = eBlack;
			}
		}
	}
	return settled;
}

bool gameBoard::resolveBombs()
{
	bool foundSomething = false;
	for(int r = 0; r < m_h; ++r)
	{
		for(int c = 0; c < m_w; ++c)
		{
			if(board[r][c] & eBomb)
			{
				//check if there is the base color w/o the bomb around the piece
				foundSomething = isColorAround(board[r][c] & ~eBomb, c, r);
				if(foundSomething)
					explodeColor((board[r][c] & ~eBomb), c, r);
			}
		}
	}
	return foundSomething;
}

void gameBoard::explodeColor(int a_color, int a_x, int a_y)
{
	board[a_y][a_x] = eBlack;
	if(timers->timerIn(a_x, a_y) != NORESULT)
	{
		timers->removeTimerOn(a_x, a_y);
		return;
	}
	if(a_x > 0 && board[a_y][a_x - 1] == a_color)
		explodeColor(a_color, a_x - 1, a_y);
	if(a_x < m_w - 1 && board[a_y][a_x + 1] == a_color)
		explodeColor(a_color, a_x + 1, a_y);
	if(a_y > 0 && board[a_y - 1][a_x] == a_color)
		explodeColor(a_color, a_x, a_y - 1);
	if(a_y < m_h - 1 && board[a_y + 1][a_x] == a_color)
		explodeColor(a_color, a_x, a_y + 1);
}

bool gameBoard::isColorAround(int a_color, int a_x, int a_y)
{
	if( (a_x > 0		&& board[a_y][a_x - 1] == a_color && timers->timerIn(a_x - 1, a_y) == NORESULT) ||
		(a_x < m_w - 1	&& board[a_y][a_x + 1] == a_color && timers->timerIn(a_x + 1, a_y) == NORESULT) ||
		(a_y > 0		&& board[a_y - 1][a_x] == a_color && timers->timerIn(a_x, a_y - 1) == NORESULT) ||
		(a_y < m_h - 1	&& board[a_y + 1][a_x] == a_color && timers->timerIn(a_x, a_y + 1) == NORESULT))
		return true;
	return false;
}

void gameBoard::resetBlocks()
{
	blocks->killAllBlocks();
	for(int r = 0; r < m_h - 1; r++)
	{
		for(int c = 0; c < m_w - 1; ++c)
		{
			//huge, gross, disgusting if statement to check if a viable block can be made
			if( board[r][c] != eBlack &&
				
				!(board[r][c] & eBomb) &&
				timers->timerIn(c, r) == NORESULT &&
				blocks->blockPartOf(c, r) == NORESULT &&

				board[r + 1][c] == board[r][c] &&
				timers->timerIn(c, r + 1) == NORESULT &&
				blocks->blockPartOf(c, r + 1) == NORESULT &&

				board[r][c + 1] == board[r][c] &&
				timers->timerIn(c + 1, r) == NORESULT &&
				blocks->blockPartOf(c + 1, r) == NORESULT &&

				board[r + 1][c + 1] == board[r][c] &&
				timers->timerIn(c + 1, r + 1) == NORESULT &&
				blocks->blockPartOf(c + 1, r + 1) == NORESULT)
			{
				area_block * newBlock = new area_block;
				newBlock->m_color = board[r][c] | eBomb;
				newBlock->addpoint(c, r);
				newBlock->addpoint(c + 1, r + 1);

				int maxX = c + 1, maxY = r + 1;
				bool done = false;
				for(int nc = c; nc < m_w - 1 && !done; ++nc)
				{
					if( board[r][nc + 1] != board[r][c] ||
						timers->timerIn(nc + 1, r) != NORESULT ||
						blocks->blockPartOf(nc + 1, r) != NORESULT ||

						board[r + 1][nc + 1] != board[r][c] ||
						timers->timerIn(nc + 1, r + 1) != NORESULT ||
						blocks->blockPartOf(nc + 1, r + 1) != NORESULT)
					{
						done = true;
						maxX = nc;
					}
				}
				done = false;
				for(int nr = r; nr < m_h - 1 && !done; ++nr)
				{
					for(int nc = c; nc <= maxX && !done; ++nc)
					{
						if(board[nr + 1][nc] != board[r][c] || blocks->blockPartOf(nc, nr + 1) != NORESULT ||timers->timerIn(nc, nr + 1) != NORESULT)
						{
							done = true;
							maxY = nr - 1;
							//if(nc != maxX || blocks->blockPartOf(nc, maxY + 1) != NORESULT || timers->timerIn(nc, maxY + 1) != NORESULT)
							//	maxY--;
						}
					}
				}
				newBlock->addpoint(maxX, maxY);
				blocks->addBlock(newBlock);
			}
		}
	}
}
bool pieceClass::isNew()
{
	if(newPiece)
	{
		newPiece = false;
		return true;
	}
	return false;
}

////attempt one
//GamePlay* GamePlay::Ins()
//{
//	static GamePlay instance;
//	return & instance;
//}
//
//void GamePlay::begin()
//{
//	//TODO: get player 1 and player 2 characters from char_selection
//	//TODO: load in drop patterns for player 1 and 2
//	//TODO: if player2 is a computer, setup AI for that character
//	screen = GDH::Ins()->getScreen();
//	boardSize[0].x = boardSize[0].y = boardSize[1].x = boardSize[1].y = 0;
//	pieceSize.h = pieceSize.w = 25;
//	boardSize[0].h = boardSize[1].h = BOARDHEIGHT * pieceSize.h;
//	boardSize[0].w = boardSize[1].w = BOARDWIDTH * pieceSize.w;
//	boardSize[1].x += boardSize[1].w + 50;
//}
//
//void GamePlay::update(int msPassed)
//{
//	//TODO: update game board
//	//TODO: move piece while checking for collision
//	if(msPassed > 1000)
//	{
//		for(int p = 0; p < 2; p++)
//		{
//			if(pieceCanMove(eDown, p))
//				piecePointer[p]->moveDown();
//		}
//	}
//	//TODO: check for piece destruction
//	//TODO: update AI if player 2 is an AI
//}
//
//void GamePlay::draw()
//{
//	//TODO: draw background
//	//TODO: draw characters
//	//TODO: draw UI (conveyer belt, score, difficulty?, names of characters, etc)
//	for(int p = 0; p < 2; p++)
//	{
//		//TODO: draw game board
//		SDL_FillRect(screen,&boardSize[p],0x000000);
//		//TODO: draw pieces
//		for(int y = 0; y < BOARDHEIGHT; y++)
//		{
//			for(int x = 0; x < BOARDWIDTH; x++)
//			{
//				drawPieceInPosition(gameBoard[p][x][y], x, y, 1);
//			}
//		}
//		//TODO: draw held pieces
//		drawPieceInPosition(piecePointer[p]->getMainPiece(), piecePointer[p]->getX(), piecePointer[p]->getY(), p);
//		drawPieceInPosition(piecePointer[p]->getOffPiece(), piecePointer[p]->getOffX(), piecePointer[p]->getOffY(), p);
//	}
//	//TODO: draw anything that would cover pieces
//}
//
//void GamePlay::input(SDL_Event e)
//{
//	//TODO: get input from player, if player is computer, get input from computer
//	//TODO: input should set flags for the update to handle
//}
//
//void GamePlay::exit()
//{
//	//TODO: clean up
//}
//
//void GamePlay::drawPieceInPosition(int piece, int x, int y, int boardNumber) //TODO: This function needs to be revised later
//{
//	if(piece == 0)
//		return;
//	SDL_Rect boardPosition = boardSize[boardNumber];
//	Uint32 color;
//	if(piece & eRedPiece)
//		color = 0xff0000;
//	if(piece & eBluePiece)
//		color = 0x0000ff;
//	if(piece & eGreenPiece)
//		color = 0x00ff00;
//	if(piece & eYellowPiece)
//		color = 0xff00ff;
//	pieceSize.x = (x * pieceSize.w) + boardPosition.x;
//	pieceSize.y = (y * pieceSize.h) + boardPosition.y;
//	SDL_FillRect(screen,&pieceSize,color);
//}
//
//bool GamePlay::pieceCanMove(int direction, int player)
//{
//	//TODO: fill in this function. use direction enums for simplicity
//	return true;
//}