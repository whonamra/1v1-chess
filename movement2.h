#include<math.h>
using namespace std;
int pawn2move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    if(r_initial==8)
    {
        if(r_final==r_initial-1 && a[r_initial-1][c_initial]==' ' && c_final==c_initial)
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        else if(r_final==r_initial-2 && a[r_initial-2][c_initial]==' ' && c_final==c_initial && a[r_initial-1][c_initial]==' ')
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        else if(r_final==r_initial-1 && (c_final==c_initial+1 || c_final==c_initial-1) && a[r_final][c_final]!='P'&& a[r_final][c_final]!='Q'&&a[r_final][c_final]!='K'&&
                a[r_final][c_final]!='B'&& a[r_final][c_final]!='R'&&a[r_final][c_final]!='N' && a[r_final][c_final]!=' ')
        {
            char tempi;
            tempi=a[r_initial][c_initial];
            a[r_final][c_final]=tempi;
            a[r_initial][c_initial]=' ';
            return 1;
        }
        else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
            || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
        {
            //cout << "OBSTACLE ENCOUNTERED" << endl;
            return 0;
        }
        else
        {
            //cout<<"INVALID MOVE:pawn does not move in this manner"<<endl;
            return 0;
        }
    }
    else
    {
        if(r_final==r_initial-1 && (c_final==c_initial+1 || c_final==c_initial-1) && a[r_final][c_final]!='P'&& a[r_final][c_final]!='Q'&&a[r_final][c_final]!='K'&&
            a[r_final][c_final]!='B'&& a[r_final][c_final]!='R'&&a[r_final][c_final]!='N' && a[r_final][c_final]!=' ')
        {
            char temp;
            temp=a[r_initial][c_initial];
            a[r_final][c_final]=temp;
            a[r_initial][c_initial]=' ';
            return 1;
        }
        if(r_final==r_initial-1 && a[r_initial-1][c_initial]==' ' && c_final==c_initial)
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
            || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
        {
            //cout << "OBSTACLE ENCOUNTERED" << endl;
            return 0;
        }
        else
        {
            //cout<<"INVALID MOVE:pawn does not move in this manner"<<endl;
            return 0;
        }
    }
}



using namespace std;
int rook2move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int i,temp1,c;
    c=0;

    /*the following for loops checks that there are no pieces present b/w the final and initial position by constantly
    incrementing or decrementing the value of the row or column*/

    if(c_final == c_initial)
    {

                /*this 2 for loops takes the care of obstacle clearence in vertical direction*/

                            for(i=r_initial+1 ; i<r_final ; i++)                      // for loop to check vertically downwards movement
                            {
                                if(a[i][c_initial]!=' ')
                                {
                                    c=1;
                                }
                            }
                            for(i=r_initial-1 ; i>r_final ; i--)			  //for loops to check vertically upwards movement
                            {
                                if(a[i][c_initial]!=' ')
                                {
                                    c=1;
                                }
                            }
                        }

                        if(r_final == r_initial)
                        {
                            for(i=c_initial+1 ; i<c_final ; i++)			 //for loops to check movement toward right-side
                            {
                                if(a[r_initial][i]!=' ')
                                {
                                    c=1;
                                }
                            }
                            c=0;
                            for(i=c_initial-1 ; i>c_final ; i--)			//for loops to check movement towards left-side
                            {
                                if(a[r_initial][i]!=' ')
                                {
                                    c=1;
                                }
                            }
                        }

                    /*the logic for checking the movement of rook is that if the co-ordinates lie in a vertical or horizontal straight
                      line then the earlier declared variables rook_r and rook_c  on addition/subtraction with the initial co-ordinates will
                      be equal to the final co-ordinates entered*/

                        if(c==0)
                        {
                            if( ((r_initial==r_final && c_final != c_initial) || (c_initial==c_final && r_final != r_initial)) &&
                                a[r_final][c_final]==' ')
                            {
                                swap(a[r_initial][c_initial],a[r_final][c_final]);
                                return 1;
                            }
                            else if( ((r_initial==r_final && c_final != c_initial) || (c_initial==c_final && r_final != r_initial)) &&
                                  a[r_final][c_final]!=' ' && (a[r_final][c_final]!='P'&& a[r_final][c_final]!='Q'&&a[r_final][c_final]!='K'&&
                                 a[r_final][c_final]!='R'&& a[r_final][c_final]!='B'&&a[r_final][c_final]!='N'))
                            {
                                    temp1=a[r_initial][c_initial];
                                    a[r_final][c_final]=a[r_initial][c_initial];
                                    a[r_initial][c_initial]=' ';
                                    return 1;
                            }
                            else
                            {
                                //cout  << endl << "INVALID MOVE : rook does not move in this manner" << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            //cout  << endl << "INVALID MOVE : obstacle encountered and rook does not move in this manner" << endl;
                            return 0;
                        }
}



