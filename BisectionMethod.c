#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int maxi;
    double intervalA, intervalB, mid, result;
    printf("Enter Two Interval a and b:");
    scanf("%lf %lf", &intervalA, &intervalB);
    printf("Enter Number of Max Iteration:");
    scanf("%d", &maxi);
    printf("Initial Interval: %lf %lf\n", intervalA, intervalB);
    while (maxi >= 0)
    {
        mid = ((intervalA + intervalB) / 2);
        // result = pow(mid, 3) - 4 * mid - 9;
        // result = pow(mid, 3) - 3;
        result = pow(mid, 3) - mid - 1;
        if (result < 0)
        {
            intervalA = mid;
            printf("Interval:%lf %lf\n", intervalA, intervalB);
        }
        else if (result > 0)
        {
            intervalB = mid;
            printf("Interval:%lf %lf\n", intervalA, intervalB);
        }
        --maxi;
    }

    return 0;
}