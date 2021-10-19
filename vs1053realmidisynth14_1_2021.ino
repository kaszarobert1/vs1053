//vs1053 midi constans
//#define VS1053_BANK_DEFAULT 0x00
//#define VS1053_BANK_DRUMS1 0x78
//#define VS1053_BANK_DRUMS2 0x7F
#define VS1053_BANK_MELODY 0x79
//#define VS1053_GM1_SOUND 27
#define MIDI_NOTE_ON 0x90
#define MIDI_NOTE_OFF 0x80
#define MIDI_CHAN_MSG 0xB0
#define MIDI_CHAN_BANK 0x00
//#define MIDI_CHAN_VOLUME 0x07
//#define MIDI_CHAN_PAN 0x0A
#define MIDI_CHAN_BANDRAGE 0x06
//#define MIDI_CHAN_EXP 0x0B
#define MIDI_CHAN_PITCH 0xE0
//#define MIDI_EFFECT_CNTRL 0x0C
//#define MIDI_EFFECT_LEVEL 0x5B
#define MIDI_EFFECT_CNTRL 0x0C
#define MIDI_EFFECT_LEVEL 0x5B
#define MIDI_CHAN_PROGRAM 0xC0
#define MIDI_CHAN_EVERYNOTE_OFF 0x78

//Drumset sound
#define lab 36
#define lab2 35
#define pergo 38
#define pergo2 36
#define cin 42

//horizontal menu
#define maxmenupoz 10
#define maxprog 127

//Multiplexer adress setting
#define multiadress0 3
#define multiadress1 4
#define multiadress2 5
#define multiadress3 10
//multiplexer out
#define analogpin2 2
#define analogpin3 3
//analog potenciometer input
//pich whel
#define analogpin1 1
//poti2
#define analogpin6 6
//poti1
#define analogpin7 7
#define cvspin A0
#define framemax 8192

const byte drumtomb[8][4] = {
  { B11111111, B11111111, B11111111, B11111111 },
  { B10101010, B10101010, B10101010, B10101010 },
  { B01010101, B01010101, B01010101, B01010101 },
  { B10001000, B10001000, B10001000, B10001000 },
  { B00100100, B10010010, B01001001, B00100100 },
  { B00000010, B00000010, B00000010, B00010000 },
  { B00010001, B00000001, B00010001, B00001000 },
  { B10000000, B10000000, B10000000, B10000000 }
};

//special caracters
const byte vonal0[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

const byte vonal1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};
const byte vonal2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
const byte vonal3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
const byte vonal4[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};
const byte vonal5[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
const byte vonal6[8] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
const byte vonal7[8] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};



//keyboard
int igombok;
int igombokelozo;
int igombok2;
int igombokelozo2;
bool keymode = true;
bool shift = false;
bool shift2 = false;
bool arpon = false;
bool dobon = false;
bool cvs = false;
byte velocity = 127;
byte valtozaskey = 60;
byte prog = 104;
byte menupoz = 1;
byte utolsohang = 0;
byte utolsovelocity = 0;
byte arpeggionotenumber = 32;
struct note {
  byte key;
  byte velocity;
  byte chan;
};
struct note2 {
  byte key;
  byte velocity;
};
//midi chan 2 note on for arpeggio
note2 utolsohangok[32];
//other midi chan note on 1,3,4,5,6,7,8,9,10,etc. for arpeggio
byte utolsohangokchan = 1;
note utolsohangok2[32];
byte negyed = 0;
byte black = 1;
byte sebesseg = 4;
note2 utolsoelottielottihang;
note utolsoelottielottihang2;
byte chan = 0;
byte drumchan = 9;
byte drumset = 32;
byte comb = 1;
String combiname = "Combiinit";
byte page = 1;
int trans = 0; //!!!
int hang = 0;
int dinamika = 0;
int framearpeggio = 0;
int elozoframearpeggio;
int pichwhel = 0;
int pich = 0; //!!!
int elozopich = 0;
int poti1 = 0;
int poti2 = 0;
int kalibraltpichwhel = 0;
int kalibraltpichwhel2 = 0;
int kalibraltpoti1 = 0;
int kalibraltpoti2 = 0;
const byte erzekenyseg = 10;
unsigned long elozoido = 0;
unsigned long ido;
unsigned long elozohangtime;
unsigned int bpm = 120;
unsigned int frame = 0;
unsigned int BPMETALON = 7320;
unsigned int pichido = BPMETALON / bpm;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SPI.h>
#define VS_XCS    6 // Control Chip Select Pin (for accessing SPI Control/Status registers)
#define VS_XDCS   7 // Data Chip Select / BSYNC Pin
#define VS_DREQ   2 // Data Request Pin: Player asks for more data
#define VS_RESET  8 //Reset is active low
#define VS_WRITE_COMMAND 0x02
#define VS_READ_COMMAND 0x03
//sdcard
#include <vs1053_SdFat.h>
SdFat SD;
vs1053 vs;
#define SD_CS_PIN 9
File myFile;
char fajlnevkar[10];


unsigned int VSReadregister(unsigned char reg)
{
  unsigned char inHigh;
  unsigned char inLow;
   while (!digitalRead(VS_DREQ)) ; //Wait for DREQ to go high indicating IC is available
  digitalWrite(VS_XCS, LOW); //Select control
  //SCI consists of instruction byte, address byte, and 16-bit data word.
  SPI.transfer(VS_READ_COMMAND); //Read instruction
  SPI.transfer(reg);
  inHigh=SPI.transfer(0xff);
  inLow=SPI.transfer(0xff);
  while (!digitalRead(VS_DREQ)) ; //Wait for DREQ to go high indicating command is complete
  digitalWrite(VS_XCS, HIGH); //Deselect Control
  return (unsigned short)(inHigh<<8)+inLow;
}

