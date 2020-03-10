using namespace std;

int checkpawn2(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    //The pawn can only check the king in only two ways i.e firstly the king should be diagonally below the pawn's final position to the left
    //or to the right eg. (r_final,c_final)=(2,1) and the enemy king should be at either (3,0) or (3,2)

    if(a[r_final-1][c_final-1] =='k' || a[r_final-1][c_final+1] =='k')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


using namespace std;
int checkbishop2(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int king_row=0,king_col=0,c1,c2,flag=0;

    //Here the below loop will find the enemy king's coordinates

    for(int i=2;i<=9;i++)
    {
        for(int j=2;j<=9;j++)
        {
            if(a[i][j]=='k')
            {
                king_row=i;
                king_col=j;
                break;
            }
        }

        if(king_row!=0 && king_col!=0)
            break;
    }

    //For the below if condition consider the eg of the (r_final,c_final) = (4,2) and the king to be at (6,4)

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
int checkrook2(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int king_row=0,king_col=0,i,j;

    for(i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='k')
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
int checkknight2(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int king_row=0,king_col=0,i,j;

    //Here we are swapping the initial value with the final value
    swap(r_initial,r_final);
    swap(c_initial,c_final);

    for(int i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='k')
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
int checkqueen2(int r_initial,int c_initial,int r_final,int c_final,char a[10][10])
{
    int king_row=0,king_col=0,c1,c2,i,j;
    for(i=2;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        {
            if(a[i][j]=='k')
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
