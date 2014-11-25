#include "scoreTable.h"


#include "inter.h"

ScoreTable::ScoreTable(Game * p, int points) : parent(p), points(points)
{
    // Render big header
    fntH1.setAll(parent, "media/fuenteMenu.ttf", 60);
    mHeader1 = fntH1.renderText(_("GAME OVER"));

    fntH2.setAll(parent, "media/fuenteNormal.ttf", 35);

    fntLcdBig.setAll(parent, "media/fuentelcd.ttf", 72);
    fntLcdSmall.setAll(parent, "media/fuentelcd.ttf", 36);

    string scoreFilePath = "freeGemasScore";

    // scoreFile.open(scoreFilePath.c_str(), fstream::in);

    // if(!scoreFile.is_open()){
    //     lDEBUG << "ZOMG FILE DOES NOT EXIST";
    //     scoreFile.close();

    //     fillEmptyScoreFile();

    //     scoreFile.open(scoreFilePath.c_str(), fstream::in);
    // }

    // while(!scoreFile.eof() && scoreFile.good()){
    //     pair<string, int> currentScore;
    //     scoreFile >> currentScore.first;
    //     scoreFile >> currentScore.second;
    //     lDEBUG << "Read: " << currentScore.first << " => " << currentScore.second;

    //     if(currentScore.first == "") continue;

    //     readScoreSet.insert(currentScore);
    // }

    // scoreFile.close();

    for (size_t i = 0; i < 5; ++i)
    {
        pair<string, int> currentScore;
        currentScore.first = "Pepe";
        currentScore.second = i * 100;

        readScoreSet.insert(currentScore);
    }

    state = eRequestPlayerName;

    scoreBoardWidth = 300;
}

#define KOL 0xffffffff

void ScoreTable::draw(int x, int y, double z)
{
    (void) x;
    (void) y;
    (void) z;

    // Get the localized score table string
    string stringTitle = _("GAME OVER");

    // Get the width of the first header
    double w1 = fntH1.getTextWidth(stringTitle);

    // Get the width of the subheader
    double wp = fntLcdBig.getTextWidth(std::to_string(points));

    // Get the center
    int center = x + scoreBoardWidth / 2;

    mHeader1.draw(center - w1 / 2, y, z);

/*
    fntH1.draw(stringTitle,
                  center - w1 / 2 + 1,
                  y+3, z - 0.1, 1, 1, 0x44000000);

    fntLcdBig.draw(std::to_string(points),
                      center - wp / 2, y + 67, z);



    if(state == eRequestPlayerName){
        wstring stringSubtitle = Gosu::widen(_("Write your name:"));
        double w2 = fntH2 -> getTextWidth(stringSubtitle);

        fntH2 -> draw(stringSubtitle,
                      center - w2 / 2,
                      y + 140, z);



        float lineWidth = 200.f;
        float lineStartX = center - lineWidth / 2;
        float lineEndX = center + lineWidth / 2;

        parent -> graphics().drawLine(lineStartX, y + 210, KOL,
                                      lineEndX, y + 210, KOL,
                                      z);

        fntH2 -> draw(nameInput.text(),
                      center - fntH2 -> getTextWidth(nameInput.text()) / 2,
                      y + 210 - 33, z);

    }else if(state == eShowScores){
        int ii = 0;

        for(scoreSetIterator it = readScoreSet.begin();
            it != readScoreSet.end() && ii < 5;
            ++it, ++ii){

            Gosu::Color clr = (it -> first == Gosu::narrow(nameInput.text()) && it -> second == points) ?
                0xffff0000 : 0xffffffff;

            fntH2 -> draw(Gosu::widen(it -> first),
                          x + 50, y + 140 + ii * 30, z, 1, 1, clr);

            fntLcdSmall -> draw(std::to_string(it -> second),
                                (int)(x + 230 - fntLcdSmall -> getTextWidth(std::to_string(it -> second)) / 2),
                                y + 140 + ii * 30, z, 1, 1, clr);
        }
    }
    //*/
}

void ScoreTable::buttonDown(SDL_Keycode button)
{
    (void) button;
    // if((B == Gosu::kbReturn || B == Gosu::kbEnter) && state == eRequestPlayerName){
    //     state = eShowScores;

    //     // Stop checking the input
    //     parent -> input().setTextInput(0);

    //     // If there was no name input, set it to NoName
    //     if(nameInput.text() == L""){
    //         nameInput.setText(L"NoName");
    //     }

    //     // Check if the current score is one of the highest
    //     readScoreSet.insert(make_pair(Gosu::narrow(nameInput.text()), points));

    //     string scoreFilePath = Gosu::narrow(Gosu::userSettingsPrefix()) + "freeGemasScore";
    //     scoreFile.open(scoreFilePath.c_str(), fstream::out);

    //     int ii = 0;

    //     for(scoreSetIterator it = readScoreSet.begin();
    //         it != readScoreSet.end() && ii < 5;
    //         ++it, ++ii){

    //         scoreFile << it -> first << " ";
    //         scoreFile << it -> second << endl;
    //     }

    //     scoreFile.close();
    // }
}


void ScoreTable::fillEmptyScoreFile()
{
    // string scoreFilePath = Gosu::narrow(Gosu::userSettingsPrefix()) + "freeGemasScore";
    // scoreFile.open(scoreFilePath.c_str(), fstream::out);

    // scoreFile << "ChuckNorris 2000" << endl
    //           << "Pepe 1400" << endl
    //           << "Elena 1200" << endl
    //           << "Juanjo 900" << endl
    //           << "Pedro 600" << endl;

    // scoreFile.close();
}