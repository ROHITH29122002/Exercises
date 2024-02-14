#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class Sensor{
private:
    string name;
    float value;
    bool isConnected;
public:
    Sensor() {
        cout<<"Enter The Name of The Sensor : ";
        cin>>name;
        cout<<endl;
        cout << "Enter The default value of Sensor : ";
        cin >> value;
        cout << endl;
        isConnected = false;
    }
    float getValue() {
        return value;
    }
    string getName() {
        return name;
    }
    bool getStatus() {
        return isConnected;
    }
    void onConnect() {
        cout <<name<<" Sensor Connected" << endl;
        isConnected = true;
    }
    void onDisconnect() {
        cout <<name<<" Sensor DisConnected" << endl;
        isConnected = false;
    }
    void increase() {
        if (isConnected) {
            value += 1;
            cout << name<<" increased to : " << value << endl;
            return;
        }
        cout << name<<" Sensor not connected" << endl;
    }
    void decrease() {
        if (isConnected) {
            value -= 1;
            cout << name<<" decreased to : " << value << endl;
            return;
        }
        cout << name<<" Sensor not connected" << endl;
    }
    friend bool operator<(Sensor& sensor, int value) {
        return sensor.getValue() < value;
    }
    friend bool operator>(Sensor& sensor, int value) {
        return sensor.getValue() > value;
    }
};

class Devices {
public:
    virtual string getName() = 0;
    virtual bool getStatus() = 0;
    virtual bool IsConnected() = 0;
    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
    void onConnect() {
        cout << "Device Connected" << endl;
    }
    void DisConnect() {
        cout << "Device Disconnected" << endl;
    }
};

struct rule {
    shared_ptr<Sensor> foundsensor;
    shared_ptr<Devices> founddevice;
    int value;
    string comparision;
    string func;
    function<void(shared_ptr<Sensor>, shared_ptr<Devices>, int, string, string)> automation_function;
};

class Fan : public Devices {
private:
    string name;
    bool status;
    bool isConnected;
public:
    Fan() {
        name = "fan";
        status = false;
        isConnected = false;
    }
    void switchOn() {
        cout << "Fan switched on" << endl;
        status = true;
    }
    void switchOff() {
        cout << "Fan switched off" << endl;
        status = false;
    }
    bool getStatus() {
        return status;
    }
    string getName() {
        return name;
    }
    bool IsConnected() {
        return isConnected;
    }
};

class Light : public Devices {
private:
    string name;
    bool status;
    bool isConnected;
public:
    Light() {
        name = "light";
        status = false;
        isConnected = false;
    }
    void switchOn() {
        cout << "Light switched on" << endl;
        status = true;
    }
    void switchOff() {
        cout << "Light switched off" << endl;
        status = false;
    }
    bool getStatus() {
        return status;
    }
    string getName() {
        return name;
    }
    bool IsConnected() {
        return isConnected;
    }
};

class Door : public Devices {
private:
    string name;
    bool status;
    bool isConnected;
public:
    Door() {
        name = "door";
        status = false;
        isConnected = false;
    }
    void switchOn() {
        cout << "Door Opened" << endl;
        status = true;
    }
    void switchOff() {
        cout << "Door Closed" << endl;
        status = false;
    }
    bool getStatus() {
        return status;
    }
    string getName() {
        return name;
    }
    bool IsConnected() {
        return isConnected;
    }
};

int SearchSensors(string sensorname,vector<shared_ptr<Sensor> > &sensors){
  int sensorsize=sensors.size();
  for(int i=0;i<sensorsize;i++){
    if(sensorname==(*sensors[i]).getName()){
      return i;
    }
  }
  return -1;
}

int SearchDevices(string devicename,vector<shared_ptr<Devices> > &devices){
  int devicesize=devices.size();
  for(int i=0;i<devicesize;i++){
    if(devicename==(*devices[i]).getName()){
      return i;
    }
  }
  return -1;
}

void SimulateInput(vector<shared_ptr<Sensor> > &sensors) {
  string sensorname;
  cout<<"Enter Sensor : ";
  cin>>sensorname;
  cout<<endl;
  int sensorindex=SearchSensors(sensorname,sensors);
  if(sensorindex==-1){
    cout<<sensorname<<" Not Found "<<endl;
    return ;
  }
  cout << "1.Increase Value" << endl;
  cout << "2.Decrease Value" << endl;
  cout << "3.Connect  Sensor" << endl;
  cout << "4.Disconnect  Sensor" << endl;
  int option;
  cin >> option;
  switch (option) {
  case 1:
      (*sensors[sensorindex]).increase();
      break;
  case 2:
      (*sensors[sensorindex]).decrease();
      break;
  case 3:
      (*sensors[sensorindex]).onConnect();
      break;
  case 4:
      (*sensors[sensorindex]).onDisconnect();
      break;
  default:
      break;
  }
}

