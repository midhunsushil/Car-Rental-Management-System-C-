#include<windows.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"design.h"

char op;
void menu();
void ventry(char[],short,short);
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

 class Login
  {
    char usr[12];
    char pss[12];
    //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    public:
    int check();
  }L;

int Login::check()
  { //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    xx:
    clrscr();
    border(3,2,74,21,2);
    int i=0;
    textcolor(YELLOW);
    gotoxy(27,4);
    cprintf("WELCOME TO ### CAR RENTAL");
    gotoxy(27,5);
    cprintf("-------------------------");
    gotoxy(33,8);
    cprintf("System Login");
    gotoxy(33,9);
    cprintf("------------");
    border(24,12,27,7,1);
    gotoxy(27,14);
    //system("COLOR 71");
    SetConsoleTextAttribute(color, 3);
    cout<<"Username : ";
    //cprintf("Username : ");
    gotoxy(27,17);
    cout<<"Password : ";
    //cprintf("Password : ");

    //crusor();
    gotoxy(38,14);
    SetConsoleTextAttribute(color, 10);
    ventry(usr,2,12);
    gotoxy(38,17);

    while((pss[i]=getch())!='\r' && i<12)
     { if(pss[i]=='\b' && i>0)
	     { cout<<'\b'<<' '<<'\b';
          i--;
	     }
	    else if(i!=0 || pss[i]!='\b')
	     { cout << "*";
	       i++;
        }
	  }
    pss[i]='\0';
    gotoxy(38,18);
    cout<<pss<<endl;


    if(strcmp(usr,"admin") == 0 && strcmp(pss,"pass123") == 0)
      {
         cout<<'\a';
	      clrscr();
          return(1);
      }

    else
      {
	textcolor(RED + BLINK);
	gotoxy(22,21);cout<<'\a'<<'\a';
	cprintf("Invalid Username Or Password !!!");
	getch();
	textcolor(WHITE);
	goto xx;
      }
  }

 short namecmp(char* name,char* word)
 // To search for a 'word' in a 'name'
   { short sc,count=0;
     for(short i=0;i<=(strlen(name)-strlen(word));i++)
      { sc=0;
        for(short j=0;j<strlen(word);j++)
         if(tolower(name[i+j])!=tolower(word[j])) { sc=1; break; }
        if(sc==0) count++;
      }
     return count;
   }

 void ventry(char t[],short code=4,short N=1)
/* code=0 >> for inputing alphabets(a-Z), space, comma(,) & dot(.)
   code=1 >> for inputing numbers(0-9), dot(.) & '/'
   code=2 >> for inputing username / ID
   code=3 >> for normal input without space, ':' & ';'
   code=4 >> for menu input (only numbers 0-9)
*/
  { unsigned short i=0;
    if(code==0)
	  { while(i<N && (t[i]=getch())!='\r')
        if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='.'|| t[i]==',')
         { if(t[0]!=' '&& t[0]!='_') // To prevent space or '_' at first input
		      { cout << t[i];
		        i++;
	         }
         }
	     else if(t[i]==8 && i>0)
		   { cout<<"\b \b";
		     i--;
	    	}
	  }
    else if(code==1)
	  { while(i<N && (t[i]=getch())!='\r')
	    if((t[i]>=48 && t[i]<=57) || t[i]==46 || t[i] == '/')
	     { cout<<t[i];
	     	 i++;
        }
	    else if(t[i]==8 && i>0)
        { cout<<"\b \b";
		    i--;
	     }
	  }

    if(code==2)
	  { while(i<N && (t[i]=getch())!='\r')
        if((t[i]>=95 && t[i]<=122) || (t[i]>=46 && t[i]<=57) || (t[i]>=65 && t[i]<=90) || t[i]=='@')
		   { cout << t[i];
		     i++;
	    	}
	     else if(t[i]==8 && i>0)
		   { cout<<"\b \b";
		     i--;
	    	}
     }

    if(code==3)
	  { while(i<N && (t[i]=getch())!='\r')
        if((t[i]>=33 && t[i]<=126) && t[i]!=':' && t[i]!=';')
		   { cout << t[i];
		     i++;
	    	}
	     else if(t[i]==8 && i>0)
		   { cout << "\b \b";
		     i--;
	    	}
	  }

    else if(code==4)
	  { while(i<N && (t[i]=getch())!='\r')
	    if( t[i]>=48 && t[i]<=57 )
	     { cout<<t[i];
	     	 i++;
        }
	    else if(t[i]==8 && i>0)
        { cout<<"\b \b";
		    i--;
	     }
	  }
    t[i]='\0';
  }

 void voutput(short N,char t[],char o[]=NULL)
