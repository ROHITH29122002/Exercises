#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace std;

class Rectangle{
public:
  string name;
  shared_ptr<int> width;
  shared_ptr<int> height;
  shared_ptr<int> top;
  shared_ptr<int> left;
  shared_ptr<int> area;

  Rectangle(){
    cout<<"Enter The Name of The Rectangle : ";
    cin>>name;
    cout<<endl;
    width = make_shared<int>(0);
    height = make_shared<int>(0);
    top = make_shared<int>(0);
    left = make_shared<int>(0);
    area = make_shared<int>(0);
  }

  Rectangle(string username,int w,int h){
    name=username;
    width = make_shared<int>(w);
    height = make_shared<int>(h);
    top = make_shared<int>(0);
    left = make_shared<int>(0);
    area = make_shared<int>(0);
  }

  Rectangle(string username,int w,int h,int t,int l){
    name=username;
    width = make_shared<int>(w);
    height = make_shared<int>(h);
    top = make_shared<int>(t);
    left = make_shared<int>(l);
    area = make_shared<int>(0);
  }

  Rectangle(string username,float w,float h,float t,float l){
    name=username;
    width = make_shared<int>(int(w));
    height = make_shared<int>(int(h));
    top = make_shared<int>(int(t));
    left = make_shared<int>(int(l));
    area = make_shared<int>(0);
  }

  Rectangle(const Rectangle& rectangle){
    name=rectangle.name;
    width=rectangle.width;
    height=rectangle.height;
    top=rectangle.top;
    left=rectangle.left;
    area=rectangle.area;
  }

  friend ostream& operator<<(ostream &output,Rectangle rectangle){
    output<<"Rectangle "<<rectangle.name<<" details : "<<endl;
    output<<"Rectangle Width : "<<*(rectangle.width)<<endl;
    output<<"Rectangle Height : "<<*(rectangle.height)<<endl;
    output<<"Rectangle Top : "<<*(rectangle.top)<<endl;
    output<<"Rectangle Left : "<<*(rectangle.left)<<endl;
    return output;
  }
};

void CreateRectangle(vector<Rectangle> &rectangles){
  Rectangle rectangle;
  rectangles.push_back(rectangle);
}

void CreateRectangleWithWidthAndHeight(vector<Rectangle> &rectangles){
  string name;
  int width,height;
  cout<<"Enter the name for the Rectangle : ";
  cin>>name;
  cout<<endl;
  cout<<"Enter the width of Rectangle : ";
  cin>>width;
  cout<<endl;
  cout<<"Enter the height of Rectangle : ";
  cin>>height;
  cout<<endl;
  Rectangle rectangle(name,width,height);
  rectangles.push_back(rectangle);
}

void CreateRectangleWithAllIntValues(vector<Rectangle> &rectangles){
  string name;
  int width,height,top,left;
  cout<<"Enter the name for the Rectangle : ";
  cin>>name;
  cout<<endl;
  cout<<"Enter the width of Rectangle : ";
  cin>>width;
  cout<<endl;
  cout<<"Enter the height of Rectangle : ";
  cin>>height;
  cout<<endl;
  cout<<"Enter the top of Rectangle : ";
  cin>>top;
  cout<<endl;
  cout<<"Enter the left of Rectangle : ";
  cin>>left;
  cout<<endl;
  Rectangle rectangle(name,width,height,top,left);
  rectangles.push_back(rectangle);
}

void CreateRectangleWithAllFloatValues(vector<Rectangle> &rectangles){
  string name;
  float width,height,top,left;
  cout<<"Enter the name for the Rectangle : ";
  cin>>name;
  cout<<endl;
  cout<<"Enter the width of Rectangle : ";
  cin>>width;
  cout<<endl;
  cout<<"Enter the height of Rectangle : ";
  cin>>height;
  cout<<endl;
  cout<<"Enter the top of Rectangle : ";
  cin>>top;
  cout<<endl;
  cout<<"Enter the left of Rectangle : ";
  cin>>left;
  cout<<endl;
  Rectangle rectangle(name,width,height,top,left);
  rectangles.push_back(rectangle);
}

Rectangle* Search(vector<Rectangle> &rectangles){
  string username;
  cout<<"Enter the name of the Rectangle : ";
  cin>>username;
  cout<<endl;
  Rectangle* rectangle=nullptr;
  for(Rectangle &iterrectangle : rectangles){
    if(iterrectangle.name==username){
      rectangle=&iterrectangle;
      break;
    }
  }
  return rectangle;
}

void CalculateAndPrintArea(vector<Rectangle> &rectangles){
  Rectangle* rectangle=Search(rectangles);
  if(rectangle==nullptr){
    cout<<"Rectangle Not Found"<<endl;
    return;
  }
  Rectangle rectangle2=*rectangle;
  cout<<"The Area is : "<<*(rectangle2.area)<<endl;
}

void PrintRectangle(vector<Rectangle> &rectangles){
  Rectangle* rectangle=Search(rectangles);
  if(rectangle==nullptr){
    cout<<"Rectangle Not Found"<<endl;
    return;
  }
  cout<<*rectangle<<endl;
}

int main(){
  vector<Rectangle> rectangles;
  while(true){
    cout<<"Select any option : "<<endl;
    cout<<"1.Create Rectangle"<<endl;
    cout<<"2.Create Rectangle with width and height "<<endl;
    cout<<"3.Create Rectangle with width,height,top,left"<<endl;
    cout<<"4.Create Rectangle with width,height,top,left as float"<<endl;
    cout<<"5.Print Area"<<endl;
    cout<<"6.Print Rectangle"<<endl;
    cout<<"7.Exit"<<endl;
    int option;
    cin>>option;
    switch (option)
    {
    case 1:
      CreateRectangle(rectangles);
      break;
    case 2:
      CreateRectangleWithWidthAndHeight(rectangles);
      break;
    case 3:
      CreateRectangleWithAllIntValues(rectangles);
      break;
    case 4:
      CreateRectangleWithAllFloatValues(rectangles);
      break;
    case 5:
      CalculateAndPrintArea(rectangles);
      break;
    case 6:
      PrintRectangle(rectangles);
      break;
    case 7:
      return 0;
      break;
    default:
      break;
    }
  }
  return 0;
}