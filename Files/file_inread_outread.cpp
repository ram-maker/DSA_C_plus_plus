#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream infile("Tmp/example.txt");
    std::ofstream outfile("Tmp/output1.txt");
    if(!infile){
        std::cout<<"File doesnt exists"<<std::endl;
    }
    if(!outfile){
        std::cout<<"Output File doesnt exists"<<std::endl;
    }
    std::string Line;
    while (std::getline(infile,Line)){
        outfile<<Line<<std::endl;
    }
    infile.close();
}