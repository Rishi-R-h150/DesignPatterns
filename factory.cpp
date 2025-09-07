#include <bits/stdc++.h>
using namespace std;
//Products of Factory
class Pizza
{
    protected:
        string name;
        string dough;
        string sauce;
        vector<string> toppings;
    public:
        virtual void prepare()
        {
            cout << "Preparing " << name << endl;
            cout << "Adding " << dough << endl;
            cout << "Adding " << sauce << endl;
            cout << "Adding toppings " << endl;
            for(auto top : toppings){cout << top << endl;}
        }
       void bake()
        {
            cout << "baking the pizza" << endl;
        }
        void cut()
        {
            cout << "Cutting the pizza" << endl;
        }
        void box()
        {
            cout << "putting the pizza in the box" << endl;
        }
        void isready()
        {
           cout << "Your Pizza is " << name << " is Ready";
        }
};
class NYstylePeparoniPizza : public Pizza
{
    public:
      NYstylePeparoniPizza()
      {
          dough = "Thin crust";
          name = "NYstylePeparoniPizza";
          sauce = "Tomato sause";
          toppings.push_back("Grated Cheese");
          toppings.push_back("Peparoni");
      }
      
};
class NYstyleCheesePizza : public Pizza
{
    public:
      NYstyleCheesePizza()
      {
          dough = "Thin crust";
          name = "NYstylePeparoniPizza";
          sauce = "Tomato sause";
          toppings.push_back("Grated Cheese");
          toppings.push_back("More cheese");
      }
      
};
class ChicagostyleCheesePizza : public Pizza
{
    public:
        ChicagostyleCheesePizza()
        {
            dough = "Thick crust";
            name = "ChicagocheesePizza";
            sauce = "Cherry tomato sause";
            toppings.push_back("Cheese");
            toppings.push_back("Chicken");
            toppings.push_back("Olives");
        }
    
};
class ChicagostylePeparoniPizza : public Pizza
{
    public:
        ChicagostylePeparoniPizza()
        {
            dough = "Thick crust";
            name = "ChicagopeparoniPizza";
            sauce = "Cherry tomato sause";
            toppings.push_back("Grated Cheese");
            toppings.push_back("Peparoni");
        }
    
};
//Creators
class PizzaStore
{
    protected:
        Pizza* pizza;
        //abstract factory method
        virtual Pizza* createPizza(const string type) = 0;
    public:
        void orderPizza(const string type)
        {
            pizza = createPizza(type);
            if(pizza == nullptr)
            {
                cout << "Pizza is not in menu yet";
            }
            else
            {
                pizza->prepare();
                pizza->bake();
                pizza->cut();
                pizza->box();
                pizza->isready();
            }
        }
};
    
class NYpizzaStore: public PizzaStore
{
    protected:
        Pizza* createPizza(const string type)
        {
            if(type == "PeparoniPizza")
            {
                return new NYstylePeparoniPizza();
            }
            if(type == "CheesePizza")
            {
                return new NYstyleCheesePizza();
            }
            return nullptr;
        }
};
   
class ChicagopizzaStore : public PizzaStore
{
    protected:
        Pizza* createPizza(const string type)
        {
            if(type == "PeparoniPizza")
            {
                return new ChicagostylePeparoniPizza();
            }
            if(type == "CheesePizza")
            {
                return new ChicagostyleCheesePizza();
            }
            return nullptr;
        }
};

int main()
{
    PizzaStore* Nystore = new NYpizzaStore();
    Nystore->orderPizza("PeparoniPizza");
    
}