#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class Loans{
public:
  virtual void getAvailableLoans()=0;
  virtual float getIntrest()=0;
};

class Bank{
public:
   virtual string getName()=0;
   virtual string getEstablishedDate()=0;
   virtual string getBankType()=0;
   virtual string getBranchName()=0;
};

class Banks:public Bank,public Loans{
private:
  string Name;
  string EstablishedDate;
  string BankType;
  string BranchName;
  int TotAvailableLoans;
  float intrest;
public:
  Banks(){
    cout<<"Enter The Bank Name : ";
    cin>>Name;
    cout<<endl;
    cout<<"Enter The Bank Established Date : ";
    cin>>EstablishedDate;
    cout<<endl;
    cout<<"Enter The Bank Type : ";
    cin>>BankType;
    cout<<endl;
    cout<<"Enter The Bank Branch Name : ";
    cin>>BranchName;
    cout<<endl;
    cout<<"Enter The Bank Total Loans : ";
    cin>>TotAvailableLoans;
    cout<<endl;
    cout<<"Enter The Loan Intrest Rate : ";
    cin>>intrest;
    cout<<endl;
  }
  string getName(){
  return Name;
  }
  string getEstablishedDate(){
  return EstablishedDate;
  }
  string getBankType(){
  return BankType;
  }
  string getBranchName(){
  return BranchName;
  }
  void getAvailableLoans(){
    cout<<"There are "<<TotAvailableLoans<<" available"<<endl;
  }
  float getIntrest(){
  return intrest;
  }
  friend ostream& operator<<(ostream& output,Banks &bank){
  output<<"Bank : "<<bank.getName()<<endl;
  output<<"Established Date : "<<bank.getEstablishedDate()<<endl;
  output<<"Bank Type : "<<bank.getBankType()<<endl;
  output<<"Loan Intrest Rate : "<<bank.getIntrest()<<endl;
  return output;
  }
  friend bool operator<(Banks &bank1,Banks &bank2){
    if(bank1.getIntrest()<bank2.getIntrest()){
      return true;
    }
    return false;
  }
};

int Search(string name,vector<shared_ptr<Banks> > &banks){
  int size=banks.size();
  int bankindex=-1;
  for(int i=0;i<size;i++){
    if(banks[i]->getName()==name){
      bankindex=i;
      break;
    }
  }
  return bankindex;
}

void DisplayBankWithLowestIntrestRate(vector<shared_ptr<Banks> > &banks){
  int index=0;
  float min_intrest=(*banks[0]).getIntrest();
  int size=banks.size();
  for(int i=0;i<size;i++){
    if((*banks[i]).getIntrest()<min_intrest){
      min_intrest=(*banks[i]).getIntrest();
      index=i;
    }
  }
  cout<<(*banks[index]).getName()<<" has Lowest Intrest Rate as "<<(*banks[index]).getIntrest()<<endl;
}

class Broker{
public:
  void CompareTwoBanks(vector<shared_ptr<Banks> > &banks){
    string bankname1,bankname2;
    cout<<"Enter Bank 1 Name : ";
    cin>>bankname1;
    cout<<endl;
    int bank1index=Search(bankname1,banks);
    if(bank1index==-1){
      cout<<"Bank Not Found"<<endl;
      return;
    }
    cout<<"Enter Bank 2 Name : ";
    cin>>bankname2;
    cout<<endl;
    int bank2index=Search(bankname2,banks);
    if(bank2index==-1){
      cout<<"Bank Not Found"<<endl;
      return;
    }
    if(*banks[bank1index]<*banks[bank2index]){
      cout<<(*banks[bank1index]).getName()<<" has lower intrest rate"<<endl;
    }
    else{
      cout<<(*banks[bank2index]).getName()<<" has lower intrest rate"<<endl;
    }
  }

