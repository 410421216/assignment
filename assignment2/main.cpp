#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::fstream;

typedef struct  WAV_HEADER{
    char                RIFF[4];        // RIFF Header      Magic header
    unsigned long       ChunkSize;      // RIFF Chunk Size
    char                WAVE[4];        // WAVE Header
    char                fmt[4];         // FMT header
    unsigned long       Subchunk1Size;  // Size of the fmt chunk
    unsigned short      AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
    unsigned short      NumOfChan;      // Number of channels 1=Mono 2=Sterio
    unsigned long       SamplesPerSec;  // Sampling Frequency in Hz
    unsigned long       bytesPerSec;    // bytes per second
    unsigned short      blockAlign;     // 2=16-bit mono, 4=16-bit stereo
    unsigned short      bitsPerSample;  // Number of bits per sample
    char                Subchunk2ID[4]; // "data"  string
    unsigned long       Subchunk2Size;  // Sampled data length

}wav_hdr;

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
