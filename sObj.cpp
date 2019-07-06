#include "sObj.h"

void StockClass::*readFile(std::string fileName)
{
    float data, stoK, stoD;
    int i=0, vol;
    std::ifstream inFile;
    stockName=fileName;

    inFile.open(fileName);

    while(inFile.good())
    {
        inFile >> data >> stoK >> stoD >> vol;
        stockPrices[i] = data;
        stoKArr[i] = stoK;
        stoDArr[i] = stoD;
        volArr[i] = vol;
        ++i;
    }
    inFile.close();
   
}


void StockClass::setName(std::string name)
{
    stockName=name;
}

std::string StockClass::getName()
{
    return stockName;
}

void StockClass::setData(float *stockData)
{
    stockPrices = stockData;
}

void StockClass::getData(int x)
{
    for(int i=0; i<x; i++)
    {
        std::cout << i+1 << ": " << stockPrices[i] << std::endl;
    }
    latestPrice=stockPrices[0];
}

void StockClass::setMovingAvg(int x, float y)
{
    switch(x)
    {
        case 15:
            ma15=y;
            break;
        case 50:
            ma50=y;
            break;
        case 100:
            ma100=y;
            break;
    } 
}
float StockClass::calcMovingAvg(int x)
{
    float movingAvg=0.0;

    for(int i=x-1; i>=0; i--)
    {
        movingAvg+=(stockPrices[i]);        
    } 

    setMovingAvg(x,movingAvg/float(x));
    return (movingAvg / float(x)); 
}
float StockClass::getMovingAvg(int x)
{
    switch(x)
    {
        case 15:
            return ma15;
            break;
        case 50:
            return ma50;
            break;
        case 100:
            return ma100;
            break;
    } 
}

float StockClass::getLatestData()
{
    return stockPrices[0];
}

float StockClass::getLowest(int x, int y)
{
    float lowest=100.0;
    for(int i=x; i<=y; i++)
    {
        if(stockPrices[i] < lowest) lowest=stockPrices[i];
    } 
    return lowest;
}

float StockClass::getHighest(int x, int y)
{
    float highest=0.0;
    for(int i=x; i<=y; i++)
    {
        if(stockPrices[i] > highest) highest=stockPrices[i];
    } 
    return highest;

}

float StockClass::calcStoK(int x, int y)
{
    return float((stockPrices[x] - getLowest(x, y) ) / ( getHighest(x, y) - getLowest(x,y)) * 100); 
}

float StockClass::calcStoD()
{
    stoArr = new float[3];    
    float stoD = 0.0;
    stoArr[0] = calcStoK(0, 13);
    stoArr[1] = calcStoK(1, 14);
    stoArr[2] = calcStoK(2, 15);
    for(int i = 0; i < 3; i++)
    {
        stoD+=stoArr[i];
    }
    return (stoD/3);
}

void StockClass::setStoK(float *_stoK)
{
    stoKArr = _stoK;
}

void StockClass::setStoD(float *_stoD)
{
    stoDArr = _stoD;
}

float StockClass::getStoK()
{
    return stoKArr[0];
}

float StockClass::getStoD()
{
    return stoDArr[0];
}
float StockClass::getStoK(int x)
{
    return stoKArr[x];
}
float StockClass::getStoD(int x)
{
    return stoDArr[x];
}

void StockClass::setVol(int *_vol)
{
    volArr=_vol;

}
int StockClass::getVol()
{
    return volArr[0];
}   

float StockClass::getRelativeVol()
{
    float relVol=0;

    for(int i=0; i<100; i++)
    {
        relVol += volArr[i];    
    }
    relVol = relVol / 100;

    return (volArr[0] / relVol);  
}


