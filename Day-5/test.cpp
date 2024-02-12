#include<iostream>
using namespace std;

namespace test{
    class Maths{
        public:
          Maths(){
            cout<<"Class Created"<<endl;
          }
    };
    namespace MathEquations{
        int add(int a,int b){
            return a+b;
        }
        int substract(int a,int b){
            return a-b;
        }
        int multiply(int a,int b){
            return a*b;
        }
        int divide(int a,int b){
            return a/b;
        }
    }
    inline namespace values{
        int a=5;
        int b=5;
    }
}

namespace alias=test;

using namespace test;

class AnotherMaths{
public:
    void PerformOperations(){
        while(true){
            cout<<"Select any option : "<<endl;
            cout<<"1.Addition"<<endl;
            cout<<"2.Substraction"<<endl;
            cout<<"3.Multiplication"<<endl;
            cout<<"4.Division"<<endl;
            cout<<"5.Exit"<<endl;
            int option,a,b;
            cin>>option;
            cout<<endl;
            if(option!=5){
                cout<<"Enter The First Number : ";
                cin>>a;
                cout<<"Enter The Second Number : ";
                cin>>b;
                cout<<endl;
            }
            switch (option)
            {
            case 1:
                cout<<"The Sum is "<<MathEquations::add(a,b)<<endl;
                break;
            case 2:
                cout<<"The Difference is "<<MathEquations::substract(a,b)<<endl;
                break;
            case 3:
                cout<<"The Product is "<<MathEquations::multiply(a,b)<<endl;
                break;
            case 4:
                cout<<"The Qoutient is "<<MathEquations::divide(a,b)<<endl;
                break;
            case 5:
               return;
            default:
                return;
                break;
            }
        }
    }
};

int main(){
    Maths obj;
    AnotherMaths math;
    math.PerformOperations();
    cout<<alias::a<<" "<<alias::b<<endl;
    return 0;
}