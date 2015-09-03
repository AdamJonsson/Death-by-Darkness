#pragma once
class Keyboard
{
public:
	Keyboard();

	bool esc = false;
	bool space = false;

	void update();

	~Keyboard();
};



