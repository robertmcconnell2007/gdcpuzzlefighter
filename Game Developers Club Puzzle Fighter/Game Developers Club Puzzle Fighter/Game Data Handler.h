// Game Data Handler.h
//
// by GDC club
//
// file overseen by
// Brian "The Razor" Schick, GDH Gatekeeper
//
// Contribution guidelines IMPORTANT READ
//  READ the contribution guidelines before contributing to
//		the GDH.
//
//	This header file will be kept in UML format, 
//	sorted by overall function,
//  and then alphabetically :

// UML Format:
//	- Class Name
//	- Friend Functions
//	- Attributes
//	-	- public
//	-	- protected
//	-	- private
//	- Cotr, Decotr, operators
//	- Member Functions
//	-	- public
//	-	- protected
//	-	- private

// Overall Functions:
// - Events
// - Game Mechanics
// - Game States
// - SDL Graphics

// Naming conventions:
// Use scope_hungarian notation
//	Scope: g: global m: member a: arguement (i.e. parameter)
//	Hungarian: http://en.wikipedia.org/wiki/Hungarian_notation
// ex:
// int m_iPlayerCount;
// void SetPosition( struct Point a_sNewPos )

// Comment guidelines IMPORTANT READ
// - All public member functions should have a description of
//		the function and use instructions placed in comments
//		directly above the function definition with no empty 
//		lines between them.
// - Avoid placement of a comment on the same line as the definition.
//		ex.  Don't do:  void SomeFunction();  // This is bad comment
//		ex.  Do do:     // This is good comment
//                      void SomeOtherFunction();
//	If you follow the above two guidelines, when a developer presses
//		<CTRL><SPACE>, intellisense will show your comments
//		adjacent to the combo box of suggested methods and 
//		attributes.

// Accessor / Mutator guidelines IMPORTANT
// - All accessors should not change the state of GDH
//	 Use the following format for accessors:
//		retval AccessorFunc( params ) const;
#pragma once

// All includes will be put here in alphabetical order
// include class for a High score chart to be created "ScoreAll.h"
//#include "World States\World_States Core.h"
#include "Character.h"
#include "ScoreAll.h"

// All defines will be put here in alphabetical order


using namespace std;

class World_State;
//GDH -> Game Data Handler
class GDH
{

	// A T T R I B U T E S
private:
	
	// Event
	SDL_Event			m_uE;

	// Mechanics
	Character *			m_apoCurrent_chars[2];	//need a pair of characters that can be used 
	// TODO need to store the world space to be used
	// environment  current_envrmt;

	// Game (World) State
	World_State *		m_poCurr_State;
	bool				m_bGameRunning;		//tells whether the game is running
	
	// SDL Graphics
	SDL_Surface *		m_psScreen;
	

	// C O T R , D E C O T R , O P E R A T O R S
private:
	// GDH::GDH()
	//	Default COTR initializes all literals
	//	May not initialize non-literals
	GDH();
	~GDH();


	// M E M B E R   F U N C T I O N S
public:
	// GDH Class
	static GDH *		Ins();
	// GDH::Initialize
	//	Initializes all non-literals for GDH
	bool				Initialize();
		
	// SDL Graphics
	// checkEvent() 
	//	check Event is a Accessor/Mutator:  It is intended to
	//	allow the calling function to change the event.
	SDL_Event*			checkEvent() { return &m_uE; }
	void				draw() const;
	SDL_Surface *		getScreen() { return m_psScreen; }

	// Game States
	bool				changeState(World_State * a_poNewState);
	void				endGame(){ m_bGameRunning = false; }
	void				input();	
	bool				isGameRunning() const { return m_bGameRunning; }
	void				update( int a_iMSPassed );
	
};

// Notes:
//
// 5/19/2010 - Added comments describing contribution guidelines - bms.