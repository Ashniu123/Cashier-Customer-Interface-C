/*This program is the imitation of the day to day working of a system used in a RAYMOND SHOP(SHOPPER 9). It is NOT AN ONLINE SHOPPING INTERFACE.
There are many aspects of the system created here.
1.The basic purchase of goods.
2.The membership system.
3.The owner access of the system.
The first two modules are self explanatory thus lets talk about the third one.

The owner of the shop can access the sales of the shop based on the daily sales,monthly sales and the yearly sales.In the real world system sales are not updated based on the date.The owner can shut the daily sales through the operation of "day close".However the monthly and yearly sales are updated based on the month and year end respectively.

The owner can access the membership list to see the various members and their data but it cannot be manipulated by the owner.

The owner can access the monthly sales of all the months of the year as well as the sales of the last 12 years to understand the progress of his business over time.

To put things into perspective the owner can also see the graphs of the above mentioned data.The graphs are not static but vary as the data is changed.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO
    //declaring structure
int nsleep(long milliseconds)
{
  struct timespec req,rem;
  if(milliseconds > 999)
  {
    req.tv_sec = (int)(milliseconds/1000);
    req.tv_nsec = (milliseconds - ((long)req.tv_sec*1000))*1000000;
   }
   else
   {
     req.tv_sec = 0;
     req.tv_nsec = milliseconds *1000000;
    }

    return nanosleep(&req,&rem);

 }
    struct account
   {  char name[100];
     int mem;
     float point;
   };
     struct data
   { char mo[20];
     float months;
     float years;
   };

  struct database
   { int code;
     float sales;
     char description[80];
   };
   struct sentance
  {
  char load[50];
  char end[55];
  };

   struct sentance st3[72];
   struct account st[1000];
   struct data st1[12];
   struct database st2[80];
    //DECLARING VARIABLES
    int a1,t1,t2,t3,b,z,a,ch=0, e=0,ct=0,d=0,m=0,h=0,min=0,sec=0,y=0,flag=-1,pos=1,t=0;
    char name[100]="";
    int qwe=0,l=0;
    char sd;
    char v;
    int dummy1;
    char dummy[100];
    int i=0,a=0,j=0;
    int ssp=0,sp,op=0;
    char shnuff[100];
    char snuff[100];
    char ch1=' ';
    char password[20]="PASSWORD";
    char PASSWORD[20]="";
    char na[25];
    int code[1000];
    int delay;
    float amount=0.0,famt=0.0;
    float total=0.0,total1=0.0,total2=0.0;
    float quantity[1000];
    char size[1000];
    char ps1[100]="MR.AKSHAT SHETTY";
    char ps2[100]="MR.ADHRIT SHETTY";
    char ps3[100]="MR.SAURABH SHINDE";
    char ps4[100]="MR.NISHEET SINVHAL";
    int mem_type[1000];
    float point_earn[1000];
     //DECLARING POINTER VARIABLES
    FILE *fp;
    FILE *fp1;
    FILE *fp2;
    FILE *fme;
    FILE *fpo;
    FILE *fmo;
    FILE *fye;
    FILE *fna;
    FILE *fnm;
    FILE *fpos;
    FILE *fse;
    FILE *fda;
    FILE *fde;
   //DECLARING FUNCTION PROTOTYPE
   void check();
   int checkeryn(char);
   int checkersize(char);
   int checkertie(char);
   int Input();
   void fabric();
   void park_avenue();
   void accessories();
   void parx();
   void owner();
   void calculate();
   void calc();
   void swipe();
   void read1();
   void find();
   void addmem();
   void new();
   void print();
   void store();
   void data_read();
   void data_store();
   void data_print();
   void database_print();
   void database_find_and_update();
   void database_store();
   void graph();
   void load1();
   void load2();
   void bill_space(float a,int n);
   void pass();
   void initial_screen();
   void end_screen();
   
   
   void main()
     {   
        setbuf(stdout,NULL);
         for(i=0;i<1000;i++)
         {mem_type[i]=-1;
          st[i].mem=-1;
          point_earn[i]=-1.00000;
          st[i].point=-1.00000;
         }
         for(i=0;i<12;i++)
         {st1[i].months=-1.00000;
          st1[i].years=-1.00000;
         }
       system("clear");
       read1();
       store();
       initial_screen();
        while(1<2)
        {  for(i=0;i<1000;i++)
           {size[i]='-';
           }

           while(1>0)
           {
            system("clear");
            printf("\t\t\t\t    THE RAYMOND SHOP");
            calc();
            ch1=ch=' ';
            printf("\nWELCOME");
            printf("\nENTER YOUR NAME IN GIVEN FORMAT.\nEG-MR.MANOJ SINGH OR MRS.MANJU SINGH:");
            fgets(name,100,stdin);
            z=strlen(name);
            for(i=0;i<z;i++)
            {
              name[i]=toupper(name[i]);
            }
            if(name[z-1]=='\n')
              name[z-1]='\0';


           	b=1;
            for(i=0;i<z-1;i++)
            {   if(isalpha(name[i]))
                {
                    if(name[i+2]=='\0' && (ispunct(name[i+1])||isspace(name[i+1])))
                    	name[i+1]='\0';
                }
                else
                if(isdigit(name[i]))
                {
                    b=0;
                }

                 else if(iscntrl(name[i]))
                {
                    b=0;
                }
                 else if(name[0]=='.' || name[0]==' ')
                {
                    b=0;
                }
                else if(ispunct(name[i]))
                {
                    if(name[i]!='.')
                	{
                    	 b=0;
                	}
                }
             	else
             	{
                	 break;
             	}
             	if(b==0)
             	break;
            }
           if(b==1)
           {
               break;
           }

           }


            ct=0;
            flag=-1;
            e=0;

            if(strcmp(name,ps1)==0||strcmp(name,ps2)==0||strcmp(name,ps3)==0||strcmp(name,ps4)==0)
            {
                printf("\nENTER THE PASSWORD:");
                pass();
                printf("\nVERIFYING THE PASSWORD ");
                a=0;
                load2();
               if(strcmp(PASSWORD,password)==0)
                {
                    ct=-1;
                    flag=0;
                    owner();
                }
            }
            while(ct>=0)
            {   ch=Input();
                check();
                if(ch1=='n'||ch1=='N')
                    break;
                    while(1)
                {
                    printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASES?\nIF YES PRESS Y ELSE N:");
                scanf("%c",&ch1);
                fgets(dummy,100,stdin);
                t1=checkeryn(ch1);

                    if(t1==0||t1==1)
                    {
                        break;
                    }
                    else if(t1==-1)
                    {
                        continue;
                    }
                }
                system("clear");
                printf("\t\t\t\t    THE RAYMOND SHOP");
                if(ch1=='n'||ch1=='N')
                    break;
                else
                    continue;

            }

            if(flag==-1)
            {   if(code[0]==0)
                {    system("clear");
                    printf("\nTHANK YOU FOR VISITING US.PLEASE WAIT WHILE THE COMPUTER IS UPDATING\n ");
                    for(i=1;i<1000000;i+=100)
                    {for(j=1;j<10000000;j+=100)
                    	{}
                    }
                    load1();

                }
                else
                {   calculate();
                    char v=' ';

                    if(dummy1==0)
                    {
                    scanf("%c",&v);
                    printf("\nIS THE BILL PAID FOR?IF YES PRESS THE ENTER KEY");
                    scanf("%c",&v);
                    load1();
                    dummy1=1;
                    }
                    else
                    {printf("\nIS THE BILL PAID FOR?IF YES PRESS THE ENTER KEY");
                    scanf("%c",&v);
                    load1();
                    }
                }
            }
            if(e==-1)
            {  total=0.000000;
               fp=fopen("My_file.txt","w");
               fprintf(fp,"%0.2f",total);
               fclose(fp);
               end_screen();
               exit(0);
            }
        }
    }//main ENDS

/*The check function is used to check the input of the user and redirect them to the department chosen*/

 void check()
    {


        if(ch>4)
        {   int q=0;

            while(1<2)
            {
                if(q==0)
                {printf("\nINVALID INPUT \nIF YOU WISH TO PURCHASE ANY THING PRESS Y ELSE PRESS N:");
                    scanf("%c",&ch1);
                    fgets(dummy,100,stdin);
                }

                a1=checkeryn(ch1);
                if(a1==1)
                {
                    ch=Input();
                    if(ch<=4)
                    {
                        break;
                    }

                }
                 else if(a1==0)
                {
                   break;
                }
                else if(a1==-1)
                {
                    continue;
                }

                q++;
            }
        }
        system("clear");
        if(ch==1)
        {

            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            fabric();
        }
        else
        if(ch==2)
        {

            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            parx();

        }else
        if(ch==3)
        {
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            park_avenue();

        }else
        if(ch==4)
        {

            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            accessories();

        }else
            printf("\nTHANK YOU FOR VISITING \n");
    } // check ENDS
//It is used to take input of the choice of department.
int Input()
    {
        ch=0;
        while(1<2)
        {
            system("clear");
            printf("\n\t\t\t\t THE RAYMOND SHOP");
            printf("\n\nDEPARTMENTS:");
            printf("\n1.FABRIC\n2.PARX\n3.PARK AVENUE\n4.ACCESSORIES\n***********************************************************************************************************************************************");

            printf("\nEnter your choice:");
            scanf("%d",&ch);
             fgets(dummy,100,stdin);
             if(ch==1 || ch==2 || ch==3 ||ch==4)
             {
                 break;
             }
             else
             {
                 continue;
             }
        }
        return ch;

    }// Input ENDS
