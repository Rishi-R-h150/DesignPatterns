#include <bits/stdc++.h>
using namespace std;
class Idisplay
{
    public:
        virtual void display() = 0;
        virtual void Update(float temp , float hum , float pre) = 0;
};
class Istation
{
    public:
        virtual void addObserver(Idisplay* d)=0;
        virtual void removeObserver(Idisplay *d)=0;
        virtual void notifyObservers(float temp , float humidity , float pressure)=0;
};

class weatherStation : public Istation
{
    public:
        vector<Idisplay*>observers;
        void addObserver (Idisplay* d)override
        {
            observers.push_back(d);
        }
        void removeObserver (Idisplay* d)override
        {
            auto it = find(observers.begin(),observers.end(),d);
            observers.erase(it);
        }
        void notifyObservers (float temp,float humidity,float pressure) override
        {
            for(auto o : observers)
            {
                o->Update(temp,humidity,pressure);
            }
        }
};
class currentConditionsDisplay : public Idisplay
{
    public:
        float temperature;
        float humidity;
        float pressure;
        Istation* station;
        currentConditionsDisplay(Istation* weatherStation)
        {
            this->station = weatherStation;
            station->addObserver(this);
        }
        void Update (float temp,float hum,float pre) override
        {
            this->temperature = temp;
            this->pressure = pre;
            this->humidity = hum;
            display();
        }
        void display ()override
        {
            cout << "CurrentConditions" << endl << "temperature : " << temperature << endl << "humidity : " << humidity << endl << "pressure : " << pressure << endl;
        }
};
int main()
{
    Istation* wStation = new weatherStation();
    Idisplay* CCDisplay = new currentConditionsDisplay(wStation);
    wStation->notifyObservers(50,82,99);
    
    
}