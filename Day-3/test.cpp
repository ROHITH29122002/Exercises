#include<iostream>
#include<memory>
using namespace std;

int FormGroup(unique_ptr<unique_ptr<int[]>[]> &city,int rows,int columns,int i,int j){
    if(i<0 || j<0 || i>=rows || j>=columns || city[i][j]==0){
        return 0;
    }
    int sum=city[i][j];
    city[i][j]=0;
    sum+=FormGroup(city,rows,columns,i+1,j);
    sum+=FormGroup(city,rows,columns,i,j+1);
    sum+=FormGroup(city,rows,columns,i-1,j);
    sum+=FormGroup(city,rows,columns,i,j-1);
    return sum;
}

int findLeader(unique_ptr<int[]> &groups,int end){
    int leader=INT_MIN;
    for(int i=0;i<end;i++){
        leader=max(leader,groups[i]);
    }
    return leader;
}

int main(){
    while(true){
        int rows;
        int columns;
        cout<<"Enter The Number of Rows : ";
        cin>>rows;
        cout<<endl;
        cout<<"Enter The Number of Columns : ";
        cin>>columns;
        cout<<endl;
        // int **city =new int*[n];
        unique_ptr<unique_ptr<int[]>[]> city(new unique_ptr<int[]>[rows]);
        for(int i=0;i<rows;i++){
            // city[i]=new int[m];
            city[i]=unique_ptr<int[]>(new int[columns]);
            cout<<"Enter The Values for "<<i<<"th Row : "<<endl;
            for(int j=0;j<columns;j++){
                cin>>city[i][j];
            }
        }
        // int *groups=new int[n*m];
        unique_ptr<int[]> groups(new int[rows*columns]);
        int end=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(city[i][j]!=0){
                    groups[end]=FormGroup(city,rows,columns,i,j);
                    end++;
                }
            }
        }
        while(true){
            cout<<"Select any Option : "<<endl;
            cout<<"1.Print All Groups"<<endl;
            cout<<"2.Print Leader of The Groups"<<endl;
            cout<<"3.Exit"<<endl;
            int option;
            cin>>option;
            switch (option)
            {
            case 1:
                cout<<"The Groups in the City are : [ ";
                for(int i=0;i<end;i++){
                    cout<<groups[i]<<" ";
                }
                cout<<"]"<<endl;
                break;
            case 2:
                cout<<"The Leader of The City is : ";
                cout<<findLeader(groups,end)<<endl;
                break;
            case 3:
                return 0;
                break;
            default:
                return 0; 
                break;
            }
            }
    }
    return 0;
}