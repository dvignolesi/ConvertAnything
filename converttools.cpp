#include "converttools.h"

ConvertTools::ConvertTools()
{

}
void tempMath(QList<double> *numbersToConvert, int whoSignaled)
{
    //Qlist/whoSignaled - 1. Fahrenheit 2. Celcius, 3. Kelvin 4. Rankine

    switch(whoSignaled) {
    case 1: //Fahrenheit to 1. Celcius 2. Kelvin 3. Rankine
        numbersToConvert->insert(2,((numbersToConvert->at(1)) - 32) * (5/9));
        numbersToConvert->insert(3,((numbersToConvert->at(1)) - 32) * (5/9) + 273.15);
        numbersToConvert->insert(4,((numbersToConvert->at(1)) + 459.67));
        break;
    case 2: // Celcius to 1. Fahrenheit 2. Kelvin 3. Rankine
        numbersToConvert->insert(1,(((numbersToConvert->at(2))*(9/5) + 32)));
        numbersToConvert->insert(3,((numbersToConvert->at(2)) + 273.15));
        numbersToConvert->insert(4,(((numbersToConvert->at(2)) + 273.15) * (9/5)));
        break;
    case 3: // Kelvin to 1. Fahrenheit 2. Celcius 3. Rankine
        numbersToConvert->insert(1,(((numbersToConvert->at(3)) - 273.15) * (9/5) + 32));
        numbersToConvert->insert(2,((numbersToConvert->at(3)) - 273.15));
        numbersToConvert->insert(4,((numbersToConvert->at(3) * (9/5))));
        break;
    case 4: // Rankine to 1. Fahrenheit 2. Celcius 3. Kelvin
        numbersToConvert->insert(1,(((numbersToConvert->at(4)) - 459.67)));
        numbersToConvert->insert(2,(((numbersToConvert->at(4)) - 491.67) * (5/9)));
        numbersToConvert->insert(3,((numbersToConvert->at(4) * (5/9))));
        break;
    }
}