using namespace std;
int knight2move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    if(r_final==r_initial+2 || r_final==r_initial-2)
    {
        if(c_final == c_initial+1 || c_final == c_initial-1)
        {
            if(a[r_final][c_final]!='P' || a[r_final][c_final]!='R' || a[r_final][c_final]!='N' || a[r_final][c_final]!='B' || a[r_final][c_final]!='Q'
               || a[r_final][c_final]!='K')
            {
                swap(a[r_initial][c_initial],a[r_final][c_final]);
                a[r_initial][c_initial] = ' ';
                return 1;
            }
            else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
                || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
            {
                //cout << "OBSTACLE ENCOUNTERED" << endl;
                return 0;
            }
        }
        else
        {
            //cout << "INAVLID MOVE" << endl;
            return 0;
        }
    }
    else if(r_final==r_initial+1 || r_final==r_initial-1)
    {
        if(c_final == c_initial+2 || c_final == c_initial-2)
        {
            if( a[r_final][c_final]!='P' || a[r_final][c_final]!='R' || a[r_final][c_final]!='N'
                || a[r_final][c_final]!='B' || a[r_final][c_final]!='Q' || a[r_final][c_final]!='K')
            {
                swap(a[r_initial][c_initial],a[r_final][c_final]);
                a[r_initial][c_initial] = ' ';
                return 1;
            }
            else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
                || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
            {
               // cout << "OBSTACLE ENCOUNTERED" << endl;
                return 0;
            }
        }
        else
        {
            //cout << "INVALID MOVE" << endl;
            return 0;
        }
    }
    else
    {
      //  cout << "INVALID MOVE : knight does not move in this manner"<< endl;
        return 0;
    }
}



