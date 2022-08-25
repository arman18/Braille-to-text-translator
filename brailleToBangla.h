#ifndef BRAILLETOBANGLA_H
#define BRAILLETOBANGLA_H
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<regex>
#include "bangla.h"
#include "banglaTextProcess.h"
#include "brailleToText.h"

using namespace std;

class BrailleToBangla: public BanglaTextProcess, public BrailleToText
{
    private:
        Bangla bangla;
        vector<string> notFirstLetter = { "্‌", "ং", "ঃ", "ঁ", "$"}; //"ঙ", "ঞ", "ণ", "ড়", "ঢ়", "য়", "ৎ",
        //vector<string> notSingle = {"্‌", "ং", "ঃ", "ঁ", "$"};

    public:
        BrailleToBangla()
        {
            //cout<<"braille to bangla"<<endl;
        }

        string returnText(vector<string> text)
        {
            string outText = "";
            for(int i=0; i<text.size(); i++)
            {
                outText += text[i];
            }
            return outText;
        }

        bool isConsonant(string consonant)
        {
            unordered_map<string, string> allVowel = bangla.getVowelDictionary();
            for (pair<string, string> element : allVowel)
            {
                //cout<<8909000<<endl;
                //oFile<<consonant<<" "<<element.second<<endl;
                if(consonant == element.second)
                {
                    //cout<<"dd "<<letters[i]<<endl;
                    return false; //element.second;
                }
            }
            return true;


            /*
            for (pair<string, string> element : bangla.getConsonant())
            {
                if(consonant == element.second)
                {
                    return true;
                }
            }
            return false;
            */
        }

        string getBrailleToText(vector<string> text) //overriden
        {
            vector<string> outText = textProcess(text); //banglaTextProcess class
            int i = 0;
            //ofstream oFile("tests.txt", ios::app);
            //int length = srtlen(outText);

            while(i < outText.size())
            {
                //oFile<<outText[i]<<"\n";
                if(bangla.getVol_spe().find(outText[i]) != bangla.getVol_spe().end() && i>0 && outText[i-1] == bangla.getVolume()["100000"]
                        && (i-2>=0 && isConsonant(outText[i-2])))
                {
                    //outText = outText.substr(0, i-1) + outText.substr(i, outText.size()-i+1);
                    outText.erase(outText.begin()+ i-1);
                    i -= 1;
                }
                else if(bangla.getSymbolToKar().find(outText[i]) != bangla.getSymbolToKar().end() && i>0 &&
                        isConsonant(outText[i-1]))
                {
                    //outText = outText.substr(0, i) + bangla.getSymbolToKar()[outText[i]] + outText.substr(i+1, outText.size()-i);
                    outText[i] = bangla.getSymbolToKar()[outText[i]];
                    //cout<<"yes"<<endl;
                }

                else if(outText[i] == bangla.getConsonant()["001000"] &&
                        (i+1 < outText.size() && bangla.getSymbolToKar().find(outText[i+1]) != bangla.getSymbolToKar().end()) &&
                        (i-1 >=0 && isConsonant(outText[i-1]))){

                    outText[i] = bangla.getSymbolToKar()[outText[i+1]];
                    outText[i+1] = bangla.getConsonant()["001000"];
                    i += 1;
                }
                else if(i == 0 &&
                        find(notFirstLetter.begin(), notFirstLetter.end(), outText[i]) != notFirstLetter.end()){
                    outText.erase(outText.begin()+i);
                    i -= 1;
                }
                //if(bangla.getSymbolToKar().find(outText[i]) != bangla.getSymbolToKar().end()) cout<<"paise"<<endl;
                i += 1;
            }

            return returnText(outText);
        }

        string postProcess(string text)
        {
            string pattern = "([ঢ]*)";
            string match = text.erase(text.size() - 1);

            if (regex_match(match, regex(pattern)))
                return "";

//            else if(){

//            }

            return text + " ";
            //return text;
        }


};

#endif // BRAILLETOBANGLA_H
