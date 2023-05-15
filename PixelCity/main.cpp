#include <bits/stdc++.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<windows.h>
#include<cstdio>
using namespace std;

bool dayNight = true;
void setColor(string col){
    //day
    if(dayNight){
        if(col == "orange") glColor3ub (215, 146, 145);
        else if(col == "white") glColor3ub (226, 225, 226);
        else if(col == "cloud") glColor3ub (180, 188, 193);
        else if(col == "tree") glColor3ub (85, 87, 116);
        else if(col == "darkGray") glColor3ub (61, 69, 82);
        else if(col == "bird") glColor3ub (146, 168, 174);
        else if(col == "lightBuilding") glColor3ub (208, 209, 210);
        else if(col == "midBuilding") glColor3ub (180, 188, 193);
        else if(col == "frontBuilding") glColor3ub (100, 116, 127);
        else if(col == "iceBlue") glColor3ub (149, 168, 172);
        else if(col == "pink") glColor3ub (211, 163, 181);
        else if(col == "reflectionDark") glColor3ub (103, 121, 134);
        else if(col == "reflectionLight") glColor3ub (151, 168, 175);
        else if(col == "trainBody") glColor3ub (102, 121, 134);
        else if(col == "trainGlass") glColor3ub (146, 168, 175);
        else if(col == "trainStripeLight") glColor3ub (148, 167, 176);
        else if(col == "trainStripeDark") glColor3ub (106, 120, 133);
        else if(col == "background") glColor3ub (215, 216, 215);
        else if(col == "birdFace") glColor3ub (178, 199, 212);
        else if(col == "light") glColor3ub (255, 254, 211);
        else if(col == "sun") glColor3ub (215, 146, 145);
        else{
            cout<<"INVALID COLOR CODE: "<<col<<"\n";
            glColor3ub (0,0,0);
        }

    }
    //night
    else{


        if(col == "orange") glColor3ub (111, 100, 116);
        else if(col == "white") glColor3ub (91, 157, 169);
        else if(col == "cloud") glColor3ub (79, 132, 150);
        else if(col == "tree") glColor3ub (53, 57, 102);
        else if(col == "darkGray") glColor3ub (46, 46, 82);
        else if(col == "bird") glColor3ub (65, 117, 139);
        else if(col == "lightBuilding") glColor3ub (88, 146, 158);
        else if(col == "midBuilding") glColor3ub (79, 132, 150);
        else if(col == "frontBuilding") glColor3ub (52, 82, 110);
        else if(col == "iceBlue") glColor3ub (64, 120, 137);
        else if(col == "pink") glColor3ub (105, 110, 139);
        else if(col == "reflectionDark") glColor3ub (54, 83, 113);
        else if(col == "reflectionLight") glColor3ub (72, 116, 141);
        else if(col == "trainBody") glColor3ub (53, 84, 115);
        else if(col == "trainGlass") glColor3ub (65, 117, 139);
        else if(col == "trainStripeLight") glColor3ub (67, 117, 140);
        else if(col == "trainStripeDark") glColor3ub (55, 78, 110);
        else if(col == "background") glColor3ub (90, 152, 163);
        else if(col == "birdFace") glColor3ub (66, 138, 153);
        else if(col == "light") glColor3ub (255, 254, 211);
        else if(col == "sun") glColor3ub (199, 198, 167);
        else{
            cout<<"INVALID COLOR CODE: "<<col<<"\n";
            glColor3ub (0,0,0);
        }
    }
}

//animate train
int trainSpeed = 0;
int trainPosition = 1400;

//animate reflection
float evenReflectionChange = 0.1;
float evenReflectionPosition = 0;

float oddReflectionChange = -0.1;
float oddReflectionPosition = 0;

//animate clouds
float smallCloudChange = 1;
float smallCloudPosition = 0;

float bigCloud1Change = 0.2;
float bigCloud1Position = 0;

float bigCloud2Change = 0.15;
float bigCloud2Position = 0;

//animate boats
float boat1Change = 0.5;
float boat1Position = 0;

void drawBackground(){
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,720);
    glVertex2i(0,720);
    glEnd();
}

void drawWater(){

    setColor("reflectionLight");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,45);
    glVertex2i(0,45);
    glEnd();
}

