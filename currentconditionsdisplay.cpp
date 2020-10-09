#include "currentconditionsdisplay.h"

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject *weatherData)
{
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(100, 100, 400, 200);
    this->setWindowTitle("Текущие значения");

    temp = new QLabel(this);
    temp->setText("Влажность: НЕТ ДАННЫЙ!!!");
    temp->setGeometry(10, 10, 190, 20);
    temp->setParent(this);

    hum = new QLabel(this);
    hum->setText("Температура: НЕТ ДАННЫЙ!!!");
    hum->setGeometry(10, 30, 190, 20);
    hum->setParent(this);

}

void CurrentConditionsDisplay::update(float t, float h, float p) {
    this->temperature = t;
    this->humidity = h;
    //this->pressure = p;
    this->display();
}

void CurrentConditionsDisplay::display() {
    temp->setText("Температура: " + QString::number(temperature));
    hum->setText("Влажность: " + QString::number(humidity));
    /*cout << "Current conditions: " << endl << "\t"
         << temperature << "% °C" << endl
         << "\t" << humidity << endl
         << "\t" << pressure << " mm Hg" << endl;*/
}
