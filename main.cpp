#include <SFML/Audio.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pixel.h"
#include "ADSR_Envelope.h"


using namespace std;

sf::Pixel d;

//sf::Vector2f v(2.0,4.0);

//p.getPosition(v)

int main() {
    const unsigned SAMPLES = 44100;
    const unsigned SAMPLE_RATE = 44100;
    const unsigned AMPLITUDE = 30000;

    sf::Int16 raw[SAMPLES];

    const double TWO_PI = 6.28318;
    const double increment = 440./44100/2;
    double x = 0;
    for (unsigned i = 0; i < SAMPLES; i++) {
        raw[i] = AMPLITUDE * sin(x*TWO_PI);
        x += increment;
    }

    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
        std::cerr << "Loading failed!" << std::endl;
        return 1;
    }

    ADSR_Envelope e;

    e.printEnvelope();

    sf::Sound Sound;
    Sound.setBuffer(Buffer);
    Sound.setLoop(true);
    Sound.play();
    float i = 0;
    float rate = 1;
    while (1) {

        //e.GATE = true;
        //int i = e.getAmplitude();
        //Sound.setVolume(i);
        //sf::sleep(sf::milliseconds(100));
        i++;



    }
    return 0;
}
