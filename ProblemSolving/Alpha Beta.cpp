// C++ program to demonstrate
// working of Alpha-Beta Pruning
#include<bits/stdc++.h>
using namespace std;

// Initial values of
// Alpha and Beta
const int MAX = 1000;
const int MIN = -1000;

// Returns optimal value for
// current player(Initially called
// for root and maximizer)
int minimax(int depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta, int h)
{

	// Terminating condition. i.e
	// leaf node is reached
	if (depth == h)
		return values[nodeIndex];

	if (maximizingPlayer)
	{
		int best = MIN;

		// Recur for left and
		// right children
		for (int i = 0; i < 2; i++)
		{
			int val = minimax(depth + 1, nodeIndex * 2 + i,
							false, values, alpha, beta, h);
			best = max(best, val);
			alpha = max(alpha, best);

			// Alpha Beta Pruning
			if (beta <= alpha)
				break;
		}
		return best;
	}
	else
	{
		int best = MAX;

		// Recur for left and
		// right children
		for (int i = 0; i < 2; i++)
		{
			int val = minimax(depth + 1, nodeIndex * 2 + i,
							true, values, alpha, beta, h);
			best = min(best, val);
			beta = min(beta, best);

			// Alpha Beta Pruning
			if (beta <= alpha)
				break;
		}
		return best;
	}
}

// Driver Code
int main()
{
	int values[8] = {3, 5, 2, 9, 12, 5, 23, 23};

	int h = 0, n = 8;
	while(n>1){
        n/=2;
        h++;
	}

	cout <<"The optimal value is : "<< minimax(0, 0, true, values, MIN, MAX, h);
	return 0;
}

