/*
Imagine there is a class Navigation, which helps for nvigation between two places for user. The user can be cyclists,
public commuter, private vehicle or pedestrian. Now the navigation facilates all the provision for these type of user. Wait but the navigation class is likely to 
become very big as navigator type increases, which may invite unmaintainable code,

The strategy pattern instead of groupping all the navigator into single class , delegates each navigator to separate class sharing the common interface.
This makes the code more maintainable and easy to scale
Suitable for the use case that uses Family of algorithms

Generally the strategy pattern contains:
Context:
 a class which holds the refernce for one of the concrete strategy
 It doesnt decide which concrete algorithm to choose, rather client fetches the concrete stratregy, 
 It then delegates the concrete stratregy method

 Strategy:
 a common interface for concrete strategy

 Concrete Strategy:
 The subclass of strategy
*/
#include <iostream>
#include <memory>
using namespace std;

/*Context*/
class RouteStrategy{
    public:
    virtual int getTotalDistance()=0;
};

/*Strategy 1*/
class PedestrianStrategy:public RouteStrategy{
    public:
    int getTotalDistance(){
        return 4;
    }
};

/*Strategy 1*/
class PublicStrategy:public RouteStrategy{
    public:
    int getTotalDistance(){
        return 8;
    }
};
/*Context*/
class Navigator{
    shared_ptr<RouteStrategy> route;
    public:
    Navigator(shared_ptr<RouteStrategy> route){
        this->route=route;
    }
    int renderDistance(){
        return route->getTotalDistance();
    }

};

int main(){
    shared_ptr<RouteStrategy> pedestrian_route=make_shared<PedestrianStrategy>();
    shared_ptr<Navigator> pedestrian_navigator=make_shared<Navigator>(pedestrian_route);
    int distance=pedestrian_navigator->renderDistance();
    cout<<"Distance:"<<distance<<endl;
}


