#include<iostream>
#include<vector>
#include<memory>
using namespace std;

template <typename connectiontype>
class Zoho{
private:
  vector<shared_ptr<connectiontype> > connections;
public:
  vector<shared_ptr<connectiontype>> getConnections(){
      return connections;
  }
  void AddConnection(connectiontype &connection){
    connections.push_back(make_shared<connectiontype>(connection));
  }
  int Search(string std,string number){
    int connectionindex=-1;
    int connectionsize=connections.size();
    for(int i=0;i<connectionsize;i++){
        if(std==(*connections[i]).getStd() && number==(*connections[i]).getNumber()){
            connectionindex=i;
            break;
        }
    }
    return connectionindex;
  }
  void updateAmount(string std,string number,int amount){
    int connectionindex=Search(std,number);
    if(connectionindex==-1){
        cout<<"Connection Not Found"<<endl;
        return;
    }
    (*connections[connectionindex]).updateBill(amount);
  }
  void payBills(string std,string number){
    int connectionindex=Search(std,number);
    if(connectionindex==-1){
        cout<<"Connection Not Found"<<endl;
        return;
    }
    (*connections[connectionindex]).payBill();
  }
  void PrintConnectionDetails(string std,string number){
    int connectionindex=Search(std,number);
    if(connectionindex==-1){
        cout<<"Connection Not Found"<<endl;
        return;
    }
    cout<<(*connections[connectionindex]).getStd()<<" "<<(*connections[connectionindex]).getNumber()<<" "<<(*connections[connectionindex]).getDueAmount()<<endl;
  }
};

class Mobile{
private:
  string std;
  string number;
  int due_amount;
public:
  Mobile(){
    std="";
    cout<<"Enter The mobile number : ";
    cin>>number;
    cout<<endl;
    due_amount=0;
  }
  string getStd(){
    return std;
  }
  string getNumber(){
    return number;
  }
  int getDueAmount(){
    return due_amount;
  }
  void payBill(){
    due_amount=0;
    cout<<"Bill Paid Successfully for "<<std<<" "<<number<<endl;
  }
  void updateBill(int amount){
    due_amount+=amount;
    cout<<"Due Amount is updated to : "<<amount<<endl;
  }
};

class Landline{
private:
  string std;
  string number;
  int due_amount;
public:
  Landline(){
    cout<<"Enter The Std Code : ";
    cin>>std;
    cout<<"Enter The mobile number : ";
    cin>>number;
    cout<<endl;
    due_amount=0;
  }
  string getStd(){
    return std;
  }
  string getNumber(){
    return number;
  }
  int getDueAmount(){
    return due_amount;
  }
  void payBill(){
    due_amount=0;
    cout<<"Bill Paid Successfully for "<<std<<" "<<number<<endl;
  }
  void updateBill(int amount){
    due_amount+=amount;
    cout<<"Due Amount is updated to : "<<amount<<endl;
  }
};

void AddConnection(Zoho<Mobile> &mobiles){
    Mobile m;
    mobiles.AddConnection(m);
}

void AddConnection(Zoho<Landline> &landlines){
    Landline l;
    landlines.AddConnection(l);
}

void makeBillPayment(Zoho<Mobile> &mobiles,Zoho<Landline> &landlines){
  string std="";
  string number;
  cout<<"Enter the Number : ";
  cin>>number;
  cout<<endl;
  if(number.length()<10){
      cout<<"Enter the Std Code : ";
      cin>>std;
      cout<<endl;
      landlines.payBills(std,number);
      return;
  }
  mobiles.payBills(std,number);
}

void makeUpdate(Zoho<Mobile> &mobiles,Zoho<Landline> &landlines){
  string std="";
  string number;
  int amount=0;
  cout<<"Enter the Number : ";
  cin>>number;
  cout<<endl;
  if(number.length()<10){
      cout<<"Enter the Std Code : ";
      cin>>std;
      cout<<endl;
      cout<<"Enter the Amount : ";
      cin>>amount;
      cout<<endl;
      landlines.updateAmount(std,number,amount);
      return;
  }
  cout<<"Enter the Amount : ";
  cin>>amount;
  cout<<endl;
  mobiles.updateAmount(std,number,amount);
}

void PrintDetails(Zoho<Mobile> &mobiles,Zoho<Landline> &landlines){
  string std="";
  string number;
  cout<<"Enter the Number : ";
  cin>>number;
  cout<<endl;
  if(number.length()<10){
      cout<<"Enter the Std Code : ";
      cin>>std;
      cout<<endl;
      landlines.PrintConnectionDetails(std,number);
      return;
  }
  mobiles.PrintConnectionDetails(std,number);
}

int main(){
    Zoho<Mobile> mobiles;
    Zoho<Landline> landlines;
    while(true){
        // cout<<(mobiles.getConnections()).size()<<endl;
        // cout<<(landlines.getConnections()).size()<<endl;
        cout<<"Enter Any option : "<<endl;
        cout<<"1. Add a new mobile connection"<<endl;
        cout<<"2. Add a new landline connection"<<endl;
        cout<<"3. Pay bill using the connection number"<<endl;
        cout<<"4. Update bill amount using the connection number."<<endl;
        cout<<"5. Print Details "<<endl;
        cout<<"6.Exit"<<endl;
        int option;
        cin>>option;
        switch (option)
        {
        case 1:
            AddConnection(mobiles);
            break;
        case 2:
            AddConnection(landlines);
            break;
        case 3:
            makeBillPayment(mobiles,landlines);
            break;
        case 4:
            makeUpdate(mobiles,landlines);
            break;
         case 5:
            PrintDetails(mobiles,landlines);
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
    return 0;
}