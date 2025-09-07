#include <bits/stdc++.h>
using namespace std;

//Quack Strategies
class QuackBehaviour
{
  public:
      virtual void quack() = 0;
      virtual ~QuackBehaviour(){};
};
class SimpleQuack : public QuackBehaviour
{
    public:
        void quack() override
        {
            cout << "Simple Quack"<< endl;
        }
};
class RoboticQuack : public QuackBehaviour
{
    public:
        void quack() override
        {
            cout << "Machine quack" << endl;
        }
};
class NoQuack : public QuackBehaviour
{
  public:
      void quack() override
      {
          cout << "Silence or No Quack"<< endl;
      }
};
//Fly Strategies
class FlyBehaviour
{
    public:
        virtual void fly()=0;
        virtual ~FlyBehaviour(){};
    
};
class SimpleFly : public FlyBehaviour
{
    public:
        void fly() override
        {
            cout << "This just flies" << endl;
        }
};
class JetFly : public FlyBehaviour
{
    public:
        void fly() override
        {
            cout << "Uses Jet to fly" << endl;
        }
};
class NoFly : public FlyBehaviour
{
    public:
        void fly() override
        {
            cout << "This doesnt fly" << endl;
        }
};
class Duck
{   public:
        QuackBehaviour *qb;
        FlyBehaviour *fb;
        Duck(QuackBehaviour *qb,FlyBehaviour *fb)
        {
            this->qb = qb;
            this->fb = fb;
        }
        void quack()
        {
            qb->quack();
        }
        void fly()
        {
            fb->fly();
        }
        void display()
        {
            cout << "Just Duck Display" << endl;
        }
};  
class RoboticDuck : public Duck
{
    public:
        RoboticDuck() : Duck(new RoboticQuack(), new JetFly()) {}
};
class NormalDuck : public Duck
{
    public:
        NormalDuck() : Duck(new SimpleQuack(), new SimpleFly()) {}
};
class WoodenDuck : public Duck
{
    public:
        WoodenDuck() : Duck(new NoQuack(), new NoFly()) {}
};

int main()
{
    //Robo
    Duck *RoboD = new RoboticDuck();
    RoboD->quack();
    RoboD->fly();
    cout << endl;
    //Wooden
    Duck *WoodenD = new WoodenDuck();
    WoodenD->quack();
    WoodenD->fly();
    cout << endl;
    
    //Normal
    Duck *NormalD = new NormalDuck();
    NormalD->quack();
    NormalD->fly();
    cout << endl;
    
}
