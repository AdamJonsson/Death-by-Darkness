#pragma once
class Keyboard
{
public:
	Keyboard();

	bool esc = false;
	bool up = false, left = false, right = false, down = false;

	void update();

	~Keyboard();
};



