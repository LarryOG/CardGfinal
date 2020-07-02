#pragma once
class Game;

class Card
{
public:
	enum class Type {PowerPlus, PowerMinus, Steal, Double};
	Card(Type t, int power) : power_(power), type_(t) {}
	~Card() = default;

	bool equals(const Card& c) const;
	void printCard() const;
	Type getType() const { return type_; }
	void setType(Type t) { type_ = t; }
	int getPower() const { return power_; }
	void setPower(int p) { power_ = p; }
	
private:
	int power_;
	Type type_;
};

