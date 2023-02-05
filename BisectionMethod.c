#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) pow(x, 3) - 4 * x - 9 // Write Your Function Definition Here
int main()
{
    int step = 1;
    double intervalA, intervalB, mid, result, error, func1, func2;
start:
    printf("\nEnter Two Interval a and b:");
    scanf("%lf %lf", &intervalA, &intervalB); // Enter Your Interval Here
    printf("\nEnter Tolrable Error:");
    scanf("%lf", &error); // Enter Your Correction of Decimal Point
    func1 = f(intervalA);
    func2 = f(intervalB);
    if (func1 * func2 > 0.0)
    {
        printf("\nIncorrect Initial Interval");
        goto start;
    }
    else
    {
        printf("\nInitial Interval: %lf %lf\n", intervalA, intervalB);
        do
        {
            mid = ((intervalA + intervalB) / 2);
            result = f(mid);
            if (result < 0)
            {
                intervalA = mid;
                printf("\n(%d) Interval : %lf\t%lf\n", step, intervalA, intervalB);
            }
            else if (result > 0)
            {
                intervalB = mid;
                printf("\n(%d) Interval : %lf\t%lf\n", step, intervalA, intervalB);
            }
            step++;
        } while (fabs(result) > error);
        printf("\nRoot:%lf", mid);
    }

    return 0;
}