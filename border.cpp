#include<iostream.h>
#include<conio.h>

void main()
  {
    int i,p,q,l,w;char c;
    /* Where (p,q)-margin (coordinate of top-left vertice of box border);
       w-width(vertical distance) of border;
       l-length(horizontal distance) of border;
    */
    while(c!='N')
   { cout<<"Enter margin of border "<<"["<<p<<" "<<q<<"]"<<" (x y)=> ";
    cin>>p>>q;
    clrscr();
    cout<<"\rEnter length & width "<<"["<<l<<" "<<w<<"]"<<" (l w)=> ";
    cin>>l>>w;
    textcolor(WHITE);
    gotoxy(p,q);
    cprintf("\xC9");
    gotoxy(p+l,q);
    cprintf("\xBB");
    gotoxy(p,q+w);
    cprintf("\xC8");
    gotoxy(p+l,q+w);
    cprintf("\xBC");

    for(i=1;i<w;i++)  // Vertical line for width w
     { gotoxy(p,q+i);
       cprintf("\xBA");
       gotoxy(p+l,q+i);
       cprintf("\xBA");
     }

     for(i=1;i<l;i++) // Horizontal Line of length l
     { gotoxy(p+i,q);
       cprintf("\xCD");
       gotoxy(p+i,q+w);
       cprintf("\xCD");
     }

   c=getch();clrscr();
   }

  }