/* N >> for outputing N characters of the concatinated string
*/
  { unsigned short i=0;
    strcat(t," ");strcat(t,o);
    if(N<strlen(t))
     { for(i=N;i<N+3;i++) t[i]='.';
       strcat(t,"..");
       N+=2;
     }
    for(i=0;i<N&&i<strlen(t);i++)
    cout<<t[i];
  }



//            ***************** class Cars *******************
//## stored in cardata

 class Cars { char carid[6];
              char make[20];
              char model[20];
              unsigned short year;
              char category[20];
              char passengers;
              char description[10];
              short status; //1=avail. , 0=booked
        public:
              void getcar();
              void putcar();
              void CarTable();
              void AvailTable(char*&c);
              void switch_status(int op=2);
              char *retcarid() { return(carid); }
              char *retmodel() { return(model); }
              char *retmake() { return(make); }
              //char *retprice() { return(price); }
              ~Cars(){ /*Destructor to distroy this class when the scope is over*/ }
             }C;

 void Cars::getcar() {  cout<<"\n\tCarID => ";
                        ventry(carid,2,6);
                        cout<<"\n\tMAKE => ";
                        gets(make);
                        cout<<"\n\tModel => ";
                        gets(model);
                        cout<<"\n\tYEAR => ";
                        cin>>year;
                        cout<<"\n\tCATEGORY => ";
                        ventry(category,0,11);
                        cout<<"\n\tPassengers => ";
                        cin>>passengers;
                        cout<<"\n\tDescription[press ENTER to SKIP] => ";
                        gets(description);
                        status=1;//status=1 means available;
                     }

 void Cars::putcar() {  cout<<"\n\tCarID => "<<carid;      // Displayed on Table
                        cout<<"\n\tMAKE => "<<make;       // MAKE+model Displayed on table
                        cout<<"\n\tModel => "<<model;
                        cout<<"\n\tYEAR => "<<year;
                        cout<<"\n\tCATEGORY => "<<category;
                        cout<<"\n\tPassengers => "<<passengers;
                        //cout<<"\n\tDescription[press ENTER to SKIP] => ";
                      }

 void Cars::CarTable(){ border(4,3,73,20,1);
                        line(8,4,19);//Vertical line After No.
                        line(16,4,19);//Vertical line After Carid
                        line(37,4,19);//Vertical line After Car
                        line(55,4,19);// After Category
                        line(65,4,19);// After Price
                        line(5,5,72,'h');// Horizontal line
                        gotoxy(5,4);cout<<" No";gotoxy(9,4);cout<<" CarID";gotoxy(25,4);cout<<"CAR";
                        gotoxy(43,4);cout<<"CATEGORY";gotoxy(57,4);cout<<"Price/hr";gotoxy(69,4);cout<<"STATUS";
                        gotoxy(1,1);
                        int i=0,r=7;
                        ifstream carfile("carsdata",ios::in|ios::binary);
                        cout<<"\t\t\tDISPLAY AVAILABLE CARS";
                        //Read From File
                      while(carfile.read((char*)&C, sizeof(Cars)))
                       {
                        gotoxy(6, r);(i>8) ? cout<<(i+1):cout<<" "<<(i+1);
                        gotoxy(10,r);cout<<carid;
                        gotoxy(18,r);voutput(17,make,model);
                        gotoxy(39,r);cout<<category;
                        gotoxy(51,r);//cout<<C.price;
                        gotoxy(67,r);(status==1) ? cout<<"Available" : cout<<"BOOKED!";
                        i++;r++;
                       }
                      }

 void Cars::AvailTable(char* &c) { system("color 0E");
                                   clrscr();
                                   border(4,4,73,17,1);
                                   line(8,5,16,'v',1);//Vertical line After No.
                                   line(16,5,16,'v',1);//Vertical line After Carid
                                   line(35,5,16,'v',1);//Vertical line After Car
                                   line(55,5,16,'v',1);// After Category
                                   line(65,5,16,'v',1);// After Price
                                   line(5,6,72,'h',1);// Horizontal line
                                   gotoxy(5,5);cout<<" No";gotoxy(10,5);cout<<" Year";gotoxy(25,5);cout<<"CAR";gotoxy(42,5);cout<<"CATEGORY";gotoxy(57,5);cout<<"Price/hr";gotoxy(67,5);cout<<"Passengers";
                                   gotoxy(1,2);
                                   ifstream carfile("carsdata",ios::in|ios::binary);
                                   //Read From File
                                   int i,r;
                                   cout<<"\t\t\tDISPLAY AVAILABLE CARS";
                                   for(i=1,r=8;carfile.read((char*)&C, sizeof(C));)
                                   if(status==1)
                                    { gotoxy(5, r);cout<<"["<<i<<"]";
                                      gotoxy(10,r);cout<<year;
                                      gotoxy(18,r);cout<<make<<" "<<model;
                                      gotoxy(37,r);cout<<category;
                                      gotoxy(51,r);//cout<<C.price;
                                      gotoxy(67,r);cout<<passengers;
                                      i++,r++;
                                    }
                                   carfile.clear();
                                   carfile.seekg(0);
                                   gotoxy(5,24); cout<<"Select Car No. >> ";cin>>r;
                                   i=1;
                                   while(carfile.read((char*)&C, sizeof(C)))
                                    { if(i==r&&status==1) { strcpy(c,carid);
                                                            break;
                                                          }
                                      if(status==1) { i++; }
                                    }
                                 }

 void Cars::switch_status(int op) { if(op==1) status=1;
                                      else if(op==0) status=0;
                                      else (status==0) ? status=1 : status=0;
                                    }

 void status_edit(char *op="#Nothing") { fstream carfile("carsdata",ios::in|ios::out|ios::binary);
                                         while(carfile.read((char*)&C, sizeof(C)))
                                          { if(*op=='1'&&*(op+1)=='\0') C.switch_status(1);
                                            else if(*op=='0'&&*(op+1)=='\0') C.switch_status(0);
                                            else if(strcmp(C.retcarid(),op)==0)
                                             { C.switch_status();
                                               carfile.seekg(carfile.tellg()-sizeof(C));
                                               carfile.write((char*)&C, sizeof(C));
                                               break;
                                             }
                                            carfile.seekg(carfile.tellg()-sizeof(C));
                                            carfile.write((char*)&C, sizeof(C));
                                          }
                                       }


  void AddCar() { Cars C;
                  int i,N;
                  cout<<"\nEnter no. of cars to be added => ";
                  cin>>N;
                  clrscr();
                  ofstream carfile("carsdata",ios::out|ios::binary|ios::app);
                             //Write TO File
                  cout<<"\n\t\t\tADD NEW CAR";
                  for(i=0;i<N;i++)
                   { clrscr();
                     cout<<"\n\n\tAdd Car No. "<<(i+1)<<endl;
                     C.getcar();
                     carfile.write((char*)&C, sizeof(Cars));
                   }
                  carfile.close();
                }

 bool SearchCar(Cars& D, char *objective ="#Nothing")
 /* Can only search for make, model, carid and price
 */
   {  short count=0,searchstatus=0,i=0;
      Cars M[10];
      ifstream carfile("carsdata",ios::in|ios::out|ios::binary);
      if(*objective==NULL) return 0;

      //Read from File and Write to File
      while(carfile.read((char*)&C, sizeof(Cars)))
       { if(strcmp(objective,C.retcarid())==0||strcmpi(objective,C.retmodel())==0)
          { D=C;
            searchstatus++;
            break;
          }
         else if( strcmpi(objective,C.retmake())==0 ) count++;
       }

      carfile.clear();
      carfile.seekg(0);

      if(count==1)
       while(carfile.read((char*)&C, sizeof(Cars)))
        if(strcmpi(objective,C.retmake())==0)
         { D=C;
           searchstatus++;
           break;
         }

      if(count>1)
       { clrscr();
         cout<<"\nMore than one record found !\a\n";
         while(carfile.read((char*)&C, sizeof(Cars)))
          if(strcmpi(objective,C.retmake())==0)
           { M[i]=C; i++; }
         for(i=0;i<count;i++)
          { cout<<"\n\t["<<(i+1)<<"]"<<"\tCarID: "<<M[i].retcarid();
            cout<<"\t\tCAR: "<<M[i].retmake()<<" "<<M[i].retmodel();
          }
         int op;
         cout<<"\n\nOption => ";
         cin>>op;
         carfile.clear();
         D=M[op-1];
         searchstatus++;
       }

      if(searchstatus) return 1;
                  else return 0;

      carfile.close();
   }

 void UpdateCar() {  short updatestatus=0,i=0;
                     Cars D;
                     char update[20];
                     fstream carfile("carsdata",ios::in|ios::out|ios::binary);
                         //Read from File and Write to File
                     clrscr();
                     cout<<"\nEnter Carid/Model/Make of Car to Update => ";
                     gets(update);
                     SearchCar(D,update);
                     D.putcar();
                     getch();
                     while(carfile.read((char*)&C, sizeof(Cars)))
                       if(strcmp(update,C.retcarid())==0||strcmpi(update,C.retmodel())==0||strcmp(D.retcarid(),C.retcarid())==0)
                         { cout<<"\nCar Found!";
                           updatestatus=1;
                           carfile.seekg(carfile.tellg()-sizeof(Cars));
                           C.putcar();
                           C.getcar();
                           carfile.write((char*)&C, sizeof(Cars));
                           break;
                         }

                     if(updatestatus) cout<<"\n\t\tCar Details Updated ! ";
                     else cout<<"\n\t\tCar Not Found !";
                     carfile.close();
                        getch();

                  }



 void DisplayCar() { Cars D;
                     int i=0;
                     ifstream carfile("carsdata",ios::in|ios::binary);
                         //Read From File
                     clrscr();
                     cout<<"\n\t\t\tDISPLAY AVAILABLE CARS";
                     while(carfile.read((char*)&D, sizeof(Cars)))
                      { cout<<"\n\n\tCar No. "<<(i+1)<<endl;
                        D.putcar();
                        getch();
                        i++;
                      }
                     carfile.close();
                   }

 void inputdesign() { clrscr;
                      SetConsoleTextAttribute(color,9);
                      border(3,2,74,21,2);
                      gotoxy(9,8);cout<<"Drv. Lic. #: ";
                      gotoxy(46,8);cout<<"Name: ";
                      gotoxy(9,11);cout<<"Address: ";
                      gotoxy(9,14);cout<<"City: ";
                      gotoxy(46,14);cout<<"ZIPCode: ";
                      gotoxy(9,17);cout<<"Email: ";
                      gotoxy(46,17);cout<<"Rent Car ID: ";
                    }