void VSWriteRegister(unsigned char addressbyte, unsigned char highbyte, unsigned char lowbyte) {
  while (!digitalRead(VS_DREQ)) ; //Wait for DREQ to go high indicating IC is available
  digitalWrite(VS_XCS, LOW); //Select control
  //SCI consists of instruction byte, address byte, and 16-bit data word.
  SPI.transfer(VS_WRITE_COMMAND); //Write instruction
  SPI.transfer(addressbyte);
  SPI.transfer(highbyte);
  SPI.transfer(lowbyte);
  while (!digitalRead(VS_DREQ)) ; //Wait for DREQ to go high indicating command is complete
  digitalWrite(VS_XCS, HIGH); //Deselect Control
}

const unsigned short sVS1053b_Realtime_MIDI_Plugin[28] = {
  0x0007, 0x0001, 0x8050, 0x0006, 0x0014, 0x0030, 0x0715, 0xb080,
  0x3400, 0x0007, 0x9255, 0x3d00, 0x0024, 0x0030, 0x0295, 0x6890,
  0x3400, 0x0030, 0x0495, 0x3d00, 0x0024, 0x2908, 0x4d40, 0x0030,
  0x0200, 0x000a, 0x0001, 0x0050,
};

/*
  void VSLoadUserCodeSD()
  {
  vs.ADMixerLoad("rtmidi.053") ;//rtmidistart.plg
  }
*/
void VSLoadUserCode(void) {
  int i = 0;
  while (i < sizeof(sVS1053b_Realtime_MIDI_Plugin) / sizeof(sVS1053b_Realtime_MIDI_Plugin[0])) {
    unsigned short addr, n, val;
    addr = sVS1053b_Realtime_MIDI_Plugin[i++];
    n = sVS1053b_Realtime_MIDI_Plugin[i++];
    while (n--) {
      val = sVS1053b_Realtime_MIDI_Plugin[i++];
      VSWriteRegister(addr, val >> 8, val & 0xFF);
    }
  }
}

void setup() {
  pinMode(cvspin, OUTPUT);
  Wire.setClock(1000000);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, vonal0);
  lcd.createChar(1, vonal1);
  lcd.createChar(2, vonal2);
  lcd.createChar(3, vonal3);
  lcd.createChar(4, vonal4);
  lcd.createChar(5, vonal5);
  lcd.createChar(6, vonal6);
  lcd.createChar(7, vonal7);
  lcd.setCursor(0, 0);
  lcd.print(" Arpeggio Synth");
  delay(700);
  lcd.setCursor(0, 1);
  lcd.print("Controller & DSP");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Firmware:");
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("Midisynt_14.1");
  delay(800);
  lcd.clear();
  // filewrite();
  fileread();
  //randominit();
  //midi freq serial
  Serial.begin(31250);
   //Serial.begin(57600);
  Serial.println("\n******\n");
  spiinit();
  lcdkiir(100);
  vezerlokiir(3);

//1111 1011 1110 1000 15-0.bit clockf sci regiszter...
// VSWriteRegister(0x02,B00000000,B00000000);  // SCI basstreble register 0x02 good 
//VSWriteRegister(0x00,B11001000,B000000); // Half Freq ->The Base SCIMode: B0100100000000000 

//byte highbyte=10011011;
//byte lowhbyte=11101000;
//Serial.println(highbyte);
//Serial.println(lowhbyte);
//set 66MHz
// scmulti=4=100 scadd=3=11  scfreq=B01111101000 ==  1001101111101000
 VSWriteRegister(0x03, B10011011,B11101000);
 VSWriteRegister(0x1e03, B00000000,B00001111);
 
/*
Serial.println("regiszterművelet");
int data=VSReadregister(0x3);
Serial.println(data);
*/
utolsoelottielottihang.key = 0;
}

void loop() {
  if (frame <= framemax) {
    frame++;
  } else {
    frame = 0;
  }
  if (frame % 64 == 0) {
    potiread();
    programvalt(); 
  }
  keyscan();
  // pichbandcont();
  arpeggio();
}


void spiinit() {
  //init vs1053 realtime midi mode
  pinMode(VS_DREQ, INPUT);
  pinMode(VS_XCS, OUTPUT);
  pinMode(VS_XDCS, OUTPUT);
  digitalWrite(VS_XCS, HIGH); //Deselect Control
  digitalWrite(VS_XDCS, HIGH); //Deselect Data
  pinMode(VS_RESET, OUTPUT);
  digitalWrite(VS_RESET, LOW); //Put VS1053 into hardware reset
  pinMode(10, OUTPUT); //Pin 10 must be set as an output for the SPI communication to work
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  //From page 12 of datasheet, max SCI reads are CLKI/7. Input clock is 12.288MHz.
  //Internal clock multiplier is 1.0x after power up.
  //Therefore, max SPI speed is 1.75MHz. We will use 1MHz to be safe.
  SPI.setClockDivider(SPI_CLOCK_DIV8); //Set SPI bus speed to 1MHz (16MHz / 16 = 1MHz)
  SPI.transfer(0xFF); //Throw a dummy byte at the bus
  delayMicroseconds(1);
  digitalWrite(VS_RESET, HIGH); //Bring up VS1053
  //VSLoadUserCodeSD();
  VSLoadUserCode();
  keyscaninit();
 // talkMIDI(0xB9, 0, 0x7F);
 // talkMIDI(0xB9, 0x07, 127);
  midiSetChannelBank(chan, VS1053_BANK_MELODY);
  midiSetInstrument(chan, prog);
 // midiSetReverbType(chan, 127);
 // midiSetReverbLevel(chan, 64);
}

