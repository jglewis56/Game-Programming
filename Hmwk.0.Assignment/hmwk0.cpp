/* Author:	Keith Bush
*			UALR
* 
* Date:		January 12, 2015	
*
* File:		hmwk0.cpp
*
* Purpose:	The purpose of this homework is to review Programming I topics covering
*           standard input/output, types, declaration, selection constructs, loop 
*           constructs, and functions using a very simple Single-User Dungeon environment.
*/

#include<iostream>
#include<string>
using namespace std;

/* GUI Functions */
void clearConsole();
void pauseConsole();
void splashScreen();
void displayGameState(int, int, bool);
void displayGameDone(int, int, bool);
void displayIllegalMove(int, char, bool);
char getAction();

/* Engine Functions*/
bool changeGameState(char, int &, int &, bool &);
bool gameIsNotDone(int, int, bool);

int main()
{

	/*State variables*/
	int location = 0;
	char action = '\n';
	int health = 10;
	bool key = false;

	/*Splash Screen*/
	clearConsole();
	splashScreen();
	
	/*Until Game Termination Condition Do: */
	do
	{

		/*Display Game State*/
		clearConsole();
		displayGameState(location, health, key);

		/*Collect Player Action*/
		action = getAction();

		/*Update Game State*/
		if(changeGameState(action, location, health, key))
		{
			health--;
		}
		else
		{
			displayIllegalMove(location,action,key);
		}

	/*Check Game Termination*/
	}
	while(gameIsNotDone(location, health, key));

	/*Display Termination Game State*/
	displayGameDone(location, health, key);
	 
	return 0;

}


void clearConsole()
{
	system("cls");
}

void pauseConsole()
{
	system("PAUSE");
}

void splashScreen()
{
	cout << "DUNGEON ADVENTURE" << endl;
	cout << endl;
	cout << "Jordan Lewis (2016)" << endl;
	cout << "CPSC 2377, Game Programming, Homework 0" << endl;
	cout << "UALR, Computer Science Dept." << endl;
	cout << endl;
	cout << "INSTRUCTIONS:" << endl;
	cout << endl;
	cout << "Find the key and get out of the dungeon!" << endl;
	cout << endl;
	cout << "        (North)          " << endl;
	cout << "           w             " << endl;
	cout << "           |             " << endl;
	cout << "(West) a --+-- d (East)  " << endl;
	cout << "           |             " << endl;
	cout << "           s             " << endl;
	cout << "        (South)          " << endl;
	cout << endl;
	pauseConsole();
}

void displayGameState(int location,int health, bool key)
{
	string Equip;
	switch(location)
	{
		
	      case 0:
			cout<<"A large, torchlit room with doors South and East"<<endl;
			cout<<"Health:"<<health<<endl;
			if(key==true)
			{
				Equip=" 1 jailer's key";
				cout<<"Equip:" <<Equip<<endl;
			}
			else
				cout<<"Equip:"<<endl;
			break;
		  case 1:
			  cout<<"A jailer's barracks room with doors West, South, and East."<<endl;
			  cout<<"There is daylight entering under the door to the East."<<endl;
			  cout<<"Health:"<<health<<endl;
			  if(key==true)
			{
				Equip=" 1 jailer's key";
				cout<<"Equip:" <<Equip<<endl;
			}
			else
				cout<<"Equip:"<<endl;
			  break;
		  
		  case 3:
			  cout<<"A small, dark prison cell with doors North and East"<<endl;
			  cout<<"Health:"<<health<<endl;
			  if(key==true)
			{
				Equip=" 1 jailer's key";
				cout<<"Equip:" <<Equip<<endl;
			}
			else
				cout<<"Equip:"<<endl;
			  break;
		  case 4:
			  cout<<"A store room with doors West and North."<<endl;
			 do
			 {
				 cout<<"There is a key on the floor. You pick it up."<<endl;
			 }
			 while(key==false &&location==4);
			  cout<<"Health:"<<health<<endl;
			  cout<<"Equip:" <<Equip<<endl;
			  break;

	}

			
}

void displayGameDone(int location, int health, bool key)
{
	if(location==2&&health>0&&key==true)
	{
				cout<<"YOU FOUND THE KEY AND ESCAPED"<<endl;
				pauseConsole();
				
	}
	else
		if(health<=0)
		{
			cout<<" YOU DIED... RIP."<<endl;
			
		}
	

}


void displayIllegalMove(int location, char action, bool key)
{
	if(location==1&&action=='d'&&key==false)
	{
	  clearConsole();
	  cout<<"The door is locked."<<endl;
	}
	else
	{
	 clearConsole();
	 cout<<"You cannot go that way."<<endl;
	}
	pauseConsole();

}

char getAction()
{
	char action;
	cout << endl;
	cout << "Select action: ";
	cin >> action;
	return(action);
}

//Apply the game's logical rules to the current location, possession of the
//key, move legality, and health.
bool changeGameState(char action, int & location, int & health, bool & key)
{
	bool moveCorrect=true;
	switch(location)
	{	
	  case 0:
		  {
		  if(action=='s')
		  {
			 location=3;
			  return(true);
		  }
		  else
			  if(action=='d')
			  {
			    location=1;
				return(true);
			  }
			  else
				  return(false);
		  break;
		  }
	  case 1:
		  {
		  if(action=='s')
		  {
			 
			 location=4;
			  key=true;
			  return(true);
		  }
		  else
			  if(action=='d'&&key==true)
			  {
			    clearConsole();
				cout<<"YOU HAVE FOUND THE KEY AND ESCAPED"<<endl;
				pauseConsole();
				exit(0);
			  }
			  else
				  if(action=='a')
				  {
				    location=0;
					return(true);
				  }
				  else
				  return(false);
		  break;
		  }
	  case 3:
		{
		  if(action=='w')
		  {
		    location=0;
			return(true);
		  }
		  else
			  if(action=='d')
			  {
			    
				location=4;
				key=true;
				return(true);
			  }
			  else
				  return(false);
		  break;
		}
	  case 4:
		 {
			if(action=='a')
		  {
		    location=3;
			return(true);
		  }
		  else
			  if(action=='w')
			  {
				  location=1;
				  return(true);
			  }
			  else
				  return(false);
			break;
		 }
		  
	 }
	}
	



//Check the end-of-game conditions.  If the player is out
//of health or the player has reached room 2 (i.e., outside)
//then the game is over.
bool gameIsNotDone(int location, int health, bool key)
{

	if(health>0&&key!=true)
			return(true);
	else
		if(health<=0)
		{
			clearConsole();
			cout<<" YOU DIED... RIP."<<endl;
			pauseConsole();
			return(false);
		}

}