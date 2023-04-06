void displayR(int cifra, int frogment,boolean tochka){
  for(int KONKRETNOECHISLOFORFOR = 7;KONKRETNOECHISLOFORFOR>=0;KONKRETNOECHISLOFORFOR--){
    digitalWrite(pinDISPLAYfrogment[frogment],1);
    digitalWrite(pinDISPLAYsigment[7-KONKRETNOECHISLOFORFOR],KONKRETNOECHISLOFORFOR==0?tochka==1?bitRead(sigmentsCODE[cifra],KONKRETNOECHISLOFORFOR):1:bitRead(sigmentsCODE[cifra],KONKRETNOECHISLOFORFOR));
    digitalWrite(pinDISPLAYfrogment[frogment],0);
    digitalWrite(pinDISPLAYsigment[7-KONKRETNOECHISLOFORFOR],1);
  }
}
void Vivod(int FR0,int FR1,int FR2,int FR3){
  displayR(FR0,0,0);
  displayR(FR1,1,0);
  displayR(FR2,2,0);
  displayR(FR3,3,0);
}

void VivodQIFRA(int QIFRA){
  displayR(floor(QIFRA/1000),0,0);
  displayR(floor(QIFRA/100)-floor(QIFRA/1000)*10,1,0);
  displayR(((QIFRA%100)-(QIFRA%10))/10,2,0);
  displayR(QIFRA%10,3,0);
}
void vivodChar(char bukva,int znakomesto){
  switch(bukva){
    case 't': displayR(11,znakomesto,0); break;
    case 's': displayR(13,znakomesto,0); break;
    case 'e': displayR(12,znakomesto,0); break;
    case 'r': displayR(14,znakomesto,0); break;
  }
}
void vivodSlovo(String SLOVOdisplay,char polozjenie){
 if(polozjenie=='R'){
  for(int schetSTRiNG = SLOVOdisplay.length();schetSTRiNG>0;schetSTRiNG--){
   vivodChar(SLOVOdisplay[schetSTRiNG-1],schetSTRiNG);
  }  
 }
 if(polozjenie=='L'){
   for(int schetSTRiNG = 0;schetSTRiNG<=SLOVOdisplay.length()-1;schetSTRiNG++){
    vivodChar(SLOVOdisplay[schetSTRiNG],schetSTRiNG);
   }
 }
}
