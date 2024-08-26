class Knapsack
{
private:
  struct Item
  {
    int weight;
    int value;
  };
  int n;
  int W;
  Item* items;
  void printSelectedItems(int** dp);
  void printSelectedItems(bool* selectedItems);
  void knapsackBacktrackingUtil(int i, int currentWeight, int currentValue, int& maxValue, bool* bestSet, bool* currentSet);
  void knapsackBranchAndBoundUtil(int i, int currentWeight, int currentValue, int& maxValue, bool* bestSet, bool* currentSet);
public:
  Knapsack(int numItems, int maxWeight);
  ~Knapsack();
  void printItems();
  void knapsackDP();
  void knapsackBacktracking();
  void knapsackBranchAndBound();
  void knapsackBruteForce();
};