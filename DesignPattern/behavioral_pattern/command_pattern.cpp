/*
Sometimes  a tight coupling between sender and receiver can invite unnecessary hazzles in the code section. MOreover, the situation may demand delay of immediate response
from given request:delaying request process. Some command pattern is generaaly used to refrain tight coupling between sender and reciver. It can also be leve
raged to group series of command into standalone command. For instance, turning on light, tv at the sametime. Moreover it can undo the things that it is doing.
It contains:
receiver:
The classes that are going to recieve the final command for operation
*/
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

/*Receiver 1*/
class TV{
    public:
    void turnOn(){
        cout<<"Turning on TV"<<endl;
    }

    void turnOff(){
        cout<<"Turning off TV"<<endl;
    }

};

/*Receiver 2*/
class Light{
    public:
    void turnOn(){
        cout<<"Turning on Light"<<endl;
    }
    
    void turnOff(){
        cout<<"Turning off Light"<<endl;
    }
};



/*Command Interface*/
class Command{
    public:
    virtual void execute()=0;
    virtual void undo()=0;
};

/*Concrete Command 1*/
class TurnOnTVCommand:public Command{
    TV tv;
    public:
    void execute(){
        tv.turnOn();
    }

    void undo(){
        tv.turnOff();
    }

};

/*Concrete Command 2*/
class TurnOnLightCommand:public Command{
    Light light;
    public:
    void execute(){
        light.turnOn();
    }

    void undo(){
        light.turnOff();
    }


};

/*Invoker*/
class MergeCommand{
    vector<shared_ptr<Command>>  commands;
    public:
    // MergeCommand(shared_ptr<Command> command):command(command){}//Defining intializer command with initiazer list directly assigns the value, it doesnt depend on deault constructor for intialization
    void addCommand(shared_ptr<Command> command){
        commands.push_back(command);
    }

    void removeCommand(shared_ptr<Command> command){
        auto it=remove(commands.begin(),commands.end(),command);
        if (it!=commands.end()){
            commands.erase(it,commands.end());
            cout<<"Sucessfully removed command from merger command"<<endl;
        }else{
            cout<<"Cant remove command"<<endl;
        }
    }

    void executeCommand(){
        for(auto command:commands){
            command->execute();
        }
    }

    void undoCommand(){
        for(auto command:commands){
            command->undo();
        }
    }

};

int main(){
    shared_ptr<Command> light_turn_on_command=make_shared<TurnOnLightCommand>();
    shared_ptr<Command> tv_turn_on_command=make_shared<TurnOnTVCommand>();
    MergeCommand command_merger;
    command_merger.addCommand(light_turn_on_command);
    command_merger.addCommand(tv_turn_on_command);
    command_merger.executeCommand();
    command_merger.undoCommand();
    command_merger.removeCommand(tv_turn_on_command);
    command_merger.executeCommand();
}

