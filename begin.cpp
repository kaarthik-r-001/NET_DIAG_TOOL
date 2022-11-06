#include <bits/stdc++.h>
#include <fstream> //to get directly from the file
using namespace std;
// class router{
//     public:

// };
// class hub{

// };
// class switches{

// };
// class end_devices{

// };
// class bridge{

// };
// class gateway{

// };
// class modem{

// };
// class repeater{

// };
// class accesspoint{

// };
class edges{

    pair<int,int> participant;
    int bandwidth;
    public:
    edges(){

    }
    edges(pair<int,int> participant, int bandwidth ){
        this->participant=participant;
        this->bandwidth=bandwidth;
    }
    void display_edges(){
        cout<<"partipant 1 "<<participant.first<<" participant 2 = "<<participant.second<<" bandwidth"<<bandwidth<<"\n";
    }
    // int throughput;
};
class node{
    private:
    int total_of_sockets;
    int already_connected;
    int node_id;
    string node_type;
    vector<edges> edgelist;
    public:
    node(){

    }
    node(int node_id,string node_type,int no_of_sockets)
    {
        this->node_type=node_type;
        this->node_id=node_id;
        this->total_of_sockets=total_of_sockets;
    }
    void display_var(){
        cout<<node_id<<node_type<<total_of_sockets<<"\n";
    }

};

class network{
    vector<node> components;
    vector<edges> edgelist;
    public:
    network(vector<node> components, vector<edges> edgelist){
        this->components=components;
        this->edgelist=edgelist;
    }
};
vector<node> readconfig(){
    vector<node> tempnode;
    ifstream fin("config.txt");
    int temp1;
    string temp2;
    int temp3;
    while(true){
        if(fin.eof()) break;
        fin>>temp1>>temp2>>temp3;
        tempnode.push_back(node(temp1,temp2,temp3));
        
    }
    return tempnode;
}

vector<edges> readedges()
{
    ifstream fin("edges.txt");
    int temp1,temp2,temp3;
    vector<edges> tempedges;
    while(true){
        fin>>temp1>>temp2>>temp3;
        if(fin.eof()) break;
        pair<int,int> temp;
        //checks if port exceedes 
        //warning
        //edge added //next time

        temp.first=temp1;
        temp.second=temp2;
        tempedges.push_back(edges(temp,temp3));
    } 
    return tempedges;   
}
int main(){
    vector<node> node_objects;
    node_objects=readconfig();
    for(auto it:node_objects){
        it.display_var();
    }
    vector<edges> edge_objects;
    edge_objects=readedges();
    for(auto it1 : edge_objects){
        it1.display_edges();
    }
    //generation
    // node_objects,edge_objects finalizing here

    // network MyNet(node_objects,edge_objects); 
    //diagon
    return 0;
}
//adding a change