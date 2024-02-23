#include "TXLib.h"

    struct Tanker
{
 HDC Left;
 int x;
 int y;
 int v;
 int h;
 int w;
 bool visible;

void draw()
      {
       if(image == left || image == right)
        {
            txTransparentBlt(txDC(), x, y, w, h, 0, 0, TX_BLACK);
        }
      }

};

    struct Tank
  {
    HDC right;
    HDC left;
    HDC up;
    HDC down;
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

       else if(image == up || image == down)
        {
            txTransparentBlt(txDC(), x, y, h, w, image, 0, 0, TX_BLACK);
        }
    }



  };


    int main()
{
txCreateWindow (800, 600);

    HDC fon1 = txLoadImage("fon/fon1.bmp");
    Tank tank1 = {txLoadImage("Tanks/tank1Right.bmp"), txLoadImage("Tanks/tank1Left.bmp"), txLoadImage("Tanks/tank1Up.bmp"), txLoadImage("Tanks/tank1Down.bmp"), tank1.right, 600, 500, 10, 100, 200};
    Tanker tank2 = {txLoadImage("TankNPC/TankNPCright.bmp"), txLoadImage("TankNPC/TankNPCleft.bmp"), 600, 400, 15, 100, 200, true};


    while(true)
    {
       txSetFillColor(TX_BLACK);
       txClear();
       txBegin();


       txBitBlt(txDC(), 0, 0, 800, 600, fon1);
       tank1.draw();
       tank2.draw();

 {  //��� � ���������� ��� E 100
        if(GetAsyncKeyState('W'))
        {
            tank1.image = tank1.up;
            tank1.y -= tank1.v;
        }

        if(GetAsyncKeyState('S'))
        {
            tank1.image = tank1.down;
            tank1.y += tank1.v;
        }

        if(GetAsyncKeyState('A'))
        {
            tank1.image = tank1.left;
            tank1.x -= tank1.v;
        }

        if(GetAsyncKeyState('D'))
        {
            tank1.image = tank1.right;
            tank1.x += tank1.v;
        }

        if(tank1.x<0)
        {
            tank1.x=0;
        }

        if(tank1.x+tank1.w>800)
        {
            tank1.x=800-tank1.w;
        }

        if(tank1.y<0)
        {
            tank1.y=0;
        }

        if(tank1.y+tank1.h>600)
        {
            tank1.y=600-tank1.h;
        }

        if(tank1.y+tank1.h>100)
        {
       }


           tank1.y=100-tank1.h;
        }

    txEnd();
    txSleep(15);
    }

txTextCursor (false);
return 0;
}
