
#include "iGraphics.h"
#include "bitmap_loader.h"



int cx=30,cy=150;
int flag=0,f=1;
int image1,image2,image3;
int x = 300, y = 300, r = 20;
int win_b = 400, win_l = 400;
float delay = 0;
int speed = 0;
int counter =0;
/*
 function iDraw() is called again and again by the system.

 */
void drawRoadLines(int offset)
{
	int len = 10;
	int width = 5;
	int gap = 10;
	int midx = 0, midy = win_l / 2;
	for (int i = 0; i < win_b / (len + gap); i++)
		iFilledRectangle((i * (len + gap) + offset) % win_b, midy, len, width);
}
int k = 0;







void mainMenu(){



	iShowImage(0,0,1024,576,image1);    //Home Background

	


	iSetColor(255,255,255);
	iFilledRectangle(440,278,115,40);   //START


	


	iSetColor(255,255,255);
	iFilledRectangle(147.5,278,115,40);  //EXIT



	iSetColor(255,255,255);
	iFilledRectangle(732.5,278,115,40);  //SCORE



	iSetColor(0,0,0);
	iText(460,288,"START", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(177.5,288,"EXIT", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(752.5,288,"SCORE", GLUT_BITMAP_TIMES_ROMAN_24);




}


void startingLevel(){


iShowImage(0,0,1024,576,image2);  //sky background

iSetColor(128,128,128);
iFilledRectangle(0,100,1024,30);
iSetColor(255,0,0);
iFilledCircle(cx,cy,20,900);   //life
iFilledCircle(20,555,10,900);  //life
iFilledCircle(45,555,10,900);  //life
iFilledCircle(70,555,10,900);  //life
iFilledCircle(95,555,10,900);  //life
iFilledCircle(120,555,10,900);  //life


iText(824,555,"SCORE : ",GLUT_BITMAP_9_BY_15);




}


void scorePage(){


	iSetColor(0,0,0);
	iFilledRectangle(0,0,1024,576);







}












void iDraw()
{
	//place your drawing codes here
	iClear();
	

	mainMenu();

	if(flag==1){
		startingLevel();
	}

	/*if(f==1){

		scorePage();
	}*/

}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>=440 && mx<=555 && my>=278 && my<=318)   //Gameplay
			flag=1;



		//if(mx>=732.5 && mx<=847.5 && my>=278 && my<=318)
			//f=1;




		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	else if (key == 'a' && speed < 5)
		speed += 1;
	else if (key == 's' && speed > 0)
		speed -= 1;
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.


	iInitialize(1024,576, "Demo");
	image1=iLoadImage("mainMenu.jpg");
	image2=iLoadImage("SKY.jpg");

	iStart(); // it will start drawing

	return 0;
}