//************/**************/************* class Customer *************/***************/*************/*****
                                 /* stored in customer_record */


 class Customer { char lic_no[12];
                  char name[30],email[30];
                  char address[100],city[30];
                  char rentcarid[10];
                  char zipcode[10];
              public:
                  void getcustomer();
                  void putcustomer();
                  void Cust_Table();
                  void get_rentcarid() { C.AvailTable(rentcarid); }
                  void test() { gotoxy(1,1);cout<<lic_no<<"=="<<name<<"=="<<address<<"==\n"<<city<<"=="<<zipcode<<"=="<<email<<"=="<<rentcarid;  }
                  char *ret_rentcarid() { return rentcarid; }
                  char *ret_licno() { return lic_no; }
                  char *ret_name() { return name; }
                  char *ret_email() { return email; }
                  ~Customer() { /*Destructor the destroyer*/ }
                }N;

 void Customer::getcustomer() { SetConsoleTextAttribute(color,11);//Customer Input Color
                                lic:
                                gotoxy(22, 8); ventry(lic_no,4,10);
                                if(lic_no[0]==NULL) goto lic;
                                name:
                                gotoxy(52,8); ventry(name,0,23);
                                if(name[0]==NULL) goto name;
                                gotoxy(18,11); gets(address);
                                gotoxy(15,14); gets(city); gotoxy(55,14); ventry(zipcode,4,6);
                                gotoxy(16,17); ventry(email,3,26);
                                flushall();
                              }

 void Customer::putcustomer() { SetConsoleTextAttribute(color,11);
                                gotoxy(22, 8); cout<<lic_no; gotoxy(52,8); cout<<name;
                                gotoxy(18,11); cout<<address;
                    				  gotoxy(15,14); cout<<city; gotoxy(55,14); puts(zipcode);
                  			     gotoxy(16,17); puts(email); gotoxy(59,17);puts(rentcarid);
                                if(email[0]==NULL) { gotoxy(1,1); cout<<"Null"; }
                  			   }

 void Customer::Cust_Table() { clrscr();
                               cout<<"\t\t\tDISPLAY AVAILABLE CUST";
                               ifstream customer("customer_record",ios::in|ios::binary);
                               if(!customer)
                                { cout<<"\n\n\t\aFile Does Not Exist / Unable to Open File ";
                                  getch();
                                }
                               else
                                { Cars D;
                                  border(4,3,73,20,1);
                                  line(16,4,19);//Vertical line After Lic. #
                                  line(38,4,19);//Vertical line After Customer
                                  line(46,4,19);// After CarID
                                  line(67,4,19);// After CAR
                                  line(5,5,72,'h');// Horizontal line
                                  gotoxy(5,4);cout<<" Licence #";gotoxy(23,4);cout<<" CUSTOMER ";
                                  gotoxy(39,4);cout<<" CarID";gotoxy(54,4);cout<<" CAR";gotoxy(69,4);cout<<"Price/hr";
                             		 short i=0,r=7;
                                  //Read From File
                                  while(customer.read((char*)&N, sizeof(N)))
                                   { SearchCar(D,rentcarid);
                        			    gotoxy(40,r);cout<<rentcarid;
              				  		       gotoxy(6 ,r);cout<<lic_no;
             				     		    gotoxy(48,r);voutput(17,D.retmake(),D.retmodel());
                   				  		 gotoxy(18,r);cout<<name;
                  						 gotoxy(51,r);//cout<<D.retprice();
                    	      	       //getch();
                              		 i++;r++;
                               	  }
                                }
                             }

 void AddCustomer() { clrscr();
                      cout<<"\n\t\t\tADD NEW CUSTOMER";
                      inputdesign();
                      N.getcustomer();
                      N.get_rentcarid();
                      clrscr();
                      inputdesign();
                      N.putcustomer();

                      { SetConsoleTextAttribute(color,138);
                        gotoxy(23,21); cout << " S";
                        SetConsoleTextAttribute(color,142);
                        cout << "ave ";  }

                      { SetConsoleTextAttribute(color,140);
                        gotoxy(51,21); cout << " C";
                        SetConsoleTextAttribute(color,142);
                        cout << "ancel "; }

                      save:
                      ::op=tolower(getch());
                      if(::op == 's')
                       {     //Write TO File
                         ofstream cust;
                         cust.open("customer_record",ios::out|ios::binary|ios::app);
                         cust.write((char *) &N, sizeof(class Customer));
                         cust.close();flushall();
                         status_edit(N.ret_rentcarid());
                         SetConsoleTextAttribute(color,252);
                         clrscr();
                         gotoxy(30,12); cout<<" PLEASE WAIT ! ";
                         SetConsoleTextAttribute(color,10);
                         loading(52,12);
                         gotoxy(30,12); cout<<" CUSTOMER SAVED ! ";
                         for(short i=0;i<5;i++) delay();
                       }
                      else if(::op=='c') menu();
                      else goto save;
                    }

 void DisplayCust() { clrscr();
                      cout<<"\n\t\t\tDISPLAY AVAILABLE CUSTOMERS";
                      ifstream cust;
                      cust.open("customer_record",ios::in|ios::binary);
                      cust.clear();
                      cust.seekg(0);
                       //Read From File
                      while(cust.read((char *) &N, sizeof(class Customer)))
                       { clrscr();
                         inputdesign();
                         N.putcustomer();
                         flushall();
                         getch();
                       }
                      cust.close();
                    }

 bool SearchCust(Customer& D, char *objective ="#Nothing")