void DeviceAutomation(vector<shared_ptr<Sensor>>& sensors, vector<shared_ptr<Devices>>& devices, vector<rule>& automation_rules) {
    cout << "Enter The Automation : " << endl;
    string condition, action;
    cin.ignore();
    cout << "Enter The Condition : If ";
    getline(cin, condition, '\n');
    condition += " ";
    cout << "Enter The Action : Then ";
    getline(cin, action, '\n');
    action += " ";
    cout << endl;

    vector<string> input(5, "");
    int conditionsize = condition.length();
    int actionsize = action.length();
    int i = 0;
    int j = 0;
    string temp = "";
    while (i < conditionsize) {
        if (condition[i] == ' ') {
            input[j] = temp;
            temp = "";
            j++;
            i++;
            continue;
        }
        temp += condition[i];
        i++;
    }
    i = 0;
    while (i < actionsize) {
        if (action[i] == ' ') {
            input[j] = temp;
            temp = "";
            j++;
            i++;
            continue;
        }
        temp += action[i];
        i++;
    }
    int sensorindex = SearchSensors(input[0], sensors);
    if (sensorindex == -1) {
        cout << "Sensor Not Found" << endl;
        return;
    }
    int deviceindex = SearchDevices(input[3], devices);
    if (deviceindex == -1) {
        cout << "Device Not Found" << endl;
        return;
    }
    shared_ptr<Sensor> foundsensor = sensors[sensorindex];
    string comparision = input[1];
    int value = stoi(input[2]);
    shared_ptr<Devices> founddevice = devices[deviceindex];
    string func = input[4];
    automation_rules.push_back({
        foundsensor,
        founddevice,
        value,
        comparision,
        func,
        [](shared_ptr<Sensor> foundsensor, shared_ptr<Devices> founddevice, int value, string comparision, string func) {
          if(!(*foundsensor).getStatus()){
            return;
          }
          if (comparision == "<") {
              if (*foundsensor < value) {
                  if (func == "on") {
                      if(!(*founddevice).getStatus()){
                        founddevice->switchOn();
                      }
                  } else {
                      if((*founddevice).getStatus()){
                        founddevice->switchOff();
                      }
                  }
              }
          } else if (comparision == ">") {
              if (*foundsensor > value) {
                  if (func == "on") {
                      if(!(*founddevice).getStatus()){
                        founddevice->switchOn();
                      }
                  } else {
                      if((*founddevice).getStatus()){
                        founddevice->switchOff();
                      }
                  }
              }
          }
        }
    });
}

void PrintDetails(vector<shared_ptr<Sensor> > &sensors){
  int sensorsize=sensors.size();
  for(int i=0;i<sensorsize;i++){
    cout<<sensors[i]->getName()<<" : "<<sensors[i]->getValue()<<" "<<(sensors[i]->getStatus() ? "Connected" : "Disconnected")<<endl;
  }
}


int main() {
    vector<shared_ptr<Sensor>> sensors;
    vector<shared_ptr<Devices>> devices;
    vector<rule> automation_rules;
    shared_ptr<Fan> fan = make_shared<Fan>();
    shared_ptr<Light> light = make_shared<Light>();
    shared_ptr<Door> door = make_shared<Door>();
    devices.push_back(fan);
    devices.push_back(light);
    devices.push_back(door);
    while (true) {
        int automation_rules_size = automation_rules.size();
        for (int i = 0; i < automation_rules_size; i++) {
            automation_rules[i].automation_function(automation_rules[i].foundsensor, automation_rules[i].founddevice, automation_rules[i].value, automation_rules[i].comparision, automation_rules[i].func);
        }
        cout << "Details : " << endl;
        PrintDetails(sensors);
        cout << "Fan : " << (fan->getStatus() ? "On" : "Off") << endl;
        cout << "Light : " << (light->getStatus() ? "On" : "Off") << endl;
        cout << "Door : " << (door->getStatus() ? "Open" : "Closed") << endl;
        cout << "Select any Option : " << endl;
        cout << "1.Add Sensor" << endl;
        cout << "2.Simulate Input" << endl;
        cout << "3.Device Automation" << endl;
        cout << "4.Exit" << endl;
        int option;
        cin >> option;
        switch (option) {
        case 1:
            sensors.push_back(make_shared<Sensor>());
            break;
        case 2:
            SimulateInput(sensors);
            break;
        case 3:
            DeviceAutomation(sensors, devices, automation_rules);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
