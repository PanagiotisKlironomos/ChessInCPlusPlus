#include "Gui.h"
/**************
boot graphical interface
and table initialization
*******************/
void Gui::startProcess()
{
	system ("chcp 1253");
	system ("cls");
	Board board1;
	board1.initBoard();
	return startMenu(board1);
}
/**************
menu display and
user login
*******************/
void Gui::startMenu(Board b){ 

 string message= "CHOICES: (N)EW GAME / (L)OAD GAME / E(X)IT :  "  ;
 
 	HWND hwnd = GetConsoleWindow();
	if( hwnd != NULL )
	{ 
		SetWindowPos(hwnd ,0,0,0 ,800,650 ,SWP_SHOWWINDOW|SWP_NOMOVE); 
	}
	HANDLE  hConsole;
	hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	HMENU hMenu = GetSystemMenu(hwnd, FALSE);
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND) ;
	DeleteMenu(hMenu, SC_SIZE, MF_BYCOMMAND) ;
 
cout << "  _    _       _                    _ _                  __  "  <<endl;
cout << " | |  | |     (_)                  (_) |                / _| "  <<endl;
cout << " | |  | |_ __  ___   _____ _ __ ___ _| |_ _   _    ___ | |_  "  <<endl;
cout << " | |  | | '_ \\| \\ \\ / / _ \\ '__/ __| | __| | | |  / _ \\|  _| "  <<endl;
cout << " | |__| | | | | |\\ V /  __/ |  \\__ \\ | |_| |_| | | (_) | |   "  <<endl;
cout << "  \\____/|_| |_|_| \\_/ \\___|_|  |___/_|\\__|\\__, |  \\___/|_|   "  <<endl;
cout << "                                           __/ |             "  <<endl;
cout << " __          __       _             _   _ |___/              "  <<endl;
cout << " \\ \\        / /      | |       /\\  | | | | (_)               "  <<endl;
cout << "  \\ \\  /\\  / /__  ___| |_     /  \\ | |_| |_ _  ___ __ _      "  <<endl;
cout << "   \\ \\/  \\/ / _ \\/ __| __|   / /\\ \\| __| __| |/ __/ _` |     "  <<endl;
cout << "    \\  /\\  /  __/\\__ \\ |_   / ____ \\ |_| |_| | (_| (_| |     "  <<endl;
cout << "     \\/  \\/ \\___||___/\\__| /_/    \\_\\__|\\__|_|\\___\\__,_|    "  <<endl;

cout << "   _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____ "  <<endl; 
cout << "  (_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)"  <<endl;

