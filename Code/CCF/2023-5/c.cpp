#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned char byte;

struct Bite
{
    byte value;
    Bite():value(0) {
        
    }
    void input() {
        byte a, b;
        cin>>a>>b;
        byte high = a >= 'a'? a-'a'+10: a-'0', low = b>='a'? b-'a'+10: b-'0';
        value = (high<<4) | low;
    }
    void print() {
        cout<<hex<<(value>>4)<<(value & 0x0f);
    }
};

struct Instream
{
    Bite *stream, *output;
    int scanner, outpoint;
    int outlength, inlength;

    Instream(int n):inlength(n) {
        stream = new Bite[inlength];
        for (int i = 0; i<inlength; i++) {
            if (i%8 == 0) getchar();
            stream[i].input();
        }
    }
    ~Instream() {
        delete[] stream;
        delete[] output;
    }
    void get_set_guide() {
        outlength = 0;
        scanner = 0;
        byte next = stream[scanner].value;
        while(true) {
            outlength += int(next& 0x7f)*pow(128, scanner);
            scanner ++;
            if (!(next >> 7)) break;
            next = stream[scanner].value;
        };
        this->output = new Bite[outlength];
    }
    void depackage() {
        outpoint = 0;
        byte now;
        int facelength, o, l;

        while (scanner < inlength) {
            now = this->stream[scanner].value;
            switch(now & 0b00000011) {
                case 0:
                    if (int(now >> 2) <= 59) {
                        facelength = (now >> 2);
                    }
                    else {
                        facelength = 0;
                        for (int i = 0; i<(now>>2)-59; i++) {
                            scanner++;
                            facelength |= (int(stream[scanner].value)<<(8*i));
                        }
                    }
                    scanner++;
                    facelength++;
                    // cout<<"f: "<<facelength<<endl;
                    for (int i = 0; i<facelength; i++) {
                        output[outpoint] = stream[scanner];
                        scanner++;
                        outpoint++;
                    }
                    break;
                case 1:
                    l = ((now & 0b00011100)>>2)+4;
                    o = (now & 0b11100000)<<3;
                    o |= int(stream[scanner+1].value);
                    scanner+=2;
                    get_lo(l, o);
                    break;
                case 2:
                    l = (now >> 2) + 1;
                    o = int(stream[scanner+1].value) | (int(stream[scanner+2].value)<<8);
                    scanner += 3;
                    get_lo(l, o);
                    break;
                case 3:
                    cout<<oct<<"Error : "<<scanner<<endl;
                    scanner++;
                    break;
            }
        }
    }
    void get_lo(int &l, int &o) {
        // cout<<"lo: "<<l<<' '<<o<<endl;
        int begin = outpoint - o;
        for (int i = 0; i<l; i++) {
            output[outpoint++] = output[begin+i%o];
        }
    }
    void out() {
        // cout<<outpoint<<endl;
        for (int i = 1; i<=outlength; i++) {
            output[i-1].print();
            if (i % 8 == 0) cout<<endl;
        }
    }
};


int main() {
    int n;
    cin>>n;

    Instream instream(n);
    instream.get_set_guide();
    instream.depackage();
    instream.out();
}