#include "Game Data Handler.h"
#include "World States\World_States Core.h"


// COTR / DECOTR / OPERATOR
GDH::GDH()
{
	m_poCurr_State = NULL;
	m_bGameRunning = true;
}

GDH::~GDH()
{
	m_poCurr_State = NULL;
	//clear away anything we made
}


// MEMBER FUNCTIONS
// GDH CLASS
// GDH::Ins()
//	Access the singleton through this call
GDH * GDH::Ins()
{
	static GDH instance;
	return & instance;
}

// GDH::Initialize
//	Initializes all non-literals for GDH
bool GDH::Initialize()
{
	//TODO: load core information from ini file, i.e. resolution etc
	//make screen and all that jazz for now will just use some magic numbers

	m_psScreen = SDL_SetVideoMode(860, 640, 32, SDL_SWSURFACE);
	if ( m_psScreen == NULL )
		return false;

	GDH::Ins()->changeState(/*(World_State*)*/Splash_Screen::Ins());

	return true;
}


// SDL GRAPHICS
void GDH::draw() const
{
	SDL_FillRect(m_psScreen, &m_psScreen->clip_rect, 0x000000);
	if(m_poCurr_State)
		m_poCurr_State->draw();
	//if there is any global things to be drawn
	//they belong here

	//flip the screen
	if(SDL_Flip(m_psScreen) == -1)
		return;
}

// GDH::GDH()
//	Default COTR initializes all literals
//	May not initialize non-literals
bool GDH::changeState(World_State * a_poNewState)
{
	if ( a_poNewState == NULL )
		return false;
	else
	{
		if(m_poCurr_State)
			m_poCurr_State->exit();
		m_poCurr_State = a_poNewState;
		m_poCurr_State->begin();
		return true;
	}
}

void GDH::input()
{
	if(m_poCurr_State)
		m_poCurr_State->input(m_uE);
	//if there are any global checks for input, they belong here
	if(m_uE.type == SDL_QUIT || m_uE.key.keysym.sym == SDLK_RETURN)
	{
		m_bGameRunning = false;
	}
}

void GDH::update(int a_iMSPassed)
{
	if(m_poCurr_State)
		m_poCurr_State->update(a_iMSPassed);
	//if there are any global updates
	//they belong here below curr_State->update();
}

