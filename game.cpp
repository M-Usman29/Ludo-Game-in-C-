//============================================================================
// Name        :.cpp
// Author      :Muhammad Usman
// Roll no     :20i-0416
//Section      :Z
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <iomanip>
// for basic math functions such as cos, sin, sqrt
using namespace std;
int dice_val,noof_players=4,player_turn=1,plr1_start=1,plr2_start=1,plr3_start=1,plr4_start=1;
int count_six;
const int size=8;
int player1_Rtoken[size]={210,120,300,120,210,220,300,220};
int player4_Gtoken[size]={710,120,800,120,710,220,800,220};
int player2_Btoken[size]={210,615,300,615,210,715,300,715};
int player3_Ytoken[size]={710,615,800,615,710,715,800,715};

        //T STANDS FOR TOKEN ,r STANDS for red , 1 stands for token number;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;



void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	DrawSquare( 110, 23 ,300,colors[RED]); 
	DrawSquare( 148,60 ,220,colors[ANTIQUE_WHITE]);
	DrawSquare( 610, 23 ,300,colors[GREEN]); 
	DrawSquare( 648, 60 ,220,colors[ANTIQUE_WHITE]);
	//Mushroom
	DrawSquare(110, 518 ,300,colors[POWDER_BLUE]); 
	DrawSquare( 150, 559 ,220,colors[ANTIQUE_WHITE]);
	DrawSquare( 610, 517 ,300,colors[GOLD]); 
	DrawSquare( 648, 554 ,220,colors[ANTIQUE_WHITE]);
	DrawSquare( 410,320,200,colors[GRAY]);
	//Display Score
	DrawString( 10, 800, "DICE", colors[NAVY]);
	//Spider
	DrawTriangle( 408, 520 , 408, 310 , 510 , 420, colors[POWDER_BLUE] );
	DrawTriangle( 408, 320 , 610, 320 , 510 , 420, colors[RED] ); 
	DrawTriangle( 610, 320 , 610, 520 , 510 , 420, colors[GREEN] );
	DrawTriangle( 408, 520 , 610, 520 , 510 , 420, colors[GOLD] );
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 110 ,23 , 110 , 818 , 4 , colors[BLACK] );	
	DrawLine( 610 ,23 , 610 , 816 , 4 , colors[BLACK] );	
	DrawLine( 410 ,23 , 410 , 816 , 4 , colors[BLACK] );	
	DrawLine( 907 ,23 , 907 , 816 , 4 , colors[BLACK] );
	DrawLine( 110,23 , 610 , 23 , 4 , colors[BLACK] );
	DrawLine( 609,23 , 909, 23 , 4 , colors[BLACK] );
	DrawLine( 110,320 , 909, 320 , 4 , colors[BLACK] );	
	DrawLine( 110,816 , 909, 816 , 4 , colors[BLACK] );
	DrawLine( 110,516 , 909, 515 , 4 , colors[BLACK] );
	DrawLine( 148,60, 368,60 , 4 , colors[BLACK] );
	DrawLine( 148,280, 368,280 , 4 , colors[BLACK] );
	DrawLine( 148,60, 148,280 , 4 , colors[BLACK] );
	DrawLine( 368,60, 368,280 , 4 , colors[BLACK] );
	DrawLine( 646,60,867 ,60, 4 , colors[BLACK] );
	DrawLine( 646,60,646 ,280, 4 , colors[BLACK] );
	DrawLine( 867,60,867 ,280, 4 , colors[BLACK] );
	DrawLine( 646,280,867 ,280, 4 , colors[BLACK] );
	DrawLine( 148,559,148 ,779, 4 , colors[BLACK] );
	DrawLine( 148,559,370 ,559, 4 , colors[BLACK] );
	DrawLine( 148,779,370 ,779, 4 , colors[BLACK] );
	DrawLine( 370,559,370 ,779, 4 , colors[BLACK] );
	DrawLine( 648,555,868 ,555, 4 , colors[BLACK] );
	DrawLine( 648,555,648 ,773, 4 , colors[BLACK] );
	DrawLine( 648,773,868 ,773, 4 , colors[BLACK] );
	DrawLine( 868,555,868 ,773, 4 , colors[BLACK] );
	
	//red box playing field vertical lines
	DrawLine( 475,23,475 ,317, 4 , colors[BLACK] );
	DrawLine( 543,23,543 ,317, 4 , colors[BLACK] );
	//yellow box playing field vertical lines
	DrawLine( 475,518,475 ,814, 4 , colors[BLACK] );
	DrawLine( 543,518,543 ,814, 4 , colors[BLACK] );
	//blue box playing field vertical lines
	DrawLine( 108,450,408 ,450, 4 , colors[BLACK] );
	DrawLine( 108,382,408 ,382, 4 , colors[BLACK] );
	//green box playing field vertical lines
	DrawLine( 610,450,906 ,450, 4 , colors[BLACK] );
	DrawLine( 610,382,906 ,382, 4 , colors[BLACK] );
	//red to blue vertical lines
	DrawLine( 160,320,160 ,516, 4 , colors[BLACK] );
	DrawLine( 210,320,210 ,516, 4 , colors[BLACK] );
	DrawLine( 260,320,260 ,516, 4 , colors[BLACK] );
	DrawLine( 310,320,310 ,516, 4 , colors[BLACK] );
	DrawLine( 358,320,358 ,516, 4 , colors[BLACK] );
	//green to golden vertical lines
	DrawLine( 658,320,658 ,516, 4 , colors[BLACK] );
	DrawLine( 708,320,708 ,516, 4 , colors[BLACK] );
	DrawLine( 758,320,758 ,516, 4 , colors[BLACK] );
	DrawLine( 808,320,808 ,516, 4 , colors[BLACK] );
	DrawLine( 856,320,856 ,516, 4 , colors[BLACK] );
	//red to green lines
	DrawLine( 408,74,611 ,74, 4 , colors[BLACK] );
	DrawLine( 408,124,611 ,124, 4 , colors[BLACK] );
	DrawLine( 408,174,611 ,174, 4 , colors[BLACK] );
	DrawLine( 408,224,611 ,224, 4 , colors[BLACK] );
	DrawLine( 408,272,611 ,272, 4 , colors[BLACK] );
	//blue to golden lines
	DrawLine( 408,565,611 ,565, 4 , colors[BLACK] );
	DrawLine( 408,615,611 ,615, 4 , colors[BLACK] );
	DrawLine( 408,665,611 ,665, 4 , colors[BLACK] );
	DrawLine( 408,715,611 ,715, 4 , colors[BLACK] );
	DrawLine( 408,765,611 ,765, 4 , colors[BLACK] );
	
	//now for home boxes of red
	 
	DrawRectangle(412,75,62,48,colors[RED]);//start box of red
	DrawRectangle(477,75,65,48,colors[RED]); 
	DrawRectangle(477,125,65,48,colors[RED]); 
	DrawRectangle(477,175,65,48,colors[RED]);
	DrawRectangle(477,225,65,47,colors[RED]);
	DrawRectangle(477,275,65,45,colors[RED]);
	//stop box after red home
	DrawRectangle(212,322,48,60,colors[SLATE_BM]);
	
	//now for home boxes of blue
	DrawRectangle(161,451,48,63,colors[POWDER_BLUE]);
	DrawRectangle(161,384,48,65,colors[POWDER_BLUE]);
	DrawRectangle(212,384,48,64,colors[POWDER_BLUE]);
	DrawRectangle(262,384,48,65,colors[POWDER_BLUE]);
	DrawRectangle(312,384,46,65,colors[POWDER_BLUE]);
	DrawRectangle(360,384,49,65,colors[POWDER_BLUE]);
	//now for home box of green
        DrawRectangle(809,322,47,60.5,colors[GREEN]);
	DrawRectangle(612,384,46,65,colors[GREEN]);
        DrawRectangle(660,384,48,65,colors[GREEN]);
         DrawRectangle(709,384,48,65,colors[GREEN]);
          DrawRectangle(759,384,48,65,colors[GREEN]);
          DrawRectangle(809,384,47,65,colors[GREEN]);
          //stop box before green home 
           DrawRectangle(759,451,48,64.5,colors[SLATE_BM]);
           //stop box after green home 
	DrawRectangle(544,125,65,48,colors[SLATE_BM]);
	//now for golden home boxes
	DrawRectangle(477,517,65,47,colors[GOLD]);
	DrawRectangle(477,567,65,46,colors[GOLD]);
	DrawRectangle(477,617,65,46,colors[GOLD]);
	DrawRectangle(477,667,65,46,colors[GOLD]);
	DrawRectangle(477,717,65,46,colors[GOLD]);
	DrawRectangle(545,717,65,46,colors[GOLD]);
	//stop box after blue
	DrawRectangle(410,667,64.5,46,colors[SLATE_BM]);
	
	
	//TOKENS OF RED BOX
	DrawCircle(player1_Rtoken[0],player1_Rtoken[1],20, colors[DARK_RED]);//1st token of second row: from left
	DrawCircle(player1_Rtoken[2],player1_Rtoken[3],20, colors[DARK_RED]);//2nd token of second row: from left
	DrawCircle(player1_Rtoken[4],player1_Rtoken[5],20, colors[DARK_RED]);//1st token of first row: from left
	DrawCircle(player1_Rtoken[6],player1_Rtoken[7],20, colors[DARK_RED]);//2nd token of first row: from left
	//TOKENS OF Blue BOX
	DrawCircle(player2_Btoken[0],player2_Btoken[1],20, colors[POWDER_BLUE]);//1st token of second row: from left
        DrawCircle(player2_Btoken[2],player2_Btoken[3],20, colors[POWDER_BLUE]);//2nd token of second row: from left
        DrawCircle(player2_Btoken[4],player2_Btoken[5],20, colors[POWDER_BLUE]);//1st token of first row: from left
	DrawCircle(player2_Btoken[6],player2_Btoken[7],20, colors[POWDER_BLUE]);//2nd token of first row: from left
	//TOKENS OF GREEN BOX BOX
	DrawCircle(player4_Gtoken[0],player4_Gtoken[1],20, colors[GREEN]);//1st token of second row: from left
	DrawCircle(player4_Gtoken[2],player4_Gtoken[3],20, colors[GREEN]);//2nd token of second row: from left
	DrawCircle(player4_Gtoken[4],player4_Gtoken[5],20, colors[GREEN]);//1st token of first row: from left
	DrawCircle(player4_Gtoken[6],player4_Gtoken[7],20, colors[GREEN]);//2nd token of first row: from left
	//TOKENS OF Golden BOX
	DrawCircle(710,615,20, colors[GOLD]);//1st token of second row: from left
	DrawCircle(800,615,20, colors[GOLD]);//2nd token of second row: from left
	DrawCircle(710,715,20, colors[GOLD]);//1st token of first row: from left
	DrawCircle(800,715,20, colors[GOLD]);//2nd token of first row: from left
	
	//sqaure of dice
	DrawSquare( 950, 360 ,100,colors[ROYAL_BLUE]); 
	
	if (dice_val==6){
	DrawCircle(980,375,9, colors[ANTIQUE_WHITE]);
	DrawCircle(980,410,9, colors[ANTIQUE_WHITE]);
	DrawCircle(980,445,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1020,375,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1020,410,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1020,445,9, colors[ANTIQUE_WHITE]);
	}
	if (dice_val==5){
	DrawCircle(970,375,9, colors[ANTIQUE_WHITE]);
	DrawCircle(970,445,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1000,410,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1030,375,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1030,445,9, colors[ANTIQUE_WHITE]);
	}
	if (dice_val==4){
	DrawCircle(980,380,9, colors[ANTIQUE_WHITE]);
	DrawCircle(980,440,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1020,380,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1020,440,9, colors[ANTIQUE_WHITE]);
}
if (dice_val==3){
	DrawCircle(970,440,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1000,410,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1030,380,9, colors[ANTIQUE_WHITE]);
	
}
if (dice_val==2){
	DrawCircle(970,380,9, colors[ANTIQUE_WHITE]);
	DrawCircle(1030,440,9, colors[ANTIQUE_WHITE]);
	
}
if (dice_val==1){
	DrawCircle(1000,410,9, colors[ANTIQUE_WHITE]);
}
switch(player_turn){


case 1:
if(plr1_start==1){
if(dice_val==6){
count_six++;
if(count_six==3){
player_turn=2;
}
else if(count_six<3){
count_six=0;
player1_Rtoken[0]=445;
player1_Rtoken[1]=96;
plr1_start++;
}
}
}

else if (plr1_start>1){
if(dice_val==5){

}
if(dice_val==4){
if(player1_Rtoken[0]==444||player1_Rtoken[0]==445||player1_Rtoken[0]==446||player1_Rtoken[0]==447){//check for token on vertical movement or not
player1_Rtoken[1]=player1_Rtoken[1]+193;
}
}
if(dice_val==3){
if(player1_Rtoken[0]==444||player1_Rtoken[0]==445||player1_Rtoken[0]==446||player1_Rtoken[0]==447){//check for token on vertical movement or not
player1_Rtoken[1]=player1_Rtoken[1]+145;
}
}
if(dice_val==2){
if(player1_Rtoken[0]==444||player1_Rtoken[0]==445||player1_Rtoken[0]==446||player1_Rtoken[0]==447){//check for token on vertical movement or not
player1_Rtoken[1]=player1_Rtoken[1]+97;
}
}
if(dice_val==1){

if(player1_Rtoken[0]==445){//check for token on vertical movement or not
player1_Rtoken[1]=player1_Rtoken[1]+50;
}
}
}
break;



case 2:

break;

case 3:

break;

 case 4:
 if(plr4_start==1){
if(dice_val==6){
count_six++;
if(count_six==3){
player_turn=1;
}
else if(count_six<3){
count_six=0;
player4_Gtoken[0]=809;
player4_Gtoken[1]=322;
plr4_start++;
}
}
}

else if (plr4_start>1){
if(dice_val==5){

}
if(dice_val==4){
if(player4_Gtoken[1]==322||player4_Gtoken[1]==323||player4_Gtoken[1]==324||player4_Gtoken[1]==325){//check for token on vertical movement or not
player4_Gtoken[0]=player4_Gtoken[0]-193;
}
}
if(dice_val==3){
if(player4_Gtoken[1]==322||player4_Gtoken[1]==323||player4_Gtoken[1]==324||player4_Gtoken[1]==325){//check for token on vertical movement or not
player4_Gtoken[0]=player4_Gtoken[0]-145;
}
}

if(dice_val==2){
if(player4_Gtoken[1]==322||player4_Gtoken[1]==323||player4_Gtoken[1]==324||player4_Gtoken[1]==325){//check for token on vertical movement or not
player4_Gtoken[0]=player4_Gtoken[0]-97;
}
}
if(dice_val==1){

if(player4_Gtoken[1]==322||player4_Gtoken[1]==323||player4_Gtoken[1]==324||player4_Gtoken[1]==325){//check for token on vertical movement or not
player4_Gtoken[0]=player4_Gtoken[0]-50;
}
}
}

 break;

}
count_six=0;
player_turn++;
if(player_turn==4){
player_turn=1;
}
	glutSwapBuffers(); // do not modify this line..

}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...


	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32) {//press space for generating the random number
		dice_val=(rand()%6)+1;
		
		

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1250, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
//MENU
int choice;
string array_name[10];
const int SIZE = 10;

  string names[SIZE] = {"Parker", "Wesley", "Weston", "Damian", "George",
                        "Jasper", "Ashton", "Waylon", "Brooks", "Carlos"};
  string scores[SIZE] = {"200", "80", "70", "65", "87", "95", "78",
                        "43", "73", "50"};

cout<<"(1)START Ludo"<<endl<<"(2)View LEADER BOARD"<<endl<<"(3)EXIT"<<endl<<endl<<"Enter your choice: ";
cin>>choice;
switch(choice){
case 1:
cout<<"Enter the number of players: "<<endl;
cin>>noof_players;

for(int i=0;i<noof_players;i++){
cout<<endl<<"Enter name of player "<<i+1<<" : "<<endl;
cin>>array_name[i];
}


glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

glutMainLoop();

break;

case 2:
{
ofstream out_file("highscore.txt");
  string str1 = "*****Leaderboard Table*****",
         str2 = "Names",
         str3 = "Scores";

  out_file<<setw(55)<<"\n\n"<<str1<<"\n\n\n"<<setw(30)<<str2<<setw(27)<<str3<<"\n\n";

  for(int i=0;i<SIZE;i++){
    out_file<<names[i]<<setw(10)<<scores[i];
  }

  ifstream in_file;
  in_file.open("highscore.txt");

  cout<<"\n\n"<<setw(55)<<str1<<"\n\n\n"<<setw(30)<<str2<<setw(27)<<str3<<"\n\n";

  for(int i=0;i<SIZE;i++){
    in_file>>names[i]>>scores[i];
    cout<<setw(29)<<names[i]<<setw(27)<<scores[i]<<endl;
  }
  }
break;

case 3:
exit(1);
break;
 }
	
	

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	
	return 1;
}
#endif /* AsteroidS_CPP_ */
