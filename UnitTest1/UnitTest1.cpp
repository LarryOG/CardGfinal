#include "pch.h"
#include "../CardGfinal/Card.h"
#include "../CardGfinal/Deck.h"

#include "CppUnitTest.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(CardTests)
	{
	public:

		Card power5 = Card(Card::Type::PowerPlus, 5);
		Card steal1 = Card(Card::Type::Steal, 1);
		
		TEST_METHOD(CardTest1)
		{
			
		}
	};
}