cout << "   _____ _                      __            "  <<endl;
cout << "  / ____| |                    / _|           "  <<endl;
cout << " | |    | |__   ___  ___ ___  | |_ ___  _ __  "  <<endl;
cout << " | |    | '_ \\ / _ \\/ __/ __| |  _/ _ \\| '__| "  <<endl;
cout << " | |____| | | |  __/\\__ \\__ \\ | || (_) | |    "  <<endl;
cout << "  \\_____|_| |_|\\___||___/___/ |_| \\___/|_|    "  <<endl;
cout << " |__ \\        | |                             "  <<endl;
cout << "    ) |  _ __ | | __ _ _   _  ___ _ __ ___    "  <<endl;
cout << "   / /  | '_ \\| |/ _` | | | |/ _ \\ '__/ __|   "  <<endl;
cout << "  / /_  | |_) | | (_| | |_| |  __/ |  \\__ \\   "  <<endl;
cout << " |____| | .__/|_|\\__,_|\\__, |\\___|_|  |___/   "  <<endl;
cout << "        | |             __/ |                 "  <<endl;
cout << "        |_|            |___/                 "  <<endl;
return takeStartInput(&b, message);    
}
/**************
all program-user dialogs but also functionality
during a lot
*******************/
void Gui::newGame (Board board1) 
{
	int i;
	char  input1[3];
	char  input2[3];
	vector<char> white;
	vector<char> black;
	vector<Move*> moves;
	bool notend=true;
	bool flag = true; // white first
	string  endMessage;
	while(notend)
	{
		string piecemsg;
		string piececlr;
		string checkColor;
		bool input1Flag=false;
		bool input2Flag=false;
		bool input3Flag = false;
		if (flag) {	piecemsg = "white"; piececlr="WHITE"; } else {piecemsg = "black"; piececlr="BLACK";	}
		system("cls");
		refresh(board1);
		if((!white.empty()))
		{
			cout << "Captive whites : ";
			for ( i=0; i<white.size()-1; ++i)
    			cout  << white[i]<<", ";
    		cout  << white[white.size()-1]<<endl;
    	}
		if((!black.empty()))
		{
			cout << "Captive blacks : ";
			for ( i=0; i<black.size()-1; ++i)
    			cout  << black[i]<<", ";
    		cout  << black[black.size()-1]<<endl;
    	}
		cout<< piecemsg+"s turn !"<<endl;
		do
		{
			input1Flag = false;
			cout<<"Enter(RE) for repeating moves or  \n";
			if (flag)  cout<<"Enter (RH) for saving the game or \n";
			takeInput(input1,"Enter position of the "+piecemsg +" pawn: ");
			if ( input1[0] =='9' && input1[1] =='R')  
			{ 
				Board board2= board1;
				board2.initBoard();
				int i;
				system("cls");
				refresh(board2);
				for(i=0; i<moves.size(); ++i) 
				{
					board2.makeMove((*moves[i]).getNow(), (*moves[i]).getNext());
					cout<<" Press enter for the next move";
					getchar(); system("cls");
					refresh(board2);
				}
    			cout<<"End of moves. press enter to return to the game"; getchar(); input1Flag=true; continue;				
				
			}
			if ( input1[0] =='9' && input1[1] =='9')  
			{
				if (piececlr != "WHITE")
				{ 
					cout<< "!!Saving in whites turn!! "<<endl; 
					input1Flag = true; 
					continue;
				}
				else
				{
					board1.writeFile();
					cout<< "!!Game saved in the file uniwa.chess!! "<<endl; 
					input1Flag = true; 
					continue;					
				}
			}
   			if (board1.getSquares((int)input1[1]-'0', (int)input1[0]-'0').getEmpty() ) 
			{
				cout<<"!!No pawn here!! "<<endl; 
				input1Flag = true; 
				continue;
			}

			if (board1.getSquares((int)input1[1]-'0',(int)input1[0]-'0').getPiece()->getColor() != piececlr)  
			{
				cout<< "!!Wrong pawn!! "<<endl; 
				input1Flag = true; 
				continue;
			}
			
		}while (input1Flag);
		do
		{
			input2Flag=false;
			input3Flag = false;
			takeInput(input2,"enter the new position \nor (PR) for a new try: ");
			if (! (input2[0] == '8' && input2[1] == '8' ) )
			{
				if (input1[0]== input2[0] && input1[1]== input2[1] ) {cout<<"!!Move not accepted!!"<<endl; input2Flag = true; continue;}
				if (input1[0]== input2[0] && input1[1]== input2[1] ) {cout<<"!!Move not accepted!!"<<endl; input2Flag = true; continue;}
				if (  board1.getSquares((int)input2[1]-'0', (int)input2[0]-'0').getPiece()->getColor() == piececlr) {cout<<"!!Can't capture a pawn of the same colour!!"<<endl; input2Flag = true; continue;}
			
			}
			else if (input2[0] == '8' && input2[1] == '8' ) { input3Flag = true; break; }
		}while (input2Flag);
		 
		if (input3Flag) continue;
		
		if ( ! board1.getSquares((int)input2[1]-'0', (int)input2[0]-'0').getEmpty() ) 
			if (!flag)
				white.push_back (board1.getSquares((int)input2[1]-'0', (int)input2[0]-'0').getPiece()->getType());
			else
				black.push_back (board1.getSquares((int)input2[1]-'0', (int)input2[0]-'0').getPiece()->getType());
				
		if (board1.isMoveValid(new Position(input1[0],input1[1]),new Position (input2[0],input2[1])) )
		{
			board1.makeMove(new Position(input1[0],input1[1]),new Position (input2[0],input2[1]) );
			moves.push_back (new Move(new Position(input1[0],input1[1]),new Position (input2[0],input2[1]) ));
		}
		else
		{
			cout<< "!!Wrong pawn move!!! \n(Press enter to continue) "<<endl; getchar(); continue;
		}
		flag=  !flag;
		if (piececlr== "WHITE") checkColor="BLACK"; else  checkColor="WHITE";
		notend = board1.IsGameOver(checkColor, &endMessage);
	}
	system("cls");
	refresh(board1);
	cout << endMessage ;
	cout << "Press enter to continue ";  getchar();
	return startProcess();
}
/**************
reprint table with new data (for each move)
*******************/
 void Gui::refresh(Board b)
{
	HWND hwnd = GetConsoleWindow();
	if( hwnd != NULL )
	{ 
		SetWindowPos(hwnd ,0,0,0 ,375,500 ,SWP_SHOWWINDOW|SWP_NOMOVE); 
	}
	HANDLE  hConsole;
	hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	HMENU hMenu = GetSystemMenu(hwnd, FALSE);
	DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND) ;
	DeleteMenu(hMenu, SC_SIZE, MF_BYCOMMAND) ;
	cout<<endl;
   	cout << " ChessInCPLusPlus "<<endl;
   	cout << " Panagiotis Klironomos "<<endl<<endl;
   	b.printBoard(hConsole);
	cout << endl;
   	
}
/**************
entry from the main menu
*******************/
void Gui::takeStartInput( Board * b , string message)
{
	bool flag= true;
	while (flag) 
	{
		string inputStr;
   		char  inputChars[2];
		cout << message ;
    	getline(cin, inputStr);

   	 	if (inputStr.length() != 1)
   	 	{
    	    cout << "Wrong Input ! "<<endl<<"Enter one charachter"<<endl;
        	continue;
    	}
    	strcpy(inputChars, inputStr.c_str());
      	
		switch(inputChars[0])
    	{
      		case 'N' :  
      		case 'n' :  return newGame(*b);	break;
      		case 'L' :  
      		case 'l' :  (*b).readFile(); return newGame((*b)); break;
			case 'X' :  
      		case 'x' :	return ;	
     		default  : cout << "Wrong Input! "<<endl<<"Enter a right choice"<<endl;continue;
   	 	}
   	}
}
/**************
entry during the batch
*******************/
void Gui::takeInput( char  input[], string message)
{ 
	bool flag = true;
 	while (flag) 
 	{
	 
		string inputStr;
   		char  inputChars[3];
		cout << message ;
    	getline(cin, inputStr);

   	 	if (inputStr.length() != 2)
   	 	{
    	    cout << "Wrong Input ! "<<endl<<"Enter two charachters"<<endl;
        	continue;
    	}
    	strcpy(inputChars, inputStr.c_str());
      	
		switch(inputChars[0])
    	{
      		case 'Α' :  
      		case 'α' :
      		case 'a' :
			case 'A' :  inputChars[0] ='0'; break;
			case 'Β' :
			case 'β' :
			case 'b' :
      		case 'B' :  inputChars[0] ='1'; break;
      		case 'Γ' :
    	  	case 'γ' :
    	  	case 'c' :
   		   	case 'C' :  inputChars[0] ='2'; break;
   		   	case 'Δ' :
   		   	case 'δ' :
   		   	case 'd' :
      		case 'D' :  inputChars[0] ='3'; break;
      		case 'Ε' :
      		case 'ε' :
      		case 'e' :
      		case 'E' :  inputChars[0] ='4'; break;
     	 	case 'Ζ' :
      		case 'ζ' :
      		case 'f' :
      		case 'F' :  inputChars[0] ='5'; break;
      		case 'Η' :
      		case 'η' :
      		case 'g' :
      		case 'G' :  inputChars[0] ='6'; break;
      		case 'Θ' :
      		case 'θ' :
      		case 'h' :
      		case 'H' :  inputChars[0] ='7'; break;
      		case 'P' :
      		case 'p' :
      		case 'Π' :
      		case 'π' : inputChars[0] ='8'; break;
      		case 'R' :
      		case 'r' : inputChars[0] ='9'; break;
     		default  : cout << "Wrong Input ! "<<endl<<"Enter right coordinates"<<endl;continue;
   	 	}
    	switch(inputChars[1])
    	{
      		case '1' :inputChars[1] ='0'; break;
      		case '2' :inputChars[1] ='1'; break;
      		case '3' :inputChars[1] ='2'; break;
      		case '4' :inputChars[1] ='3'; break;
      		case '5' :inputChars[1] ='4'; break;
      		case '6' :inputChars[1] ='5'; break;
      		case '7' :inputChars[1] ='6'; break;
      		case '8' :inputChars[1] ='7'; break;
      		case 'r' :
      		case 'R' :
      		case 'ρ' :
      		case 'Ρ' : inputChars[1] ='8'; break;
      		case 'Η' :
      		case 'η' :
      		case 'H' :
      		case 'h' : inputChars[1] ='9'; break;
      		case 'Ε' :
      		case 'ε' :
      		case 'E' :
      		case 'e' : inputChars[1] ='R'; break;
      		default  : cout << "Wrong Input ! "<<endl<<"Enter right coordinates"<<endl;continue;
    	}
    	flag = false;
     	input[0 ] = inputChars[0]; input[1] = inputChars[1];
	}	
	
}
 	


      	
	
	