void filewrite()
{
  if (!SD.begin(SD_CS_PIN)) {
    while (1);
  }
  String eleje = "set";
  String vege = ".txt";
  String filename = eleje + comb + vege;
  //String filename="set1.txt";
  filename.toCharArray(fajlnevkar, 10);
  SD.remove(fajlnevkar);
  myFile = SD.open(fajlnevkar, FILE_WRITE);

  if (myFile) {
    // myFile.print(255);
    char c;
    //prog                          drumset                       trans +100                      chan                       drumchan                        sebesseg                         bpm                       arpeggionotenumber                       pich +100
    c = prog; myFile.print(c); c = drumset; myFile.print(c); c = trans + 100; myFile.print(c); c = chan; myFile.print(c); c = drumchan;  myFile.print(c); c = sebesseg;  myFile.print(c); c = bpm;  myFile.print(c); c = arpeggionotenumber;  myFile.print(c); c = pich + 100;  myFile.print(c);
    /*
      for (int i = 0; i < arpeggionotenumber; i++)
      {
       c = utolsohangok[i].key;
       myFile.print(c);
       c = utolsohangok[i].velocity;
       myFile.print(c);
       c = utolsohangokchan;
       myFile.print(c);
       c = utolsohangok2[i].key;
       myFile.print(c);
       c = utolsohangok2[i].velocity;
       myFile.print(c);
       c = utolsohangok2[i].chan;
       myFile.print(c);
      }
    */
  }
  myFile.close();
  // SPI.begin();
  // spiinit();
}


void randominit()
{
  prog = random(1, 127);
  drumset = random(1, 127);
  trans = random(-24, 24);
  sebesseg = random(4);
  bpm = random(0, 255);
  arpeggionotenumber == random(0, 32);
  // pich=random(-10, 10);
  for (int i = 0; i < arpeggionotenumber; i++)
  {
    utolsohangok[i].key = random(32, 64);
    utolsohangok[i].velocity = random(67, 127);
    utolsohangokchan = 1;
  }
  for (int i = 0; i < arpeggionotenumber; i++)
  {
    utolsohangok2[i].key = random(32, 64);
    utolsohangok2[i].velocity = random(67, 127);
    utolsohangok2[i].chan = 3;
  }
}

void fileread()
{
  if (!SD.begin(SD_CS_PIN)) {
    while (1);
  }
  String eleje = "set";
  String vege = ".txt";
  String filename = eleje + comb + vege;
  //String filename="set1.txt";
  filename.toCharArray(fajlnevkar, 10);
  myFile = SD.open(fajlnevkar);
  if (myFile)
  {
    while (myFile.available())
    {
      // myFile.read();
      prog = myFile.read();
      drumset = myFile.read();
      trans = myFile.read() - 100;
      chan = myFile.read();
      drumchan = myFile.read();
      sebesseg = myFile.read();
      bpm = myFile.read();
      arpeggionotenumber = myFile.read();
      pich = myFile.read() - 100;
      /*
        for (int i = 0; i < arpeggionotenumber; i++)
        {
        utolsohangok[i].key = myFile.read();
        utolsohangok[i].velocity = myFile.read();
        utolsohangokchan = myFile.read();
        utolsohangok2[i].key = myFile.read();
        utolsohangok2[i].velocity = myFile.read();
        utolsohangok2[i].chan = myFile.read();
        }
      */

    }

    myFile.close();

  }
  //midiSetInstrument(chan, prog);
  //SPI.begin();
  //spiinit();
}

byte eqstep=0;
void eqset() {
  byte basslevel;
  byte bassfreq;
  byte highlevel;
  byte highfreq;
  if (eqstep <= 15) {
    basslevel = eqstep;
  } else {
    basslevel = 15;
  }
  
  if (eqstep < 15) {
    bassfreq = 16 - eqstep;
  } else {
    bassfreq = 1;
  }
  if (eqstep <= 15) {
    highlevel = 0;
  } else {
    highlevel = eqstep - 15;
  }
  if (eqstep < 15) {
    highfreq = 1;
  } else {
    highfreq = eqstep - 13;
  }
  highlevel=highlevel+8;
  // int vol = MP3player.getVolume();
  //MP3player.setVolume(vol, vol);
    byte b1= 16*basslevel+bassfreq;
      byte b2=16*highlevel+highfreq;    
      VSWriteRegister(0x02,b2,b1);
    // unsigned int data=VSReadregister(0x02);
    
//Serial.println("regiszterművelet");
//Serial.println(data,BIN);
//Serial.println(eqstep);

 /*
  MP3player.setBassFrequency(bassfreq * 10);
  MP3player.setBassAmplitude(basslevel);
  MP3player.setTrebleFrequency(highfreq * 1000);
  MP3player.setTrebleAmplitude(highlevel);
  */
}

void arpeggio()
{
  ido = micros() >> 6;
  if (elozoido > ido)
  {
    elozoido = 0;
  }
  unsigned long kulonbseg = (unsigned long)ido - elozoido;
  //-2 is calibral bpm 120bpm=244 122bpm=236 128bpm=212
  if (kulonbseg > pichido)
  {
    elozoido = ido - kulonbseg + pichido;
    negyed++;
  
   
    if (negyed % 6 == 0)
    {
      midiclock();
    }
    // if (negyed % (sebesseg *8) == 0)
    if (negyed % (sebesseg << 3) == 0)
    {

      negyed = 0;
     
      utolsoelottielottihang = utolsohangok[framearpeggio];
      utolsoelottielottihang2 = utolsohangok2[framearpeggio];
      elozoframearpeggio = framearpeggio;
      if (framearpeggio > arpeggionotenumber - 1)
      {
        //  midiclockstop();
        // midiclockstart();
        framearpeggio = 0;

      }
      else
      {
        framearpeggio++;
      }
     //  eqstep=framearpeggio;
   // eqset();
      if (dobon)
      {
        dobcontrol();
      }
      hang = utolsohangok[framearpeggio].key;
      dinamika = utolsohangok[framearpeggio].velocity;
      byte chantmp = utolsohangokchan;
      if (arpon)
      {
        if (utolsoelottielottihang.key != 0)
        {
          noteOff(utolsohangokchan, utolsoelottielottihang.key, 0);
        }
        if (dinamika != 0)
        {
          noteOn(chantmp, hang, dinamika, 0);
        }
      }
      hang = utolsohangok2[framearpeggio].key;
      dinamika = utolsohangok2[framearpeggio].velocity;
      chantmp = utolsohangok2[framearpeggio].chan;
      if (arpon)
      {
        if (utolsoelottielottihang2.key != 0)
        {
          noteOff(utolsoelottielottihang2.chan, utolsoelottielottihang2.key, 0);
        }
        if (dinamika != 0) {
          noteOn(chantmp, hang, dinamika, 0);
        }
        //  cvscontrol();
      }
    }
  }
}

