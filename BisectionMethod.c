#include <stdio.h>  //This Library Cintains Definition of printf(),scanf(),
#include <math.h>   //To use Mathematical Function like cos,sin in f(x),
#include <stdlib.h> //To Use fabs function;

#define f(x) (pow(x, 3) - (4 * x) - 9) //! Write Your Function Definition Here

int main()
{
    int count = 1;
    double intervalA, intervalB, mid, result, error, func1 = 0, func2 = 1, i = 0;

    do
    {
        func1 = f(i);
        func2 = f(i + 1);
        intervalA = i;
        intervalB = i + 1;
        i++;
    } while (func1 * func2 > 0.0);

    printf("\nInitial Interval: [ %lf , %lf ]\n", intervalA, intervalB);

err:
    printf("\nEnter Tolrable Error:");
    scanf("%lf", &error); // To Get The Upto How Many Places Correction

    if (error < 0.0)
    {
        printf("\nPlease Enter Valid Tolrable Error.");
        goto err;
    }
    else
    {
        do
        {
            mid = ((intervalA + intervalB) / 2);
            result = f(mid);
            if (result < 0)
            {
                intervalA = mid;
                printf("\n(%d) Interval : [ %lf , %lf ]\n", count, intervalA, intervalB);
            }
            else if (result > 0)
            {
                intervalB = mid;
                printf("\n(%d) Interval : [ %lf , %lf ]\n", count, intervalA, intervalB);
            }
            count++;
        } while (fabs(result) > error);
    }

    printf("\nRoot:%lf\n", mid);

    return 0;
}