#include <iostream>
#include <list>

using namespace std;
int main(){
  list<int> l;
  l.push_back(11);

  auto it = l.begin();
  for(it != l.end()){
    cout<<*it<<endl;
    it++;
  }
  return 0;
}
//g++ a.cpp -std=c++11 编译使用c++11编译
