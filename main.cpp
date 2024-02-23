#include "TXLib.h"

struct Tank
{
    HDC right;
    HDC left;
    HDC up;
    HDC image;
    int x;
    int y;
    int v;
    int h;
    int w;

    void draw()
    {
        if(image == right || image == left)
        {
            txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_BLACK);
        }

        else if(image == up)
        {
            txTransparentBlt(txDC(), x, y, h, w, image, 0, 0, TX_BLACK);
        }
    }



};


int main()
{
txCreateWindow (800, 600);

    HDC fon1 = txLoadImage("fon/fon1.bmp");
    Tank tank1 = {txLoadImage("Tanks/tank1Right.bmp"), txLoadImage("Tanks/tank1Left.bmp"), txLoadImage("Tanks/tank1Up.bmp"), tank1.right, 600, 500, 10, 100, 200};

    Tank tank2 = {txLoadImage("TankNPC/TankNPCright.bmp"), txLoadImage("TankNPC/TankNPCleft.bmp"), tank2.right, tank2.right, -300, 0, 10, 100, 200};


    while(true)
    {
       txSetFillColor(TX_BLACK);
       txClear();
       txBegin();


       txBitBlt(txDC(), 0, 0, 800, 600, fon1);
       tank1.draw();
       tank2.draw();

        //ифы и управление для E 100
        if(GetAsyncKeyState('W'))
        {
            tank1.image = tank1.up;
            tank1.y = 400;
        }

        if(GetAsyncKeyState('A'))
        {
            tank1.image = tank1.left;
            tank1.x -= tank1.v;
            tank1.y = 500;
        }

        if(GetAsyncKeyState('D'))
        {
            tank1.image = tank1.right;
            tank1.x += tank1.v;
            tank1.y = 500;
        }

        if(tank1.x<0)
        {
            tank1.x=0;
        }

        if(tank1.x>800-tank1.w)
        {
            tank1.x=800-tank1.w;
        }

        if(tank1.y<0)
        {
            tank1.y=0;
        }

        if(tank1.y>600-tank1.h)
        {
            tank1.y=600-tank1.h;
        }

        tank2.x += tank2.v;
        if(tank2.x>1100)
        {
            tank2.v = -tank2.v;
            tank2.image = tank2.left;
        }
        if(tank2.x<-300)
        {
            tank2.v = -tank2.v;
            tank2.image = tank2.right;
        }

        txEnd();
        txSleep(15);
    }

txTextCursor (false);
return 0;
}
