#include "Gui.h"
/**************
εκκίνηση γραφικού περιβάλλοντος
και αρχικοποίση πίνακα
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
εμφάνιση μενού και 
είσοδος από τον χρήστη
*******************/
void Gui::startMenu(Board b){ 

 string message= "ΕΠΙΛΟΓΕΣ: (N)EO ΠΑΙΧΝΙΔΙ / (Φ)ΟΡΤΩΣΗ  ΠΑΙΧΝΙΔΙΟΥ / Ε(Ξ)ΟΔΟΣ :  "  ;
 
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
 
cout << " _______ ___  _   _ _____ _______ _________ _____ _   _ __   __ ___ ___             "<<endl;
cout << "(   _   ) _ \\| \\ | |  ___|   _   |   )  ___|_   _) | | |  \\ /  (   ) _ \\           " <<endl;
cout << " | | | | |_| |  \\| | |_   | | | | | | \\ \\    | | | |_| |   v   || | | | |          " <<endl;
cout << " | | | |  _  |     |  _)  | | | | | |  > >   | | |  _  | |\\_/| || | | | |           "<<endl;
cout << " | | | | | | | |\\  | |___ | | | | | | / /__  | | | | | | |   | || | |_| |           "<<endl;
cout << " |_| |_|_| |_|_| \\_|_____)|_| |_|(___)_____) |_| |_| |_|_|   |_(___)___/           " <<endl;                                                                                                                                                                     
cout << "       __   __ _____ ___ _   ___   _______    ___ _____ _____ ___ _   ___   _______ "<<endl;
cout << "    /\\(_ \\ / _|_   _|   ) | / / | | \\  ___)  / _ (_   _|_   _|   ) | / / | | \\  ___)"<<endl;
cout << "   /  \\ \\ v /   | |  | || |/ /| |_| |\\ \\    | |_| || |   | |  | || |/ /| |_| |\\ \\"  <<endl; 
cout << "  / /\\ \\ | |    | |  | ||   < |  _  | > >   |  _  || |   | |  | ||   < |  _  | > >  "<<endl;
cout << " / /__\\ \\| |    | |  | || |\\ \\| | | |/ /__  | | | || |   | |  | || |\\ \\| | | |/ /__ "<<endl;
cout << "/________\\_|    |_| (___)_| \\_\\_| |_/_____) |_| |_||_|   |_| (___)_| \\_\\_| |_/_____)"  <<endl;   

cout << "   _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____ "  <<endl; 
cout << "  (_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)"  <<endl;


cout << "  ______   _   __   ___    _   __  ___    _____  ___   ___  "  <<endl;             
cout << "  \\  ___) | | / /  / _ \\  | | / / (   )  |  ___)(   ) / _ \\ "  <<endl;             
cout << "   \\ \\    | |/ /  | |_| | | |/ /   | |   | |     | | | |_| |"  <<endl;             
cout << "    > >   |   <   |  _  | |   <    | |   | |     | | |  _  |"  <<endl;             
cout << "   / /__  | |\\ \\  | | | | | |\\ \\   | |   | |     | | | | | |"  <<endl;             
cout << "  /_____) |_| \\_\\ |_| |_| |_| \\_\\ (___)  |_|    (___)|_| |_|"  <<endl;             
cout << "          __   __  ___    _______  ___   ___  _   __ _____  _____ ______ "  <<endl;
cout << "      /\\ (_ \\ / _)/ _ \\  (   _   )/ _ \\ (   )| | / /(_   _)|  ___)\\  ___)"  <<endl;
cout << "     /  \\  \\ v / | | | |  | | | || |_| | | | | |/ /   | |  | |_    \\ \\   "  <<endl;
cout << "    / /\\ \\  | |  | | | |  | | | ||  _  | | | |   <    | |  |  _)    > >  "  <<endl;
cout << "   / /__\\ \\ | |  | |_| |  | | | || | | | | | | |\\ \\   | |  | |___  / /__ "  <<endl;
cout << "  /________\\|_|   \\___/   |_| |_||_| |_|(___)|_| \\_\\  |_|  |_____)/_____)"  <<endl;
cout << "                                                                         "  <<endl; 
return takeStartInput(&b, message);    
}
/**************
όλοι οι διάλογοι προγράμματος-χρήστη αλλά και η λειτουργικότητα
κατα την διάρκεια μιας παρτίδας
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
		if (flag) {	piecemsg = "άσπρ"; piececlr="WHITE"; } else {piecemsg = "μαύρ"; piececlr="BLACK";	}
		system("cls");
		refresh(board1);
		if((!white.empty()))
		{
			cout << "Αιχμαλωτισμένα άσπρα : ";
			for ( i=0; i<white.size()-1; ++i)
    			cout  << white[i]<<", ";
    		cout  << white[white.size()-1]<<endl;
    	}
		if((!black.empty()))
		{
			cout << "Αιχμαλωτισμένα μαύρα : ";
			for ( i=0; i<black.size()-1; ++i)
    			cout  << black[i]<<", ";
    		cout  << black[black.size()-1]<<endl;
    	}
		cout<< "Σειρά "+piecemsg+"ων !"<<endl;
		do
		{
			input1Flag = false;
			cout<<"Πατήστε ΣΕ για επανάληψη κινή(ΣΕ)ων ή \n";
			if (flag)  cout<<"Πατήστε ΣΗ για αποθήκευ(ΣΗ) παιχνιδιού ή \n";
			takeInput(input1,"Πληκτρολογήστε θέση "+piecemsg +"ου πιονιού: ");
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
					cout<<" Πιέστε Enter για την επόμενη κίνηση";
					getchar(); system("cls");
					refresh(board2);
				}
    			cout<<"Tέλος κινήσεων. Enter για επιστροφή στο παιχνίδι"; getchar(); input1Flag=true; continue;				
				
			}
			if ( input1[0] =='9' && input1[1] =='9')  
			{
				if (piececlr != "WHITE")
				{ 
					cout<< "!!Η αποθήκευση γίνεται στην σειρά των άσπρων!! "<<endl; 
					input1Flag = true; 
					continue;
				}
				else
				{
					board1.writeFile();
					cout<< "!!Το παιχνίδι αποθκέυτηκε στο αρχείο uniwa.chess!! "<<endl; 
					input1Flag = true; 
					continue;					
				}
			}
   			if (board1.getSquares((int)input1[1]-'0', (int)input1[0]-'0').getEmpty() ) 
			{
				cout<<"!!Δεν υπάρχει πιόνι εδώ!! "<<endl; 
				input1Flag = true; 
				continue;
			}

			if (board1.getSquares((int)input1[1]-'0',(int)input1[0]-'0').getPiece()->getColor() != piececlr)  
			{
				cout<< "!!Λάθος πιόνι!! "<<endl; 
				input1Flag = true; 
				continue;
			}
			
		}while (input1Flag);
		do
		{
			input2Flag=false;
			input3Flag = false;
			takeInput(input2,"Πληκτρολογήστε επιθυμητή θέση \nή ΠΡ ή PR(en) για νέα προσπάθεια: ");
			if (! (input2[0] == '8' && input2[1] == '8' ) )
			{
				if (input1[0]== input2[0] && input1[1]== input2[1] ) {cout<<"!!Μη αποδεκτή κίνηση!!"<<endl; input2Flag = true; continue;}
				if (  board1.getSquares((int)input2[1]-'0', (int)input2[0]-'0').getPiece()->getColor() == piececlr) {cout<<"!!Δεν γίνετε να αιχμαλωτίσετε πιόνι ίδιου χρώματος!!"<<endl; input2Flag = true; continue;}
			
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
			cout<< "!!Λάθος κίνηση πιονιού!!! \n(Πιέστε enter για συνέχεια) "<<endl; getchar(); continue;
		}
		flag=  !flag;
		if (piececlr== "WHITE") checkColor="BLACK"; else  checkColor="WHITE";
		notend = board1.IsGameOver(checkColor, &endMessage);
	}
	system("cls");
	refresh(board1);
	cout << endMessage ;
	cout << "Πιέστε enter για συνέχεια ";  getchar();
	return startProcess();
}
/**************
επανεκτύπωση πίνακα με τα νέα δεδομένα (για κάθε κίνηση)
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
   	cout << " ΣΚΑΚΙ 2019 ΕΡΓΑΣΤΗΡΙΟ ΑΝΤ/ΦΟΥΣ ΠΡΟΓ/ΣΜΟΥ "<<endl;
   	cout << " ΠΑΝΑΓΙΩΤΗΣ ΚΛΗΡΟΝΟΜΟΣ AM: 711151128"<<endl<<endl;
   	b.printBoard(hConsole);
	cout << endl;
   	
}
/**************
είσοδος από το αρχικό μενού
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
    	    cout << "Λάθος εισαγωγή ! "<<endl<<"Πλήκτρολογήστε 1 χαρακτήρα"<<endl;
        	continue;
    	}
    	strcpy(inputChars, inputStr.c_str());
      	
		switch(inputChars[0])
    	{
      		case 'N' :  
      		case 'n' :
      		case 'Ν' :
			case 'ν' :  return newGame(*b);	break;
      		case 'Φ' :  
      		case 'φ' :
      		case 'F' :
			case 'f' :  (*b).readFile(); return newGame((*b)); break;
			case 'Ξ' :  
      		case 'ξ' :
      		case 'J' :
			case 'j' :	return ;	
     		default  : cout << "Λάθος εισαγωγή ! "<<endl<<"Πλήκτρολογήστε σωστή επιλογή"<<endl;continue;
   	 	}
   	}
}
/**************
είσοδος κατα την διάρκεια της παρτίδας
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
    	    cout << "Λάθος εισαγωγή ! "<<endl<<"Πλήκτρολογήστε 2 χαρακτήρες"<<endl;
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
      		case 'Σ' :
      		case 'σ' :
      		case 'S' :
      		case 's' : inputChars[0] ='9'; break;
     		default  : cout << "Λάθος εισαγωγή ! "<<endl<<"Πλήκτρολογήστε σωστές συντεταγμένες"<<endl;continue;
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
      		default  : cout << "Λάθος εισαγωγή ! "<<endl<<"Πλήκτρολογήστε σωστές συντεταγμένες"<<endl;continue;
    	}
    	flag = false;
     	input[0 ] = inputChars[0]; input[1] = inputChars[1];
	}	
	
}
 	


      	
	
	