void dobcontrol() {
  byte drumdinamika = 127;
  int labnumber = (drumset >> 3) & 7;
  int cinnumber = drumset & 7;
  int pergonumber = ((drumset % 6) + 2) ;
  byte dobindex = framearpeggio >> 3;
  byte cinindex = framearpeggio >> 3;
  byte pergoindex = framearpeggio >> 3;
  byte elozodobindex = elozoframearpeggio >> 3;
  byte elozocinindex = elozoframearpeggio >> 3;
  byte elozopergoindex = elozoframearpeggio >> 3;
  byte elozosplit = elozoframearpeggio & 7;
  byte split = framearpeggio & 7;
  lcdkiir(6);
  //doboff
  if (bitRead(drumtomb[labnumber][elozodobindex], elozosplit)) {
    talkMIDI( 0x80 | drumchan, lab,  drumdinamika);

    if (elozodobindex % 2 == 0) {
      talkMIDI( 0x80 | drumchan, lab2,  drumdinamika);
      noteOnMIDI(0x80 | drumchan,  lab2,  drumdinamika);
    } else {
      talkMIDI( 0x80 | drumchan, lab,  drumdinamika);
      noteOnMIDI(0x80 | drumchan,  lab,  drumdinamika);
    }
  }
  if (bitRead(drumtomb[cinnumber][elozocinindex], elozosplit)) {
    talkMIDI( 0x80 | drumchan, cin,  drumdinamika);
    noteOnMIDI(0x80 | drumchan,  cin,  drumdinamika);
  }

  if (bitRead(drumtomb[pergonumber][elozopergoindex], elozosplit)) {
    talkMIDI( 0x80 | drumchan, pergo,  drumdinamika);
    noteOnMIDI(0x80 | drumchan,  pergo,  drumdinamika);
    noteOnMIDI(0x80 | drumchan,  pergo2,  drumdinamika);
  }

  //dobon
  if (bitRead(drumtomb[labnumber][dobindex], split)) {
    talkMIDI( 0x90 | drumchan, lab,  drumdinamika);
    if (dobindex % 2 == 0) {
      noteOnMIDI(0x90 | drumchan,  lab2,  drumdinamika);
    } else
    {
      noteOnMIDI(0x90 | drumchan,  lab,  drumdinamika);
    }
  }
  if (bitRead(drumtomb[cinnumber][cinindex], split)) {
    talkMIDI( 0x90 | drumchan, cin,  drumdinamika);
    noteOnMIDI(0x90 | drumchan,  cin,  drumdinamika);
  }
  if (bitRead(drumtomb[pergonumber][pergoindex], split)) {
    talkMIDI( 0x90 | drumchan, pergo,  drumdinamika);
    noteOnMIDI(0x90 | drumchan,  pergo,  drumdinamika);
    noteOnMIDI(0x90 | drumchan,  pergo2,  drumdinamika);
  }
}
/*
  void cvscontrol() {
  if (cvs) {
    cvs = false;  digitalWrite(cvspin, LOW );
  } else {
    cvs = true;
    digitalWrite(cvspin, HIGH );
  }
  }
*/
void arpeggiopich(int eltol) {
  midieverynoteoff(0);
  if (elozopich != pich) {
    for (int i = 0; i < arpeggionotenumber; i++)
    {
      utolsohangok[i].key = utolsohangok[i].key-elozopich+eltol;
      utolsohangok2[i].key =utolsohangok2[i].key- elozopich+eltol;    
    }
    elozopich = pich;
  }
  midieverynoteoff(0);
}

void arpeggiopich2(int eltol) {
  for (int i = 0; i < arpeggionotenumber; i++) {
    utolsohangok[i].key += eltol;
    utolsohangok2[i].key += eltol;
  }
}

void programvalt() {
  // if (gombok2[2])
  //INCREMENT Button!!!--------------------------------
  if (bitRead(igombok2, 2))
  {
    switch (page)
    {
      case 0:
        filewrite();
        page = 1;
        lcdkiir(100);
        break;
      case 1:
        switch (menupoz) {
          case 1:
            if (prog >= maxprog) {
              prog = 0;
            }
            else {
              prog++;
            }
            midiSetInstrument(chan, prog);
            break;
          case 2:
            trans++;
            break;
          case 3:
            utolsohangnoteoff();
            pich++;
            arpeggiopich2(1);
            break;
          case 4:
            bpm++;
            pichido = BPMETALON / bpm;
            break;
          case 5:
            sebesseg++;
            lcdkiir(5);
            break;
          case 6:
            drumset++;
            break;
          case 7:
            if (arpeggionotenumber < 32)
            {
              arpeggionotenumber++;
            }
            break;
          case 8:
            if (chan < 15) {
              chan++;
            }
            break;
        }
        lcdkiir(menupoz);
        break;
      case 2:
        comb++;
        combiload();
        break;
    }
  }

  //if (gombok2[1])
  //DECREMENT Button!!!-------------------
  if (bitRead(igombok2, 1))
  {
    switch (page)
    {
      case 0:
        page = 1;
        lcdkiir(100);
        break;
      case 1:
        switch (menupoz)
        {
          case 0:
            break;
          case 1:
            if (prog == 0) {
              prog = maxprog;
            } else {
              prog--;
            }
            midiSetInstrument(chan, prog);
          //  midiSetReverbType(chan, 13);
           // midiSetReverbLevel(chan, 64);
            break;
          case 2:
            utolsohangnoteoff();
            trans--;
            break;
          case 3:
            pich--;
            utolsohangnoteoff();
            arpeggiopich2(-1);
            break;
          case 4:
            bpm--;
            pichido = BPMETALON / bpm;

            break;
          case 5:
            if (sebesseg > 1) {
              sebesseg --;
            }
            break;
          case 6:
            drumset--;
            break;
          case 7:
            arpeggionotenumber--;

            break;
          case 8:
            if (chan > 0)
            {
              chan--;
            }
            break;
        }
        lcdkiir(menupoz);
        break;
      case 2:
        comb--;
        combiload();
        break;

    }
  }
  // if (gombok2[3])
  //RED Button!!!----------------------
  if (bitRead(igombok2, 3))
  {
    if (arpon) {
      arpon = false;
      dobon = false;
      // midiclockstop();
      midieverynoteoff(0);
      vezerlokiir(2);
    } else {
      // midiclockstart();
      arpon = true;
      dobon = true;
      midieverynoteoff(0);

      vezerlokiir(2);
    }
  }

  // if (gombok2[5])
  //BLUE Button!!!--------------------
  if (bitRead(igombok2, 5))
  {
    if (menupoz >= maxmenupoz) {
      menupoz = 0;
    } else
    {
      menupoz++;
      lcdvillog();
    }
  }

  //if (gombok2[4])
  //ORANGE Button
  if (bitRead(igombok2, 4))
  {
    utolsohangnoteoff();
    for (int i = 0; i <= arpeggionotenumber; i++)
    {
      if (chan == 1) {
        utolsohangok[i].key = 0;
        utolsohangok[i].velocity = 0;
        //        utolsohangok[i].chan = 0;
      } else {
        utolsohangok2[i].key = 0;
        utolsohangok2[i].velocity = 0;
        utolsohangok2[i].chan = 0;
      }
    }


  }
  // if (!gombok2[4])
  if (!bitRead(igombok2, 4))
  {
  }
  //if (gombok2[6])
  //BLACKButton
  if (bitRead(igombok2, 6) && !bitRead(igombok2, 2) )
  {
    if (black == 1)
    {
      keymode = false;
      black = 0;
      vezerlokiir(3);
      vezerlokiir(2);
    }
    else
    {
      black = 1;
      keymode = true;
      vezerlokiir(3);
    }
  }
  //BLACK+INC Button
  if (bitRead(igombok2, 6) && bitRead(igombok2, 2))
  {
    if (page < 2) {
      page++;
    }
    lcdkiir(100);
  }

  //BLACK+DEC Button
  if (bitRead(igombok2, 6) && bitRead(igombok2, 1))
  {
    if (page > 0) {
      page--;
    }
    lcdkiir(100);
  }
}

