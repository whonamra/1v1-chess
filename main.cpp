#include<iostream>
#include<stdlib.h>
#include"movement.h"
#include"movement2.h"
#include"check1p.h"
#include"check2p.h"
#include"Checkmate1.h"
#include"Checkmate2.h"

using namespace std;

char a[10][10]={{' ',' ','0','1','2','3','4','5','6','7'},
                {' ',' ','_','_','_','_','_','_','_','_'},
                {'0','|','r','n','b','k','q','b','n','r'},
                {'1','|','p','p','p','p','p','p','p','p'},
                {'2','|',' ',' ',' ',' ',' ',' ',' ',' '},
                {'3','|',' ',' ',' ',' ',' ',' ',' ',' '},
                {'4','|',' ',' ',' ',' ',' ',' ',' ',' '},
                {'5','|',' ',' ',' ',' ',' ',' ',' ',' '},
                {'6','|','P','P','P','P','P','P','P','P'},
                {'7','|','R','N','B','K','Q','B','N','R'}};

int player_no=0;
int flag=0,c=0,d=0,i,j;
int check=0;

class player
{
       public:
              int r_initial,c_initial,r_final,c_final;

       public:
              bool input()
              {
                    char e,b,c,d;
                    cout << endl << "Initial position of piece : ";
                    cin >> e>>b;
                    cout << "Position to be moved to : ";
                    cin >> c>>d;

                    /*the following addition is done to the co-ordinates as the co-ordinates entered by the user will be short by 2 units as
                    on the screen the board is denoted as a 8x8 matrix but is in turn a 10x10 matrix*/
                    r_initial=int(e-48);
                    r_final=int(c-48);
                    c_initial=int(b-48);
                    c_final=int(d-48);

                    r_initial+=2;
                    c_initial+=2;
                    r_final+=2;
                    c_final+=2;

                    if(check_input())
                    {
                        ::check=0;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
              }

              bool check_input()
              {
                    if((r_initial >=2 &&  r_initial <=9) && (c_initial >=2 &&  c_initial <=9) && (r_final >=2 &&  r_final <=9) && (c_final >=2 &&  c_final <=9))
                    {
                        if(player_no==1 && ::check==0 && (a[r_initial][c_initial]=='p' || a[r_initial][c_initial]=='b' || a[r_initial][c_initial]=='q' || a[r_initial][c_initial]=='k' ||
                           a[r_initial][c_initial]=='r' || a[r_initial][c_initial]=='n'))
                        {
                                //cout << "VALID INPUT" << endl;
                                return true;
                        }
                        else if(player_no==2 && ::check==0 && (a[r_initial][c_initial]=='P' || a[r_initial][c_initial]=='B' || a[r_initial][c_initial]=='Q' || a[r_initial][c_initial]=='K' ||
                           a[r_initial][c_initial]=='R' || a[r_initial][c_initial]=='N'))
                        {
                                //cout << "VAILD INPUT";
                                return true;
                        }
                        else if(::check!=0 && ::player_no==1)
                        {
                            if(a[r_initial][c_initial] == 'k' || a[r_initial][c_initial] == 'q' || a[r_initial][c_initial] == 'r' || a[r_initial][c_initial] == 'b')
                            {
                                //cout << "VALID MOVE " << endl;

                                return true;
                            }
                            else
                            {
                                cout << "INLVALID MOVE" << endl;
                                return false;
                            }
                        }
                        else if(::check!=0 && ::player_no==2)
                        {
                            if(a[r_initial][c_initial] == 'K' || a[r_initial][c_initial] == 'Q' || a[r_initial][c_initial] == 'R' || a[r_initial][c_initial] == 'B')
                            {
                                //cout << "VALID MOVE " << endl;

                                return true;
                            }
                            else
                            {
                                cout << "INVALID MOVE" << endl;
                                return false;
                            }
                        }
                        else
                        {
                            cout << "INVALID MOVE" << endl;
                            return false;
                        }

                    }
                    else
                    {
                        cout << "INVALID INPUT";
                        return false;
                    }
              }
};

class logic : public player
{
public:
    void setvalue(player p1)
    {
         r_initial=p1.r_initial;
         c_initial=p1.c_initial;
         r_final=p1.r_final;
         c_final=p1.c_final;
    }

