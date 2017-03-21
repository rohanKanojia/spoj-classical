#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Box { int L, B, H; };
int findMaxStackHt(vector<Box>& arr);
bool myComp(Box a, Box b) { return a.L*a.B > b.L*b.B; }

int main() {
  while(true) {
    int N;
    cin >> N;
    if(N == 0) break;
    vector<Box> arr(N);
    for(int i = 0; i < N; i++) 
      cin >> arr[i].H >> arr[i].B >> arr[i].L;

    int ans = findMaxStackHt(arr);
    cout << ans << endl;
  }
  return 0;
}

int findMaxStackHt(vector<Box>& arr) {
  vector<Box> possibleRotations;

  for(int i = 0; i < arr.size(); i++) {
    Box aBox = arr[i];
    possibleRotations.push_back(aBox);

    aBox.H = arr[i].B;
    aBox.L = std::max(arr[i].H, arr[i].L);
    aBox.B = std::min(arr[i].H, arr[i].L);
    possibleRotations.push_back(aBox);

    aBox.H = arr[i].L;
    aBox.L = std::max(arr[i].B, arr[i].H);
    aBox.B = std::min(arr[i].B, arr[i].H);
    possibleRotations.push_back(aBox);
  }

  std::sort(possibleRotations.begin(), possibleRotations.end(), myComp);

  vector<int> msh(possibleRotations.size());
  for(int i = 0; i < msh.size(); i++)
    msh[i] = possibleRotations[i].H;

  for(int i = 1; i < msh.size(); i++) {
    for(int j = 0; j < i; j++) {
      if(((possibleRotations[i].B < possibleRotations[j].B && 
          possibleRotations[i].L < possibleRotations[j].L)||
        (possibleRotations[j].L > possibleRotations[i].B &&
          possibleRotations[j].B > possibleRotations[i].L))
         && msh[i] < msh[j] + possibleRotations[i].H)
        msh[i] = msh[j] + possibleRotations[i].H;
    }
  }

  int ans = -1;
  for(int i = 0; i < msh.size(); i++)
    ans = std::max(msh[i], ans);

  return ans;
}