void combiload()
{
  /*
    for   (int i=0;i<16;i++)
    {
    midieverynoteoff(i);
    }*/

  utolsohangnoteoff();
  fileread();
  lcdkiir(100);
}

void utolsohangnoteoff()
{
  if (utolsoelottielottihang2.key != 0)
  {
    noteOff(utolsohangokchan, utolsohangok[framearpeggio].key, utolsohangok[framearpeggio].velocity);
  }
  if (utolsoelottielottihang.key != 0)
  {
    noteOff(utolsohangokchan, utolsohangok[framearpeggio].key, utolsohangok[framearpeggio].velocity);
  }
}

void potiread() {
  int pichwhelmost = analogRead(analogpin1);
  int poti1most = analogRead(analogpin7);
  int poti2most = analogRead(analogpin6);
  if (abs(pichwhelmost - pichwhel) > erzekenyseg) {
    pichwhel = pichwhelmost;
    kalibraltpichwhel = pichwhel >> 3;
    if (kalibraltpichwhel < 0) {
      kalibraltpichwhel = 0;
    }
    if (kalibraltpichwhel > 127) {
      kalibraltpichwhel = 127;
    }
    kalibraltpichwhel2 = 127 - kalibraltpichwhel;
    lcdkiir(11);
    potivaltozas(1);
  }
  if (abs(poti1most - poti1) > erzekenyseg) {
    poti1 = poti1most;
    kalibraltpoti1 = poti1 / 8;
    if (kalibraltpoti1 < 0) {
      kalibraltpoti1 = 0;
    }
    if (kalibraltpoti1 > 127) {
      kalibraltpoti1 = 127;
    }
    lcdkiir(9);
    menupoz = kalibraltpoti1 / 16 + 1;
    if (menupoz == 0) {
      menupoz = 1;
    }
    lcdvillog();
  }
  if (abs(poti2most - poti2) > erzekenyseg) {
    poti2 = poti2most;
    kalibraltpoti2 = poti2 / 8;
    if (kalibraltpoti2 < 0) {
      kalibraltpoti2 = 0;
    }
    if (kalibraltpoti2 > 127) {
      kalibraltpoti2 = 127;
    }

    if (menupoz == 6) {
      if (kalibraltpoti2 < 80) {
        if (drumset > 0) {
          drumset--;
        } else
        {
          drumset = 255;
        }
      }
      if (kalibraltpoti2 > 110) {
        if (drumset < 256) {
          drumset++;
        } else
        {
          drumset = 0;
        }
      }
      //drumset = kalibraltpoti2 / 2 - 10;
      lcdkiir(6);
      lcdkiir(10);
    }
  }
}

void potivaltozas(byte potinumber) {
  //Serial.println(menupoz);
  if (potinumber == 1) {
    switch (page) {
      case 0:
        break;
      case 1:
        switch (menupoz)
        {
          case 1:
            if (prog != kalibraltpichwhel2)
            {
              prog = kalibraltpichwhel2;
              midiSetInstrument(chan, prog);
            }
            break;
          case 2:
            if ( kalibraltpichwhel2 / 2 > 48)
            {
              trans = 24;
            } else
            {
              trans = kalibraltpichwhel2 / 2 - 24;
            }
            break;
          case 3:
            if (pich != kalibraltpichwhel2)
            {
              pich = kalibraltpichwhel2 / 2 - 32;
              arpeggiopich2(pich >> 2);
            }
            lcd.print(menupoz);
            break;
          case 4:
            if (bpm != kalibraltpichwhel2)
            {
              bpm = kalibraltpichwhel2 * 2;
              pichido = BPMETALON / bpm;
            }
            break;
          case 5:
            if (sebesseg != kalibraltpichwhel2 / 16)
            {
              sebesseg = kalibraltpichwhel2 / 16;
            }
            break;
          case 6:
            if (drumset != kalibraltpichwhel2)
            {
              drumset = kalibraltpichwhel2;
            }

            break;
          case 7:
            if (arpeggionotenumber != kalibraltpichwhel2)
            {
              arpeggionotenumber = kalibraltpichwhel2;
            }

            break;
          case 8:
            if (chan != kalibraltpichwhel2)
            {
              chan = kalibraltpichwhel2 / 16;
            }

            break;
        }
        lcdkiir(menupoz);
        break;
      case 2:
        if (comb != kalibraltpichwhel2)
        {
          comb = kalibraltpichwhel2;
          fileread();
          lcdkiir(21);
        }
        break;
    }
  }
}

