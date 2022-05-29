#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>

char board[3][3];
char board1[3][3];
char PLAYER_1='X';
char PLAYER_2='O';
char PLAYER_3='&';
char PLAYER_4='@';


void printboard();
void resetboard();
void resetb2();
void resetb4(); 
int  isfull();
int  full();
void *playermove_1(void *args);
void *playermove_2(void *args);
void *playermove_3(void *args);
void *playermove_4(void *args);
char checkwinner();
char checkwinner1();
void printwinner();
void *tictac_2(void *args);
void *tictac_4(void *args);
void board4();
void resetboard1();

int b3[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int b2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int b4[3][3]={{1,2,3},{4,5,6},{7,8,9}};
 


int main()
{

  pthread_t p[2]; 
   int no;
   system("clear");
   printf("------------------------------------------\n");
   printf("------------------------------------------\n\n");
   printf("\t\tWELCOME\n\n");
   printf("------------------------------------------\n");
   printf("------------------------------------------\n\n");
   printf("1 : TICTACTEO for 2 players\n");
   printf("2 : TICTACTEO for 4 players\n");
   printf("3 : TO EXIT\n\n");
   printf("Enter your choice to proceed :  ");
   scanf("%d",&no);
   printf("\n");
   switch(no)
   {
    case 1:
    {
    
    pthread_create(&p[0],NULL,tictac_2,NULL);
    pthread_join(p[0],NULL);
    break;
    }
    case 2:
    {
    //tictac_4();
    pthread_create(&p[1],NULL,tictac_4,NULL);
    pthread_join(p[1],NULL);
    break;
    }
    case 3:
    {
    exit(0);
    }
    default:
    printf("\nInvalid\n");
   }
   
 	 pthread_exit(&p[0]);
 	 pthread_exit(&p[1]);
}
// tictacteo for 2 players
void *tictac_2(void *args)
{

	pthread_t p[2]; 
    char winner=' ';
	char response[1];
	do
	{ 
	winner =' ' ;
	resetboard();
	resetb2(); 
	while (winner==' ' && isfull()!=0)
	{
		printboard();
		//playermove_1();
		pthread_create(&p[0],NULL,playermove_1,NULL);
    		 pthread_join(p[0],NULL);
   
		winner =checkwinner1();
		if(winner!=' '|| isfull()==0)
		{
		break;
		}
		printboard();
		//playermove_2();
		pthread_create(&p[1],NULL,playermove_2,NULL);
    		 pthread_join(p[1],NULL);
   
		winner =checkwinner1();
		if(winner!=' '|| isfull()==0)
		{
		break;
		}
	 }
	printboard();
	printwinner();
	printf("TO CONTINUE PRESS 'Y/y' OR TO EXIT PRESS ANY KEY  :   ");
	scanf("%s",&response[0]);
	} 
	while(response[0]=='Y'||response[0]=='y');
	printf("\n\t\t----------THANKS FOR PLAYING---------\n");
	
	 pthread_exit(&p[0]);
}

// tictac for 4 players
void *tictac_4(void *args)
{
	pthread_t p[4]; 
    	char winner=' ';
	char response[1];
	do
	{ 
	winner =' ' ;
	resetboard();
	resetboard1();
	resetb2(); 
	resetb4(); 
	while (winner==' ' && isfull()!=0)
	{
	while (winner==' ' && full()!=0)
	{
		board4();
		//playermove_1();
		pthread_create(&p[0],NULL,playermove_1,NULL);
    		 pthread_join(p[0],NULL);
   
		winner =checkwinner();
		if(winner!=' '|| isfull()==0)
		{
		break;
		}
		board4();
		//playermove_2();
		pthread_create(&p[1],NULL,playermove_2,NULL);
    		 pthread_join(p[1],NULL);
   
		winner =checkwinner();
		if(winner!=' '|| isfull()==0)
		{
		break;
		}
		board4();
		//playermove_3();
		pthread_create(&p[2],NULL,playermove_3,NULL);
    		pthread_join(p[2],NULL);
   
		winner =checkwinner();
		if(winner!=' '|| full()==0)
		{
		break;
		}
		board4();
		//playermove_4();
		pthread_create(&p[3],NULL,playermove_4,NULL);
    		pthread_join(p[3],NULL);
   
		winner =checkwinner();
		if(winner!=' '|| full()==0)
		{
		break;
		}
	 }}
	board4();
	printwinner();
	printf("TO CONTINUE PRESS 'Y/y' OR TO EXIT PRESS ANY KEY  :   ");
	scanf("%s",&response[0]);
	} 
	while(response[0]=='Y'||response[0]=='y');
	printf("\n\t\t----------THANKS FOR PLAYING---------\n");
	
	 pthread_exit(&p[0]);
}
// reset board
void resetboard()
{


    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
		board[i][j]=b[i][j];
	}
    }
    
    
}
void resetb2()
{

int n=0;
    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
		b2[i][j]=b3[i][j];
	}
    }
    
    
}
//
void resetb4()
{

int n=0;
    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
		b4[i][j]=b3[i][j];
	}
    }
    
    
}
void resetboard1()
{


    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
		board1[i][j]=b[i][j];
	}
    }
    
    
}
//print board
void printboard()
{
system("clear");
    printf("\n\n-------------------------Tic Tac Toe----------------\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}
//check free space in the board 
int isfull()
{
    int freespace=9;
    for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
    {
	if (board[i][j]!=b[i][j])
	freespace--;
    }
    }
    return freespace;  
}

// for board 1
int full()
{
    int freespace=9;
    for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
    {
	if (board1[i][j]!=b[i][j])
	freespace--;
    }
    }
    return freespace;  
}

