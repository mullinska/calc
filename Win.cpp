#ifndef win
#define win
#include "Win.h"
#include "Bttn.h"
#include "Converter.h"

//Constructors
Win::Win() {
}
Win::~Win() {

}
//misc function
string Win::rev(string s) {
    string f;
    for (int i = s.length()-1; i >= 0; i--) {
        f += s.substr(i,1);
    }
    return f;
}

//Functions
int Win::run() {
    if (!font.loadFromFile("arial.ttf")) {
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(500, 800), "Base Conversion Calculator", sf::Style::Titlebar+sf::Style::Close);
    height = 800;
    width = 500;
    text.setFont(font);
    result.setFont(font);
    text.setCharacterSize(25);
    result.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    result.setFillColor(sf::Color::White);

    loadButtons();
    Converter converter;

    while (window.isOpen()) {
        //test for user events
        sf::Event event;
        bool pressed = false;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                mousex = sf::Mouse::getPosition(window).x;
                mousey = sf::Mouse::getPosition(window).y;
                mousepressed = true;
            } else {
                mousepressed = false;
                buttonlock = true;
            }

            //keyboard
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && !pressed) {
                converter.setNumber(converter.getNumber()+"0");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !pressed) {
                converter.setNumber(converter.getNumber()+"1");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !pressed && converter.getBase() > 2) {
                converter.setNumber(converter.getNumber()+"2");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && !pressed && converter.getBase() > 3) {
                converter.setNumber(converter.getNumber()+"3");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && !pressed && converter.getBase() > 4) {
                converter.setNumber(converter.getNumber()+"4");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && !pressed && converter.getBase() > 5) {
                converter.setNumber(converter.getNumber()+"5");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && !pressed && converter.getBase() > 6) {
                converter.setNumber(converter.getNumber()+"6");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && !pressed && converter.getBase() > 7) {
                converter.setNumber(converter.getNumber()+"7");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && !pressed && converter.getBase() > 8) {
                converter.setNumber(converter.getNumber()+"8");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && !pressed && converter.getBase() > 9) {
                converter.setNumber(converter.getNumber()+"9");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !pressed && converter.getBase() > 10) {
                converter.setNumber(converter.getNumber()+"A");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && !pressed && converter.getBase() > 11) {
                converter.setNumber(converter.getNumber()+"B");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !pressed && converter.getBase() > 12) {
                converter.setNumber(converter.getNumber()+"C");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !pressed && converter.getBase() > 13) {
                converter.setNumber(converter.getNumber()+"D");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !pressed && converter.getBase() > 14) {
                converter.setNumber(converter.getNumber()+"E");
                pressed = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !pressed && converter.getBase() > 15) {
                converter.setNumber(converter.getNumber()+"F");
                pressed = true;
            } else {
                pressed = false;
            }
        }

        //mouse clicking
        int clicked;
        if (mousey > 200 && mousepressed) {
            clicked = (mousex/100) + ((mousey/100)-2)*5;
        } else {converter.setNumber(converter.getNumber() + "");
            clicked = -1;
        }
        //do calculations
        if (clicked == 0 && buttonlock) {
            converter.setOp("^");
            buttonlock = false;
        } else if (clicked == 1 && buttonlock) {
            converter.setOp("r");
            buttonlock = false;
        } else if (clicked == 2 && buttonlock) {
            converter.setNumber(rev(converter.getNumber()));
            buttonlock = false;
        } else if (clicked == 3 && buttonlock) {
            converter.setOp("%");
            converter.setLastNumber(converter.getNumber());
            converter.setNumber("");
            buttonlock = false;
        } else if (clicked == 4 && buttonlock) {

            buttonlock = false;
        } else if (clicked == 5 && buttonlock) {
            converter.setOp("+");
            converter.setLastNumber(converter.getNumber());
            converter.setNumber("");
            buttonlock = false;
        } else if (clicked == 6 && buttonlock) {
            converter.setOp("-");
            converter.setLastNumber(converter.getNumber());
            converter.setNumber("");
            buttonlock = false;
        } else if (clicked == 7 && buttonlock) {
            converter.setOp("x");
            converter.setLastNumber(converter.getNumber());
            converter.setNumber("");
            buttonlock = false;
        } else if (clicked == 8 && buttonlock) {
            converter.setOp("/");
            converter.setLastNumber(converter.getNumber());
            converter.setNumber("");
            buttonlock = false;
        } else if (clicked == 9 && buttonlock) {
            converter.setNumNeg();
            buttonlock = false;
        } else if (clicked == 10 && buttonlock) {
            converter.setNumber(converter.getNumber() + "0");
            buttonlock = false;
        } else if (clicked == 11 && buttonlock) {
            converter.setNumber(converter.getNumber() + "1");
            buttonlock = false;
        } else if (clicked == 12 && buttonlock) {
            converter.setNumber(converter.getNumber() + "2");
            buttonlock = false;
        } else if (clicked == 13 && buttonlock) {
            converter.setNumber(converter.getNumber() + "3");
            buttonlock = false;
        } else if (clicked == 14 && buttonlock) {
            buttonlock = false;
        } else if (clicked == 15 && buttonlock) {
            converter.setNumber(converter.getNumber() + "4");
            buttonlock = false;
        } else if (clicked == 16 && buttonlock) {
            converter.setNumber(converter.getNumber() + "5");
            buttonlock = false;
        } else if (clicked == 17 && buttonlock) {
            converter.setNumber(converter.getNumber() + "6");
            buttonlock = false;
        } else if (clicked == 18 && buttonlock) {
            converter.setNumber(converter.getNumber() + "7");
            buttonlock = false;
        } else if (clicked == 19 && buttonlock) {
            if (converter.getNumber().length() > 0) {
                converter.setNumber(converter.getNumber().substr(0,converter.getNumber().length()-1));
            }
            buttonlock = false;
        } else if (clicked == 20 && buttonlock) {
            converter.setNumber(converter.getNumber() + "8");
            buttonlock = false;
        } else if (clicked == 21 && buttonlock) {
            converter.setNumber(converter.getNumber() + "9");
            buttonlock = false;
        } else if (clicked == 22 && buttonlock) {
            converter.setNumber(converter.getNumber() + "A");
            buttonlock = false;
        } else if (clicked == 23 && buttonlock) {
            converter.setNumber(converter.getNumber() + "B");
            buttonlock = false;
        } else if (clicked == 24 && buttonlock) {
            converter.setNumber("");
            buttonlock = false;
        } else if (clicked == 25 && buttonlock) {
            converter.setNumber(converter.getNumber() + "C");
            buttonlock = false;
        } else if (clicked == 26 && buttonlock) {
            converter.setNumber(converter.getNumber() + "D");
            buttonlock = false;
        } else if (clicked == 27 && buttonlock) {
            converter.setNumber(converter.getNumber() + "E");
            buttonlock = false;
        } else if (clicked == 28 && buttonlock) {
            converter.setNumber(converter.getNumber() + "F");
            buttonlock = false;
        } else if (clicked == 29 && buttonlock) {
            converter.convert();
            buttonlock = false;
        }

        //draw sections
        sf::RectangleShape vLines(sf::Vector2f(2,600));
        vLines.setFillColor(sf::Color(100, 100, 100));
        vLines.setPosition(95,200);
        window.draw(vLines);
        vLines.setPosition(195,200);
        window.draw(vLines);
        vLines.setPosition(295,200);
        window.draw(vLines);
        vLines.setPosition(395,200);
        window.draw(vLines);

        sf::RectangleShape hLines(sf::Vector2f(500,2));
        hLines.setFillColor(sf::Color(100, 100, 100));
        hLines.setPosition(0,200);
        window.draw(hLines);
        hLines.setPosition(0,300);
        window.draw(hLines);
        hLines.setPosition(0,400);
        window.draw(hLines);
        hLines.setPosition(0,500);
        window.draw(hLines);
        hLines.setPosition(0,600);
        window.draw(hLines);
        hLines.setPosition(0,700);
        window.draw(hLines);

        //draw buttons
        for (int i = 0; i < 30; i++) {
            text.setString(buttons[i].getValue());
            text.setPosition(((i % 5) * 100) + 10, ((i / 5) * 100) + 235);
            window.draw(text);
        }

        //draw results
        if (converter.getNumNeg()) {
            result.setString("-" + converter.getNumber());
        } else {
            result.setString(converter.getNumber());
        }

        result.setPosition(470-result.getLocalBounds().width, 80);
        window.draw(result);


        //display window then clear
        window.display();
        window.clear();
    }
    return 0;
}

