#ifndef MYENUM_H
#define MYENUM_H

class MyEnum
{
public:
	enum State
	{
		Start,
		Play,
		Pause,
		GameOver,
		Exit
	};

	enum Direction
	{
		Up,
		Down,
		Left,
		Right
	};
};

#endif