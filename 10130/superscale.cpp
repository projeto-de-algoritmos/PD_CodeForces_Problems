#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int knapsack(int N, int W, vector<pii> itens, vector<int> personMax)
{
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  int ans = 0;

  for (int i = 1; i <= N; i++)
  {
    auto [iP, iW] = itens[i];

    for (int j = 1; j <= W; j++)
    {
      if (iW <= j)
        dp[i][j] = max(dp[i - 1][j], iP + dp[i - 1][j - iW]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  // Descomente o for abaixo para visualizar a Matriz do Knapsack
  /*
  for (size_t i = 0; i <= N; i++)
  {
    for (size_t j = 0; j < W; j++)
      cout << dp[i][j] << " ";

    cout << "\n";
  }
  */

  for (const auto &max_by_person : personMax)
    ans += dp[N][max_by_person];

  return ans;
}

int main(int argc, char const *argv[])
{
  int T, N, P, W, G, maxW;

  cin >> T;

  while (T--)
  {
    vector<int> personMax;

    cin >> N;

    vector<pii> itens(N + 1, {0, 0});

    for (int i = 1; i <= N; i++)
    {
      cin >> P >> W;
      itens[i] = {P, W};
    }

    sort(itens.begin(), itens.end());

    cin >> G;

    maxW = 0;

    while (G--)
    {
      cin >> W;

      maxW = max(maxW, W);
      personMax.push_back(W);
    }

    /*
    Para poder saber o máximo que cada um consegue carregar basta rodar
    o knapsack com a maior carga que um indivíduo consegue carregar e depois
    somar as células dp[quantidade de itens][maior peso que o indivíduo carrega]
    */

    cout << knapsack(N, maxW, itens, personMax) << endl;
  }

  return 0;
}