void drawTrain(){

    glPushMatrix();
    glTranslatef(trainPosition,0, 0);
    //start of color and drawing

    //main body
    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(440,170);
    glVertex2i(440,210);
    glVertex2i(0,210);
    glEnd();

    //upperLine main body
    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(5,210);
    glVertex2i(435,210);
    glVertex2i(435,215);
    glVertex2i(5,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(5,210);
    glVertex2i(35,210);
    glVertex2i(35,215);
    glVertex2i(5,215);
    glEnd();



    //face
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(40,170);
    glVertex2i(40,205);
    glVertex2i(0,205);
    glEnd();

    //face stripe
    setColor("trainStripeDark");
    glBegin(GL_QUADS);
    glVertex2i(0,175);
    glVertex2i(40,175);
    glVertex2i(40,180);
    glVertex2i(0,180);
    glEnd();


    //lights
    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(5,175);
    glVertex2i(10,175);
    glVertex2i(10,185);
    glVertex2i(5,185);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(30,175);
    glVertex2i(35,175);
    glVertex2i(35,185);
    glVertex2i(30,185);
    glEnd();

    //frontWindow
    setColor("trainGlass");
    glBegin(GL_QUADS);
    glVertex2i(5,190);
    glVertex2i(35,190);
    glVertex2i(35,205);
    glVertex2i(5,205);
    glEnd();

    //long stripes
    //up
    setColor("trainStripeLight");
    glBegin(GL_QUADS);
    glVertex2i(40,205);
    glVertex2i(440,205);
    glVertex2i(440,210);
    glVertex2i(40,210);
    glEnd();


    //down
    setColor("trainStripeLight");
    glBegin(GL_QUADS);
    glVertex2i(40,175);
    glVertex2i(65,175);
    glVertex2i(65,180);
    glVertex2i(40,180);
    glEnd();

    setColor("trainStripeLight");
    glBegin(GL_QUADS);
    glVertex2i(100,175);
    glVertex2i(200,175);
    glVertex2i(200,180);
    glVertex2i(100,180);
    glEnd();

    setColor("trainStripeLight");
    glBegin(GL_QUADS);
    glVertex2i(235,175);
    glVertex2i(335,175);
    glVertex2i(335,180);
    glVertex2i(235,180);
    glEnd();

    setColor("trainStripeLight");
    glBegin(GL_QUADS);
    glVertex2i(370,175);
    glVertex2i(440,175);
    glVertex2i(440,180);
    glVertex2i(370,180);
    glEnd();



    //train windows and door component(1)
    //window
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(55,185);
    glVertex2i(65,185);
    glVertex2i(65,200);
    glVertex2i(55,200);
    glEnd();

    //doors
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(70,170);
    glVertex2i(80,170);
    glVertex2i(80,200);
    glVertex2i(70,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(85,170);
    glVertex2i(95,170);
    glVertex2i(95,200);
    glVertex2i(85,200);
    glEnd();
    //end doors

    //more windows
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(100,185);
    glVertex2i(110,185);
    glVertex2i(110,200);
    glVertex2i(100,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(115,185);
    glVertex2i(125,185);
    glVertex2i(125,200);
    glVertex2i(115,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(130,185);
    glVertex2i(140,185);
    glVertex2i(140,200);
    glVertex2i(130,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(145,185);
    glVertex2i(155,185);
    glVertex2i(155,200);
    glVertex2i(145,200);
    glEnd();
    //end of window + doors component(1)

    //train windows and door component(2)
    //window
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(185,185);
    glVertex2i(195,185);
    glVertex2i(195,200);
    glVertex2i(185,200);
    glEnd();

    //doors
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(200,170);
    glVertex2i(210,170);
    glVertex2i(210,200);
    glVertex2i(200,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(215,170);
    glVertex2i(225,170);
    glVertex2i(225,200);
    glVertex2i(215,200);
    glEnd();
    //end doors

    //more windows
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(230,185);
    glVertex2i(240,185);
    glVertex2i(240,200);
    glVertex2i(230,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(245,185);
    glVertex2i(255,185);
    glVertex2i(255,200);
    glVertex2i(245,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(260,185);
    glVertex2i(270,185);
    glVertex2i(270,200);
    glVertex2i(260,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(275,185);
    glVertex2i(285,185);
    glVertex2i(285,200);
    glVertex2i(275,200);
    glEnd();
    //end of window + doors component(2)

    //train windows and door component(3)
    //window
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(325,185);
    glVertex2i(335,185);
    glVertex2i(335,200);
    glVertex2i(325,200);
    glEnd();

    //doors
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(340,170);
    glVertex2i(350,170);
    glVertex2i(350,200);
    glVertex2i(340,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(355,170);
    glVertex2i(365,170);
    glVertex2i(365,200);
    glVertex2i(355,200);
    glEnd();
    //end doors

    //more windows
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(370,185);
    glVertex2i(380,185);
    glVertex2i(380,200);
    glVertex2i(370,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(385,185);
    glVertex2i(395,185);
    glVertex2i(395,200);
    glVertex2i(385,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(400,185);
    glVertex2i(410,185);
    glVertex2i(410,200);
    glVertex2i(400,200);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(415,185);
    glVertex2i(425,185);
    glVertex2i(425,200);
    glVertex2i(415,200);
    glEnd();
    //end of window + doors component(3)


    //end of color and drawing
    glPopMatrix();
}


void drawBridge(){


    //upper
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,155);
    glVertex2i(1280,155);
    glVertex2i(1280,170);
    glVertex2i(0,170);
    glEnd();
    //dark line
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0,150);
    glVertex2i(1280,150);
    glVertex2i(1280,155);
    glVertex2i(0,155);
    glEnd();

    //lower
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,135);
    glVertex2i(1280,135);
    glVertex2i(1280,150);
    glVertex2i(0,150);
    glEnd();


    //lamps
    //1
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(210+10,135);
    glVertex2i(215+10,135);
    glVertex2i(215+10,150);
    glVertex2i(210+10,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(220+10,135);
    glVertex2i(225+10,135);
    glVertex2i(225+10,150);
    glVertex2i(220+10,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(215+10,165);
    glVertex2i(220+10,165);
    glVertex2i(220+10,215);
    glVertex2i(215+10,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(215+10,165);
    glVertex2i(220+10,165);
    glVertex2i(220+10,215);
    glVertex2i(215+10,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(200+10,210);
    glVertex2i(215+10,210);
    glVertex2i(215+10,215);
    glVertex2i(200+10,215);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(200+10,200);
    glVertex2i(215+10,200);
    glVertex2i(215+10,210);
    glVertex2i(200+10,210);
    glEnd();
    //1

    //2
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(400,135);
    glVertex2i(405,135);
    glVertex2i(405,150);
    glVertex2i(400,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(410,135);
    glVertex2i(415,135);
    glVertex2i(415,150);
    glVertex2i(410,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(405,165);
    glVertex2i(410,165);
    glVertex2i(410,215);
    glVertex2i(405,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(405,165);
    glVertex2i(410,165);
    glVertex2i(410,215);
    glVertex2i(405,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(390,210);
    glVertex2i(405,210);
    glVertex2i(405,215);
    glVertex2i(390,215);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(390,200);
    glVertex2i(405,200);
    glVertex2i(405,210);
    glVertex2i(390,210);
    glEnd();
    //2

    //3
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(590,135);
    glVertex2i(595,135);
    glVertex2i(595,150);
    glVertex2i(590,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(600,135);
    glVertex2i(605,135);
    glVertex2i(605,150);
    glVertex2i(600,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(595,165);
    glVertex2i(600,165);
    glVertex2i(600,215);
    glVertex2i(595,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(595,165);
    glVertex2i(600,165);
    glVertex2i(600,215);
    glVertex2i(595,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(580,210);
    glVertex2i(595,210);
    glVertex2i(595,215);
    glVertex2i(580,215);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(580,200);
    glVertex2i(595,200);
    glVertex2i(595,210);
    glVertex2i(580,210);
    glEnd();
    //3

    //4
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(780,135);
    glVertex2i(785,135);
    glVertex2i(785,150);
    glVertex2i(780,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(790,135);
    glVertex2i(795,135);
    glVertex2i(795,150);
    glVertex2i(790,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(785,165);
    glVertex2i(790,165);
    glVertex2i(790,215);
    glVertex2i(785,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(785,165);
    glVertex2i(790,165);
    glVertex2i(790,215);
    glVertex2i(785,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(770,210);
    glVertex2i(785,210);
    glVertex2i(785,215);
    glVertex2i(770,215);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(770,200);
    glVertex2i(785,200);
    glVertex2i(785,210);
    glVertex2i(770,210);
    glEnd();
    //4

    //5
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(970,135);
    glVertex2i(975,135);
    glVertex2i(975,150);
    glVertex2i(970,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(980,135);
    glVertex2i(985,135);
    glVertex2i(985,150);
    glVertex2i(980,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(975,165);
    glVertex2i(980,165);
    glVertex2i(980,215);
    glVertex2i(975,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(975,165);
    glVertex2i(980,165);
    glVertex2i(980,215);
    glVertex2i(975,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(960,210);
    glVertex2i(975,210);
    glVertex2i(975,215);
    glVertex2i(960,215);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(960,200);
    glVertex2i(975,200);
    glVertex2i(975,210);
    glVertex2i(960,210);
    glEnd();
    //5

    //6
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1160,135);
    glVertex2i(1165,135);
    glVertex2i(1165,150);
    glVertex2i(1160,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1170,135);
    glVertex2i(1175,135);
    glVertex2i(1175,150);
    glVertex2i(1170,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1165,165);
    glVertex2i(1170,165);
    glVertex2i(1170,215);
    glVertex2i(1165,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1165,165);
    glVertex2i(1170,165);
    glVertex2i(1170,215);
    glVertex2i(1165,215);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1150,210);
    glVertex2i(1165,210);
    glVertex2i(1165,215);
    glVertex2i(1150,215);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(1150,200);
    glVertex2i(1165,200);
    glVertex2i(1165,210);
    glVertex2i(1150,210);
    glEnd();
    //6
    //end of lamps

    //bridge fence
    //(1)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1155,165);
    glVertex2i(1160,165);
    glVertex2i(1160,180);
    glVertex2i(1155,180);
    glEnd();
    //(2)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1140,165);
    glVertex2i(1145,165);
    glVertex2i(1145,180);
    glVertex2i(1140,180);
    glEnd();
    //(3)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1125,165);
    glVertex2i(1130,165);
    glVertex2i(1130,180);
    glVertex2i(1125,180);
    glEnd();
    //(4)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1110,165);
    glVertex2i(1115,165);
    glVertex2i(1115,180);
    glVertex2i(1110,180);
    glEnd();

    //(5)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,165);
    glVertex2i(1100,165);
    glVertex2i(1100,180);
    glVertex2i(1095,180);
    glEnd();

    //(6)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1080,165);
    glVertex2i(1085,165);
    glVertex2i(1085,180);
    glVertex2i(1080,180);
    glEnd();
    //(7)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1065,165);
    glVertex2i(1070,165);
    glVertex2i(1070,180);
    glVertex2i(1065,180);
    glEnd();

    //(8)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1050,165);
    glVertex2i(1055,165);
    glVertex2i(1055,180);
    glVertex2i(1050,180);
    glEnd();

    //(9)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1035,165);
    glVertex2i(1040,165);
    glVertex2i(1040,180);
    glVertex2i(1035,180);
    glEnd();

    //(10)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1020,165);
    glVertex2i(1025,165);
    glVertex2i(1025,180);
    glVertex2i(1020,180);
    glEnd();
    //line
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1020,175);
    glVertex2i(1155,175);
    glVertex2i(1155,180);
    glVertex2i(1020,180);
    glEnd();
    //2nd fence
    //(1)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(965,165);
    glVertex2i(970,165);
    glVertex2i(970,180);
    glVertex2i(965,180);
    glEnd();

    //(2)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(950,165);
    glVertex2i(955,165);
    glVertex2i(955,180);
    glVertex2i(950,180);
    glEnd();

    //(3)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(935,165);
    glVertex2i(940,165);
    glVertex2i(940,180);
    glVertex2i(935,180);
    glEnd();

    //(4)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(920,165);
    glVertex2i(925,165);
    glVertex2i(925,180);
    glVertex2i(920,180);
    glEnd();

    //(5)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(905,165);
    glVertex2i(910,165);
    glVertex2i(910,180);
    glVertex2i(905,180);
    glEnd();

    //(6)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(890,165);
    glVertex2i(895,165);
    glVertex2i(895,180);
    glVertex2i(890,180);
    glEnd();

    //(7)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(875,165);
    glVertex2i(880,165);
    glVertex2i(880,180);
    glVertex2i(875,180);
    glEnd();

    //(8)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(860,165);
    glVertex2i(865,165);
    glVertex2i(865,180);
    glVertex2i(860,180);
    glEnd();

    //(9)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(845,165);
    glVertex2i(850,165);
    glVertex2i(850,180);
    glVertex2i(845,180);
    glEnd();

    //(10)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(830,165);
    glVertex2i(835,165);
    glVertex2i(835,180);
    glVertex2i(830,180);
    glEnd();

    //line
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(830,175);
    glVertex2i(965,175);
    glVertex2i(965,180);
    glVertex2i(830,180);
    glEnd();
    //bridge fence end



    //bridge pillars

    //pillar start(1)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(255,125);
    glVertex2i(345,125);
    glVertex2i(345,135);
    glVertex2i(255,135);
    glEnd();

    //left pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(255,120);
    glVertex2i(290,120);
    glVertex2i(290,135);
    glVertex2i(255,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(260,50);
    glVertex2i(285,50);
    glVertex2i(285,120);
    glVertex2i(260,120);
    glEnd();

    //right pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(325,120);
    glVertex2i(360,120);
    glVertex2i(360,135);
    glVertex2i(325,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(330,50);
    glVertex2i(355,50);
    glVertex2i(355,120);
    glVertex2i(330,120);
    glEnd();

    //mid part
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(280,110);
    glVertex2i(330,110);
    glVertex2i(330,120);
    glVertex2i(280,120);
    glEnd();
    //end of pillar(1)

    //pillar start (2)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(200+255,125);
    glVertex2i(200+345,125);
    glVertex2i(200+345,135);
    glVertex2i(200+255,135);
    glEnd();

    //left pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(200+255,120);
    glVertex2i(200+290,120);
    glVertex2i(200+290,135);
    glVertex2i(200+255,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(200+260,50);
    glVertex2i(200+285,50);
    glVertex2i(200+285,120);
    glVertex2i(200+260,120);
    glEnd();

    //right pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(200+325,120);
    glVertex2i(200+360,120);
    glVertex2i(200+360,135);
    glVertex2i(200+325,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(200+330,50);
    glVertex2i(200+355,50);
    glVertex2i(200+355,120);
    glVertex2i(200+330,120);
    glEnd();

    //mid part
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(200+280,110);
    glVertex2i(200+330,110);
    glVertex2i(200+330,120);
    glVertex2i(200+280,120);
    glEnd();
    //end of pillar(2)

    //pillar start (3)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(400+255,125);
    glVertex2i(400+345,125);
    glVertex2i(400+345,135);
    glVertex2i(400+255,135);
    glEnd();

    //left pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(400+255,120);
    glVertex2i(400+290,120);
    glVertex2i(400+290,135);
    glVertex2i(400+255,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(400+260,50);
    glVertex2i(400+285,50);
    glVertex2i(400+285,120);
    glVertex2i(400+260,120);
    glEnd();

    //right pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(400+325,120);
    glVertex2i(400+360,120);
    glVertex2i(400+360,135);
    glVertex2i(400+325,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(400+330,50);
    glVertex2i(400+355,50);
    glVertex2i(400+355,120);
    glVertex2i(400+330,120);
    glEnd();

    //mid part
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(400+280,110);
    glVertex2i(400+330,110);
    glVertex2i(400+330,120);
    glVertex2i(400+280,120);
    glEnd();
    //end of pillar(3)

    //pillar start (4)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(600+255,125);
    glVertex2i(600+345,125);
    glVertex2i(600+345,135);
    glVertex2i(600+255,135);
    glEnd();

    //left pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(600+255,120);
    glVertex2i(600+290,120);
    glVertex2i(600+290,135);
    glVertex2i(600+255,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(600+260,50);
    glVertex2i(600+285,50);
    glVertex2i(600+285,120);
    glVertex2i(600+260,120);
    glEnd();

    //right pillar
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(600+325,120);
    glVertex2i(600+360,120);
    glVertex2i(600+360,135);
    glVertex2i(600+325,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(600+330,50);
    glVertex2i(600+355,50);
    glVertex2i(600+355,120);
    glVertex2i(600+330,120);
    glEnd();

    //mid part
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(600+280,110);
    glVertex2i(600+330,110);
    glVertex2i(600+330,120);
    glVertex2i(600+280,120);
    glEnd();
    //end of pillar(4)





}


void drawBigBuilding(){


    //upper
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,135);
    glVertex2i(185,135);
    glVertex2i(185,315);
    glVertex2i(0,315);
    glEnd();

    //vertical dark line
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(15,135);
    glVertex2i(20,135);
    glVertex2i(20,315);
    glVertex2i(15,315);
    glEnd();

    //wide window

    //1
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(30,135);
    glVertex2i(60,135);
    glVertex2i(60,145);
    glVertex2i(30,145);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(55,135);
    glVertex2i(60,135);
    glVertex2i(60,145);
    glVertex2i(55,145);
    glEnd();

    //2
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(65,135);
    glVertex2i(95,135);
    glVertex2i(95,145);
    glVertex2i(65,145);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(90,135);
    glVertex2i(95,135);
    glVertex2i(95,145);
    glVertex2i(90,145);
    glEnd();

    //3
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(140,135);
    glVertex2i(170,135);
    glVertex2i(170,145);
    glVertex2i(140,145);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(165,135);
    glVertex2i(170,135);
    glVertex2i(170,145);
    glVertex2i(165,145);
    glEnd();


    //horizontal lines
    //(1)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(15,290);
    glVertex2i(185,290);
    glVertex2i(185,295);
    glVertex2i(15,295);
    glEnd();

    //(2)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(15,255-10);
    glVertex2i(185,255-10);
    glVertex2i(185,260-10);
    glVertex2i(15,260-10);
    glEnd();

    //(3)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(15,210-10);
    glVertex2i(185,210-10);
    glVertex2i(185,215-10);
    glVertex2i(15,215-10);
    glEnd();

    //(4)
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(15,165);
    glVertex2i(185+10,165);
    glVertex2i(185+10,170);
    glVertex2i(15,170);
    glEnd();


    //square windows and stuff
    //1
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(5,270);
    glVertex2i(10,270);
    glVertex2i(10,285);
    glVertex2i(5,285);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(10,270);
    glVertex2i(35,270);
    glVertex2i(35,285);
    glVertex2i(10,285);
    glEnd();

    //dots begin
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,275);
    glVertex2i(5,275);
    glVertex2i(5,280);
    glVertex2i(0,280);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(15,275);
    glVertex2i(20,275);
    glVertex2i(20,280);
    glVertex2i(15,280);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(25,275);
    glVertex2i(30,275);
    glVertex2i(30,280);
    glVertex2i(25,280);
    glEnd();
    //dots end

    //main square windows
    //1
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(40,270);
    glVertex2i(50,270);
    glVertex2i(50,285);
    glVertex2i(40,285);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(50,270);
    glVertex2i(55,270);
    glVertex2i(55,285);
    glVertex2i(50,285);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(60,270);
    glVertex2i(70,270);
    glVertex2i(70,285);
    glVertex2i(60,285);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(70,270);
    glVertex2i(75,270);
    glVertex2i(75,285);
    glVertex2i(70,285);
    glEnd();

    //2
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(90,270);
    glVertex2i(100,270);
    glVertex2i(100,285);
    glVertex2i(90,285);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(100,270);
    glVertex2i(105,270);
    glVertex2i(105,285);
    glVertex2i(100,285);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(110,270);
    glVertex2i(120,270);
    glVertex2i(120,285);
    glVertex2i(110,285);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(120,270);
    glVertex2i(125,270);
    glVertex2i(125,285);
    glVertex2i(120,285);
    glEnd();

    //3
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(140,270);
    glVertex2i(150,270);
    glVertex2i(150,285);
    glVertex2i(140,285);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(150,270);
    glVertex2i(155,270);
    glVertex2i(155,285);
    glVertex2i(150,285);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(160,270);
    glVertex2i(170,270);
    glVertex2i(170,285);
    glVertex2i(160,285);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(170,270);
    glVertex2i(175,270);
    glVertex2i(175,285);
    glVertex2i(170,285);
    glEnd();

    //2 windows and stuff
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(5,225);
    glVertex2i(10,225);
    glVertex2i(10,240);
    glVertex2i(5,240);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(10,225);
    glVertex2i(35,225);
    glVertex2i(35,240);
    glVertex2i(10,240);
    glEnd();

    //dots begin
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,230);
    glVertex2i(5,230);
    glVertex2i(5,235);
    glVertex2i(0,235);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(15,230);
    glVertex2i(20,230);
    glVertex2i(20,235);
    glVertex2i(15,235);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(25,230);
    glVertex2i(30,230);
    glVertex2i(30,235);
    glVertex2i(25,235);
    glEnd();
    //dots end

    //main square windows
    //1
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(40,225);
    glVertex2i(50,225);
    glVertex2i(50,240);
    glVertex2i(40,240);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(50,225);
    glVertex2i(55,225);
    glVertex2i(55,240);
    glVertex2i(50,240);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(60,225);
    glVertex2i(70,225);
    glVertex2i(70,240);
    glVertex2i(60,240);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(70,225);
    glVertex2i(75,225);
    glVertex2i(75,240);
    glVertex2i(70,240);
    glEnd();

    //2
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(90,225);
    glVertex2i(100,225);
    glVertex2i(100,240);
    glVertex2i(90,240);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(100,225);
    glVertex2i(105,225);
    glVertex2i(105,240);
    glVertex2i(100,240);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(110,225);
    glVertex2i(120,225);
    glVertex2i(120,240);
    glVertex2i(110,240);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(120,225);
    glVertex2i(125,225);
    glVertex2i(125,240);
    glVertex2i(120,240);
    glEnd();

    //3
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(140,225);
    glVertex2i(150,225);
    glVertex2i(150,240);
    glVertex2i(140,240);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(150,225);
    glVertex2i(155,225);
    glVertex2i(155,240);
    glVertex2i(150,240);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(160,225);
    glVertex2i(170,225);
    glVertex2i(170,240);
    glVertex2i(160,240);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(170,225);
    glVertex2i(175,225);
    glVertex2i(175,240);
    glVertex2i(170,240);
    glEnd();

    //3 windows and stuff
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(5,180);
    glVertex2i(10,180);
    glVertex2i(10,195);
    glVertex2i(5,195);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(10,180);
    glVertex2i(35,180);
    glVertex2i(35,195);
    glVertex2i(10,195);
    glEnd();

    //dots begin
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,185);
    glVertex2i(5,185);
    glVertex2i(5,190);
    glVertex2i(0,190);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(15,185);
    glVertex2i(20,185);
    glVertex2i(20,190);
    glVertex2i(15,190);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(25,185);
    glVertex2i(30,185);
    glVertex2i(30,190);
    glVertex2i(25,190);
    glEnd();
    //dots end

    //main square windows
    //1
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(40,180);
    glVertex2i(50,180);
    glVertex2i(50,195);
    glVertex2i(40,195);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(50,180);
    glVertex2i(55,180);
    glVertex2i(55,195);
    glVertex2i(50,195);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(60,180);
    glVertex2i(70,180);
    glVertex2i(70,195);
    glVertex2i(60,195);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(70,180);
    glVertex2i(75,180);
    glVertex2i(75,195);
    glVertex2i(70,195);
    glEnd();

    //2
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(90,180);
    glVertex2i(100,180);
    glVertex2i(100,195);
    glVertex2i(90,195);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(100,180);
    glVertex2i(105,180);
    glVertex2i(105,195);
    glVertex2i(100,195);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(110,180);
    glVertex2i(120,180);
    glVertex2i(120,195);
    glVertex2i(110,195);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(120,180);
    glVertex2i(125,180);
    glVertex2i(125,195);
    glVertex2i(120,195);
    glEnd();

    //3
    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(140,180);
    glVertex2i(150,180);
    glVertex2i(150,195);
    glVertex2i(140,195);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(150,180);
    glVertex2i(155,180);
    glVertex2i(155,195);
    glVertex2i(150,195);
    glEnd();

    if(!dayNight) setColor("light");
    else setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(160,180);
    glVertex2i(170,180);
    glVertex2i(170,195);
    glVertex2i(160,195);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(170,180);
    glVertex2i(175,180);
    glVertex2i(175,195);
    glVertex2i(170,195);
    glEnd();

    //side parts
    //1
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(185,295);
    glVertex2i(200,295);
    glVertex2i(200,310);
    glVertex2i(185,310);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(190,265);
    glVertex2i(195,265);
    glVertex2i(195,295);
    glVertex2i(190,295);
    glEnd();
    //2
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(185,295-45);
    glVertex2i(200,295-45);
    glVertex2i(200,310-45);
    glVertex2i(185,310-45);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(190,265-45);
    glVertex2i(195,265-45);
    glVertex2i(195,295-45);
    glVertex2i(190,295-45);
    glEnd();
    //3
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(185,295-90);
    glVertex2i(200,295-90);
    glVertex2i(200,310-90);
    glVertex2i(185,310-90);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(190,265-90);
    glVertex2i(195,265-90);
    glVertex2i(195,295-90);
    glVertex2i(190,295-90);
    glEnd();
    //extra
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(185,295-125);
    glVertex2i(200,295-125);
    glVertex2i(200,310-125);
    glVertex2i(185,310-125);
    glEnd();

    //top part
    //house
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(20,315);
    glVertex2i(70,315);
    glVertex2i(70,345);
    glVertex2i(20,345);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(20+15,315);
    glVertex2i(70+15,315);
    glVertex2i(70+15,345);
    glVertex2i(20+15,345);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(45,320);
    glVertex2i(55,320);
    glVertex2i(55,330);
    glVertex2i(45,330);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(45+15,320-5);
    glVertex2i(55+15,320-5);
    glVertex2i(55+15,330);
    glVertex2i(45+15,330);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(20+15,315+20);
    glVertex2i(70+15,315+20);
    glVertex2i(70+15,315+20+5);
    glVertex2i(20+15,315+20+5);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(20+15,315+20+5);
    glVertex2i(70+15+5,315+20+5);
    glVertex2i(70+15+5,315+20+5+5);
    glVertex2i(20+15,315+20+5+5);
    glEnd();
    //house end
    //house stair




    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(10,315);
    glVertex2i(40,315);
    glVertex2i(40,330);
    glVertex2i(10,330);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(15,315);
    glVertex2i(40,315);
    glVertex2i(40,335);
    glVertex2i(15,335);
    glEnd();



    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,315);
    glVertex2i(25,315);
    glVertex2i(25,320);
    glVertex2i(0,320);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(5,315);
    glVertex2i(20,315);
    glVertex2i(20,325);
    glVertex2i(5,325);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(5+155+5,315);
    glVertex2i(20+155+5,315);
    glVertex2i(20+155+5,325);
    glVertex2i(5+155+5,325);
    glEnd();

    //end stairs

    //pumps
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(90+10,315);
    glVertex2i(105+10,315);
    glVertex2i(105+10,340);
    glVertex2i(90+10,340);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(90+30,315);
    glVertex2i(105+30,315);
    glVertex2i(105+30,340);
    glVertex2i(90+30,340);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(85,320);
    glVertex2i(85+70,320);
    glVertex2i(85+70,325);
    glVertex2i(85,325);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(90,315);
    glVertex2i(95,315);
    glVertex2i(95,320);
    glVertex2i(90,320);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(90+50,315);
    glVertex2i(95+50,315);
    glVertex2i(95+50,320);
    glVertex2i(90+50,320);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(90+60,315);
    glVertex2i(95+60,315);
    glVertex2i(95+60,320);
    glVertex2i(90+60,320);
    glEnd();

    //bottom start
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,130);
    glVertex2i(185,130);
    glVertex2i(185,135);
    glVertex2i(0,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(245,50);
    glVertex2i(245,110);
    glVertex2i(0,110);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(375,50);
    glVertex2i(375,65);
    glVertex2i(0,65);
    glEnd();

    //extra dark pixel
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(15,130);
    glVertex2i(20,130);
    glVertex2i(20,135);
    glVertex2i(15,135);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(185,50);
    glVertex2i(185,115);
    glVertex2i(0,115);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,110);
    glVertex2i(185,110);
    glVertex2i(185,130);
    glVertex2i(0,130);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0,110);
    glVertex2i(5,110);
    glVertex2i(5,125);
    glVertex2i(0,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+10,110);
    glVertex2i(5+15,110);
    glVertex2i(5+15,125);
    glVertex2i(0+10,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+25,110);
    glVertex2i(5+25,110);
    glVertex2i(5+25,125);
    glVertex2i(0+25,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+50,110);
    glVertex2i(5+50,110);
    glVertex2i(5+50,125);
    glVertex2i(0+50,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+60,110);
    glVertex2i(5+60,110);
    glVertex2i(5+60,125);
    glVertex2i(0+60,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+60-15-5,110);
    glVertex2i(5+60-15-5,110);
    glVertex2i(5+60-15-5,125);
    glVertex2i(0+60-15-5,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+75,110);
    glVertex2i(5+75,110);
    glVertex2i(5+75,125);
    glVertex2i(0+75,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0,110+10);
    glVertex2i(80,110+10);
    glVertex2i(80,115+10);
    glVertex2i(0,115+10);
    glEnd();

    //dots
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(5,120);
    glVertex2i(10,120);
    glVertex2i(10,125);
    glVertex2i(5,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(5,120-5);
    glVertex2i(10,120-5);
    glVertex2i(10,125-5);
    glVertex2i(5,125-5);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(5,120-5-5);
    glVertex2i(10,120-5-5);
    glVertex2i(10,125-5-5);
    glVertex2i(5,125-5-5);
    glEnd();


    //fence 2
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+150,110);
    glVertex2i(5+150,110);
    glVertex2i(5+150,125);
    glVertex2i(0+150,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+10+150,110);
    glVertex2i(5+15+150,110);
    glVertex2i(5+15+150,125);
    glVertex2i(0+10+150,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+25+150,110);
    glVertex2i(5+25+150,110);
    glVertex2i(5+25+150,125);
    glVertex2i(0+25+150,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+50+150,110);
    glVertex2i(5+50+150,110);
    glVertex2i(5+50+150,125);
    glVertex2i(0+50+150,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+60+150,110);
    glVertex2i(5+60+150,110);
    glVertex2i(5+60+150,125);
    glVertex2i(0+60+150,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+60-15-5+150,110);
    glVertex2i(5+60-15-5+150,110);
    glVertex2i(5+60-15-5+150,125);
    glVertex2i(0+60-15-5+150,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+75+150,110);
    glVertex2i(5+75+150,110);
    glVertex2i(5+75+150,125);
    glVertex2i(0+75+150,125);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(0+150,110+10);
    glVertex2i(80+150,110+10);
    glVertex2i(80+150,115+10);
    glVertex2i(0+150,115+10);
    glEnd();





    // building door

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(105+10-5,110);
    glVertex2i(120+10-5,110);
    glVertex2i(120+10-5,150);
    glVertex2i(105+10-5,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(130-5,110);
    glVertex2i(135-5,110);
    glVertex2i(135-5,150);
    glVertex2i(130-5,150);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(125-5,125);
    glVertex2i(130-5,125);
    glVertex2i(130-5,130);
    glVertex2i(125-5,130);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(105+10-5-10+5,110);
    glVertex2i(105+10-10+5,110);
    glVertex2i(105+10-10+5,150);
    glVertex2i(105+10-5-10+5,150);
    glEnd();

    //random detail on dark area
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(50,100);
    glVertex2i(80,100);
    glVertex2i(80,105);
    glVertex2i(50,105);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(50-20+100,100-10);
    glVertex2i(80-30+100,100-10);
    glVertex2i(80-30+100,105-10);
    glVertex2i(50-20+100,105-10);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(50+90,100);
    glVertex2i(80+90,100);
    glVertex2i(80+90,105);
    glVertex2i(50+90,105);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(50-30,100-10);
    glVertex2i(80-30,100-10);
    glVertex2i(80-30,105-10);
    glVertex2i(50-30,105-10);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(50+70,100-10);
    glVertex2i(80+70,100-10);
    glVertex2i(80+70,105-10);
    glVertex2i(50+70,105-10);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(50+70+5,100-10-5);
    glVertex2i(80+70,100-10-5);
    glVertex2i(80+70,105-10-5);
    glVertex2i(50+70+5,105-10-5);
    glEnd();



    //bottom details
    //ladder

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(180,100);
    glVertex2i(200,100);
    glVertex2i(200,105);
    glVertex2i(180,105);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(180,90);
    glVertex2i(200,90);
    glVertex2i(200,95);
    glVertex2i(180,95);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(180,80);
    glVertex2i(200,80);
    glVertex2i(200,85);
    glVertex2i(180,85);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(180,70);
    glVertex2i(200,70);
    glVertex2i(200,75);
    glVertex2i(180,75);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(180,65);
    glVertex2i(185,65);
    glVertex2i(185,105);
    glVertex2i(180,105);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(195,65);
    glVertex2i(200,65);
    glVertex2i(200,105);
    glVertex2i(195,105);
    glEnd();
    //end of ladder

    //bottom fence
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(125,65);
    glVertex2i(130,65);
    glVertex2i(130,80);
    glVertex2i(125,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(135,65);
    glVertex2i(140,65);
    glVertex2i(140,80);
    glVertex2i(135,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(115,65);
    glVertex2i(120,65);
    glVertex2i(120,80);
    glVertex2i(115,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(150,65);
    glVertex2i(155,65);
    glVertex2i(155,80);
    glVertex2i(150,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(165,65);
    glVertex2i(170,65);
    glVertex2i(170,80);
    glVertex2i(165,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(110,75);
    glVertex2i(170,75);
    glVertex2i(170,80);
    glVertex2i(110,80);
    glEnd();

    //hide imperfection

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(110,85);
    glVertex2i(170,85);
    glVertex2i(170,90);
    glVertex2i(110,90);
    glEnd();

    //bottom fence 2
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(110+125,65);
    glVertex2i(110+130,65);
    glVertex2i(110+130,80);
    glVertex2i(110+125,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(110+135,65);
    glVertex2i(110+140,65);
    glVertex2i(110+140,80);
    glVertex2i(110+135,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(110+115,65);
    glVertex2i(110+120,65);
    glVertex2i(110+120,80);
    glVertex2i(110+115,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(110+150,65);
    glVertex2i(110+155,65);
    glVertex2i(110+155,80);
    glVertex2i(110+150,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(110+165,65);
    glVertex2i(110+170,65);
    glVertex2i(110+170,80);
    glVertex2i(110+165,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(110+110,75);
    glVertex2i(110+170,75);
    glVertex2i(110+170,80);
    glVertex2i(110+110,80);
    glEnd();

//
//

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(70+110+125,65);
    glVertex2i(70+110+130,65);
    glVertex2i(70+110+130,80);
    glVertex2i(70+110+125,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(70+110+135,65);
    glVertex2i(70+110+140,65);
    glVertex2i(70+110+140,80);
    glVertex2i(70+110+135,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(70+110+115,65);
    glVertex2i(70+110+120,65);
    glVertex2i(70+110+120,80);
    glVertex2i(70+110+115,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(70+110+150,65);
    glVertex2i(70+110+155,65);
    glVertex2i(70+110+155,80);
    glVertex2i(70+110+150,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(70+110+165,65);
    glVertex2i(70+110+170,65);
    glVertex2i(70+110+170,80);
    glVertex2i(70+110+165,80);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(70+110+110,75);
    glVertex2i(70+110+170,75);
    glVertex2i(70+110+170,80);
    glVertex2i(70+110+110,80);
    glEnd();



    //close to reflection
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(20,50);
    glVertex2i(20,60);
    glVertex2i(0,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(10,50);
    glVertex2i(10,65);
    glVertex2i(0,65);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(25,55);
    glVertex2i(30,55);
    glVertex2i(30,75);
    glVertex2i(25,75);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(25+10,55);
    glVertex2i(30+10,55);
    glVertex2i(30+10,65);
    glVertex2i(25+10,65);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(45,50);
    glVertex2i(130,50);
    glVertex2i(130,55);
    glVertex2i(45,55);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(55,50);
    glVertex2i(130,50);
    glVertex2i(130,60);
    glVertex2i(55,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(60,55);
    glVertex2i(75,55);
    glVertex2i(75,65);
    glVertex2i(60,65);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(60+30,45);
    glVertex2i(75+30,45);
    glVertex2i(75+30,65);
    glVertex2i(60+30,65);
    glEnd();


    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(105,55);
    glVertex2i(110,55);
    glVertex2i(110,60);
    glVertex2i(105,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(135,45);
    glVertex2i(290,45);
    glVertex2i(290,60);
    glVertex2i(135,60);
    glEnd();


    //extra details big building end

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(230,90);
    glVertex2i(245,90);
    glVertex2i(245,100);
    glVertex2i(230,100);
    glEnd();

    //boats


    //2
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(205+375,50);
    glVertex2i(205+450,50);
    glVertex2i(205+450,60);
    glVertex2i(205+375,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(205+385,60);
    glVertex2i(205+435,60);
    glVertex2i(205+435,70);
    glVertex2i(205+385,70);
    glEnd();

    //dots
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(205+390,60);
    glVertex2i(205+400,60);
    glVertex2i(205+400,65);
    glVertex2i(205+390,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(205+405,60);
    glVertex2i(205+415,60);
    glVertex2i(205+415,65);
    glVertex2i(205+405,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(205+420,60);
    glVertex2i(205+430,60);
    glVertex2i(205+430,65);
    glVertex2i(205+420,65);
    glEnd();
    //2e

    //3
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(65+205+375,50);
    glVertex2i(65+205+450,50);
    glVertex2i(65+205+450,60);
    glVertex2i(65+205+375,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(65+205+385,60);
    glVertex2i(65+205+435,60);
    glVertex2i(65+205+435,70);
    glVertex2i(65+205+385,70);
    glEnd();

    //dots
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(65+205+390,60);
    glVertex2i(65+205+400,60);
    glVertex2i(65+205+400,65);
    glVertex2i(65+205+390,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(65+205+405,60);
    glVertex2i(65+205+415,60);
    glVertex2i(65+205+415,65);
    glVertex2i(65+205+405,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(65+205+420,60);
    glVertex2i(65+205+430,60);
    glVertex2i(65+205+430,65);
    glVertex2i(65+205+420,65);
    glEnd();
    //3e

    //4
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(130+205+375,50);
    glVertex2i(130+205+450,50);
    glVertex2i(130+205+450,60);
    glVertex2i(130+205+375,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(130+205+385,60);
    glVertex2i(130+205+435,60);
    glVertex2i(130+205+435,70);
    glVertex2i(130+205+385,70);
    glEnd();

    //dots
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(130+205+390,60);
    glVertex2i(130+205+400,60);
    glVertex2i(130+205+400,65);
    glVertex2i(130+205+390,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(130+205+405,60);
    glVertex2i(130+205+415,60);
    glVertex2i(130+205+415,65);
    glVertex2i(130+205+405,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(130+205+420,60);
    glVertex2i(130+205+430,60);
    glVertex2i(130+205+430,65);
    glVertex2i(130+205+420,65);
    glEnd();
    //4e


    //1
    glPushMatrix();
    glTranslatef(boat1Position,0,0);
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(375,50);
    glVertex2i(450,50);
    glVertex2i(450,60);
    glVertex2i(375,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(385,60);
    glVertex2i(435,60);
    glVertex2i(435,70);
    glVertex2i(385,70);
    glEnd();

    //dots
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(390,60);
    glVertex2i(400,60);
    glVertex2i(400,65);
    glVertex2i(390,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(405,60);
    glVertex2i(415,60);
    glVertex2i(415,65);
    glVertex2i(405,65);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(420,60);
    glVertex2i(430,60);
    glVertex2i(430,65);
    glVertex2i(420,65);
    glEnd();
    glPopMatrix();
    //1e












}

void drawRightBuilding(){
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(785,50);
    glVertex2i(985,50);
    glVertex2i(985,65);
    glVertex2i(785,65);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(985,50);
    glVertex2i(1020,50);
    glVertex2i(1020,60);
    glVertex2i(985,60);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1020,50);
    glVertex2i(1025,50);
    glVertex2i(1025,60);
    glVertex2i(1020,60);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1025,50);
    glVertex2i(1195,50);
    glVertex2i(1195,60);
    glVertex2i(1025,60);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,50);
    glVertex2i(1200,50);
    glVertex2i(1200,60);
    glVertex2i(1195,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,50);
    glVertex2i(1235,50);
    glVertex2i(1235,60);
    glVertex2i(1200,60);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1235,50);
    glVertex2i(1240,50);
    glVertex2i(1240,60);
    glVertex2i(1235,60);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1240,50);
    glVertex2i(1245,50);
    glVertex2i(1245,55);
    glVertex2i(1240,55);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1240,55);
    glVertex2i(1245,55);
    glVertex2i(1245,60);
    glVertex2i(1240,60);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1245,50);
    glVertex2i(1250,50);
    glVertex2i(1250,60);
    glVertex2i(1245,60);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,50);
    glVertex2i(1255,50);
    glVertex2i(1255,60);
    glVertex2i(1250,60);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1255,50);
    glVertex2i(1260,50);
    glVertex2i(1260,60);
    glVertex2i(1255,60);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1260,50);
    glVertex2i(1265,50);
    glVertex2i(1265,60);
    glVertex2i(1260,60);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1265,50);
    glVertex2i(1270,50);
    glVertex2i(1270,60);
    glVertex2i(1265,60);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1270,55);
    glVertex2i(1275,55);
    glVertex2i(1275,60);
    glVertex2i(1270,60);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1275,55);
    glVertex2i(1280,55);
    glVertex2i(1280,60);
    glVertex2i(1275,60);
    glEnd();
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1270,50);
    glVertex2i(1280,50);
    glVertex2i(1280,60);
    glVertex2i(1270,60);
    glEnd();

    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(985,60);
    glVertex2i(1020,60);
    glVertex2i(1020,65);
    glVertex2i(985,65);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1020,60);
    glVertex2i(1025,60);
    glVertex2i(1025,65);
    glVertex2i(1020,65);
    glEnd();
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1025,60);
    glVertex2i(1195,60);
    glVertex2i(1195,65);
    glVertex2i(1025,65);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,60);
    glVertex2i(1200,60);
    glVertex2i(1200,65);
    glVertex2i(1195,65);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,60);
    glVertex2i(1210,60);
    glVertex2i(1210,65);
    glVertex2i(1200,65);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1210,60);
    glVertex2i(1250,60);
    glVertex2i(1250,65);
    glVertex2i(1210,65);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,60);
    glVertex2i(1255,60);
    glVertex2i(1255,65);
    glVertex2i(1250,65);
    glEnd();
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1255,60);
    glVertex2i(1280,60);
    glVertex2i(1280,65);
    glVertex2i(1255,65);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,65);
    glVertex2i(820,65);
    glVertex2i(820,70);
    glVertex2i(815,70);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(820,65);
    glVertex2i(830,65);
    glVertex2i(830,70);
    glVertex2i(820,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(830,65);
    glVertex2i(835,65);
    glVertex2i(835,70);
    glVertex2i(830,70);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(835,65);
    glVertex2i(845,65);
    glVertex2i(845,70);
    glVertex2i(835,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(845,65);
    glVertex2i(850,65);
    glVertex2i(850,70);
    glVertex2i(845,70);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(850,65);
    glVertex2i(860,65);
    glVertex2i(860,70);
    glVertex2i(850,70);
    glEnd();
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(860,65);
    glVertex2i(865,65);
    glVertex2i(865,70);
    glVertex2i(860,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(875,65);
    glVertex2i(880,65);
    glVertex2i(880,70);
    glVertex2i(875,70);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(885,65);
    glVertex2i(890,65);
    glVertex2i(890,70);
    glVertex2i(885,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(890,65);
    glVertex2i(895,65);
    glVertex2i(895,70);
    glVertex2i(890,70);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(895,65);
    glVertex2i(905,65);
    glVertex2i(905,70);
    glVertex2i(895,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(905,65);
    glVertex2i(910,65);
    glVertex2i(910,70);
    glVertex2i(905,70);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,65);
    glVertex2i(920,65);
    glVertex2i(920,70);
    glVertex2i(910,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(920,65);
    glVertex2i(925,65);
    glVertex2i(925,70);
    glVertex2i(920,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(925,65);
    glVertex2i(960,65);
    glVertex2i(960,70);
    glVertex2i(925,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(960,65);
    glVertex2i(1030,65);
    glVertex2i(1030,70);
    glVertex2i(960,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1030,65);
    glVertex2i(1035,65);
    glVertex2i(1035,70);
    glVertex2i(1030,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1035,65);
    glVertex2i(1040,65);
    glVertex2i(1040,70);
    glVertex2i(1035,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1040,65);
    glVertex2i(1045,65);
    glVertex2i(1045,70);
    glVertex2i(1040,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1045,65);
    glVertex2i(1050,65);
    glVertex2i(1050,70);
    glVertex2i(1045,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1050,65);
    glVertex2i(1055,65);
    glVertex2i(1055,70);
    glVertex2i(1050,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1055,65);
    glVertex2i(1065,65);
    glVertex2i(1065,70);
    glVertex2i(1055,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1065,65);
    glVertex2i(1070,65);
    glVertex2i(1070,70);
    glVertex2i(1065,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1070,65);
    glVertex2i(1080,65);
    glVertex2i(1080,70);
    glVertex2i(1070,70);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1080,65);
    glVertex2i(1095,65);
    glVertex2i(1095,70);
    glVertex2i(1080,70);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,65);
    glVertex2i(1100,65);
    glVertex2i(1100,70);
    glVertex2i(1095,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1100,65);
    glVertex2i(1105,65);
    glVertex2i(1105,70);
    glVertex2i(1100,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1105,65);
    glVertex2i(1115,65);
    glVertex2i(1115,70);
    glVertex2i(1105,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1115,65);
    glVertex2i(1120,65);
    glVertex2i(1120,70);
    glVertex2i(1115,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1120,65);
    glVertex2i(1140,65);
    glVertex2i(1140,70);
    glVertex2i(1120,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1140,65);
    glVertex2i(1145,65);
    glVertex2i(1145,70);
    glVertex2i(1140,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1145,65);
    glVertex2i(1165,65);
    glVertex2i(1165,70);
    glVertex2i(1145,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1165,65);
    glVertex2i(1170,65);
    glVertex2i(1170,70);
    glVertex2i(1165,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1170,65);
    glVertex2i(1175,65);
    glVertex2i(1175,70);
    glVertex2i(1170,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,65);
    glVertex2i(1180,65);
    glVertex2i(1180,70);
    glVertex2i(1175,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1180,65);
    glVertex2i(1185,65);
    glVertex2i(1185,70);
    glVertex2i(1180,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1185,65);
    glVertex2i(1190,65);
    glVertex2i(1190,70);
    glVertex2i(1185,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1190,65);
    glVertex2i(1250,65);
    glVertex2i(1250,70);
    glVertex2i(1190,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,65);
    glVertex2i(1255,65);
    glVertex2i(1255,70);
    glVertex2i(1250,70);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1255,65);
    glVertex2i(1280,65);
    glVertex2i(1280,70);
    glVertex2i(1255,70);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,70);
    glVertex2i(820,70);
    glVertex2i(820,75);
    glVertex2i(815,75);
    glEnd();
//
setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(820,70);
    glVertex2i(830,70);
    glVertex2i(830,75);
    glVertex2i(820,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(830,70);
    glVertex2i(835,70);
    glVertex2i(835,75);
    glVertex2i(830,75);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(835,70);
    glVertex2i(845,70);
    glVertex2i(845,75);
    glVertex2i(835,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(845,70);
    glVertex2i(850,70);
    glVertex2i(850,75);
    glVertex2i(845,75);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(850,70);
    glVertex2i(860,70);
    glVertex2i(860,75);
    glVertex2i(850,75);
    glEnd();
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(860,70);
    glVertex2i(865,70);
    glVertex2i(865,75);
    glVertex2i(860,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(875,70);
    glVertex2i(880,70);
    glVertex2i(880,75);
    glVertex2i(875,75);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(885,70);
    glVertex2i(890,70);
    glVertex2i(890,75);
    glVertex2i(885,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(890,70);
    glVertex2i(895,70);
    glVertex2i(895,75);
    glVertex2i(890,75);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(895,70);
    glVertex2i(905,70);
    glVertex2i(905,75);
    glVertex2i(895,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(905,70);
    glVertex2i(910,70);
    glVertex2i(910,75);
    glVertex2i(905,75);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,70);
    glVertex2i(920,70);
    glVertex2i(920,75);
    glVertex2i(910,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,70);
    glVertex2i(925,70);
    glVertex2i(925,75);
    glVertex2i(920,75);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(925,70);
    glVertex2i(930,70);
    glVertex2i(930,75);
    glVertex2i(925,75);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(930,70);
    glVertex2i(965,70);
    glVertex2i(965,75);
    glVertex2i(930,75);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(965,70);
    glVertex2i(1030,70);
    glVertex2i(1030,75);
    glVertex2i(965,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1030,70);
    glVertex2i(1070,70);
    glVertex2i(1070,75);
    glVertex2i(1030,75);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1070,70);
    glVertex2i(1075,70);
    glVertex2i(1075,75);
    glVertex2i(1070,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,70);
    glVertex2i(1080,70);
    glVertex2i(1080,75);
    glVertex2i(1075,75);
    glEnd();
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1080,70);
    glVertex2i(1090,70);
    glVertex2i(1090,75);
    glVertex2i(1080,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1090,70);
    glVertex2i(1095,70);
    glVertex2i(1095,75);
    glVertex2i(1090,75);
    glEnd();
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,70);
    glVertex2i(1100,70);
    glVertex2i(1100,75);
    glVertex2i(1095,75);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1100,70);
    glVertex2i(1190,70);
    glVertex2i(1190,75);
    glVertex2i(1100,75);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1190,70);
    glVertex2i(1280,70);
    glVertex2i(1280,75);
    glVertex2i(1190,75);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,75);
    glVertex2i(925,75);
    glVertex2i(925,80);
    glVertex2i(815,80);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(925,75);
    glVertex2i(930,75);
    glVertex2i(930,80);
    glVertex2i(925,80);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(930,75);
    glVertex2i(935,75);
    glVertex2i(935,80);
    glVertex2i(930,80);
    glEnd();
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(935,75);
    glVertex2i(975,75);
    glVertex2i(975,80);
    glVertex2i(935,80);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(975,75);
    glVertex2i(1075,75);
    glVertex2i(1075,80);
    glVertex2i(975,80);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,75);
    glVertex2i(1095,75);
    glVertex2i(1095,80);
    glVertex2i(1075,80);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,75);
    glVertex2i(1280,75);
    glVertex2i(1280,80);
    glVertex2i(1095,80);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,80);
    glVertex2i(925,80);
    glVertex2i(925,85);
    glVertex2i(920,85);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(925,80);
    glVertex2i(930,80);
    glVertex2i(930,85);
    glVertex2i(925,85);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(930,80);
    glVertex2i(935,80);
    glVertex2i(935,85);
    glVertex2i(930,85);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(935,80);
    glVertex2i(1075,80);
    glVertex2i(1075,85);
    glVertex2i(935,85);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,80);
    glVertex2i(1080,80);
    glVertex2i(1080,85);
    glVertex2i(1075,85);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1080,80);
    glVertex2i(1090,80);
    glVertex2i(1090,85);
    glVertex2i(1080,85);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1090,80);
    glVertex2i(1095,80);
    glVertex2i(1095,85);
    glVertex2i(1090,85);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,80);
    glVertex2i(1280,80);
    glVertex2i(1280,85);
    glVertex2i(1095,85);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(925,85);
    glVertex2i(935,85);
    glVertex2i(935,90);
    glVertex2i(925,90);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(935,85);
    glVertex2i(945,85);
    glVertex2i(945,90);
    glVertex2i(935,90);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(945,85);
    glVertex2i(985,85);
    glVertex2i(985,90);
    glVertex2i(945,90);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(985,85);
    glVertex2i(1075,85);
    glVertex2i(1075,90);
    glVertex2i(985,90);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,85);
    glVertex2i(1095,85);
    glVertex2i(1095,90);
    glVertex2i(1075,90);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,85);
    glVertex2i(1280,85);
    glVertex2i(1280,90);
    glVertex2i(1095,90);
    glEnd();
    //
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(930,90);
    glVertex2i(935,90);
    glVertex2i(935,95);
    glVertex2i(930,95);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(940,90);
    glVertex2i(945,90);
    glVertex2i(945,95);
    glVertex2i(940,95);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(945,90);
    glVertex2i(1075,90);
    glVertex2i(1075,95);
    glVertex2i(945,95);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,90);
    glVertex2i(1080,90);
    glVertex2i(1080,95);
    glVertex2i(1075,95);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1080,90);
    glVertex2i(1090,90);
    glVertex2i(1090,95);
    glVertex2i(1080,95);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1090,90);
    glVertex2i(1095,90);
    glVertex2i(1095,95);
    glVertex2i(1090,95);
    glEnd();
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,90);
    glVertex2i(1110,90);
    glVertex2i(1110,95);
    glVertex2i(1095,95);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1110,90);
    glVertex2i(1120,90);
    glVertex2i(1120,95);
    glVertex2i(1110,95);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1120,90);
    glVertex2i(1280,90);
    glVertex2i(1280,95);
    glVertex2i(1120,95);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(935,95);
    glVertex2i(945,95);
    glVertex2i(945,100);
    glVertex2i(935,100);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(945,95);
    glVertex2i(955,95);
    glVertex2i(955,100);
    glVertex2i(945,100);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(955,95);
    glVertex2i(995,95);
    glVertex2i(995,100);
    glVertex2i(955,100);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(995,95);
    glVertex2i(1075,95);
    glVertex2i(1075,100);
    glVertex2i(995,100);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,95);
    glVertex2i(1095,95);
    glVertex2i(1095,100);
    glVertex2i(1075,100);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,95);
    glVertex2i(1105,95);
    glVertex2i(1105,100);
    glVertex2i(1095,100);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1105,95);
    glVertex2i(1110,95);
    glVertex2i(1110,100);
    glVertex2i(1105,100);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1110,95);
    glVertex2i(1120,95);
    glVertex2i(1120,100);
    glVertex2i(1110,100);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1120,95);
    glVertex2i(1125,95);
    glVertex2i(1125,100);
    glVertex2i(1120,100);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1125,95);
    glVertex2i(1265,95);
    glVertex2i(1265,100);
    glVertex2i(1125,100);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1265,95);
    glVertex2i(1275,95);
    glVertex2i(1275,100);
    glVertex2i(1265,100);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,95);
    glVertex2i(1280,95);
    glVertex2i(1280,100);
    glVertex2i(1275,100);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(940,100);
    glVertex2i(945,100);
    glVertex2i(945,105);
    glVertex2i(940,105);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(950,100);
    glVertex2i(955,100);
    glVertex2i(955,105);
    glVertex2i(950,105);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(955,100);
    glVertex2i(960,100);
    glVertex2i(960,105);
    glVertex2i(955,105);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(960,100);
    glVertex2i(1075,100);
    glVertex2i(1075,105);
    glVertex2i(960,105);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,100);
    glVertex2i(1080,100);
    glVertex2i(1080,105);
    glVertex2i(1075,105);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1080,100);
    glVertex2i(1090,100);
    glVertex2i(1090,105);
    glVertex2i(1080,105);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1090,100);
    glVertex2i(1095,100);
    glVertex2i(1095,105);
    glVertex2i(1090,105);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,100);
    glVertex2i(1105,100);
    glVertex2i(1105,105);
    glVertex2i(1095,105);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1105,100);
    glVertex2i(1110,100);
    glVertex2i(1110,105);
    glVertex2i(1105,105);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1110,100);
    glVertex2i(1120,100);
    glVertex2i(1120,105);
    glVertex2i(1110,105);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1120,100);
    glVertex2i(1125,100);
    glVertex2i(1125,105);
    glVertex2i(1120,105);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1125,100);
    glVertex2i(1265,100);
    glVertex2i(1265,105);
    glVertex2i(1125,105);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1265,100);
    glVertex2i(1275,100);
    glVertex2i(1275,105);
    glVertex2i(1265,105);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,100);
    glVertex2i(1280,100);
    glVertex2i(1280,105);
    glVertex2i(1275,105);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(945,105);
    glVertex2i(955,105);
    glVertex2i(955,110);
    glVertex2i(945,110);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(955,105);
    glVertex2i(960,105);
    glVertex2i(960,110);
    glVertex2i(955,110);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(960,105);
    glVertex2i(965,105);
    glVertex2i(965,110);
    glVertex2i(960,110);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(965,105);
    glVertex2i(1005,105);
    glVertex2i(1005,110);
    glVertex2i(965,110);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1005,105);
    glVertex2i(1015,105);
    glVertex2i(1015,110);
    glVertex2i(1005,110);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1015,105);
    glVertex2i(1025,105);
    glVertex2i(1025,110);
    glVertex2i(1015,110);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1025,105);
    glVertex2i(1035,105);
    glVertex2i(1035,110);
    glVertex2i(1025,110);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1035,105);
    glVertex2i(1045,105);
    glVertex2i(1045,110);
    glVertex2i(1035,110);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1045,105);
    glVertex2i(1050,105);
    glVertex2i(1050,110);
    glVertex2i(1045,110);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1050,105);
    glVertex2i(1060,105);
    glVertex2i(1060,110);
    glVertex2i(1050,110);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1060,105);
    glVertex2i(1075,105);
    glVertex2i(1075,110);
    glVertex2i(1060,110);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,105);
    glVertex2i(1095,105);
    glVertex2i(1095,110);
    glVertex2i(1075,110);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,105);
    glVertex2i(1110,105);
    glVertex2i(1110,110);
    glVertex2i(1095,110);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1110,105);
    glVertex2i(1120,105);
    glVertex2i(1120,110);
    glVertex2i(1110,110);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1120,105);
    glVertex2i(1280,105);
    glVertex2i(1280,110);
    glVertex2i(1120,110);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(950,110);
    glVertex2i(955,110);
    glVertex2i(955,115);
    glVertex2i(950,115);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(955,110);
    glVertex2i(960,110);
    glVertex2i(960,115);
    glVertex2i(955,115);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(960,110);
    glVertex2i(965,110);
    glVertex2i(965,115);
    glVertex2i(960,115);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(965,110);
    glVertex2i(970,110);
    glVertex2i(970,115);
    glVertex2i(965,115);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(970,110);
    glVertex2i(1010,110);
    glVertex2i(1010,115);
    glVertex2i(970,115);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1010,110);
    glVertex2i(1015,110);
    glVertex2i(1015,115);
    glVertex2i(1010,115);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1015,110);
    glVertex2i(1025,110);
    glVertex2i(1025,115);
    glVertex2i(1015,115);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1025,110);
    glVertex2i(1035,110);
    glVertex2i(1035,115);
    glVertex2i(1025,115);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1035,110);
    glVertex2i(1045,110);
    glVertex2i(1045,115);
    glVertex2i(1035,115);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1045,110);
    glVertex2i(1075,110);
    glVertex2i(1075,115);
    glVertex2i(1045,115);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,110);
    glVertex2i(1080,110);
    glVertex2i(1080,115);
    glVertex2i(1075,115);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1080,110);
    glVertex2i(1090,110);
    glVertex2i(1090,115);
    glVertex2i(1080,115);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1090,110);
    glVertex2i(1095,110);
    glVertex2i(1095,115);
    glVertex2i(1090,115);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,110);
    glVertex2i(1240,110);
    glVertex2i(1240,115);
    glVertex2i(1095,115);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1240,110);
    glVertex2i(1260,110);
    glVertex2i(1260,115);
    glVertex2i(1240,115);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1260,110);
    glVertex2i(1280,110);
    glVertex2i(1280,115);
    glVertex2i(1260,115);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(955,115);
    glVertex2i(965,115);
    glVertex2i(965,120);
    glVertex2i(955,120);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(965,115);
    glVertex2i(970,115);
    glVertex2i(970,120);
    glVertex2i(965,120);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(970,115);
    glVertex2i(975,115);
    glVertex2i(975,120);
    glVertex2i(970,120);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(975,115);
    glVertex2i(1015,115);
    glVertex2i(1015,120);
    glVertex2i(975,120);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1015,115);
    glVertex2i(1030,115);
    glVertex2i(1030,120);
    glVertex2i(1015,120);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1030,115);
    glVertex2i(1050,115);
    glVertex2i(1050,120);
    glVertex2i(1030,120);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1050,115);
    glVertex2i(1055,115);
    glVertex2i(1055,120);
    glVertex2i(1050,120);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1055,115);
    glVertex2i(1070,115);
    glVertex2i(1070,120);
    glVertex2i(1055,120);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1070,115);
    glVertex2i(1075,115);
    glVertex2i(1075,120);
    glVertex2i(1070,120);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,115);
    glVertex2i(1095,115);
    glVertex2i(1095,120);
    glVertex2i(1075,120);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1095,115);
    glVertex2i(1280,115);
    glVertex2i(1280,120);
    glVertex2i(1095,120);
    glEnd();

    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(960,120);
    glVertex2i(965,120);
    glVertex2i(965,125);
    glVertex2i(960,125);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(965,120);
    glVertex2i(970,120);
    glVertex2i(970,125);
    glVertex2i(965,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(970,120);
    glVertex2i(975,120);
    glVertex2i(975,125);
    glVertex2i(970,125);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(980,120);
    glVertex2i(1020,120);
    glVertex2i(1020,125);
    glVertex2i(980,125);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1020,120);
    glVertex2i(1030,120);
    glVertex2i(1030,125);
    glVertex2i(1020,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1030,120);
    glVertex2i(1070,120);
    glVertex2i(1070,125);
    glVertex2i(1030,125);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1070,120);
    glVertex2i(1075,120);
    glVertex2i(1075,125);
    glVertex2i(1070,125);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1075,120);
    glVertex2i(1080,120);
    glVertex2i(1080,125);
    glVertex2i(1075,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1080,120);
    glVertex2i(1085,120);
    glVertex2i(1085,125);
    glVertex2i(1080,125);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1085,120);
    glVertex2i(1090,120);
    glVertex2i(1090,125);
    glVertex2i(1085,125);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1090,120);
    glVertex2i(1095,120);
    glVertex2i(1095,125);
    glVertex2i(1090,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1095,120);
    glVertex2i(1100,120);
    glVertex2i(1100,125);
    glVertex2i(1095,125);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1100,120);
    glVertex2i(1105,120);
    glVertex2i(1105,125);
    glVertex2i(1100,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1105,120);
    glVertex2i(1175,120);
    glVertex2i(1175,125);
    glVertex2i(1105,125);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,120);
    glVertex2i(1180,120);
    glVertex2i(1180,125);
    glVertex2i(1175,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,120);
    glVertex2i(1185,120);
    glVertex2i(1185,125);
    glVertex2i(1180,125);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,120);
    glVertex2i(1190,120);
    glVertex2i(1190,125);
    glVertex2i(1185,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,120);
    glVertex2i(1195,120);
    glVertex2i(1195,125);
    glVertex2i(1190,125);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,120);
    glVertex2i(1200,120);
    glVertex2i(1200,125);
    glVertex2i(1195,125);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,120);
    glVertex2i(1215,120);
    glVertex2i(1215,125);
    glVertex2i(1200,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1215,120);
    glVertex2i(1220,120);
    glVertex2i(1220,125);
    glVertex2i(1215,125);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,120);
    glVertex2i(1225,120);
    glVertex2i(1225,125);
    glVertex2i(1220,125);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1225,120);
    glVertex2i(1280,120);
    glVertex2i(1280,125);
    glVertex2i(1225,125);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(965,125);
    glVertex2i(975,125);
    glVertex2i(975,130);
    glVertex2i(965,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(980,125);
    glVertex2i(985,125);
    glVertex2i(985,130);
    glVertex2i(980,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(995,125);
    glVertex2i(1000,125);
    glVertex2i(1000,130);
    glVertex2i(995,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1010,125);
    glVertex2i(1015,125);
    glVertex2i(1015,130);
    glVertex2i(1010,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1020,125);
    glVertex2i(1025,125);
    glVertex2i(1025,130);
    glVertex2i(1020,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1025,125);
    glVertex2i(1030,125);
    glVertex2i(1030,130);
    glVertex2i(1025,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1030,125);
    glVertex2i(1035,125);
    glVertex2i(1035,130);
    glVertex2i(1030,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1040,125);
    glVertex2i(1045,125);
    glVertex2i(1045,130);
    glVertex2i(1040,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1045,125);
    glVertex2i(1055,125);
    glVertex2i(1055,130);
    glVertex2i(1045,130);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1055,125);
    glVertex2i(1070,125);
    glVertex2i(1070,130);
    glVertex2i(1055,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1070,125);
    glVertex2i(1095,125);
    glVertex2i(1095,130);
    glVertex2i(1070,130);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1095,125);
    glVertex2i(1105,125);
    glVertex2i(1105,130);
    glVertex2i(1095,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1105,125);
    glVertex2i(1110,125);
    glVertex2i(1110,130);
    glVertex2i(1105,130);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1110,125);
    glVertex2i(1115,125);
    glVertex2i(1115,130);
    glVertex2i(1110,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1115,125);
    glVertex2i(1175,125);
    glVertex2i(1175,130);
    glVertex2i(1115,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,125);
    glVertex2i(1180,125);
    glVertex2i(1180,130);
    glVertex2i(1175,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,125);
    glVertex2i(1185,125);
    glVertex2i(1185,130);
    glVertex2i(1180,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,125);
    glVertex2i(1190,125);
    glVertex2i(1190,130);
    glVertex2i(1185,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,125);
    glVertex2i(1195,125);
    glVertex2i(1195,130);
    glVertex2i(1190,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,125);
    glVertex2i(1200,125);
    glVertex2i(1200,130);
    glVertex2i(1195,130);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,125);
    glVertex2i(1215,125);
    glVertex2i(1215,130);
    glVertex2i(1200,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1215,125);
    glVertex2i(1220,125);
    glVertex2i(1220,130);
    glVertex2i(1215,130);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,125);
    glVertex2i(1225,125);
    glVertex2i(1225,130);
    glVertex2i(1220,130);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1225,125);
    glVertex2i(1280,125);
    glVertex2i(1280,130);
    glVertex2i(1225,130);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(970,130);
    glVertex2i(1040,130);
    glVertex2i(1040,135);
    glVertex2i(970,135);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1040,130);
    glVertex2i(1140,130);
    glVertex2i(1140,135);
    glVertex2i(1040,135);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1140,130);
    glVertex2i(1160,130);
    glVertex2i(1160,135);
    glVertex2i(1140,135);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1160,130);
    glVertex2i(1170,130);
    glVertex2i(1170,135);
    glVertex2i(1160,135);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1170,130);
    glVertex2i(1175,130);
    glVertex2i(1175,135);
    glVertex2i(1170,135);
    glEnd();

     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,130);
    glVertex2i(1180,130);
    glVertex2i(1180,135);
    glVertex2i(1175,135);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,130);
    glVertex2i(1185,130);
    glVertex2i(1185,135);
    glVertex2i(1180,135);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,130);
    glVertex2i(1190,130);
    glVertex2i(1190,135);
    glVertex2i(1185,135);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,130);
    glVertex2i(1195,130);
    glVertex2i(1195,135);
    glVertex2i(1190,135);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,130);
    glVertex2i(1200,130);
    glVertex2i(1200,135);
    glVertex2i(1195,135);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,130);
    glVertex2i(1215,130);
    glVertex2i(1215,135);
    glVertex2i(1200,135);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1215,130);
    glVertex2i(1220,130);
    glVertex2i(1220,135);
    glVertex2i(1215,135);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,130);
    glVertex2i(1225,130);
    glVertex2i(1225,135);
    glVertex2i(1220,135);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1225,130);
    glVertex2i(1280,130);
    glVertex2i(1280,135);
    glVertex2i(1225,135);
    glEnd();
    //
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(970,135);
    glVertex2i(1030,135);
    glVertex2i(1030,140);
    glVertex2i(970,140);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1060,135);
    glVertex2i(1145,135);
    glVertex2i(1145,140);
    glVertex2i(1060,140);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1145,135);
    glVertex2i(1175,135);
    glVertex2i(1175,140);
    glVertex2i(1145,140);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,135);
    glVertex2i(1180,135);
    glVertex2i(1180,140);
    glVertex2i(1175,140);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,135);
    glVertex2i(1185,135);
    glVertex2i(1185,140);
    glVertex2i(1180,140);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,135);
    glVertex2i(1190,135);
    glVertex2i(1190,140);
    glVertex2i(1185,140);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,135);
    glVertex2i(1195,135);
    glVertex2i(1195,140);
    glVertex2i(1190,140);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,135);
    glVertex2i(1200,135);
    glVertex2i(1200,140);
    glVertex2i(1195,140);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,135);
    glVertex2i(1205,135);
    glVertex2i(1205,140);
    glVertex2i(1200,140);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1205,135);
    glVertex2i(1215,135);
    glVertex2i(1215,140);
    glVertex2i(1205,140);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1215,135);
    glVertex2i(1220,135);
    glVertex2i(1220,140);
    glVertex2i(1215,140);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,135);
    glVertex2i(1225,135);
    glVertex2i(1225,140);
    glVertex2i(1220,140);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1225,135);
    glVertex2i(1280,135);
    glVertex2i(1280,140);
    glVertex2i(1225,140);
    glEnd();
    //

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1020,140);
    glVertex2i(1050,140);
    glVertex2i(1050,145);
    glVertex2i(1020,145);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1050,140);
    glVertex2i(1150,140);
    glVertex2i(1150,145);
    glVertex2i(1050,145);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1150,140);
    glVertex2i(1175,140);
    glVertex2i(1175,145);
    glVertex2i(1150,145);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,140);
    glVertex2i(1180,140);
    glVertex2i(1180,145);
    glVertex2i(1175,145);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,140);
    glVertex2i(1185,140);
    glVertex2i(1185,145);
    glVertex2i(1180,145);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,140);
    glVertex2i(1190,140);
    glVertex2i(1190,145);
    glVertex2i(1185,145);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,140);
    glVertex2i(1195,140);
    glVertex2i(1195,145);
    glVertex2i(1190,145);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,140);
    glVertex2i(1200,140);
    glVertex2i(1200,145);
    glVertex2i(1195,145);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,140);
    glVertex2i(1215,140);
    glVertex2i(1215,145);
    glVertex2i(1200,145);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1215,140);
    glVertex2i(1220,140);
    glVertex2i(1220,145);
    glVertex2i(1215,145);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,140);
    glVertex2i(1225,140);
    glVertex2i(1225,145);
    glVertex2i(1220,145);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1225,140);
    glVertex2i(1280,140);
    glVertex2i(1280,145);
    glVertex2i(1225,145);
    glEnd();

    //
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1010,145);
    glVertex2i(1040,145);
    glVertex2i(1040,150);
    glVertex2i(1010,150);
    glEnd();


     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1150,145);
    glVertex2i(1175,145);
    glVertex2i(1175,150);
    glVertex2i(1150,150);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,145);
    glVertex2i(1180,145);
    glVertex2i(1180,150);
    glVertex2i(1175,150);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,145);
    glVertex2i(1185,145);
    glVertex2i(1185,150);
    glVertex2i(1180,150);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,145);
    glVertex2i(1190,145);
    glVertex2i(1190,150);
    glVertex2i(1185,150);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,145);
    glVertex2i(1195,145);
    glVertex2i(1195,150);
    glVertex2i(1190,150);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1195,145);
    glVertex2i(1200,145);
    glVertex2i(1200,150);
    glVertex2i(1195,150);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1200,145);
    glVertex2i(1215,145);
    glVertex2i(1215,150);
    glVertex2i(1200,150);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1215,145);
    glVertex2i(1220,145);
    glVertex2i(1220,150);
    glVertex2i(1215,150);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,145);
    glVertex2i(1225,145);
    glVertex2i(1225,150);
    glVertex2i(1220,150);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1225,145);
    glVertex2i(1235,145);
    glVertex2i(1235,150);
    glVertex2i(1225,150);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1235,145);
    glVertex2i(1240,145);
    glVertex2i(1240,150);
    glVertex2i(1235,150);
    glEnd();
    //window
    if(!dayNight) setColor("light");
    else setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1240,145);
    glVertex2i(1275,145);
    glVertex2i(1275,150);
    glVertex2i(1240,150);
    glEnd();

    //
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1000,150);
    glVertex2i(1030,150);
    glVertex2i(1030,155);
    glVertex2i(1000,155);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1030,150);
    glVertex2i(1175,150);
    glVertex2i(1175,155);
    glVertex2i(1030,155);
    glEnd();
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,150);
    glVertex2i(1180,150);
    glVertex2i(1180,155);
    glVertex2i(1175,155);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,150);
    glVertex2i(1185,150);
    glVertex2i(1185,155);
    glVertex2i(1180,155);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,150);
    glVertex2i(1190,150);
    glVertex2i(1190,155);
    glVertex2i(1185,155);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,150);
    glVertex2i(1195,150);
    glVertex2i(1195,155);
    glVertex2i(1190,155);
    glEnd();
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1235,150);
    glVertex2i(1240,150);
    glVertex2i(1240,155);
    glVertex2i(1235,155);
    glEnd();
    //window
    if(!dayNight) setColor("light");
    else setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1240,150);
    glVertex2i(1275,150);
    glVertex2i(1275,155);
    glVertex2i(1240,155);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1275,150);
    glVertex2i(1280,150);
    glVertex2i(1280,155);
    glVertex2i(1275,155);
    glEnd();
    //
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(985,155);
    glVertex2i(995,155);
    glVertex2i(995,160);
    glVertex2i(985,160);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(995,155);
    glVertex2i(1025,155);
    glVertex2i(1025,160);
    glVertex2i(995,160);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1175,155);
    glVertex2i(1180,155);
    glVertex2i(1180,160);
    glVertex2i(1175,160);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1180,155);
    glVertex2i(1185,155);
    glVertex2i(1185,160);
    glVertex2i(1180,160);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,155);
    glVertex2i(1190,155);
    glVertex2i(1190,160);
    glVertex2i(1185,160);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,155);
    glVertex2i(1195,155);
    glVertex2i(1195,160);
    glVertex2i(1190,160);
    glEnd();
     setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1235,155);
    glVertex2i(1240,155);
    glVertex2i(1240,160);
    glVertex2i(1235,160);
    glEnd();
    //window
    if(!dayNight) setColor("light");
    else setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1240,155);
    glVertex2i(1275,155);
    glVertex2i(1275,160);
    glVertex2i(1240,160);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1275,155);
    glVertex2i(1280,155);
    glVertex2i(1280,160);
    glVertex2i(1275,160);
    glEnd();
    //
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(985,160);
    glVertex2i(990,160);
    glVertex2i(990,165);
    glVertex2i(985,165);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(990,160);
    glVertex2i(1020,160);
    glVertex2i(1020,165);
    glVertex2i(990,165);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1170,160);
    glVertex2i(1280,160);
    glVertex2i(1280,165);
    glVertex2i(1170,165);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(985,165);
    glVertex2i(1015,165);
    glVertex2i(1015,170);
    glVertex2i(985,170);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1170,165);
    glVertex2i(1280,165);
    glVertex2i(1280,170);
    glVertex2i(1170,170);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,170);
    glVertex2i(1280,170);
    glVertex2i(1280,175);
    glVertex2i(1175,175);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,175);
    glVertex2i(1250,175);
    glVertex2i(1250,180);
    glVertex2i(1175,180);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,175);
    glVertex2i(1275,175);
    glVertex2i(1275,180);
    glVertex2i(1250,180);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,175);
    glVertex2i(1280,175);
    glVertex2i(1280,180);
    glVertex2i(1275,180);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,180);
    glVertex2i(1185,180);
    glVertex2i(1185,185);
    glVertex2i(1175,185);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,180);
    glVertex2i(1190,180);
    glVertex2i(1190,185);
    glVertex2i(1185,185);
    glEnd();
    //window
    if(!dayNight) setColor("light");
    else setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,180);
    glVertex2i(1220,180);
    glVertex2i(1220,185);
    glVertex2i(1190,185);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1220,180);
    glVertex2i(1250,180);
    glVertex2i(1250,185);
    glVertex2i(1220,185);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,180);
    glVertex2i(1255,180);
    glVertex2i(1255,185);
    glVertex2i(1250,185);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1255,180);
    glVertex2i(1265,180);
    glVertex2i(1265,185);
    glVertex2i(1255,185);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1265,180);
    glVertex2i(1270,180);
    glVertex2i(1270,185);
    glVertex2i(1265,185);
    glEnd();
    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(1270,180);
    glVertex2i(1275,180);
    glVertex2i(1275,185);
    glVertex2i(1270,185);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,180);
    glVertex2i(1280,180);
    glVertex2i(1280,185);
    glVertex2i(1275,185);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,185);
    glVertex2i(1185,185);
    glVertex2i(1185,190);
    glVertex2i(1175,190);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,185);
    glVertex2i(1190,185);
    glVertex2i(1190,190);
    glVertex2i(1185,190);
    glEnd();
    //window
    if(!dayNight) setColor("light");
    else setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,185);
    glVertex2i(1220,185);
    glVertex2i(1220,190);
    glVertex2i(1190,190);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1220,185);
    glVertex2i(1250,185);
    glVertex2i(1250,190);
    glVertex2i(1220,190);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,185);
    glVertex2i(1275,185);
    glVertex2i(1275,190);
    glVertex2i(1250,190);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,185);
    glVertex2i(1280,185);
    glVertex2i(1280,190);
    glVertex2i(1275,190);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,190);
    glVertex2i(1185,190);
    glVertex2i(1185,195);
    glVertex2i(1175,195);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1185,190);
    glVertex2i(1190,190);
    glVertex2i(1190,195);
    glVertex2i(1185,195);
    glEnd();
    //window
    if(!dayNight) setColor("light");
    else setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1190,190);
    glVertex2i(1220,190);
    glVertex2i(1220,195);
    glVertex2i(1190,195);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1220,190);
    glVertex2i(1280,190);
    glVertex2i(1280,195);
    glVertex2i(1220,195);
    glEnd();
    //
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,195);
    glVertex2i(1250,195);
    glVertex2i(1250,200);
    glVertex2i(1175,200);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,195);
    glVertex2i(1275,195);
    glVertex2i(1275,200);
    glVertex2i(1250,200);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,195);
    glVertex2i(1280,195);
    glVertex2i(1280,200);
    glVertex2i(1275,200);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1175,200);
    glVertex2i(1250,200);
    glVertex2i(1250,205);
    glVertex2i(1175,205);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,200);
    glVertex2i(1255,200);
    glVertex2i(1255,205);
    glVertex2i(1250,205);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1255,200);
    glVertex2i(1265,200);
    glVertex2i(1265,205);
    glVertex2i(1255,205);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1265,200);
    glVertex2i(1270,200);
    glVertex2i(1270,205);
    glVertex2i(1265,205);
    glEnd();
    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(1270,200);
    glVertex2i(1275,200);
    glVertex2i(1275,205);
    glVertex2i(1270,205);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,200);
    glVertex2i(1280,200);
    glVertex2i(1280,205);
    glVertex2i(1275,205);
    glEnd();
    //
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1180,205);
    glVertex2i(1185,205);
    glVertex2i(1185,210);
    glVertex2i(1180,210);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1190,205);
    glVertex2i(1195,205);
    glVertex2i(1195,210);
    glVertex2i(1190,210);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1200,205);
    glVertex2i(1205,205);
    glVertex2i(1205,210);
    glVertex2i(1200,210);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1210,205);
    glVertex2i(1215,205);
    glVertex2i(1215,210);
    glVertex2i(1210,210);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,205);
    glVertex2i(1225,205);
    glVertex2i(1225,210);
    glVertex2i(1220,210);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1230,205);
    glVertex2i(1250,205);
    glVertex2i(1250,210);
    glVertex2i(1230,210);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1250,205);
    glVertex2i(1275,205);
    glVertex2i(1275,210);
    glVertex2i(1250,210);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1275,205);
    glVertex2i(1280,205);
    glVertex2i(1280,210);
    glVertex2i(1275,210);
    glEnd();
    //
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1180,210);
    glVertex2i(1185,210);
    glVertex2i(1185,215);
    glVertex2i(1180,215);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1190,210);
    glVertex2i(1195,210);
    glVertex2i(1195,215);
    glVertex2i(1190,215);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1200,210);
    glVertex2i(1205,210);
    glVertex2i(1205,215);
    glVertex2i(1200,215);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1210,210);
    glVertex2i(1215,210);
    glVertex2i(1215,215);
    glVertex2i(1210,215);
    glEnd();
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1220,210);
    glVertex2i(1225,210);
    glVertex2i(1225,215);
    glVertex2i(1220,215);
    glEnd();
     setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1230,210);
    glVertex2i(1280,210);
    glVertex2i(1280,215);
    glVertex2i(1230,215);
    glEnd();
    //
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(1180,215);
    glVertex2i(1230,215);
    glVertex2i(1230,220);
    glVertex2i(1180,220);
    glEnd();
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1230,215);
    glVertex2i(1280,215);
    glVertex2i(1280,220);
    glVertex2i(1230,220);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1230,220);
    glVertex2i(1280,220);
    glVertex2i(1280,225);
    glVertex2i(1230,225);
    glEnd();
    //
    setColor("frontBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1230,225);
    glVertex2i(1280,225);
    glVertex2i(1280,230);
    glVertex2i(1230,230);
    glEnd();
    //
    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(1240,230);
    glVertex2i(1255,230);
    glVertex2i(1255,235);
    glVertex2i(1240,235);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1270,230);
    glVertex2i(1275,230);
    glVertex2i(1275,235);
    glVertex2i(1270,235);
    glEnd();
    //
    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(1240,235);
    glVertex2i(1255,235);
    glVertex2i(1255,240);
    glVertex2i(1240,240);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1265,235);
    glVertex2i(1280,235);
    glVertex2i(1280,240);
    glVertex2i(1265,240);
    glEnd();
    //
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1270,240);
    glVertex2i(1275,240);
    glVertex2i(1275,245);
    glVertex2i(1270,245);
    glEnd();
    //
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1265,245);
    glVertex2i(1280,245);
    glVertex2i(1280,250);
    glVertex2i(1265,250);
    glEnd();
    //
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1270,250);
    glVertex2i(1275,250);
    glVertex2i(1275,255);
    glVertex2i(1270,255);
    glEnd();





}



