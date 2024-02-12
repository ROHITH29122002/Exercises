#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Vehicle{
private:
    string VehicleType;
    string brand;
    string model;
    string color;
    int mileage;
    float price;
public:
   Vehicle(){
      cout<<"Enter The Vehicle Type (Petrol/Diesel) : ";
      cin>>VehicleType;
      cout<<endl;
      cout<<"Enter The Vehicle Brand : ";
      cin>>brand;
      cout<<endl;
      cout<<"Enter The Vehicle Model : ";
      cin>>model;
      cout<<endl;
      cout<<"Enter The Vehicle Color : ";
      cin>>color;
      cout<<endl;
      cout<<"Enter The Vehicle Mileage : ";
      cin>>mileage;
      cout<<endl;
      cout<<"Enter The Vehicle Price : ";
      cin>>price;
      cout<<endl;
   }
   string getVehicleType(){
     return VehicleType;
   }
   string getBrand(){
    return brand;
   }
   string getModel(){
    return model;
   }
   string getColor(){
    return color;
   }
   int getmileage(){
    return mileage;
   }
   float getPrice(){
    return price;
   }
   virtual void getNoOfWheels(){};
   friend ostream &operator<<( ostream &output, Vehicle &vehicle ) { 
         output << "Type : " << vehicle.VehicleType<<endl;
         output << "Brand : " << vehicle.brand<<endl;
         output << "Model : " << vehicle.model<<endl;
         output << "Color : " << vehicle.color<<endl;
         output << "Mileage : " << vehicle.mileage<<endl;
         output << "Price : " << vehicle.price<<endl;
         return output;            
   }
   friend bool operator<(Vehicle &vehicle1,Vehicle &vehicle2){
    if(vehicle1.getPrice() < vehicle2.getPrice()){
        return true;
    }
    return false;
   }
};

class Car : public Vehicle{
private:
   int noOfPersons;
   string carType;
public:
   Car(){
      cout<<"Enter Number of Persons : ";
      cin>>noOfPersons;
      cout<<endl;
      cout<<"Enter Car Type (Sedan,Suv,OffRoader): ";
      cin>>carType;
      cout<<endl;
   }
   int getNoOfPersons(){
    return noOfPersons;
   }
   string getCarType(){
    return carType;
   }
   void Print(){
    cout<<"No of Persons : "<<noOfPersons<<endl;
    cout<<"Car Type : "<<carType<<endl;
   }
   void getNoOfWheels(){
    cout<<" has 4 wheels"<<endl;
   }
};

class Bike : public Vehicle{
private:
   int weight;
   string bikeType;
public:
   Bike(){
      cout<<"Enter Weight : ";
      cin>>weight;
      cout<<endl;
      cout<<"Enter Bike Type (Scooter/Motorbike): ";
      cin>>bikeType;
      cout<<endl;
   }
   int getWeight(){
    return weight;
   }
   string getbikeType(){
    return bikeType;
   }
   void Print(){
    cout<<"Weight : "<<weight<<endl;
    cout<<"Bike Type : "<<bikeType<<endl;
   }
   void getNoOfWheels(){
    cout<<" has 2 wheels"<<endl;
   }
};

string Convert(string s){
   transform(s.begin(),s.end(),s.begin(),::tolower);
   return s;
}

int Search(string brandname,string modelname,vector<unique_ptr<Vehicle> > &vehicles){
   int size=vehicles.size();
   int found=-1;
   for(int i=0;i<size;i++){
      if(Convert(vehicles[i]->getBrand())==Convert(brandname) && Convert(vehicles[i]->getModel())==Convert(modelname)){
         found=i;
         break;
      }
   }
   return found;
}

void PrintVehicle(vector<unique_ptr<Vehicle> > &vehicles){
   string brandname,modelname;
   cout<<"Enter The Brand Name : ";
   cin>>brandname;
   cout<<endl;
   cout<<"Enter The Model : ";
   cin>>modelname;
   cout<<endl;
   int vehicleindex=Search(brandname,modelname,vehicles);
   if(vehicleindex==-1){
      cout<<"Vehicle Not Found"<<endl;
   }
   cout<<*vehicles[vehicleindex]<<endl;
}

void Compare(vector<unique_ptr<Vehicle> > &vehicles){
   string brandname1,brandname2,modelname1,modelname2;
   cout<<"Vehicle 1 Details : "<<endl;
   cout<<"Enter The Brand Name : ";
   cin>>brandname1;
   cout<<endl;
   cout<<"Enter The Model : ";
   cin>>modelname1;
   cout<<endl;
   cout<<"Vehicle 2 Details : "<<endl;
   cout<<"Enter The Brand Name : ";
   cin>>brandname2;
   cout<<endl;
   cout<<"Enter The Model : ";
   cin>>modelname2;
   cout<<endl;
   int vehicle1index=Search(brandname1,modelname1,vehicles);
   if(vehicle1index==-1){
      cout<<"Vehicle 1 Not Found"<<endl;
      return;
   }
   int vehicle2index=Search(brandname2,modelname2,vehicles);
   if(vehicle2index==-1){
      cout<<"Vehicle 2 Not Found"<<endl;
      return;
   }
   if(*vehicles[vehicle1index]<*vehicles[vehicle2index]){
      cout<<(*vehicles[vehicle1index]).getBrand()<<" "<<(*vehicles[vehicle1index]).getModel()<<" is Cheaper"<<endl;
   }
   else{
      cout<<(*vehicles[vehicle2index]).getBrand()<<" "<<(*vehicles[vehicle2index]).getModel()<<" is Cheaper"<<endl;
   }
}

void PrintNoofWheels(vector<unique_ptr<Vehicle> > &vehicles){
   string brandname,modelname;
   cout<<"Enter The Brand Name : ";
   cin>>brandname;
   cout<<endl;
   cout<<"Enter The Model : ";
   cin>>modelname;
   cout<<endl;
   int vehicleindex=Search(brandname,modelname,vehicles);
   if(vehicleindex==-1){
      cout<<"Vehicle Not vehicle"<<endl;
   }
   cout<<(*vehicles[vehicleindex]).getBrand()<<" "<<(*vehicles[vehicleindex]).getModel()<<" ";
   (*vehicles[vehicleindex]).getNoOfWheels();
}

int main(){
   vector<unique_ptr<Vehicle> > vehicles;
   while(true){
      cout<<endl;
      cout<<"Select Any of the Following Operations : "<<endl;
      cout<<"1.Add Car"<<endl;
      cout<<"2.Add Bike"<<endl;
      cout<<"3.Print Information"<<endl;
      cout<<"4.Compare Two Vehicles"<<endl;
      cout<<"5.Print No of Wheels"<<endl;
      cout<<"6.Exit"<<endl;
      int option;
      cin>>option;
      switch (option)
      {
      case 1:
         vehicles.push_back(unique_ptr<Vehicle>(new Car()));
         break;
      case 2:
         vehicles.push_back(unique_ptr<Vehicle>(new Bike()));
         break;
      case 3:
         PrintVehicle(vehicles);
         break;
      case 4:
         Compare(vehicles);
         break;
      case 5:
         PrintNoofWheels(vehicles);
         break;
      case 6:
         return 0;
         break;
      
      default:
         break;
      }
   }
   return 0;
}