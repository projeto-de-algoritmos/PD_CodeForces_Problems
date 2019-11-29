
#include <bits/stdc++.h>

using namespace std;

int knapsack(int N, int W, vector<int> wt, vector<int> val)
{
    vector<vector<int>> A(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= W; j++)
        {
            if (wt[i] <= j)
                A[i][j] = max(A[i - 1][j], val[i] + A[i - 1][j - wt[i]]);
            else
                A[i][j] = A[i - 1][j];
        }

    // Descomente o for abaixo para visualizar a Matriz do Knapsack
    /*
    for (size_t i = 0; i <= N; i++)
    {
        for (size_t j = 0; j < W; j++)
            cout << A[i][j] << " ";
    
        cout << "\n";
    }
    */

    return A[N][W];
}

int main()
{

    int test, sum, n;

    cin >> test;

    while (test--)
    {
        cin >> n;

        vector<int> wt(n + 1, 0);
        sum = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> wt[i];
            sum += wt[i];
        }

        /*
        1. O Knapsack retorna a maior divisão justa de moedas que cada um pode receber
           por isso passa a metade da quantidade de moedas como limitador do 'peso'
        3. Peso e valor para esse contexto são iguais
        4. Tirando do total de moedas o dobro do resultado do Knapsack tem-se a resposta
        */
        cout << sum - 2 * knapsack(n, sum / 2, wt, wt) << endl;
    }

    return 0;
}