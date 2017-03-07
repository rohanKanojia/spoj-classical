#include <cstdio>
#include <vector>

long long reverseBits(long long N) {
  long long ans = 0;
  std::vector<bool> prevBitSet;
  while(N) {
    bool curVal = ((N>>1)&1);
    prevBitSet.push_back(curVal);
    N >>= 1;
  }
  
  long long i = prevBitSet.size()-1, j = 0;
  while(prevBitSet[i] == false)
    i--;
  for(; i >= 0; i--) {
    if(prevBitSet[i]) 
      ans |= (1 << j);
    j++;
  }
  return ans;
}


int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    if((N&1) == 0) {
      N = reverseBits(N);
    }

    printf("%lld\n", N);
  }
  return 0;
}