void lcdkiir(byte kiirpoz) {
  switch (kiirpoz) {
    case 0:
      lcd.setCursor(0, 0);
      break;
    case 1:
     
      if (page == 1) {
         lcd.setCursor(1, 0);
        lcdprint3(prog);
      }
      break;
    case 2:
      
      if(page==1){
        lcd.setCursor(5, 0);
      lcdprint3b(trans);
      }
      break;
    case 3:
      
      if(page==1){
       lcd.setCursor(9, 0); 
      lcdprint3b(pich);
      }
      break;
    case 4:
     
      if (page == 1) {
         lcd.setCursor(13, 0);
        lcdprint3(bpm);
      }
      break;
    case 5:
      if (page == 1) {
        lcd.setCursor(0, 1);
        lcd.print(sebesseg);
      }
      break;
    case 6:
      lcd.setCursor(2, 1);
      if (page == 1) {
        lcdprint3(drumset);
      }
      break;
    case 7:
      lcd.setCursor(6, 1);
      lcdprint2(arpeggionotenumber + 1);
      break;
    case 8:
      lcd.setCursor(10, 1);
      lcd.print(chan);
      break;
    case 9:
      lcd.setCursor(12, 1);
      lcd.write(kiir3(kalibraltpoti1));
      break;
    case 10:
      lcd.setCursor(13, 1);
      lcd.write(kiir3(kalibraltpoti2));
      break;
    case 11:
      lcd.setCursor(11, 1);
      lcd.write(kiir3(kalibraltpichwhel));
      break;
    case 12:
      lcd.setCursor(3, 1);
      lcdprint2(chan);
      break;
    case 21:

      break;
    case 100:
      lcd.clear();
      switch (page) {
        case 0:
          lcd.setCursor(0, 0);
          lcd.print("Write Combi?    ");
          lcd.setCursor(0, 1);
          lcd.print("No      Yes");
          break;
        case 1:
          lcd.setCursor(0, 0);
          lcd.print("P");
          lcdprint3(prog);
          lcd.print(" ");
          lcdprint3b(trans);
          lcd.print(" ");
          lcdprint3b(pich);
          lcd.print(" ");
          lcdprint3(bpm);
          lcd.setCursor(0, 1);
          lcd.print(sebesseg);
          lcd.setCursor(2, 1);
          lcdprint3(drumset);
          lcd.setCursor(6, 1);
          lcdprint2(arpeggionotenumber);
          lcd.setCursor(9, 1);
          lcdprint2(chan);
          lcd.setCursor(11, 1);
          lcd.write(kiir3(kalibraltpichwhel));
          lcd.write(kiir3(kalibraltpoti1));
          lcd.write(kiir3(kalibraltpoti2));
          vezerlokiir(0);
          break;
        case 2:
          lcd.setCursor(0, 0);
          lcd.print("C:");
          lcdprint3(comb);
          lcd.print(combiname);
          lcd.setCursor(0, 1);
          lcd.print("          ");
          lcd.write(kiir3(kalibraltpichwhel));
          lcd.write(kiir3(kalibraltpoti1));
          lcd.write(kiir3(kalibraltpoti2));
          vezerlokiir(0);
          break;
      }
      break;
    case 101:
      break;
  }
  lcdvillog();
}

void lcdvillog() {
  switch (menupoz) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.noCursor();
      lcd.noBlink();
      break;
    case 1:
      lcd.setCursor(3, 0);
      lcd.cursor();
      lcd.blink();
      break;
    case 2:
      lcd.setCursor(7, 0);
      lcd.cursor();
      lcd.blink();
      break;
    case 3:
      lcd.setCursor(11, 0);
      lcd.cursor();
      lcd.blink();
      break;
    case 4:
      lcd.setCursor(15, 0);
      lcd.cursor();
      lcd.blink();
      break;
    case 5:
      lcd.setCursor(0, 1);
      lcd.cursor();
      lcd.blink();
      break;
    case 6:
      lcd.setCursor(4, 1);
      lcd.cursor();
      lcd.blink();
      break;
    case 7:
      lcd.setCursor(7, 1);
      lcd.cursor();
      lcd.blink();
      break;
    case 8:
      lcd.setCursor(10, 1);
      lcd.cursor();
      lcd.blink();
      break;
  }
}

void noteOn(byte channel, byte note, byte attack_velocity, byte source)
{
  talkMIDI( (0x90 | channel), note, attack_velocity);
  noteOnMIDI(0x90 | channel,  note, attack_velocity);

  if (channel == 1)
  {
    if (source) {
      noteOff(utolsohangokchan, utolsohangok[framearpeggio].key, utolsohangok[framearpeggio].velocity);
    }
    utolsohangok[framearpeggio].key = note;
    utolsohangok[framearpeggio].velocity = attack_velocity;
    // utolsohangok[framearpeggio].chan = utolsohangokchan;
  } else
  {
    if (source) {
      noteOff(utolsohangok2[framearpeggio].chan, utolsohangok2[framearpeggio].key, utolsohangok2[framearpeggio].velocity);
    }
    //
    utolsohangok2[framearpeggio].key = note;
    utolsohangok2[framearpeggio].velocity = attack_velocity;
    utolsohangok2[framearpeggio].chan = channel;
  }

}

void noteOff(byte channel, byte note, byte release_velocity) {
  talkMIDI( (0x80 | channel), note, release_velocity);
  noteOffMIDI(0x80 | channel,  note, release_velocity);
}

