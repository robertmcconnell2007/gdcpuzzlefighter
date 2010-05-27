AI: (word wrap reccomended)

Basic Structure:
	- the basic idea of the AI is that it is run each update in the game state to allow the AI to find where to place a piece
	- the AI will run an algolrithm to determine the location of the desired piece. If the final version of this algolrithm takes too long, it will stop where it is and continue again next update.
	- Behaviors are classes created to give the impression that the AI will not do the same thing every time it plays. This allows for players to give their characters different AI with different strategies.

How to make a behavior:
	- To make a behavior, see the behaviorClass.h to see the basic structure. If you wish to create a new behavior, you must first create a child class, giving it a unique name. after that, your behavior algolrithm goes in the findSpot() funciton. When you are done, add your behavior class name to the enum list at the top of aiClass.h, please follow format to keep things neat. Once your enum has been added to the list, you can then go to aiClass.cpp to the TODO tag. There you can add the following lines:

if(b = [your enum])
{
	behavior = new [your behavior class name]();
}

view other similar statements to get a better idea of what to do.