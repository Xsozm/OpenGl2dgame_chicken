#include <iostream>
#include <iomanip>
//#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <vector>


using namespace std;

enum EnemyMove {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum EnemySpawnMove {
	FORWARD,BACKWARD,NOMOVE
};

class Defender {
public:
	float x;
	float y;
	float xTrans;
	float yTrans;

	Defender(float intialX,float intialY) {
		x = intialX;
		y = intialY;
	}
public:
	void draw() {
		glBegin(GL_QUADS);
	}
};

class Player;
void  drawCircle(float radiusX, float radiusY, float x, float y, bool changeColor, int limDeg);
void  drawCircleFilled(float radiusX, float radiusY, float x, float y, bool changeColor, int limDeg);
void Anim(void);
void update_scene(int val);
void createFire(int value);
int p0[2];
int p1[2];
int p2[2];
int p3[2];
int p10[2];
int p11[2];
int p12[2];
int p13[2];
int* p;
int* secondp;
float t = 0;
float bezierT = 0;
float xTest = 0;
float yTest = 0;
float test = 0;
bool pauseGame = false;
bool* keyStates = new bool[256];
float rotation = 0;
int EnemeyTransX = 0;
int EnemeyTransY = 0;
int numOfEggs = 0;



class Enemy {
public: float x;
public: float y;
public:float transX;
public:float transY;
public: float intialXPos;
public: float intialYPos;
public: int hp;
public: float xMin;
public: float xMax;
public: float yMin;
public: float yMax;
public: float width;
public: float height;
public: bool isVisible;
public: int hpDuplication;
		EnemyMove direct;
		EnemySpawnMove spawnDirect;
		Enemy(float intialX, float intialY, float widthIn, float heightIn) {
			intialXPos = intialX;
			intialYPos = intialY;
			transX = 0;
			transY = 0;
			x = intialX;
			y = intialY;
			hp = 100;
			hpDuplication = 2;
			width = widthIn;
			height = heightIn;
			xMax = intialX + widthIn;
			xMin = intialX - widthIn;
			yMax = intialY + heightIn;
			yMin = intialY - heightIn;
			isVisible = true;
			spawnDirect = NOMOVE;
		}
public:
void updatePos(float xValue, float yValue) {
	if (y >= intialYPos + yValue) {
		direct = DOWN;
	}
	else {
		direct = UP;
	}
	transX =  xValue;
	x = intialXPos + xValue;
	transY =  yValue;
	y = intialYPos + yValue;
	xMax = x + width;
	xMin = x - width;
	yMax = y + height;
	yMin = y - height;
}

void moveBackwardSpawning(float yValue) {
		transY = transY + yValue;
		y = y + yValue;
		//if (y >= 1100.f) {
		//	hp = hp*hpDuplication;
		//}


}

void moveForward(float yValue) {
	hp = 200;
	transX = 0;
	transY = transY - yValue;
	y = y - yValue;
	printf("hp %d \n", hp);
}

void draw() {
	if (isVisible) {
		glPushMatrix();
		//p = bezier(0.002, p0, p1, p2, p3);
		glTranslated(transX, transY, 0);
		//printf(p[0] + "");
		glColor3f(1, 1, 1);
		drawCircle(100, 100, 500, 780, false, 180); //body
		glColor3f(0.184314, 0.4, 0.18);
		drawCircle(100, 100, 500, 780, true, -180); //body

		glColor3f(1.0f, 1.0f, 1.0f);
		drawCircle(40, 25, 500, 900, false, 360);
		drawCircle(30, 40, 500, 920, false, 360);
		glPushMatrix();

		glTranslated(500, 950, 0);
		glRotated(25, 0, 0, 1);
		glTranslated(-500, -950, 0);

		glColor3f(1.0f, 1.0f, 0);
		drawCircle(5, 12, 500, 985, false, 360); // hat end
		glPopMatrix();
		glColor3f(0.184314, 0.4, 0.18);
		drawCircle(32, 35, 500, 940, false, 180); // hat
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(500, 880, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(490, 900, 0.0f);
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(510, 900, 0.0f);
		glEnd();
		glBegin(GL_QUADS); //cloth
		glColor3f(0.184314, 0.4, 0.18);
		glVertex3f(540, 780, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(540, 874, 0.0f);
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(550, 866, 0.0f);
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(550, 780, 0.0f);
		glEnd();

		glBegin(GL_QUADS); //cloth
		glColor3f(0.184314, 0.4, 0.18);
		glVertex3f(460, 780, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(460, 874, 0.0f);
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(450, 866, 0.0f);
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(450, 780, 0.0f);
		glEnd();

		glPopMatrix();
	}

}


};

class EnemyEgg {
public: float x;
public: float y;
public:float transX;
public:float transY;
public:int dmg;
public: float intialXPos;
public: float intialYPos;
	   EnemyEgg(float intialX,float intialY) {
		   intialXPos = intialX;
		   intialYPos = intialY;
		   transX = 0;
		   transY = 0;
		   x = 0;
		   y = 0;
	   }
public:void updatePos(float xValue,float yValue) {
	transX = transX + xValue;
	x = x + xValue;
	transY = transY + yValue;
	y = y + yValue;
}
public:void updatexPos(float xIn) {
	transX = xIn;
	x = intialXPos + transX;
}
public:void resetPos() {
	transX = 0;
	transY = 0;
	//x = intialXPos;
	y = intialYPos;
}
	   void draw() {
		   glPushMatrix();
		   glTranslated(transX, transY, 0);
		   //glTranslated(0, ballTranslate, 0);
		   glColor3f(1, 1, 1);
		   drawCircle(10, 10, 500, 900, false, 360);//egg
		   glPopMatrix();
	   }
};

class Fire {
public: float x;
public: float y;
public: float xTransPos;
public: float yTransPos;
public: float dmg;
public: int index;
		Fire(int indexIn,float yIntial, float xIntial) {
			index = indexIn;
			xTransPos = 0;
			yTransPos = 0;
			x = xIntial;
			y = yIntial;
			dmg = 10;
		}
public:void updateyPos(float yVal) {
	yTransPos = yTransPos + yVal;
	y = y + yVal;

}
public: void updatexPos(float value) {
	xTransPos = xTransPos + value;
	x = x + value;
}
};

class Player {
public: float xTransPos;
public: float x;
public: float y;
public:float width;
public: float height;
public: std::vector<Fire> fires;
public:int sizeOfFire;
public:bool firing = false;
	 Player(float xIntial,float yIntial,float widthIn,float height) {
				 xTransPos = 0;
				 x = xIntial;
				 width = widthIn;
				 y = yIntial;
				 sizeOfFire = 0;

			 }

public: float getxTransPos() {
				 return xTransPos;
	}
public: float getxPos() {
	return x;
}
public: void updatexPos(float value) {
				xTransPos = xTransPos + value;
				x = x + value;
			 }
		void draw() {
			glPushMatrix();
			glColor3f(1, 1, 0);
			glTranslated(xTransPos, 0, 0);
			glTranslated(500, 10, 0);
			glRotated(rotation, 0, 0, 1);
			glTranslated(-500, -10, 0);
			drawCircle(10, 10, 500, 180, false, 360);
			glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(570, 140, 0.0f);
			//glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(500, 210, 0.0f);
			//glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(500, 180, 0.0f);
			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(430, 140, 0.0f);
			//glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(500, 210, 0.0f);
			//glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(500, 180, 0.0f);
			glEnd();
			glPopMatrix();
		}
		void drawFires() {
			for (int i = 0; i < sizeOfFire; i++) {
				glPushMatrix();
				glTranslatef(0, fires.at(i).yTransPos, 0);
				glColor3f(1, 1, 1);
				drawCircle(10, 10, fires.at(i).x, 200, false, 360);//egg
				glPopMatrix();
				glEnd();
				/*
				glPushMatrix();
				glTranslatef(0, player.fires.at(i).yTransPos, 0);
				glColor3f(1, 1, 1);
				drawCircle(10, 10, player.fires.at(i).x -20, 200, false, 360);//egg
				glPopMatrix();
				glEnd();
				*/

			}
		}
};
Player player(500.f,210.f,70.f,0);
EnemyEgg egg(500.f, 900.f);
Enemy enemy(500.f,780.f,100.f,100.f);

int* bezier(float t, int* p0, int* p1, int* p2, int* p3)
{
	int res[2];
	res[0] = pow((1 - t), 3)*p0[0] + 3 * t*pow((1 - t), 2)*p1[0] + 3 * pow(t, 2)*(1 - t)*p2[0] + pow(t, 3)*p3[0];
	res[1] = pow((1 - t), 3)*p0[1] + 3 * t*pow((1 - t), 2)*p1[1] + 3 * pow(t, 2)*(1 - t)*p2[1] + pow(t, 3)*p3[1];
	return res;
}

int* bezier2P(float t, float x , float y) {
	int res[2];
	res[0] = pow((1 - t), 3)*x;
	res[1] = pow((1 - t), 3)*y;
	return res;
}


void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	player.drawFires();
	player.draw();
	egg.draw();
	enemy.draw();
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslated(enemy.transX, enemy.transY, 0);
	drawCircleFilled(120,120,500,780,false,180);
	glPopMatrix();

	for (int i = 0; i < enemy.hp / 10;i++) {
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3d((i*55)+200, 950, 0);
	glVertex3d((i * 55) + 200, 970, 0);
	glVertex3d((i * 55) + 250, 970, 0);
	glVertex3d((i * 55) + 250, 950, 0);
	glEnd();
	}

	/*
	glPushMatrix();
	glTranslated(xTest,yTest,0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3d( + 200, 950, 0);
	glVertex3d( + 200, 970, 0);
	glVertex3d( + 250, 970, 0);
	glVertex3d( + 250, 950, 0);
	glEnd();
	glPopMatrix();
	*/




	glFlush();

}

const float DEG2RAD = 3.14159 / 180;

void drawCircle(float radiusX,float radiusY, float x, float y,bool changeColor, int limDeg)
{
	glBegin(GL_POLYGON);
	for (int i = 0; limDeg<0 ? i >= limDeg:i<=limDeg; limDeg<0?i--:i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex3f(cos(degInRad)*radiusX +x  , sin(degInRad)*radiusY +y,0 );
	}

	glEnd();
}

void drawCircleFilled(float radiusX, float radiusY, float x, float y, bool changeColor, int limDeg)
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; limDeg<0 ? i >= limDeg : i <= limDeg; limDeg<0 ? i-- : i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex3f(cos(degInRad)*radiusX + x, sin(degInRad)*radiusY + y, 0);
	}