void midieverynoteoff(uint8_t channel) {
  for (int i = 0; i < 127; i++)
  {
    noteOff( chan, i, 0);
  }
  talkMIDI(MIDI_CHAN_MSG | channel, MIDI_CHAN_EVERYNOTE_OFF, 0 );
  Serial.write(MIDI_CHAN_MSG | channel);
  Serial.write(MIDI_CHAN_EVERYNOTE_OFF);
  Serial.write(0);
}

void midiSetInstrument(uint8_t channel, uint8_t inst) {
  if (channel > 15) return;
  inst --; // page 32 has instruments starting with 1 not 0 :(
  if (inst > 127) return;
  talkMIDI (MIDI_CHAN_PROGRAM | channel, inst, 0);
  //  programchangeMIDI(MIDI_CHAN_PROGRAM | channel, inst, 1);
}

void midiSetChannelBank(uint8_t channel, uint8_t bank) {
  if (channel > 15) return;
  if (bank > 127) return;
  talkMIDI (MIDI_CHAN_MSG | channel, (uint8_t)MIDI_CHAN_BANK, bank);
}

void sendMIDI(byte data)
{
  SPI.transfer(0);
  SPI.transfer(data);
}

void midiSetReverbLevel(uint8_t channel, uint8_t amount) {
  sendMIDI(MIDI_CHAN_MSG | channel);
  sendMIDI(MIDI_EFFECT_LEVEL);
  sendMIDI(amount);
}

void midiSetReverbType(uint8_t channel, uint8_t amount) {
  sendMIDI(MIDI_CHAN_MSG | channel);
  sendMIDI(MIDI_EFFECT_CNTRL);
  sendMIDI(amount); // 0 = auto, 1..127 = increasing reverb room size (I think ?)
}

void talkMIDI(byte cmd, byte data1, byte data2) {
  while (!digitalRead(VS_DREQ));
  digitalWrite(VS_XDCS, LOW);
  sendMIDI(cmd);
  //Some commands only have one data byte. All cmds less than 0xBn have 2 data bytes
  //(sort of: http://253.ccarh.org/handout/midiprotocol/)
  if ( (cmd & 0xF0) <= 0xB0 || (cmd & 0xF0) >= 0xE0) {
    sendMIDI(data1);
    sendMIDI(data2);
  } else {
    sendMIDI(data1);
  }
  digitalWrite(VS_XDCS, HIGH);
}

void keyscaninit() {
  igombok = 0;
  igombokelozo = 0;
  igombok2 = 0;
  igombokelozo2 = 0;
  pinMode(multiadress0, OUTPUT);
  pinMode(multiadress1, OUTPUT);
  pinMode(multiadress2, OUTPUT);
  pinMode(multiadress3, OUTPUT);
}

byte velocityestimate () {
  int minvelocity = 80;
  int maxvelocity = 127;
  int notetime = ido - elozohangtime;
  elozohangtime = ido;
  int velocityvalue = maxvelocity - notetime;
  if (velocityvalue < minvelocity) {
    velocityvalue = minvelocity;
  }
  if (velocityvalue > maxvelocity) {
    velocityvalue = maxvelocity;
  }
  return velocityvalue;
}

void keyscan() {
  for (byte i = 0; i < 16; i++) {
    digitalWrite(multiadress0, i % 2);
    digitalWrite(multiadress1, i / 2 % 2);
    digitalWrite(multiadress2, i / 4 % 2);
    digitalWrite(multiadress3, i / 8 % 2);
    int multiplexer1 = analogRead(analogpin2);
    int multiplexer2 = analogRead(analogpin3);
    if (multiplexer1 > 100) {
      if (i > 7) {
        //      gombok[15 - i] = true; //!back wired
        bitWrite(igombok, 15 - i, 1);
      }
      if (i < 8) {
        //      gombok[i + 8] = true;
        bitWrite(igombok, i + 8, 1);
      }
    } else {
      if (i > 7) {
        //       gombok[ 15 - i] = false; //!back wired
        bitWrite(igombok, 15 - i, 0);
      }
      if (i < 8) {
        //   gombok[i + 8] = false;
        bitWrite(igombok, i + 8, 0);
      }
    }
    if (multiplexer2 > 100) {
      if (i > 7) {
        //        gombok2[i - 8] = true; //!back wired
        bitWrite(igombok2, i - 8, 1);
      }
      if (i < 8) {
        //        gombok2[i + 8] = true;
        bitWrite(igombok2, i + 8, 1);
      }
    } else {
      if (i > 7) {
        //    gombok2[i - 8] = false; //!back wired
        bitWrite(igombok2, i - 8, 0);
      }
      if (i < 8) {

        //   gombok2[i + 8] = false;
        bitWrite(igombok2, i + 8, 0);
      }
    }
  }

  for  (byte i = 0; i < 16; i++) {
    // if (gombok[i] && !gombokelozo[i])
    if ( bitRead(igombok, i) && !bitRead(igombokelozo, i))
    {
      if (keymode) {
        noteOn(chan, i + 57 + trans, velocityestimate (), 1);
      } else {
        valtozaskey = i + 57;
        nokey();
      }
      //     gombokelozo[i] = true;
      bitWrite(igombokelozo, i, 1);
    }
    // if (!gombok[i] && gombokelozo[i])
    if ( !bitRead(igombok, i) && bitRead(igombokelozo, i))
    {
      noteOff(chan, i + 57 + trans, 0x00);
      //   gombokelozo[i] = false;
      bitWrite(igombokelozo, i, 0);
    }
    //  if (gombok2[i] && !gombokelozo2[i])
    if ( bitRead(igombok2, i) && !bitRead(igombokelozo2, i))
    {
      if (i > 6) {

        if (keymode) {
          noteOn(chan, i + 41 + trans, velocityestimate (), 1);
        } else {
          valtozaskey = i + 41;
          nokey();
        }
      }
      //     gombokelozo2[i] = true;
      bitWrite(igombokelozo2, i, 1);
    }
    // if (!gombok2[i] && gombokelozo2[i])
    if ( !bitRead(igombok2, i) && bitRead(igombokelozo2, i))
    {
      noteOff(chan, i + 41 + trans, 0x00);
      //   gombokelozo2[i] = false;
      bitWrite(igombokelozo2, i, 0);
    }
  }
}

