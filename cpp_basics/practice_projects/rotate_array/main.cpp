#include <iostream>
#include <vector>

using namespace std;

template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{
   if(first == n_first) return last;
   if(n_first == last) return first;

   ForwardIt read      = n_first;
   ForwardIt write     = first;
   ForwardIt next_read = first; // read position for when "read" hits "last"

   while(read != last) {
      if(write == next_read) next_read = read; // track where "first" went
      std::iter_swap(write++, read++);
   }

   // rotate the remaining sequence into place
   (rotate)(write, next_read, last);
   return write;
}

int main() {
  vector<int> scale{2,2,1,2,2,2,1};
  rotate(scale.begin(), scale.begin() + 1, scale.end());

  cout << "Rotated scale by 1 step: \t" << scale << endl;
  return 0;
}