void Win::loadButtons() {
    for (int i = 0; i < 30; i++) {
        buttons[i].setWidth(100);
        buttons[i].setHeight(100);
    }
    buttons[0].setPosAndValue(0, 200, "X^2");
    buttons[1].setPosAndValue(100, 200, "Root");
    buttons[2].setPosAndValue(200, 200, "Rev");
    buttons[3].setPosAndValue(300, 200, "%");
    buttons[4].setPosAndValue(400, 200, "Base");
    buttons[5].setPosAndValue(0, 300, "+");
    buttons[6].setPosAndValue(100, 300, "-");
    buttons[7].setPosAndValue(300, 300, "x");
    buttons[8].setPosAndValue(200, 300, "/");
    buttons[9].setPosAndValue(400, 300, "Neg");
    buttons[10].setPosAndValue(0, 400, "0");
    buttons[11].setPosAndValue(100, 400, "1");
    buttons[12].setPosAndValue(200, 400, "2");
    buttons[13].setPosAndValue(300, 400, "3");
    buttons[14].setPosAndValue(400, 400, ".");
    buttons[15].setPosAndValue(0, 500, "4");
    buttons[16].setPosAndValue(100, 500, "5");
    buttons[17].setPosAndValue(200, 500, "6");
    buttons[18].setPosAndValue(300, 500, "7");
    buttons[19].setPosAndValue(400, 500, "<");
    buttons[20].setPosAndValue(0, 600, "8");
    buttons[21].setPosAndValue(100, 600, "9");
    buttons[22].setPosAndValue(200, 600, "A");
    buttons[23].setPosAndValue(300, 600, "B");
    buttons[24].setPosAndValue(400, 600, "Clr");
    buttons[25].setPosAndValue(0, 700, "C");
    buttons[26].setPosAndValue(100, 700, "D");
    buttons[27].setPosAndValue(200, 700, "E");
    buttons[28].setPosAndValue(300, 700, "F");
    buttons[29].setPosAndValue(400, 700, "=");
}

#endif