    int apply_logic()
    {
        switch(::player_no)
        {
            case 1:
            {
                switch(a[r_initial][c_initial])
                {
                 case 'p':
                    {
                        if(pawn1move(r_initial,c_initial,r_final,c_final,a)==1)
                        {
                            return true;
                        }
                        else
                        {
                            cout << "ERROR !!!" << endl;
                            return false;
                        }
                        break;
                 }

                 case 'r':
                     {
                        if(rook1move(r_initial,c_initial,r_final,c_final,a)==1)
                        {
                            return true;
                        }
                        else
                        {
                            cout << "ERROR !!!" << endl;
                            return false;
                        }
                        break;
                     }

                 case 'b':
                     {
                        if(bishop1move(r_initial,c_initial,r_final,c_final,a)==1)
                        {
                            return true;
                        }
                        else
                        {
                            cout << "ERROR !!!" << endl;
                            return false;
                        }
                        break;
                     }

                 case 'q':
                     {
                        if(queen1move(r_initial,c_initial,r_final,c_final,a)==1)
                        {
                            return true;
                        }
                        else
                        {
                            cout << "ERROR !!!" << endl;
                            return false;
                        }
                        break;
                     }

                 case 'k':
                    {
                        if(king1move(r_initial,c_initial,r_final,c_final,a)==1)
                        {
                            return true;
                        }
                        else
                        {
                            cout << "ERROR !!!" << endl;
                            return false;
                        }
                        break;
                    }

                 case 'n':
                     {
                        if(knight1move(r_initial,c_initial,r_final,c_final,a)==1)
                        {
                            return true;
                        }
                        else
                        {
                            cout << "ERROR !!!" << endl;
                            return false;
                        }
                        break;
                     }

                 default:
                    {
                        cout << "This piece can't be accessed by you." << endl;
                        break;
                    }
                }
                break;
            }

            case 2:
                {
                    switch(a[r_initial][c_initial])
                    {
                        case 'P':
                            {
                                if(pawn2move(r_initial,c_initial,r_final,c_final,a)==1)
                                {
                                    return true;
                                }
                                else
                                {
                                    cout << "ERROR !!!" << endl;
                                    return false;
                                }
                                break;
                            }

                        case 'R':
                            {
                                if(rook2move(r_initial,c_initial,r_final,c_final,a)==1)
                                {
                                    return true;
                                }
                                else
                                {
                                    cout << "ERROR !!!" << endl;
                                    return false;
                                }
                                break;
                            }

                        case 'B':
                            {
                                if(bishop2move(r_initial,c_initial,r_final,c_final,a)==1)
                                {
                                    return true;
                                }
                                else
                                {
                                    cout << "ERROR !!!" << endl;
                                    return false;
                                }
                                break;
                            }

                        case 'Q':
                            {
                                if(queen2move(r_initial,c_initial,r_final,c_final,a)==1)
                                {
                                    return true;
                                }
                                else
                                {
                                    cout << "ERROR !!!" << endl;
                                    return false;
                                }
                                break;
                            }

                        case 'N':
                            {
                                if(knight2move(r_initial,c_initial,r_final,c_final,a)==1)
                                {
                                    return true;
                                }
                                else
                                {
                                    cout << "ERROR !!!" << endl;
                                    return false;
                                }
                                break;
                            }

                        case 'K':
                           {
                                if(king2move(r_initial,c_initial,r_final,c_final,a)==1)
                                {
                                    return true;
                                }
                                else
                                {
                                    cout << "ERROR !!!" << endl;
                                    return false;
                                }
                                break;
                           }

                        default:
                          {
                                cout << "This piece can't be accessed by you." << endl;
                                break;
                          }
                    }
                    break;
                }
        }
    }

