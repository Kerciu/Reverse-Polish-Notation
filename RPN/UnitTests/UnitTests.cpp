#include "CppUnitTest.h"
#include "../../RPN/RPN/Stack.h"
#include "../../RPN/RPN/exceptions.h"
#include "../../RPN/RPN/Operator.h"
#include "../../RPN/RPN/Handler.h"
#include <exception>
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
			Assert::AreEqual((int)stack.size(), 0);
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
			Assert::ExpectException<no_element_found>([&] { stack1.search('d'); });
		}
		TEST_METHOD(DefaultConstructorTest)
		{
			Operator op;
			Assert::AreEqual('+', op.getOperator());
		}

		TEST_METHOD(ConstructorWithValidOperatorTest)
		{
			Operator op('+');
			Assert::AreEqual('+', op.getOperator());
		}

		TEST_METHOD(ConstructorWithInvalidOperatorTest)
		{
			Assert::ExpectException<wrong_operator>([] { Operator op('@'); });
		}

		TEST_METHOD(SetterTest)
		{
			Operator op;
			op.setOperator('*');
			Assert::AreEqual('*', op.getOperator());
		}

		TEST_METHOD(AdditionTest)
		{
			Operator op('+');
			int result = op.handleOperator(5, 3);
			Assert::AreEqual(8, result);
		}

		TEST_METHOD(SubtractionTest)
		{
			Operator op('-');
			int result = op.handleOperator(5, 3);
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(MultiplicationTest)
		{
			Operator op('*');
			int result = op.handleOperator(5, 3);
			Assert::AreEqual(15, result);
		}

		TEST_METHOD(DivisionTest)
		{
			Operator op('/');
			int result = op.handleOperator(6, 3);
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(ZeroDivisionTest)
		{
			Operator op('/');
			Assert::ExpectException<zero_division_error>([&] { op.handleOperator(5, 0); });
		}

		TEST_METHOD(ModuloTest)
		{
			Operator op('%');
			int result = op.handleOperator(7, 3);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(ExponentiationTest)
		{
			Operator op('^');
			int result = op.handleOperator(2, 3);
			Assert::AreEqual(8, result);
		}

		TEST_METHOD(InvalidOperatorTest)
		{
			Operator op('@');
			Assert::ExpectException<wrong_operator>([&] { op.handleOperator(5, 3); });
		}

		TEST_METHOD(StackifyExpressionTest)
		{
			Stack stack;
			Handler handler("5+3*2");
			int result = handler.stackifyExpression(stack);
			Assert::AreEqual(11, result);
		}

		TEST_METHOD(EmptyExpressionTest)
		{
			Stack stack;
			Handler handler("");
			Assert::ExpectException<empty_expression>([&] { handler.stackifyExpression(stack); });
		}

		TEST_METHOD(IncorrectExpressionTest)
		{
			Stack stack;
			Handler handler("5+x*2");
			Assert::ExpectException<incorrect_expression>([&] { handler.stackifyExpression(stack); });
		}

		TEST_METHOD(InsufficientArgumentsTest)
		{
			Stack stack;
			Handler handler("5+");
			Assert::ExpectException<insufficient_arguments>([&] { handler.stackifyExpression(stack); });
		}

		TEST_METHOD(StackUnderflowTest)
		{
			Stack stack;
			Handler handler("5+3*2");
			stack.pop();
			Assert::ExpectException<stack_underflow>([&] { handler.stackifyExpression(stack); });
		}

	};
}
