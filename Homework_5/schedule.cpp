#include <iostream>
#include <algorithm>

#define NUM_WEEKS 10
#define COMPANY_A 0
#define COMPANY_B 1

int main()
{
    // Company A's fixed rate per pound
    int r = 1;

    // Daily supply weight values for the week
    int s[NUM_WEEKS] = { 11, 9, 9, 12, 12, 12, 12, 9, 9, 11 };

    // Company B's fixed rate per week
    int c = 1;

    // Store minimum cost values
    int minCost[NUM_WEEKS] = {0};

    // Store optimal schedules
    int opt[NUM_WEEKS][NUM_WEEKS] = {{0}};

    for(int i = 1; i < NUM_WEEKS; i++)
    {
        if(i < 4)
        {
            // Compute Company A's cost for the week
            // store it as the total minimum cost for this week
            minCost[i] = minCost[i-1] + (r * s[i]);

            // Store that Company A was the best choice for this week
            for(int j = 1; j < i-1; j++)
            {
                opt[i][j] = opt[i-1][j];
            }
            opt[i][i] = COMPANY_A;
        }
        else
        {
            // Compute cost for both A and B of this week
            int costA = minCost[i-1] + (r * s[i]);
            int costB = minCost[i-4] + (4 * c);
            minCost[i] = std::min(costA,costB);

            if(costA < costB)
            {
                // Store that Company A was the best choice for this week
                for(int j = 1; j < i-1; j++)
                {
                    opt[i][j] = opt[i-1][j];
                }
                opt[i][i] = COMPANY_A;
            }
            else
            {
                // Store that Company B was the best choice for the last four weeks
                for(int j = 1; j < i-4; j++)
                {
                    opt[i][j] = opt[i-4][j];
                }

                for(int x = 3; x >= 0; x--)
                {
                    opt[i][i-x] = COMPANY_B;
                }
            }
        }
    }

    for(int i = 0; i < NUM_WEEKS; i++)
    {
        std::string choice = (opt[i][i] == COMPANY_A) ? "Company A" : "Company B";
        std::cout << "Week " << i << ": " << choice << std::endl;
    }

    return 0;
}
