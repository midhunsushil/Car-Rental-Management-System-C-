
void line(int p,int q,int l,char type='v',int type2=0)
  {
     int i;char hl,vl;
    /* Where (p,q)-margin (coordinate of top-left vertice of box border);
       type=v - For Vertical Line (default)
       type=h - For Horizontal Line
       l-length(horizontal distance) of border;
    */
    if(type2==1)
    {hl=45;vl=124;}   //hyphen(-)and or (|)

   /* else if(type2==2)
    {hl=205;vl=186;}
    else if(type2==3)
    {hl=205;vl=186;} */

    else
    {hl=196;vl=179;} //border characters

    textcolor(WHITE);
    if(type=='v')
    for(i=0;i<l;i++)  // Vertical line of length l
     { gotoxy(p,q+i);
       cprintf("%c",vl); //'7C'(hyphen); 'DE'(accented i); '7C' (or line); 'B3' (border);
     }
     else
     for(i=0;i<l;i++) // Horizontal Line of length l
      { gotoxy(p+i,q);
       cprintf("%c",hl);
      }
  }

void border(int p,int q,int l,int w,int type) //Use to make borders as the name suggests
  { /* Where (p,q)-margin (coordinate of top-left vertice of box border);
       w-width(vertical distance) of border;
       l-length(horizontal distance) of border;
       type => 2(double border)(default); type => 1(single border)
    */
    int i;
    char tl,tr,bl,br,hl,vl;
    if(type==1)
    {tl=218;tr=191;bl=192;br=217;hl=196;vl=179;}

    else
    {tl=201;tr=187;bl=200;br=188;hl=205;vl=186;}

    textcolor(WHITE);
    gotoxy(p,q);
    cprintf("%c",tl);//top-left
    gotoxy(p+l,q);
    cprintf("%c",tr);//top-right
    gotoxy(p,q+w);
    cprintf("%c",bl);//bottom-left
    gotoxy(p+l,q+w);
    cprintf("%c",br);//bottom-right

    for(i=1;i<w;i++)  // Vertical line for width w
     { gotoxy(p,q+i);
       cprintf("%c",vl);
       gotoxy(p+l,q+i);
       cprintf("%c",vl);
     }

     for(i=1;i<l;i++) // Horizontal Line of length l
     { gotoxy(p+i,q);
       cprintf("%c",hl);
       gotoxy(p+i,q+w);
       cprintf("%c",hl);
     }

  }

void crusor()//To get position of pointer in console window(for output purpose)
{ int x=1,y=1;
  char key;
  do
    { gotoxy(x,y);
      cout<<"      ";
      gotoxy(x,y);
      key=getch();
      if(key==' ')
        x++;
      else if(key=='\b')
       x--;
      else if(key=='\r')
       y++;
      else if(key=='p')
    {  gotoxy(1,1);
       cout<<x<<" "<<y;
    }

      else if(key=='r')
      {
        x=1;y=1;
      }
    }
  while(key!='N');

}

 void delay() { for(unsigned long i=0;i<40000000;i++)
                // Determines speed of loading Animation
                  {/*To delay output*/ }
              }

 void loading(short x,short y,short N=7)
 /* (x,y)-Position of Load Animation
    Loading Running delay(N=1 for 0.4786 s delay approx.)
 */
 { const char slash[4]={92,196,47,179};
   for(unsigned short i=0;i<N;i++)
   for(short j=0;j<4;j++)
    { gotoxy(x,y);textcolor(RED);
      putchar(slash[j]); delay();delay();
    }
 }