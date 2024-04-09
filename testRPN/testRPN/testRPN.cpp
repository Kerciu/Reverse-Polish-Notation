#include "CppUnitTest.h"
#include "../../RPN/RPN/Stack.h"
#include <string>
#include <sstream>

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

		TEST_METHOD(StackDeepCopy)
		{
			char table[] = { 'a', 'b', 'c' };
			Stack stack;

			for (char v : table) {
				stack.push(v);
			}
			Stack stackcopy = stack.copyStack();

			Assert::AreEqual(stack, stackcopy);
		}

		TEST_METHOD(CheckIfEmptyStack)
		{
			Stack stack;
			Assert::IsTrue(stack.isEmpty());
			Assert::AreEqual((int) stack.size(), 0);
		}

		TEST_METHOD(ClearStack)
		{
			char table[] = { 'a', 'b', 'c' };
			Stack stack;

			for (char v : table) {
				stack.push(v);
			}

			stack.clear();
			Assert::IsTrue(stack.isEmpty());
			Assert::AreEqual((int)stack.size(), 0);
		}

		TEST_METHOD(StackAssignOperator)
		{
			char table1[] = { 'a', 'b', 'c' };
			char table2[] = { 'd', 'e', 'f' };
			Stack stack1;
			Stack stack2;
			for (char v : table1) {
				stack1.push(v);
			}
			for (char v : table2) {
				stack2.push(v);
			}

			stack1 = stack2;

			Assert::AreEqual(stack1, stack2);
		}

		TEST_METHOD(StackOutputOperator)
		{
			char table1[] = { 'a', 'b', 'c' };
			Stack stack1;
			for (char v : table1) {
				stack1.push(v);
			}
			std::ostringstream oss;
			oss << stack1;

			Assert::AreEqual(std::string("[ a ]\n[ b ]\n[ c ]\n"), oss.str());
		}

		TEST_METHOD(StackPeekAndPop)
		{
			char table1[] = { 'a', 'b', 'c' };
			Stack stack1;
			for (char v : table1) {
				stack1.push(v);
			}
			char peek = stack1.peek();
			char pop = stack1.pop();

			Assert::AreEqual(peek, 'a');
			Assert::AreEqual(peek, pop);
			Assert::AreEqual(stack1.peek(), 'b');
		}

		TEST_METHOD(StackSearch) {
			char table1[] = { 'a', 'b', 'c' };
			Stack stack1;
			Stack stack2;
			for (char v : table1) {
				stack1.push(v);
			}
			int idx = stack1.search('b');
			Assert::AreEqual(idx, 1);
			Assert::ExpectException<empty_stack>([&]() {
				stack2.search('a');
			});
		}
	};
}
