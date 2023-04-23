#include<SFML/Graphics.hpp>
#include<sstream>
#include<iostream>
using namespace sf;
using namespace std;

string processText(string nphrase);

int main() {
    VideoMode vm(300, 300);
    RenderWindow window(vm, "Tp N°8");

    string nphrase;

    Text text;
    Font font;
    font.loadFromFile("font/Roboto-Blackitalic.ttf");
    text.setFont(font);
    text.setString("Palabra ingresada");
    text.setPosition(15, 0);

    Text newText;
    newText.setFont(font);
    newText.setString("Palabra procesada");
    newText.setPosition(25, 150);

    cout << "Ingrese una frase: ";
    cin >> nphrase;

    Text phrase;
    phrase.setFont(font);
    phrase.setString(nphrase);
    phrase.setPosition(80, 50);

    Text processPhrase;
    processPhrase.setFont(font);
    processPhrase.setString(processText(nphrase));
    processPhrase.setPosition(80, 200);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();

        window.draw(text);
        window.draw(phrase);
        window.draw(newText);
        window.draw(processPhrase);

        window.display();
    }

    return 0;
}

string processText(string nphrase) {

    for (int i = 0; i < nphrase.size(); i++) {
        if (nphrase[i] == "a"[0]) {
            nphrase[i] = "b"[0];
        }
    }

    return nphrase;
}