void drawReflection(){
    glPointSize(5.0);

    //start of color and drawing

    //0th line


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(0,45);
    glVertex2i(1280,45);
    glVertex2i(1280,50);
    glVertex2i(0,50);
    glEnd();



//1st line
    glPushMatrix();
    glTranslatef(oddReflectionPosition,0,0);

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,40);
    glVertex2i(20,40);
    glVertex2i(20,45);
    glVertex2i(0,45);
    glEnd();


    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(20,40);
    glVertex2i(45,40);
    glVertex2i(45,45);
    glVertex2i(20,45);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(45,40);
    glVertex2i(130,40);
    glVertex2i(130,45);
    glVertex2i(45,45);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(130,40);
    glVertex2i(135,40);
    glVertex2i(135,45);
    glVertex2i(130,45);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(135,40);
    glVertex2i(290,40);
    glVertex2i(290,45);
    glVertex2i(135,45);
    glEnd();

     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(290,40);
    glVertex2i(375,40);
    glVertex2i(375,45);
    glVertex2i(290,45);
    glEnd();

   setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(375,40);
    glVertex2i(445,40);
    glVertex2i(445,45);
    glVertex2i(375,45);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(445,40);
    glVertex2i(450,40);
    glVertex2i(450,45);
    glVertex2i(445,45);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(450,40);
    glVertex2i(475,40);
    glVertex2i(475,45);
    glVertex2i(450,45);
    glEnd();

  setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(475,40);
    glVertex2i(510,40);
    glVertex2i(510,45);
    glVertex2i(475,45);
    glEnd();


    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(510,40);
    glVertex2i(535,40);
    glVertex2i(535,45);
    glVertex2i(510,45);
    glEnd();

  setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,40);
    glVertex2i(585,40);
    glVertex2i(585,45);
    glVertex2i(535,45);
    glEnd();

setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(585,40);
    glVertex2i(640,40);
    glVertex2i(640,45);
    glVertex2i(585,45);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(585,40);
    glVertex2i(765,40);
    glVertex2i(765,45);
    glVertex2i(585,45);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(765,40);
    glVertex2i(1000,40);
    glVertex2i(1000,45);
    glVertex2i(765,45);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1000,40);
    glVertex2i(1045,40);
    glVertex2i(1045,45);
    glVertex2i(1000,45);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1025,40);
    glVertex2i(1030,40);
    glVertex2i(1030,45);
    glVertex2i(1025,45);
    glEnd();


    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1045,40);
    glVertex2i(1200,40);
    glVertex2i(1200,45);
    glVertex2i(1045,45);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1200,40);
    glVertex2i(1205,40);
    glVertex2i(1205,45);
    glVertex2i(1200,45);
    glEnd();

  setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1205,40);
    glVertex2i(1235,40);
    glVertex2i(1235,45);
    glVertex2i(1205,45);
    glEnd();


  setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1235,40);
    glVertex2i(1240,40);
    glVertex2i(1240,45);
    glVertex2i(1235,45);
    glEnd();


  setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1240,40);
    glVertex2i(1245,40);
    glVertex2i(1245,45);
    glVertex2i(1240,45);
    glEnd();

      setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1245,40);
    glVertex2i(1250,40);
    glVertex2i(1250,45);
    glVertex2i(1245,45);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1250,40);
    glVertex2i(1255,40);
    glVertex2i(1255,45);
    glVertex2i(1250,45);
    glEnd();

  setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1255,40);
    glVertex2i(1260,40);
    glVertex2i(1260,45);
    glVertex2i(1255,45);
    glEnd();

      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1260,40);
    glVertex2i(1265,40);
    glVertex2i(1265,45);
    glVertex2i(1260,45);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1265,40);
    glVertex2i(1272,40);
    glVertex2i(1272,45);
    glVertex2i(1265,45);
    glEnd();

  setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1272,40);
    glVertex2i(1280,40);
    glVertex2i(1280,45);
    glVertex2i(1272,45);
    glEnd();

    glPopMatrix();
//2nd line
    glPushMatrix();
    glTranslatef(evenReflectionPosition,0,0);

   setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,35);
    glVertex2i(10,35);
    glVertex2i(10,40);
    glVertex2i(0,40);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(10,35);
    glVertex2i(25,35);
    glVertex2i(25,40);
    glVertex2i(10,40);
    glEnd();

      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(25,35);
    glVertex2i(30,35);
    glVertex2i(30,40);
    glVertex2i(25,40);
    glEnd();

        setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(30,35);
    glVertex2i(35,35);
    glVertex2i(35,40);
    glVertex2i(30,40);
    glEnd();

            setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(35,35);
    glVertex2i(40,35);
    glVertex2i(40,40);
    glVertex2i(35,40);
    glEnd();

          setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(40,35);
    glVertex2i(60,35);
    glVertex2i(60,40);
    glVertex2i(40,40);
    glEnd();


        setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(60,35);
    glVertex2i(75,35);
    glVertex2i(75,40);
    glVertex2i(60,40);
    glEnd();


        setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(75,35);
    glVertex2i(90,35);
    glVertex2i(90,40);
    glVertex2i(75,40);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(90,35);
    glVertex2i(105,35);
    glVertex2i(105,40);
    glVertex2i(90,40);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(105,35);
    glVertex2i(370,35);
    glVertex2i(370,40);
    glVertex2i(105,40);
    glEnd();

      setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(370,35);
    glVertex2i(380,35);
    glVertex2i(380,40);
    glVertex2i(370,40);
    glEnd();
        setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(380,35);
    glVertex2i(425,35);
    glVertex2i(425,40);
    glVertex2i(380,40);
    glEnd();

        setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(425,35);
    glVertex2i(445,35);
    glVertex2i(445,40);
    glVertex2i(425,40);
    glEnd();

  setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(445,35);
    glVertex2i(470,35);
    glVertex2i(470,40);
    glVertex2i(445,40);
    glEnd();

     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(470,35);
    glVertex2i(500,35);
    glVertex2i(500,40);
    glVertex2i(470,40);
    glEnd();
       setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(505,35);
    glVertex2i(530,35);
    glVertex2i(530,40);
    glVertex2i(505,40);
    glEnd();

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,35);
    glVertex2i(540,35);
    glVertex2i(540,40);
    glVertex2i(535,40);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,35);
    glVertex2i(555,35);
    glVertex2i(555,40);
    glVertex2i(545,40);
    glEnd();

     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(555,35);
    glVertex2i(560,35);
    glVertex2i(560,40);
    glVertex2i(555,40);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(565,35);
    glVertex2i(595,35);
    glVertex2i(595,40);
    glVertex2i(565,40);
    glEnd();

        setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(600,35);
    glVertex2i(650,35);
    glVertex2i(650,40);
    glVertex2i(600,40);
    glEnd();

       setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(650,35);
    glVertex2i(655,35);
    glVertex2i(655,40);
    glVertex2i(650,40);
    glEnd();

      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(655,35);
    glVertex2i(700,35);
    glVertex2i(700,40);
    glVertex2i(655,40);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(700,35);
    glVertex2i(705,35);
    glVertex2i(705,40);
    glVertex2i(700,40);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(705,35);
    glVertex2i(750,35);
    glVertex2i(750,40);
    glVertex2i(705,40);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(750,35);
    glVertex2i(765,35);
    glVertex2i(765,40);
    glVertex2i(750,40);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(765,35);
    glVertex2i(795,35);
    glVertex2i(795,40);
    glVertex2i(765,40);
    glEnd();

     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(810,35);
    glVertex2i(960,35);
    glVertex2i(960,40);
    glVertex2i(810,40);
    glEnd();

          setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(975,35);
    glVertex2i(1025,35);
    glVertex2i(1025,40);
    glVertex2i(975,40);
    glEnd();


     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1025,35);
    glVertex2i(1035,35);
    glVertex2i(1035,40);
    glVertex2i(1025,40);
    glEnd();
       setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1035,35);
    glVertex2i(1045,35);
    glVertex2i(1045,40);
    glVertex2i(1035,40);
    glEnd();

     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1045,35);
    glVertex2i(1050,35);
    glVertex2i(1050,40);
    glVertex2i(1045,40);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1050,35);
    glVertex2i(1055,35);
    glVertex2i(1055,40);
    glVertex2i(1050,40);
    glEnd();

 setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1055,35);
    glVertex2i(1060,35);
    glVertex2i(1060,40);
    glVertex2i(1055,40);
    glEnd();

     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1060,35);
    glVertex2i(1065,35);
    glVertex2i(1065,40);
    glVertex2i(1060,40);
    glEnd();

     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1065,35);
    glVertex2i(1070,35);
    glVertex2i(1070,40);
    glVertex2i(1065,40);
    glEnd();

setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1070,35);
    glVertex2i(1080,35);
    glVertex2i(1080,40);
    glVertex2i(1070,40);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1080,35);
    glVertex2i(1085,35);
    glVertex2i(1085,40);
    glVertex2i(1080,40);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1085,35);
    glVertex2i(1115,35);
    glVertex2i(1115,40);
    glVertex2i(1085,40);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1115,35);
    glVertex2i(1120,35);
    glVertex2i(1120,40);
    glVertex2i(1115,40);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1120,35);
    glVertex2i(1130,35);
    glVertex2i(1130,40);
    glVertex2i(1120,40);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1130,35);
    glVertex2i(1135,35);
    glVertex2i(1135,40);
    glVertex2i(1130,40);
    glEnd();

setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1135,35);
    glVertex2i(1145,35);
    glVertex2i(1145,40);
    glVertex2i(1135,40);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1145,35);
    glVertex2i(1150,35);
    glVertex2i(1150,40);
    glVertex2i(1145,40);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1150,35);
    glVertex2i(1160,35);
    glVertex2i(1160,40);
    glVertex2i(1150,40);
    glEnd();

 setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1160,35);
    glVertex2i(1165,35);
    glVertex2i(1165,40);
    glVertex2i(1160,40);
    glEnd();

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1165,35);
    glVertex2i(1175,35);
    glVertex2i(1175,40);
    glVertex2i(1165,40);
    glEnd();

    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1175,35);
    glVertex2i(1180,35);
    glVertex2i(1180,40);
    glVertex2i(1175,40);
    glEnd();
        setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1180,35);
    glVertex2i(1190,35);
    glVertex2i(1190,40);
    glVertex2i(1180,40);
    glEnd();

     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1190,35);
    glVertex2i(1195,35);
    glVertex2i(1195,40);
    glVertex2i(1190,40);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1195,35);
    glVertex2i(1200,35);
    glVertex2i(1200,40);
    glVertex2i(1195,40);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1200,35);
    glVertex2i(1205,35);
    glVertex2i(1205,40);
    glVertex2i(1200,40);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1205,35);
    glVertex2i(1210,35);
    glVertex2i(1210,40);
    glVertex2i(1205,40);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1210,35);
    glVertex2i(1215,35);
    glVertex2i(1215,40);
    glVertex2i(1210,40);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1215,35);
    glVertex2i(1225,35);
    glVertex2i(1225,40);
    glVertex2i(1215,40);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1225,35);
    glVertex2i(1235,35);
    glVertex2i(1235,40);
    glVertex2i(1225,40);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1235,35);
    glVertex2i(1250,35);
    glVertex2i(1250,40);
    glVertex2i(1235,40);
    glEnd();

     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1255,35);
    glVertex2i(1270,35);
    glVertex2i(1270,40);
    glVertex2i(1255,40);
    glEnd();

setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1270,35);
    glVertex2i(1280,35);
    glVertex2i(1280,40);
    glVertex2i(1270,40);
    glEnd();

    glPopMatrix();


    //3rd line

    glPushMatrix();
    glTranslatef(oddReflectionPosition,0,0);

setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(0,30);
    glVertex2i(25,30);
    glVertex2i(25,35);
    glVertex2i(0,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(25,30);
    glVertex2i(30,30);
    glVertex2i(30,35);
    glVertex2i(25,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(30,30);
    glVertex2i(115,30);
    glVertex2i(115,35);
    glVertex2i(30,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(115,30);
    glVertex2i(120,30);
    glVertex2i(120,35);
    glVertex2i(115,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(120,30);
    glVertex2i(125,30);
    glVertex2i(125,35);
    glVertex2i(120,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(125,30);
    glVertex2i(130,30);
    glVertex2i(130,35);
    glVertex2i(125,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(130,30);
    glVertex2i(135,30);
    glVertex2i(135,35);
    glVertex2i(130,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(135,30);
    glVertex2i(140,30);
    glVertex2i(140,35);
    glVertex2i(135,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(140,30);
    glVertex2i(150,30);
    glVertex2i(150,35);
    glVertex2i(140,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(150,30);
    glVertex2i(155,30);
    glVertex2i(155,35);
    glVertex2i(150,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(155,30);
    glVertex2i(165,30);
    glVertex2i(165,35);
    glVertex2i(155,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(165,30);
    glVertex2i(170,30);
    glVertex2i(170,35);
    glVertex2i(165,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(170,30);
    glVertex2i(185,30);
    glVertex2i(185,35);
    glVertex2i(170,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(185,30);
    glVertex2i(190,30);
    glVertex2i(190,35);
    glVertex2i(185,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(190,30);
    glVertex2i(200,30);
    glVertex2i(200,35);
    glVertex2i(190,35);
    glEnd();

 setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(200,30);
    glVertex2i(205,30);
    glVertex2i(205,35);
    glVertex2i(200,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(205,30);
    glVertex2i(225,30);
    glVertex2i(225,35);
    glVertex2i(205,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(225,30);
    glVertex2i(230,30);
    glVertex2i(230,35);
    glVertex2i(225,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(230,30);
    glVertex2i(240,30);
    glVertex2i(240,35);
    glVertex2i(230,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(240,30);
    glVertex2i(245,30);
    glVertex2i(245,35);
    glVertex2i(240,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,30);
    glVertex2i(250,30);
    glVertex2i(250,35);
    glVertex2i(245,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(250,30);
    glVertex2i(255,30);
    glVertex2i(255,35);
    glVertex2i(250,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(255,30);
    glVertex2i(260,30);
    glVertex2i(260,35);
    glVertex2i(255,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(260,30);
    glVertex2i(270,30);
    glVertex2i(270,35);
    glVertex2i(260,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(270,30);
    glVertex2i(275,30);
    glVertex2i(275,35);
    glVertex2i(270,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(275,30);
    glVertex2i(285,30);
    glVertex2i(285,35);
    glVertex2i(275,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(285,30);
    glVertex2i(290,30);
    glVertex2i(290,35);
    glVertex2i(285,35);
    glEnd();
      setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(290,30);
    glVertex2i(295,30);
    glVertex2i(295,35);
    glVertex2i(290,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(295,30);
    glVertex2i(300,30);
    glVertex2i(300,35);
    glVertex2i(295,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(300,30);
    glVertex2i(310,30);
    glVertex2i(310,35);
    glVertex2i(300,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(310,30);
    glVertex2i(315,30);
    glVertex2i(315,35);
    glVertex2i(310,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(315,30);
    glVertex2i(325,30);
    glVertex2i(325,35);
    glVertex2i(315,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(325,30);
    glVertex2i(330,30);
    glVertex2i(330,35);
    glVertex2i(325,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(330,30);
    glVertex2i(335,30);
    glVertex2i(335,35);
    glVertex2i(330,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(335,30);
    glVertex2i(340,30);
    glVertex2i(340,35);
    glVertex2i(335,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(340,30);
    glVertex2i(345,30);
    glVertex2i(345,35);
    glVertex2i(340,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(345,30);
    glVertex2i(355,30);
    glVertex2i(355,35);
    glVertex2i(345,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(355,30);
    glVertex2i(360,30);
    glVertex2i(360,35);
    glVertex2i(355,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(360,30);
    glVertex2i(370,30);
    glVertex2i(370,35);
    glVertex2i(360,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(380,30);
    glVertex2i(445,30);
    glVertex2i(445,35);
    glVertex2i(380,35);
    glEnd();
      setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(445,30);
    glVertex2i(470,30);
    glVertex2i(470,35);
    glVertex2i(445,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(470,30);
    glVertex2i(500,30);
    glVertex2i(500,35);
    glVertex2i(470,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(505,30);
    glVertex2i(530,30);
    glVertex2i(530,35);
    glVertex2i(505,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,30);
    glVertex2i(545,30);
    glVertex2i(545,35);
    glVertex2i(535,35);
    glEnd();
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,30);
    glVertex2i(555,30);
    glVertex2i(555,35);
    glVertex2i(545,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(555,30);
    glVertex2i(565,30);
    glVertex2i(565,35);
    glVertex2i(555,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(575,30);
    glVertex2i(580,30);
    glVertex2i(580,35);
    glVertex2i(575,35);
    glEnd();
      setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(590,30);
    glVertex2i(595,30);
    glVertex2i(595,35);
    glVertex2i(590,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(595,30);
    glVertex2i(605,30);
    glVertex2i(605,35);
    glVertex2i(595,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(605,30);
    glVertex2i(615,30);
    glVertex2i(615,35);
    glVertex2i(605,35);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(615,30);
    glVertex2i(620,30);
    glVertex2i(620,35);
    glVertex2i(615,35);
    glEnd();
       setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(620,30);
    glVertex2i(625,30);
    glVertex2i(625,35);
    glVertex2i(620,35);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(625,30);
    glVertex2i(630,30);
    glVertex2i(630,35);
    glVertex2i(625,35);
    glEnd();
      setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(630,30);
    glVertex2i(665,30);
    glVertex2i(665,35);
    glVertex2i(630,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(665,30);
    glVertex2i(690,30);
    glVertex2i(690,35);
    glVertex2i(665,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(690,30);
    glVertex2i(720,30);
    glVertex2i(720,35);
    glVertex2i(690,35);
    glEnd();
       setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(720,30);
    glVertex2i(745,30);
    glVertex2i(745,35);
    glVertex2i(720,35);
    glEnd();
      setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(745,30);
    glVertex2i(795,30);
    glVertex2i(795,35);
    glVertex2i(745,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(795,30);
    glVertex2i(800,30);
    glVertex2i(800,35);
    glVertex2i(795,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(800,30);
    glVertex2i(810,30);
    glVertex2i(810,35);
    glVertex2i(800,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(810,30);
    glVertex2i(815,30);
    glVertex2i(815,35);
    glVertex2i(810,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,30);
    glVertex2i(825,30);
    glVertex2i(825,35);
    glVertex2i(815,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(825,30);
    glVertex2i(830,30);
    glVertex2i(830,35);
    glVertex2i(825,35);
    glEnd();
setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(830,30);
    glVertex2i(840,30);
    glVertex2i(840,35);
    glVertex2i(830,35);
    glEnd();
setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(840,30);
    glVertex2i(845,30);
    glVertex2i(845,35);
    glVertex2i(840,35);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(845,30);
    glVertex2i(855,30);
    glVertex2i(855,35);
    glVertex2i(845,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(855,30);
    glVertex2i(860,30);
    glVertex2i(860,35);
    glVertex2i(855,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(860,30);
    glVertex2i(880,30);
    glVertex2i(880,35);
    glVertex2i(860,35);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(880,30);
    glVertex2i(910,30);
    glVertex2i(910,35);
    glVertex2i(880,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(910,30);
    glVertex2i(915,30);
    glVertex2i(915,35);
    glVertex2i(910,35);
    glEnd();
      setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(915,30);
    glVertex2i(925,30);
    glVertex2i(925,35);
    glVertex2i(915,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(925,30);
    glVertex2i(965,30);
    glVertex2i(965,35);
    glVertex2i(925,35);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(965,30);
    glVertex2i(1045,30);
    glVertex2i(1045,35);
    glVertex2i(965,35);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1045,30);
    glVertex2i(1085,30);
    glVertex2i(1085,35);
    glVertex2i(1045,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1085,30);
    glVertex2i(1090,30);
    glVertex2i(1090,35);
    glVertex2i(1085,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1090,30);
    glVertex2i(1095,30);
    glVertex2i(1095,35);
    glVertex2i(1090,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1095,30);
    glVertex2i(1105,30);
    glVertex2i(1105,35);
    glVertex2i(1095,35);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1105,30);
    glVertex2i(1110,30);
    glVertex2i(1110,35);
    glVertex2i(1105,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1110,30);
    glVertex2i(1115,30);
    glVertex2i(1115,35);
    glVertex2i(1110,35);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1115,30);
    glVertex2i(1195,30);
    glVertex2i(1195,35);
    glVertex2i(1115,35);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1195,30);
    glVertex2i(1280,30);
    glVertex2i(1280,35);
    glVertex2i(1195,35);
    glEnd();

    glPopMatrix();
    //4th line
    glPushMatrix();
    glTranslatef(evenReflectionPosition,0,0);
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(0,25);
    glVertex2i(110,25);
    glVertex2i(110,30);
    glVertex2i(0,30);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(110,25);
    glVertex2i(170,25);
    glVertex2i(170,30);
    glVertex2i(110,30);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(170,25);
    glVertex2i(175,25);
    glVertex2i(175,30);
    glVertex2i(170,30);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(175,25);
    glVertex2i(195,25);
    glVertex2i(195,30);
    glVertex2i(175,30);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(195,25);
    glVertex2i(205,25);
    glVertex2i(205,30);
    glVertex2i(195,30);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(205,25);
    glVertex2i(260,25);
    glVertex2i(260,30);
    glVertex2i(205,30);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(265,25);
    glVertex2i(275,25);
    glVertex2i(275,30);
    glVertex2i(265,30);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(275,25);
    glVertex2i(280,25);
    glVertex2i(280,30);
    glVertex2i(275,30);
    glEnd();
     setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(280,25);
    glVertex2i(340,25);
    glVertex2i(340,30);
    glVertex2i(280,30);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(280,25);
    glVertex2i(340,25);
    glVertex2i(340,30);
    glVertex2i(280,30);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(340,25);
    glVertex2i(350,25);
    glVertex2i(350,30);
    glVertex2i(340,30);
    glEnd();
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(350,25);
    glVertex2i(360,25);
    glVertex2i(360,30);
    glVertex2i(350,30);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(360,25);
    glVertex2i(365,25);
    glVertex2i(365,30);
    glVertex2i(360,30);
    glEnd();
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(365,25);
    glVertex2i(370,25);
    glVertex2i(370,30);
    glVertex2i(365,30);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(370,25);
    glVertex2i(400,25);
    glVertex2i(400,30);
    glVertex2i(370,30);
    glEnd();

setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(400,25);
    glVertex2i(425,25);
    glVertex2i(425,30);
    glVertex2i(400,30);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(425,25);
    glVertex2i(435,25);
    glVertex2i(435,30);
    glVertex2i(425,30);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(435,25);
    glVertex2i(445,25);
    glVertex2i(445,30);
    glVertex2i(435,30);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(445,25);
    glVertex2i(470,25);
    glVertex2i(470,30);
    glVertex2i(445,30);
    glEnd();
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(470,25);
    glVertex2i(490,25);
    glVertex2i(490,30);
    glVertex2i(470,30);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(490,25);
    glVertex2i(500,25);
    glVertex2i(500,30);
    glVertex2i(490,30);
    glEnd();
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(500,25);
    glVertex2i(505,25);
    glVertex2i(505,30);
    glVertex2i(500,30);
    glEnd();
      setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(505,25);
    glVertex2i(530,25);
    glVertex2i(530,30);
    glVertex2i(505,30);
    glEnd();
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(530,25);
    glVertex2i(620,25);
    glVertex2i(620,30);
    glVertex2i(530,30);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,25);
    glVertex2i(640,25);
    glVertex2i(640,30);
    glVertex2i(635,30);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(640,25);
    glVertex2i(650,25);
    glVertex2i(650,30);
    glVertex2i(640,30);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(650,25);
    glVertex2i(655,25);
    glVertex2i(655,30);
    glVertex2i(650,30);
    glEnd();
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(655,25);
    glVertex2i(660,25);
    glVertex2i(660,30);
    glVertex2i(655,30);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(665,25);
    glVertex2i(690,25);
    glVertex2i(690,30);
    glVertex2i(665,30);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(690,25);
    glVertex2i(700,25);
    glVertex2i(700,30);
    glVertex2i(690,30);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(700,25);
    glVertex2i(705,25);
    glVertex2i(705,30);
    glVertex2i(700,30);
    glEnd();
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(705,25);
    glVertex2i(715,25);
    glVertex2i(715,30);
    glVertex2i(705,30);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(715,25);
    glVertex2i(720,25);
    glVertex2i(720,30);
    glVertex2i(715,30);
    glEnd();
      setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(720,25);
    glVertex2i(745,25);
    glVertex2i(745,30);
    glVertex2i(720,30);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(745,25);
    glVertex2i(795,25);
    glVertex2i(795,30);
    glVertex2i(745,30);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(795,25);
    glVertex2i(875,25);
    glVertex2i(875,30);
    glVertex2i(795,30);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(875,25);
    glVertex2i(895,25);
    glVertex2i(895,30);
    glVertex2i(875,30);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(905,25);
    glVertex2i(935,25);
    glVertex2i(935,30);
    glVertex2i(905,30);
    glEnd();
       setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(905,25);
    glVertex2i(1070,25);
    glVertex2i(1070,30);
    glVertex2i(905,30);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1070,25);
    glVertex2i(1090,25);
    glVertex2i(1090,30);
    glVertex2i(1070,30);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1090,25);
    glVertex2i(1280,25);
    glVertex2i(1280,30);
    glVertex2i(1090,30);
    glEnd();

    glPopMatrix();
//5th line
    glPushMatrix();
    glTranslatef(oddReflectionPosition,0,0);

setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(0,20);
    glVertex2i(175,20);
    glVertex2i(175,25);
    glVertex2i(0,25);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(175,20);
    glVertex2i(180,20);
    glVertex2i(180,25);
    glVertex2i(175,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(180,20);
    glVertex2i(190,20);
    glVertex2i(190,25);
    glVertex2i(180,25);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(190,20);
    glVertex2i(195,20);
    glVertex2i(195,25);
    glVertex2i(190,25);
    glEnd();
      setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(195,20);
    glVertex2i(200,20);
    glVertex2i(200,25);
    glVertex2i(195,25);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(200,20);
    glVertex2i(225,20);
    glVertex2i(225,25);
    glVertex2i(200,25);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,20);
    glVertex2i(245,20);
    glVertex2i(245,25);
    glVertex2i(225,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(245,20);
    glVertex2i(270,20);
    glVertex2i(270,25);
    glVertex2i(245,25);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(270,20);
    glVertex2i(305,20);
    glVertex2i(305,25);
    glVertex2i(270,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(305,20);
    glVertex2i(330,20);
    glVertex2i(330,25);
    glVertex2i(305,25);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(330,20);
    glVertex2i(445,20);
    glVertex2i(445,25);
    glVertex2i(330,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(445,20);
    glVertex2i(470,20);
    glVertex2i(470,25);
    glVertex2i(445,25);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(470,20);
    glVertex2i(505,20);
    glVertex2i(505,25);
    glVertex2i(470,25);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(505,20);
    glVertex2i(530,20);
    glVertex2i(530,25);
    glVertex2i(505,25);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(530,20);
    glVertex2i(635,20);
    glVertex2i(635,25);
    glVertex2i(530,25);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,20);
    glVertex2i(665,20);
    glVertex2i(665,25);
    glVertex2i(635,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(665,20);
    glVertex2i(690,20);
    glVertex2i(690,25);
    glVertex2i(665,25);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(690,20);
    glVertex2i(720,20);
    glVertex2i(720,25);
    glVertex2i(690,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(720,20);
    glVertex2i(745,20);
    glVertex2i(745,25);
    glVertex2i(720,25);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(745,20);
    glVertex2i(860,20);
    glVertex2i(860,25);
    glVertex2i(745,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(860,20);
    glVertex2i(885,20);
    glVertex2i(885,25);
    glVertex2i(860,25);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(885,20);
    glVertex2i(920,20);
    glVertex2i(920,25);
    glVertex2i(885,25);
    glEnd();
      setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(920,20);
    glVertex2i(1070,20);
    glVertex2i(1070,25);
    glVertex2i(920,25);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1070,20);
    glVertex2i(1075,20);
    glVertex2i(1075,25);
    glVertex2i(1070,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1075,20);
    glVertex2i(1085,20);
    glVertex2i(1085,25);
    glVertex2i(1075,25);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1085,20);
    glVertex2i(1090,20);
    glVertex2i(1090,25);
    glVertex2i(1085,25);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1090,20);
    glVertex2i(1255,20);
    glVertex2i(1255,25);
    glVertex2i(1090,25);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1255,20);
    glVertex2i(1280,20);
    glVertex2i(1280,25);
    glVertex2i(1255,25);
    glEnd();

    glPopMatrix();

    //6th line
    glPushMatrix();
    glTranslatef(evenReflectionPosition,0,0);

setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(0,15);
    glVertex2i(180,15);
    glVertex2i(180,20);
    glVertex2i(0,20);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(180,15);
    glVertex2i(200,15);
    glVertex2i(200,20);
    glVertex2i(180,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(200,15);
    glVertex2i(215,15);
    glVertex2i(215,20);
    glVertex2i(200,20);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(215,15);
    glVertex2i(225,15);
    glVertex2i(225,20);
    glVertex2i(215,20);
    glEnd();
      setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,15);
    glVertex2i(250,15);
    glVertex2i(250,20);
    glVertex2i(225,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(250,15);
    glVertex2i(275,15);
    glVertex2i(275,20);
    glVertex2i(250,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(275,15);
    glVertex2i(310,15);
    glVertex2i(310,20);
    glVertex2i(275,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(310,15);
    glVertex2i(335,15);
    glVertex2i(335,20);
    glVertex2i(310,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(335,15);
    glVertex2i(340,15);
    glVertex2i(340,20);
    glVertex2i(335,20);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(345,15);
    glVertex2i(350,15);
    glVertex2i(350,20);
    glVertex2i(345,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(350,15);
    glVertex2i(450,15);
    glVertex2i(450,20);
    glVertex2i(350,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(450,15);
    glVertex2i(475,15);
    glVertex2i(475,20);
    glVertex2i(450,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,15);
    glVertex2i(510,15);
    glVertex2i(510,20);
    glVertex2i(475,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(510,15);
    glVertex2i(535,15);
    glVertex2i(535,20);
    glVertex2i(510,20);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,15);
    glVertex2i(635,15);
    glVertex2i(635,20);
    glVertex2i(535,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,15);
    glVertex2i(640,15);
    glVertex2i(640,20);
    glVertex2i(635,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(650,15);
    glVertex2i(655,15);
    glVertex2i(655,20);
    glVertex2i(650,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(670,15);
    glVertex2i(695,15);
    glVertex2i(695,20);
    glVertex2i(670,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(705,15);
    glVertex2i(710,15);
    glVertex2i(710,20);
    glVertex2i(705,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(725,15);
    glVertex2i(750,15);
    glVertex2i(750,20);
    glVertex2i(725,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(750,15);
    glVertex2i(865,15);
    glVertex2i(865,20);
    glVertex2i(750,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(865,15);
    glVertex2i(890,15);
    glVertex2i(890,20);
    glVertex2i(865,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(890,15);
    glVertex2i(925,15);
    glVertex2i(925,20);
    glVertex2i(890,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(925,15);
    glVertex2i(1075,15);
    glVertex2i(1075,20);
    glVertex2i(925,20);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1075,15);
    glVertex2i(1095,15);
    glVertex2i(1095,20);
    glVertex2i(1075,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1095,15);
    glVertex2i(1105,15);
    glVertex2i(1105,20);
    glVertex2i(1095,20);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1105,15);
    glVertex2i(1120,15);
    glVertex2i(1120,20);
    glVertex2i(1105,20);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1120,15);
    glVertex2i(1235,15);
    glVertex2i(1235,20);
    glVertex2i(1120,20);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(1235,15);
    glVertex2i(1280,15);
    glVertex2i(1280,20);
    glVertex2i(1235,20);
    glEnd();

    glPopMatrix();
    //7th line
    glPushMatrix();
    glTranslatef(oddReflectionPosition,0,0);

    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(0,10);
    glVertex2i(180,10);
    glVertex2i(180,15);
    glVertex2i(0,15);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(180,10);
    glVertex2i(240,10);
    glVertex2i(240,15);
    glVertex2i(180,15);
    glEnd();
     setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(250,10);
    glVertex2i(275,10);
    glVertex2i(275,15);
    glVertex2i(250,15);
    glEnd();
     setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(275,10);
    glVertex2i(310,10);
    glVertex2i(310,15);
    glVertex2i(275,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(310,10);
    glVertex2i(335,10);
    glVertex2i(335,15);
    glVertex2i(310,15);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(335,10);
    glVertex2i(450,10);
    glVertex2i(450,15);
    glVertex2i(335,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(450,10);
    glVertex2i(475,10);
    glVertex2i(475,15);
    glVertex2i(450,15);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,10);
    glVertex2i(505,10);
    glVertex2i(505,15);
    glVertex2i(475,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(510,10);
    glVertex2i(535,10);
    glVertex2i(535,15);
    glVertex2i(510,15);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,10);
    glVertex2i(635,10);
    glVertex2i(635,15);
    glVertex2i(535,15);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,10);
    glVertex2i(670,10);
    glVertex2i(670,15);
    glVertex2i(635,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(670,10);
    glVertex2i(695,10);
    glVertex2i(695,15);
    glVertex2i(670,15);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(695,10);
    glVertex2i(725,10);
    glVertex2i(725,15);
    glVertex2i(695,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(725,10);
    glVertex2i(750,10);
    glVertex2i(750,15);
    glVertex2i(725,15);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(750,10);
    glVertex2i(855,10);
    glVertex2i(855,15);
    glVertex2i(750,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(865,10);
    glVertex2i(895,10);
    glVertex2i(895,15);
    glVertex2i(865,15);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(895,10);
    glVertex2i(925,10);
    glVertex2i(925,15);
    glVertex2i(895,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(925,10);
    glVertex2i(965,10);
    glVertex2i(965,15);
    glVertex2i(925,15);
    glEnd();
    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(965,10);
    glVertex2i(1005,10);
    glVertex2i(1005,15);
    glVertex2i(965,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1005,10);
    glVertex2i(1075,10);
    glVertex2i(1075,15);
    glVertex2i(1005,15);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1075,10);
    glVertex2i(1080,10);
    glVertex2i(1080,15);
    glVertex2i(1075,15);
    glEnd();
      setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1080,10);
    glVertex2i(1090,10);
    glVertex2i(1090,15);
    glVertex2i(1080,15);
    glEnd();
    setColor("iceBlue");
    glBegin(GL_QUADS);
    glVertex2i(1090,10);
    glVertex2i(1095,10);
    glVertex2i(1095,15);
    glVertex2i(1090,15);
    glEnd();
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(1095,10);
    glVertex2i(1280,10);
    glVertex2i(1280,15);
    glVertex2i(1095,15);
    glEnd();

    glPopMatrix();
    //8th line
    glPushMatrix();
    glTranslatef(evenReflectionPosition,0,0);

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,5);
    glVertex2i(1280,5);
    glVertex2i(1280,10);
    glVertex2i(0,10);
    glEnd();

    glPopMatrix();

    //9th line
    setColor("reflectionDark");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,5);
    glVertex2i(0,5);
    glEnd();


}

void drawtree(){
    glPointSize(5.0);

    //start of color and drawing


    setColor("tree");
    glBegin(GL_QUADS);
    glVertex2i(1265,565);
    glVertex2i(1280,565);
    glVertex2i(1280,525);
    glVertex2i(1265,525);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1260,560);
    glVertex2i(1270,560);
    glVertex2i(1270,520);
    glVertex2i(1260,520);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1255,555);
    glVertex2i(1260,555);
    glVertex2i(1260,515);
    glVertex2i(1255,515);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1210,550);
    glVertex2i(1260,550);
    glVertex2i(1260,520);
    glVertex2i(1210,520);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1200,555);
    glVertex2i(1210,555);
    glVertex2i(1210,525);
    glVertex2i(1200,525);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2i(1190,560);
    glVertex2i(1200,560);
    glVertex2i(1200,530);
    glVertex2i(1190,530);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1160,565);
    glVertex2i(1190,565);
    glVertex2i(1190,535);
    glVertex2i(1160,535);
    glEnd();

//br down
     glBegin(GL_QUADS);
    glVertex2i(1150,555);
    glVertex2i(1160,555);
    glVertex2i(1160,530);
    glVertex2i(1150,530);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1140,550);
    glVertex2i(1150,550);
    glVertex2i(1150,525);
    glVertex2i(1140,525);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1130,545);
    glVertex2i(1140,545);
    glVertex2i(1140,520);
    glVertex2i(1130,520);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2i(1120,540);
    glVertex2i(1130,540);
    glVertex2i(1130,515);
    glVertex2i(1120,515);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1100,535);
    glVertex2i(1120,535);
    glVertex2i(1120,510);
    glVertex2i(1100,510);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1090,530);
    glVertex2i(1100,530);
    glVertex2i(1100,505);
    glVertex2i(1090,505);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1080,525);
    glVertex2i(1090,525);
    glVertex2i(1090,500);
    glVertex2i(1080,500);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1070,520);
    glVertex2i(1080,520);
    glVertex2i(1080,495);
    glVertex2i(1070,495);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1030,515);
    glVertex2i(1070,515);
    glVertex2i(1070,490);
    glVertex2i(1030,490);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(990,510);
    glVertex2i(1030,510);
    glVertex2i(1030,485);
    glVertex2i(990,485);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(950,515);
    glVertex2i(990,515);
    glVertex2i(990,490);
    glVertex2i(950,490);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(910,520);
    glVertex2i(950,520);
    glVertex2i(950,495);
    glVertex2i(910,495);
    glEnd();


    //br up2

    glBegin(GL_QUADS);
    glVertex2i(900,525);
    glVertex2i(910,525);
    glVertex2i(910,510);
    glVertex2i(900,510);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,530);
    glVertex2i(900,530);
    glVertex2i(900,515);
    glVertex2i(890,515);
    glEnd();


     glBegin(GL_QUADS);
    glVertex2i(870,535);
    glVertex2i(890,535);
    glVertex2i(890,520);
    glVertex2i(870,520);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2i(850,540);
    glVertex2i(870,540);   //add br
    glVertex2i(870,530);
    glVertex2i(850,530);
    glEnd();


     glBegin(GL_QUADS);
    glVertex2i(820,545);
    glVertex2i(850,545);   //add br
    glVertex2i(850,535);
    glVertex2i(820,535);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(800,550);
    glVertex2i(820,550);   //add br
    glVertex2i(820,540);
    glVertex2i(800,540);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(760,555);
    glVertex2i(800,555);   //add br
    glVertex2i(800,545);
    glVertex2i(760,545);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(740,555);
    glVertex2i(760,555);   //add br
    glVertex2i(760,550);
    glVertex2i(740,550);
    glEnd();



    //br down2

    glBegin(GL_QUADS);
    glVertex2i(900,515);
    glVertex2i(910,515);
    glVertex2i(910,490);
    glVertex2i(900,490);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,510);
    glVertex2i(900,510);
    glVertex2i(900,490);
    glVertex2i(890,490);
    glEnd();

//div
    glBegin(GL_QUADS);
    glVertex2i(880,505);
    glVertex2i(890,505);
    glVertex2i(890,485);
    glVertex2i(880,485);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(870,500);
    glVertex2i(880,500);            //L
    glVertex2i(880,480);
    glVertex2i(870,480);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(850,500);
    glVertex2i(870,500);
    glVertex2i(870,485);             //l
    glVertex2i(850,485);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(840,495);
    glVertex2i(850,495);             //L
    glVertex2i(850,480);
    glVertex2i(840,480);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2i(820,490);
    glVertex2i(840,490);
    glVertex2i(840,480);               //L
    glVertex2i(820,480);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(800,485);
    glVertex2i(820,485);              //l
    glVertex2i(820,480);
    glVertex2i(800,480);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(790,480);
    glVertex2i(800,480);              //l
    glVertex2i(800,485);
    glVertex2i(790,485);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(760,475);
    glVertex2i(790,475);              //l
    glVertex2i(790,480);
    glVertex2i(760,480);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(740,470);
    glVertex2i(760,470);              //l
    glVertex2i(760,475);
    glVertex2i(740,475);
    glEnd();




    //branch


    glBegin(GL_QUADS);
    glVertex2i(1080,530);
    glVertex2i(1095,530);
    glVertex2i(1095,535);
    glVertex2i(1080,535);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1070,535);
    glVertex2i(1085,535);
    glVertex2i(1085,540);
    glVertex2i(1070,540);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1060,540);
    glVertex2i(1075,540);
    glVertex2i(1075,545);
    glVertex2i(1060,545);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1050,545);
    glVertex2i(1065,545);
    glVertex2i(1065,550);
    glVertex2i(1050,550);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1035,550);
    glVertex2i(1055,550);
    glVertex2i(1055,555);
    glVertex2i(1035,555);
    glEnd();










    //br up
    glBegin(GL_QUADS);
    glVertex2i(1150,575);
    glVertex2i(1160,575);
    glVertex2i(1160,545);
    glVertex2i(1150,545);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1140,580);
    glVertex2i(1150,580);
    glVertex2i(1150,550);
    glVertex2i(1140,550);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1130,585);
    glVertex2i(1140,585);
    glVertex2i(1140,555);
    glVertex2i(1130,555);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1120,590);
    glVertex2i(1130,590);
    glVertex2i(1130,560);
    glVertex2i(1120,560);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1115,595);
    glVertex2i(1120,595);
    glVertex2i(1120,565);
    glVertex2i(1115,565);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1090,600);
    glVertex2i(1115,600);
    glVertex2i(1115,580);
    glVertex2i(1090,580);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1060,605);
    glVertex2i(1090,605);
    glVertex2i(1090,590);
    glVertex2i(1060,590);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1030,610);
    glVertex2i(1060,610);
    glVertex2i(1060,600);
    glVertex2i(1030,600);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1055,600);
    glVertex2i(1060,600);
    glVertex2i(1060,630);
    glVertex2i(1055,630);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1050,605);
    glVertex2i(1055,605);
    glVertex2i(1050,635);
    glVertex2i(1055,635);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1010,615);
    glVertex2i(1030,615);
    glVertex2i(1030,605);
    glVertex2i(1010,605);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1000,615);
    glVertex2i(1020,615);
    glVertex2i(1020,620);
    glVertex2i(1000,620);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(980,620);
    glVertex2i(1005,620);
    glVertex2i(1005,625);
    glVertex2i(980,625);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(940,625);
    glVertex2i(990,625);
    glVertex2i(990,630);
    glVertex2i(940,630);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(920,620);
    glVertex2i(945,620);
    glVertex2i(945,625);
    glVertex2i(920,625);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(900,615);
    glVertex2i(925,615);
    glVertex2i(925,620);
    glVertex2i(900,620);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(980,630);
    glVertex2i(990,630);
    glVertex2i(990,635);
    glVertex2i(980,635);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(970,635);
    glVertex2i(985,635);
    glVertex2i(985,640);
    glVertex2i(970,640);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(960,640);
    glVertex2i(975,640);
    glVertex2i(975,645);
    glVertex2i(960,645);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(950,645);
    glVertex2i(965,645);
    glVertex2i(965,650);
    glVertex2i(950,650);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2i(920,650);
    glVertex2i(955,650);
    glVertex2i(955,655);
    glVertex2i(920,655);
    glEnd();


    //tree 2nd part


    glBegin(GL_QUADS);
    glVertex2i(1265,480);
    glVertex2i(1280,480);
    glVertex2i(1280,440);
    glVertex2i(1265,440);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1250,475);
    glVertex2i(1265,475);
    glVertex2i(1265,435);
    glVertex2i(1250,435);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1230,470);
    glVertex2i(1250,470);
    glVertex2i(1250,430);
    glVertex2i(1230,430);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1210,465);
    glVertex2i(1230,465);
    glVertex2i(1230,425);
    glVertex2i(1210,425);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1190,445);
    glVertex2i(1220,445);
    glVertex2i(1220,415);
    glVertex2i(1190,415);
    glEnd();


glBegin(GL_QUADS);
    glVertex2i(1160,435);
    glVertex2i(1190,435);
    glVertex2i(1190,410);
    glVertex2i(1160,410);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(1130,425);
    glVertex2i(1160,425);
    glVertex2i(1160,405);
    glVertex2i(1130,405);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1100,415);
    glVertex2i(1130,415);
    glVertex2i(1130,400);
    glVertex2i(1100,400);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1070,405);
    glVertex2i(1100,405);
    glVertex2i(1100,395);
    glVertex2i(1070,395);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1040,395);
    glVertex2i(1070,395);
    glVertex2i(1070,390);
    glVertex2i(1040,390);
    glEnd();







     //leaf
    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(1090,545);
    glVertex2i(1095,545);
    glVertex2i(1095,535);
    glVertex2i(1090,535);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1085,540);
    glVertex2i(1090,540);
    glVertex2i(1090,530);
    glVertex2i(1085,530);
    glEnd();


     glBegin(GL_QUADS);
    glVertex2i(1080,535);
    glVertex2i(1085,535);
    glVertex2i(1085,530);
    glVertex2i(1080,530);
    glEnd();









    glBegin(GL_QUADS);
    glVertex2i(1075,545);
    glVertex2i(1080,545);
    glVertex2i(1080,535);
    glVertex2i(1075,535);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1070,540);
    glVertex2i(1075,540);
    glVertex2i(1075,530);
    glVertex2i(1070,530);
    glEnd();


     glBegin(GL_QUADS);
    glVertex2i(1070,550);
    glVertex2i(1075,550);
    glVertex2i(1075,545);
    glVertex2i(1070,545);
    glEnd();




    glBegin(GL_QUADS);
    glVertex2i(1055,545);
    glVertex2i(1060,545);
    glVertex2i(1060,535);
    glVertex2i(1055,535);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1050,550);
    glVertex2i(1055,550);
    glVertex2i(1055,545);
    glVertex2i(1050,545);
    glEnd();


     glBegin(GL_QUADS);
    glVertex2i(1045,555);
    glVertex2i(1050,555);
    glVertex2i(1050,550);
    glVertex2i(1045,550);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1040,560);
    glVertex2i(1045,560);
    glVertex2i(1045,555);
    glVertex2i(1040,555);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(1040,555);
    glVertex2i(1045,555);
    glVertex2i(1045,560);
    glVertex2i(1040,560);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1040,550);
    glVertex2i(1045,550);
    glVertex2i(1045,555);
    glVertex2i(1040,555);
    glEnd();

    //n

glBegin(GL_QUADS);
    glVertex2i(875,500);
    glVertex2i(880,500);            //L
    glVertex2i(880,495);
    glVertex2i(875,495);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(870,505);
    glVertex2i(875,505);            //L
    glVertex2i(875,500);
    glVertex2i(870,500);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(830,495);
    glVertex2i(835,495);            //L
    glVertex2i(835,490);
    glVertex2i(830,490);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(825,495);
    glVertex2i(830,495);            //L
    glVertex2i(830,485);
    glVertex2i(825,485);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(820,490);
    glVertex2i(825,490);            //L
    glVertex2i(825,480);
    glVertex2i(820,480);
    glEnd();


    //m


    glBegin(GL_QUADS);
    glVertex2i(820,490);
    glVertex2i(825,490);            //L
    glVertex2i(825,485);
    glVertex2i(820,485);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(810,480);
    glVertex2i(820,480);            //L
    glVertex2i(820,475);
    glVertex2i(810,475);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(780,475);
    glVertex2i(790,475);            //L
    glVertex2i(790,470);
    glVertex2i(780,470);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(785,485);
    glVertex2i(790,485);            //L
    glVertex2i(790,470);
    glVertex2i(785,470);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(785,490);
    glVertex2i(795,490);            //L
    glVertex2i(795,485);
    glVertex2i(785,485);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(800,490);
    glVertex2i(810,490);            //L
    glVertex2i(810,485);
    glVertex2i(800,485);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(765,485);
    glVertex2i(775,485);            //L
    glVertex2i(775,480);
    glVertex2i(765,480);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(760,480);
    glVertex2i(770,480);            //L
    glVertex2i(770,475);
    glVertex2i(760,475);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(760,475);
    glVertex2i(770,475);            //L
    glVertex2i(770,470);
    glVertex2i(760,470);
    glEnd();


//s

glBegin(GL_QUADS);
    glVertex2i(820,545);
    glVertex2i(825,545);            //L
    glVertex2i(825,540);
    glVertex2i(820,540);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(810,545);
    glVertex2i(820,545);            //L
    glVertex2i(820,540);
    glVertex2i(810,540);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(780,550);
    glVertex2i(790,550);            //L
    glVertex2i(790,545);
    glVertex2i(780,545);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(785,555);
    glVertex2i(790,555);            //L
    glVertex2i(790,550);
    glVertex2i(785,550);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(785,560);
    glVertex2i(795,560);            //L
    glVertex2i(795,555);
    glVertex2i(785,555);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(800,555);
    glVertex2i(810,555);            //L
    glVertex2i(810,550);
    glVertex2i(800,550);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(765,560);
    glVertex2i(775,560);            //L
    glVertex2i(775,555);
    glVertex2i(765,555);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(760,480);
    glVertex2i(770,480);            //L
    glVertex2i(770,475);
    glVertex2i(760,475);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(760,475);
    glVertex2i(770,475);            //L
    glVertex2i(770,470);
    glVertex2i(760,470);
    glEnd();





 glBegin(GL_QUADS);
    glVertex2i(1050,390);
    glVertex2i(1060,390);
    glVertex2i(1060,385);
    glVertex2i(1050,385);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1050,395);
    glVertex2i(1055,395);
    glVertex2i(1055,390);
    glVertex2i(1050,390);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(1045,400);
    glVertex2i(1055,400);
    glVertex2i(1055,395);
    glVertex2i(1045,395);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1075,400);
    glVertex2i(1085,400);
    glVertex2i(1085,395);
    glVertex2i(1075,395);
    glEnd();

     glBegin(GL_QUADS);
    glVertex2i(1065,395);
    glVertex2i(1075,395);
    glVertex2i(1075,390);
    glVertex2i(1065,390);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1065,405);
    glVertex2i(1075,405);
    glVertex2i(1075,400);
    glVertex2i(1065,400);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1085,405);
    glVertex2i(1095,405);
    glVertex2i(1095,400);
    glVertex2i(1085,400);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1130,405);
    glVertex2i(1140,405);
    glVertex2i(1140,400);
    glVertex2i(1130,400);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1050,640);
    glVertex2i(1060,640);
    glVertex2i(1060,635);
    glVertex2i(1050,635);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1040,635);
    glVertex2i(1050,635);
    glVertex2i(1050,630);
    glVertex2i(1040,630);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1045,630);
    glVertex2i(1050,630);
    glVertex2i(1050,625);
    glVertex2i(1045,625);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1055,630);
    glVertex2i(1060,630);
    glVertex2i(1060,625);
    glVertex2i(1055,625);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(1055,625);
    glVertex2i(1060,625);
    glVertex2i(1060,620);
    glVertex2i(1055,620);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(985,620);
    glVertex2i(990,620);
    glVertex2i(990,615);
    glVertex2i(985,615);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(980,620);
    glVertex2i(985,620);
    glVertex2i(985,610);
    glVertex2i(980,610);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(965,625);
    glVertex2i(970,625);
    glVertex2i(970,615);
    glVertex2i(965,615);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(960,625);
    glVertex2i(965,625);
    glVertex2i(965,620);
    glVertex2i(960,620);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(960,630);
    glVertex2i(965,630);
    glVertex2i(965,625);
    glVertex2i(960,625);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(955,635);
    glVertex2i(965,635);
    glVertex2i(965,630);
    glVertex2i(955,630);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(940,635);
    glVertex2i(950,635);
    glVertex2i(950,630);
    glVertex2i(940,630);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(945,630);
    glVertex2i(950,630);
    glVertex2i(950,625);
    glVertex2i(945,625);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(935,620);
    glVertex2i(945,620);
    glVertex2i(945,615);
    glVertex2i(935,615);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(925,625);
    glVertex2i(930,625);
    glVertex2i(930,610);
    glVertex2i(925,610);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(920,630);
    glVertex2i(930,630);
    glVertex2i(930,625);
    glVertex2i(920,625);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(900,620);
    glVertex2i(910,620);
    glVertex2i(910,615);
    glVertex2i(900,615);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(895,615);
    glVertex2i(910,615);
    glVertex2i(910,610);
    glVertex2i(895,610);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(925,655);
    glVertex2i(930,655);
    glVertex2i(930,650);
    glVertex2i(925,650);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(920,660);
    glVertex2i(930,660);
    glVertex2i(930,655);
    glVertex2i(920,655);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(925,650);
    glVertex2i(935,650);
    glVertex2i(935,645);
    glVertex2i(925,645);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(945,650);
    glVertex2i(955,650);
    glVertex2i(955,645);
    glVertex2i(945,645);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(950,655);
    glVertex2i(955,655);
    glVertex2i(955,650);
    glVertex2i(950,650);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(960,650);
    glVertex2i(965,650);
    glVertex2i(965,645);
    glVertex2i(960,645);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2i(970,645);
    glVertex2i(975,645);
    glVertex2i(975,635);
    glVertex2i(970,635);
    glEnd();




    //end of color and drawing

}


void drawBird(){
    glPointSize(5.0);



    glPushMatrix();
    glTranslatef(-15,-25,0);

    //start of color and drawing



    //body
    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(955,555);
    glVertex2i(985,555);
    glVertex2i(985,585);
    glVertex2i(955,585);
    glEnd();

    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(960,550);
    glVertex2i(990,550);
    glVertex2i(990,575);
    glVertex2i(960,575);
    glEnd();

    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(965,545);
    glVertex2i(990,545);
    glVertex2i(990,570);
    glVertex2i(965,570);
    glEnd();

    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(970,540);
    glVertex2i(990,540);
    glVertex2i(990,565);
    glVertex2i(970,565);
    glEnd();
    //head

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(955,580);
    glVertex2i(960,580);
    glVertex2i(960,585);
    glVertex2i(955,585);
    glEnd();

    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(960,580);
    glVertex2i(985,580);
    glVertex2i(985,585);
    glVertex2i(960,585);
    glEnd();

    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(955,585);
    glVertex2i(980,585);
    glVertex2i(980,595);
    glVertex2i(955,595);
    glEnd();


    setColor("birdFace");
    glBegin(GL_QUADS);
    glVertex2i(955,580);
    glVertex2i(965,580);
    glVertex2i(965,590);
    glVertex2i(955,590);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(960,585);
    glVertex2i(965,585);
    glVertex2i(965,590);
    glVertex2i(960,590);
    glEnd();

    setColor("tree");
    glBegin(GL_QUADS);
    glVertex2i(940,585);
    glVertex2i(955,585);
    glVertex2i(955,590);
    glVertex2i(940,590);
    glEnd();

    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(960,595);
    glVertex2i(975,595);
    glVertex2i(975,600);
    glVertex2i(960,600);
    glEnd();

    //tail
    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(980,485);
    glVertex2i(985,485);
    glVertex2i(985,540);
    glVertex2i(980,540);
    glEnd();

    setColor("bird");
    glBegin(GL_QUADS);
    glVertex2i(985,490);
    glVertex2i(990,490);
    glVertex2i(990,540);
    glVertex2i(985,540);
    glEnd();

    //shadow
    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(975,515);
    glVertex2i(980,515);
    glVertex2i(980,540);
    glVertex2i(975,540);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(965,540);
    glVertex2i(970,540);
    glVertex2i(970,545);
    glVertex2i(965,545);
    glEnd();

    setColor("darkGray");
    glBegin(GL_QUADS);
    glVertex2i(960,545);
    glVertex2i(965,545);
    glVertex2i(965,550);
    glVertex2i(960,550);
    glEnd();

    glPopMatrix();


}

void drawSun(){


    //start of color and drawing


    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(230,530);
    glVertex2i(300,530);
    glVertex2i(300,550);
    glVertex2i(230,550);
    glEnd();

 setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(235,545);
    glVertex2i(295,545);
    glVertex2i(295,555);
    glVertex2i(235,555);
    glEnd();

setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(240,555);
    glVertex2i(290,555);
    glVertex2i(290,560);
    glVertex2i(240,560);
    glEnd();

    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(245,560);
    glVertex2i(285,560);
    glVertex2i(285,565);
    glVertex2i(245,565);
    glEnd();

 setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(255,565);
    glVertex2i(275,565);
    glVertex2i(275,570);
    glVertex2i(255,570);
    glEnd();


    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(230,530);
    glVertex2i(300,530);
    glVertex2i(300,525);
    glVertex2i(230,525);
    glEnd();

setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(235,525);
    glVertex2i(295,525);
    glVertex2i(295,520);
    glVertex2i(235,520);
    glEnd();

setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(240,520);
    glVertex2i(290,520);
    glVertex2i(290,515);
    glVertex2i(240,515);
    glEnd();

     setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(245,515);
    glVertex2i(285,515);
    glVertex2i(285,510);
    glVertex2i(245,510);
    glEnd();

 setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(255,510);
    glVertex2i(275,510);
    glVertex2i(275,505);
    glVertex2i(255,505);
    glEnd();
    //end of color and drawing

}


void drawSmallCloud(){
    glPushMatrix();
    glTranslatef(smallCloudPosition,0,0);

    setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(0,650);
    glVertex2i(55,650);
    glVertex2i(55,655);
    glVertex2i(0,655);
    glEnd();

      setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(5,650);
    glVertex2i(40,650);
    glVertex2i(40,660);
    glVertex2i(5,660);
    glEnd();


    setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(0+500,650-50);
    glVertex2i(55+500,650-50);
    glVertex2i(55+500,655-50);
    glVertex2i(0+500,655-50);
    glEnd();

      setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(5+510,650-50);
    glVertex2i(40+510,650-50);
    glVertex2i(40+510,660-50);
    glVertex2i(5+510,660-50);
    glEnd();

    glPopMatrix();
}

void drawBigCloud1(){

    glPushMatrix();
    glTranslatef(bigCloud1Position,0,0);
      setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(75,515);
    glVertex2i(250,515);
    glVertex2i(250,520);
    glVertex2i(75,520);
    glEnd();

       setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(100,515);
    glVertex2i(150,515);
    glVertex2i(150,510);
    glVertex2i(100,510);
    glEnd();


       setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(170,515);
    glVertex2i(210,515);
    glVertex2i(210,510);
    glVertex2i(170,510);
    glEnd();


       setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(180,510);
    glVertex2i(190,510);
    glVertex2i(190,505);
    glVertex2i(180,505);
    glEnd();

        setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(200,515);
    glVertex2i(230,515);
    glVertex2i(230,505);
    glVertex2i(200,505);
    glEnd();


       setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(130,520);
    glVertex2i(180,520);
    glVertex2i(180,525);
    glVertex2i(130,525);
    glEnd();


       setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(135,525);
    glVertex2i(170,525);
    glVertex2i(170,530);
    glVertex2i(135,530);
    glEnd();

    glPopMatrix();

}

void drawBigCloud2(){

    glPushMatrix();
    glTranslatef(bigCloud2Position,0,0);

         setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(295,530);
    glVertex2i(400,530);
    glVertex2i(400,535);
    glVertex2i(295,535);
    glEnd();

           setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(325,535);
    glVertex2i(365,535);
    glVertex2i(365,540);
    glVertex2i(325,540);
    glEnd();

            setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(385,535);
    glVertex2i(430,535);
    glVertex2i(430,540);
    glVertex2i(385,540);
    glEnd();

         setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(335,535);
    glVertex2i(355,535);
    glVertex2i(355,545);
    glVertex2i(335,545);
    glEnd();


           setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(345,530);
    glVertex2i(385,530);
    glVertex2i(385,525);
    glVertex2i(345,525);
    glEnd();

            setColor("cloud");
    glBegin(GL_QUADS);
    glVertex2i(395,535);
    glVertex2i(420,535);
    glVertex2i(420,545);
    glVertex2i(395,545);
    glEnd();

    glPopMatrix();

}
void drawLightBuilding(){
    //first left building
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(75,325);
    glVertex2i(75,450);
    glVertex2i(0,450);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(60,450);
    glVertex2i(65,450);
    glVertex2i(65,455);
    glVertex2i(60,455);
    glEnd();

       glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(15,325);
    glVertex2i(15,330);
    glVertex2i(0,330);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,335);
    glVertex2i(15,335);
    glVertex2i(15,345);
    glVertex2i(0,345);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,365);
    glVertex2i(15,365);
    glVertex2i(15,375);
    glVertex2i(0,375);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,380);
    glVertex2i(15,380);
    glVertex2i(15,390);
    glVertex2i(0,390);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,425);
    glVertex2i(15,425);
    glVertex2i(15,435);
    glVertex2i(0,435);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,410);
    glVertex2i(15,410);
    glVertex2i(15,420);
    glVertex2i(0,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,325);
    glVertex2i(35,325);
    glVertex2i(35,330);
    glVertex2i(20,330);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,335);
    glVertex2i(35,335);
    glVertex2i(35,345);
    glVertex2i(20,345);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,365);
    glVertex2i(35,365);
    glVertex2i(35,375);
    glVertex2i(20,375);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,380);
    glVertex2i(35,380);
    glVertex2i(35,390);
    glVertex2i(20,390);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,410);
    glVertex2i(35,410);
    glVertex2i(35,420);
    glVertex2i(20,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,425);
    glVertex2i(35,425);
    glVertex2i(35,435);
    glVertex2i(20,435);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,325);
    glVertex2i(55,325);
    glVertex2i(55,330);
    glVertex2i(40,330);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,335);
    glVertex2i(55,335);
    glVertex2i(55,345);
    glVertex2i(40,345);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,365);
    glVertex2i(55,365);
    glVertex2i(55,375);
    glVertex2i(40,375);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,380);
    glVertex2i(55,380);
    glVertex2i(55,390);
    glVertex2i(40,390);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,410);
    glVertex2i(55,410);
    glVertex2i(55,420);
    glVertex2i(40,420);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,425);
    glVertex2i(55,425);
    glVertex2i(55,435);
    glVertex2i(40,435);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,325);
    glVertex2i(70,325);
    glVertex2i(70,330);
    glVertex2i(60,330);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,335);
    glVertex2i(70,335);
    glVertex2i(70,345);
    glVertex2i(60,345);
    glEnd();

      glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,365);
    glVertex2i(70,365);
    glVertex2i(70,375);
    glVertex2i(60,375);
    glEnd();

  glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,380);
    glVertex2i(70,380);
    glVertex2i(70,390);
    glVertex2i(60,390);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,410);
    glVertex2i(70,410);
    glVertex2i(70,420);
    glVertex2i(60,420);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,425);
    glVertex2i(70,425);
    glVertex2i(70,435);
    glVertex2i(60,435);
    glEnd();

    //2nd left building

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,325);
    glVertex2i(140,325);
    glVertex2i(140,400);
    glVertex2i(75,400);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,400);
    glVertex2i(130,400);
    glVertex2i(130,410);
    glVertex2i(75,410);
    glEnd();
