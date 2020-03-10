#include<math.h>
using namespace std;
int pawn1move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    if(r_initial==3)    //Here internally we are adding 2 to the coordinates therefore this line means r_initial==1
    {
        if(r_final==r_initial+1 && a[r_initial+1][c_initial]==' ' && c_final==c_initial)
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }

        //The below line of code takes care of the two step movement of the pawn at the starting of the game

        else if(r_final==r_initial+2 && a[r_initial+1][c_initial]==' ' && c_final==c_initial && a[r_initial+2][c_initial]==' ' )
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        else if(r_final==r_initial+1 && (c_final==c_initial+1 || c_final==c_initial-1) && a[r_final][c_final]!='p'&& a[r_final][c_final]!='q'&&a[r_final][c_final]!='k'&&
                a[r_final][c_final]!='b'&& a[r_final][c_final]!='r'&&a[r_final][c_final]!='n' && a[r_final][c_final]!=' ')
        {
            char tempt;
            tempt=a[r_initial][c_initial];
            a[r_final][c_final]=tempt;
            a[r_initial][c_initial]=' ';
            return 1;
        }
        else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
            || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
        {
            cout << "ERROR !!!" << endl;
            return 0;
        }
        else
        {
            cout << "ERROR !!!" << endl;
            return 0;
        }
    }
    else
    {
        if(r_final==r_initial+1 && (c_final==c_initial+1 || c_final==c_initial-1) && a[r_final][c_final]!='p' && a[r_final][c_final]!='q'
           && a[r_final][c_final]!='k' && a[r_final][c_final]!='b' && a[r_final][c_final]!='r' && a[r_final][c_final]!='n' && a[r_final][c_final]!=' ')
        {
            char temp;
            temp=a[r_initial][c_initial];
            a[r_final][c_final]=temp;
            a[r_initial][c_initial]=' ';
            return 1;
        }
        else if(r_final==r_initial+1 && a[r_initial+1][c_initial]==' ' && c_final==c_initial)
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        else if(a[r_final][c_final]!=' ')
        {
            cout << "ERROR !!!" << endl;
            return 0;
        }
        else
        {
            cout << "ERROR !!!" << endl;
            return 0;
        }
    }
}

using namespace std;
int rook1move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int i,temp1,c=0;

    /*the following for loops checks that there are no pieces present b/w the final and initial position by constantly
    incrementing or decrementing the value of the row or column*/

    if(c_final == c_initial)
    {

        /*this 2 for loops takes the care of obstacle clearance in vertical direction*/
        if(r_final>r_initial)
        {
            for(i=r_initial+1 ; i<r_final ; i++)                      // for loop to check vertically downwards movement
            {
                if(a[i][c_initial]!=' ')
                {
                    c=1;
                }
            }
        }
        else if(r_final<r_initial)
        {
            for(i=r_initial-1 ; i>r_final ; i--)			  //for loops to check vertically upwards movement
            {
                if(a[i][c_initial]!=' ')
                {
                    c=1;
                }
            }
        }
    }

    else if(r_final == r_initial)
    {
        if(c_final>c_initial)
        {
            for(i=c_initial+1 ; i<c_final ; i++)			 //for loops to check movement toward right-side
            {
                if(a[r_initial][i]!=' ')
                {
                    c=1;
                }
            }
        }
        else if(c_final<c_initial)
        {
            for(i=c_initial-1 ; i>c_final ; i--)			//for loops to check movement towards left-side
            {
                if(a[r_initial][i]!=' ')
                {
                    c=1;
                }
            }
        }
    }

    /*the logic for checking the movement of rook is that if the co-ordinates lie in a vertical or horizontal straight
    line then the earlier declared variables rook_r and rook_c  on addition/subtraction with the initial co-ordinates will
    be equal to the final co-ordinates entered*/

    if(c==0)
    {
        if( ((r_initial==r_final && c_final != c_initial) || (c_initial==c_final && r_final != r_initial)) && a[r_final][c_final]==' ')
        {
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            return 1;
        }
        if( ((r_initial==r_final && c_final != c_initial) || (c_initial==c_final && r_final != r_initial)) &&
                a[r_final][c_final]!=' ' && (a[r_final][c_final]!='p'&& a[r_final][c_final]!='q'&&a[r_final][c_final]!='k'&&
                a[r_final][c_final]!='r'&& a[r_final][c_final]!='b'&&a[r_final][c_final]!='n'))
        {
            temp1=a[r_initial][c_initial];
            a[r_final][c_final]=a[r_initial][c_initial];
            a[r_initial][c_initial]=' ';
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {

        return 0;
    }
}


using namespace std;
int knight1move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    if(r_final==r_initial+2)
    {
        if(c_final == c_initial+1 || c_final == c_initial-1)
        {
            if(a[r_final][c_final]!='p' || a[r_final][c_final]!='r' || a[r_final][c_final]!='n' || a[r_final][c_final]!='b' || a[r_final][c_final]!='q' || a[r_final][c_final]!='k')
            {
                swap(a[r_initial][c_initial],a[r_final][c_final]);
                a[r_initial][c_initial] = ' ';
                return 1;
            }
            else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n' || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' ||
                    a[r_final][c_final]=='k'))
            {
                return 0;
            }
            else
            {

                return 0;
            }
        }
        else
        {

            return 0;
        }
    }
    else if(r_final==r_initial+1 || r_final==r_initial-1)
    {
        if(c_final == c_initial+2 || c_final == c_initial-2)
        {
            if(a[r_final][c_final]!='p' && a[r_final][c_final]!='r' && a[r_final][c_final]!='n'
                && a[r_final][c_final]!='b' && a[r_final][c_final]!='q' && a[r_final][c_final]!='k')
            {
                swap(a[r_initial][c_initial],a[r_final][c_final]);
                a[r_initial][c_initial] = ' ';
                return 1;
            }
            else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
            || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
            {

                return 0;
            }
        }
        else
        {

            return 0;
        }
    }
    else if(r_final==r_initial-2)
    {
        if(c_final == c_initial+1 || c_final == c_initial-1)
        {
            if(a[r_final][c_final]!='p' && a[r_final][c_final]!='r' && a[r_final][c_final]!='n'
                && a[r_final][c_final]!='b' && a[r_final][c_final]!='q' && a[r_final][c_final]!='k')
            {
                swap(a[r_initial][c_initial],a[r_final][c_final]);
                a[r_initial][c_initial] = ' ';
                return 1;
            }
            else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
            || a[r_final][c_final]=='b' || a[r_final][c_final]=='q' || a[r_final][c_final]=='k'))
            {
                return 0;
            }
        }
        else
        {

            return 0;
        }
    }
    else
    {

        return 0;
    }
}

