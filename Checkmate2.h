#include<iostream>
using namespace std;

/*the idea behind checkmate is that king has no possible moves to perform in any directions, as these tiles are occupied by same player's
pieces or are covered by opponent's pieces which are on some distance or by opponent's pieces itself*/

/*there we are take another 2-D array of 3X3 of characters to denote the 8 tiles which can be accessed by the king for its movement. If any
tile is occupied by any other piece other than the king it considered a dead end which is denoted by a '-' and the available tiles are
denoted by ' ' in the moves array*/

/*after calculating all the blocked and available spaces for the king to move we decrement the possible_moves variable which is initially
assigned value 9, which is all the 8 movement direction of king and the tile occupied by the king itself*/

int check_checkmate2(char a[10][10])
{
    int possible_moves=9;
    int i,j,king_row=0,king_col=0;
    int temp_row=0,temp_col=0;
    int team=0,bound=0;
    char moves[3][3]={' ',' ',' ',
                     ' ','-',' ',
                     ' ',' ',' '};

    //getting the coordinates of the king
    for(i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='K')
            {
                king_row=i;
                king_col=j;
                break;
            }
        }

        if(king_row!=0 && king_col!=0)
            break;
    }

    //getting the coordinates of the enemy king
    for(i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='k')
            {
                temp_row=i;
                temp_col=j;
                break;
            }
        }
        if(temp_row!=0 && temp_col!=0)
            break;
    }

    for(i=king_row-1;i<=king_row+1;i++)
    {
        for(j=king_col-1;j<=king_col+1;j++)
        {
            if((i>=2 || j>=2) && (i<=9 || j<=9))      //if the position under consideration is under bounds or not is checked here.
            {
                if((a[i][j]=='P' || a[i][j]=='B' || a[i][j]=='R' || a[i][j]=='N' || a[i][j]=='Q'))
                {
                    //Here the checking of our team members is done.
                    team++;
                    moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                }
                else if(a[i][j]=='_' || a[i][j]=='|')
                {
                    //If the selected position has the coordinates less than 2 or greater than 10 then it is not in the bound of the chess board
                    //Therefore there should be reduction in the possible moves and the increment in the bound
                    bound++;
                    moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                }
                else if((i>9 || j>9)){
                    bound++;
                    moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                }
            }
        }
    }

    if(possible_moves>0)
    {
        //for rook

        for(i=king_row-1;i<=king_row+1;i++)
        {
            for(j=king_col-1;j<=king_col+1;j++)
            {
                for(int m=1;m<=8;m++)
                {
                    if(j-m>=2 && a[i][j]!='K')      //Checking for the bounds in left direction
                    {
                        if((a[i][j-m]=='r' || a[i][j-m]=='q'))
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }

                    if (i-m>=2 && a[i][j]!='K')     //Checking for the bounds in upward direction
                    {
                        if(a[i-m][j]=='r' || a[i-m][j]=='q')
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }

                    if(j+m<=10 && a[i][j]!='K')     //Checking for the bounds in right direction
                    {
                        if(a[i][j+m]=='r' || a[i][j+m]=='q')
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }

                    if(i+m<=10 && a[i][j]!='K')                     //Checking for the bounds in downward direction
                    {
                        if(a[i+m][j]=='r' || a[i+m][j]=='q')
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }
                }
            }
        }

        //for bishop

         for(i=king_row-1;i<=king_row+1;i++)
        {
            for(j=king_col-1;j<=king_col+1;j++)
            {
                for(int m=1;m<=8;m++)
                {
                    if(j-m>=2 && i-m>=2 && a[i][j]!='K')      //Checking for the bounds in left direction
                    {
                        if((a[i-m][j-m]=='b' || a[i-m][j-m]=='q'))
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }

                    if (i-m>=2 && j+m <=10 && a[i][j]!='K')     //Checking for the bounds in upward direction
                    {
                        if(a[i-m][j+m]=='b' || a[i-m][j+m]=='q')
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }

                    if(j+m<=10 && i+m<=10 && a[i][j]!='K')     //Checking for the bounds in right direction
                    {
                        if(a[i+m][j+m]=='b' || a[i+m][j+m]=='q')
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }

                    if(i+m<=10 && j-m >=2 && a[i][j]!='K')     //Checking for the bounds in downward direction
                    {
                        if(a[i+m][j-m]=='b' || a[i+m][j-m]=='q')
                        {
                            moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
                        }
                    }
                }
            }
        }

        //for knight

        for(i=king_row-1;i<=king_row+1;i++)
        {
            for(j=king_col-1;j<=king_col+1;j++)
            {
                if(a[i+2][j-1]=='n' && a[i+2][j+1]=='n' && a[i-2][j-1]=='n' && a[i+1][j+2]=='N' && a[i+1][j-2]=='n'
                    && a[i-1][j+2]=='n' && a[i-1][j-2]=='n' && i!=king_row &&j!=king_col)
                        moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
            }
        }

        //for pawn

        for(i=king_row-1;i<king_row;i++)
        {
            for(j=king_col-1;j<king_col;j++)
            {
                if((a[i+1][j-1]=='p' || a[i+1][j+1]=='p') && (i!=king_row-1 && j!=king_col))
                    moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
            }
        }

        for(i=king_row;i<king_row+1;i++)
        {
            for(j=king_col-1;j<king_col+1;j++)
            {
                if((a[i+1][j-1]=='p' || a[i+1][j+1]=='p' ) && i!=king_row &&j!=king_col)
                    moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
            }
        }

        for(i=king_row+1;i<king_row+2;i++)
        {
            for(j=king_col-1;j<king_col+1;j++)
            {
                if(a[i+1][j-1]=='p' || a[i+1][j+1]=='p')
                    moves[abs(king_row-i-1)][abs(king_col-j-1)]='-';
            }
        }

        //for king
        //getting the coordinates of the second players king
        //if the enemy king lies on the same row or column as the first king then the possible number of moves is directly reduced by
        //three else the moves are reduced by one

        if((temp_col==king_col && temp_row+2==king_row) || (temp_row==king_row && temp_col+2 == king_col)
            || (temp_col==king_col && temp_row-2==king_row) || (temp_row==king_row && temp_col-2 == king_col))
        {
            possible_moves-=3;
        }
    }
    else if(team+bound==8)
    {
        return 1;
    }
    else
    {
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(moves[i][j]=='-'){
                    possible_moves--;
                }
            }
        }
    }
    return possible_moves;
}
