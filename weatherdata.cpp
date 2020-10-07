#include "weatherdata.h"

WeatherData::WeatherData()
{
    observers = new QList<Observer*>();
}

void WeatherData::registerObserver(Observer *o){
    observers->append(o);
}

void WeatherData::removeObserver(Observer *o){
    // поиск наблюдателя))0
    int i = observers->indexOf(o);
    // Удаление
    if (i > 0) {
        observers->removeAt(i);
    }
}
void WeatherData::notifyObserver(){
    for (int i = 0; i < observers->size(); i++) {
        Observer *observer = observers->at(i);
        observer->update(temperature, humidity, pressure);
    }
}

void WeatherData::setMeasurementsChanged(float t, float h, float p){
    this->temperature = t;
    this->humidity = h;
    this->pressure = p;
    this->notifyObserver();
}

void WeatherData::measurementsChanged() {
    notifyObserver();
}
