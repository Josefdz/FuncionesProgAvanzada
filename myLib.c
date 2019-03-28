#include "myLib.h"

int asciiBinaryToInt(char *s) {
    int iResult=0, iExp=0, iExpCount=0, iMult=0;
    iExp=strlen(s);
    iExpCount=iExp-1;
    for (int i=0; i<iExp; i++) {
        iMult=*(s+i)-'0';
        iResult+=pow(2, iExpCount)*iMult;
        iExpCount--;
    }
    return iResult;
    
}

int asciiHEXToInt(char *s) {
    int iResult=0, iExp=0, iExpCount=0, iMult=0;
    iExp=strlen(s);
    iExpCount=iExp-1;
    for (int i=0; i<sizeof(s); i++) {
        if (isdigit(*(s+i))) {
            iMult=*(s+i)-'0';
            iResult+=pow(10, iExpCount)*iMult;
            iExpCount--;
        }
        else if (isalpha(*(s+i))) {
            switch (*(s+i)) {
                case 'A':
                    iMult=10;
                    break;
                case 'B':
                    iMult=11;
                    break;
                case 'C':
                    iMult=12;
                    break;
                case 'D':
                    iMult=13;
                    break;
                case 'E':
                    iMult=14;
                    break;
                case 'F':
                    iMult=15;
                    break;
                case 'a':
                    iMult=10;
                    break;
                case 'b':
                    iMult=11;
                    break;
                case 'c':
                    iMult=12;
                    break;
                case 'd':
                    iMult=13;
                    break;
                case 'e':
                    iMult=14;
                    break;
                case 'f':
                    iMult=15;
                    break;
                default:
                    return iResult;
                    break;
            } //switch over
            iResult+=pow(10, iExpCount)*iMult;
            iExpCount--;
        }
        else return iResult;
    }
    return iResult;
}

double asciiToDouble(char *sNum) {
 
    int iCont=0, iPot=0, bDec=0, bNumInv=0;
    
    double iSuma=0.0;
    while (isdigit(sNum[iCont])||sNum[iCont]=='.') {
        if (sNum[iCont]=='.') {
            iPot=iCont-1;
            bDec=1;
        }
        iCont++;
    }
    if (bDec==0) {
        iPot=iCont-1;
    }
    for (int j=0; j<iCont; j++) {
        if (sNum[j]!='.') {
            iSuma=iSuma+(pow(10,iPot)*(sNum[j]-'0'));
            iPot--;
        }
    }
    for (int i=0; i<sizeof(sNum)-1; i++) {
        if ((!isdigit(sNum[i]))&&sNum[i]!='.') {
            bNumInv=1;
        }
    }
    if (sizeof(sNum)<3) {
        bNumInv=1;
    }
    if (!bNumInv) {
        return iSuma;
    }
    else return -1.0;
    
    
}
