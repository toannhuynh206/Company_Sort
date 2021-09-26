#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Project{
                                          
    int max_dev; //max amount of developers
    int max_des;  //max amount of designers 
    string tech_lead="0";//0 meaning empty string for tl
    string prod_man="0";  //0 meaning empty string for pm
    string name; //name of the project 
    string* dev_list;  //array of of names developers
    string* des_list; //array of names for designers

};

class ProjectTracker
{
public:
    
    ProjectTracker(int n); //constructor 
    
    ~ProjectTracker(); //deconstructor 
    void print_proj(); //print all projects 

    Project** projects; //array of projects
    int max; //number of projects

};

ProjectTracker::ProjectTracker(int n) {
    max=n;   //intalize n amount of projects
    projects = new Project*[n];
    for(int i=0;i<n;i++){
        projects[i]=new Project();
    }
}

ProjectTracker::~ProjectTracker(){

    for(int i=0;i<max;i++){
       delete projects[i];
   }
    delete[] projects;

}

void ProjectTracker::print_proj(){  //function to print the output formatted well
    for(int i=0;i<max;i++){
        cout<<projects[i]->name<<endl;
        cout<<"TL: "<<projects[i]->tech_lead<<endl;
        cout<<"PM: "<<projects[i]->prod_man<<endl;
        cout <<"Developers: ";

        if(projects[i]->max_dev==0||projects[i]->dev_list[0]=="0"){
            cout<<"None";
        }
        else{
        for(int j=0;j<projects[i]->max_dev;j++){

            if(projects[i]->dev_list[j]!="0"){ //only print out name if the spot is filled in
            cout<<projects[i]->dev_list[j];
            }
            
             if (projects[i]->max_dev==0|| j==(projects[i]->max_dev)-1){
                break;
            }
            else{cout<<", ";}
        }
        }
        cout<<endl;
        cout <<"Designers: ";
        if(projects[i]->max_des==0||projects[i]->des_list[0]=="0"){
            cout<<"None";
        }
        else{
            for(int j=0;j<projects[i]->max_des;j++){
                if(projects[i]->des_list[j]!="0"){
                    cout<<projects[i]->des_list[j];
                 }
                 if (projects[i]->max_des==0|| j==(projects[i]->max_des)-1){
                    break;
                 }
                else{cout<<", ";}
            }
        }
        cout<<endl;
        cout<<endl;
    }
}



int main(){

    string team;
    string num_team;
    int max_mem;
    string name;
    string role;
    string rank;
    int num;
    string dev;
    string des;
    string my_str;

    getline(cin,my_str);              //this block of code gets the # of projects and the #of members 
    stringstream s_stream(my_str); 
    getline(s_stream, num_team, ',');
    getline(s_stream, team, ',');
    int max_team=stoi(num_team);
    max_mem=stoi(team);


    ProjectTracker prod(max_team); //intialize the projects we are going to fill in





//this for loop intializes our projects name and max # of developers and designers, it also allocates the correct number of members for devs and des.
    for(int i=0;i<max_team;i++){
        getline(cin,my_str);
        stringstream s_stream(my_str); //this blocks of code gets the input for the name and # of developers and designers for each team
        getline(s_stream, name, ',');
        getline(s_stream, dev, ',');
        getline(s_stream, des, ',');


        prod.projects[i]->name=name;  
        prod.projects[i]->dev_list= new string[stoi(dev)];
        prod.projects[i]->des_list= new string[stoi(des)];
        prod.projects[i]->max_des=stoi(des);
        prod.projects[i]->max_dev=stoi(dev);
        for(int j=0;j<stoi(dev);j++){    //intializes the developers and designers array to 0, if there is space in the list , 0 meaning that slot is open to be filled in
            prod.projects[i]->dev_list[j]="0";
        }
        for(int j=0;j<stoi(des);j++){
            prod.projects[i]->des_list[j]="0";
        }
       
    }

    //this block of code inputs the members and places them according to there role and rank
    for(int i=0;i<max_mem;i++){
        cin>>my_str;
        stringstream s_stream(my_str); //create string stream from the string
        getline(s_stream, name, ',');
        getline(s_stream, role, ',');
    
        //depending on the role place the names into the project accordinly testing to see if they are avaiable 
        if(role=="TL"){    //if role is TL we will first test if there first ranked options TL is filled up, if not we will add them to that project, it is full, then we will go to the next rank
            while(s_stream.good()){
                getline(s_stream,rank,',');
                num=stoi(rank);
                num-=1; //-1 since rank 0 is the first project
                if(prod.projects[stoi(rank)-1]->tech_lead=="0"){ //if this project tech lead is open we will fill it in
                    prod.projects[stoi(rank)-1]->tech_lead=name;
                    break; 
                }
            }
        }
        else if(role=="PM"){  //if role is PM we will first test if there first ranked options TL is filled up, if not we will add them to that project, it is full, then we will go to the next rank
            while(s_stream.good()){
                getline(s_stream,rank,',');

                if(prod.projects[stoi(rank)-1]->prod_man=="0"){
                    prod.projects[stoi(rank)-1]->prod_man=name;
                    break;
                }
            }

        }
        else if(role=="Developer"){ //for developers we want to check if there is even space in the list first by checking the last element in the array, if the last element is still open that means we can add that person to that project
            while(s_stream.good()){
                getline(s_stream,rank,',');
                num=stoi(rank);
                num-=1;
                if(prod.projects[num]->dev_list[(prod.projects[num]->max_dev)-1]=="0"){ //check to see if the array is full
                    for(int i=0;i<prod.projects[num]->max_dev;i++){
                        if(prod.projects[num]->dev_list[i]=="0"){ //check each slot to see if there is already a name in each opening
                            prod.projects[num]->dev_list[i]=name; //once we find it we enter the name in
                            break; 
                        }
                    }
                    break;
                }
            }
        }
        else if(role=="Designer"){ //same logic goes for designers 
            while(s_stream.good()){
                getline(s_stream,rank,',');
                if(prod.projects[stoi(rank)-1]->des_list[(prod.projects[stoi(rank)-1]->max_des)-1]=="0"){
                    for(int i=0;i<prod.projects[stoi(rank)-1]->max_des;i++){
                        if(prod.projects[stoi(rank)-1]->des_list[i]=="0"){
                            prod.projects[stoi(rank)-1]->des_list[i]=name;
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    prod.print_proj(); //call print project function to output the teams

   for(int i=0;i<prod.max;i++){   //deallocate arrays of developers and designers from each project
       delete[] prod.projects[i]->dev_list;
       delete[] prod.projects[i]->des_list;
   }


    return 0;
}

