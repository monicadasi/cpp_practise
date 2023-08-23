#include<iostream>
#include<vector>
#include<functional>

// abstract observer
class Observer{
public:
    virtual void update() = 0;
};

// concrete observer 1
class Observer1 : public Observer{
public:
    void update() override{
        std::cout << "Received update in observer 1" << std::endl;
    }
};

// concrete observer 2
class Observer2 : public Observer{
public:
    void update() override{
        std::cout << "Received update in observer 2" << std::endl;
    }
};

// subject 
class Subject{
    std::vector<std::function<void()>> observerList;
public:
    void addObserver(std::function<void()> observer){
        observerList.push_back(observer);
    }

    void notifyObserver(){
        for(auto observer : observerList)
        {
            observer();
        }
    }
};

int main()
{
    // create instances
    Subject subj;
    Observer1 obs1;
    Observer2 obs2;

    // create the std::function object by binding the observer update function with observer instances
    std::function<void()> obs1_fp = std::bind(&Observer1::update, &obs1);
    std::function<void()> obs2_fp = std::bind(&Observer2::update, &obs2);

    // register the observers
    subj.addObserver(obs1_fp);
    subj.addObserver(obs2_fp);

    // notify observers
    subj.notifyObserver();
}