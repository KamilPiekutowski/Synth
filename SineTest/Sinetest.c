#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#define BUFFER_LEN 48000 * 4


/* notes and their frequencies*/
#define C4 261.63
#define C4_SHARP 277.18
#define D4 293.66
#define D4_SHARP 311.13
#define E4 329.63
#define F4 349.23
#define F4_SHARP 369.99
#define G4 392.00
#define G4_SHARP 415.30
#define A4 440.00
#define A4_SHARP 466.16
#define B4 493.88


static char *device = "default";                       //soundcard
snd_output_t *output = NULL;
float buffer [BUFFER_LEN];


int main(void)
{
    int err;
    int j,k;
              //frequency
    float fs = 48000;             //sampling frequency

    snd_pcm_t *handle;
    snd_pcm_t *handle1;
    snd_pcm_sframes_t frames;

//    printf("C4#: %s\n",C4_SHARP);

   // printf("size of double midi note table %d\n", sizeof(double) * 128);

    // ERROR HANDLING

    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);
    }

    if ((err = snd_pcm_open(&handle1, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
            printf("Playback open rror: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);
    }

    if ((err = snd_pcm_set_params(handle,
                                  SND_PCM_FORMAT_FLOAT,
                                  SND_PCM_ACCESS_RW_INTERLEAVED,
                                  1,
                                  48000,
                                  1,
                                  500000)) < 0) {
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);


    }



    float f = 50;
    float f2 = 478.5;
    float f3 = 439.5;
    // SINE WAVE
    printf("\nSine tone at %fHz\n",f);
  //  int i = 10;
  //  while(i > 1){
        float sounds = 3;
        float amp = 1/sounds;
        for (k=0; k<BUFFER_LEN; k++){

            buffer[k] = (sin(2*M_PI*f/fs*k)  * amp * .8);
            //amp -= .00011;
            if(amp < 0){
                amp = 0;
            }             //sine wave value generation
            //printf("AMP: %f",amp);

            }

       // for (j=0; j<5; j++){
       int z = 0;
       for(z = 0;z < 6;++z){
            frames = snd_pcm_writei(handle, buffer, BUFFER_LEN);
       }
            printf ("second being played");
  //sending values to sound driver
       //     }
          //  i--;
            //printf("i: %d\n",i);
   //  }

/*
   for (k=0; k<BUFFER_LEN; k++){

            buffer[k] = (sin(2*M_PI*f*2/fs*k));                 //sine wave value generation
            }

       // for (j=0; j<5; j++){
            frames = snd_pcm_writei(handle, buffer, BUFFER_LEN);

*/

    snd_pcm_close(handle);
    return 0;

}
