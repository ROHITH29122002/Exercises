#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace std;

class Rectangle{
public:
  string name;
  unique_ptr<int> width;
  unique_ptr<int> height;
  unique_ptr<int> top;
  unique_ptr<int> left;
  unique_ptr<int> area;

  Rectangle(){
    cout<<"Enter The Name of The Rectangle : ";
    cin>>name;
    cout<<endl;
    width=unique_ptr<int>(new int(0));
    height=unique_ptr<int>(new int(0));
    top=unique_ptr<int>(new int(0));
    left=unique_ptr<int>(new int(0));
    area=unique_ptr<int>(new int(0));
  }

  Rectangle(string username,int w,int h){
    name=username;
    width=unique_ptr<int>(new int(w));
    height=unique_ptr<int>(new int(h));
    top=unique_ptr<int>(new int(0));
    left=unique_ptr<int>(new int(0));
    area=unique_ptr<int>(new int(0));
  }

  Rectangle(string username,int w,int h,int t,int l){
    name=username;
    width=unique_ptr<int>(new int(w));
    height=unique_ptr<int>(new int(h));
    top=unique_ptr<int>(new int(t));
    left=unique_ptr<int>(new int(l));
    area=unique_ptr<int>(new int(0));
  }

  Rectangle(string username,float w,float h,float t,float l){
    name=username;
    width=unique_ptr<int>(new int(int(w)));
    height=unique_ptr<int>(new int(int(h)));
    top=unique_ptr<int>(new int(int(t)));
    left=unique_ptr<int>(new int(int(l)));
    area=unique_ptr<int>(new int(0));
  }

  Rectangle(Rectangle& rectangle){
    name=rectangle.name;
    width=unique_ptr<int>(new int(*rectangle.width));
    height=unique_ptr<int>(new int(*rectangle.width));
    top=unique_ptr<int>(new int(*rectangle.width));
    left=unique_ptr<int>(new int(*rectangle.width));
    area=unique_ptr<int>(new int((*width)*(*height)));
    *(rectangle.area)=*area;
  }

  friend ostream& operator<<(ostream &output,Rectangle &rectangle){
    output<<"Rectangle "<<rectangle.name<<" details : "<<endl;
    output<<"Rectangle Width : "<<*(rectangle.width)<<endl;
    output<<"Rectangle Height : "<<*(rectangle.height)<<endl;
    output<<"Rectangle Top : "<<*(rectangle.top)<<endl;
    output<<"Rectangle Left : "<<*(rectangle.left)<<endl;
    output<<"Rectangle Area : "<<*(rectangle.area)<<endl;
    return output;
  }
};

void CreateRectangle(vector<unique_ptr<Rectangle> > &rectangles){
  rectangles.push_back(unique_ptr<Rectangle>(new Rectangle()));
}

void CreateRectangleWithWidthAndHeight(vector<unique_ptr<Rectangle> > &rectangles){
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
  rectangles.push_back(unique_ptr<Rectangle>(new Rectangle(name,width,height)));
}

void CreateRectangleWithAllIntValues(vector<unique_ptr<Rectangle> > &rectangles){
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
  rectangles.push_back(unique_ptr<Rectangle>(new Rectangle(name,width,height,top,left)));
}

void CreateRectangleWithAllFloatValues(vector<unique_ptr<Rectangle> > &rectangles){
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
  rectangles.push_back(unique_ptr<Rectangle>(new Rectangle(name,width,height,top,left)));
}

int Search(vector<unique_ptr<Rectangle> > &rectangles){
  string username;
  int size=rectangles.size();
  cout<<"Enter the name of the Rectangle : ";
  cin>>username;
  cout<<endl;
  int rectangleindex=-1;
  for(int i=0;i<size;i++){
    if((*rectangles[i]).name==username){
      rectangleindex=i;
      break;
    }
  }
  return rectangleindex;
}

void CalculateAndPrintArea(vector<unique_ptr<Rectangle> > &rectangles){
  int rectangleindex=Search(rectangles);
  if(rectangleindex==-1){
    cout<<"Rectangle Not Found"<<endl;
    return;
  }
  Rectangle rectangle2=*rectangles[rectangleindex];
  cout<<"The Area is : "<<*(rectangle2.area)<<endl;
}

void PrintRectangle(vector<unique_ptr<Rectangle> > &rectangles){
  int rectangleindex=Search(rectangles);
  if(rectangleindex==-1){
    cout<<"Rectangle Not Found"<<endl;
    return;
  }
  cout<<*rectangles[rectangleindex]<<endl;
}

int main(){
  vector<unique_ptr<Rectangle> > rectangles;
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