void pichbandcont() {
  byte msb;
  byte lsb;
  //if (gombok2[4])
  //ORANGE Button
  if (bitRead(igombok2, 4))
  {
    msb =  0 / 128;
    lsb =  0 % 128;
    pitchBend(lsb, msb);
    shift = true;
    vezerlokiir(1);

  }
  // if (!gombok2[4])
  if (bitRead(igombok2, 4))
  {
    msb = 8192 / 128;
    lsb = 8192 % 128;
    if (shift)
    {
      pitchBend(lsb, msb);
      shift = false;
      vezerlokiir(1);
    }
  }
}

void nokey() {
  if (!keymode) {
    switch (menupoz) {
      case 2:
        trans = valtozaskey - 60;
        break;
      case 3:
        pich = valtozaskey - 60;
        arpeggiopich(pich);
        break;
      case 4:
        bpm = valtozaskey << 1 ;
        pichido = BPMETALON / bpm;
        break;
      case 5:
        sebesseg = (valtozaskey - 48);
        break;
      case 6:
        drumset = valtozaskey - 48;
        break;
      case 7:
        arpeggionotenumber = valtozaskey - 48;
        break;
      case 8:
        chan = (valtozaskey - 48) / 2;
        break;
    }
    lcdkiir(menupoz);
  }
}

void pitchBend(int lsb, int msb) {
  int channel = 0;
  if (lsb > 127) return;
  if (msb > 127) return;
  talkMIDI (0xE0 | channel, lsb , msb);
  pichBandMIDI(0xE0 | channel, lsb , msb);
}

void lcdprint4(int cc)
{
  lcd.print(cc / 1000);
  lcd.print((cc % 1000) / 100);
  lcd.print((cc % 100) / 10);
  lcd.print(cc % 10);
}

void lcdprint3(int cc)
{
  lcd.print(cc / 100);
  lcd.print((cc % 100) / 10);
  lcd.print(cc % 10);
}

void lcdprint3b(int cc)
{

  if (cc > 0) {
    lcd.print("+");
    lcd.print((cc % 100) / 10);
    lcd.print(cc % 10);
  }
  else if (cc < 0) {
    lcd.print("-");
    cc = -1 * cc;
    lcd.print((cc % 100) / 10);
    lcd.print(cc % 10);
  } else {
    lcd.print(" ");
    lcd.print("0");
    lcd.print("0");
  }
}

void lcdprint2(int cc)
{
  lcd.print((cc % 100) / 10);
  lcd.print(cc % 10);
}

void vezerlokiir(byte hanyadik)
{ lcd.noBlink();
  switch (hanyadik) {
    case 0:
      lcd.setCursor(13, 1);
      lcd.write(kiir2(shift, shift));
      lcd.write(kiir2(arpon, dobon));
      lcd.write(kiir2(cvs, cvs));
      break;
    case 1:
      lcd.setCursor(13, 1);
      lcd.write(kiir2(shift, 0));
      break;
    case 2:
      lcd.setCursor(14, 1);
      lcd.write(kiir2(arpon, dobon));
      break;
    case 3:
      lcd.setCursor(15, 1);
      lcd.write(kiir2(keymode, keymode));
      break;
  }
  //lcdkiir(menupoz);
  //  lcd.blink();
  lcd.noCursor();
}

//write controller caracters: space, square, arrows
byte kiir2(int eleje, int vege) {
  if (eleje == 0 && vege == 0) {
    return B00100000;
  }
  if (eleje == 0 && vege == 1) {
    return B01111110;
  }
  if (eleje == 1 && vege == 0) {
    return B01111111;
  }
  if (eleje == 1 && vege == 1) {
    return B11011011;
  }
}

//write potenciometer value, one digit 1 to 10, input value range: 0-127
byte kiir3(byte eleje) {
  eleje = eleje / 10;
  if (eleje == 0)
  {
    return B00100000;
  } else
  {
    if (eleje > 7 )
    {
      return B11111111;
    } else
    {
      return eleje;
    }
  }
}


/*
  byte kiir3(byte eleje) {
  eleje = eleje / 2;
  if (eleje == 0)
  {
    return B00100000;
  }
  if (eleje >= 1 && eleje <= 10)
  {
    return 6;
  }
  if (eleje >= 11 && eleje <= 20)
  {
    return 0;
  }
  if (eleje >= 21 && eleje <= 30)
  {
    return 1;
  }
  if (eleje >= 31 && eleje <= 40)
  {
    return 2;
  }
  if (eleje >= 41 && eleje <= 50)
  {
    return 3;
  }
  if (eleje >= 51 && eleje <= 60)
  {
    return 4;
  }
  if (eleje >= 61 && eleje <= 70)
  {
    return 5;
  }
  if (eleje > 71)
  {
    return B11111111;
  }
  }
*/
void pichBandMIDI(int cmd, int note, int velocity) {
  Serial.write(cmd);
  Serial.write(note);
  Serial.write(velocity);
}

void programchangeMIDI(int cmd, int note, int velocity) {
  Serial.write(cmd);
  Serial.write(note);
  Serial.write(velocity);
}


void noteOnMIDI(int cmd, int note, int velocity) {
  Serial.write(cmd);
  Serial.write(note);
  Serial.write(velocity);
}

void noteOffMIDI(int cmd, int note, int velocity) {
  Serial.write(cmd);
  Serial.write(note);
  Serial.write(velocity);
}

void midiclockstart() {
  Serial.write(0xFA);
  // Serial.write(0x00);
}

void midiactivity()
{
  Serial.write(0xFE);
}
void midiclock() {
  Serial.write(0xF8);
  
  //Serial.write(0x00);
}
void midiclockstop() {
  Serial.write(0xFC);
  //Serial.write(0x00);
}

void midiclockcontinue() {
  Serial.write( 0xFB);
  //Serial.write(0x00);
}
