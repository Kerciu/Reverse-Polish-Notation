#include "CppUnitTest.h"
#include "../../RPN/RPN/Stack.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testRPN
{
	TEST_CLASS(testRPN)
	{
	public:
		
		TEST_METHOD(CreateStack)
		{
			Stack stack1;
			stack1.push('a');
			Assert::AreEqual(std::string(1, stack1.pop()), std::string("a"));
		}
	};
}
