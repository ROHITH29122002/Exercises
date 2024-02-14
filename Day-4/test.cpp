#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace std;

class Rectangle{
public:
  string name;
  int* width;
  int* height;
  int* top;
  int* left;
  int* area;

  Rectangle(){
    cout<<"Enter The Name of The Rectangle : ";
    cin>>name;
    cout<<endl;
    width=new int(0);
    height=new int(0);
    top=new int(0);
    left=new int(0);
    area=new int(0);
  }

  Rectangle(string username,int w,int h){
    name=username;
    width=new int(w);
    height=new int(h);
    top=new int(0);
    left=new int(0);
    area=new int(0);
  }

  Rectangle(string username,int w,int h,int t,int l){
    name=username;
    width=new int(w);
    height=new int(h);
    top=new int(t);
    left=new int(l);
    area=new int(0);
  }

  Rectangle(string username,float w,float h,float t,float l){
    name=username;
    width=new int(int(w));
    height=new int(int(h));
    top=new int(int(t));
    left=new int(int(l));
    area=new int(0);
  }

  Rectangle(Rectangle& rectangle){
    name=rectangle.name;
    width=new int(*rectangle.width);
    height=new int(*rectangle.height);
    top=new int(*rectangle.top);
    left=new int(*rectangle.left);
    area=new int((*width)*(*height));
    *(rectangle.area)=*area;
  }

  ~Rectangle(){
    delete width;
    delete height;
    delete top;
    delete left;
    delete area;
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

void CreateRectangle(vector<Rectangle*> &rectangles){
  rectangles.push_back(new Rectangle());
}

void CreateRectangleWithWidthAndHeight(vector<Rectangle*> &rectangles){
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
  rectangles.push_back(new Rectangle(name,width,height));
}

void CreateRectangleWithAllIntValues(vector<Rectangle* > &rectangles){
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
  rectangles.push_back(new Rectangle(name,width,height,top,left));
}

void CreateRectangleWithAllFloatValues(vector<Rectangle*> &rectangles){
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
  rectangles.push_back(new Rectangle(name,width,height,top,left));
}

int Search(vector<Rectangle*> &rectangles){
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

void CalculateAndPrintArea(vector<Rectangle*> &rectangles){
  int rectangleindex=Search(rectangles);
  if(rectangleindex==-1){
    cout<<"Rectangle Not Found"<<endl;
    return;
  }
  Rectangle rectangle2=*rectangles[rectangleindex];
  cout<<"The Area is : "<<*(rectangle2.area)<<endl;
}

void PrintRectangle(vector<Rectangle* > &rectangles){
  int rectangleindex=Search(rectangles);
  if(rectangleindex==-1){
    cout<<"Rectangle Not Found"<<endl;
    return;
  }
  cout<<*rectangles[rectangleindex]<<endl;
}

int main(){
  vector<Rectangle*> rectangles;
  while(true){
    // cout<<"Rectangles : "<<endl;
    int rectanglesize=rectangles.size();
    // for(int i=0;i<rectanglesize;i++){
    //   cout<<*rectangles[i]<<endl;
    // }
    cout<<"Select any option : "<<endl;
    cout<<"1.Create Rectangle"<<endl;
    cout<<"2.Create Rectangle with width and height "<<endl;
    cout<<"3.Create Rectangle with width,height,top,left"<<endl;
    cout<<"4.Create Rectangle with width,height,top,left as float"<<endl;
    cout<<"5.Calculate Area"<<endl;
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
      for(int i=0;i<rectanglesize;i++){
        delete rectangles[i];
      }
      return 0;
      break;
    default:
      break;
    }
  }
  return 0;
}