//first window row
setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(80,400);
    glVertex2i(85,400);
    glVertex2i(85,405);
    glVertex2i(80,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(90,400);
    glVertex2i(95,400);
    glVertex2i(95,405);
    glVertex2i(90,405);
    glEnd();

 setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(100,400);
    glVertex2i(105,400);
    glVertex2i(105,405);
    glVertex2i(100,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,400);
    glVertex2i(115,400);
    glVertex2i(115,405);
    glVertex2i(110,405);
    glEnd();
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(120,400);
    glVertex2i(125,400);
    glVertex2i(125,405);
    glVertex2i(120,405);
    glEnd();

    // row
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,345);
    glVertex2i(105,345);
    glVertex2i(105,335);
    glVertex2i(95,335);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,395);
    glVertex2i(120,395);
    glVertex2i(120,385);
    glVertex2i(110,385);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,380);
    glVertex2i(120,380);
    glVertex2i(120,370);
    glVertex2i(110,370);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,360);
    glVertex2i(120,360);
    glVertex2i(120,350);
    glVertex2i(110,350);
    glEnd();
       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,345);
    glVertex2i(120,345);
    glVertex2i(120,335);
    glVertex2i(110,335);
    glEnd();




     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,395);
    glVertex2i(135,395);
    glVertex2i(135,385);
    glVertex2i(125,385);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,380);
    glVertex2i(135,380);
    glVertex2i(135,370);
    glVertex2i(125,370);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,360);
    glVertex2i(135,360);
    glVertex2i(135,350);
    glVertex2i(125,350);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,345);
    glVertex2i(135,345);
    glVertex2i(135,335);
    glVertex2i(125,335);
    glEnd();
//3rd building
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(145,325);
    glVertex2i(155,325);
    glVertex2i(155,460);
    glVertex2i(145,460);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(155,460);
    glVertex2i(160,460);
    glVertex2i(160,465);
    glVertex2i(155,465);
    glEnd();


     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(165,460);
    glVertex2i(170,460);
    glVertex2i(170,470);
    glVertex2i(165,470);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(175,460);
    glVertex2i(180,460);
    glVertex2i(180,470);
    glVertex2i(175,470);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(185,460);
    glVertex2i(190,460);
    glVertex2i(190,465);
    glVertex2i(185,465);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,450);
    glVertex2i(185,450);
    glVertex2i(185,440);
    glVertex2i(160,440);
    glEnd();


      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,435);
    glVertex2i(185,435);
    glVertex2i(185,425);
    glVertex2i(160,425);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,420);
    glVertex2i(185,420);
    glVertex2i(185,410);
    glVertex2i(160,410);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,390);
    glVertex2i(185,390);
    glVertex2i(185,380);
    glVertex2i(160,380);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,375);
    glVertex2i(185,375);
    glVertex2i(185,365);
    glVertex2i(160,365);
    glEnd();
           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,360);
    glVertex2i(185,360);
    glVertex2i(185,350);
    glVertex2i(160,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,335);
    glVertex2i(185,335);
    glVertex2i(185,325);
    glVertex2i(160,325);
    glEnd();
    //4th building
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(200,325);
    glVertex2i(220,325);
    glVertex2i(220,415);
    glVertex2i(200,415);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,335);
    glVertex2i(215,335);
    glVertex2i(215,345);
    glVertex2i(205,345);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,350);
    glVertex2i(215,350);
    glVertex2i(215,360);
    glVertex2i(205,360);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,365);
    glVertex2i(215,365);
    glVertex2i(215,375);
    glVertex2i(205,375);
    glEnd();
          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,380);
    glVertex2i(215,380);
    glVertex2i(215,390);
    glVertex2i(205,390);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,395);
    glVertex2i(215,395);
    glVertex2i(215,405);
    glVertex2i(205,405);
    glEnd();


     setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(220,415);
    glVertex2i(225,415);
    glVertex2i(225,420);
    glVertex2i(220,420);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(235,415);
    glVertex2i(250,415);
    glVertex2i(250,425);
    glVertex2i(235,425);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(255,415);
    glVertex2i(260,415);
    glVertex2i(260,425);
    glVertex2i(255,425);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(280,415);
    glVertex2i(285,415);
    glVertex2i(285,420);
    glVertex2i(280,420);
    glEnd();
//windows
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,400);
    glVertex2i(240,400);
    glVertex2i(240,410);
    glVertex2i(225,410);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,395);
    glVertex2i(240,395);
    glVertex2i(240,385);
    glVertex2i(225,385);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,380);
    glVertex2i(240,380);
    glVertex2i(240,370);
    glVertex2i(225,370);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,350);
    glVertex2i(240,350);
    glVertex2i(240,340);
    glVertex2i(225,340);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,335);
    glVertex2i(240,335);
    glVertex2i(240,325);
    glVertex2i(225,325);
    glEnd();


   setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,400);
    glVertex2i(260,400);
    glVertex2i(260,410);
    glVertex2i(245,410);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,395);
    glVertex2i(260,395);
    glVertex2i(260,385);
    glVertex2i(245,385);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,380);
    glVertex2i(260,380);
    glVertex2i(260,370);
    glVertex2i(245,370);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,350);
    glVertex2i(260,350);
    glVertex2i(260,340);
    glVertex2i(245,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,335);
    glVertex2i(260,335);
    glVertex2i(260,325);
    glVertex2i(245,325);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,400);
    glVertex2i(280,400);
    glVertex2i(280,410);
    glVertex2i(265,410);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,395);
    glVertex2i(280,395);
    glVertex2i(280,385);
    glVertex2i(265,385);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,380);
    glVertex2i(280,380);
    glVertex2i(280,370);
    glVertex2i(265,370);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,350);
    glVertex2i(280,350);
    glVertex2i(280,340);
    glVertex2i(265,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,335);
    glVertex2i(280,335);
    glVertex2i(280,325);
    glVertex2i(265,325);
    glEnd();

    //5th building
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(290,225);
    glVertex2i(400,225);
    glVertex2i(400,365);
    glVertex2i(290,365);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(300,365);
    glVertex2i(305,365);
    glVertex2i(305,370);
    glVertex2i(300,370);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(340,365);
    glVertex2i(345,365);
    glVertex2i(345,370);
    glVertex2i(340,370);
    glEnd();

    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(390,365);
    glVertex2i(395,365);
    glVertex2i(395,370);
    glVertex2i(390,370);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,235);
    glVertex2i(325,235);
    glVertex2i(325,255);
    glVertex2i(320,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,235);
    glVertex2i(360,235);
    glVertex2i(360,255);
    glVertex2i(350,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,235);
    glVertex2i(380,235);
    glVertex2i(380,255);
    glVertex2i(370,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,235);
    glVertex2i(400,235);
    glVertex2i(400,255);
    glVertex2i(390,255);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,260);
    glVertex2i(325,260);
    glVertex2i(325,280);
    glVertex2i(320,280);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,260);
    glVertex2i(360,260);
    glVertex2i(360,280);
    glVertex2i(350,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,260);
    glVertex2i(380,260);
    glVertex2i(380,280);
    glVertex2i(370,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,260);
    glVertex2i(400,260);
    glVertex2i(400,280);
    glVertex2i(390,280);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,285);
    glVertex2i(325,285);
    glVertex2i(325,305);
    glVertex2i(320,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,285);
    glVertex2i(360,285);
    glVertex2i(360,305);
    glVertex2i(350,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,285);
    glVertex2i(380,285);
    glVertex2i(380,305);
    glVertex2i(370,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,285);
    glVertex2i(400,285);
    glVertex2i(400,305);
    glVertex2i(390,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,310);
    glVertex2i(325,310);
    glVertex2i(325,330);
    glVertex2i(320,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,310);
    glVertex2i(360,310);
    glVertex2i(360,330);
    glVertex2i(350,330);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,310);
    glVertex2i(380,310);
    glVertex2i(380,330);
    glVertex2i(370,330);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,310);
    glVertex2i(400,310);
    glVertex2i(400,330);
    glVertex2i(390,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,335);
    glVertex2i(325,335);
    glVertex2i(325,355);
    glVertex2i(320,355);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,335);
    glVertex2i(360,335);
    glVertex2i(360,355);
    glVertex2i(350,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,335);
    glVertex2i(380,335);
    glVertex2i(380,355);
    glVertex2i(370,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,335);
    glVertex2i(400,335);
    glVertex2i(400,355);
    glVertex2i(390,355);
    glEnd();