  void CompareThreeBanks(vector<shared_ptr<Banks> > &banks){
    string bankname1,bankname2,bankname3;
    cout<<"Enter Bank 1 Name : ";
    cin>>bankname1;
    cout<<endl;
    cout<<"Enter Bank 2 Name : ";
    cin>>bankname2;
    cout<<endl;
    cout<<"Enter Bank 3 Name : ";
    cin>>bankname3;
    cout<<endl;
    int bank1index=Search(bankname1,banks);
    if(bank1index==-1){
      cout<<"Bank Not Found"<<endl;
      return;
    }
    int bank2index=Search(bankname2,banks);
    if(bank2index==-1){
      cout<<"Bank Not Found"<<endl;
      return;
    }
    int bank3index=Search(bankname3,banks);
    if(bank3index==-1){
      cout<<"Bank Not Found"<<endl;
      return;
    }
    if((*banks[bank1index])<(*banks[bank2index]) && (*banks[bank1index])<(*banks[bank3index])){
      cout<<(*banks[bank1index]).getName()<<" has lowest intrest rate."<<endl;
    }
    else if((*banks[bank2index])<(*banks[bank1index]) && (*banks[bank2index])<(*banks[bank3index])){
      cout<<(*banks[bank2index]).getName()<<" has lowest intrest rate."<<endl;
    }
    else{
      cout<<(*banks[bank3index]).getName()<<" has lowest intrest rate."<<endl;
    }
  }

  void CompareNBanks(vector<shared_ptr<Banks> > &banks){
    int n;
    cout<<"Enter the number of Banks for comparision : ";
    cin>>n;
    cout<<endl;
    vector<shared_ptr<Banks> > userbanks;
    for(int i=0;i<n;i++){
      string bankname;
      cout<<"Enter Bank "<<i+1<<" Name : ";
      cin>>bankname;
      cout<<endl;
      int bankindex=Search(bankname,banks);
      if(bankindex==-1){
        cout<<"Bank Not Found"<<endl;
        return;
      }
      userbanks.push_back(banks[bankindex]);
    }
    DisplayBankWithLowestIntrestRate(userbanks);
  }
};

string Convert(string s){
  transform(s.begin(),s.end(),s.begin(),::tolower);
  return s;
}


void CreateBank(vector<shared_ptr<Banks> > &banks){
  banks.push_back(shared_ptr<Banks>(new Banks()));
}

void PrintOneBank(vector<shared_ptr<Banks> > &banks){
  string bankname;
  cout<<"Enter The Bank Name : ";
  cin>>bankname;
  cout<<endl;
  int bankindex=Search(bankname,banks);
  if(bankindex==-1){
    cout<<"Bank Not Found"<<endl;
    return;
  }
  cout<<*banks[bankindex]<<endl;
}

void PrintMultipleBanks(vector<shared_ptr<Banks> > &banks){
  int n;
  cout<<"Enter the number of Banks : ";
  cin>>n;
  cout<<endl;
  vector<int> userbanks;
  for(int i=0;i<n;i++){
    string bankname;
    cout<<"Enter Bank "<<i+1<<" Name : ";
    cin>>bankname;
    cout<<endl;
    int bankindex=Search(bankname,banks);
    if(bankindex==-1){
      cout<<"Bank Not Found"<<endl;
      return;
    }
    userbanks.push_back(bankindex);
  }
  int sizeOfUserBanks=userbanks.size();
  for(int i=0;i<sizeOfUserBanks;i++){
    cout<<*banks[userbanks[i]]<<endl;
  }
}


int main(){
  Broker broker;
  vector<shared_ptr<Banks> > banks;
  while(true){
    cout<<"Select Any Operation : "<<endl;
    cout<<"1.Add Bank"<<endl;
    cout<<"2.Print One Bank Info"<<endl;
    cout<<"3.Display Bank with Lowest Intrest Rate"<<endl;
    cout<<"4.Compare Two Banks Loan Intrest Rates"<<endl;
    cout<<"5.Compare Three Banks Loan Intrest Rates"<<endl;
    cout<<"6.Compare n Banks Loans Intrest Rates"<<endl;
    cout<<"7.Print Multiple Banks Info"<<endl;
    cout<<"8.Exit"<<endl;
    int option;
    cin>>option;
    switch (option)
    {
    case 1:
      CreateBank(banks);
      break;
    case 2:
      PrintOneBank(banks);
      break;
    case 3:
      DisplayBankWithLowestIntrestRate(banks);
      break;
    case 4:
      broker.CompareTwoBanks(banks);
      break;
    case 5:
      broker.CompareThreeBanks(banks);
      break;
    case 6:
      broker.CompareNBanks(banks);
      break;
    case 7:
      PrintMultipleBanks(banks);
      break;
    case 8:
      return 0;
      break;
    default:
      break;
    }
  }
  return 0;
}