using namespace std;
int bishop2move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int temp4;
    int flag=0;
    if(r_initial<r_final &&  c_initial<c_final)
    {
        for(int i=1 ; r_final > (r_initial+i) && c_final > (c_initial+i) ; i++)
        {
            if(a[r_initial+i][c_initial+i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }
    else if(r_initial < r_final && c_initial>c_final)
    {
        for(int i=1 ; r_final > (r_initial +i) && c_final < c_initial -i; i++)
        {
            if(a[r_initial+i][c_initial-i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }
    else if(r_initial > r_final && c_initial>c_final)
    {
        for(int i=1 ; (r_final + i) < r_initial && (c_final + i) < c_initial ; i++)
        {
            if(a[r_initial-i][c_initial-i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }
    else if(r_initial > r_final && c_initial< c_final)
    {
        for(int i=1 ; (r_final + i) < r_initial && c_final > c_initial +i ; i++)
        {
            if(a[r_initial-i][c_initial+i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }

    if(flag==0)
    {
        int c1,c2,temp2;

        /*Here we know that the bishop moves diagonally so if we consider the movement of the bishop as a straight line
        y=mx+c then the slope of that line can either be 1 or -1 so now we only need the constant c which can be
        calculated as below*/

        c1 = c_initial - (1)*r_initial;
        c2 = c_initial - (-1)*r_initial;

        /*now if the final point we entered lies on the either of the two lines i.e with slope 1 or -1 then the entered
        move is valid else it is invalid*/

        if( ((c_final ==  r_final + c1) || (c_final == ((-1) * r_final) + c2 )) && a[r_final][c_final]==' ')
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        else if( ((c_final ==  r_final + c1) || (c_final == ((-1) * r_final) + c2 )) && a[r_final][c_final]!=' ' &&
                (a[r_final][c_final]!='P'&& a[r_final][c_final]!='Q'&&a[r_final][c_final]!='K'&&
                a[r_final][c_final]!='B'&& a[r_final][c_final]!='R'&&a[r_final][c_final]!='N') )
        {
            temp2=a[r_initial][c_initial];
            a[r_final][c_final]=a[r_initial][c_initial];
            a[r_initial][c_initial]=' ';
            return 1;
        }
        else
        {
        //    cout << "INVALID MOVE:Bishop does not move in this manner" << endl;
            return 0;
        }
    }
    else
    {
       // cout << "INVALID MOVE : obstacle encountered and bishop does not move in this manner" << endl;
        return 0;
    }
}

using namespace std;
int king2move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int see_move=0;
    if(a[r_initial][c_initial]=='K' && (a[r_initial][c_final]=='R') )
    {
        if((r_initial==r_final) && ((abs(c_final-c_initial))==3) && (a[r_initial][c_initial+1]==' ' && a[r_final][c_final-1]==' '))
        {
            see_move=1;
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            swap(a[r_initial][c_initial],a[r_initial][c_initial+1]);
            swap(a[r_final][c_final],a[r_final][c_final - 1]);
        }
        else if((r_initial==r_final) && ((abs(c_final-c_initial))==4) && ((a[r_initial][c_initial-1]==' ' && a[r_final][c_final+1]==' ') && a[r_initial][c_initial-2]==' '))
        {
            see_move=1;
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            swap(a[r_initial][c_initial],a[r_initial][c_initial- 1]);
            swap(a[r_initial][c_final],a[r_final][c_final + 1]);
        }
        else if(a[r_initial][c_initial]!=' ' &&  (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
            || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
        {
            cout << "OBSTACLE ENCOUNTERED" << endl;
        }
        else
        {
            cout<<"CASTLING NOT POSSIBLE"<< endl;
        }
    }
    else if(a[r_initial][c_initial]=='K')
    {
        if(abs(r_final-r_initial)==1 || abs(c_initial-c_final)==1)
        {
            if(a[r_final][c_final]==' ')
            {
                see_move=1;
                swap(a[r_initial][c_initial], a[r_final][c_final]);
            }
            else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]!='P' || a[r_final][c_final]!='R' || a[r_final][c_final]!='N'
                    || a[r_final][c_final]!='B' || a[r_final][c_final]!='Q'))
            {
                see_move=1;
                swap(a[r_initial][c_initial], a[r_final][c_final]);
                a[r_initial][c_initial]=' ';
            }
            else
            {
                see_move=2;
            }
        }
    }

    if(see_move==0)
    {
    //    cout << "INVALID MOVE" << endl;
        return 0;
    }
    else if(see_move==2)
    {
      //  cout << "OBSTACLE ENCOUNTERED" << endl;
        return 0;
    }
    else
    {
        //cout << "VALID MOVE" << endl;
        return 1;
    }
}

using namespace std;
int queen2move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int d=0, c=0, i;

    /* the following for loops checks that there are no pieces present b/w the final and initial position by constantly
    incrementing or decrementing the value of the row or column */

    if(c_initial==c_final)
    {
        if(r_initial>r_final)
        {
            for(i=(r_initial-1); i>=r_final;i--)
            {
                if(a[i][c_initial]!=' ')
                {
                    c++;
                }
            }
        }
        else
        {
            for(i=(r_initial+1);i<=r_final;i++)
            {
                if(a[i][c_initial]!=' ')
                {
                    c++;
                }
            }
        }
    }

    if(r_final==r_initial)
    {
        if(c_initial<c_final)
        {
            for(i=(c_initial+1); i<=r_final ;i++)
            {
                if(a[r_initial][i]!=' ')
                {
                    d++;
                }
            }
        }
        else
        {
            for(i=(c_initial-1); i>=c_final ;i--)
            {
                if(a[r_initial][i]!=' ')
                {
                    d++;
                }
            }
        }
    }

    int flag=0;
    if(r_initial<r_final &&  c_initial<c_final)
    {
        for(int i=1 ; r_final >= (r_initial+i) && c_final >=(c_initial+i) ; i++)
        {
            if(a[r_initial+i][c_initial+i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }
    else if(r_initial < r_final && c_initial>c_final)
    {
        for(int i=1 ; r_final >= (r_initial +i) && c_final <=c_initial -i; i++)
        {
            if(a[r_initial+i][c_initial-i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }
    else if(r_initial > r_final && c_initial>c_final)
    {
        for(int i=1 ; (r_final + i) <= r_initial && (c_final + i) <=c_initial ; i++)
        {
            if(a[r_initial-i][c_initial-i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }
    else if(r_initial > r_final && c_initial< c_final)
    {
        for(int i=1 ; (r_final + i) <= r_initial && c_final >=c_initial +i ; i++)
        {
            if(a[r_initial-i][c_initial+i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }

    if(flag==0)
    {
        int c1,c2;

        /*Here we know that the bishop moves diagonally so if we consider the movement of the bishop as a straight line y=mx+c then the slope
        of that line can either be 1 or -1 so now we only need the constant c which can be calculated as below now if the final point we entered
        lies on the either of the two lines i.e with slope 1 or -1 then the entered move is valid else it is invalid*/

        c1 = c_initial - r_initial;
        c2 = c_initial + r_initial;

        if( ((c_final ==  r_final + c1) || (c_final == ((-1) * r_final) + c2 )) && a[r_final][c_final]==' ' )
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        else if( ((r_initial==r_final && c_final != c_initial) || (c_initial==c_final && r_final != r_initial)) &&
                (a[r_final][c_final]!='P'&& a[r_final][c_final]!='Q'&&a[r_final][c_final]!='K'&&
                a[r_final][c_final]!='R'&& a[r_final][c_final]!='B'&&a[r_final][c_final]!='N'))
        {
            char temp;
            temp=a[r_initial][c_initial];
            a[r_final][c_final]=temp;
            a[r_initial][c_initial]=' ';
            return 1;
        }
        else
        {
            //cout << "INVALID MOVE : queen does not move in this manner" << endl;
            return 0;
        }
    }
    else
    {
//        cout << "INVALID MOVE : obstacle encountered and queen does not move in this manner" << endl;
        return 0;
    }
}
