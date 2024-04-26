#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include <SFML/System/Time.hpp>
#include "SharedContext.h"
#include "BaseState.h"
#include "State_Intro.h"
#include "State_MainMenu.h"
#include "State_Game.h"
#include "State_Paused.h"

using StateContainer = std::vector<std::pair<StateType, BaseState* >> ;
using TypeContainer = std::vector <StateType>;
using StateFactory = std::unordered_map<StateType, std::function<BaseState* (void)>>;

class StateManager
{
public:
	StateManager() {};
	StateManager(SharedContext* l_shared);
	~StateManager();

	void Update(const sf::Time& l_time);
	void Draw();

	void ProcessRequests();
	
	SharedContext* GetContext() { return m_shared; }
	bool HasState(const StateType& l_type);

	void SwitchTo(const StateType& l_type);
	void Remove(const StateType& l_type) { m_toRemove.push_back(l_type); }

private:
	void CreateState(const StateType& l_type);
	void RemoveState(const StateType& l_type);

	template<class T>
	void RegisterState(const StateType& l_type) {
		m_stateFactory[l_type] = [this]() -> BaseState*
			{
				return new T(this);
			};
	}
	SharedContext* m_shared;
	StateContainer m_states;
	TypeContainer m_toRemove;
	StateFactory m_stateFactory;
};

