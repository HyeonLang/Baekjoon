#include <iostream>
using namespace std;

int N;
string board[50];
int max_count = 0;

void checkCandy()
{
    for (int n1 = 0; n1 < N; n1++)
    {
        int count_r = 1;
        char first_r = board[n1][0];
        for (int n2 = 1; n2 < N; n2++)
        {
            if (first_r == board[n1][n2])
            {
                count_r++;
            }
            else
            {
                max_count = max(max_count, count_r);
                count_r = 1;
                first_r = board[n1][n2];
            }
        }
        max_count = max(max_count, count_r);
    }
    for (int n1 = 0; n1 < N; n1++)
    {
        int count_c = 1;
        char first_c = board[0][n1];
        for (int n2 = 1; n2 < N; n2++)
        {
            if (first_c == board[n2][n1])
            {
                count_c++;
            }
            else
            {
                max_count = max(max_count, count_c);
                count_c = 1;
                first_c = board[n2][n1];
            }
        }
        max_count = max(max_count, count_c);
    }
}

int main()
{
    cin >> N;
    for (int n = 0; n < N; n++)
    {
        cin >> board[n];
    }

    checkCandy();

    for (int n1 = 0; n1 < N; n1++)
    {
        for (int n2 = 0; n2 < N - 1; n2++)
        {
            swap(board[n1][n2], board[n1][n2 + 1]);
            checkCandy();
            swap(board[n1][n2], board[n1][n2 + 1]);

            swap(board[n2][n1], board[n2 + 1][n1]);
            checkCandy();
            swap(board[n2][n1], board[n2 + 1][n1]);
        }
    }
    cout << max_count;

}