//6th building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(430,265);
    glVertex2i(465,265);
    glVertex2i(465,315);
    glVertex2i(430,315);
    glEnd();

        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(465,315);
    glVertex2i(470,315);
    glVertex2i(470,320);
    glVertex2i(465,320);
    glEnd();


        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(555,315);
    glVertex2i(560,315);
    glVertex2i(560,320);
    glVertex2i(555,320);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,275);
    glVertex2i(440,275);
    glVertex2i(440,290);
    glVertex2i(435,290);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,295);
    glVertex2i(440,295);
    glVertex2i(440,310);
    glVertex2i(435,310);
    glEnd();



           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,275);
    glVertex2i(450,275);
    glVertex2i(450,290);
    glVertex2i(445,290);
    glEnd();


           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,295);
    glVertex2i(450,295);
    glVertex2i(450,310);
    glVertex2i(445,310);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,275);
    glVertex2i(460,275);
    glVertex2i(460,290);
    glVertex2i(455,290);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,295);
    glVertex2i(460,295);
    glVertex2i(460,310);
    glVertex2i(455,310);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,295);
    glVertex2i(480,295);
    glVertex2i(480,310);
    glVertex2i(475,310);
    glEnd();
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,275);
    glVertex2i(480,275);
    glVertex2i(480,290);
    glVertex2i(475,290);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,295);
    glVertex2i(490,295);
    glVertex2i(490,310);
    glVertex2i(485,310);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,275);
    glVertex2i(490,275);
    glVertex2i(490,290);
    glVertex2i(485,290);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,295);
    glVertex2i(510,295);
    glVertex2i(510,310);
    glVertex2i(505,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();
setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,295);
    glVertex2i(520,295);
    glVertex2i(520,310);
    glVertex2i(515,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,275);
    glVertex2i(520,275);
    glVertex2i(520,290);
    glVertex2i(515,290);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,295);
    glVertex2i(540,295);
    glVertex2i(540,310);
    glVertex2i(535,310);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,275);
    glVertex2i(540,275);
    glVertex2i(540,290);
    glVertex2i(535,290);
    glEnd();

  setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,245);
    glVertex2i(540,245);
    glVertex2i(540,260);
    glVertex2i(535,260);
    glEnd();

setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,225);
    glVertex2i(540,225);
    glVertex2i(540,240);
    glVertex2i(535,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,170);
    glVertex2i(540,170);
    glVertex2i(540,185);
    glVertex2i(535,185);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,295);
    glVertex2i(550,295);
    glVertex2i(550,310);
    glVertex2i(545,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,275);
    glVertex2i(550,275);
    glVertex2i(550,290);
    glVertex2i(545,290);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,245);
    glVertex2i(550,245);
    glVertex2i(550,260);
    glVertex2i(545,260);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,225);
    glVertex2i(550,225);
    glVertex2i(550,240);
    glVertex2i(545,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,190);
    glVertex2i(550,190);
    glVertex2i(550,205);
    glVertex2i(545,205);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,170);
    glVertex2i(550,170);
    glVertex2i(550,185);
    glVertex2i(545,185);
    glEnd();


    //midbuild

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(365,170);
    glVertex2i(525,170);
    glVertex2i(525,270);
    glVertex2i(365,270);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(375,270);
    glVertex2i(385,270);
    glVertex2i(385,275);
    glVertex2i(375,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(420,270);
    glVertex2i(430,270);
    glVertex2i(430,275);
    glVertex2i(420,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(510,270);
    glVertex2i(520,270);
    glVertex2i(520,275);
    glVertex2i(510,275);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,190);
    glVertex2i(390,190);
    glVertex2i(390,200);
    glVertex2i(385,200);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,220);
    glVertex2i(390,220);
    glVertex2i(390,230);
    glVertex2i(385,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,250);
    glVertex2i(390,250);
    glVertex2i(390,260);
    glVertex2i(385,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,190);
    glVertex2i(400,190);
    glVertex2i(400,200);
    glVertex2i(395,200);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,220);
    glVertex2i(400,220);
    glVertex2i(400,230);
    glVertex2i(395,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,250);
    glVertex2i(400,250);
    glVertex2i(400,260);
    glVertex2i(395,260);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,250);
    glVertex2i(455,250);
    glVertex2i(455,260);
    glVertex2i(435,260);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,220);
    glVertex2i(455,220);
    glVertex2i(455,230);
    glVertex2i(435,230);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,200);
    glVertex2i(455,200);
    glVertex2i(455,190);
    glVertex2i(435,190);
    glEnd();


   setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,250);
    glVertex2i(485,250);
    glVertex2i(485,260);
    glVertex2i(465,260);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,220);
    glVertex2i(485,220);
    glVertex2i(485,230);
    glVertex2i(465,230);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,200);
    glVertex2i(485,200);
    glVertex2i(485,190);
    glVertex2i(465,190);
    glEnd();
  setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,250);
    glVertex2i(515,250);
    glVertex2i(515,260);
    glVertex2i(495,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,220);
    glVertex2i(515,220);
    glVertex2i(515,230);
    glVertex2i(495,230);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,200);
    glVertex2i(515,200);
    glVertex2i(515,190);
    glVertex2i(495,190);
    glEnd();
//light bridge
       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(525,220);
    glVertex2i(815,220);
    glVertex2i(815,235);
    glVertex2i(525,235);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(575,220);
    glVertex2i(595,220);
    glVertex2i(595,215);
    glVertex2i(575,215);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,220);
    glVertex2i(590,220);
    glVertex2i(590,170);
    glVertex2i(580,170);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(585,235);
    glVertex2i(590,235);
    glVertex2i(590,255);
    glVertex2i(585,255);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,255);
    glVertex2i(580,255);
    glEnd();

         setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,245);
    glVertex2i(580,245);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(650,235);
    glVertex2i(655,235);
    glVertex2i(655,255);
    glVertex2i(650,255);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,255);
    glVertex2i(645,255);
    glEnd();

          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,245);
    glVertex2i(645,245);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(715,235);
    glVertex2i(720,235);
    glVertex2i(720,255);
    glVertex2i(715,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,255);
    glVertex2i(710,255);
    glEnd();

           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,245);
    glVertex2i(710,245);
    glEnd();

             setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(770,235);
    glVertex2i(775,235);
    glVertex2i(775,255);
    glVertex2i(770,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,255);
    glVertex2i(765,255);
    glEnd();


           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,245);
    glVertex2i(765,245);
    glEnd();



       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,220);
    glVertex2i(655,220);
    glVertex2i(655,215);
    glVertex2i(635,215);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(640,220);
    glVertex2i(650,220);
    glVertex2i(650,170);
    glVertex2i(640,170);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(695,220);
    glVertex2i(715,220);
    glVertex2i(715,215);
    glVertex2i(695,215);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(710,220);
    glVertex2i(710,170);
    glVertex2i(700,170);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(755,220);
    glVertex2i(775,220);
    glVertex2i(775,215);
    glVertex2i(755,215);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,220);
    glVertex2i(770,220);
    glVertex2i(770,170);
    glVertex2i(760,170);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,205);
    glVertex2i(845,205);
    glVertex2i(845,170);
    glVertex2i(760,170);
    glEnd();


         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(765,205);
    glVertex2i(770,205);
    glVertex2i(770,210);
    glVertex2i(765,210);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,195);
    glVertex2i(780,195);
    glVertex2i(780,200);
    glVertex2i(765,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,185);
    glVertex2i(780,185);
    glVertex2i(780,190);
    glVertex2i(765,190);
    glEnd();


             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,195);
    glVertex2i(800,195);
    glVertex2i(800,200);
    glVertex2i(785,200);
    glEnd();

            setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,185);
    glVertex2i(800,185);
    glVertex2i(800,190);
    glVertex2i(785,190);
    glEnd();
             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,195);
    glVertex2i(815,195);
    glVertex2i(815,200);
    glVertex2i(805,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,185);
    glVertex2i(815,185);
    glVertex2i(815,190);
    glVertex2i(805,190);
    glEnd();

                setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(680,170);
    glVertex2i(765,170);
    glVertex2i(765,175);
    glVertex2i(680,175);
    glEnd();

                 setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(690,175);
    glVertex2i(695,175);
    glVertex2i(695,180);
    glVertex2i(690,180);
    glEnd();

                   setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(730,175);
    glVertex2i(735,175);
    glVertex2i(735,180);
    glVertex2i(730,180);
    glEnd();

                    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(750,175);
    glVertex2i(755,175);
    glVertex2i(755,180);
    glVertex2i(750,180);
    glEnd();



//light bridge right building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,170);
    glVertex2i(845,170);
    glVertex2i(845,275);
    glVertex2i(815,275);
    glEnd();

         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(815,275);
    glVertex2i(820,275);
    glVertex2i(820,280);
    glVertex2i(815,280);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,200);
    glVertex2i(830,200);
    glVertex2i(830,215);
    glVertex2i(820,215);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,200);
    glVertex2i(845,200);
    glVertex2i(845,215);
    glVertex2i(835,215);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,220);
    glVertex2i(830,220);
    glVertex2i(830,235);
    glVertex2i(820,235);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,220);
    glVertex2i(845,220);
    glVertex2i(845,235);
    glVertex2i(835,235);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,240);
    glVertex2i(830,240);
    glVertex2i(830,255);
    glVertex2i(820,255);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,240);
    glVertex2i(845,240);
    glVertex2i(845,255);
    glVertex2i(835,255);
    glEnd();

          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(845,170);
    glVertex2i(965,170);
    glVertex2i(965,295);
    glVertex2i(845,295);
    glEnd();


          setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(855,295);
    glVertex2i(865,295);
    glVertex2i(865,300);
    glVertex2i(855,300);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(865,295);
    glVertex2i(960,295);
    glVertex2i(960,315);
    glVertex2i(865,315);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(905,315);
    glVertex2i(935,315);
    glVertex2i(935,320);
    glVertex2i(905,320);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(935,315);
    glVertex2i(945,315);
    glVertex2i(945,380);
    glVertex2i(935,380);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,380);
    glVertex2i(935,380);
    glVertex2i(935,385);
    glVertex2i(930,385);
    glEnd();

       setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(900,380);
    glVertex2i(905,380);
    glVertex2i(905,385);
    glVertex2i(900,385);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,365);
    glVertex2i(915,365);
    glVertex2i(915,370);
    glVertex2i(910,370);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,355);
    glVertex2i(915,355);
    glVertex2i(915,360);
    glVertex2i(910,360);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,345);
    glVertex2i(915,345);
    glVertex2i(915,350);
    glVertex2i(910,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,335);
    glVertex2i(915,335);
    glVertex2i(915,340);
    glVertex2i(910,340);
    glEnd();



           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,365);
    glVertex2i(925,365);
    glVertex2i(925,370);
    glVertex2i(920,370);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,355);
    glVertex2i(925,355);
    glVertex2i(925,360);
    glVertex2i(920,360);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,345);
    glVertex2i(925,345);
    glVertex2i(925,350);
    glVertex2i(920,350);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,335);
    glVertex2i(925,335);
    glVertex2i(925,340);
    glVertex2i(920,340);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(875,295);
    glVertex2i(885,295);
    glVertex2i(885,310);
    glVertex2i(875,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,255);
    glVertex2i(875,255);
    glVertex2i(875,270);
    glVertex2i(860,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,215);
    glVertex2i(875,215);
    glVertex2i(875,230);
    glVertex2i(860,230);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,180);
    glVertex2i(875,180);
    glVertex2i(875,195);
    glVertex2i(860,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,255);
    glVertex2i(895,255);
    glVertex2i(895,270);
    glVertex2i(880,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,215);
    glVertex2i(895,215);
    glVertex2i(895,230);
    glVertex2i(880,230);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,180);
    glVertex2i(895,180);
    glVertex2i(895,195);
    glVertex2i(880,195);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,255);
    glVertex2i(915,255);
    glVertex2i(915,270);
    glVertex2i(900,270);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,215);
    glVertex2i(915,215);
    glVertex2i(915,230);
    glVertex2i(900,230);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,180);
    glVertex2i(915,180);
    glVertex2i(915,195);
    glVertex2i(900,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(890,295);
    glVertex2i(900,295);
    glVertex2i(900,310);
    glVertex2i(890,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(905,295);
    glVertex2i(915,295);
    glVertex2i(915,310);
    glVertex2i(905,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(940,295);
    glVertex2i(940,310);
    glVertex2i(930,310);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(935,295);
    glVertex2i(935,300);
    glVertex2i(930,300);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(945,295);
    glVertex2i(955,295);
    glVertex2i(955,310);
    glVertex2i(945,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,265);
    glVertex2i(940,265);
    glVertex2i(940,280);
    glVertex2i(935,280);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,260);
    glVertex2i(940,260);
    glVertex2i(940,245);
    glVertex2i(935,245);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,240);
    glVertex2i(940,240);
    glVertex2i(940,225);
    glVertex2i(935,225);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,220);
    glVertex2i(940,220);
    glVertex2i(940,205);
    glVertex2i(935,205);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,200);
    glVertex2i(940,200);
    glVertex2i(940,185);
    glVertex2i(935,185);
    glEnd();



          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(960,295);
    glVertex2i(965,295);
    glVertex2i(965,300);
    glVertex2i(960,300);
    glEnd();
}

void drawLightBuildingMore(){
    glPushMatrix();
    glTranslatef(200,0,0);
    //first left building
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(75,325);
    glVertex2i(75,450);
    glVertex2i(0,450);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(60,450);
    glVertex2i(65,450);
    glVertex2i(65,455);
    glVertex2i(60,455);
    glEnd();

       glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(15,325);
    glVertex2i(15,330);
    glVertex2i(0,330);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,335);
    glVertex2i(15,335);
    glVertex2i(15,345);
    glVertex2i(0,345);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,365);
    glVertex2i(15,365);
    glVertex2i(15,375);
    glVertex2i(0,375);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,380);
    glVertex2i(15,380);
    glVertex2i(15,390);
    glVertex2i(0,390);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,425);
    glVertex2i(15,425);
    glVertex2i(15,435);
    glVertex2i(0,435);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,410);
    glVertex2i(15,410);
    glVertex2i(15,420);
    glVertex2i(0,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,325);
    glVertex2i(35,325);
    glVertex2i(35,330);
    glVertex2i(20,330);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,335);
    glVertex2i(35,335);
    glVertex2i(35,345);
    glVertex2i(20,345);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,365);
    glVertex2i(35,365);
    glVertex2i(35,375);
    glVertex2i(20,375);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,380);
    glVertex2i(35,380);
    glVertex2i(35,390);
    glVertex2i(20,390);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,410);
    glVertex2i(35,410);
    glVertex2i(35,420);
    glVertex2i(20,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,425);
    glVertex2i(35,425);
    glVertex2i(35,435);
    glVertex2i(20,435);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,325);
    glVertex2i(55,325);
    glVertex2i(55,330);
    glVertex2i(40,330);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,335);
    glVertex2i(55,335);
    glVertex2i(55,345);
    glVertex2i(40,345);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,365);
    glVertex2i(55,365);
    glVertex2i(55,375);
    glVertex2i(40,375);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,380);
    glVertex2i(55,380);
    glVertex2i(55,390);
    glVertex2i(40,390);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,410);
    glVertex2i(55,410);
    glVertex2i(55,420);
    glVertex2i(40,420);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,425);
    glVertex2i(55,425);
    glVertex2i(55,435);
    glVertex2i(40,435);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,325);
    glVertex2i(70,325);
    glVertex2i(70,330);
    glVertex2i(60,330);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,335);
    glVertex2i(70,335);
    glVertex2i(70,345);
    glVertex2i(60,345);
    glEnd();

      glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,365);
    glVertex2i(70,365);
    glVertex2i(70,375);
    glVertex2i(60,375);
    glEnd();

  glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,380);
    glVertex2i(70,380);
    glVertex2i(70,390);
    glVertex2i(60,390);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,410);
    glVertex2i(70,410);
    glVertex2i(70,420);
    glVertex2i(60,420);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,425);
    glVertex2i(70,425);
    glVertex2i(70,435);
    glVertex2i(60,435);
    glEnd();

    //2nd left building

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,325);
    glVertex2i(140,325);
    glVertex2i(140,400);
    glVertex2i(75,400);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,400);
    glVertex2i(130,400);
    glVertex2i(130,410);
    glVertex2i(75,410);
    glEnd();
//first window row
setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(80,400);
    glVertex2i(85,400);
    glVertex2i(85,405);
    glVertex2i(80,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(90,400);
    glVertex2i(95,400);
    glVertex2i(95,405);
    glVertex2i(90,405);
    glEnd();

 setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(100,400);
    glVertex2i(105,400);
    glVertex2i(105,405);
    glVertex2i(100,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,400);
    glVertex2i(115,400);
    glVertex2i(115,405);
    glVertex2i(110,405);
    glEnd();
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(120,400);
    glVertex2i(125,400);
    glVertex2i(125,405);
    glVertex2i(120,405);
    glEnd();

    // row
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,345);
    glVertex2i(105,345);
    glVertex2i(105,335);
    glVertex2i(95,335);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,395);
    glVertex2i(120,395);
    glVertex2i(120,385);
    glVertex2i(110,385);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,380);
    glVertex2i(120,380);
    glVertex2i(120,370);
    glVertex2i(110,370);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,360);
    glVertex2i(120,360);
    glVertex2i(120,350);
    glVertex2i(110,350);
    glEnd();
       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,345);
    glVertex2i(120,345);
    glVertex2i(120,335);
    glVertex2i(110,335);
    glEnd();




     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,395);
    glVertex2i(135,395);
    glVertex2i(135,385);
    glVertex2i(125,385);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,380);
    glVertex2i(135,380);
    glVertex2i(135,370);
    glVertex2i(125,370);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,360);
    glVertex2i(135,360);
    glVertex2i(135,350);
    glVertex2i(125,350);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,345);
    glVertex2i(135,345);
    glVertex2i(135,335);
    glVertex2i(125,335);
    glEnd();
//3rd building
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(145,325);
    glVertex2i(155,325);
    glVertex2i(155,460);
    glVertex2i(145,460);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(155,460);
    glVertex2i(160,460);
    glVertex2i(160,465);
    glVertex2i(155,465);
    glEnd();


     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(165,460);
    glVertex2i(170,460);
    glVertex2i(170,470);
    glVertex2i(165,470);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(175,460);
    glVertex2i(180,460);
    glVertex2i(180,470);
    glVertex2i(175,470);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(185,460);
    glVertex2i(190,460);
    glVertex2i(190,465);
    glVertex2i(185,465);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,450);
    glVertex2i(185,450);
    glVertex2i(185,440);
    glVertex2i(160,440);
    glEnd();


      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,435);
    glVertex2i(185,435);
    glVertex2i(185,425);
    glVertex2i(160,425);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,420);
    glVertex2i(185,420);
    glVertex2i(185,410);
    glVertex2i(160,410);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,390);
    glVertex2i(185,390);
    glVertex2i(185,380);
    glVertex2i(160,380);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,375);
    glVertex2i(185,375);
    glVertex2i(185,365);
    glVertex2i(160,365);
    glEnd();
           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,360);
    glVertex2i(185,360);
    glVertex2i(185,350);
    glVertex2i(160,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,335);
    glVertex2i(185,335);
    glVertex2i(185,325);
    glVertex2i(160,325);
    glEnd();
    //4th building
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(200,325);
    glVertex2i(220,325);
    glVertex2i(220,415);
    glVertex2i(200,415);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,335);
    glVertex2i(215,335);
    glVertex2i(215,345);
    glVertex2i(205,345);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,350);
    glVertex2i(215,350);
    glVertex2i(215,360);
    glVertex2i(205,360);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,365);
    glVertex2i(215,365);
    glVertex2i(215,375);
    glVertex2i(205,375);
    glEnd();
          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,380);
    glVertex2i(215,380);
    glVertex2i(215,390);
    glVertex2i(205,390);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,395);
    glVertex2i(215,395);
    glVertex2i(215,405);
    glVertex2i(205,405);
    glEnd();


     setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(220,415);
    glVertex2i(225,415);
    glVertex2i(225,420);
    glVertex2i(220,420);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(235,415);
    glVertex2i(250,415);
    glVertex2i(250,425);
    glVertex2i(235,425);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(255,415);
    glVertex2i(260,415);
    glVertex2i(260,425);
    glVertex2i(255,425);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(280,415);
    glVertex2i(285,415);
    glVertex2i(285,420);
    glVertex2i(280,420);
    glEnd();
//windows
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,400);
    glVertex2i(240,400);
    glVertex2i(240,410);
    glVertex2i(225,410);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,395);
    glVertex2i(240,395);
    glVertex2i(240,385);
    glVertex2i(225,385);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,380);
    glVertex2i(240,380);
    glVertex2i(240,370);
    glVertex2i(225,370);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,350);
    glVertex2i(240,350);
    glVertex2i(240,340);
    glVertex2i(225,340);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,335);
    glVertex2i(240,335);
    glVertex2i(240,325);
    glVertex2i(225,325);
    glEnd();


   setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,400);
    glVertex2i(260,400);
    glVertex2i(260,410);
    glVertex2i(245,410);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,395);
    glVertex2i(260,395);
    glVertex2i(260,385);
    glVertex2i(245,385);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,380);
    glVertex2i(260,380);
    glVertex2i(260,370);
    glVertex2i(245,370);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,350);
    glVertex2i(260,350);
    glVertex2i(260,340);
    glVertex2i(245,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,335);
    glVertex2i(260,335);
    glVertex2i(260,325);
    glVertex2i(245,325);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,400);
    glVertex2i(280,400);
    glVertex2i(280,410);
    glVertex2i(265,410);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,395);
    glVertex2i(280,395);
    glVertex2i(280,385);
    glVertex2i(265,385);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,380);
    glVertex2i(280,380);
    glVertex2i(280,370);
    glVertex2i(265,370);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,350);
    glVertex2i(280,350);
    glVertex2i(280,340);
    glVertex2i(265,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,335);
    glVertex2i(280,335);
    glVertex2i(280,325);
    glVertex2i(265,325);
    glEnd();

    //5th building
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(290,225);
    glVertex2i(400,225);
    glVertex2i(400,365);
    glVertex2i(290,365);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(300,365);
    glVertex2i(305,365);
    glVertex2i(305,370);
    glVertex2i(300,370);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(340,365);
    glVertex2i(345,365);
    glVertex2i(345,370);
    glVertex2i(340,370);
    glEnd();

    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(390,365);
    glVertex2i(395,365);
    glVertex2i(395,370);
    glVertex2i(390,370);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,235);
    glVertex2i(325,235);
    glVertex2i(325,255);
    glVertex2i(320,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,235);
    glVertex2i(360,235);
    glVertex2i(360,255);
    glVertex2i(350,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,235);
    glVertex2i(380,235);
    glVertex2i(380,255);
    glVertex2i(370,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,235);
    glVertex2i(400,235);
    glVertex2i(400,255);
    glVertex2i(390,255);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,260);
    glVertex2i(325,260);
    glVertex2i(325,280);
    glVertex2i(320,280);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,260);
    glVertex2i(360,260);
    glVertex2i(360,280);
    glVertex2i(350,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,260);
    glVertex2i(380,260);
    glVertex2i(380,280);
    glVertex2i(370,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,260);
    glVertex2i(400,260);
    glVertex2i(400,280);
    glVertex2i(390,280);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,285);
    glVertex2i(325,285);
    glVertex2i(325,305);
    glVertex2i(320,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,285);
    glVertex2i(360,285);
    glVertex2i(360,305);
    glVertex2i(350,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,285);
    glVertex2i(380,285);
    glVertex2i(380,305);
    glVertex2i(370,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,285);
    glVertex2i(400,285);
    glVertex2i(400,305);
    glVertex2i(390,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,310);
    glVertex2i(325,310);
    glVertex2i(325,330);
    glVertex2i(320,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,310);
    glVertex2i(360,310);
    glVertex2i(360,330);
    glVertex2i(350,330);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,310);
    glVertex2i(380,310);
    glVertex2i(380,330);
    glVertex2i(370,330);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,310);
    glVertex2i(400,310);
    glVertex2i(400,330);
    glVertex2i(390,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,335);
    glVertex2i(325,335);
    glVertex2i(325,355);
    glVertex2i(320,355);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,335);
    glVertex2i(360,335);
    glVertex2i(360,355);
    glVertex2i(350,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,335);
    glVertex2i(380,335);
    glVertex2i(380,355);
    glVertex2i(370,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,335);
    glVertex2i(400,335);
    glVertex2i(400,355);
    glVertex2i(390,355);
    glEnd();
//6th building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(430,265);
    glVertex2i(465,265);
    glVertex2i(465,315);
    glVertex2i(430,315);
    glEnd();

        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(465,315);
    glVertex2i(470,315);
    glVertex2i(470,320);
    glVertex2i(465,320);
    glEnd();


        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(555,315);
    glVertex2i(560,315);
    glVertex2i(560,320);
    glVertex2i(555,320);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,275);
    glVertex2i(440,275);
    glVertex2i(440,290);
    glVertex2i(435,290);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,295);
    glVertex2i(440,295);
    glVertex2i(440,310);
    glVertex2i(435,310);
    glEnd();



           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,275);
    glVertex2i(450,275);
    glVertex2i(450,290);
    glVertex2i(445,290);
    glEnd();


           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,295);
    glVertex2i(450,295);
    glVertex2i(450,310);
    glVertex2i(445,310);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,275);
    glVertex2i(460,275);
    glVertex2i(460,290);
    glVertex2i(455,290);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,295);
    glVertex2i(460,295);
    glVertex2i(460,310);
    glVertex2i(455,310);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,295);
    glVertex2i(480,295);
    glVertex2i(480,310);
    glVertex2i(475,310);
    glEnd();
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,275);
    glVertex2i(480,275);
    glVertex2i(480,290);
    glVertex2i(475,290);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,295);
    glVertex2i(490,295);
    glVertex2i(490,310);
    glVertex2i(485,310);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,275);
    glVertex2i(490,275);
    glVertex2i(490,290);
    glVertex2i(485,290);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,295);
    glVertex2i(510,295);
    glVertex2i(510,310);
    glVertex2i(505,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();
setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,295);
    glVertex2i(520,295);
    glVertex2i(520,310);
    glVertex2i(515,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,275);
    glVertex2i(520,275);
    glVertex2i(520,290);
    glVertex2i(515,290);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,295);
    glVertex2i(540,295);
    glVertex2i(540,310);
    glVertex2i(535,310);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,275);
    glVertex2i(540,275);
    glVertex2i(540,290);
    glVertex2i(535,290);
    glEnd();

  setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,245);
    glVertex2i(540,245);
    glVertex2i(540,260);
    glVertex2i(535,260);
    glEnd();

setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,225);
    glVertex2i(540,225);
    glVertex2i(540,240);
    glVertex2i(535,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,170);
    glVertex2i(540,170);
    glVertex2i(540,185);
    glVertex2i(535,185);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,295);
    glVertex2i(550,295);
    glVertex2i(550,310);
    glVertex2i(545,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,275);
    glVertex2i(550,275);
    glVertex2i(550,290);
    glVertex2i(545,290);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,245);
    glVertex2i(550,245);
    glVertex2i(550,260);
    glVertex2i(545,260);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,225);
    glVertex2i(550,225);
    glVertex2i(550,240);
    glVertex2i(545,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,190);
    glVertex2i(550,190);
    glVertex2i(550,205);
    glVertex2i(545,205);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,170);
    glVertex2i(550,170);
    glVertex2i(550,185);
    glVertex2i(545,185);
    glEnd();


    //midbuild

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(365,170);
    glVertex2i(525,170);
    glVertex2i(525,270);
    glVertex2i(365,270);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(375,270);
    glVertex2i(385,270);
    glVertex2i(385,275);
    glVertex2i(375,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(420,270);
    glVertex2i(430,270);
    glVertex2i(430,275);
    glVertex2i(420,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(510,270);
    glVertex2i(520,270);
    glVertex2i(520,275);
    glVertex2i(510,275);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,190);
    glVertex2i(390,190);
    glVertex2i(390,200);
    glVertex2i(385,200);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,220);
    glVertex2i(390,220);
    glVertex2i(390,230);
    glVertex2i(385,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,250);
    glVertex2i(390,250);
    glVertex2i(390,260);
    glVertex2i(385,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,190);
    glVertex2i(400,190);
    glVertex2i(400,200);
    glVertex2i(395,200);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,220);
    glVertex2i(400,220);
    glVertex2i(400,230);
    glVertex2i(395,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,250);
    glVertex2i(400,250);
    glVertex2i(400,260);
    glVertex2i(395,260);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,250);
    glVertex2i(455,250);
    glVertex2i(455,260);
    glVertex2i(435,260);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,220);
    glVertex2i(455,220);
    glVertex2i(455,230);
    glVertex2i(435,230);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,200);
    glVertex2i(455,200);
    glVertex2i(455,190);
    glVertex2i(435,190);
    glEnd();


   setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,250);
    glVertex2i(485,250);
    glVertex2i(485,260);
    glVertex2i(465,260);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,220);
    glVertex2i(485,220);
    glVertex2i(485,230);
    glVertex2i(465,230);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,200);
    glVertex2i(485,200);
    glVertex2i(485,190);
    glVertex2i(465,190);
    glEnd();
  setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,250);
    glVertex2i(515,250);
    glVertex2i(515,260);
    glVertex2i(495,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,220);
    glVertex2i(515,220);
    glVertex2i(515,230);
    glVertex2i(495,230);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,200);
    glVertex2i(515,200);
    glVertex2i(515,190);
    glVertex2i(495,190);
    glEnd();