//It includes all the input,execution and display pertaining to the fabric department.
 void fabric()
    {
        char ch1=' ';int ssp=0,sp,op=0;char shnuff[100];char snuff[100];
        // DECLARING VARIABLES
        while(1)
        {
         system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
        printf("\nFABRICS FOR:\n1.PANTS\n2.SHIRTS\n3.SUITS\n***********************************************************************************************************************************************");
        printf("\nEnter your choice:");
        scanf("%c",&ch1);
        fgets(dummy,100,stdin);
        if(ch1=='1'||ch1=='2'||ch1=='3')
        {
            break;
        }
        else
        {
            continue;
        }
        }

	if(ch1=='1')
        {
            while(1)
            {
                system("clear");
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nFABRICS FOR PANTS ARE:");
            printf("\nQUALITY\t\tSHADE\t\tCODE\t\tPRICE");
            printf("\nSAPPHIRE\tBLUE\t\t1001\t\tRs.500 PER METRE");
            printf("\nSAPPHIRE\tBLACK\t\t1002\t\tRs.500 PER METRE");
            printf("\nSAPPHIRE\tGREY\t\t1003\t\tRs.500 PER METRE");
            printf("\nSPRING FIELD    WHITE\t\t1004\t\tRs.800 PER METRE");
            printf("\nSPRING FIELD    CREAM\t\t1005\t\tRs.800 PER METRE");
            printf("\nSPRING FIELD    OFF WHITE\t1006\t\tRs.800 PER METRE");
            printf("\nPREMIUM BLACK   CHARCOAL BLACK\t1007\t\tRs.1100 PER METRE");
            printf("\nPREMIUM BLACK   JET BLACK\t1008\t\tRs.1100 PER METRE");
            printf("\nPREMIUM BLACK   VELVET BLACK\t1009\t\tRs.1100 PER METRE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);

            if(a1==1)
            {t3=0;
                while(ct>=0)
                { t2=0;

                     printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0;ssp=0;
                      for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;

                     if((code[i]==1001)||(code[i]==1002)||(code[i]==1003)||(code[i]==1004)||(code[i]==1005)||(code[i]==1006)||
                         (code[i]==1007)||(code[i]==1008)||(code[i]==1009))
                         {
                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;

                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF PANTS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");

                    }

                    if(t2==1)
                       {t3=1;
                        break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
    }
        if(ch1=='2')
        {    while(1)
           {

                    system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nFABRICS FOR SHIRTS ARE:");
            printf("\nQUALITY\t\tSHADE\t\t\tCODE\t\tPRICE");
            printf("\nTERINO\t\tBLUE CHECKS\t\t2001\t\tRs.500 PER METRE");
            printf("\nTERINO\t\tRED CHECKS\t\t2002\t\tRs.500 PER METRE");
            printf("\nTERINO\t\tYELLOW CHECKS\t\t2003\t\tRs.500 PER METRE");
            printf("\nCELEBRITY\tBLUE STRIPES\t\t2004\t\tRs.800 PER METRE");
            printf("\nCELEBRITY\tGREEN STRIPES\t\t2005\t\tRs.800 PER METRE");
            printf("\nCELEBRITY\tPURPLE STRIPES\t\t2006\t\tRs.800 PER METRE");
            printf("\nANTIQUITY\tPLAIN WHITE\t\t2007\t\tRs.1100 PER METRE");
            printf("\nANTIQUITY\tPLAIN BLACK\t\t2008\t\tRs.1100 PER METRE");
            printf("\nANTIQUITY\tPLAIN CREAM\t\t2009\t\tRs.1100 PER METRE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);

            if(a1==1)
            {t3=0;
                while(ct>=0)
                { t2=0;

                     printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0;ssp=0;
                      for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;

                     if((code[i]==2001)||(code[i]==2002)||(code[i]==2003)||(code[i]==2004)||(code[i]==2005)||
                         (code[i]==2006)||(code[i]==2007)||(code[i]==2008)||(code[i]==2009))
                         {

                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;

                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF PANTS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");

                    }

                    if(t2==1)
                       {t3=1;
                        break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
    }
        if(ch1=='3')
        {    while(1)
        {system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nFABRICS FOR SUITS ARE:");
            printf("\nSHADE\t\tCODE\t\tPRICE");
            printf("\nBLUE\t\t3001\t\tRs.9000 PER METRE");
            printf("\nBLACK\t\t3002\t\tRs.9000 PER METRE");
            printf("\nGREY STRIPED\t3003\t\tRs.9000 PER METRE");
            printf("\nMUSTARD STRIPED\t3004\t\tRs.9000 PER METRE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);
            if(a1==1)
            {  t3=0;while(ct>=0)
                {t2=0;
                     printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                       for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                     if((code[i]==3001)||(code[i]==3002)||(code[i]==3003)||(code[i]==3004))
                    {
			while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;

                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF SUITS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}
    }//fabric ENDS

    //It includes all the input,execution and display pertaining to the parx department.
 void parx()
    {
        char ch1=' ';int ssp=0,sp;char shnuff[100];
        // DECLARING VARIABLES
        while(1)
        {

         system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
        printf("\nPARX:\n1.READYMADE SHIRTS\n2.READYMADE TROUSERS\n***********************************************************************************************************************************************");
        printf("\nEnter your choice:");
        scanf("%c",&ch1);
        fgets(dummy,100,stdin);
        if(ch1=='1'||ch1=='2')
        {
            break;
        }
        else
        {
            continue;
        }
        }

        if(ch1=='1')
        {    while(1)
        {system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nREADYMADE SHIRTS ARE:");
            printf("\nTYPES\t\t\tCODE\t\tPRICE");
            printf("\nBLUE STRIPES\t\t4001\t\tRs.1500 PER PIECE");
            printf("\nBLACK STRIPES\t\t4002\t\tRs.1500 PER PIECE");
            printf("\nBROWN STRIPES\t\t4003\t\tRs.1500 PER PIECE");
            printf("\nBLUE CHECKS\t\t4004\t\tRs.1500 PER PIECE");
            printf("\nPURPLE CHECKS\t\t4005\t\tRs.1500 PER PIECE");
            printf("\nGREEN CHEKS\t\t4006\t\tRs.1500 PER PIECE");
            printf("\nPLAIN WHITE\t\t4007\t\tRs.1500 PER PIECE");
            printf("\nPLAIN BLUE \t\t4008\t\tRs.1500 PER PIECE");
            printf("\nPLAIN PINK\t\t4009\t\tRs.1500 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
             scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);
            if(a1==1)
            {  t3=0;while(ct>=0)
                {t2=0;
                     printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                        for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                     if((code[i]==4001)||(code[i]==4002)||(code[i]==4003)||(code[i]==4004)||(code[i]==4005)||
                     (code[i]==4006)||(code[i]==4007)||(code[i]==4008)||(code[i]==4009))
                    {
                        while(1)
                        {
                        printf("\nSMALL(S),MEDIUM(M),LARGE(L),EXTRA LARGE(X).\nENTER YOUR SIZE:");
                          scanf("%c",&size[ct]);
                         fgets(dummy,100,stdin);

                         t1=checkersize(size[ct]);
                         if(t1==1)
                         break;
                         else
                         continue;
                        }
                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF READYMADE SHIRTS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}
        if(ch1=='2')
        {
            while(1)
            {
            system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nREADYMADE TROUSERS ARE:");
            printf("\nSHADES\t\tCODE\t\tPRICE");
            printf("\nBLUE \t\t5001\t\tRs.3000 PER PIECE");
            printf("\nBLACK \t\t5002\t\tRs.3000 PER PIECE");
            printf("\nBROWN \t\t5003\t\tRs.3000 PER PIECE");
            printf("\nLIGHT BLUE \t5004\t\tRs.3000 PER PIECE");
            printf("\nMUSTARD\t\t5005\t\tRs.3000 PER PIECE");
            printf("\nGREEN \t\t5006\t\tRs.3000 PER PIECE");
            printf("\nWHITE\t\t5007\t\tRs.3000 PER PIECE");
            printf("\nGREY \t\t5008\t\tRs.3000 PER PIECE");
            printf("\nOFF WHITE\t5009\t\tRs.3000 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
             scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);
            if(ch1=='y'||ch1=='Y')
            {  t3=0;
            while(ct>=0)
                {t2=0;
                    printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                         for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                     if((code[i]==5001)||(code[i]==5002)||(code[i]==5003)||(code[i]==5004)||(code[i]==5005)||
                   	 (code[i]==5006)||(code[i]==5007)||(code[i]==5008)||(code[i]==5009))
                    {
                        while(1)
                        {
                        printf("\nSMALL(S),MEDIUM(M),LARGE(L),EXTRA LARGE(X).\nENTER YOUR SIZE:");
                         scanf("%c",&size[ct]);
                         fgets(dummy,100,stdin);
                         t1=checkersize(size[ct]);
                         if(t1==1)
                         break;
                         else
                         continue;
                        }
                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF READYMADE TROUSERS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}
    }// parx ends


//It includes all the input,execution and display pertaining to the park avenue department.
void park_avenue()
    {
char ch1=' ';int ssp=0,sp;char shnuff[100];
        // DECLARING VARIABLES

        while(1)
        {
           system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
          printf("\nPARK AVENUE:\n1.READYMADE SHIRTS\n2.T-SHIRTS\n3.JEANS\n***********************************************************************************************************************************************");
        printf("\nEnter your choice:");
        scanf("%c",&ch1);
        fgets(dummy,100,stdin);
        if(ch1=='1'||ch1=='2'||ch1=='3')
        {
            break;
        }
        else
        {
            continue;
        }
        }

        t=0;

        if(ch1=='1')
        {    while(1)
        {   system("clear");
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nREADYMADE SHIRTS ARE:");
            printf("\nTYPES\t\tCODE\t\tPRICE");
            printf("\nBLUE STRIPES\t\t6001\t\tRs.2000 PER PIECE");
            printf("\nBLACK STRIPES\t\t6002\t\tRs.2000 PER PIECE");
            printf("\nBROWN STRIPES\t\t6003\t\tRs.2000 PER PIECE");
            printf("\nBLUE CHECKS\t\t6004\t\tRs.2000 PER PIECE");
            printf("\nPURPLE CHECKS\t\t6005\t\tRs.2000 PER PIECE");
            printf("\nGREEN CHECKS\t\t6006\t\tRs.2000 PER PIECE");
            printf("\nPLAIN WHITE\t\t6007\t\tRs.2000 PER PIECE");
            printf("\nPLAIN BLUE \t\t6008\t\tRs.2000 PER PIECE");
            printf("\nPLAIN PINK\t\t6009\t\tRs.2000 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);
            if(a1==1)
            {  t3=0;
            while(ct>=0)
                {t2=0;
                    printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                          for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                     if((code[i]==6001)||(code[i]==6002)||(code[i]==6003)||(code[i]==6004)||(code[i]==6005)||(code[i]==6006)||
                    	 (code[i]==6007)||(code[i]==6008)||(code[i]==6009))
                       {
                       while(1)
                       {
                        printf("\nSMALL(S),MEDIUM(M),LARGE(L),EXTRA LARGE(X).\nENTER YOUR SIZE:");
                         scanf("%c",&size[ct]);
                         fgets(dummy,100,stdin);
                         t1=checkersize(size[ct]);
                         if(t1==1)
                         break;
                         else
                         continue;
                        }
                       while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF READYMADE SHIRTS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }

                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;


                    }

                    if(t2==1)
                       {
                           t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}
        if(ch1=='2')
        {
            while(1)
            {
                system("clear");
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nT-SHIRTS ARE:");
            printf("\nSHADES\t\tCODE\t\tPRICE");
            printf("\nBLUE \t\t7001\t\tRs.1500 PER PIECE");
            printf("\nBLACK \t\t7002\t\tRs.1500 PER PIECE");
            printf("\nPINK \t\t7003\t\tRs.1500 PER PIECE");
            printf("\nLIGHT BLUE \t7004\t\tRs.1500 PER PIECE");
            printf("\nMUSTARD\t\t7005\t\tRs.1500 PER PIECE");
            printf("\nGREEN \t\t7006\t\tRs.1500 PER PIECE");
            printf("\nWHITE\t\t7007\t\tRs.1500 PER PIECE");
            printf("\nGREY \t\t7008\t\tRs.1500 PER PIECE");
            printf("\nOFF WHITE\t7009\t\tRs.1500 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);
            if(a1==1)
            {  t3=0;
            while(ct>=0)
                {t2=0;
                    printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                          for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                     if((code[i]==7001)||(code[i]==7002)||(code[i]==7003)||(code[i]==7004)||(code[i]==7005)||
                    	 (code[i]==7006)||(code[i]==7007)||(code[i]==7008)||(code[i]==7009))
                    {
                        while(1)
                        {
                        printf("\nSMALL(S),MEDIUM(M),LARGE(L),EXTRA LARGE(X).\nENTER YOUR SIZE:");
                         scanf("%c",&size[ct]);
                         fgets(dummy,100,stdin);
                         t1=checkersize(size[ct]);
                         if(t1==1)
                         break;
                         else
                         continue;
                        }
                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF T-SHIRTS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}
        if(ch1=='3')
        {
            while(1)
            {
                system("clear");
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nJEANS ARE:");
            printf("\nTYPES\t\t\tCODE\t\tPRICE");
            printf("\nBLUE \t\t\t8001\t\tRs.3000 PER PIECE");
            printf("\nBLACK \t\t\t8002\t\tRs.3000 PER PIECE");
            printf("\nDARK BLUE \t\t8003\t\tRs.3000 PER PIECE");
            printf("\nLIGHT BLUE \t\t8004\t\tRs.3000 PER PIECE");
            printf("\nRIPPED LIGHT BLUE\t8005\t\tRs.3000 PER PIECE");
            printf("\nDESIGNER BLUE \t\t8006\t\tRs.3000 PER PIECE");
            printf("\nDESIGNER BLUE\t\t8007\t\tRs.3000 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);
            if(a1==1)
            {t3=0;
              while(ct>=0)
                {t2=0;
                    printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                          for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                     if((code[i]==8001)||(code[i]==8002)||(code[i]==8003)||(code[i]==8004)||
                    	 (code[i]==8005)||(code[i]==8006)||(code[i]==8007))
                    {
                        while(1)
                        {
                        printf("\nSMALL(S),MEDIUM(M),LARGE(L),EXTRA LARGE(X).\nENTER YOUR SIZE:");
                         scanf("%c",&size[ct]);
                        fgets(dummy,100,stdin);
                         t1=checkersize(size[ct]);
                         if(t1==1)
                         break;
                         else
                         continue;
                        }
                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF JEANS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}
    }//park_avenue ENDS

//It includes all the input,execution and display pertaining to the accessories department.
  void accessories()
    {
        // DECLARING VARIABLES
        char ch1=' ';int ssp=0,sp;char shnuff[100];

        while(1>0)
        {
         system("clear");
         printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
        printf("\nACCESSORIES:\n1.TIES\n2.BELTS\n3.DEODORANTS\n***********************************************************************************************************************************************");
        printf("\nEnter your choice:");
         scanf("%c",&ch1);
         fgets(dummy,100,stdin);
        if(ch1=='1'||ch1=='2'||ch1=='3')
        {
            break;
        }
        else
        {
            continue;
        }
        }

        if(ch1=='1')
        {     while(1>0)
            {
            system("clear");
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nTIES ARE:");
            printf("\nTYPES\t\t\tCODE\t\tPRICE");
            printf("\nPLAIN RED\t\t9001\t\tRs.800 PER PIECE");
            printf("\nRED DOTTED \t\t9002\t\tRs.800 PER PIECE");
            printf("\nRED STRIPED\t\t9003\t\tRs.800 PER PIECE");
            printf("\nPLAIN BLUE \t\t9004\t\tRs.800 PER PIECE");
            printf("\nBLUE DOTTED\t\t9005\t\tRs.800 PER PIECE");
            printf("\nBLUE STRIPED \t\t9006\t\tRs.800 PER PIECE");
            printf("\nPLAIN PINK \t\t9007\t\tRs.800 PER PIECE");
            printf("\nPINK DOTTED\t\t9008\t\tRs.800 PER PIECE");
            printf("\nPINK STRIPED \t\t9009\t\tRs.800 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);

            if(a1==1)
            { t3=0;
                  while(ct>=0)
                {
                    t2=0;
                    printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                          for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                    if((code[i]==9001)||(code[i]==9002)||(code[i]==9003)||(code[i]==9004)||(code[i]==9005)||
                   	 (code[i]==9006)||(code[i]==9007)||(code[i]==9008)||(code[i]==9009))
                    {
                        while(1>0)
                        {
                        printf("\nTHIN(T)OR BROAD(B).\nENTER YOUR SIZE:");
                         scanf("%c",&size[ct]);
                        fgets(dummy,100,stdin);
                         t1=checkertie(size[ct]);
                         if(t1==0)
                         {
                             printf("INVALID INPUT");
                         }
                         else
                         {
                             break;
                         }
                        }
                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF TIES?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}

        if(ch1=='2')
        {
            while(1)
            {  system("clear");
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nBELTS ARE:");
            printf("\nTYPES\t\tCODE\t\tPRICE");
            printf("\nBLACK\t\t10001\t\tRs.1200 PER PIECE");
            printf("\nBROWN \t\t10002\t\tRs.1200 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
             scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);

            if(a1==1)
            {  t3=0;
                  while(ct>=0)
                {
                    t2=0;
                   printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                          for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                     if((code[i]==10001)||(code[i]==10002))
                    {
                        while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                        while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF BELTS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}

        if(ch1=='3')
        {   while(1)
            {
                system("clear");
            printf("\n\t\t\t\t    THE RAYMOND SHOP\n");
            printf("\nDEODORANTS ARE:");
            printf("\nTYPES\t\t\tCODE\t\tPRICE");
            printf("\nGOOD MORNING\t\t11001\t\tRs.400 PER PIECE");
            printf("\nVOYAGE\t\t\t11002\t\tRs.400 PER PIECE");
            printf("\nPARTY\t\t\t11003\t\tRs.400 PER PIECE");
            printf("\nDISCOVER\t\t11004\t\tRs.400 PER PIECE");
            printf("\nDO YOU WANT TO PURCHASE?\nIF YES PRESS Y ELSE N:");
            scanf("%c",&ch1);
            fgets(dummy,100,stdin);
            t=0;
            a1=checkeryn(ch1);
            if(a1==1)
            {   t3=0;
                  while(ct>=0)
                {
                     t2=0;
                   printf("\nENTER THE CODE OF YOUR LIKING:");
                     fgets(shnuff,100,stdin);
                     shnuff[strlen(shnuff)-1]='\0';
                     for(sp=0;sp<(strlen(shnuff)-1);sp++)
                      {
                       if(!isdigit(shnuff[sp]))
                          ssp=1;
                      }
                      if(ssp==1)
                      { code[ct]=0; ssp=0;
                          for(sp=0;sp<strlen(shnuff);sp++)
                      {
                       shnuff[sp]='\0';
                      }
                      }
                      else
                      {
                       code[ct]=atoi(shnuff);

                      }
                    // DECLARING VARIABLES
                    int i=ct;
                    //CHECKING IF CODE INPUT IS INVALID
                    if((code[i]==11001)||(code[i]==11002)||(code[i]==11003)||(code[i]==11004))
                    {

                       while(1>0)
                        {printf("\nENTER THE QUANTITY OF YOUR LIKING:");
                        fgets(snuff,100,stdin);
                        if(snuff[strlen(snuff)-1]==' ')
                          snuff[strlen(snuff)-1]='\0';
                        for(sp=0;sp<(strlen(snuff)-1);sp++)
                        {
                         if(!isdigit(snuff[sp]))
                         op=1;
                        }
                        if(op==1)
                         { printf("INVALID INPUT\n");
                           op=0;
                         }
                        else
                         {
                           quantity[ct]=atoi(snuff);
                           quantity[ct]=floor(quantity[ct]);
                           break;
                         }
                         }
                        ct++;
                           while(1)
                        {
                            printf("\nDO YOU WANT TO MAKE ANY MORE PURCHASE OF DEODORANTS?\nIF YES PRESS Y ELSE N:");
                        scanf("%c",&ch1);
                        fgets(dummy,100,stdin);
                        if(ch1=='n'||ch1=='N')
                        {
                            t2=1;break;
                        }
                        else if(ch1=='y'||ch1=='Y')
                        {break;}
                        else
                        {
                            printf("INVALID INPUT");
                            continue;
                        }
                        }

                    }


                    else
                    {
                        printf("\nINVALID CHOICE");
                        t++;
                    }

                    if(t2==1)
                       {t3=1;
                           break;
                       }
                }
                if(t3==1)
                {
                    break;
                }
            }

            else if(a1==0)
            {
                break;
            }
            else if(a1==-1)
            {
                continue;
            }
        }
		}
    }//accessories ENDS

//This is the part of the program which is only for the owner's use.It has all stats regarding the shop's business.
void owner()
    {   //READING THE FILE
        //total=total1=total2=0.000000;
        fp=fopen("My_file.txt","r");
        fp1=fopen("My_file1.txt","r");
        fp2=fopen("My_file2.txt","r");
        fscanf(fp,"%f",&total);
        fscanf(fp1,"%f",&total1);
        fscanf(fp2,"%f",&total2);
      while(1>0)
     {   while(1>0)
       { system("clear");
         printf("\n\n\t\t\tWELCOME\n1.REPORTS OF THE DAY\n2.MEMBERSHIP LISTS\n3.MONTHLY AND YEARLY SALES\n4.GRAPHS FOR MONTHLY AND YEARLY SALES\n5.INDIVIDUAL STATISTICS OF ITEMS SOLD\n6.DAY CLOSE\n7.EXIT");
        printf("\n\nENTER YOUR CHOICE:");
        scanf("%c",&ch1);
        fgets(dummy,100,stdin);
       if(ch1=='1'||ch1=='2'||ch1=='3'||ch1=='4'||ch1=='5'||ch1=='6'||ch1=='7')
        {  break;
         }

       }
    int ex=0;

     ex=0;
       switch(ch1)
       {
        case'1':
         system("clear");
        printf("\nWELCOME TO THE REPORTS OF THE DAY");

        printf("\nTOTAL SALES OF TODAY:%0.2f",total);
        printf("\nTOTAL SALES OF THE MONTH:%0.2f",total1);
        printf("\nTOTAL SALES OF THE YEAR:%0.2f",total2);
        printf("\n\nPRESS ENTER IF DONE VIEWING");
          fgets(dummy,100,stdin);
        break;

        case '2':
         system("clear");
          print();
          break;

        case '3':
         system("clear");
         data_print();
         break;

        case '4':
         system("clear");
          graph();
          break;

       case '5':
        system("clear");
        printf("\n\n\n");
        database_print();
        break;

       case '6':
         system("clear");
        printf("\nDO YOU WANT TO CLOSE THE DAY?IF YES PRESS Y ELSE N:");
        scanf("%c",&sd);
         fgets(dummy,100,stdin);
        if(sd=='Y'||sd=='y')
        e=-1;
        ex=-1;
        break;

       case '7':

         ex=-1;
        break;

      }
    if(ex==-1)
     break;
    }
        //FILE CLOSE
        fclose(fp);
        fclose(fp1);
        fclose(fp2);


 }//OWNER ENDS
//It is used for calculation and printing of final bill and related fields.
 void calculate()
    {   time_t t=time(NULL);
		struct tm tm = *localtime(&t);
       t=time(NULL);
       tm = *localtime(&t);
        d=tm.tm_mday;
        m=tm.tm_mon+1;
        y=tm.tm_year+1900;
        h=tm.tm_hour;
        min=tm.tm_min;
        sec=tm.tm_sec;
        system("clear");
         printf("\n                --------------------------------------------------------------------------------------------");
 printf("\n                --------------------------------------------------------------------------------------------");
        printf("\n\t\t||\t\t\t\t\tTHE RAYMOND SHOP      \t\t\t\t  ||");
	//declaring variables
        char s[100]="";
        int s1=0;
        int i=0;
        int k=31-strlen(name);
        printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||\t    BILL FOR: %s                       ",name);
        if(m>=10)
        k--;
        if(d>=10)
        k--;
        if(h>=10)
        k--;
        if(min>=10)
        k--;
        if(sec>=10)
        k--;
         printf("%d-%d-%d %d:%d:%d",y,m,d,h,min,sec);

         for(j=0;j<k;j++)
        {
         printf(" ");
        }
        printf("||");
        printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||   CODE\t\tSIZE\t\tRATE\t\tQUANTITY\t   AMOUNT\t  ||");

        //CHECKING THE CODE INPUTED AND ON BASIS OF THAT CALCULATING THE AMOUNT
        /**WE HAVE USED IF ELSE LADDER AS IT REDUCES COMPLICATIONS CAUSED WHILE USING SWITCH*/
        for(i=0;i<1000;i++)
        {
            if(size[i]=='\0')
                size[i]='-';

            if(code[i]==0)
                break;
            s1=code[i];
             double dse=quantity[i];

             if((code[i]==1001)||(code[i]==1002)||(code[i]==1003)||(code[i]==2001)||(code[i]==2002)||(code[i]==2003))
            {   amount=(double)500*dse;
                famt+=amount;
                database_find_and_update(code[i]);
                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 500  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],dse,amount);
             bill_space(amount,1);
            }
            else

            if((code[i]==1004)||(code[i]==1005)||(code[i]==1006)||(code[i]==2004)||(code[i]==2005)||(code[i]==2006)||(code[i]==9001)||
                    	 (code[i]==9002)||(code[i]==9003)||
                    	 (code[i]==9004)||(code[i]==9005)||
                   	 (code[i]==9006)||(code[i]==9007)||
                    	 (code[i]==9008)||(code[i]==9009))
            {   amount=800*quantity[i];
                famt+=amount;
                database_find_and_update(code[i]);
                 printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 800  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                 bill_space(amount,1);
            }
            else
            if((code[i]==1007)||(code[i]==1008)||(code[i]==1009)||(code[i]==2007)||(code[i]==2008)||(code[i]==2009))
            {   amount=1100*quantity[i];
                famt+=amount;
                database_find_and_update(code[i]);
                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 1100  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                bill_space(amount,1);
            }

            else
            if((code[i]==3001)||(code[i]==3002)||
                    	 (code[i]==3003)||(code[i]==3004))
            {   amount=9000*quantity[i];
                famt+=amount;
                database_find_and_update(code[i]);
                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 9000  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                bill_space(amount,1);
            }
            else
            if((code[i]==10001)||(code[i]==10002))
            {   amount=1200*quantity[i];
                famt+=amount;
                database_find_and_update(code[i]);
               printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 1200  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                bill_space(amount,1);
            }
            else
            if((code[i]==11001)||(code[i]==11002)||(code[i]==11003)||(code[i]==11004))
            {   amount=400*quantity[i];
                famt+=amount;
                database_find_and_update(code[i]);
                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 400  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                 bill_space(amount,1);
            }
            else
            if((code[i]==6001)||(code[i]==6002)||
                   	 (code[i]==6003)||(code[i]==6004)||
                   	 (code[i]==6005)||(code[i]==6006)||
                    	 (code[i]==6007)||(code[i]==6008)||
                    	 (code[i]==6009))
            {   amount=2000*quantity[i];
                famt+=amount;
                database_find_and_update(code[i]);
                 printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 2000  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                  bill_space(amount,1);
            }
            else
            if((code[i]==4001)||(code[i]==4002)||
                    	 (code[i]==4003)||(code[i]==4004)||
                    	 (code[i]==4005)||(code[i]==4006)||
                    	 (code[i]==4007)||(code[i]==4008)||
                    	 (code[i]==4009)||(code[i]==7001)||
                    	 (code[i]==7002)||(code[i]==7003)||
                    	 (code[i]==7004)||(code[i]==7005)||
                    	 (code[i]==7006)||(code[i]==7007)||
                    	 (code[i]==7008)||(code[i]==7009))
            {   amount=1500*quantity[i];
                famt+=amount;
                database_find_and_update(code[i]);
                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 1500  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
               bill_space(amount,1);
            }
            else
            if((code[i]==8001)||(code[i]==8002)||
                    	 (code[i]==8003)||(code[i]==8004)||
                    	 (code[i]==8005)||(code[i]==8006)||
                    	 (code[i]==8007)||(code[i]==5001)||
                    	 (code[i]==5002)||(code[i]==5003)||
                    	 (code[i]==5004)||(code[i]==5005)||
                   	 (code[i]==5006)||(code[i]==5007)||(code[i]==5008)||(code[i]==5009))
            {   amount=3000*quantity[i];
                famt=famt+amount;
                database_find_and_update(code[i]);
                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 3000  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
               bill_space(amount,1);
            }

        }
         printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n                ||----------------------------------------------------------------------------------------||");
 printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||  FINAL AMOUNT=%0.2f" ,famt);
        famt=floor(famt);
        bill_space(famt,2);
        printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||     FINAL AMOUNT TO BE PAID AFTER ROUNDING OFF=%0.2f",famt);
        bill_space(famt,3);
        printf("\n                --------------------------------------------------------------------------------------------");
 printf("\n                --------------------------------------------------------------------------------------------");
        while(1)
        {
        printf("\n\n\nARE YOU A MEMBER.\nIF YES PRESS Y ELSE N:");
        scanf("%c",&ch1);
        fgets(dummy,100,stdin);
        a1=checkeryn(ch1);

          if(a1==1)
        {
          find();
          break;
        }
        else if(a1==0)
        {

        while(1)
        {
          ch1=' ';
           printf("\n\n\nDO YOU WANT TO BECOME A MEMBER. \nIF YES PRESS Y ELSE N:");
           scanf("%c",&ch1);
           fgets(dummy,100,stdin);
           t1=checkeryn(ch1);
           if(t1==1)
           {
             addmem();
            break;
           }
           else if(t1==0)
           {
             break;
           }
        }
        break;
      }
    }
        i=-1;


  system("clear");
         printf("\n                --------------------------------------------------------------------------------------------");
 printf("\n                --------------------------------------------------------------------------------------------");
        printf("\n\t\t||\t\t\t\t\tTHE RAYMOND SHOP      \t\t\t\t  ||");
	//declaring variables
         //s[100]="";
         s1=0;
         i=0;
         k=31-strlen(name);
        printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||\t    BILL FOR: %s                       ",name);
        if(m>=10)
        k--;
        if(d>=10)
        k--;
        if(h>=10)
        k--;
        if(min>=10)
        k--;
        if(sec>=10)
        k--;
         printf("%d-%d-%d %d:%d:%d",y,m,d,h,min,sec);

         for(j=0;j<k;j++)
        {
         printf(" ");
        }
        printf("||");
        printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||   CODE\t\tSIZE\t\tRATE\t\tQUANTITY\t   AMOUNT\t  ||");

        //CHECKING THE CODE INPUTED AND ON BASIS OF THAT CALCULATING THE AMOUNT
        /**WE HAVE USED IF ELSE LADDER AS IT REDUCES COMPLICATIONS CAUSED WHILE USING SWITCH*/
        for(i=0;i<1000;i++)
        {
            if(size[i]=='\0')
                size[i]='-';

            if(code[i]==0)
                break;
            s1=code[i];
             double dse=quantity[i];

             if((code[i]==1001)||(code[i]==1002)||(code[i]==1003)||(code[i]==2001)||(code[i]==2002)||(code[i]==2003))
            {   amount=(double)500*dse;

                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 500  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],dse,amount);
             bill_space(amount,1);
            }
            else

            if((code[i]==1004)||(code[i]==1005)||(code[i]==1006)||(code[i]==2004)||(code[i]==2005)||(code[i]==2006)||(code[i]==9001)||
                    	 (code[i]==9002)||(code[i]==9003)||
                    	 (code[i]==9004)||(code[i]==9005)||
                   	 (code[i]==9006)||(code[i]==9007)||
                    	 (code[i]==9008)||(code[i]==9009))
            {   amount=800*quantity[i];

                 printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 800  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                 bill_space(amount,1);
            }
            else
            if((code[i]==1007)||(code[i]==1008)||(code[i]==1009)||(code[i]==2007)||(code[i]==2008)||(code[i]==2009))
            {   amount=1100*quantity[i];

                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 1100  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                bill_space(amount,1);
            }

            else
            if((code[i]==3001)||(code[i]==3002)||
                    	 (code[i]==3003)||(code[i]==3004))
            {   amount=9000*quantity[i];

                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 9000  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                bill_space(amount,1);
            }
            else
            if((code[i]==10001)||(code[i]==10002))
            {   amount=1200*quantity[i];

               printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 1200  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                bill_space(amount,1);
            }
            else
            if((code[i]==11001)||(code[i]==11002)||(code[i]==11003)||(code[i]==11004))
            {   amount=400*quantity[i];

                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 400  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                 bill_space(amount,1);
            }
            else
            if((code[i]==6001)||(code[i]==6002)||
                   	 (code[i]==6003)||(code[i]==6004)||
                   	 (code[i]==6005)||(code[i]==6006)||
                    	 (code[i]==6007)||(code[i]==6008)||
                    	 (code[i]==6009))
            {   amount=2000*quantity[i];
                                 printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 2000  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
                  bill_space(amount,1);
            }
            else
            if((code[i]==4001)||(code[i]==4002)||
                    	 (code[i]==4003)||(code[i]==4004)||
                    	 (code[i]==4005)||(code[i]==4006)||
                    	 (code[i]==4007)||(code[i]==4008)||
                    	 (code[i]==4009)||(code[i]==7001)||
                    	 (code[i]==7002)||(code[i]==7003)||
                    	 (code[i]==7004)||(code[i]==7005)||
                    	 (code[i]==7006)||(code[i]==7007)||
                    	 (code[i]==7008)||(code[i]==7009))
            {   amount=1500*quantity[i];
                                printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 1500  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
               bill_space(amount,1);
            }
            else
            if((code[i]==8001)||(code[i]==8002)||
                    	 (code[i]==8003)||(code[i]==8004)||
                    	 (code[i]==8005)||(code[i]==8006)||
                    	 (code[i]==8007)||(code[i]==5001)||
                    	 (code[i]==5002)||(code[i]==5003)||
                    	 (code[i]==5004)||(code[i]==5005)||
                   	 (code[i]==5006)||(code[i]==5007)||(code[i]==5008)||(code[i]==5009))
            {   amount=3000*quantity[i];

                             printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t|| %d. %d \t\t %c \t\t 3000  \t\t %0.2f \t\t   %0.2f" ,(i+1),code[i],size[i],quantity[i],amount);
               bill_space(amount,1);
            }

        }



        printf("\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||\t\t\t\t\t\t\t\t\t\t\t  ||\n\t\t||     FINAL AMOUNT TO BE PAID AFTER ROUNDING OFF=%0.2f",famt);
        bill_space(famt,3);
                 printf("\n                --------------------------------------------------------------------------------------------");
 printf("\n                --------------------------------------------------------------------------------------------");

        char ch8;
if(famt!=0.0)
{        if(dummy1==9)
        {
          while(1>0)
        {
          printf("\n\n\nWILL THE BILL BE PAID IN CASH(C) OR CREDIT(D):");
         fgets(dummy,100,stdin);
         scanf("%c",&ch8);

         if(ch8=='c'||ch8=='C')
         break;
         else if(ch8=='d'||ch8=='D')
         { swipe();
           break;
          }
          else
          printf("INVALID INPUT");
        }
        dummy1=0;
        }
        else
        { while(1>0)
        {
          printf("\nWILL THE BILL BE PAID IN CASH(C) OR CREDIT(D):");
          scanf("%c",&ch8);
          fgets(dummy,100,stdin);

         if(ch8=='c'||ch8=='C')
         break;
         else if(ch8=='d'||ch8=='D')
         { swipe();
           break;
          }
          else
          printf("INVALID INPUT");
        }
        dummy1=1;
       }
  }
 else
{  //printf("\n\nPRESS ENTER IF DONE VIEWING");
  scanf("%c",&ch1);
}
        fp=fopen("My_file.txt","r");
        fp1=fopen("My_file1.txt","r");
        fp2=fopen("My_file2.txt","r");
        fscanf(fp,"%f",&total);
        fscanf(fp1,"%f",&total1);
        fscanf(fp2,"%f",&total2);

         total+=famt;
        for(i=0;i<1000;i++)
        {
            code[i]=0;
            quantity[i]=0.0;
            size[i]=' ';
        }
        total1+=famt;
        total2+=famt;
        famt=0.0;
        fclose(fp);
        fclose(fp1);
        fclose(fp2);

        //WRITING IN THE FILE
        fp=fopen("My_file.txt","w");
        fp1=fopen("My_file1.txt","w");
        fp2=fopen("My_file2.txt","w");

        fprintf(fp,"%f",total);
        fprintf(fp1,"%f",total1);
        fprintf(fp2,"%f",total2);
        fscanf(fp,"%f",&total);
        fscanf(fp1,"%f",&total1);
        fscanf(fp2,"%f",&total2);

        //CLOSING THE FILE
        fclose(fp);
        fclose(fp1);
        fclose(fp2);
       // membership_store();
    }//calculate ENDS
//It is used for permanent storage(files) of sales data and required updation.
  void calc()
    {
        //USING TIME FUNCTIONS
        time_t t=time(NULL);
        struct tm tm = *localtime(&t);

        d=tm.tm_mday;
        m=tm.tm_mon+1;
        y=tm.tm_year+1900;
        h=tm.tm_hour;
        min=tm.tm_min;
        sec=tm.tm_sec;
        //READING THE FILE
	data_read();
	fpos=fopen("pos.txt","r");
        //fp=fopen("My_file.txt","r");
        fp1=fopen("My_file1.txt","r");
        fp2=fopen("My_file2.txt","r");
        //fscanf(fp,"%f",&total);
        fscanf(fp1,"%f",&total1);
        fscanf(fp2,"%f",&total2);
        fscanf(fpos,"%d",&pos);
        //FILE CLOSE
        //fclose(fp);
        fclose(fp1);
        fclose(fp2);
        fclose(fpos);
        //WRITING IN THE FILE

        //fp=fopen("My_file.txt","w");
        fp1=fopen("My_file1.txt","w");
        fp2=fopen("My_file2.txt","w");
        fpos=fopen("pos.txt","r");
        if(d==1)
        {   if(pos==1)
           {total1=0.0;
            fprintf(fp1, "%f",total1);
           st1[m-1].months=0.0000;
            pos=0;
           }
        }
        else
           { fprintf(fp1,"%f",total1);
             pos=1;
           }
        if(d==1&&m==1)
        {   if(pos==1)
           { total2=0.0;
            fprintf(fp2,"%f",total2);
            for(i=0;i<11;i++)
            {
              st1[i+1].years=st1[i].years;
            }
            pos=0;
           for(j=0;j<12;j++)
           {
            st1[j].months=0.0;
           }
           for(i=0;i<80;i++)
           {
             st2[i].sales=0.0;
           }
         }
       }
        else
         {   fprintf(fp2,"%f",total2);
             st1[m-1].months=total1;
             st1[0].years=total2;
          }
          fprintf(fpos,"%d",pos);
        //CLOSING FILE
        data_store();
        fclose(fpos);
        //fclose(fp);
        fclose(fp1);
        fclose(fp2);
    }//calc ENDS
//It is used for graphic display of the card swiping during bill payment.
     void swipe()
    { int i=0,j=0;
        for(j=0;j<3;j++)
        {

           system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n -------------->");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            delay=nsleep(180);
             system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n                -------------->");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
           delay=nsleep(180);
            system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
           printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n                               -------------->");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
           delay=nsleep(180);
             system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n                                             -------------->");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
           delay=nsleep(180);
            system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n                                                             ------------->");
           printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

           delay=nsleep(180);
            system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
           printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n                                                                               -------------->");
           printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
           delay=nsleep(180);
            system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n                                                                                                  -------------->");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

           delay=nsleep(180);
             system("clear");
            printf("\nPLEASE WAIT WHILE YOUR CARD IS BEING SWIPED");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n                                                                                                                 --------------> ");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
           delay=nsleep(180);
        }

          system("clear");

    }
//It is used to store(read) the membership data of the customer in the file.
void read1()
   {  i=0;
     fme=fopen("card.txt","r");
     fpo=fopen("balance.txt","r");
     fna=fopen("name.txt","r");
     while(!feof(fme))
     {
       fscanf(fme,"%d",&st[i].mem);
       i++;
     }
     i=0;
      while(!feof(fna))
     {
       fscanf(fna,"%s",st[i].name);
       i++;
     }
     i=0;
     while(!feof(fpo))
     {
       fscanf(fpo,"%f",&st[i].point);
       i++;
     }

      fclose(fme);
      fclose(fpo);
      fclose(fna);
}
//It includes details and related operations regarding the membership of the customer.
void find()
{    read1();
     int t=0;
     char p;
     int z;
     float points;
     printf("ENTER YOUR MEMBERSHIP NO:");
     scanf("%d",&t);
     t--;
     z=st[t].mem;
     z=(int)z;
     if(z==1)
     p='S';
     else if(z==2)
     p='G';
     else if(z==3)
     p='B';

     points=st[t].point;
     if(p=='s'||p=='S')
     {
         points=points+0.03*famt;
     }

    else if(p=='g'||p=='G')
     {
         points+=0.05*famt;

     }
    else if(p=='b'||p=='B')
     {
         points+=0.1*famt;
     }
     printf("\nMEMBERSHIP NAME:%s",st[t].name);
     printf("\nMEMBERSHIP TYPE:%c",p);
     printf("\nMEMBERSHIP POINTS:%0.2f",points);
     printf("\nDO YOU WANT TO REDEEM YOU POINTS?(Y/N):");
     fgets(dummy,100,stdin);
       scanf("%c",&ch1);

     dummy1=9;
          if(ch1=='y'||ch1=='Y')
          {if(points>famt)
            {
               points-=famt;
               famt=0.0;
            }
          else
            {
               famt-=points;
               points=0.0;
            }
         }
         st[t].point=points;
         store();
}
//It is used to provide new membership accounts to the customers.
void addmem()
{   qwe=0;
    read1();
    for(qwe=0;qwe<1000;qwe++)
     {
        if(st[qwe].mem==-1)
       break;
     }
     qwe--;

      printf("\nENTER YOUR NAME:");
      fgets(na,25,stdin);
      int z=strlen(na);
      for(i=0;i<z;i++)
      {
        na[i]=toupper(na[i]);
      }
      if(na[z-1]=='\n')
        na[z-1]='\0';
     printf("\nSILVER MEMBERSHIP IS FREE OF COST AND ADDS 3 PERCENT OF EACH BILL AMOUNT TO  YOUR ACCOUNT.\n GOLD MEMBERSHIP COSTS Rs.1500 AND ADDS 5 PERCENT OF EACH BILL AMOUNT TO YOUR ACCOUNT.\n BLACK MEMBERSHIP COSTS Rs.3000 AND ADDS 10 PERCENT OF EACH BILL AMOUNT YOUR ACCOUNT");
     for(i=10;i!=2;)
     { printf("\nENTER TYPE OF MEMBERSHIP SILVER(S) OR GOLD(G) OR BLACK(B):");
       scanf("%c",&ch1);
       fgets(dummy,100,stdin);
       if(ch1=='s' || ch1=='S')
       { printf("\nTHE POINTS WILL BE ADDED FROM YOUR NEXT PURCHASE ONWARDS");
         l=1;
         i=2;
         new();

       }
       else if(ch1=='g' || ch1=='G')
            {  printf("\nTHE POINTS WILL BE ADDED FROM YOUR NEXT PURCHASE ONWARDS");
               famt+=1500;
               l=2;
               i=2;
               new();
            }
       else if(ch1=='b' || ch1=='B')
            {  printf("\nTHE POINTS WILL BE ADDED FROM YOUR NEXT PURCHASE ONWARDS");
               famt+=3000;
               l=3;
               i=2;
               new();
            }
       else
            { printf("\nINVALID INPUT");
            }
     }

}

//It is used to store permanently the details of the new member.
void new()
{
         float z=0.0;
    fme=fopen("card.txt","a");
    fpo=fopen("balance.txt","a");
    fna=fopen("name.txt","a");
    qwe++;
    for(int k=0;k<100;k++)
    {
      st[qwe].name[k]=na[k];
    }
    st[qwe].mem=l;
    st[qwe].point=0.0;
    fprintf(fme,"%d \n",st[qwe].mem);
    fprintf(fna,"%s \n",st[qwe].name);
    fprintf(fpo,"%f \n",z);
    qwe++;
    printf("\nYOUR MEMBERSHIP TYPE IS:%c \nYOUR MEMBERSHIP NUMBER IS:%d",ch1,qwe);
    fclose(fpo);
    fclose(fme);
    fclose(fna);
    printf("\n\nPRESS ENTER TO CONTINUE");
    fgets(dummy,100,stdin); 
}
//It is used to display membership details of all customers to the owner.
void print()
{   char ch3;
     read1();

     i--;

     printf("\nMEMBERSHIP NO            NAME                MEMBERSHIP TYPE          POINTS EARNED\n");
     for(j=0;j<i;j++)
     {   delay=nsleep(100);
         if(st[j].mem==1)
         ch3='S';
         else if(st[j].mem==2)
         ch3='G';
         else if(st[j].mem==3)
         ch3='B';
         printf("     %d\t\t\t%s" ,(j+1),st[j].name);
           for(int k=0;k<25-strlen(st[j].name);k++)
           { printf(" ");
            }
           printf("%c			%0.2f \n",ch3,st[j].point);
     }
   printf("\n\nPRESS ENTER IF DONE VIEWING\n");
scanf("%c",&v);
}

void store()
{
     fme=fopen("card.txt","w");
     fpo=fopen("balance.txt","w");
     for(i=0;i<1000;i++)
     {
        if(st[i].mem==-1)
       break;
     }

     j=0;
     while(j<i)
     {
       fprintf(fme,"%d \n",st[j].mem);
       j++;
     }
      j=0;
    while(j<i)
     {
       fprintf(fpo,"%f \n",st[j].point);
       j++;
     }
     fclose(fpo);
     fclose(fme);

}

void data_read()
{
     i=0;
     fmo=fopen("month.txt","r");
     fye=fopen("year.txt","r");

     while(!feof(fmo))
     {
       fscanf(fmo,"%f",&st1[i].months);
       i++;
     }

     i=0;
     while(!feof(fye))
     {
       fscanf(fye,"%f",&st1[i].years);
       i++;
      }

        fclose(fmo);
        fclose(fye);
}

void data_store()
{
     fmo=fopen("month.txt","w");
     fye=fopen("year.txt","w");
     for(i=0;i<12;i++)
     {
        if(st1[i].months==-1.000)
       break;
     }

     j=0;
     while(j<i)
     {
       fprintf(fmo,"%f \n",st1[j].months);
       j++;
     }
       for(i=0;i<12;i++)
     {
        if(st1[i].years==-1.000)
       break;
     }
      j=0;
    while(j<i)
     {
       fprintf(fye,"%f \n",st1[j].years);
       j++;
     }
     fclose(fye);
     fclose(fmo);

}
void data_print()
{
    fnm=fopen("nmonth.txt","r");
    for(i=0;i<12;i++)
    { fscanf(fnm,"%s",st1[i].mo);
    }
    fclose(fnm);
  data_read();
  printf("MONTHLY SALES FOR YEAR:%d \n",y);
  for(i=0;i<12;i++)
  { delay=nsleep(100);
    if(st1[i].months==-1)
     break;
    printf("%s:\t %0.2f \n",st1[i].mo,st1[i].months);
   }
printf("\n\n\n");
  int y1=y;
  printf("SALES OF THE LAST 12 YEARS\n");
  for(i=0;i<12;i++)
  { delay=nsleep(100);
    printf("%d:\t%0.2f \n",y1,st1[i].years);
   y1--;
  }
printf("\n\nPRESS ENTER IF DONE VIEWING\n");
scanf("%c",&v);

}

void graph()
{  int w[12];
   int k=y;
  float arr[6];
  arr[5]=0.0;
  char a[30][61];
 char b[30][61];
  data_read();
 int space;
float plt,plt1;
 float g;
 int ct=0;
 char v;
 int i,j;
  float max=st1[0].years;
   float max1=st1[0].months;
for(i=1;i<12;i++)
    {if(max1<st1[i].months)
      max1=st1[i].months;
    }

for(i=0;i<5;i++)
  { arr[i]=0;
  }
  arr[0]=max1;
  for(i=4;i>=0;i--)
  {
    arr[i]=(float)(5-i)*((float)max1/5);
  }


char mon[]=" JAN  FEB  MAR  APR  MAY  JUN  JUL  AUG  SEP  OCT  NOV  DEC";

for(i=0;i<30;i++)
  {  for(j=0;j<61;j++)
    {
      b[i][j]=' ';
    }
  }
  for(i=0;i<29;i++)
  {
    b[i][0]='|';
    }
     for(i=4;i<29;i+=5)
    {
    b[i][0]='-';
    }
    for(i=1;i<61;i++)
     {     b[28][i]='_';
       }

       for(i=3;i<61;i+=5)
       {  b[28][i]=' ';
          b[29][i]='|';
       }
     k=3;
     for(i=0;i<12;i++)
     { if(st1[i].months==-1)
       continue;
       plt=(float)st1[i].months/max1;
       plt*=25;
       //plt=floor(plt);
       if(plt>0 && plt<1)
       plt=1;
       plt1=plt;
      for(j=28;j>0;j--)
      { if(plt<1)
         break;
          b[j][k]='*';
         plt--;

      }

   k+=5;
     }
     printf("\n ");
       k=0;
       printf("\n\nGRAPH FOR MONTHLY SALES OF THE YEAR:%d\n\n ",y);

       for(i=0;i<30;i++)
       { if((i+1)%5==0)
         { g=arr[k];

           ct=0;
          while(g>1)
          {
           g/=10;
           ct++;

          }

          while((16-ct)>0)
          {
          printf(" ");
          ct++;
          }
         if(k==5)
         printf("%0.2f",arr[k]);
         else
         printf("%0.2f ",arr[k]);
         k++;
        }
       else
       for(space=0;space<20;space++)
         printf(" ");

      for(j=0;j<61;j++)
      {delay = nsleep(5);
       printf("%c",b[i][j]);
      }
      printf("\n ");
      }
   for(space=0;space<21;space++)
   {      printf(" ");
   }
   printf("%s",mon);

printf("\n\nPRESS ENTER IF DONE VIEWING\n");
scanf("%c",&v);

 for(i=1;i<12;i++)
    {if(max<st1[i].years)
      max=st1[i].years;
    }

  for(i=0;i<5;i++)
  { arr[i]=0;
  }
  arr[0]=max;
  for(i=4;i>=0;i--)
  {
    arr[i]=(float)(5-i)*((float)max/5);
  }



  k=y;

   for(i=0;i<12;i++)
   {  w[i]=k;
      k--;
   }

  {
 for(i=0;i<30;i++)
  {  for(j=0;j<61;j++)
    {
      a[i][j]=' ';
    }
  }
  for(i=0;i<29;i++)
  {
    a[i][0]='|';
    }
     for(i=4;i<29;i+=5)
    {
    a[i][0]='-';
    }
    for(i=1;i<61;i++)
     {     a[28][i]='_';
       }

       for(i=3;i<61;i+=5)
       {  a[28][i]=' ';
          a[29][i]='|';
       }

     k=3;

     for(i=0;i<12;i++)
     { plt=(float)st1[i].years/max;
       plt*=25;
       //plt=floor(plt);
        if(plt>0 && plt<1)
       plt=1;
       plt1=plt;
      for(j=28;j>0;j--)
      { if(plt<1)
         break;
          a[j][k]='*';
         plt--;

      }

   k+=5;
     }
     printf("\n ");
       k=0;
       printf("\n\nGRAPH FOR SALES OF THE LAST 12 YEARS\n\n ");
       for(i=0;i<30;i++)
       { if((i+1)%5==0)
         { g=arr[k];

           ct=0;
          while(g>1)
          {
           g/=10;
           ct++;

          }

          while((16-ct)>0)
          {
          printf(" ");
          ct++;
          }
         if(k==5)
         printf("%0.2f",arr[k]);
         else
         printf("%0.2f ",arr[k]);
         k++;
        }
       else
       for(space=0;space<20;space++)
         printf(" ");

      for(j=0;j<61;j++)
      { delay = nsleep(5);
       printf("%c",a[i][j]);
      }
      printf("\n ");
      }
   for(space=0;space<21;space++)
   {      printf(" ");
   }
    for(i=0;i<12;i++)
   { printf("%d ",w[i]);
   }


  printf("\n\nPRESS ENTER IF DONE VIEWING\n");
scanf("%c",&v);


}
}

void load1()
 {int a=-5;
  float k;
  int i,j,q;
  float g;
  while(a<31)
  {
   if(a%4==0)
    {printf("\n\n\n\t\t\t\t\t\t\t\n\n");

    }
   else
   {printf("\n\n\n\t\t\t\t\t\t\t    LOADING\n\n");
   }
  printf("\t\t\t                                     *****                \n");
  printf("\t\t\t                              **               **          \n");
  printf("\t\t\t                           **                     **          \n");
  printf("\t\t\t                        **                           **          \n");
  printf("\t\t\t                      **                               **          \n");
  printf("\t\t\t                    **                   ______          **          \n");
  printf("\t\t\t                   **           /             /            **         \n");
  printf("\t\t\t                  **           /             /              **         \n");
  printf("\t\t\t                 **           /___|___      /                **         \n");
  printf("\t\t\t                **                |        /                  **         \n");




  	for(i=-5;i<23;i++)
  	{ k=sqrt(484-(i*i));
 	   k=ceil(k);
    	printf("\t\t\t\t\t");
   	for(j=22;j>k;j--)
  	 {
     	printf(" ");
   	}

  	 printf("**");
  	 for(j=0;j<k;j++)
  	 { if(i<a)
  	   printf("-");

  	   else
  	   printf(" ");
  	 }
  	 for(j=0;j<k;j++)
  	 {
  	   if(i<a)
  	   printf("-");

  	   else
  	   printf(" ");
  	 }
  	   printf("** \n");
  	 }
 	a++;

 	delay = nsleep(100);

 	system("clear");
 	}


}


void load2()
 {
    int i,j;
    setbuf(stdout,NULL);
   system("clear");

    for(i=0;i<2;i++)
     {
       for(j=1;j<=5;j++)
       {
    system("clear");
    printf("\n\nVERIFYING THE PASSWORD:\n\n\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎ ▎ ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎   ▎   ▎ ▎   ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎   ▎ ▎ ▎ ▎     ▎ ▎     ▎ ▎ ▎     ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎     ▎   ▎ ▎     ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎     ▎ ▎ ▎ ▎   ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎                                     47▎ ▎\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    delay = nsleep(110);
     system("clear");
     printf("\n\nVERIFYING THE PASSWORD:\n\n\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎     ▎ ▎ ▎ ▎   ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎ ▎ ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎   ▎   ▎ ▎   ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎   ▎ ▎ ▎ ▎     ▎ ▎     ▎ ▎ ▎     ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎     ▎   ▎ ▎     ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎                                     47▎ ▎\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    delay = nsleep(110);
     system("clear");

    printf("\n\nVERIFYING THE PASSWORD:\n\n\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▎ ▎   ▎     ▎   ▎ ▎     ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎     ▎ ▎ ▎ ▎   ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎ ▎ ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎   ▎   ▎ ▎   ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎   ▎ ▎ ▎ ▎     ▎ ▎     ▎ ▎ ▎     ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎                                     47▎ ▎\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    delay = nsleep(110);
     system("clear");
    printf("\n\nVERIFYING THE PASSWORD:\n\n\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎   ▎ ▎ ▎ ▎     ▎ ▎     ▎ ▎ ▎     ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎     ▎   ▎ ▎     ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎     ▎ ▎ ▎ ▎   ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎ ▎ ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎   ▎   ▎ ▎   ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎                                     47▎ ▎\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    delay = nsleep(110);
    system("clear");
    printf("\n\nVERIFYING THE PASSWORD:\n\n\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎   ▎   ▎ ▎   ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎ ▎   ▎ ▎ ▎ ▎     ▎ ▎     ▎ ▎ ▎     ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎     ▎   ▎ ▎     ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎     ▎ ▎ ▎ ▎   ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎ ▎ ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎ ▎   ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎ ▎   ▎ ▎   ▎   ▎ ▎ ▎ ▎ ▎ ▎     ▎ ▎ ▎ ▎ ▎ ▎\n");
    printf("\t\t\t\t\t▎ ▎                                     47▎ ▎\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    printf("\t\t\t\t\t▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
    delay = nsleep(110);

    system("clear");
  }

 }
 }


 void database_read()
 {   int i=0;

     fda=fopen("database.txt","r");
     fse=fopen("sales.txt","r");
     fde=fopen("description.txt","r");

     while(!feof(fda))
     {
       fscanf(fda,"%d",&st2[i].code);
       i++;
     }
     i=0;

     while(!feof(fse))
     {
       fscanf(fse,"%f",&st2[i].sales);
       i++;
     }
     i=0;

     while(!feof(fde))
     {
       fscanf(fde,"%s",st2[i].description);
       i++;
     }

    fclose(fse);
    fclose(fda);
    fclose(fde);
 }

 void database_find_and_update(int a)
 { int i;
   database_read();
   for(i=0;i<80;i++)
   {
     if(a==st2[i].code)
       break;
   }
   st2[i].sales+=amount;
   database_store();
 }

void database_store()
{    int i=0;
     fse=fopen("sales.txt","w");


     while(i<80)
     {
       fprintf(fse,"%f \n",st2[i].sales);
       i++;
     }

     fclose(fse);
}

void database_print()
{    int k=0;
     float max;
     int w=0;
     float department[4];
     for(i=0;i<4;i++)
     { department[i]=0.0;
     }
      system("clear");
      database_read();
       printf("\nTHE DEPARTMENT WISE SALES:");
       printf("\n\nDEPARTMENT\t\tDESCRIPTION\t\t\t\t\t\tCODE\t\tSALES\n");
       max=st2[0].sales;
       for(i=0;i<80;i++)
       {  delay = nsleep(90);
          if(max<st2[i].sales)
           { max=st2[i].sales;
              w=i;
            }
         if((st2[i].code==1001)||(st2[i].code==1002)||
            (st2[i].code==1003)||(st2[i].code==1004)||
            (st2[i].code==1005)||(st2[i].code==1006)||
            (st2[i].code==1007)||(st2[i].code==1008)||
            (st2[i].code==1009)||(st2[i].code==2001)||
            (st2[i].code==2002)||(st2[i].code==2003)||
            (st2[i].code==2004)||(st2[i].code==2005)||
            (st2[i].code==2006)||(st2[i].code==2007)||
            (st2[i].code==2008)||(st2[i].code==2009)||
            (st2[i].code==3001)||(st2[i].code==3002)||
            (st2[i].code==3003)||(st2[i].code==3004))
            {
             printf("FABRIC\t\t\t%s  ",st2[i].description);
            for(j=0;j<(54-strlen(st2[i].description));j++)
            {  printf(" ");
             }
              printf("%d\t\t%0.2f\n",st2[i].code,st2[i].sales);
         }
         else
         if((st2[i].code==4001)||(st2[i].code==4002)||
           (st2[i].code==4003)||(st2[i].code==4004)||
           (st2[i].code==4005)||(st2[i].code==4006)||
           (st2[i].code==4007)||(st2[i].code==4008)||
       	   (st2[i].code==4009)||(st2[i].code==5001)||
           (st2[i].code==5002)||(st2[i].code==5003)||
           (st2[i].code==5004)||(st2[i].code==5005)||
           (st2[i].code==5006)||(st2[i].code==5007)||
           (st2[i].code==5008)||(st2[i].code==5009)||
           (st2[i].code==6001)||(st2[i].code==6002)||
           (st2[i].code==6003)||(st2[i].code==6004)||
           (st2[i].code==6005)||(st2[i].code==6006)||
           (st2[i].code==6007)||(st2[i].code==6008)||
       	   (st2[i].code==6009))
           {
              printf("PARX\t\t\t%s  ",st2[i].description);
           for(j=0;j<54-strlen(st2[i].description);j++)
            {  printf(" ");
             }
              printf("%d\t\t%0.2f\n",st2[i].code,st2[i].sales);
           }
          else
      	 if((st2[i].code==7001)||
      	 (st2[i].code==7002)||(st2[i].code==7003)||
     	 (st2[i].code==7004)||(st2[i].code==7005)||
      	 (st2[i].code==7006)||(st2[i].code==7007)||
       	 (st2[i].code==7008)||(st2[i].code==7009)||
      	 (st2[i].code==8001)||(st2[i].code==8002)||
      	 (st2[i].code==8003)||(st2[i].code==8004)||
       	 (st2[i].code==8005)||(st2[i].code==8006)||
       	 (st2[i].code==8007))
         {printf("PARK AVENUE\t\t%s  ",st2[i].description);
           for(j=0;j<54-strlen(st2[i].description);j++)
            {  printf(" ");
             }
              printf("%d\t\t%0.2f\n",st2[i].code,st2[i].sales);
         }
     	 else
      	 if((st2[i].code==9001)||
      	 (st2[i].code==9002)||(st2[i].code==9003)||
      	 (st2[i].code==9004)||(st2[i].code==9005)||
      	 (st2[i].code==9006)||(st2[i].code==9007)||
       	 (st2[i].code==9008)||(st2[i].code==9009)||
      	 (st2[i].code==10001)||(st2[i].code==10002)||
       	 (st2[i].code==11001)||(st2[i].code==11002)||
      	 (st2[i].code==11003)||(st2[i].code==11004))
         {printf("ACCESSORIES\t\t%s  ",st2[i].description);
           for(j=0;j<54-strlen(st2[i].description);j++)
            {  printf(" ");
             }
              printf("%d\t\t%0.2f\n",st2[i].code,st2[i].sales);
         }


         if(i==21||i==48||i==64)
         {printf("PRESS ENTER IF DONE VIEWING");
          fgets(dummy,100,stdin);
          system("clear");
          printf("\nTHE DEPARTMENT WISE SALES:");
       printf("\n\nDEPARTMENT\t\tDESCRIPTION\t\t\t\t\t\tCODE\t\tSALES\n");
         k++;
         }

      department[k]+=st2[i].sales;
     }
     printf("\n\nTHE MOST SOLD PRODUCT IS:%d WITH SALES OF:%0.2f",st2[w].code,max);
   printf("\n\nTHE SALES OF EACH DEPARTMENT IS:\n");
  for(i=0;i<4;i++)
 { delay = nsleep(90);
 if(i==0)
   printf("FABRIC:\t\t\t");
   else
   if(i==1)
   printf("PARX:\t\t\t");
   else
   if(i==2)
   printf("PARK AVENUE:\t\t");
   else
   if(i==3)
   printf("ACCESSORIES:\t\t");
  printf("%0.2f\n",department[i]);
 }
 printf("PRESS ENTER IF DONE VIEWING");
          fgets(dummy,100,stdin);
          system("clear");
}

int checkeryn(char a)
{
    if(a=='y' || a=='Y')
    {
        return 1;
    }
    else if(a=='n'||a=='N')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void bill_space(float a,int n)
{ int a1=(int)a;


 if(n==1)
  { j=0;
  while(a1>0)
  {
    a1/=10;
    j++;
  }
    j=12-j;
 //printf("%d",j);
  while(j>0)
  {
  printf(" ");
  j--;
  }
  printf("||");
  }
  else if(n==2)
  {
    j=0;
    while(a1>0)
   {
    a1/=10;
    j++;
   }

  j=70-j;

  while(j>0)
  {
  printf(" ");
  j--;
  }
  printf("||");
  }
  else if(n==3)
  {
   j=0;
   if(a1!=0)
   {while(a1>0)
   {
    a1/=10;
    j++;
   }
   }
   else
   j=1;
  j=37-j;

  while(j>0)
  {
  printf(" ");
  j--;
  }
  printf("||");
  }
}

int checkersize(char a)
{
    if(a=='s'||a=='S'||a=='m'||a=='M'||a=='x'||a=='X'||a=='l'||a=='L')
    {
        return 1;
    }
    else
    {
        return 0;
    }
 }

 int checkertie(char a)
 {
    if(a=='t'||a=='T'||a=='b'||a=='B')
    {
        return 1;
    }

    else
    {
        return 0;
    }

 }

void pass()
 {
     i=0;
	char c;

    static struct termios oldt, newt;

    /*tcgetattr gets the parameters of the current terminal
    STDIN_FILENO will tell tcgetattr that it should write the settings
    of stdin to oldt*/
    tcgetattr( STDIN_FILENO, &oldt);
    /*now the settings will be copied*/
    newt = oldt;

    /*ICANON normally takes care that one line at a time will be processed
    that means it will return if it sees a "\n" or an EOF or an EOL*/
    newt.c_lflag &= ~(ICANON | ECHO);

    /*Those new settings will be set to STDIN
    TCSANOW tells tcsetattr to change attributes immediately. */
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    /*This is your part:
    I choose 'e' to end input. Notice that EOF is also turned off
    in the non-canonical mode*/
    while((c=getchar())!= '\n')
    {
	   printf("*");
		PASSWORD[i]=c;
		i++;
	}

    /*restore the old settings*/
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

    }
    
    void end_screen()
{   
  strcpy(st3[0].end,"LOADING.");
  strcpy(st3[1].end,"LOADING..");
  strcpy(st3[2].end,"LOADING...");
  strcpy(st3[3].end,"LOADING....");
  strcpy(st3[4].end,"LOADING.....");
  strcpy(st3[5].end,"LOADING......");
  strcpy(st3[6].end,"LOADING.......");
  strcpy(st3[7].end,"GENERATING ENVIRONMENT.");
  strcpy(st3[8].end,"DEGENERATING ENVIRONMENT..");
  strcpy(st3[9].end,"DEGENERATING ENVIRONMENT...");
  strcpy(st3[10].end,"DEGENERATING ENVIRONMENT....");
  strcpy(st3[11].end,"DEGENERATING ENVIRONMENT.....");
  strcpy(st3[12].end,"DEGENERATING ENVIRONMENT......");
  strcpy(st3[13].end,"UNPARSING VARIABLES.");
  strcpy(st3[14].end,"UNPARSING VARIABLES..");
  strcpy(st3[15].end,"UNPARSING VARIABLES...");
  strcpy(st3[16].end,"UNPARSING VARIABLES....");
  strcpy(st3[17].end,"UNPARSING VARIABLES.....");
  strcpy(st3[18].end,"UPDATING DATABASE.");
  strcpy(st3[19].end,"UPDATING DATABASE..");
  strcpy(st3[20].end,"UPDATING DATABASE...");
  strcpy(st3[21].end,"UPDATING DATABASE....");
  strcpy(st3[22].end,"UPDATING DATABASE.....");
  strcpy(st3[23].end,"DESTOYING WORKSPACE.");
  strcpy(st3[24].end,"DESTOYING WORKSPACE..");
  strcpy(st3[25].end,"DESTOYING WORKSPACE...");
  strcpy(st3[26].end,"DESTOYING WORKSPACE....");
  strcpy(st3[27].end,"DESTOYING WORKSPACE.....");
  strcpy(st3[28].end,"DESTOYING WORKSPACE......");
  strcpy(st3[29].end,"STORING THE SUITS.");
  strcpy(st3[30].end,"STORING THE SUITS..");
  strcpy(st3[31].end,"STORING THE SUITS...");
  strcpy(st3[32].end,"STORING THE SUITS....");
  strcpy(st3[33].end,"STORING THE SUITS.....");
  strcpy(st3[34].end,"UNLINKING FILES.");
  strcpy(st3[35].end,"UNLINKING FILES..");
  strcpy(st3[36].end,"UNLINKING FILES...");
  strcpy(st3[37].end,"UNLINKING FILES....");
  strcpy(st3[38].end,"UNLINKING FILES.....");
  strcpy(st3[39].end,"UNLINKING FILES......");
  strcpy(st3[40].end,"DEGENERATING STAFF.");
  strcpy(st3[41].end,"DEGENERATING STAFF..");
  strcpy(st3[42].end,"DEGENERATING STAFF...");
  strcpy(st3[43].end,"DEGENERATING STAFF....");
  strcpy(st3[44].end,"DEGENERATING STAFF.....");
  strcpy(st3[44].end,"DEGENERATING STAFF......");
  strcpy(st3[44].end,"DEGENERATING STAFF.......");
  strcpy(st3[45].end,"RESETTING PARAMETERS.");
  strcpy(st3[46].end,"RESETTING PARAMETERS..");
  strcpy(st3[47].end,"RESETTING PARAMETERS...");
  strcpy(st3[48].end,"RESETTING PARAMETERS....");
  strcpy(st3[49].end,"RESETTING PARAMETERS.....");
  strcpy(st3[50].end,"RESETTING PARAMETERS......");
  strcpy(st3[51].end,"DEINITIALIZING ELEMENTS.");
  strcpy(st3[52].end,"DEINITIALIZING ELEMENTS..");
  strcpy(st3[53].end,"DEINITIALIZING ELEMENTS...");
  strcpy(st3[54].end,"DEINITIALIZING ELEMENTS....");
  strcpy(st3[55].end,"DEINITIALIZING ELEMENTS.....");
  strcpy(st3[56].end,"DEINITIALIZING ELEMENTS......");
  strcpy(st3[57].end,"DEINITIALIZING ELEMENTS.......");
  strcpy(st3[58].end,"WASTING SOME MORE TIME.");
  strcpy(st3[59].end,"WASTING SOME MORE TIME..");
  strcpy(st3[60].end,"WASTING SOME MORE TIME...");
  strcpy(st3[61].end,"WASTING SOME MORE TIME....");
  strcpy(st3[62].end,"WASTING SOME MORE TIME.....");
  strcpy(st3[63].end,"WASTING SOME MORE TIME......");
  strcpy(st3[64].end,"ALMOST DONE.");
  strcpy(st3[65].end,"ALMOST DONE..");
  strcpy(st3[66].end,"ALMOST DONE...");
  strcpy(st3[67].end,"ALMOST DONE....");
  strcpy(st3[68].end,"ALMOST DONE.....");
  strcpy(st3[69].end,"ALMOST DONE......");
  strcpy(st3[70].end,"ALMOST DONE.......");
  strcpy(st3[71].end,"DONE");
  int i;
  int delay;
  system("clear");
  for(i=0;i<72;i++)
 {
  printf("\n\n\n\t       ++++++++++  ++   ++  +++++++");
  printf("\n\t       ++++++++++  ++   ++  ++");
  printf("\n\t           ++      +++++++  +++++++");
  printf("\n\t           ++      +++++++  +++++++");
  printf("\n\t           ++      ++   ++  ++");
  printf("\n\t           ++      ++   ++  +++++++ ==================================================== ++");
  printf("\n\t                                                                                          ++");
  printf("\n\t       ++  ++      +++++   ++              +  ++   ++    ++       ++     ++ +++++          ++");
  printf("\n\t       +++   ++    ++++++   ++            +    ++   ++++   ++   ++   ++   ++     ++         ++");
  printf("\n\t       ++     ++        ++   ++          +     ++    ++    ++  ++    ++   ++      ++         ++");
  printf("\n\t       ++     ++         ++   ++        +      ++    ++    ++  ++    ++   ++      ++       ++++ ");
  printf("\n\t       ++   +           ++++   ++      +       ++    ++    ++  ++    ++   ++      ++     ++  ++");
  printf("\n\t       ++ +          ++    ++   ++    +        ++    ++    ++  ++    ++   ++      ++    ++   ++");
  printf("\n\t       ++  ++     ++        ++   ++  +         ++    ++    ++  ++    ++   ++      ++   ++    ++");
  printf("\n\t       ++   ++   ++         ++     ++          ++    ++    ++  ++    ++   ++      ++   ++    ++");
  printf("\n\t       ++    ++   ++        +++     +          ++    ++    ++  ++    ++   ++      ++   ++    ++");
  printf("\n\t       ++     ++   ++        ++    +           ++    ++    ++  ++   ++    ++      ++   ++    ++");
  printf("\n\t       ++      ++    ++ ++++ ++   +            ++    ++    ++    ++       ++      ++      ++");
  printf("\n\t                                 +  ");
  printf("\n\t       ======================== + ========================== +++    ++   ++     ++     ++++++");
  printf("\n\t                           ++  +                           ++   ++  ++   ++  ++    ++  ++    ++");
  printf("\n\t                             ++                             ++      ++   ++  ++    ++  ++    ++");
  printf("\n\t                                                               ++   +++++++  ++    ++  ++++++");
  printf("\n\t                                                                ++  ++   ++  ++    ++  ++");
  printf("\n\t                                                           ++   ++  ++   ++  ++    ++  ++");
  printf("\n\t                                                             +++    ++   ++     ++     ++");

  printf("\n");
  printf("%s",st3[i].end);
  printf("\n");
  printf("\n");
  delay = nsleep(100);
  system("clear");
 }
 /*for(int j=0;j<75000000;j++)
  {
  }*/
  delay = nsleep(500);
  system("clear");
}  
  

void initial_screen()
{   
  strcpy(st3[0].load,"LOADING.");
  strcpy(st3[1].load,"LOADING..");
  strcpy(st3[2].load,"LOADING...");
  strcpy(st3[3].load,"LOADING....");
  strcpy(st3[4].load,"LOADING.....");
  strcpy(st3[5].load,"LOADING......");
  strcpy(st3[6].load,"LOADING.......");
  strcpy(st3[7].load,"GENERATING ENVIRONMENT.");
  strcpy(st3[8].load,"GENERATING ENVIRONMENT..");
  strcpy(st3[9].load,"GENERATING ENVIRONMENT...");
  strcpy(st3[10].load,"GENERATING ENVIRONMENT....");
  strcpy(st3[11].load,"GENERATING ENVIRONMENT.....");
  strcpy(st3[12].load,"GENERATING ENVIRONMENT......");
  strcpy(st3[13].load,"PARSING VARIABLES.");
  strcpy(st3[14].load,"PARSING VARIABLES..");
  strcpy(st3[15].load,"PARSING VARIABLES...");
  strcpy(st3[16].load,"PARSING VARIABLES....");
  strcpy(st3[17].load,"PARSING VARIABLES.....");
  strcpy(st3[18].load,"UPDATING DATABASE.");
  strcpy(st3[19].load,"UPDATING DATABASE..");
  strcpy(st3[20].load,"UPDATING DATABASE...");
  strcpy(st3[21].load,"UPDATING DATABASE....");
  strcpy(st3[22].load,"UPDATING DATABASE.....");
  strcpy(st3[23].load,"CREATING WORKSPACE.");
  strcpy(st3[24].load,"CREATING WORKSPACE..");
  strcpy(st3[25].load,"CREATING WORKSPACE...");
  strcpy(st3[26].load,"CREATING WORKSPACE....");
  strcpy(st3[27].load,"CREATING WORKSPACE.....");
  strcpy(st3[28].load,"CREATING WORKSPACE......");
  strcpy(st3[29].load,"BRUSHING THE SUITS.");
  strcpy(st3[30].load,"BRUSHING THE SUITS..");
  strcpy(st3[31].load,"BRUSHING THE SUITS...");
  strcpy(st3[32].load,"BRUSHING THE SUITS....");
  strcpy(st3[33].load,"BRUSHING THE SUITS.....");
  strcpy(st3[34].load,"LINKING FILES.");
  strcpy(st3[35].load,"LINKING FILES..");
  strcpy(st3[36].load,"LINKING FILES...");
  strcpy(st3[37].load,"LINKING FILES....");
  strcpy(st3[38].load,"LINKING FILES.....");
  strcpy(st3[39].load,"LINKING FILES......");
  strcpy(st3[40].load,"GENERATING STAFF.");
  strcpy(st3[41].load,"GENERATING STAFF..");
  strcpy(st3[42].load,"GENERATING STAFF...");
  strcpy(st3[43].load,"GENERATING STAFF....");
  strcpy(st3[44].load,"GENERATING STAFF.....");
  strcpy(st3[44].load,"GENERATING STAFF......");
  strcpy(st3[44].load,"GENERATING STAFF.......");
  strcpy(st3[45].load,"RESETTING PARAMETERS.");
  strcpy(st3[46].load,"RESETTING PARAMETERS..");
  strcpy(st3[47].load,"RESETTING PARAMETERS...");
  strcpy(st3[48].load,"RESETTING PARAMETERS....");
  strcpy(st3[49].load,"RESETTING PARAMETERS.....");
  strcpy(st3[50].load,"RESETTING PARAMETERS......");
  strcpy(st3[51].load,"INITIALIZING ELEMENTS.");
  strcpy(st3[52].load,"INITIALIZING ELEMENTS..");
  strcpy(st3[53].load,"INITIALIZING ELEMENTS...");
  strcpy(st3[54].load,"INITIALIZING ELEMENTS....");
  strcpy(st3[55].load,"INITIALIZING ELEMENTS.....");
  strcpy(st3[56].load,"INITIALIZING ELEMENTS......");
  strcpy(st3[57].load,"INITIALIZING ELEMENTS.......");
  strcpy(st3[58].load,"WASTING SOME MORE TIME.");
  strcpy(st3[59].load,"WASTING SOME MORE TIME..");
  strcpy(st3[60].load,"WASTING SOME MORE TIME...");
  strcpy(st3[61].load,"WASTING SOME MORE TIME....");
  strcpy(st3[62].load,"WASTING SOME MORE TIME.....");
  strcpy(st3[63].load,"WASTING SOME MORE TIME......");
  strcpy(st3[64].load,"ALMOST DONE.");
  strcpy(st3[65].load,"ALMOST DONE..");
  strcpy(st3[66].load,"ALMOST DONE...");
  strcpy(st3[67].load,"ALMOST DONE....");
  strcpy(st3[68].load,"ALMOST DONE.....");
  strcpy(st3[69].load,"ALMOST DONE......");
  strcpy(st3[70].load,"ALMOST DONE.......");
  strcpy(st3[71].load,"DONE");
  int i;
  int delay;
  system("clear");
  for(i=0;i<72;i++)
 {
  printf("\n\n\n\t       ++++++++++  ++   ++  +++++++");
  printf("\n\t       ++++++++++  ++   ++  ++");
  printf("\n\t           ++      +++++++  +++++++");
  printf("\n\t           ++      +++++++  +++++++");
  printf("\n\t           ++      ++   ++  ++");
  printf("\n\t           ++      ++   ++  +++++++ ==================================================== ++");
  printf("\n\t                                                                                          ++");
  printf("\n\t       ++  ++      +++++   ++              +  ++   ++    ++       ++     ++ +++++          ++");
  printf("\n\t       +++   ++    ++++++   ++            +    ++   ++++   ++   ++   ++   ++     ++         ++");
  printf("\n\t       ++     ++        ++   ++          +     ++    ++    ++  ++    ++   ++      ++         ++");
  printf("\n\t       ++     ++         ++   ++        +      ++    ++    ++  ++    ++   ++      ++       ++++ ");
  printf("\n\t       ++   +           ++++   ++      +       ++    ++    ++  ++    ++   ++      ++     ++  ++");
  printf("\n\t       ++ +          ++    ++   ++    +        ++    ++    ++  ++    ++   ++      ++    ++   ++");
  printf("\n\t       ++  ++     ++        ++   ++  +         ++    ++    ++  ++    ++   ++      ++   ++    ++");
  printf("\n\t       ++   ++   ++         ++     ++          ++    ++    ++  ++    ++   ++      ++   ++    ++");
  printf("\n\t       ++    ++   ++        +++     +          ++    ++    ++  ++    ++   ++      ++   ++    ++");
  printf("\n\t       ++     ++   ++        ++    +           ++    ++    ++  ++   ++    ++      ++   ++    ++");
  printf("\n\t       ++      ++    ++ ++++ ++   +            ++    ++    ++    ++       ++      ++      ++");
  printf("\n\t                                 +  ");
  printf("\n\t       ======================== + ========================== +++    ++   ++     ++     ++++++");
  printf("\n\t                           ++  +                           ++   ++  ++   ++  ++    ++  ++    ++");
  printf("\n\t                             ++                             ++      ++   ++  ++    ++  ++    ++");
  printf("\n\t                                                               ++   +++++++  ++    ++  ++++++");
  printf("\n\t                                                                ++  ++   ++  ++    ++  ++");
  printf("\n\t                                                           ++   ++  ++   ++  ++    ++  ++");
  printf("\n\t                                                             +++    ++   ++     ++     ++");

  printf("\n");
  printf("%s",st3[i].load);
  printf("\n");
  printf("\n");
  delay = nsleep(100);
  system("clear");
 }
 /*for(int j=0;j<75000000;j++)
  {
  }*/
  delay = nsleep(500);
  system("clear");
}  
    