	glEnd();
}

bool isColliding(Fire fire, Enemy enemy) {
	//printf("enemy x %g %g \n", enemy.xMax, enemy.xMin);
	//printf("enemy y %g %g \n", enemy.yMax, enemy.yMin);
	//printf("fire x %g y %g \n", fire.x, fire.y);
	if ((enemy.xMax>= fire.x && enemy.xMin <= fire.x) && (enemy.yMax >= fire.y && enemy.yMin <= fire.y)) {
		return true;
	}
	return false;
}

void checkInput() {
		if (keyStates['a'] == true) {
			player.updatexPos(-0.0001);
			rotation = 25;
		}
		if (keyStates['d'] == true) {
			player.updatexPos(0.0001);

			rotation = -25;
		}
		if (keyStates['q'] == true) {
			player.firing = true;

		}
		egg.updatePos(0, -0.0001);
		if (egg.y <= 100.f) {
			//ballTranslate = 0;
			egg.resetPos();
			egg.updatexPos(enemy.transX);
		}
		if (keyStates['r'] == true) {
			pauseGame = !pauseGame;
		}

}

void Anim()
{
	if ((egg.x <= player.x + player.width && egg.x >= player.x - player.width) && egg.y <= player.y) {
		egg.resetPos();
		egg.updatexPos(enemy.transX);

		//printf("ball x:%g y:%g \n", EnemyPosX, ballyPos);
		//printf("collid \n");
		//printf("player x:%g y:%g \n", player.x, player.y);
	}









	//float r = static_cast <float> (rand()) / static_cast <float> (1);




	//numOfEggs = rand() % 3;
	if (!pauseGame) {
		checkInput();
		xTest = player.xTransPos-0.001 ;

		t += 0.00000003;
		bezierT+= 0.00000003;

		if (t >= 1) {
			t = 0;
			enemy.x = enemy.intialXPos;
			enemy.y = enemy.intialYPos;

			/*
			p0[0] = rand() % -200;
			p0[1] = rand() % -50;

			p1[0] = rand() % 200;
			p1[1] = rand() % 50;

			p2[0] = rand() % 300;
			p2[1] = rand() % -70;

			p3[0] = rand() % 80;
			p3[1] = 9;
			*/

		}

		//p = bezier(t, p0, p1, p2, p3);
		//std::cout << p[0];
		//printf("\n");
		//glutPostRedisplay();

		//glVertex3f(p[0], p[1], 0);



	//for (ballPos = 0; ballPos < 150; ballPos++) {}

	//glutPostRedisplay();

	}
	//glutPostRedisplay();
}


void tasten(unsigned char key, int xmouse, int ymouse)
{
	keyStates[key] = true;
   glutPostRedisplay();
}

void keyUp(unsigned char key, int xmouse, int ymouse) {
	keyStates[key] = false;
	if (!keyStates['a']) {
		rotation = 0;
	}
	if (!keyStates['d']) {
		rotation = 0;
	}
	if (!keyStates['q']) {
		player.firing = false;
	}
}


void damageEnemy(Enemy &enemy,int dmg) {
	int &hp = enemy.hp;
	if (hp>0) {
		hp = hp - dmg;
	}
	printf("%d \n",enemy.hp);
}

void checkFires() {
	for (int i = 0; i < player.sizeOfFire; i++) {
		player.fires.at(i).updateyPos(20.f);
		if (isColliding(player.fires.at(i), enemy)) {
			damageEnemy(enemy, player.fires.at(i).dmg);
			player.fires.erase(player.fires.begin() + i);
			player.sizeOfFire--;
		}
		else if (player.fires.at(i).y >= 950) {
			player.fires.erase(player.fires.begin() + i);
			player.sizeOfFire--;
		}
	}
}



void update_scene(int val) {
	checkFires();




	//printf("%d \n",player.sizeOfFire);
	//printf("%g \n",egg.y);
	//std::cout << p[0];
	/*p0[0] = rand() % 100;
	p0[1] = rand() % 100;

	p1[0] = rand() % 100;
	p1[1] = rand() % 500;

	p2[0] = rand() % 500;
	p2[1] = rand() % 500;

	p3[0] = rand() % 500;
	p3[1] = 100;
	//glutTimerFunc(1000, update_scene, 0);*/
	//printf("%g\n", player.x);
	glutPostRedisplay();
	glutTimerFunc(30, update_scene, 0);


}

void spawnNewEnemy() {

}

void spawningTimer(int val) {

}

void updateEnemyPos(int val) {
	//printf("yes %d \n", enemy.direct);
	if (!pauseGame) {

		//secondp = bezier2P(t,1500,1600);
		//yTest = egg.transY - 100;
		//printf("%d \n",xTest);

		//printf("%g \n", enemy.y);

		//EnemeyTransX = p[0];
		//EnemeyTransY = p[1];
		if (enemy.hp == 0 && enemy.spawnDirect != BACKWARD) {

			enemy.spawnDirect = BACKWARD;

		}
		else if(enemy.y>=1100.f ){

			enemy.spawnDirect = FORWARD;
		}
		else if (enemy.y <= 700.f  && 	enemy.spawnDirect == FORWARD) {
			enemy.spawnDirect = NOMOVE;
		}
		if (enemy.spawnDirect== BACKWARD) {
			enemy.moveBackwardSpawning(5.f);
		}
		else if (enemy.spawnDirect==FORWARD) {
			enemy.moveForward(5.f);

		}
		else if (enemy.spawnDirect == NOMOVE) {
		p = bezier(t, p0, p1, p2, p3);
		enemy.updatePos(p[0], p[1]);
		}





		//EnemyPosX = EnemeyTransX + 500.f;
		//printf("ball x:%g y:%g \n", egg.x, egg.y);
		//printf("vs \n");
		//printf("player xMin:%g xMax:%g y:%g \n", player.x- player.width, player.x + player.width, player.y);

		glutPostRedisplay();

	}
	glutTimerFunc(40, updateEnemyPos, 0);
}

void updateEnemyPoints(int val) {


	/*
	p0[0] = rand() % -200;
	p0[1] = rand() % -50;

	p1[0] = rand() % 200;
	p1[1] = rand() % 50;

	p2[0] = rand() % 300;
	p2[1] = rand() % -70;

	p3[0] = rand() % 80;
	p3[1] = 9;
	*/

	glutPostRedisplay();
	glutTimerFunc(3000, updateEnemyPoints, 0);

}


void createFire(int val) {

	if (player.firing) {
		//if (player.sizeOfFire < 5) {
			player.fires.push_back(Fire(player.sizeOfFire,200.f,player.x));
			//player.fires.push_back(Fire(player.sizeOfFire, 200.f, player.x));
			player.sizeOfFire +=1;
			glutTimerFunc(500, createFire, 0);

		//}

		//printf("%d \n", player.sizeOfFire);
	}
	else {
		glutTimerFunc(5, createFire, 0);
	}


}




int main(int argc, char** argr) {
	p0[0] = -200;
	p0[1] = -50;

	p1[0] = 200;
	p1[1] = 50;

	p2[0] = 300;
	p2[1] = -70;

	p3[0] = 80;
	p3[1] = 9;

	glutInit(&argc, argr);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(500, 0);
	glutCreateWindow("Test");
	glutKeyboardFunc(tasten);
	glutKeyboardUpFunc(keyUp);
	glutDisplayFunc(Display);
	glutIdleFunc(Anim);
	glutTimerFunc(0, updateEnemyPos, 0);
	glutTimerFunc(0,update_scene,0);
	glutTimerFunc(0, createFire, 0);
	//glutTimerFunc(3000, updateEnemyPoints, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 1000, 0.0, 1000);

	glutMainLoop();
  return -1;
}
//2403
