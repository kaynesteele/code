#include <iostream>
#include <cstring>
#include <string>
//#include <fstream>
#include "sObj.h"

using namespace std;


int main(int argc, char **argv)
{
    StockClass s[argc];
    float *test, ma15=0.0, ma50=0.0, ma100=0, latest=0.0, stoK=0.0, stoD=0.0;
    int x=0, count=0, vol=0;
    float relativeVol=0;

    for(int i=1; i<argc; i++)
    {
        x=i-1;
        s[x].readFile(argv[i]);

        //s[x].setName(argv[i]);
        //s[x].setData(test);

        ma15 = s[x].calcMovingAvg(15);
        ma50 = s[x].calcMovingAvg(50);
        ma100 = s[x].calcMovingAvg(100);
        latest = s[x].getLatestData();


        stoK=s[x].getStoK();
        stoD=s[x].getStoD();
        vol=s[x].getVol();
        relativeVol = s[x].getRelativeVol();

        
        if(ma15 > ma50)
        {
            if(latest > ma100)//if(latest > ma100 && latest > ma50)
            {
                if(ma50 > ma100)
                {
                    if(latest > 06.0 && latest < 50.0)
                    {
                        if(stoK > stoD && stoK < 30)//if(latest < highPer && latest > lowPer)
                        {
                            if(vol > 300000)
                            {
                                    cout << s[x].getName() << endl;
                                    cout << "Latest Price: " << latest << endl;
                                    cout << "Volume: " << vol << endl;
                                    cout << "Relative Volume: " << relativeVol << endl;
                                    cout << "MA15: " << ma15 << endl;
                                    cout << "MA50: " << ma50 << endl;
                                    cout << "MA100: " << ma100 << endl;
                                    cout << "%K: " << stoK << endl;
                                    cout << "%D: " << stoD << endl  << endl;
                                    count++;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
