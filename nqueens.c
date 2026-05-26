#include<stdio.h>
#include<stdlib.h>

int x[10], n;

/* check if queen can be placed */
int safe(int row, int col)
{
    int i;

    for(i=1; i<row; i++)
    {
        if(x[i]==col || abs(x[i]-col)==abs(i-row))
            return 0;
    }

    return 1;
}

/* place queens */
void queen(int row)
{
    int col, i;

    for(col=1; col<=n; col++)
    {
        if(safe(row,col))
        {
            x[row]=col;

            if(row==n)
            {
                printf("\nSolution:\n");

                for(i=1;i<=n;i++)
                    printf("Queen %d -> Column %d\n",i,x[i]);
            }
            else
                queen(row+1);
        }
    }
}

int main()
{
    printf("Enter N: ");
    scanf("%d",&n);

    queen(1);

    return 0;
}