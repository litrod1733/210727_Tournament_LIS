//
// Created by 이인성 on 2021/07/24.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int maxLess_than_N(vector<int> v, int N) {
  int max=0;
  int index;
  int size = v.size();
  for(int i=0; i<size; i++) {
    if(v[i] < N)
      if(max < v[i]) {
        max = v[i];
        index = i;
      }
  }
  return index;
}

int minTournament(vector<int> tnmt) {
  int sum = 0;
  int index1;
  int index2;
  int size = tnmt.size();
  int max = size;
  vector<int>::iterator iter = tnmt.begin();
  for(int j=0; j<size-1; j++) {
    int size1 = tnmt.size();
    for(int i=0; i<size1; i++) {
      index1 = maxLess_than_N(tnmt, max-i+1);
      index2 = maxLess_than_N(tnmt, max-i);
      if (index1 - index2 == 1 || index2 - index1 == 1) {
        *iter += tnmt[index1];
        sum += tnmt[index1] - tnmt[index2];
        tnmt.erase(iter);
        break;
      }
    }
  }
  return sum;
}

int main() {
  vector<int> tournament;
  vector<int> member_index;
  int N;
  int result;
  cin >> N;
  tournament.resize(N);
//  입력된 순서대로 벡터에 저장
  for(int i=0; i<N; i++) {
    scanf("%d", &tournament[i]);
  }
//  벡터의 저장된 멤버의 인덱스 값 저장
//  for(int i=0; i<N; i++) {
//    member_index[tournament[i]-1] = i;
//  }
  result = minTournament(tournament);
  cout << result << endl;
  return 0;
}