//player 1 move
 void *playermove_1(void *args)
 {
 	pthread_t p[1];
	int ch;
	int flag=0;
	printf("Player : 1  Its Your turn  \n");
	printf("Please Enter any number From (1---9)  :  ");
	scanf ("%d",&ch);
	
	while(!(ch>=1&&ch<=9))
	{
	printf("\n\t---------------INVALID TURN-------------------\n");
	printf("Please Renter any number From (1---9)  :  ");
	scanf ("%d",&ch);
	}
	printf("\n");
	for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{
	if (ch==b2[i][j])
	{
	b2[i][j]=-1;
	board[i][j]=PLAYER_1;
	flag=1;
	break;
	}
	}
	}
	if(flag==0)
	{
		printf("\n This index has been already filled. Please enter another index.\n");
		/* pthread_create(&p[0],NULL,playermove_1,NULL);
    		 pthread_join(p[0],NULL);*/
   		
		 playermove_1(NULL);
	}
	
	 //pthread_exit(&p[0]);
 }
void *playermove_2(void *args)
 {
 	pthread_t p[1];
	int ch;
	int flag=0;
	printf("Player : 2  Its Your turn \n");
	printf("Please Enter any number From (1---9)  :  ");
	scanf ("%d",&ch);
	while(ch<1||ch>9)
	{
	printf("\n\t---------------INVALID TURN-------------------\n");
	printf("Please Renter any number From (1---9)  :  ");
	scanf ("%d",&ch);	
	}	
	printf("\n");
		
	for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{
	if (ch==b2[i][j])
	{
	b2[i][j]=-1;
	board[i][j]=PLAYER_2;
	flag=1;
	break;
	}
	}
	}
	
	if(flag==0)
	{
		printf("\n This index has been already filled. Please enter another index.\n");
		/* pthread_create(&p[0],NULL,playermove_2,NULL);
    		 pthread_join(p[0],NULL);*/
   		
		playermove_2(NULL);   
	}
	
	 pthread_exit(&p[0]);
 }
