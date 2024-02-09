#pragma once
#include <cstdint>

class health {
public:
	//Getters
	uint16_t getMaxHP() { return m_maxHP; }
	uint16_t getCurrentHP() { return m_currentHP; }

	//Setters
	bool setMaxHP(uint16_t maxHP) {
		if (maxHP < 1)
			return false;

		m_maxHP = maxHP;

		if (m_currentHP > m_maxHP)
			m_currentHP = m_maxHP;

		return true;
	}

	void takeDMG(uint16_t damage) {
		if (damage > m_currentHP) {
			m_currentHP = 0;
			return;
		}

		m_currentHP -= damage;
	}

	void heal(uint16_t amount) {
		if (amount + m_currentHP > m_maxHP) {
			m_currentHP = m_maxHP;
			return;
		}

		m_currentHP += amount;
	}

protected:
	health(uint16_t maxHP) {
		m_maxHP = maxHP;
		m_currentHP = m_maxHP;
	}

private:
	std::uint16_t m_currentHP;
	std::uint16_t m_maxHP;
};