#include <string>
#include <iostream>
#include <fstream>

class StockClass
{
    private:
        std::string stockName;
        float *stockPrices, latestPrice;
        float ma15, ma50,ma100,*stoKArr, *stoDArr;
        int *volArr;

    public:
        StockClass() { stockName = "NULL";  stockPrices = new float[1001];stoDArr=new float[1101]; stoKArr=new float[1101]; };
        ~StockClass() { delete[] stoDArr; delete[] stoKArr; };
        void readFile(std::string);
        void setName(std::string);
        std::string getName();
        void setData(float *);
        void getData(int);
        float calcMovingAvg(int);
        float getMovingAvg(int);
        void setMovingAvg(int,float);
        float displayMovingAvgFifteen();
        float displayMovingAvgFifty();
        float getLatestData();
        float getLowest(int, int);
        float getHighest(int, int);
        float calcStoK(int, int); 
        float calcStoD();
        void setStoK(float*);
        void setStoD(float*);
        float getStoK();
        float getStoD();
        float getStoK(int);
        float getStoD(int);
        void setVol(int*);
        int getVol();
        float getRelativeVol();

};
