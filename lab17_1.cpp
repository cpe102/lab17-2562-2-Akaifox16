//Write your code here
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

int main(){
    string inp , name , command;
    ifstream file("name_score.txt");
    vector<string> data;
    vector<string> score;
    int n1 , n2 ,n3 , sum , count = 0;
    char format[] = "%[^:]: %d %d %d",nm[100];

    while(getline(file,inp)){
        sscanf(inp.c_str(),format,nm , &n1 , &n2 ,&n3);
        sum = n1+ n2 + n3;
        score.push_back(sum >= 80 ? "A": sum >= 70 ? "B" : sum >= 60 ? "C" : sum >= 50 ? "D" : "F");
        data.push_back(nm);
        count++;
    }
    file.close();
   
    while(true){
        bool chck = 0;
        
        cout << "Plese input your command :";
        getline(cin , inp);
        command = inp.substr(0, 5);
        for(int i = 0 ; i < command.size() ; i++){
            command[i] = tolower(command[i]);
        }
        if(command == "exit"){
            break;
        }
        else if(command == "name "){
            command = inp.substr(5 , inp.size() - 5);
            for(int i= 0 ; i < data.size();i++){
                name = data.at(i);
                for(int i = 0 ; i < name.size() ; i++){
                    name.at(i) = tolower(name.at(i));
                }
                for(int i = 0 ; i < command.size() ; i++){
                    command.at(i) = tolower(command.at(i));
                }
                if(command == name){
                    cout << "---------------------------------\n";
                    cout << data.at(i) <<"'s grade = " << score.at(i) << '\n';
                    chck = 1;
                    cout << "---------------------------------\n";    
                }
                else if(!chck && i +1 == data.size()){ 
                    cout << "Cannot found.\n";
                    break;
                }
            }       
        }
        else if(command == "grade"){
            bool first = 1;
            command = inp.substr(6 , 1);
            for(int i=0 ; i < score.size() ; i++){
                command  = toupper(command.at(0));
                if(command == score.at(i) ){
                    if(first){
                    cout << "---------------------------------\n";
                    first = 0;
                    }
                    cout << data.at(i) << '\n';
                    chck = 1;
                }
                else if(i + 1 == score.size()){
                    if(!chck){
                        cout << "Cannot found.\n";
                        break;
                    }
                    if(chck)
                    cout << "---------------------------------\n";
                }
                
            }
        }
        else{
            cout << "Invalid command\n";
        }
    }
    return 0;
}