//light bridge
       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(525,220);
    glVertex2i(815,220);
    glVertex2i(815,235);
    glVertex2i(525,235);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(575,220);
    glVertex2i(595,220);
    glVertex2i(595,215);
    glVertex2i(575,215);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,220);
    glVertex2i(590,220);
    glVertex2i(590,170);
    glVertex2i(580,170);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(585,235);
    glVertex2i(590,235);
    glVertex2i(590,255);
    glVertex2i(585,255);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,255);
    glVertex2i(580,255);
    glEnd();

         setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,245);
    glVertex2i(580,245);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(650,235);
    glVertex2i(655,235);
    glVertex2i(655,255);
    glVertex2i(650,255);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,255);
    glVertex2i(645,255);
    glEnd();

          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,245);
    glVertex2i(645,245);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(715,235);
    glVertex2i(720,235);
    glVertex2i(720,255);
    glVertex2i(715,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,255);
    glVertex2i(710,255);
    glEnd();

           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,245);
    glVertex2i(710,245);
    glEnd();

             setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(770,235);
    glVertex2i(775,235);
    glVertex2i(775,255);
    glVertex2i(770,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,255);
    glVertex2i(765,255);
    glEnd();


           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,245);
    glVertex2i(765,245);
    glEnd();



       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,220);
    glVertex2i(655,220);
    glVertex2i(655,215);
    glVertex2i(635,215);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(640,220);
    glVertex2i(650,220);
    glVertex2i(650,170);
    glVertex2i(640,170);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(695,220);
    glVertex2i(715,220);
    glVertex2i(715,215);
    glVertex2i(695,215);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(710,220);
    glVertex2i(710,170);
    glVertex2i(700,170);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(755,220);
    glVertex2i(775,220);
    glVertex2i(775,215);
    glVertex2i(755,215);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,220);
    glVertex2i(770,220);
    glVertex2i(770,170);
    glVertex2i(760,170);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,205);
    glVertex2i(845,205);
    glVertex2i(845,170);
    glVertex2i(760,170);
    glEnd();


         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(765,205);
    glVertex2i(770,205);
    glVertex2i(770,210);
    glVertex2i(765,210);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,195);
    glVertex2i(780,195);
    glVertex2i(780,200);
    glVertex2i(765,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,185);
    glVertex2i(780,185);
    glVertex2i(780,190);
    glVertex2i(765,190);
    glEnd();


             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,195);
    glVertex2i(800,195);
    glVertex2i(800,200);
    glVertex2i(785,200);
    glEnd();

            setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,185);
    glVertex2i(800,185);
    glVertex2i(800,190);
    glVertex2i(785,190);
    glEnd();
             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,195);
    glVertex2i(815,195);
    glVertex2i(815,200);
    glVertex2i(805,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,185);
    glVertex2i(815,185);
    glVertex2i(815,190);
    glVertex2i(805,190);
    glEnd();

                setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(680,170);
    glVertex2i(765,170);
    glVertex2i(765,175);
    glVertex2i(680,175);
    glEnd();

                 setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(690,175);
    glVertex2i(695,175);
    glVertex2i(695,180);
    glVertex2i(690,180);
    glEnd();

                   setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(730,175);
    glVertex2i(735,175);
    glVertex2i(735,180);
    glVertex2i(730,180);
    glEnd();

                    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(750,175);
    glVertex2i(755,175);
    glVertex2i(755,180);
    glVertex2i(750,180);
    glEnd();



//light bridge right building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,170);
    glVertex2i(845,170);
    glVertex2i(845,275);
    glVertex2i(815,275);
    glEnd();

         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(815,275);
    glVertex2i(820,275);
    glVertex2i(820,280);
    glVertex2i(815,280);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,200);
    glVertex2i(830,200);
    glVertex2i(830,215);
    glVertex2i(820,215);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,200);
    glVertex2i(845,200);
    glVertex2i(845,215);
    glVertex2i(835,215);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,220);
    glVertex2i(830,220);
    glVertex2i(830,235);
    glVertex2i(820,235);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,220);
    glVertex2i(845,220);
    glVertex2i(845,235);
    glVertex2i(835,235);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,240);
    glVertex2i(830,240);
    glVertex2i(830,255);
    glVertex2i(820,255);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,240);
    glVertex2i(845,240);
    glVertex2i(845,255);
    glVertex2i(835,255);
    glEnd();

          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(845,170);
    glVertex2i(965,170);
    glVertex2i(965,295);
    glVertex2i(845,295);
    glEnd();


          setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(855,295);
    glVertex2i(865,295);
    glVertex2i(865,300);
    glVertex2i(855,300);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(865,295);
    glVertex2i(960,295);
    glVertex2i(960,315);
    glVertex2i(865,315);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(905,315);
    glVertex2i(935,315);
    glVertex2i(935,320);
    glVertex2i(905,320);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(935,315);
    glVertex2i(945,315);
    glVertex2i(945,380);
    glVertex2i(935,380);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,380);
    glVertex2i(935,380);
    glVertex2i(935,385);
    glVertex2i(930,385);
    glEnd();

       setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(900,380);
    glVertex2i(905,380);
    glVertex2i(905,385);
    glVertex2i(900,385);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,365);
    glVertex2i(915,365);
    glVertex2i(915,370);
    glVertex2i(910,370);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,355);
    glVertex2i(915,355);
    glVertex2i(915,360);
    glVertex2i(910,360);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,345);
    glVertex2i(915,345);
    glVertex2i(915,350);
    glVertex2i(910,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,335);
    glVertex2i(915,335);
    glVertex2i(915,340);
    glVertex2i(910,340);
    glEnd();



           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,365);
    glVertex2i(925,365);
    glVertex2i(925,370);
    glVertex2i(920,370);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,355);
    glVertex2i(925,355);
    glVertex2i(925,360);
    glVertex2i(920,360);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,345);
    glVertex2i(925,345);
    glVertex2i(925,350);
    glVertex2i(920,350);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,335);
    glVertex2i(925,335);
    glVertex2i(925,340);
    glVertex2i(920,340);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(875,295);
    glVertex2i(885,295);
    glVertex2i(885,310);
    glVertex2i(875,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,255);
    glVertex2i(875,255);
    glVertex2i(875,270);
    glVertex2i(860,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,215);
    glVertex2i(875,215);
    glVertex2i(875,230);
    glVertex2i(860,230);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,180);
    glVertex2i(875,180);
    glVertex2i(875,195);
    glVertex2i(860,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,255);
    glVertex2i(895,255);
    glVertex2i(895,270);
    glVertex2i(880,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,215);
    glVertex2i(895,215);
    glVertex2i(895,230);
    glVertex2i(880,230);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,180);
    glVertex2i(895,180);
    glVertex2i(895,195);
    glVertex2i(880,195);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,255);
    glVertex2i(915,255);
    glVertex2i(915,270);
    glVertex2i(900,270);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,215);
    glVertex2i(915,215);
    glVertex2i(915,230);
    glVertex2i(900,230);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,180);
    glVertex2i(915,180);
    glVertex2i(915,195);
    glVertex2i(900,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(890,295);
    glVertex2i(900,295);
    glVertex2i(900,310);
    glVertex2i(890,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(905,295);
    glVertex2i(915,295);
    glVertex2i(915,310);
    glVertex2i(905,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(940,295);
    glVertex2i(940,310);
    glVertex2i(930,310);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(935,295);
    glVertex2i(935,300);
    glVertex2i(930,300);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(945,295);
    glVertex2i(955,295);
    glVertex2i(955,310);
    glVertex2i(945,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,265);
    glVertex2i(940,265);
    glVertex2i(940,280);
    glVertex2i(935,280);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,260);
    glVertex2i(940,260);
    glVertex2i(940,245);
    glVertex2i(935,245);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,240);
    glVertex2i(940,240);
    glVertex2i(940,225);
    glVertex2i(935,225);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,220);
    glVertex2i(940,220);
    glVertex2i(940,205);
    glVertex2i(935,205);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,200);
    glVertex2i(940,200);
    glVertex2i(940,185);
    glVertex2i(935,185);
    glEnd();



          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(960,295);
    glVertex2i(965,295);
    glVertex2i(965,300);
    glVertex2i(960,300);
    glEnd();
    glPopMatrix();
}


void drawLightBuildingBottom(){





    //first left building

    glPushMatrix();
    glTranslatef(350,-250,0);
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(75,325);
    glVertex2i(75,450);
    glVertex2i(0,450);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(60,450);
    glVertex2i(65,450);
    glVertex2i(65,455);
    glVertex2i(60,455);
    glEnd();

       glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(15,325);
    glVertex2i(15,330);
    glVertex2i(0,330);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,335);
    glVertex2i(15,335);
    glVertex2i(15,345);
    glVertex2i(0,345);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,365);
    glVertex2i(15,365);
    glVertex2i(15,375);
    glVertex2i(0,375);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,380);
    glVertex2i(15,380);
    glVertex2i(15,390);
    glVertex2i(0,390);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,425);
    glVertex2i(15,425);
    glVertex2i(15,435);
    glVertex2i(0,435);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,410);
    glVertex2i(15,410);
    glVertex2i(15,420);
    glVertex2i(0,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,325);
    glVertex2i(35,325);
    glVertex2i(35,330);
    glVertex2i(20,330);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,335);
    glVertex2i(35,335);
    glVertex2i(35,345);
    glVertex2i(20,345);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,365);
    glVertex2i(35,365);
    glVertex2i(35,375);
    glVertex2i(20,375);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,380);
    glVertex2i(35,380);
    glVertex2i(35,390);
    glVertex2i(20,390);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,410);
    glVertex2i(35,410);
    glVertex2i(35,420);
    glVertex2i(20,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,425);
    glVertex2i(35,425);
    glVertex2i(35,435);
    glVertex2i(20,435);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,325);
    glVertex2i(55,325);
    glVertex2i(55,330);
    glVertex2i(40,330);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,335);
    glVertex2i(55,335);
    glVertex2i(55,345);
    glVertex2i(40,345);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,365);
    glVertex2i(55,365);
    glVertex2i(55,375);
    glVertex2i(40,375);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,380);
    glVertex2i(55,380);
    glVertex2i(55,390);
    glVertex2i(40,390);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,410);
    glVertex2i(55,410);
    glVertex2i(55,420);
    glVertex2i(40,420);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,425);
    glVertex2i(55,425);
    glVertex2i(55,435);
    glVertex2i(40,435);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,325);
    glVertex2i(70,325);
    glVertex2i(70,330);
    glVertex2i(60,330);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,335);
    glVertex2i(70,335);
    glVertex2i(70,345);
    glVertex2i(60,345);
    glEnd();

      glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,365);
    glVertex2i(70,365);
    glVertex2i(70,375);
    glVertex2i(60,375);
    glEnd();

  glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,380);
    glVertex2i(70,380);
    glVertex2i(70,390);
    glVertex2i(60,390);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,410);
    glVertex2i(70,410);
    glVertex2i(70,420);
    glVertex2i(60,420);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,425);
    glVertex2i(70,425);
    glVertex2i(70,435);
    glVertex2i(60,435);
    glEnd();

    //2nd left building

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,325);
    glVertex2i(140,325);
    glVertex2i(140,400);
    glVertex2i(75,400);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,400);
    glVertex2i(130,400);
    glVertex2i(130,410);
    glVertex2i(75,410);
    glEnd();
//first window row
setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(80,400);
    glVertex2i(85,400);
    glVertex2i(85,405);
    glVertex2i(80,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(90,400);
    glVertex2i(95,400);
    glVertex2i(95,405);
    glVertex2i(90,405);
    glEnd();

 setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(100,400);
    glVertex2i(105,400);
    glVertex2i(105,405);
    glVertex2i(100,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,400);
    glVertex2i(115,400);
    glVertex2i(115,405);
    glVertex2i(110,405);
    glEnd();
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(120,400);
    glVertex2i(125,400);
    glVertex2i(125,405);
    glVertex2i(120,405);
    glEnd();

    // row
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,345);
    glVertex2i(105,345);
    glVertex2i(105,335);
    glVertex2i(95,335);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,395);
    glVertex2i(120,395);
    glVertex2i(120,385);
    glVertex2i(110,385);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,380);
    glVertex2i(120,380);
    glVertex2i(120,370);
    glVertex2i(110,370);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,360);
    glVertex2i(120,360);
    glVertex2i(120,350);
    glVertex2i(110,350);
    glEnd();
       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,345);
    glVertex2i(120,345);
    glVertex2i(120,335);
    glVertex2i(110,335);
    glEnd();




     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,395);
    glVertex2i(135,395);
    glVertex2i(135,385);
    glVertex2i(125,385);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,380);
    glVertex2i(135,380);
    glVertex2i(135,370);
    glVertex2i(125,370);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,360);
    glVertex2i(135,360);
    glVertex2i(135,350);
    glVertex2i(125,350);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,345);
    glVertex2i(135,345);
    glVertex2i(135,335);
    glVertex2i(125,335);
    glEnd();
//3rd building
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(145,325);
    glVertex2i(155,325);
    glVertex2i(155,460);
    glVertex2i(145,460);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(155,460);
    glVertex2i(160,460);
    glVertex2i(160,465);
    glVertex2i(155,465);
    glEnd();


     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(165,460);
    glVertex2i(170,460);
    glVertex2i(170,470);
    glVertex2i(165,470);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(175,460);
    glVertex2i(180,460);
    glVertex2i(180,470);
    glVertex2i(175,470);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(185,460);
    glVertex2i(190,460);
    glVertex2i(190,465);
    glVertex2i(185,465);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,450);
    glVertex2i(185,450);
    glVertex2i(185,440);
    glVertex2i(160,440);
    glEnd();


      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,435);
    glVertex2i(185,435);
    glVertex2i(185,425);
    glVertex2i(160,425);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,420);
    glVertex2i(185,420);
    glVertex2i(185,410);
    glVertex2i(160,410);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,390);
    glVertex2i(185,390);
    glVertex2i(185,380);
    glVertex2i(160,380);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,375);
    glVertex2i(185,375);
    glVertex2i(185,365);
    glVertex2i(160,365);
    glEnd();
           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,360);
    glVertex2i(185,360);
    glVertex2i(185,350);
    glVertex2i(160,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,335);
    glVertex2i(185,335);
    glVertex2i(185,325);
    glVertex2i(160,325);
    glEnd();
    //4th building
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(200,325);
    glVertex2i(220,325);
    glVertex2i(220,415);
    glVertex2i(200,415);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,335);
    glVertex2i(215,335);
    glVertex2i(215,345);
    glVertex2i(205,345);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,350);
    glVertex2i(215,350);
    glVertex2i(215,360);
    glVertex2i(205,360);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,365);
    glVertex2i(215,365);
    glVertex2i(215,375);
    glVertex2i(205,375);
    glEnd();
          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,380);
    glVertex2i(215,380);
    glVertex2i(215,390);
    glVertex2i(205,390);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,395);
    glVertex2i(215,395);
    glVertex2i(215,405);
    glVertex2i(205,405);
    glEnd();


     setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(220,415);
    glVertex2i(225,415);
    glVertex2i(225,420);
    glVertex2i(220,420);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(235,415);
    glVertex2i(250,415);
    glVertex2i(250,425);
    glVertex2i(235,425);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(255,415);
    glVertex2i(260,415);
    glVertex2i(260,425);
    glVertex2i(255,425);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(280,415);
    glVertex2i(285,415);
    glVertex2i(285,420);
    glVertex2i(280,420);
    glEnd();
//windows
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,400);
    glVertex2i(240,400);
    glVertex2i(240,410);
    glVertex2i(225,410);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,395);
    glVertex2i(240,395);
    glVertex2i(240,385);
    glVertex2i(225,385);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,380);
    glVertex2i(240,380);
    glVertex2i(240,370);
    glVertex2i(225,370);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,350);
    glVertex2i(240,350);
    glVertex2i(240,340);
    glVertex2i(225,340);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,335);
    glVertex2i(240,335);
    glVertex2i(240,325);
    glVertex2i(225,325);
    glEnd();


   setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,400);
    glVertex2i(260,400);
    glVertex2i(260,410);
    glVertex2i(245,410);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,395);
    glVertex2i(260,395);
    glVertex2i(260,385);
    glVertex2i(245,385);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,380);
    glVertex2i(260,380);
    glVertex2i(260,370);
    glVertex2i(245,370);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,350);
    glVertex2i(260,350);
    glVertex2i(260,340);
    glVertex2i(245,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,335);
    glVertex2i(260,335);
    glVertex2i(260,325);
    glVertex2i(245,325);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,400);
    glVertex2i(280,400);
    glVertex2i(280,410);
    glVertex2i(265,410);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,395);
    glVertex2i(280,395);
    glVertex2i(280,385);
    glVertex2i(265,385);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,380);
    glVertex2i(280,380);
    glVertex2i(280,370);
    glVertex2i(265,370);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,350);
    glVertex2i(280,350);
    glVertex2i(280,340);
    glVertex2i(265,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,335);
    glVertex2i(280,335);
    glVertex2i(280,325);
    glVertex2i(265,325);
    glEnd();

    //5th building
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(290,225);
    glVertex2i(400,225);
    glVertex2i(400,365);
    glVertex2i(290,365);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(300,365);
    glVertex2i(305,365);
    glVertex2i(305,370);
    glVertex2i(300,370);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(340,365);
    glVertex2i(345,365);
    glVertex2i(345,370);
    glVertex2i(340,370);
    glEnd();

    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(390,365);
    glVertex2i(395,365);
    glVertex2i(395,370);
    glVertex2i(390,370);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,235);
    glVertex2i(325,235);
    glVertex2i(325,255);
    glVertex2i(320,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,235);
    glVertex2i(360,235);
    glVertex2i(360,255);
    glVertex2i(350,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,235);
    glVertex2i(380,235);
    glVertex2i(380,255);
    glVertex2i(370,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,235);
    glVertex2i(400,235);
    glVertex2i(400,255);
    glVertex2i(390,255);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,260);
    glVertex2i(325,260);
    glVertex2i(325,280);
    glVertex2i(320,280);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,260);
    glVertex2i(360,260);
    glVertex2i(360,280);
    glVertex2i(350,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,260);
    glVertex2i(380,260);
    glVertex2i(380,280);
    glVertex2i(370,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,260);
    glVertex2i(400,260);
    glVertex2i(400,280);
    glVertex2i(390,280);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,285);
    glVertex2i(325,285);
    glVertex2i(325,305);
    glVertex2i(320,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,285);
    glVertex2i(360,285);
    glVertex2i(360,305);
    glVertex2i(350,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,285);
    glVertex2i(380,285);
    glVertex2i(380,305);
    glVertex2i(370,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,285);
    glVertex2i(400,285);
    glVertex2i(400,305);
    glVertex2i(390,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,310);
    glVertex2i(325,310);
    glVertex2i(325,330);
    glVertex2i(320,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,310);
    glVertex2i(360,310);
    glVertex2i(360,330);
    glVertex2i(350,330);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,310);
    glVertex2i(380,310);
    glVertex2i(380,330);
    glVertex2i(370,330);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,310);
    glVertex2i(400,310);
    glVertex2i(400,330);
    glVertex2i(390,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,335);
    glVertex2i(325,335);
    glVertex2i(325,355);
    glVertex2i(320,355);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,335);
    glVertex2i(360,335);
    glVertex2i(360,355);
    glVertex2i(350,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,335);
    glVertex2i(380,335);
    glVertex2i(380,355);
    glVertex2i(370,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,335);
    glVertex2i(400,335);
    glVertex2i(400,355);
    glVertex2i(390,355);
    glEnd();
//6th building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(430,265);
    glVertex2i(465,265);
    glVertex2i(465,315);
    glVertex2i(430,315);
    glEnd();

        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(465,315);
    glVertex2i(470,315);
    glVertex2i(470,320);
    glVertex2i(465,320);
    glEnd();


        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(555,315);
    glVertex2i(560,315);
    glVertex2i(560,320);
    glVertex2i(555,320);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,275);
    glVertex2i(440,275);
    glVertex2i(440,290);
    glVertex2i(435,290);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,295);
    glVertex2i(440,295);
    glVertex2i(440,310);
    glVertex2i(435,310);
    glEnd();



           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,275);
    glVertex2i(450,275);
    glVertex2i(450,290);
    glVertex2i(445,290);
    glEnd();


           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,295);
    glVertex2i(450,295);
    glVertex2i(450,310);
    glVertex2i(445,310);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,275);
    glVertex2i(460,275);
    glVertex2i(460,290);
    glVertex2i(455,290);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,295);
    glVertex2i(460,295);
    glVertex2i(460,310);
    glVertex2i(455,310);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,295);
    glVertex2i(480,295);
    glVertex2i(480,310);
    glVertex2i(475,310);
    glEnd();
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,275);
    glVertex2i(480,275);
    glVertex2i(480,290);
    glVertex2i(475,290);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,295);
    glVertex2i(490,295);
    glVertex2i(490,310);
    glVertex2i(485,310);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,275);
    glVertex2i(490,275);
    glVertex2i(490,290);
    glVertex2i(485,290);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,295);
    glVertex2i(510,295);
    glVertex2i(510,310);
    glVertex2i(505,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();
setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,295);
    glVertex2i(520,295);
    glVertex2i(520,310);
    glVertex2i(515,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,275);
    glVertex2i(520,275);
    glVertex2i(520,290);
    glVertex2i(515,290);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,295);
    glVertex2i(540,295);
    glVertex2i(540,310);
    glVertex2i(535,310);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,275);
    glVertex2i(540,275);
    glVertex2i(540,290);
    glVertex2i(535,290);
    glEnd();

  setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,245);
    glVertex2i(540,245);
    glVertex2i(540,260);
    glVertex2i(535,260);
    glEnd();

setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,225);
    glVertex2i(540,225);
    glVertex2i(540,240);
    glVertex2i(535,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,170);
    glVertex2i(540,170);
    glVertex2i(540,185);
    glVertex2i(535,185);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,295);
    glVertex2i(550,295);
    glVertex2i(550,310);
    glVertex2i(545,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,275);
    glVertex2i(550,275);
    glVertex2i(550,290);
    glVertex2i(545,290);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,245);
    glVertex2i(550,245);
    glVertex2i(550,260);
    glVertex2i(545,260);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,225);
    glVertex2i(550,225);
    glVertex2i(550,240);
    glVertex2i(545,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,190);
    glVertex2i(550,190);
    glVertex2i(550,205);
    glVertex2i(545,205);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,170);
    glVertex2i(550,170);
    glVertex2i(550,185);
    glVertex2i(545,185);
    glEnd();


    //midbuild

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(365,170);
    glVertex2i(525,170);
    glVertex2i(525,270);
    glVertex2i(365,270);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(375,270);
    glVertex2i(385,270);
    glVertex2i(385,275);
    glVertex2i(375,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(420,270);
    glVertex2i(430,270);
    glVertex2i(430,275);
    glVertex2i(420,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(510,270);
    glVertex2i(520,270);
    glVertex2i(520,275);
    glVertex2i(510,275);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,190);
    glVertex2i(390,190);
    glVertex2i(390,200);
    glVertex2i(385,200);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,220);
    glVertex2i(390,220);
    glVertex2i(390,230);
    glVertex2i(385,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,250);
    glVertex2i(390,250);
    glVertex2i(390,260);
    glVertex2i(385,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,190);
    glVertex2i(400,190);
    glVertex2i(400,200);
    glVertex2i(395,200);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,220);
    glVertex2i(400,220);
    glVertex2i(400,230);
    glVertex2i(395,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,250);
    glVertex2i(400,250);
    glVertex2i(400,260);
    glVertex2i(395,260);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,250);
    glVertex2i(455,250);
    glVertex2i(455,260);
    glVertex2i(435,260);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,220);
    glVertex2i(455,220);
    glVertex2i(455,230);
    glVertex2i(435,230);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,200);
    glVertex2i(455,200);
    glVertex2i(455,190);
    glVertex2i(435,190);
    glEnd();


   setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,250);
    glVertex2i(485,250);
    glVertex2i(485,260);
    glVertex2i(465,260);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,220);
    glVertex2i(485,220);
    glVertex2i(485,230);
    glVertex2i(465,230);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,200);
    glVertex2i(485,200);
    glVertex2i(485,190);
    glVertex2i(465,190);
    glEnd();
  setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,250);
    glVertex2i(515,250);
    glVertex2i(515,260);
    glVertex2i(495,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,220);
    glVertex2i(515,220);
    glVertex2i(515,230);
    glVertex2i(495,230);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,200);
    glVertex2i(515,200);
    glVertex2i(515,190);
    glVertex2i(495,190);
    glEnd();
//light bridge
       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(525,220);
    glVertex2i(815,220);
    glVertex2i(815,235);
    glVertex2i(525,235);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(575,220);
    glVertex2i(595,220);
    glVertex2i(595,215);
    glVertex2i(575,215);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,220);
    glVertex2i(590,220);
    glVertex2i(590,170);
    glVertex2i(580,170);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(585,235);
    glVertex2i(590,235);
    glVertex2i(590,255);
    glVertex2i(585,255);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,255);
    glVertex2i(580,255);
    glEnd();

         setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,245);
    glVertex2i(580,245);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(650,235);
    glVertex2i(655,235);
    glVertex2i(655,255);
    glVertex2i(650,255);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,255);
    glVertex2i(645,255);
    glEnd();

          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,245);
    glVertex2i(645,245);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(715,235);
    glVertex2i(720,235);
    glVertex2i(720,255);
    glVertex2i(715,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,255);
    glVertex2i(710,255);
    glEnd();

           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,245);
    glVertex2i(710,245);
    glEnd();

             setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(770,235);
    glVertex2i(775,235);
    glVertex2i(775,255);
    glVertex2i(770,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,255);
    glVertex2i(765,255);
    glEnd();


           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,245);
    glVertex2i(765,245);
    glEnd();



       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,220);
    glVertex2i(655,220);
    glVertex2i(655,215);
    glVertex2i(635,215);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(640,220);
    glVertex2i(650,220);
    glVertex2i(650,170);
    glVertex2i(640,170);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(695,220);
    glVertex2i(715,220);
    glVertex2i(715,215);
    glVertex2i(695,215);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(710,220);
    glVertex2i(710,170);
    glVertex2i(700,170);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(755,220);
    glVertex2i(775,220);
    glVertex2i(775,215);
    glVertex2i(755,215);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,220);
    glVertex2i(770,220);
    glVertex2i(770,170);
    glVertex2i(760,170);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,205);
    glVertex2i(845,205);
    glVertex2i(845,170);
    glVertex2i(760,170);
    glEnd();


         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(765,205);
    glVertex2i(770,205);
    glVertex2i(770,210);
    glVertex2i(765,210);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,195);
    glVertex2i(780,195);
    glVertex2i(780,200);
    glVertex2i(765,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,185);
    glVertex2i(780,185);
    glVertex2i(780,190);
    glVertex2i(765,190);
    glEnd();


             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,195);
    glVertex2i(800,195);
    glVertex2i(800,200);
    glVertex2i(785,200);
    glEnd();

            setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,185);
    glVertex2i(800,185);
    glVertex2i(800,190);
    glVertex2i(785,190);
    glEnd();
             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,195);
    glVertex2i(815,195);
    glVertex2i(815,200);
    glVertex2i(805,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,185);
    glVertex2i(815,185);
    glVertex2i(815,190);
    glVertex2i(805,190);
    glEnd();

                setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(680,170);
    glVertex2i(765,170);
    glVertex2i(765,175);
    glVertex2i(680,175);
    glEnd();

                 setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(690,175);
    glVertex2i(695,175);
    glVertex2i(695,180);
    glVertex2i(690,180);
    glEnd();

                   setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(730,175);
    glVertex2i(735,175);
    glVertex2i(735,180);
    glVertex2i(730,180);
    glEnd();

                    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(750,175);
    glVertex2i(755,175);
    glVertex2i(755,180);
    glVertex2i(750,180);
    glEnd();



//light bridge right building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,170);
    glVertex2i(845,170);
    glVertex2i(845,275);
    glVertex2i(815,275);
    glEnd();

         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(815,275);
    glVertex2i(820,275);
    glVertex2i(820,280);
    glVertex2i(815,280);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,200);
    glVertex2i(830,200);
    glVertex2i(830,215);
    glVertex2i(820,215);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,200);
    glVertex2i(845,200);
    glVertex2i(845,215);
    glVertex2i(835,215);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,220);
    glVertex2i(830,220);
    glVertex2i(830,235);
    glVertex2i(820,235);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,220);
    glVertex2i(845,220);
    glVertex2i(845,235);
    glVertex2i(835,235);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,240);
    glVertex2i(830,240);
    glVertex2i(830,255);
    glVertex2i(820,255);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,240);
    glVertex2i(845,240);
    glVertex2i(845,255);
    glVertex2i(835,255);
    glEnd();

          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(845,170);
    glVertex2i(965,170);
    glVertex2i(965,295);
    glVertex2i(845,295);
    glEnd();


          setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(855,295);
    glVertex2i(865,295);
    glVertex2i(865,300);
    glVertex2i(855,300);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(865,295);
    glVertex2i(960,295);
    glVertex2i(960,315);
    glVertex2i(865,315);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(905,315);
    glVertex2i(935,315);
    glVertex2i(935,320);
    glVertex2i(905,320);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(935,315);
    glVertex2i(945,315);
    glVertex2i(945,380);
    glVertex2i(935,380);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,380);
    glVertex2i(935,380);
    glVertex2i(935,385);
    glVertex2i(930,385);
    glEnd();

       setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(900,380);
    glVertex2i(905,380);
    glVertex2i(905,385);
    glVertex2i(900,385);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,365);
    glVertex2i(915,365);
    glVertex2i(915,370);
    glVertex2i(910,370);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,355);
    glVertex2i(915,355);
    glVertex2i(915,360);
    glVertex2i(910,360);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,345);
    glVertex2i(915,345);
    glVertex2i(915,350);
    glVertex2i(910,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,335);
    glVertex2i(915,335);
    glVertex2i(915,340);
    glVertex2i(910,340);
    glEnd();



           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,365);
    glVertex2i(925,365);
    glVertex2i(925,370);
    glVertex2i(920,370);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,355);
    glVertex2i(925,355);
    glVertex2i(925,360);
    glVertex2i(920,360);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,345);
    glVertex2i(925,345);
    glVertex2i(925,350);
    glVertex2i(920,350);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,335);
    glVertex2i(925,335);
    glVertex2i(925,340);
    glVertex2i(920,340);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(875,295);
    glVertex2i(885,295);
    glVertex2i(885,310);
    glVertex2i(875,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,255);
    glVertex2i(875,255);
    glVertex2i(875,270);
    glVertex2i(860,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,215);
    glVertex2i(875,215);
    glVertex2i(875,230);
    glVertex2i(860,230);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,180);
    glVertex2i(875,180);
    glVertex2i(875,195);
    glVertex2i(860,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,255);
    glVertex2i(895,255);
    glVertex2i(895,270);
    glVertex2i(880,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,215);
    glVertex2i(895,215);
    glVertex2i(895,230);
    glVertex2i(880,230);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,180);
    glVertex2i(895,180);
    glVertex2i(895,195);
    glVertex2i(880,195);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,255);
    glVertex2i(915,255);
    glVertex2i(915,270);
    glVertex2i(900,270);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,215);
    glVertex2i(915,215);
    glVertex2i(915,230);
    glVertex2i(900,230);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,180);
    glVertex2i(915,180);
    glVertex2i(915,195);
    glVertex2i(900,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(890,295);
    glVertex2i(900,295);
    glVertex2i(900,310);
    glVertex2i(890,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(905,295);
    glVertex2i(915,295);
    glVertex2i(915,310);
    glVertex2i(905,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(940,295);
    glVertex2i(940,310);
    glVertex2i(930,310);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(935,295);
    glVertex2i(935,300);
    glVertex2i(930,300);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(945,295);
    glVertex2i(955,295);
    glVertex2i(955,310);
    glVertex2i(945,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,265);
    glVertex2i(940,265);
    glVertex2i(940,280);
    glVertex2i(935,280);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,260);
    glVertex2i(940,260);
    glVertex2i(940,245);
    glVertex2i(935,245);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,240);
    glVertex2i(940,240);
    glVertex2i(940,225);
    glVertex2i(935,225);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,220);
    glVertex2i(940,220);
    glVertex2i(940,205);
    glVertex2i(935,205);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,200);
    glVertex2i(940,200);
    glVertex2i(940,185);
    glVertex2i(935,185);
    glEnd();



          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(960,295);
    glVertex2i(965,295);
    glVertex2i(965,300);
    glVertex2i(960,300);
    glEnd();

    glPopMatrix();
}