using namespace std;
int bishop1move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int flag=0;
    if(r_initial<r_final &&  c_initial<c_final)
    {
        for(int i=1 ; r_final > (r_initial+i) && c_final >(c_initial+i) ; i++)
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
        for(int i=1 ; (r_final + i) < r_initial && (c_final + i) <c_initial ; i++)
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
                (a[r_final][c_final]!='p'&& a[r_final][c_final]!='q'&&a[r_final][c_final]!='k'&&
                a[r_final][c_final]!='b'&& a[r_final][c_final]!='r'&&a[r_final][c_final]!='n') )
        {
            temp2=a[r_initial][c_initial];
            a[r_final][c_final]=a[r_initial][c_initial];
            a[r_initial][c_initial]=' ';
            return 1;
        }
        else
        {

            return 0;
        }
    }
    else
    {

        return 0;
    }
}

using namespace std;
int king1move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int see_move=0;
    if(a[r_initial][c_initial]=='k' && a[r_initial][c_final]=='r')
    {
        if((r_initial==r_final) && ((abs(c_final-c_initial))==3) && (a[r_initial][c_initial+1]==' ' && a[r_final][c_final-1]==' '))
        {
            see_move=1;
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            swap(a[r_initial][c_initial],a[r_initial][c_initial+ 1]);
            swap(a[r_final][c_final],a[r_final][c_final - 1]);
        }
        else if((r_initial==r_final) && ((abs(c_final-c_initial))==4) && ((a[r_initial][c_initial-1]==' ' &&
                a[r_final][c_final+1]==' ') && a[r_initial][c_initial-2]==' '))
        {
            see_move=1;
            swap(a[r_initial][c_initial],a[r_final][c_final]);
            swap(a[r_initial][c_initial],a[r_initial][c_initial-1]);
            swap(a[r_final][c_final],a[r_final][c_final + 1]);
        }
        else if((a[r_final][c_final]=='p' || a[r_final][c_final]=='r' || a[r_final][c_final]=='n'
        || a[r_final][c_final]=='b' || a[r_final][c_final]=='q'))
        {
            cout << "OBSTACLE ENCOUNTERED" << endl;
        }
        else
        {
            cout<<"CASTLING NOT POSSIBLE"<< endl;
        }
    }
    else if(a[r_initial][c_initial]=='k')
    {
        if(abs(r_final-r_initial)==1 || abs(c_initial-c_final)==1)
        {
            if(a[r_final][c_final]==' ')
            {
                see_move=1;
                swap(a[r_initial][c_initial], a[r_final][c_final]);
            }
            else if(a[r_final][c_final]!=' ' && (a[r_final][c_final]!='p' || a[r_final][c_final]!='r' || a[r_final][c_final]!='n'
                    || a[r_final][c_final]!='b' || a[r_final][c_final]!='q'))
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
        return 0;
    }
    else if(see_move==2)
    {
        return 0;
    }
    else
    {
        //cout << "VALID MOVE" << endl;
        return 1;
    }

}


using namespace std;
int queen1move(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
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
                    (a[r_final][c_final]!='p'&& a[r_final][c_final]!='q'&&a[r_final][c_final]!='k'&&
                    a[r_final][c_final]!='r'&& a[r_final][c_final]!='b'&&a[r_final][c_final]!='n'))
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
        //cout << "INVALID MOVE : obstacle encountered and queen does not move in this manner" << endl;
        return 0;
    }
}
