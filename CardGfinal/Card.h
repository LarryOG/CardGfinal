#pragma once
class Card
{
public:
	enum class Type {PowerPlus, PowerMinus, Steal};
	Card(Type t, int power) : power_(power), type_(t) {}
	~Card() = default;
	
	Type getType() const { return type_; }
	int getPower() const { return power_; }
private:
	int power_;
	Type type_;
};

