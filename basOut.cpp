#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <sstream>
#include <cmath>
using namespace std;

struct notes{
  double deg;
  double leng;
  notes *next;
};
class song{
private:
  notes *first;
  notes *last;
  int key;
  string vals[23];
  double degs[23];
  int major[7];
  void fillKey(){
    if(key == -99){
      return;
    }
    else{
      switch (key){
        case 0://a_ major scale - b_ e_ a_ d_
          major[0] = 0 ; major[1] = 3 ; major[2] = 7 ;
          major[3] = 9 ; major[4] = 12 ; major[5] = 16 ; major[6] = 19 ;
          break;
        case 1://a scale - f# c# g#
        major[0] = 1 ; major[1] = 4 ; major[2] = 8 ;
        major[3] = 10 ; major[4] = 13 ; major[5] =  17; major[6] = 20 ;
          break;
        case 2://b_scale - b_ e_0;
        major[0] = 3 ; major[1] = 7 ; major[2] = 10 ;
        major[3] = 12 ; major[4] = 16 ; major[5] = 19 ; major[6] = 1 ;
          break;
        case 3: //b scale - f# c# g# D# a#;
        major[0] = 4 ; major[1] = 8 ; major[2] = 11 ;
        major[3] = 13 ; major[4] = 17 ; major[5] = 20 ; major[6] = 1 ;
          break;
        case 4:// c_ scale - ALL FLAT
        major[0] = 6 ; major[1] = 9 ; major[2] = 12 ;
        major[3] = 15 ; major[4] = 18 ; major[5] = 0 ; major[6] = 3 ;
          break;
        case 5://c scale
        major[0] = 7 ; major[1] = 10 ; major[2] = 13 ;
        major[3] = 16 ; major[4] = 19 ; major[5] = 1 ; major[6] = 4 ;
          break;
        case 6://c# scale - ALL SHARP
        major[0] = 8 ; major[1] = 11 ; major[2] = 14 ;
        major[3] = 17 ; major[4] = 20 ; major[5] = 2 ; major[6] = 5 ;
          break;
        case 7://d_ scale - b_ e_ a_ d_ g_
        major[0] = 9 ; major[1] = 12 ; major[2] = 16 ;
        major[3] = 18 ; major[4] = 1 ; major[5] = 3 ; major[6] = 7 ;
          break;
        case 8: // d scale - f# c#
        major[0] = 10 ; major[1] = 13 ; major[2] = 17 ;
        major[3] = 19 ; major[4] = 1 ; major[5] = 4 ; major[6] = 8 ;
          break;
        case 9://e_ scale - b_ e_ a_
        major[0] = 12 ; major[1] = 16 ; major[2] = 19 ;
        major[3] = 0 ; major[4] = 3 ; major[5] = 7 ; major[6] = 10 ;
          break;
        case 10://e scale - f# c# g# d#
        major[0] = 13 ; major[1] = 17 ; major[2] = 20 ;
        major[3] = 1 ; major[4] = 4 ; major[5] = 8 ; major[6] = 11 ;
          break;
        case 11://f scale - b_
        major[0] = 16 ; major[1] = 19 ; major[2] = 1 ;
        major[3] = 3 ; major[4] = 7 ; major[5] = 10 ; major[6] = 13 ;
          break;
        case 12: //f# scale - everything but b
        major[0] = 17 ; major[1] = 20 ; major[2] = 2 ;
        major[3] = 4 ; major[4] = 8 ; major[5] = 11 ; major[6] = 14 ;
          break;
        case 13://g_ scale - everything but f
        major[0] = 18 ; major[1] = 0 ; major[2] = 3 ;
        major[3] = 6 ; major[4] = 9 ; major[5] = 12 ; major[6] = 16 ;
          break;
        case 14: //g scale - f#
        major[0] = 19 ; major[1] = 1 ; major[2] = 4 ;
        major[3] = 7 ; major[4] = 10 ; major[5] = 13 ; major[6] = 17 ;
          break;
      }
    }
  }
public:
  song(){
    first = NULL;
    last = NULL;
    key = -99;
    basicVals();
  }
  song(istream& in){
    first = NULL;
    last = NULL;
    key = -99;
    basicVals();
    addSong(in);
  }
  void basicVals(){
    vals[0]="A_", vals[1]="A"; vals[2]="A#";
    vals[3]="B_"; vals[4]="B"; vals[5]="B#";
    vals[6]="C_"; vals[7]="C"; vals[8]="C#";
    vals[9]="D_"; vals[10]="D"; vals[11]="D#";
    vals[12]="E_"; vals[13]="E"; vals[14]="E#";
    vals[15]="F_"; vals[16]="F"; vals[17]="F#";
    vals[18]="G_"; vals[19]="G"; vals[20]="G#";
    vals[21]="A_"; vals[22]="A";

    degs[0]=-25.7142857, degs[1]=0; degs[2]=25.7142847;
    degs[3]=degs[2]; degs[4]=2*degs[2]; degs[5]=3*degs[2];
    degs[6]=degs[5]; degs[7]=2*degs[4]; degs[8]=5*degs[2];
    degs[9]=degs[8]; degs[10]=3*degs[4]; degs[11]=7*degs[2];
    degs[12]=degs[11]; degs[13]=4*degs[4]; degs[14]=9*degs[2];
    degs[15]=degs[14]; degs[16]=5*degs[4]; degs[17]=11*degs[2];
    degs[18]=degs[17]; degs[19]=6*degs[4]; degs[20]=13*degs[2];
    degs[21]=degs[2]; degs[22]=360;

    for(int i = 0; i<7; i++){
      major[i]=-99;
    }
  }
  void getKey(string k){
    int s;
    int no;
    s = k.length();
      switch (k[0]){
        case 'A':
          key = 1;
          break;
        case 'B':
          key = 3;
          break;
        case 'C':
          key = 5;
          break;
        case 'D':
          key = 8;
          break;
        case 'E':
          key = 10;
          break;
        case 'F':
          key = 11;
          break;
        case 'G':
          key = 14;
          break;
      }
    if (s!=1){
      if(k[1]=='#'){
        key += 1;
      }
      else if(k[2]=='_'){
        key -= 1;
      }
    }
    fillKey();
  }
  void addSong(istream& in){
      string n;
      double l;
      int count = 0;
      notes *p;
      int s;
      string thp;
      in>>thp;
      if (first != NULL){
        clear();
      }
      getKey(thp);
      first = new notes;
      last = first;
      first->next = NULL;
      p = first;
      in>>n;
      while(thp!="*"){
        if(count%2 == 0){
          addNote(n, p);
        }
        else{
          in>>l;
          addL(l, p);
          p->next = new notes;
          p = p->next;
          p->next = NULL;
          last = p;
          in>>n;
        }
        thp = n;
        count++;
      }
  }
  int getNote(string k, bool& nat){
    int s;
    nat = false;
    s = k.length();
    if(s!=1 && k[1]=='%'){
      nat = true;
      k = k[0];
      s = 1;
    }
    for(int i = 0; i<21; i++){
      if(k == vals[i]){
        return i;
      }
    }
  }
  void addNote(string n, notes *p){
    n[0] = toupper(n[0]);
    double revdegs;
    int no;
    bool nat;
    no = getNote(n, nat);
    if(key == 5){
      no = no;
    }
    else if(nat){
      no = no;
    }
    else{
      for(int i = 0; i<7; i++){
        if (major[i]-no == -1 || major[i]-no == 1 || major[i]==no)
          no = major[i];
      }
    }
    revdegs = degs[no]-degs[major[0]];
    if(revdegs<0){
      revdegs+=360;
    }
    p->deg = revdegs;
  }
  void addL(double l, notes* p){
    p-> leng = l*2;
  }
  void saveSong(ostream& out){
    notes *p;
    int tog;
    p=first;
    while(p!=NULL){
      out<<p->deg<<"--"<<p->leng<<"--&"<<endl;
      p = p->next;
    }
  }
  int calOut(){
    double mod;
    double n;
    double thrw;
    double stay;
    double prev = 0;
    notes *p, *f;
    p = first;
    f = NULL;
    while(p!=NULL){
      n = p-> deg;
      thrw = n;
      n-=prev;
      f = p;
      p = p->next;
      stay+=prev;
      prev = thrw;
    }
    cout<<stay<<endl;
    for(double i = 1.0; ; i++){
      mod = stay*i;
      if (fmod(mod,360) < 1 || (360-fmod(mod,360))<1){
        return i;
        break;
      }
      mod = 0;
    }
  }
  ~song(){
    clear();
  }
  void clear(){
    notes *temp;
    while (first!=NULL){
      temp = first;
      first = first->next;
      delete temp;
    }
    last = NULL;
  }
  void print(){
    notes *p;
    p = first;
    while(p!=NULL){
      cout<<p->deg<<" "<<p->leng;
      cout<<endl;
    }
  }
};

int main(){
  ifstream songNotes;
  ofstream turtle;
  string o, tut;
  cout<<"Name of file: ";
  cin>>o;
    songNotes.open(o);
    song Fly(songNotes);
  cout<<"Save file name: ";
  cin>>tut;
    turtle.open(tut);
    Fly.saveSong(turtle);
    turtle.close();
    songNotes.close();

}