void drawLightLeftMore(){
    //first left building


    glPushMatrix();
    glTranslatef(150,-160,0);
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(75,325);
    glVertex2i(75,450);
    glVertex2i(0,450);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(60,450);
    glVertex2i(65,450);
    glVertex2i(65,455);
    glVertex2i(60,455);
    glEnd();

       glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(15,325);
    glVertex2i(15,330);
    glVertex2i(0,330);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,335);
    glVertex2i(15,335);
    glVertex2i(15,345);
    glVertex2i(0,345);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,365);
    glVertex2i(15,365);
    glVertex2i(15,375);
    glVertex2i(0,375);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,380);
    glVertex2i(15,380);
    glVertex2i(15,390);
    glVertex2i(0,390);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,425);
    glVertex2i(15,425);
    glVertex2i(15,435);
    glVertex2i(0,435);
    glEnd();


          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,410);
    glVertex2i(15,410);
    glVertex2i(15,420);
    glVertex2i(0,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,325);
    glVertex2i(35,325);
    glVertex2i(35,330);
    glVertex2i(20,330);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,335);
    glVertex2i(35,335);
    glVertex2i(35,345);
    glVertex2i(20,345);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,365);
    glVertex2i(35,365);
    glVertex2i(35,375);
    glVertex2i(20,375);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,380);
    glVertex2i(35,380);
    glVertex2i(35,390);
    glVertex2i(20,390);
    glEnd();


        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,410);
    glVertex2i(35,410);
    glVertex2i(35,420);
    glVertex2i(20,420);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(20,425);
    glVertex2i(35,425);
    glVertex2i(35,435);
    glVertex2i(20,435);
    glEnd();

         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,325);
    glVertex2i(55,325);
    glVertex2i(55,330);
    glVertex2i(40,330);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,335);
    glVertex2i(55,335);
    glVertex2i(55,345);
    glVertex2i(40,345);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,365);
    glVertex2i(55,365);
    glVertex2i(55,375);
    glVertex2i(40,375);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,380);
    glVertex2i(55,380);
    glVertex2i(55,390);
    glVertex2i(40,390);
    glEnd();


         glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,410);
    glVertex2i(55,410);
    glVertex2i(55,420);
    glVertex2i(40,420);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(40,425);
    glVertex2i(55,425);
    glVertex2i(55,435);
    glVertex2i(40,435);
    glEnd();

          glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,325);
    glVertex2i(70,325);
    glVertex2i(70,330);
    glVertex2i(60,330);
    glEnd();

        glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,335);
    glVertex2i(70,335);
    glVertex2i(70,345);
    glVertex2i(60,345);
    glEnd();

      glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,365);
    glVertex2i(70,365);
    glVertex2i(70,375);
    glVertex2i(60,375);
    glEnd();

  glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,380);
    glVertex2i(70,380);
    glVertex2i(70,390);
    glVertex2i(60,390);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,410);
    glVertex2i(70,410);
    glVertex2i(70,420);
    glVertex2i(60,420);
    glEnd();
 glPointSize(5.0);
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(60,425);
    glVertex2i(70,425);
    glVertex2i(70,435);
    glVertex2i(60,435);
    glEnd();

    //2nd left building

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,325);
    glVertex2i(140,325);
    glVertex2i(140,400);
    glVertex2i(75,400);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(75,400);
    glVertex2i(130,400);
    glVertex2i(130,410);
    glVertex2i(75,410);
    glEnd();
//first window row
setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(80,400);
    glVertex2i(85,400);
    glVertex2i(85,405);
    glVertex2i(80,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(90,400);
    glVertex2i(95,400);
    glVertex2i(95,405);
    glVertex2i(90,405);
    glEnd();

 setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(100,400);
    glVertex2i(105,400);
    glVertex2i(105,405);
    glVertex2i(100,405);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,400);
    glVertex2i(115,400);
    glVertex2i(115,405);
    glVertex2i(110,405);
    glEnd();
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(120,400);
    glVertex2i(125,400);
    glVertex2i(125,405);
    glVertex2i(120,405);
    glEnd();

    // row
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,345);
    glVertex2i(105,345);
    glVertex2i(105,335);
    glVertex2i(95,335);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,395);
    glVertex2i(120,395);
    glVertex2i(120,385);
    glVertex2i(110,385);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,380);
    glVertex2i(120,380);
    glVertex2i(120,370);
    glVertex2i(110,370);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,360);
    glVertex2i(120,360);
    glVertex2i(120,350);
    glVertex2i(110,350);
    glEnd();
       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(110,345);
    glVertex2i(120,345);
    glVertex2i(120,335);
    glVertex2i(110,335);
    glEnd();




     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,395);
    glVertex2i(135,395);
    glVertex2i(135,385);
    glVertex2i(125,385);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,380);
    glVertex2i(135,380);
    glVertex2i(135,370);
    glVertex2i(125,370);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,360);
    glVertex2i(135,360);
    glVertex2i(135,350);
    glVertex2i(125,350);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(125,345);
    glVertex2i(135,345);
    glVertex2i(135,335);
    glVertex2i(125,335);
    glEnd();
//3rd building
     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(145,325);
    glVertex2i(155,325);
    glVertex2i(155,460);
    glVertex2i(145,460);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(155,460);
    glVertex2i(160,460);
    glVertex2i(160,465);
    glVertex2i(155,465);
    glEnd();


     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(165,460);
    glVertex2i(170,460);
    glVertex2i(170,470);
    glVertex2i(165,470);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(175,460);
    glVertex2i(180,460);
    glVertex2i(180,470);
    glVertex2i(175,470);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(185,460);
    glVertex2i(190,460);
    glVertex2i(190,465);
    glVertex2i(185,465);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,450);
    glVertex2i(185,450);
    glVertex2i(185,440);
    glVertex2i(160,440);
    glEnd();


      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,435);
    glVertex2i(185,435);
    glVertex2i(185,425);
    glVertex2i(160,425);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,420);
    glVertex2i(185,420);
    glVertex2i(185,410);
    glVertex2i(160,410);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,390);
    glVertex2i(185,390);
    glVertex2i(185,380);
    glVertex2i(160,380);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,375);
    glVertex2i(185,375);
    glVertex2i(185,365);
    glVertex2i(160,365);
    glEnd();
           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,360);
    glVertex2i(185,360);
    glVertex2i(185,350);
    glVertex2i(160,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(160,335);
    glVertex2i(185,335);
    glVertex2i(185,325);
    glVertex2i(160,325);
    glEnd();
    //4th building
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(200,325);
    glVertex2i(220,325);
    glVertex2i(220,415);
    glVertex2i(200,415);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,335);
    glVertex2i(215,335);
    glVertex2i(215,345);
    glVertex2i(205,345);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,350);
    glVertex2i(215,350);
    glVertex2i(215,360);
    glVertex2i(205,360);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,365);
    glVertex2i(215,365);
    glVertex2i(215,375);
    glVertex2i(205,375);
    glEnd();
          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,380);
    glVertex2i(215,380);
    glVertex2i(215,390);
    glVertex2i(205,390);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(205,395);
    glVertex2i(215,395);
    glVertex2i(215,405);
    glVertex2i(205,405);
    glEnd();


     setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(220,415);
    glVertex2i(225,415);
    glVertex2i(225,420);
    glVertex2i(220,420);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(235,415);
    glVertex2i(250,415);
    glVertex2i(250,425);
    glVertex2i(235,425);
    glEnd();

      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(255,415);
    glVertex2i(260,415);
    glVertex2i(260,425);
    glVertex2i(255,425);
    glEnd();


     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(280,415);
    glVertex2i(285,415);
    glVertex2i(285,420);
    glVertex2i(280,420);
    glEnd();
//windows
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,400);
    glVertex2i(240,400);
    glVertex2i(240,410);
    glVertex2i(225,410);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,395);
    glVertex2i(240,395);
    glVertex2i(240,385);
    glVertex2i(225,385);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,380);
    glVertex2i(240,380);
    glVertex2i(240,370);
    glVertex2i(225,370);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,350);
    glVertex2i(240,350);
    glVertex2i(240,340);
    glVertex2i(225,340);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(225,335);
    glVertex2i(240,335);
    glVertex2i(240,325);
    glVertex2i(225,325);
    glEnd();


   setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,400);
    glVertex2i(260,400);
    glVertex2i(260,410);
    glVertex2i(245,410);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,395);
    glVertex2i(260,395);
    glVertex2i(260,385);
    glVertex2i(245,385);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,380);
    glVertex2i(260,380);
    glVertex2i(260,370);
    glVertex2i(245,370);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,350);
    glVertex2i(260,350);
    glVertex2i(260,340);
    glVertex2i(245,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(245,335);
    glVertex2i(260,335);
    glVertex2i(260,325);
    glVertex2i(245,325);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,400);
    glVertex2i(280,400);
    glVertex2i(280,410);
    glVertex2i(265,410);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,395);
    glVertex2i(280,395);
    glVertex2i(280,385);
    glVertex2i(265,385);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,380);
    glVertex2i(280,380);
    glVertex2i(280,370);
    glVertex2i(265,370);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,350);
    glVertex2i(280,350);
    glVertex2i(280,340);
    glVertex2i(265,340);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(265,335);
    glVertex2i(280,335);
    glVertex2i(280,325);
    glVertex2i(265,325);
    glEnd();

    //5th building
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(290,225);
    glVertex2i(400,225);
    glVertex2i(400,365);
    glVertex2i(290,365);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(300,365);
    glVertex2i(305,365);
    glVertex2i(305,370);
    glVertex2i(300,370);
    glEnd();

    setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(340,365);
    glVertex2i(345,365);
    glVertex2i(345,370);
    glVertex2i(340,370);
    glEnd();

    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(390,365);
    glVertex2i(395,365);
    glVertex2i(395,370);
    glVertex2i(390,370);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,235);
    glVertex2i(325,235);
    glVertex2i(325,255);
    glVertex2i(320,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,235);
    glVertex2i(360,235);
    glVertex2i(360,255);
    glVertex2i(350,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,235);
    glVertex2i(380,235);
    glVertex2i(380,255);
    glVertex2i(370,255);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,235);
    glVertex2i(400,235);
    glVertex2i(400,255);
    glVertex2i(390,255);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,260);
    glVertex2i(325,260);
    glVertex2i(325,280);
    glVertex2i(320,280);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,260);
    glVertex2i(360,260);
    glVertex2i(360,280);
    glVertex2i(350,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,260);
    glVertex2i(380,260);
    glVertex2i(380,280);
    glVertex2i(370,280);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,260);
    glVertex2i(400,260);
    glVertex2i(400,280);
    glVertex2i(390,280);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,285);
    glVertex2i(325,285);
    glVertex2i(325,305);
    glVertex2i(320,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,285);
    glVertex2i(360,285);
    glVertex2i(360,305);
    glVertex2i(350,305);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,285);
    glVertex2i(380,285);
    glVertex2i(380,305);
    glVertex2i(370,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,285);
    glVertex2i(400,285);
    glVertex2i(400,305);
    glVertex2i(390,305);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,310);
    glVertex2i(325,310);
    glVertex2i(325,330);
    glVertex2i(320,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,310);
    glVertex2i(360,310);
    glVertex2i(360,330);
    glVertex2i(350,330);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,310);
    glVertex2i(380,310);
    glVertex2i(380,330);
    glVertex2i(370,330);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,310);
    glVertex2i(400,310);
    glVertex2i(400,330);
    glVertex2i(390,330);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(320,335);
    glVertex2i(325,335);
    glVertex2i(325,355);
    glVertex2i(320,355);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(350,335);
    glVertex2i(360,335);
    glVertex2i(360,355);
    glVertex2i(350,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(370,335);
    glVertex2i(380,335);
    glVertex2i(380,355);
    glVertex2i(370,355);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(390,335);
    glVertex2i(400,335);
    glVertex2i(400,355);
    glVertex2i(390,355);
    glEnd();
//6th building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(430,265);
    glVertex2i(465,265);
    glVertex2i(465,315);
    glVertex2i(430,315);
    glEnd();

        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(465,315);
    glVertex2i(470,315);
    glVertex2i(470,320);
    glVertex2i(465,320);
    glEnd();


        setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(555,315);
    glVertex2i(560,315);
    glVertex2i(560,320);
    glVertex2i(555,320);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,275);
    glVertex2i(440,275);
    glVertex2i(440,290);
    glVertex2i(435,290);
    glEnd();

          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,295);
    glVertex2i(440,295);
    glVertex2i(440,310);
    glVertex2i(435,310);
    glEnd();



           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,275);
    glVertex2i(450,275);
    glVertex2i(450,290);
    glVertex2i(445,290);
    glEnd();


           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(445,295);
    glVertex2i(450,295);
    glVertex2i(450,310);
    glVertex2i(445,310);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,275);
    glVertex2i(460,275);
    glVertex2i(460,290);
    glVertex2i(455,290);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(455,295);
    glVertex2i(460,295);
    glVertex2i(460,310);
    glVertex2i(455,310);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,295);
    glVertex2i(480,295);
    glVertex2i(480,310);
    glVertex2i(475,310);
    glEnd();
      setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(475,275);
    glVertex2i(480,275);
    glVertex2i(480,290);
    glVertex2i(475,290);
    glEnd();
    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,295);
    glVertex2i(490,295);
    glVertex2i(490,310);
    glVertex2i(485,310);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(485,275);
    glVertex2i(490,275);
    glVertex2i(490,290);
    glVertex2i(485,290);
    glEnd();

 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,295);
    glVertex2i(510,295);
    glVertex2i(510,310);
    glVertex2i(505,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(505,275);
    glVertex2i(510,275);
    glVertex2i(510,290);
    glVertex2i(505,290);
    glEnd();
setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,295);
    glVertex2i(520,295);
    glVertex2i(520,310);
    glVertex2i(515,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(515,275);
    glVertex2i(520,275);
    glVertex2i(520,290);
    glVertex2i(515,290);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,295);
    glVertex2i(540,295);
    glVertex2i(540,310);
    glVertex2i(535,310);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,275);
    glVertex2i(540,275);
    glVertex2i(540,290);
    glVertex2i(535,290);
    glEnd();

  setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,245);
    glVertex2i(540,245);
    glVertex2i(540,260);
    glVertex2i(535,260);
    glEnd();

setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,225);
    glVertex2i(540,225);
    glVertex2i(540,240);
    glVertex2i(535,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();


 setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,190);
    glVertex2i(540,190);
    glVertex2i(540,205);
    glVertex2i(535,205);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(535,170);
    glVertex2i(540,170);
    glVertex2i(540,185);
    glVertex2i(535,185);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,295);
    glVertex2i(550,295);
    glVertex2i(550,310);
    glVertex2i(545,310);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,275);
    glVertex2i(550,275);
    glVertex2i(550,290);
    glVertex2i(545,290);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,245);
    glVertex2i(550,245);
    glVertex2i(550,260);
    glVertex2i(545,260);
    glEnd();


    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,225);
    glVertex2i(550,225);
    glVertex2i(550,240);
    glVertex2i(545,240);
    glEnd();

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,190);
    glVertex2i(550,190);
    glVertex2i(550,205);
    glVertex2i(545,205);
    glEnd();

     setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(545,170);
    glVertex2i(550,170);
    glVertex2i(550,185);
    glVertex2i(545,185);
    glEnd();


    //midbuild

    setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(365,170);
    glVertex2i(525,170);
    glVertex2i(525,270);
    glVertex2i(365,270);
    glEnd();

     setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(375,270);
    glVertex2i(385,270);
    glVertex2i(385,275);
    glVertex2i(375,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(420,270);
    glVertex2i(430,270);
    glVertex2i(430,275);
    glVertex2i(420,275);
    glEnd();

      setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(510,270);
    glVertex2i(520,270);
    glVertex2i(520,275);
    glVertex2i(510,275);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,190);
    glVertex2i(390,190);
    glVertex2i(390,200);
    glVertex2i(385,200);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,220);
    glVertex2i(390,220);
    glVertex2i(390,230);
    glVertex2i(385,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(385,250);
    glVertex2i(390,250);
    glVertex2i(390,260);
    glVertex2i(385,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,190);
    glVertex2i(400,190);
    glVertex2i(400,200);
    glVertex2i(395,200);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,220);
    glVertex2i(400,220);
    glVertex2i(400,230);
    glVertex2i(395,230);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(395,250);
    glVertex2i(400,250);
    glVertex2i(400,260);
    glVertex2i(395,260);
    glEnd();


     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,250);
    glVertex2i(455,250);
    glVertex2i(455,260);
    glVertex2i(435,260);
    glEnd();

      setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,220);
    glVertex2i(455,220);
    glVertex2i(455,230);
    glVertex2i(435,230);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(435,200);
    glVertex2i(455,200);
    glVertex2i(455,190);
    glVertex2i(435,190);
    glEnd();


   setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,250);
    glVertex2i(485,250);
    glVertex2i(485,260);
    glVertex2i(465,260);
    glEnd();

     setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,220);
    glVertex2i(485,220);
    glVertex2i(485,230);
    glVertex2i(465,230);
    glEnd();

       setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(465,200);
    glVertex2i(485,200);
    glVertex2i(485,190);
    glVertex2i(465,190);
    glEnd();
  setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,250);
    glVertex2i(515,250);
    glVertex2i(515,260);
    glVertex2i(495,260);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,220);
    glVertex2i(515,220);
    glVertex2i(515,230);
    glVertex2i(495,230);
    glEnd();


    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(495,200);
    glVertex2i(515,200);
    glVertex2i(515,190);
    glVertex2i(495,190);
    glEnd();
//light bridge
       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(525,220);
    glVertex2i(815,220);
    glVertex2i(815,235);
    glVertex2i(525,235);
    glEnd();

       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(575,220);
    glVertex2i(595,220);
    glVertex2i(595,215);
    glVertex2i(575,215);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,220);
    glVertex2i(590,220);
    glVertex2i(590,170);
    glVertex2i(580,170);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(585,235);
    glVertex2i(590,235);
    glVertex2i(590,255);
    glVertex2i(585,255);
    glEnd();

        setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,255);
    glVertex2i(580,255);
    glEnd();

         setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(580,250);
    glVertex2i(585,250);
    glVertex2i(585,245);
    glVertex2i(580,245);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(650,235);
    glVertex2i(655,235);
    glVertex2i(655,255);
    glVertex2i(650,255);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,255);
    glVertex2i(645,255);
    glEnd();

          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(645,250);
    glVertex2i(650,250);
    glVertex2i(650,245);
    glVertex2i(645,245);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(715,235);
    glVertex2i(720,235);
    glVertex2i(720,255);
    glVertex2i(715,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,255);
    glVertex2i(710,255);
    glEnd();

           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(710,250);
    glVertex2i(715,250);
    glVertex2i(715,245);
    glVertex2i(710,245);
    glEnd();

             setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(770,235);
    glVertex2i(775,235);
    glVertex2i(775,255);
    glVertex2i(770,255);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,255);
    glVertex2i(765,255);
    glEnd();


           setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(765,250);
    glVertex2i(770,250);
    glVertex2i(770,245);
    glVertex2i(765,245);
    glEnd();



       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(635,220);
    glVertex2i(655,220);
    glVertex2i(655,215);
    glVertex2i(635,215);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(640,220);
    glVertex2i(650,220);
    glVertex2i(650,170);
    glVertex2i(640,170);
    glEnd();


       setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(695,220);
    glVertex2i(715,220);
    glVertex2i(715,215);
    glVertex2i(695,215);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(710,220);
    glVertex2i(710,170);
    glVertex2i(700,170);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(755,220);
    glVertex2i(775,220);
    glVertex2i(775,215);
    glVertex2i(755,215);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,220);
    glVertex2i(770,220);
    glVertex2i(770,170);
    glVertex2i(760,170);
    glEnd();


         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(760,205);
    glVertex2i(845,205);
    glVertex2i(845,170);
    glVertex2i(760,170);
    glEnd();


         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(765,205);
    glVertex2i(770,205);
    glVertex2i(770,210);
    glVertex2i(765,210);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,195);
    glVertex2i(780,195);
    glVertex2i(780,200);
    glVertex2i(765,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(765,185);
    glVertex2i(780,185);
    glVertex2i(780,190);
    glVertex2i(765,190);
    glEnd();


             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,195);
    glVertex2i(800,195);
    glVertex2i(800,200);
    glVertex2i(785,200);
    glEnd();

            setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(785,185);
    glVertex2i(800,185);
    glVertex2i(800,190);
    glVertex2i(785,190);
    glEnd();
             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,195);
    glVertex2i(815,195);
    glVertex2i(815,200);
    glVertex2i(805,200);
    glEnd();

              setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(805,185);
    glVertex2i(815,185);
    glVertex2i(815,190);
    glVertex2i(805,190);
    glEnd();

                setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(680,170);
    glVertex2i(765,170);
    glVertex2i(765,175);
    glVertex2i(680,175);
    glEnd();

                 setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(690,175);
    glVertex2i(695,175);
    glVertex2i(695,180);
    glVertex2i(690,180);
    glEnd();

                   setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(730,175);
    glVertex2i(735,175);
    glVertex2i(735,180);
    glVertex2i(730,180);
    glEnd();

                    setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(750,175);
    glVertex2i(755,175);
    glVertex2i(755,180);
    glVertex2i(750,180);
    glEnd();



//light bridge right building
         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(815,170);
    glVertex2i(845,170);
    glVertex2i(845,275);
    glVertex2i(815,275);
    glEnd();

         setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(815,275);
    glVertex2i(820,275);
    glVertex2i(820,280);
    glVertex2i(815,280);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,200);
    glVertex2i(830,200);
    glVertex2i(830,215);
    glVertex2i(820,215);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,200);
    glVertex2i(845,200);
    glVertex2i(845,215);
    glVertex2i(835,215);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,220);
    glVertex2i(830,220);
    glVertex2i(830,235);
    glVertex2i(820,235);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,220);
    glVertex2i(845,220);
    glVertex2i(845,235);
    glVertex2i(835,235);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(820,240);
    glVertex2i(830,240);
    glVertex2i(830,255);
    glVertex2i(820,255);
    glEnd();


         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(835,240);
    glVertex2i(845,240);
    glVertex2i(845,255);
    glVertex2i(835,255);
    glEnd();

          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(845,170);
    glVertex2i(965,170);
    glVertex2i(965,295);
    glVertex2i(845,295);
    glEnd();


          setColor("orange");
    glBegin(GL_QUADS);
    glVertex2i(855,295);
    glVertex2i(865,295);
    glVertex2i(865,300);
    glVertex2i(855,300);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(865,295);
    glVertex2i(960,295);
    glVertex2i(960,315);
    glVertex2i(865,315);
    glEnd();


          setColor("midBuilding");
    glBegin(GL_QUADS);
    glVertex2i(905,315);
    glVertex2i(935,315);
    glVertex2i(935,320);
    glVertex2i(905,320);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(935,315);
    glVertex2i(945,315);
    glVertex2i(945,380);
    glVertex2i(935,380);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,380);
    glVertex2i(935,380);
    glVertex2i(935,385);
    glVertex2i(930,385);
    glEnd();

       setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(900,380);
    glVertex2i(905,380);
    glVertex2i(905,385);
    glVertex2i(900,385);
    glEnd();

          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,365);
    glVertex2i(915,365);
    glVertex2i(915,370);
    glVertex2i(910,370);
    glEnd();


          setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,355);
    glVertex2i(915,355);
    glVertex2i(915,360);
    glVertex2i(910,360);
    glEnd();

           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,345);
    glVertex2i(915,345);
    glVertex2i(915,350);
    glVertex2i(910,350);
    glEnd();

            setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(910,335);
    glVertex2i(915,335);
    glVertex2i(915,340);
    glVertex2i(910,340);
    glEnd();



           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,365);
    glVertex2i(925,365);
    glVertex2i(925,370);
    glVertex2i(920,370);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,355);
    glVertex2i(925,355);
    glVertex2i(925,360);
    glVertex2i(920,360);
    glEnd();


           setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,345);
    glVertex2i(925,345);
    glVertex2i(925,350);
    glVertex2i(920,350);
    glEnd();

         setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(920,335);
    glVertex2i(925,335);
    glVertex2i(925,340);
    glVertex2i(920,340);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(875,295);
    glVertex2i(885,295);
    glVertex2i(885,310);
    glVertex2i(875,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,255);
    glVertex2i(875,255);
    glVertex2i(875,270);
    glVertex2i(860,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,215);
    glVertex2i(875,215);
    glVertex2i(875,230);
    glVertex2i(860,230);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(860,180);
    glVertex2i(875,180);
    glVertex2i(875,195);
    glVertex2i(860,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,255);
    glVertex2i(895,255);
    glVertex2i(895,270);
    glVertex2i(880,270);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,215);
    glVertex2i(895,215);
    glVertex2i(895,230);
    glVertex2i(880,230);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(880,180);
    glVertex2i(895,180);
    glVertex2i(895,195);
    glVertex2i(880,195);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,255);
    glVertex2i(915,255);
    glVertex2i(915,270);
    glVertex2i(900,270);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,215);
    glVertex2i(915,215);
    glVertex2i(915,230);
    glVertex2i(900,230);
    glEnd();

        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(900,180);
    glVertex2i(915,180);
    glVertex2i(915,195);
    glVertex2i(900,195);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(890,295);
    glVertex2i(900,295);
    glVertex2i(900,310);
    glVertex2i(890,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(905,295);
    glVertex2i(915,295);
    glVertex2i(915,310);
    glVertex2i(905,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(940,295);
    glVertex2i(940,310);
    glVertex2i(930,310);
    glEnd();


          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(930,295);
    glVertex2i(935,295);
    glVertex2i(935,300);
    glVertex2i(930,300);
    glEnd();



          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(945,295);
    glVertex2i(955,295);
    glVertex2i(955,310);
    glVertex2i(945,310);
    glEnd();


          setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,265);
    glVertex2i(940,265);
    glVertex2i(940,280);
    glVertex2i(935,280);
    glEnd();

           setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,260);
    glVertex2i(940,260);
    glVertex2i(940,245);
    glVertex2i(935,245);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,240);
    glVertex2i(940,240);
    glVertex2i(940,225);
    glVertex2i(935,225);
    glEnd();

             setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,220);
    glVertex2i(940,220);
    glVertex2i(940,205);
    glVertex2i(935,205);
    glEnd();

         setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(935,200);
    glVertex2i(940,200);
    glVertex2i(940,185);
    glVertex2i(935,185);
    glEnd();



          setColor("pink");
    glBegin(GL_QUADS);
    glVertex2i(960,295);
    glVertex2i(965,295);
    glVertex2i(965,300);
    glVertex2i(960,300);
    glEnd();

    glPopMatrix();

}


void drawFixBlank(){

    glPushMatrix();
    glTranslatef(210,-90,0);

    setColor("lightBuilding");
    glBegin(GL_QUADS);
    glVertex2i(0,325);
    glVertex2i(75,325);
    glVertex2i(75,425);
    glVertex2i(0,425);
    glEnd();
    glPopMatrix();


    //one
    glPushMatrix();
    glTranslatef(165,-80,0);
        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();
    glPopMatrix();




    //two
    glPushMatrix();
    glTranslatef(150,-80,0);
        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();
    glPopMatrix();


    //three
    glPushMatrix();
    glTranslatef(135,-80,0);
        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();
    glPopMatrix();



    //four
    glPushMatrix();
    glTranslatef(120,-80,0);
        setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,395);
    glVertex2i(105,395);
    glVertex2i(105,385);
    glVertex2i(95,385);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,380);
    glVertex2i(105,380);
    glVertex2i(105,370);
    glVertex2i(95,370);
    glEnd();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(95,360);
    glVertex2i(105,360);
    glVertex2i(105,350);
    glVertex2i(95,350);
    glEnd();
    glPopMatrix();



}
void update(int val){
    //animate train
    if(trainPosition <= -430) trainPosition = 1400;
    trainPosition -= trainSpeed;

    //animate reflection
    //even lines
    if(evenReflectionPosition >= 3.0)
        evenReflectionChange = -0.1;
    else if(evenReflectionPosition <= -6.0)
        evenReflectionChange = 0.1;

    evenReflectionPosition += evenReflectionChange;

    //odd lines
    if(oddReflectionPosition >= 3.0)
        oddReflectionChange = -0.1;
    else if(oddReflectionPosition <= -6.0)
        oddReflectionChange = 0.1;

    oddReflectionPosition += oddReflectionChange;

    //animate clouds
    if(smallCloudPosition <= -550) smallCloudPosition = 1300;
    smallCloudPosition -= smallCloudChange;

    if(bigCloud1Position >= 10.0)
        bigCloud1Change = -0.2;
    else if(bigCloud1Position <= -15.0)
        bigCloud1Change = 0.2;

    bigCloud1Position += bigCloud1Change;

    if(bigCloud2Position >= 15.0)
        bigCloud2Change = -0.15;
    else if(bigCloud2Position <= -10.0)
        bigCloud2Change = 0.15;

    bigCloud2Position += bigCloud2Change;

    //animate boats
    if(boat1Position >= 335.0)
        boat1Change = -0.5;
    else if(boat1Position <= 0)
        boat1Change = 0.5;

    boat1Position += boat1Change;


    glutPostRedisplay();
    glutTimerFunc(10, update,0);
}




















void playMusic(){
    PlaySound("music.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}


void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    drawBackground();
    drawSun();
    drawBigCloud1();
    drawBigCloud2();
    drawSmallCloud();
    drawLightBuilding();
    drawLightBuildingMore();
    drawLightBuildingBottom();
    drawLightLeftMore();
    drawFixBlank();
    drawTrain();
    drawBridge();
    drawBigBuilding();
    drawRightBuilding();
    drawWater();
    drawReflection();
    drawtree();
    drawBird();
    glFlush ();
}

void myInit (void)
{
    glPointSize(5.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1280.0, 0.0, 720.0);
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {
        case 's':
            if(trainSpeed >= 1) trainSpeed -= 1;
            break;

        case 'w':
            trainSpeed += 1;
            break;

        case 't':
            dayNight = !dayNight;
            break;

        case 'r':
            trainSpeed = 0;
            break;

        case 'x':
            trainSpeed = 5;

    glutPostRedisplay();

	}

}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1280, 720);
    glutInitWindowPosition (120, 60);
    glutCreateWindow ("Pixel City");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(0, update, 0);
    playMusic();
    glutMainLoop();
}
