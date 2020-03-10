using namespace std;

/*Here the main idea behind the check is that for the piece in consideration we just check if the king is lying on the path on which the
selected piece can move if the king lies on the path of the movement of the selected piece's then the function that is called returns 1 i.e.
true else the function will return false i.e. 0*/

int checkpawn1(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    //The pawn can only check the king in only two ways i.e firstly the king should be diagonally below the pawn's final position to the left
    //or to the right eg. (r_final,c_final)=(2,1) and the enemy king should be at either (3,0) or (3,2)
    //if this condition is true than the function returns true i.e. 1 else false i.e. 0

    if(a[r_final+1][c_final+1] =='K' || a[r_final+1][c_final-1] =='K')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

using namespace std;
int checkbishop1(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{

    /*Here the main logic behind the bishop's check is that first we will calculate the enemy kings coordinates after that we will check all
    the direction in which the bishop can move to see if the king lies in that direction or not. Here again there arises four possibilities
    first is that if the king would be in the top right side of the king the second is that if the king is at the top left corner of the king
    the third possibility would be that the king would be at the bottom left corner and similarly the forth would be that if the king would be
    the king being at the bottom right side of the bishop. For this we have taken four if loops each loop*/

    /*When the position of the king is determined then we see if there are any obstacles between the bishop and the king by using for loops
    if the obstacle is found then we just set the value of the variable flag to 1 else it is retained to 0 */

    /*After doing this we just check if the king is in the line of the bishop or not if the king is found then we will just return
    true else we would return false */

    int king_row=0,king_col=0,c1,c2,flag=0;

    //Here the below loop will find the enemy king's coordinates

    for(int i=2;i<=9;i++)
    {
        for(int j=2;j<=9;j++)
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

    //For the below if condition consider the example of the (r_final,c_final) = (4,2) and the king to be at (6,4)

    if(r_final<king_row &&  c_final<king_col)
    {
        for(int i=1 ; king_row > (r_final+i) && king_col >(c_final+i) ; i++)
        {
            if(a[r_final+i][c_final+i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }

    //For this else if condition consider the example of (r_final,c_final)=(4,2) and king is on (6,0)

    else if(r_final < king_row && c_final > king_col)
    {
        for(int i=1 ; king_row>(r_final+i) && king_col<(c_final-i); i++)
        {
            if(a[r_final+i][c_final-i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }

    //For this else if consider the example of(r_initial,c_initial)=(4,2) and the king coordinates to be equal to (2,0)

    else if(r_final>king_row && c_final>king_col)
    {
        for(int i=1 ; king_row < (r_final-i) && king_col < (c_final-i) ; i++)
        {
            if(a[r_final-i][c_final-i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }

    //For this else if consider the example of(r_initial,c_initial)=(4,2) and the king coordinates to be equal to (2,4)

    else if(r_final > king_row && c_final< king_col)
    {
        for(int i=1 ; king_row < (r_final-i) && king_col > (c_final+i) ; i++)
        {
            if(a[r_final-i][c_final+i] != ' ')
            {
                flag=1;
                break;
            }
        }
    }
    else
    {
        flag=1;
    }

    if(flag==0)
    {
        c1 = c_final - (1)*r_final;
        c2 = c_final - (-1)*r_final;

        if( ((king_col ==  king_row + c1) || (king_col == ((-1) * king_row) + c2 )) )
        {
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
int checkrook1(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    /*Here the logic applied is that, Firstly we will be calculating the position of the enemy king then after the second step would be to
    king lies in which direction of the rook i.e. the king can have the same column as that of the rook and also the king can have the same
    row as the king first again we see in which direction does the king lie then according to that we just track out obstacles using the
    flag variable as used previously in the bishop case then just we take see the value of the rook's flag then we just return true if the
    value of it is 1 then we return true else we return false*/

    int king_row=0,king_col=0,i,j;

    for(i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='K')
            {
                king_row=i;
                king_col=j;
            }
            if(king_row!=0 && king_col!=0)
                break;
        }
        if(king_row!=0 && king_col!=0)
                break;
    }

    int flag_rook=0;

    //For this case consider the example where (r_final,c_final)=(2,7) and the enemy king coordinates are (0,7)

    if(c_final==king_col)
    {
        j=c_final;
        if(r_final>king_row)
        {
            //Here i is set to r_final-1 due to the reason that we want to go from the r_final->king_row checking that is there any obstacle
            //on the way and if there is we set the flag_rook value to 1 indicating that we encountered an obstacle

            for(i=r_final-1; i>king_row; i--)
            {
                if(a[i][j]!=' ')
                {
                    flag_rook=1;
                    break;
                }
            }
        }

        //for checking this condition we will consider the example (r_final,c_final) = (2,7) and the king coordinates to be (4,7)

        else if(r_final<king_row)
        {
            //Here again we set the value of i to be r_final +1 since we want to check the position's that are between the rook and the
            //king if we set the coordinates to i=r_final then the position of the rook will also be checked which we don't want.

            for(i=r_final+1; i<king_row ; i++)
            {
                if(a[i][j]!=' ')
                {
                    flag_rook=1;
                    break;
                }
            }
        }
    }

    else if(r_final==king_row)
    {
        i=r_final;

        //for checking this condition we will consider the example (r_final,c_final) = (2,4) and the king coordinates to be (2,2)

        if(c_final>king_col)
        {
            for(j=c_final-1;j>king_col;j--)
            {
                if(a[i][j]!=' ')
                {
                    flag_rook=1;
                    break;
                }
            }
        }

        //for checking this condition we will consider the example (r_final,c_final) = (2,4) and the king coordinates to be (2,6)

        if(c_final<king_col)
        {
            for(j=c_final+1;j<king_col;j++)
            {
                if(a[i][j]!=' ')
                {
                    flag_rook=1;
                    break;
                }
            }
        }
    }
    else
    {
        return 0;
    }

    if(flag_rook==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

using namespace std;
int checkknight1(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    /*Here the logic behind the the movement of the knight is that we will first find the coordinates of the enemy king then we will check if
    the enemy king coordinates matches with the final coordinates of the knight if it does then we would simply return true else we would
    return false
    */
    int king_row=0,king_col=0,i,j;

    //Here we are swapping the initial value with the final value
    swap(r_initial,r_final);
    swap(c_initial,c_final);

    for(int i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='K')
            {
                king_row=i;
                king_col=j;
                break;
            }

            if(king_row!=0 && king_col!=0)
            {
                break;
            }
        }
    }

    r_final=king_row;
    c_final=king_col;

    //Here we are assigning the king row to the r_final and the king col to the c_final

    if(r_final==r_initial+2 || r_final==r_initial-2)
    {
        if(c_final == c_initial+1 || c_final == c_initial-1)
        {
            return 1;
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
int checkqueen1(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    /*Here we have just combined the logic of the bishop and the rook*/
    int king_row=0,king_col=0,c1,c2,i,j;
    for(i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='K')
            {
                king_row=i;
                king_col=j;
            }

            if(king_row!=0 && king_col!=0)
                break;
        }

        if(king_row!=0 && king_col!=0)
                break;
    }

    int flag_queen=0;

    if(r_final<king_row && c_final<king_col)
    {
        for(int i=1 ;king_row > (r_final+i) && king_col >(c_final+i) ; i++)
        {
            if(a[r_final+i][c_final+i] !=' ')
            {
                flag_queen=1;
                break;
            }
        }
    }
    else if(r_final < king_row && c_final>king_col)
    {
        for(int i=1 ; king_row > (r_final +i) && king_col < (c_final -i); i++)
        {
            if(a[r_final+i][c_final-i] !=' ')
            {
                flag_queen=1;
                break;
            }
        }
    }
    else if(r_final > king_row && c_final > king_col)
    {
        for(int i=1 ; king_row < (r_final - i) && king_col <(c_final - i) ; i++)
        {
            if(a[r_final-i][c_final-i] != ' ')
            {
                flag_queen=1;
                break;
            }
        }
    }
    else if(r_final > king_row && c_final< king_col)
    {
        for(int i=1 ; king_row < (r_final - i) && king_col > (c_final +i) ; i++)
        {
            if(a[r_final-i][c_final+i] != ' ')
            {
                flag_queen=1;
                break;
            }
        }
    }
    else
    {
        flag_queen=1;
    }

    //Here the flag_queen =1 indicates that an obstacle has been encountered
    //if the value of the variable flag_queen is 0 then it means that no obstacle has been detected and therefore we will proceed to check
    //if the king is lying on the diagonal positions of the queen

    if(flag_queen==0)
    {
        c1 = c_final - (1)*r_final;
        c2 = c_final - (-1)*r_final;

        if((king_col ==  king_row + c1) || (king_col == ((-1) * king_row) + c2 ))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // Here the check will be conducted for the positions of the rook

    flag_queen=0;
    if(c_final==king_col)
    {
        j=c_final;
        if(r_final>king_row)
        {
            for(i=r_final-1;i>king_row;i--)
            {
                if(a[i][j]!=' ')
                {
                    flag_queen=1;
                    break;
                }
            }
        }
        else if(r_final<king_row)
        {
            for(i=r_final+1;i<king_row;i++)
            {
                if(a[i][j]!=' ')
                {
                    flag_queen=1;
                    break;
                }
            }
        }
    }
    else if(r_final==king_row)
    {
        i=r_final;
        if(c_final>king_col)
        {
            for(j=c_final-1;j>king_col;j--)
            {
                if(a[i][j]!=' ')
                {
                    flag_queen=1;
                    break;
                }
            }
        }
        else if(c_final<king_col)
        {
            for(j=c_final+1;j<king_col;j++)
            {
                if(a[i][j]!=' ')
                {
                    flag_queen=1;
                    break;
                }
            }
        }
    }
    else
    {
        flag_queen=0;
    }

    if(flag_queen==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
