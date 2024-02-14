#include<iostream>
using namespace std;

class Test{
private:
  int val;
public:
  Test(int i):val(i){}
  friend int operator+(Test &t1,Test &t2);
};

int operator+(Test &t1,Test &t2){
    return t1.val + t2.val;
}


int main(){
    Test t1(2);
    Test t2(3);
    cout<<t1+t2<<endl;
    return 0;
}