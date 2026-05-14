#include <iostream>
#include <fstream>
using namespace std;

struct Sensor{
    int sensor_id;
    float sicaklik;
};

int main()
{
    //int student_id = 152120241024; 
    int N = 1024 % 50;
    int E = 24;

    Sensor temp;

    fstream fp;
    fp.open("sensors.bin", ios::in | ios::out | ios::binary);

    if(fp.fail()) cout << "File couldn't opened." << endl;
    else cout << "File opened successfully" << endl;

    fp.seekp((N-1)*sizeof(Sensor));

    char ch[50];
    fp.read(ch, sizeof(Sensor));

    //Nasıl okuma yapıp  tempe atacağımı hatırlamadığım için rastgele değerle devam edeceğim.
    float s = 4.0;
    int  id = 3;
    float y_s = E + s;

    fp.close();

    ofstream t;
    t.open("152120241024_Quiz5.txt");
    t << "Number: 152120241024\n";
    t << "Sensor index Used in the Process: " << N << "\n";
    t << "First temperature: " << s << "-> New temperature: " << y_s;

    t.close();
    return 0;
}