    bool check_condition(){

        switch(::player_no)
        {
            case 1:
                {
                    switch(a[r_final][c_final])
                    {
                        case 'p':
                        {
                            if(checkpawn1(r_initial,c_initial,r_final,c_final,a)==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'k':
                        {
                            int z=0;
                            for(int i=r_final-1;i<=r_final+1;i++)
                            {
                                for(int j=c_final-1;j<=c_final+1;j++)
                                {
                                    if((i!=r_final || j!=c_final) && ((i>=2 && j>=2) && (i<=10 && j<=10)))
                                    {
                                        if(a[i][j]=='K')
                                        {
                                            z=1;
                                        }
                                    }
                                }
                            }
                            if(z==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'b':
                        {
                            if(checkbishop1(r_initial,c_initial,r_final,c_final,a)==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'r':
                        {
                            if(checkrook1(r_initial,c_initial,r_final,c_final,a)==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'n':
                        {
                           if(checkknight1(r_initial,c_initial,r_final,c_final,a)==1)
                           {
                               return true;
                           }
                           else
                           {
                               return false;
                           }
                           break;
                       }

                        case 'q':
                        {
                            if(checkqueen1(r_initial,c_initial,r_final,c_final,a)==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                      }

                        default:
                        {
                        return false;
                     }
                }
                break;
                }
            case 2:
                {
                    switch(a[r_final][c_final])
                    {
                        case 'P':
                        {
                            if(checkpawn2(r_initial,c_initial,r_final,c_final,a)==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'K':
                        {
                            int z=0;
                            for(int i=r_final-1; i<=r_final+1; i++)
                            {
                                for(int j=c_final-1;j<=c_final+1;j++)
                                {
                                    if((i!=r_final || j!=c_final) && ((i>=2 && j>=2) && (i<=10 && j<=10)) )
                                    {
                                        if(a[i][j]=='k')
                                        {
                                            z=1;
                                        }
                                    }
                                }
                            }
                            if(z==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'B':
                        {
                            if(checkbishop2(r_initial,c_initial,r_final,c_final,a)==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'R':
                        {
                            if(checkrook2(r_initial,c_initial,r_final,c_final,a)==1)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        }

                        case 'N':
                        {
                           if(checkknight2(r_initial,c_initial,r_final,c_final,a)==1)
                           {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                           break;
                        }


                        case 'Q':
                        {
                                if(checkqueen2(r_initial,c_initial,r_final,c_final,a)==1)
                                {
                                    return true;
                                }
                                else
                                {
                                    return false;
                                }
                                break;
                        }
                        default:
                        {
                            return false;
                        }
                     }
                     break;
                  }
                default:
                {
                    return false;
                }

             }
        }
};

class print : public logic
{
 public:
    void print_board()
    {
        system("CLS");
        cout << endl;
        for(int i=0;i<10;i++)
        {
            cout << "\t\t\t\t\t   ";
             for(int j=0;j<10 ;j++)
             {
                  cout << a[i][j] <<"  " ;
             }
            cout<<endl<<endl;
       }
    }
};

int main()
{
    player p1;
    player p2;
    print board;
    logic l;
    int choice,ch1;
    do
    {
        cout<< "\n\n\n\n\n\t\t\t\t\t   _____ _    _ ______  _____ _____ \n\t\t\t\t\t"<<
                                    "/ ____ | |  | |  ____|/ ____/ ____| \n\t\t\t\t\t"<<
                                    "| |    | |__| | |__  | (___| (___  \n\t\t\t\t\t"<<
                                    "| |    |  __  |  __|  \\___  \\___ \\ \n\t\t\t\t\t"<<
                                    "\\_____ |_|  |_|______|_____/_____/ \n\n\n" << endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"1. START GAME."<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"2. INSTRUCTIONS"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"3. CREDITS"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"4. EXIT"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
                 case 1:
                {
                    while(1)
                    {
                        for(int s=0;s<1000;s++){}
                        board.print_board();
                        cout << endl << "Player 1 : " << endl;

                        if(l.logic::check_condition())
                        {
                            ::check=2;
                            cout <<"CHECK !!!" << endl;
                            cout << "Your king is under check and you can move king, queen, bishop , rook " << endl;
                        }
                        if(check_checkmate(a)<=0)
                        {
                            cout << "CHECKMATE FOR PLAYER 1 !!!" <<endl;
                            cout  << "PLAYER 2 WINS " << endl << endl;
                            exit(0);
                        }
                        ::player_no=1;
                        if(p1.input())
                        {
                            l.setvalue(p1);
                            while(!(l.apply_logic()))
                            {
                                p1.input();
                                l.setvalue(p1);
                            }
                            for(int s=0;s<1000;s++){}
                            board.print_board();
                            if(l.logic::check_condition())
                            {
                                ::check=2;
                                cout <<"CHECK !!!" << endl;
                                cout << "Your king is under check and you can move king, queen, bishop , rook " << endl;
                            }
                        }
                        else
                        {
                            while(!p1.input())
                            {
                                p1.input();
                            }
                            l.setvalue(p1);

                            while(!(l.apply_logic()))
                            {
                                p1.input();
                                l.setvalue(p1);
                            }
                            for(int s=0;s<1000;s++){}
                            board.print_board();
                            if(l.logic::check_condition())
                            {
                                ::check=2;
                                cout <<"CHECK !!!" << endl;
                                cout << "Your king is under check and you can move king, queen, bishop , rook " << endl;
                            }
                        }

                        cout << endl << "Player 2 : " <<endl;
                        if(check_checkmate2(a)<=0)
                            {
                                cout << "CHECKMATE FOR PLAYER 2 !!!" << endl;
                                cout  << "PLAYER 1 WINS " << endl << endl;
                                exit(0);
                            }
                        ::player_no=2;
                        if(p2.input())
                        {
                            l.setvalue(p2);
                            while(!(l.apply_logic()))
                            {
                                p2.input();
                                l.setvalue(p2);
                            }
                            for(int s=0;s<1000;s++){}
                            board.print_board();
                            if(l.logic::check_condition())
                            {
                                ::check=1;
                                cout << "CHECK 2 !!!" << endl;
                                cout << "Your king is under check and you can move king, queen, bishop , rook " << endl;
                            }
                        }
                        else
                        {
                            while(!p2.input())
                            {
                                p2.input();
                            }
                            l.setvalue(p2);
                            while(!(l.apply_logic()))
                            {
                                p2.input();
                                l.setvalue(p2);
                            }
                            for(int s=0;s<1000;s++){}
                        board.print_board();
                        if(l.logic::check_condition())
                        {
                            ::check=1;
                            cout <<"CHECK !!!" << endl;
                            cout << "Your king is under check and you can move king, queen, bishop , rook " << endl;
                        }
                    }
                }
                break;
                }

                case 2:
                {
                    system("CLS");
                    cout<<"In this game u will have two palyers"<<endl << endl;
                    cout<<"\nDo u want to go back to menu again(1.yes/2.no):";
                    cin>>ch1;
                    if(ch1==1)
                    {
                        system("CLS");
                    }
                    break;
                }

                case 3:
                {

                    system("CLS");
                        cout<<" This game is developed by : "<<endl<<endl<<" 18DCS135 - DHRUVAM ZAVERI"<<endl<<" 18DCS132 - MURTAZA VASI"
                        <<endl<<" 18DCS133 - DHRUVISHA VASOYA "<<endl<<" 18DCS120 - NAMRA SOLANKI"<<endl << endl;
                        cout<<"\nDo u want to go back to menu again(1.yes/2.no):";
                        cin>>ch1;
                        if(ch1==1)
                        {
                            system("CLS");
                        }
                        break;
                }

                case 4:
                {
                    exit(0);
                    break;
                }

                default:
                {
                    system("CLS");
                    cout<<"INVALID CHOICE"<<endl;
                    cout<<"\nDo u want to go back to menu again(1.yes/2.no):";
                    cin>>ch1;
                    if(ch1==1)
                    {
                        system("CLS");
                    }
                    break;
                }

        }
    }while(ch1==1);
    return 0;
}
