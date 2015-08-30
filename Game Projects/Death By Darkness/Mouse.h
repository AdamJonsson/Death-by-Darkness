#pragma once
class Mouse
{
public:
	Mouse();

	void update();

	int x, y;
	bool leftButton = false;
	bool rightButton = false;

	~Mouse();
};

