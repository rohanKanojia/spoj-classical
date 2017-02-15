#include <iostream>
#include <unistd.h>
#include <vector>

long long countInversions(std::vector<long long> list);
void mergeSort(std::vector<long long>& list, long long& nInversions, long long start, long long end);
void merge(std::vector<long long>& list, std::vector<long long> left, std::vector<long long> right, long long& nInversions);

int main() {
  long long T;
  std::cin >> T;
  while(T--) {
    long long N;
    std::vector<long long> list; 
    std::cin >> N;
    for(long long i = 0; i < N; i++) {
      long long tmp;
      std::cin >> tmp;
      list.push_back(tmp);
    }
    std::cout << countInversions(list) << std::endl;
  }
  return 0;
}

long long countInversions(std::vector<long long> list) {
  long long nInversions = 0;

  mergeSort(list, nInversions, 0, list.size());

  return nInversions;
}

void mergeSort(std::vector<long long>& list, long long& nInversions, long long start, long long end) {
  if(list.size() <= 1)
    return;

  long long mid =  start+(end-start)/2;
  std::vector<long long> left, right;
  left.assign(list.begin()+start, list.begin()+mid);
  right.assign(list.begin()+mid, list.begin()+end);

  mergeSort(left, nInversions, 0, mid);
  mergeSort(right, nInversions, 0, list.size()-mid);

  merge(list, left, right, nInversions);
}

void merge(std::vector<long long>& list, std::vector<long long> left, std::vector<long long> right, long long& nInversions) {
  long long i, l, r;
  l = r = i = 0;

  while(l < left.size() && r < right.size()) {
    if(left[l] > right[r]) {
      list[i] = right[r];
      i++;
      r++;
      nInversions = nInversions + (left.size()-l);
    }
    else {
      list[i] = left[l];
      l++;
      i++;
    }
  }

  while(l < left.size()) list[i++] = left[l++];
  while(r < right.size()) list[i++] = right[r++];
}
