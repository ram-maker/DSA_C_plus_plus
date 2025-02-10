/*
State design pattern
In software engineering application an object has certain state and are likely to change in accordance to certain action. The primitive method to deal with such problems
is load of conditional ifs. BY leveraging a state pattern we are able to eliminate the use of conditional ifs. The state of the object change to another state in accordance
to certain action.

Concrete state changes state by interacting with context, it holds the reference of current state.generally it has same method as that of interface and delegates
call to methods of current object.

It violates I principle, as concrete type are forced with the methods that they dont need it.
*/
#include <iostream>
#include <memory>
using namespace std;
class AutomaticGateState;
class OpeningState;
class ClosingState;
class OpenState;
class CloseState;
class StopState;
/*Door state Interface*/
class GateState{
    public:
    virtual void pressOpenButton(AutomaticGateState& gate_state)=0;
    virtual void pressCloseButton(AutomaticGateState& gate_state)=0;
    virtual void pressStopButton(AutomaticGateState& gate_state)=0;
};
/*Context*/
class AutomaticGateState{
    shared_ptr<GateState> current_state;
    public:
    AutomaticGateState(shared_ptr<GateState> current_state){
        this->current_state=current_state;
    }
    void setCurrentState(shared_ptr<GateState> current_state){
        this->current_state=current_state;
    }
    void pressOpenButton(){
        current_state->pressOpenButton(*this);
    }
    void pressCloseButton(){
        current_state->pressCloseButton(*this);
    }
    void pressStopButton(){
        current_state->pressStopButton(*this);
    }
};
/*Concrete State*/
class OpeningState:public GateState{
    public:
    void pressOpenButton(AutomaticGateState& gate_state){
        cout<<"Opening Gate continue to be opening when open button pressed"<<endl;
    }
    void pressCloseButton(AutomaticGateState &gate_state){
        cout<<"Opening Gate dont close when close button pressed"<<endl;
    }
    void pressStopButton(AutomaticGateState &gate_state){
        cout<<"Opening gate stops when stop button pressed"<<endl;
        gate_state.setCurrentState(std::static_pointer_cast<GateState>(make_shared<StopState>()));
    }
};

class ClosingState:public GateState{
    public:
    void pressOpenButton(AutomaticGateState& gate_state){
        cout<<"Closing Gate  dont open when open button pressed"<<endl;
    }

    void pressCloseButton(AutomaticGateState &gate_state){
        cout<<"Closing Gate continue to be closing when close button pressed"<<endl;
    }

    void pressStopButton(AutomaticGateState &gate_state){
        cout<<"Closing gate stops when stop button pressed"<<endl;
        gate_state.setCurrentState(std::static_pointer_cast<GateState>(make_shared<StopState>()));
    }
};

class OpenState:public GateState{
    public:
    void pressOpenButton(AutomaticGateState& gate_state){
        cout<<"Open Gate continue to be  opened when open button pressed"<<endl;
    }
    void pressCloseButton(AutomaticGateState &gate_state){
        cout<<"Open Gate  closes when close button pressed"<<endl;
        gate_state.setCurrentState(make_shared<ClosingState>());
    }
    void pressStopButton(AutomaticGateState &gate_state){
        cout<<"Open Gate continues to open when stop button pressed"<<endl;
    }
};

class CloseState:public GateState{
    public:
    void pressOpenButton(AutomaticGateState& gate_state){
        cout<<"Closed gate Opens when Open button pressed"<<endl;
        gate_state.setCurrentState(make_shared<OpeningState>());
    }
    void pressCloseButton(AutomaticGateState &gate_state){
        cout<<"Closed Gate continue to close  when close button pressed"<<endl;
    }
    void pressStopButton(AutomaticGateState &gate_state){
        cout<<"Closed Gate continues to close when stop button pressed"<<endl;
    }
};

class StopState:public GateState{
    public:
    void pressOpenButton(AutomaticGateState& gate_state){
        cout<<"Stooped Gate Opens when open button pressed"<<endl;
        gate_state.setCurrentState(make_shared<OpeningState>());
    }
    void pressCloseButton(AutomaticGateState &gate_state){
        cout<<"Stopped Gate  closes when close button pressed"<<endl;
        gate_state.setCurrentState(make_shared<ClosingState>());
    }
    void pressStopButton(AutomaticGateState &gate_state){
        cout<<"Stopped Gate continues stops when stop button pressed"<<endl;

    }
};
 int main(){
    shared_ptr<GateState> default_gate_state=make_shared<StopState>();
    shared_ptr<AutomaticGateState> gate_state=make_shared<AutomaticGateState>(default_gate_state);
    gate_state->pressOpenButton();
    gate_state->pressStopButton();
    gate_state->pressStopButton();
    gate_state->pressCloseButton();
    gate_state->pressOpenButton();
    return 0;
 }