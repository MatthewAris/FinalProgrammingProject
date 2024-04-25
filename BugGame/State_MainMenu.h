#pragma once
#include "BaseState.h"
class State_MainMenu :
    public BaseState
{
public:
    State_MainMenu(StateManager* l_stateManager) : BaseState(l_stateManager) {};
    ~State_MainMenu() {};

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate() {};

    void Update(const sf::Time& l_time) {};
    void Draw();

    void MouseClick(EventDetails* l_details);
private:
    sf::Text m_text;
    sf::Font m_font;

    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    unsigned int m_buttonPadding;

    sf::RectangleShape m_rects[3];
    sf::Text m_labels[3];
};