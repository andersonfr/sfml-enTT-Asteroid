#include "App.h"

void App::Run()
{
	m_game = std::make_unique<Game>();
	m_game->OnInit();

}

void App::Stop()
{
	m_game->OnEnd();
}
