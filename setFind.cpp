#include <unordered_set>
#include <iostream>
#include <random>

#include <chrono>
#define SIZE 100

std::unordered_set<char> set;



template<typename T>
[[nodiscard]] bool existsInSet(T datum)
{
  return set.find(datum) != set.end();
}

template<typename T>
[[nodiscard]] bool existsInArray(T datum, T * arr)
{
  for (auto c : arr)
  {
    if (c == datum) return true;
  }
  return false;
}

int main()
{

  int array[SIZE];
  int lowerBound = 0;
  int upperBound = SIZE << 2; 
  std::random_device rd; 
  std::mt19937 gen(rd());

  for (int i = 0; i < SIZE; ++i)
  {
    const int num = gen();
    array[i] = num;
    set.insert(num);
  }

  // PERFORM SET SEARCH
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < SIZE << 2; ++i)
  {
    [[maybe_unused]] bool exists = existsInSet(0);
    
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "TIME FOR SET " << duration.count() << "\n";


  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < SIZE << 2; ++i)
  {
    [[maybe_unused]] bool exists = existsInSet(0);
    
  }
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "TIME FOR ARRAY " << duration.count() << "\n";
}
