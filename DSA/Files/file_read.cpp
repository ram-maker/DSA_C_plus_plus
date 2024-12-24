#include <iostream>
#include <fstream>
#include <string>

int main(){
  
    std::ofstream outfile("Tmp/output1.txt",std::ios::app);
    if(!outfile){
        std::cout<<"Output File doesnt exists"<<std::endl;
    }
    std::string Line;
    std::cout<<"Please fill the file content(Type 'exit' if you are done)"<<std::endl;
    while (std::getline(std::cin,Line)){
        if (Line=="exit"){
            break;
        }
        outfile<<Line<<std::endl;
    }
    outfile.close();
   
}