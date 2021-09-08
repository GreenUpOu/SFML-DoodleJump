#include <SFML/Graphics.hpp>
#include <time.h>
#include<sstream>
    using namespace sf;

struct point
{ int x,y;};


int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    Texture tplat[6], T[3][2];
    Texture Phone[6];
    Phone[1].loadFromFile("images/desert.png");
    Phone[0].loadFromFile("images/background.png");
    Phone[2].loadFromFile("images/sky.png");
    Phone[3].loadFromFile("images/jungle.png");
    Phone[4].loadFromFile("images/space.png");
    Phone[5].loadFromFile("images/Pinsk.png");
    tplat[0].loadFromFile("images/classic platform.png");
    tplat[1].loadFromFile("images/desert platform.png");
    tplat[2].loadFromFile("images/sky platform.png");
    tplat[3].loadFromFile("images/jungle platform.png");
    tplat[4].loadFromFile("images/space platform.png");
    tplat[5].loadFromFile("images/Pinsk platform.png");
    T[0][0].loadFromFile("images/doodle_left.png");
    T[0][1].loadFromFile("images/doodle_right.png");
    T[1][0].loadFromFile("images/chiken_left.png");
    T[1][1].loadFromFile("images/chiken_right.png");
    T[2][0].loadFromFile("images/girl_left.png");
    T[2][1].loadFromFile("images/girl_right.png");
    int back = 0, platform = 0;
    Texture tplag[2], tex[2], tch[2], them[2];
    tplag[0].loadFromFile("images/play again.png");
    tex[0].loadFromFile("images/exit.png");
    tch[0].loadFromFile("images/change skin.png");
    tplag[1].loadFromFile("images/play again pressed.png");
    tex[1].loadFromFile("images/exit pressed.png");
    tch[1].loadFromFile("images/change skin pressed.png");
    them[0].loadFromFile("images/theme.png");
    them[1].loadFromFile("images/theme pressed.png");
    Sprite sBackground, sPlat, sPersl, sPersr, sPers, sPlag, sExit, sChng, sthem;
    int but_type = 0;
    int skin = 0;
    point plat[20];
    int last = 0;
    plat[0].x = 110;
    plat[0].y = 370;
    bool flag = true;

        for (int i = 1; i < 10; i++)
        {
            do {
                flag = true;
                plat[i].x = rand() % 332;
                plat[i].y = rand() % 533;
                for (int j = 0; j < i; j++)
                {
                    if (plat[i].x >= plat[j].x - 70 && plat[i].x <= plat[j].x + 70 && plat[i].y >= plat[j].y - 20 && plat[i].y <= plat[j].y + 20)
                    {
                        flag = false;
                        break;
                    }
                }
            } while (!flag);
        }
    int x=100,y=100,h=200;

    float playerScore = 0, record = 0;

    float dx=0, dy=0;
    bool name = false, left = false, right = true, menu = false;

    std::string str;

    Font font1;
    font1.loadFromFile("al-seana.ttf");
    Text text1("", font1, 40);
    text1.setOutlineColor(Color::Black);
    text1.setFillColor(Color::Black);
    text1.setStyle(sf::Text::Bold);
    text1.setString("Enter your name:");
    sPersl.setTexture(T[skin][0]);
    sPersr.setTexture(T[skin][1]);
    sBackground.setTexture(Phone[0]);
    sPlat.setTexture(tplat[0]);
    while (app.isOpen())
    {

        
        Event event;
        
        
        while (app.pollEvent(event))  
        {
            
            if (!name) 
            {
                
                if (event.type == Event::TextEntered)
                {
                    if (event.text.unicode < 128)
                    {
                        
                        if (event.text.unicode == 8)
                        {
                            if (str.size() > 0)
                                str.erase(str.size() - 1);
                        }
                        else
                        str += static_cast<char>(event.text.unicode);
                        text1.setString("Enter your name:\n" + str);
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                    name = true;
                
            }
            if (event.type == Event::Closed)
                app.close();
            if (event.type == Event::MouseButtonReleased && but_type == 3)
            {
                skin++;
                if (skin >= 3)
                    skin = 0;
                sPersl.setTexture(T[skin][0]);
                sPersr.setTexture(T[skin][1]);
            }
            else if (event.type == Event::MouseButtonReleased && but_type == 4)
            {
                back++;
                if (back == 6)
                    back = 0;
                sBackground.setTexture(Phone[back]);
                platform++;
                if (platform == 6)
                    platform = 0;
                sPlat.setTexture(tplat[platform]);
            }
        }
        
        if (!name)
        {
            app.draw(sBackground);
            text1.setPosition(20, 100);
            app.draw(text1);
        }
        

        if (menu)
        {
            app.draw(sBackground);
            Texture over;
            over.loadFromFile("images/game over.png");
            Sprite sover(over);
            sover.setPosition(20, 10);
            app.draw(sover);

            if (playerScore > record)
                record = playerScore;
            Font font;
            font.loadFromFile("al-seana.ttf");
            Text text("", font, 50);
            text.setOutlineColor(Color::Black);
            text.setFillColor(Color::Black);
            text.setStyle(sf::Text::Bold);

            std::ostringstream playerScoreString, recordString;
            playerScoreString << playerScore;
            recordString << record;
            text.setString("score:" + playerScoreString.str() + "\nbest score:" + recordString.str());
            text.setPosition(60, 165);
            app.draw(text);
            if(but_type != 1)
            sPlag.setTexture(tplag[0]);
            sPlag.setPosition(20, 380);
            if (but_type != 2)
            sExit.setTexture(tex[0]);
            sExit.setPosition(100, 450);
            if (but_type != 3)
                sChng.setTexture(tch[0]);
            if (but_type != 4)
                sthem.setTexture(them[0]);
            sthem.setPosition(80, 115);
            sChng.setPosition(220, 380);
            sPersl.setPosition(250, 270);
            sPlat.setPosition(260, 345);
            app.draw(sPlat);
            app.draw(sPlag);
            app.draw(sExit);
            app.draw(sChng);
            app.draw(sPersl);
            app.draw(sthem);
            but_type = 0;

            if (IntRect(20, 380, 164, 44).contains(Mouse::getPosition(app)))
            {
                sPlag.setTexture(tplag[1]);
                but_type = 1;
            }
            else if (IntRect(80, 115, 164, 44).contains(Mouse::getPosition(app)))
            {
                sthem.setTexture(them[1]);
                but_type = 4;
            }
            else if (IntRect(100, 450, 164, 44).contains(Mouse::getPosition(app)))
            {
                sExit.setTexture(tex[1]);
                but_type = 2;
            }
            
            else if (IntRect(220, 380, 164, 44).contains(Mouse::getPosition(app)))
            {
                sChng.setTexture(tch[1]);
                but_type = 3;
            }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (but_type == 2)
                    app.close();
                else if (but_type == 1)
                {
                    playerScore = 0;
                    x = 100;
                    y = 100;
                    dy = 0;
                    plat[0].x = 110;
                    plat[0].y = 370;
                    bool flag = true;
                    for (int i = 1; i < 10; i++)
                    {
                        do {
                            flag = true;
                            plat[i].x = rand() % 332;
                            plat[i].y = rand() % 533;
                            for (int j = 0; j < i; j++)
                            {
                                if (plat[i].x >= plat[j].x - 70 && plat[i].x <= plat[j].x + 70 && plat[i].y >= plat[j].y - 20 && plat[i].y <= plat[j].y + 20)
                                {
                                    flag = false;
                                    break;
                                }
                            }
                        } while (!flag);
                    }
                    menu = false;
                }
            }
        }


        if (name && !menu)
        {
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                right = true;
                left = false;
                x += 4;
                if (x > 400)
                    x = -60;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                left = true;
                right = false;
                x -= 4;
                if (x < -70)
                    x = 400;
            }

            dy += 0.2;
            y += dy;

            /*/ CHEATS
                if (Keyboard::isKeyPressed(Keyboard::Up))
                {


                    dy = -15;
                    for (int i = 0; i < 10; i++)
                    {
                        y = h;
                        plat[i].y = plat[i].y + dy;
                        if (plat[i].y > 533) { plat[i].y = 0; plat[i].x = rand() % 400; }
                    }

                }
            /*/
            

            if (y > 500)
                menu = true;


            if (y < h)
            {
                for (int i = 0; i < 10; i++)
                {
                    y = h;
                    plat[i].y = plat[i].y - dy;
                    if (plat[i].y > 533) 
                    { 
                        plat[i].y = 0; plat[i].x = rand() % 332; 
                        while (plat[i].x >= last - 70 && plat[i].x <= last + 70)
                            plat[i].x = rand() % 332;
                        last = plat[i].x;
                    }
                }
                playerScore -= dy;
            }

            for (int i = 0; i < 10; i++)
                if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                    && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;

            Font font;
            font.loadFromFile("al-seana.ttf");
            Text text("", font, 30);
            text.setOutlineColor(Color::Black);
            text.setFillColor(Color::Black);
            text.setStyle(sf::Text::Bold);

            if (left)
                sPers = sPersl;
            else
            sPers = sPersr;
            sPers.setPosition(x, y);

            app.draw(sBackground);
            
            for (int i = 0; i < 10; i++)
            {
                sPlat.setPosition(plat[i].x, plat[i].y);
                app.draw(sPlat);
            }
            app.draw(sPers);


            std::ostringstream playerScoreString;
            playerScoreString << playerScore;
            text.setString(str + ", your score:" + playerScoreString.str());
            text.setPosition(10, 10);
            app.draw(text);
        }

    app.display();
}
    return 0;
}
