#include "Textbox.h"



Textbox::Textbox()
{
	setup(5, 9, 200, Vector2f(0, 0));
}

Textbox::Textbox(int visible, int charSize, int width, Vector2f screenPos)
{
	setup(visible, charSize, width, screenPos);
}

Textbox::~Textbox()
{
	clear();
}

void Textbox::setup(int visible, int charSize, int width, Vector2f screenPos)
{
	numVisible = visible;
	//Margines czcionki (gorny i lewy)
	Vector2f offset(2.0f, 2.0f);

	//Cechy czcionki
	if (!(font.loadFromFile("data/above.ttf")))
	{
		cout << "Nie zaladowano czcionki!";
	}
	content.setFont(font);
	content.setString("");
	content.setCharacterSize(charSize);
	content.setPosition(screenPos + offset);
	//Ustawienie koloru
	content.setFillColor(Color::Black);
	//Cechy tla pola tekstowego
	textBackground.setSize(Vector2f(width, visible * (charSize * 1.2f)));
	textBackground.setFillColor(Color::White);
	textBackground.setPosition(screenPos);
}

void Textbox::add(string message)
{
	messages.push_back(message);
	if (message.size() < 10)
		return;
	//Usuwa wybrany element z vectora
	messages.erase(messages.begin());
}

void Textbox::clear()
{
	messages.clear();
}

void Textbox::render(RenderWindow &window)
{
	string contentR;

	for (auto &itr : messages)
	{
		//Dolacza wiadomosc do stringa
		contentR.append(itr + "\n");
		//cout << "Dolaczono";
	}

	if (contentR != "");
	{
		content.setString(contentR);
		window.draw(textBackground);
		//cout << "Rysuje";
		window.draw(content);
	}
}