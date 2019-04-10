#include <iostream>
#include <stdio.h>
#include <list>
#include <iterator>
#include <tuple>
#include <vector>
#include <map>
#include <climits>
#include <fstream>
#include <cmath>

#include "Json.h"

using namespace std;


int main(){

  Object obj;
  Array a;
  a.arr.push_back(new Real(12.6));
    a.arr.push_back(new Real(1.6));
      a.arr.push_back(new Real(2.6));
  obj.obj["a"] = new Integer(10);
  obj.obj["b"] = new String("str");
  obj.obj["c"] = new Real(1.02);
  obj.obj["d"] = &a;
  cout << obj << endl;

  return 0;
}
