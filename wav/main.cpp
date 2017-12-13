#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <inttypes.h>

using namespace std;

int main()
{
    int fs=8000;
    int freq;
    int A,t,i;
    cin >> freq;
    cin >> t;
    short x[t*fs];

    for(i=0;i<t*fs;i++)
    {
        x[i]=A*sin(2*M_PI*freq*i/fs);
    }

    System::Media::SoundPlayer(x);

    return 0;
}
