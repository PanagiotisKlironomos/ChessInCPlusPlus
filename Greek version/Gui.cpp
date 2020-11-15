#include "Gui.h"
/**************
�������� �������� �������������
��� ����������� ������
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
�������� ����� ��� 
������� ��� ��� ������
*******************/
void Gui::startMenu(Board b){ 

 string message= "��������: (N)EO �������� / (�)������  ���������� / �(�)���� :  "  ;
 
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
���� �� �������� ������������-������ ���� ��� � ���������������
���� ��� �������� ���� ��������
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
		if (flag) {	piecemsg = "����"; piececlr="WHITE"; } else {piecemsg = "����"; piececlr="BLACK";	}
		system("cls");
		refresh(board1);
		if((!white.empty()))
		{
			cout << "�������������� ����� : ";
			for ( i=0; i<white.size()-1; ++i)
    			cout  << white[i]<<", ";
    		cout  << white[white.size()-1]<<endl;
    	}
		if((!black.empty()))
		{
			cout << "�������������� ����� : ";
			for ( i=0; i<black.size()-1; ++i)
    			cout  << black[i]<<", ";
    		cout  << black[black.size()-1]<<endl;
    	}
		cout<< "����� "+piecemsg+"�� !"<<endl;
		do
		{
			input1Flag = false;
			cout<<"������� �� ��� ��������� ����(��)�� � \n";
			if (flag)  cout<<"������� �� ��� ��������(��) ���������� � \n";
			takeInput(input1,"�������������� ���� "+piecemsg +"�� �������: ");
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
					cout<<" ������ Enter ��� ��� ������� ������";
					getchar(); system("cls");
					refresh(board2);
				}
    			cout<<"T���� ��������. Enter ��� ��������� ��� ��������"; getchar(); input1Flag=true; continue;				
				
			}
			if ( input1[0] =='9' && input1[1] =='9')  
			{
				if (piececlr != "WHITE")
				{ 
					cout<< "!!� ���������� ������� ���� ����� ��� ������!! "<<endl; 
					input1Flag = true; 
					continue;
				}
				else
				{
					board1.writeFile();
					cout<< "!!�� �������� ����������� ��� ������ uniwa.chess!! "<<endl; 
					input1Flag = true; 
					continue;					
				}
			}
   			if (board1.getSquares((int)input1[1]-'0', (int)input1[0]-'0').getEmpty() ) 
			{
				cout<<"!!��� ������� ����� ���!! "<<endl; 
				input1Flag = true; 
				continue;
			}

			if (board1.getSquares((int)input1[1]-'0',(int)input1[0]-'0').getPiece()->getColor() != piececlr)  
			{
				cout<< "!!����� �����!! "<<endl; 
				input1Flag = true; 
				continue;
			}
			
		}while (input1Flag);
		do
		{
			input2Flag=false;
			input3Flag = false;
			takeInput(input2,"�������������� ��������� ���� \n� �� � PR(en) ��� ��� ����������: ");
			if (! (input2[0] == '8' && input2[1] == '8' ) )
			{
				if (input1[0]== input2[0] && input1[1]== input2[1] ) {cout<<"!!�� �������� ������!!"<<endl; input2Flag = true; continue;}
				if (  board1.getSquares((int)input2[1]-'0', (int)input2[0]-'0').getPiece()->getColor() == piececlr) {cout<<"!!��� ������ �� ������������� ����� ����� ��������!!"<<endl; input2Flag = true; continue;}
			
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
			cout<< "!!����� ������ �������!!! \n(������ enter ��� ��������) "<<endl; getchar(); continue;
		}
		flag=  !flag;
		if (piececlr== "WHITE") checkColor="BLACK"; else  checkColor="WHITE";
		notend = board1.IsGameOver(checkColor, &endMessage);
	}
	system("cls");
	refresh(board1);
	cout << endMessage ;
	cout << "������ enter ��� �������� ";  getchar();
	return startProcess();
}
/**************
������������ ������ �� �� ��� �������� (��� ���� ������)
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
   	cout << " ����� 2019 ���������� ���/���� ����/���� "<<endl;
   	cout << " ���������� ���������� AM: 711151128"<<endl<<endl;
   	b.printBoard(hConsole);
	cout << endl;
   	
}
/**************
������� ��� �� ������ �����
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
    	    cout << "����� �������� ! "<<endl<<"�������������� 1 ���������"<<endl;
        	continue;
    	}
    	strcpy(inputChars, inputStr.c_str());
      	
		switch(inputChars[0])
    	{
      		case 'N' :  
      		case 'n' :
      		case '�' :
			case '�' :  return newGame(*b);	break;
      		case '�' :  
      		case '�' :
      		case 'F' :
			case 'f' :  (*b).readFile(); return newGame((*b)); break;
			case '�' :  
      		case '�' :
      		case 'J' :
			case 'j' :	return ;	
     		default  : cout << "����� �������� ! "<<endl<<"�������������� ����� �������"<<endl;continue;
   	 	}
   	}
}
/**************
������� ���� ��� �������� ��� ��������
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
    	    cout << "����� �������� ! "<<endl<<"�������������� 2 ����������"<<endl;
        	continue;
    	}
    	strcpy(inputChars, inputStr.c_str());
      	
		switch(inputChars[0])
    	{
      		case '�' :  
      		case '�' :
      		case 'a' :
			case 'A' :  inputChars[0] ='0'; break;
			case '�' :
			case '�' :
			case 'b' :
      		case 'B' :  inputChars[0] ='1'; break;
      		case '�' :
    	  	case '�' :
    	  	case 'c' :
   		   	case 'C' :  inputChars[0] ='2'; break;
   		   	case '�' :
   		   	case '�' :
   		   	case 'd' :
      		case 'D' :  inputChars[0] ='3'; break;
      		case '�' :
      		case '�' :
      		case 'e' :
      		case 'E' :  inputChars[0] ='4'; break;
     	 	case '�' :
      		case '�' :
      		case 'f' :
      		case 'F' :  inputChars[0] ='5'; break;
      		case '�' :
      		case '�' :
      		case 'g' :
      		case 'G' :  inputChars[0] ='6'; break;
      		case '�' :
      		case '�' :
      		case 'h' :
      		case 'H' :  inputChars[0] ='7'; break;
      		case 'P' :
      		case 'p' :
      		case '�' :
      		case '�' : inputChars[0] ='8'; break;
      		case '�' :
      		case '�' :
      		case 'S' :
      		case 's' : inputChars[0] ='9'; break;
     		default  : cout << "����� �������� ! "<<endl<<"�������������� ������ �������������"<<endl;continue;
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
      		case '�' :
      		case '�' : inputChars[1] ='8'; break;
      		case '�' :
      		case '�' :
      		case 'H' :
      		case 'h' : inputChars[1] ='9'; break;
      		case '�' :
      		case '�' :
      		case 'E' :
      		case 'e' : inputChars[1] ='R'; break;
      		default  : cout << "����� �������� ! "<<endl<<"�������������� ������ �������������"<<endl;continue;
    	}
    	flag = false;
     	input[0 ] = inputChars[0]; input[1] = inputChars[1];
	}	
	
}
 	


      	
	
	