/*  Can only search for Drv_Lic.#, *Name, email_id and rentcarid
    * more than one record;
*/ {  short count=0,searchstatus=0,i=0;
      Customer M[10];
      ifstream customer("customer_record",ios::in|ios::out|ios::binary);
      if(*objective==NULL) return 0;

      //Read from File and Write to File
      while(customer.read((char*)&N, sizeof(Customer)))
       { if(strcmp(objective,N.ret_rentcarid())==0||strcmp(objective,N.ret_email())==0||strcmp(objective,N.ret_licno())==0)
          { D=N;
            searchstatus++;
            break;
          }
         else if( namecmp(N.ret_name(),objective) ) count++;
       }
      //gotoxy(1,1);cout<<"{ "<<count<<" }"; //For Testing
      customer.clear();
      customer.seekg(0);

      if(count==1)
       while(customer.read((char*)&N, sizeof(Customer)))
        if( namecmp(N.ret_name(),objective) )
         { D=N;
           searchstatus++;
           break;
         }

      if(count>1)
       { clrscr();
         cout<<"\nMore than one record found !\a\n";
         while(customer.read((char*)&N, sizeof(Customer)))
          if( namecmp(N.ret_name(),objective) )
           { M[i]=N; i++; }
         cout<<"\n\n\t Option\t\t Drv_Lic.#"<<"\t\tFull Name\n";
         cout<<"\t------------------------------------------------------------";
         for(i=0;i<count;i++)
          { cout<<"\n\n\t  ["<<(i+1)<<"]"<<"\t\t"<<setw(10)<<M[i].ret_licno();
            cout<<"\t\t"<<setw(19)<<M[i].ret_name();
          }
         int op;
         cout<<"\n\n\nEnter Option / 0 to exit => ";
         cin>>op;
         if(op==0) return 0;
         customer.clear();
         D=M[op-1];
         searchstatus++;
         clrscr();
       }

      if(searchstatus) return 1;
                  else return 0;

      customer.close();
   }

 void ReturnCar(short code=0) { char info[30];
                                search:
                                clrscr();
                                if(code==0)
                                 { cout<<"\n\n\tEnter Driv. Licence # of Customer : ";
                                   gets(info);
                                   SearchCust(N,info);
                                 }
                                if(code==1)
                                 { gotoxy(6,5); cout<<"Name: "; gotoxy(6,7);
                                   cout<<"Email: "; gotoxy(6,9); cout<<"Rent_CarID: ";
                                   gotoxy(12,5); gets(info);
                                   if(info[0]==NULL||SearchCust(N,info)==0)
                                    { gotoxy(13,7); gets(info);
                                      if(info[0]==NULL||SearchCust(N,info)==0)
                                       { gotoxy(18,9); gets(info);
                                         if(SearchCust(N,info)==0)
                                          { cout<<"\n\n\tRECORD NOT FOUND !"; getch();
                                            goto search;
                                       }  }
                                 }  }clrscr();N.putcustomer();getch();
                              }

 void report_menu() { menu:
                      clrscr();
                      cout<<"\n\t\t\tREPORTS\n\n";
                      cout<<"\n\t[1] View All Car Reports(Inventory) \n ";
                      cout<<"\n\t[2] View All Customer Report \n";
                      cout<<"\n\t[3] View Customer - Car Report \n";
                      cout<<"\n\t[4] GO BACK\n";
                      cout<<"\nEnter your option => ";
                      ventry(&::op);
                      switch(::op)
                       { case '1': clrscr();
                                   cout<<'\a';
                                   C.CarTable();getch();
                                   break;

                       //  case '2': clrscr();
                         //          cout<<'\a';
                           //        status_edit("0");getch();
                             //      break;

                         case '3': clrscr();
                                   cout<<'\a';
                                   N.Cust_Table();getch();
                                   break;

                         case '4': clrscr();
                                   menu();
                                   break;
                       }
                      goto menu;
                    }

 void status_editmenu() { menu:
                          clrscr();
                          cout<<"\n\t\t\tEDIT CAR STATUS\n\n";
                          cout<<"\n\t[1] EDIT All Status to [ AVAILABLE ] \n ";
                          cout<<"\n\t[2] EDIT All Status to [ BOOKED! ]\n";
                          cout<<"\n\t[3] Car Status Switch\n";
                          cout<<"\n\t[4] GO BACK\n";
                          cout<<"\nEnter your option => ";
                          ventry(&::op);
                          char carid[6];
                          switch(::op)
                           { case '1': clrscr();
                                       cout<<'\a';
                                       status_edit("1");getch();
                                       break;

                             case '2': clrscr();
                                       cout<<'\a';
                                       status_edit("0");getch();
                                       break;

                             case '3': clrscr();
                                       cout<<'\a';
                                       cout<<"\n\tEnter CarID to Update: ";
                                       gets(carid);
                                       status_edit(carid);getch();
                                       break;

                             case '4': clrscr();
                                       menu();
                                       break;

                           }
                          goto menu;
                        }

 void menu() {
               menu: clrscr();
               system("color 0F");
               cout<<"\t\t\t Main Menu\n\n";
               cout<<"\n\t[1] ADD Car\n";
               cout<<"\n\t[2] ADD Customer\n";
               cout<<"\n\t[3] DISPLAY Customer\n";
               cout<<"\n\t[4] Display Car\n";
               cout<<"\n\t[5] REPORTS\n";
               cout<<"\n\t[6] Update Car\n";
               cout<<"\n\t[7] EDIT STATUS\n";
               cout<<"\n\t[8] Exit\n";
               cout<<"\nEnter your option => ";
               ventry(&::op,4,1);
            switch(::op)
                { case '1': clrscr();
                            cout<<'\a';
                            AddCar();
                            break;

                  case '2': clrscr();
                            cout<<'\a';
                            AddCustomer();
                            break;

                  case '3': clrscr();
                            cout<<'\a';
                            DisplayCust();
                            break;

                  case '4': clrscr();
                            cout<<'\a';
                            DisplayCar();
                            break;

                  case '5': clrscr();
                            cout<<'\a';
                            report_menu();
                            break;

                  case '6': clrscr();
                            cout<<'\a';
                            UpdateCar();
                            break;

                  case '7': clrscr();
                            cout<<'\a';
                            status_editmenu();
                            break;

                 // case '7': clrscr();
                 //           char* str;
                 //           C.AvailTable(str);
                 //           cout<<str; getch();
                 //           break;

                  case '8': exit(-1);
                }
               goto menu;
             }




 void main() {
              ReturnCar(1);
              getch();
              //loading(4,4,10);

              // L.check();
               menu();
             }





