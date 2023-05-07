// Map notes with their frequencies based on
// https://pages.mtu.edu/~suits/notefreqs.html
//              g    a    b    c    d    e    f    g    A  ?=Bb   B    C
int freqs[] = {196, 220, 247, 262, 294, 330, 349, 392, 440, 466, 494, 523};
String frMap = "GabcdefgA?BC";
int tempo = 20;
int switchState;

// Plays the beginning from "Pirates of the Caribbean" roughly according to
// https://www.youtube.com/watch?v=DmpJfK70dgg


char song0[16] = {'a','c','d','d','d','e','f','f','f','g','e','e','d','c','c','d'};
int time0[] =  { 4,  4,  8,  8,  4,  4,  8,  8,  4,  4,  8,  8,  4,  4,  4,  4};

char song1[15] = {'a','c','d','d','d','e','f','f','f','g','e','e','d','c','d'};
int time1[] =  { 4,  4,  8,  8,  4,  4,  8,  8,  4,  4,  8,  8,  4,  4,  3};

char song2[16] = {'a','c','d','d','d','f','g','g','g','A','?','?','A','g','A','d'};
int time2[] =  { 4,  4,  8,  8,  4,  4,  8,  8,  4,  4,  8,  8,  4,  4,  4,  8};

char song3[14] = {'d','e','f','f','g','A','d','d','f','e','e','f','d','e'};
int time3[] =  { 4,  4,  8,  8,  8,  4,  12,  4,  4,  8,  8,  4,  4,  12};

char songEnd[14] = {'d','e','f','f','g','A','d','d','f','e','e','d','c','d'};
int timeEnd[] =  { 4,  4,  8,  8,  8,  4,  12,  4,  4,  8,  8,  4,  4,  20};

char intro[16] = {'d','d','d','d','d','d','d','d','d','d','d','d','d','d','d'};
int timeIntro[] = {8,  4,  8,  4,  8,  4,  4,  4,  4,  8,  4,  8,  4,  8,  4};
int i;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(A5, INPUT);
}

void loop() {

  // check if the button pressed
  switchState = analogRead(A5);
  if (switchState == LOW) {
    //pass
  } else {

  //intro
  for (i = 0; i < 15; i++) {
    tone(2, freqs[frMap.indexOf(intro[i])], timeIntro[i]*tempo);
    delay(timeIntro[i]*2*tempo);
  }

  // first half of song
  for (i = 0; i < sizeof(song0); i++) {
    tone(2, freqs[frMap.indexOf(song0[i])], time0[i]*tempo);
    delay(time0[i]*2*tempo);
  }

  delay(15*tempo);

  for (i = 0; i < sizeof(song1); i++) {
    tone(2, freqs[frMap.indexOf(song1[i])], time1[i]*tempo);
    delay(time1[i]*2*tempo);
  }

  delay(30*tempo);

  for (i = 0; i < sizeof(song2); i++) {
    tone(2, freqs[frMap.indexOf(song2[i])], time2[i]*tempo);
    delay(time2[i]*2*tempo);
  }

  delay(15*tempo);

  for (i = 0; i < sizeof(song3); i++) {
    tone(2, freqs[frMap.indexOf(song3[i])], time3[i]*tempo);
    delay(time3[i]*2*tempo);
  }

  delay(tempo*15);


  // second half of song, mostly same identical to first one,
  // except this is from higher octave

  for (i = 0; i < sizeof(song0); i++) {
    tone(2, freqs[frMap.indexOf(song0[i])]*2, time0[i]*tempo);
    delay(time0[i]*2*tempo);
  }

  delay(tempo*15);

  for (i = 0; i < sizeof(song1); i++) {
    tone(2, freqs[frMap.indexOf(song1[i])]*2, time1[i]*tempo);
    delay(time1[i]*2*tempo);
  }

  delay(30*tempo);

  for (i = 0; i < sizeof(song2); i++) {
    tone(2, freqs[frMap.indexOf(song2[i])]*2, time2[i]*tempo);
    delay(time2[i]*2*tempo);
  }

  delay(15*tempo);

  for (i = 0; i < sizeof(songEnd); i++) {
    tone(2, freqs[frMap.indexOf(songEnd[i])]*2, timeEnd[i]*tempo);
    delay(timeEnd[i]*2*tempo);
  }
  }
}
