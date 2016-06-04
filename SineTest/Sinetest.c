#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#define BUFFER_LEN 48000 * 8

static char *device = "default";                       //soundcard
snd_output_t *output = NULL;
float buffer [BUFFER_LEN];


int main(void)
{
    int err;
    int j,k;

    int f = 440;                //frequency
    int fs = 48000;             //sampling frequency

    snd_pcm_t *handle;
    snd_pcm_sframes_t frames;


    // ERROR HANDLING

    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
            printf("Playback open error: %s\n", snd_strerror(err));
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
    int f2 = 523;
    int f3 = 659;
    // SINE WAVE
    printf("\nSine tone at %dHz\n",f);
  //  int i = 10;
  //  while(i > 1){
        float sounds = 3;
        float amp = 1/sounds;
        for (k=0; k<BUFFER_LEN; k++){

            buffer[k] = ((sin(2*M_PI*f/fs*k) + sin(2*M_PI*f2/fs*k) + sin(2*M_PI*f3/fs*k)) * amp);
            amp -= .000001;
            if(amp < 0){
                amp = 0;
            }             //sine wave value generation
            //printf("AMP: %f",amp);

            }

       // for (j=0; j<5; j++){
            frames = snd_pcm_writei(handle, buffer, BUFFER_LEN);    //sending values to sound driver
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