//player 3
void *playermove_3(void *args)
 {
 	pthread_t p[1];
	int ch;
	int flag=0;
	printf("Player : 3  Its Your turn  \n");
	printf("Please Enter any number From (1---9)  :  ");
	scanf ("%d",&ch);
	while(ch<1||ch>9)
	{
	printf("\n\t---------------INVALID TURN-------------------\n");
	printf("Please Renter any number From (1---9)  :  ");
	scanf ("%d",&ch);
	}
	printf("\n");
	for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{
	if (ch==b4[i][j])
	{
	b4[i][j]=-1;
	board1[i][j]=PLAYER_3;
	flag=1;
	break;
	}
	}
	}
	
	if(flag==0)
	{
		printf("\n This index has been already filled. Please enter another index.\n");
		 /*pthread_create(&p[0],NULL,playermove_3,NULL);
    		 pthread_join(p[0],NULL);*/
    		 playermove_3(NULL);
   
	}
	
	 pthread_exit(&p[0]);
 }
 // player 4 turn
 void *playermove_4(void *args)
 {
 	pthread_t p[1];
	int ch;
	int flag=0;
	printf("Player : 4 Its Your turn  \n");
	printf("Please Enter any number From (1---9)  :  ");
	scanf ("%d",&ch);
	while(ch<1||ch>9)
	{
	printf("\n\t---------------INVALID TURN-------------------\n");
	printf("Please Renter any number From (1---9)  :  ");
	scanf ("%d",&ch);
	}
	printf("\n");
	for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{
	if (ch==b4[i][j])
	{
	b4[i][j]=-1;
	board1[i][j]=PLAYER_4;
	flag=1;
	break;
	}
	}
	}
	
	if(flag==0)
	{
		printf("\n This index has been already filled. Please enter another index.\n");
		/* pthread_create(&p[0],NULL,playermove_4,NULL);
    		 pthread_join(p[0],NULL);*/
   		playermove_4(NULL);
	}
	
	 pthread_exit(&p[0]);
 }
 
 // check winner
 char checkwinner()
 {
 //for rows
    for(int i=0;i<3;i++)
    {
    if (board[i][0]==board[i][1] &&board[i][0]==board[i][2] )
		return board[i][0];
    }
 //for column
    for(int i=0;i<3;i++)
    {
    if (board[0][i]==board[1][i] &&board[0][i]==board[2][i] )
		return board[0][i];
    }
 //for diagonals
    
    if (board[0][0]==board[1][1] &&board[0][0]==board[2][2] )
		  return board[0][0];
    if (board[0][2]==board[1][1] &&board[0][2]==board[2][0] )
		  return board[0][2];
		 
    
    //for rows
    for(int i=0;i<3;i++)
    {
    if (board1[i][0]==board1[i][1] &&board1[i][0]==board1[i][2] )
		return board1[i][0];
    }
 //for column
    for(int i=0;i<3;i++)
    {
    if (board1[0][i]==board1[1][i] &&board1[0][i]==board1[2][i] )
		return board1[0][i];
    }
 //for diagonals
    
    if (board1[0][0]==board1[1][1] &&board1[0][0]==board1[2][2] )
		  return board1[0][0];
    if (board1[0][2]==board1[1][1] &&board1[0][2]==board1[2][0] )
		  return board1[0][2];
		  return ' '; 		  
 }
 char checkwinner1()
 {
 //for rows
    for(int i=0;i<3;i++)
    {
    if (board[i][0]==board[i][1] &&board[i][0]==board[i][2] )
		return board[i][0];
    }
 //for column
    for(int i=0;i<3;i++)
    {
    if (board[0][i]==board[1][i] &&board[0][i]==board[2][i] )
		return board[0][i];
    }
 //for diagonals
    
    if (board[0][0]==board[1][1] &&board[0][0]==board[2][2] )
		  return board[0][0];
    if (board[0][2]==board[1][1] &&board[0][2]==board[2][0] )
		  return board[0][2];
		 
    
   		  return ' '; 		  
 }
 // print winner function
 void printwinner()
 {
    char w =checkwinner();
    if (w=='X')
    printf("\n \t--------- Hurray ! Palyer 1 has won the Match---------\n");
    else if (w=='O')
    printf("\n\t --------- Hurray ! Palyer 2 has won the Match---------\n");
    else if (w=='@')
    printf("\n\t --------- Hurray ! Palyer 4 has won the Match---------\n");
    else if (w=='&')
    printf("\n\t --------- Hurray ! Palyer 3 has won the Match---------\n");
    else 
    printf("\n \t--------- Oh ! Its a Drawn match---------\n");
 }
 //
 void board4()
{
system("clear");
    
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\nPlayer 3 (&)  -  Player 4 (@)\n\n\n");


    printf("     |     |                                        |     |     \n");
    printf("  %c  |  %c  |  %c                                  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2], board1[0][0], board1[0][1], board1[0][2]);

    printf("_____|_____|_____                              _____|_____|_____\n");
    printf("     |     |                                        |     |     \n");

    printf("  %c  |  %c  |  %c                                  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2],board1[1][0], board1[1][1], board1[1][2]);

    printf("_____|_____|_____                              _____|_____|_____\n");
    printf("     |     |                                        |     |     \n");

    printf("  %c  |  %c  |  %c                                  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2],board1[2][0], board1[2][1], board1[2][2]);

    printf("     |     |                                        |     |     \n\n");

}