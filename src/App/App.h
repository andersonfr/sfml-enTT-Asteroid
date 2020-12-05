#pragma once
#include <memory>
#include "Game.h"

class App 
{
public:

	App() = default;
	~App() = default;

	void Run();
	void Stop();

private:
	std::unique_ptr<Game> m_game;
};