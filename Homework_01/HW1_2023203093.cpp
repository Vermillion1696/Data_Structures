#include <iostream>
#include <stdexcept>
#include <string>
#include "MyStringVector.h"

using namespace std;

// Consolidated test class for all tests
class errTest {
public:

	// These functions test functions which are related to constructors and destructors.
	void testDefaultConstructor() {
		try {
			MyStringVector vec;
			if (vec.get_size() == 0 && vec.get_capacity() == 0) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: incorrect size or capacity\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in default constructor: " << e.what() << "\n";
		}
	}
	void testCapacityConstructor(size_t capacity) {
		try {
			MyStringVector vec(capacity);
			if (vec.get_size() == 0 && vec.get_capacity() == capacity) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: incorrect size or capacity\n";
			}
		}
		catch (const std::bad_alloc& e) {
			cerr << "exception in capacity constructor: " << e.what() << "\n";
		}
		catch (const exception& e) {
			cerr << "exception in capacity constructor: " << e.what() << "\n";
		}
	}
	void testCopyConstructor(const MyStringVector& original) {
		try {
			MyStringVector copy(original);
			bool passed = true;

			if (copy.get_size() != original.get_size() || copy.get_capacity() != original.get_capacity()) {
				passed = false;
			}
			else {
				for (size_t i = 0; i < original.get_size(); ++i) {
					if (copy[i] != original[i]) {
						passed = false;
						break;
					}
				}
			}

			if (passed) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: copy not identical to original\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in copy constructor: " << e.what() << "\n";
		}
	}

	// These functions test functions which are related to memory management.
	void testShrinkToFit(MyStringVector& vec) {
		try {
			size_t old_capacity = vec.get_capacity();
			vec.shrink_to_fit();
			if (vec.get_capacity() == vec.get_size()) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: capacity not shrunk correctly\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in shrink_to_fit: " << e.what() << "\n";
		}
	}
	void testReserve(MyStringVector& vec, size_t new_capacity) {
		try {
			vec.reserve(new_capacity);
			if (vec.get_capacity() >= new_capacity) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: reserve did not update capacity correctly\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in reserve: " << e.what() << "\n";
		}
	}

	// These functions test functions which are related to data management.
	void testPushBack(MyStringVector& vec, const string& value) {
		try {
			size_t old_size = vec.get_size();
			vec.push_back(value);
			if (vec.get_size() == old_size + 1 && vec[old_size] == value) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: value not added correctly\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in push_back: " << e.what() << "\n";
		}
	}
	void testPopBack(MyStringVector& vec) {
		try {
			if (vec.get_size() > 0) {
				size_t old_size = vec.get_size();
				vec.pop_back();
				if (vec.get_size() == old_size - 1) {
					cout << "passed\n";
				}
				else {
					cerr << "failed: size not decremented correctly\n";
				}
			}
			else {
				cerr << "failed: cannot pop_back from an empty vector\n";
			}
		}
		catch (const out_of_range& e) {
			cerr << "exception in pop_back: " << e.what() << "\n";
		}
		catch (const exception& e) {
			cerr << "exception in pop_back: " << e.what() << "\n";
		}
	}
	
	// These functions test functions which are related to data status.
	void testIsEmpty(MyStringVector& vec) {
		try {
			if (vec.is_empty()) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: vector is not empty when expected to be empty\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in is_empty: " << e.what() << "\n";
		}
	}
	void testClear(MyStringVector& vec) {
		try {
			vec.clear();
			if (vec.get_size() == 0 && vec.get_capacity() == 0) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: vector not cleared properly\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in clear: " << e.what() << "\n";
		}
	}

	// These functions test functions which are getter and setter.
	void testSizeGetterSetter(MyStringVector& vec, size_t new_size) {
		try {
			if (new_size <= vec.get_capacity()) {
				vec.set_size(new_size);
				if (vec.get_size() == new_size) {
					cout << "passed\n";
				}
				else {
					cerr << "failed: size setter/getter mismatch\n";
				}
			}
			else {
				cerr << "failed: new_size exceeds current capacity\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in size getter/setter: " << e.what() << "\n";
		}
	}
	void testCapacityGetterSetter(MyStringVector& vec, size_t new_capacity) {
		try {
			vec.set_capacity(new_capacity);
			if (vec.get_capacity() == new_capacity) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: capacity setter/getter mismatch\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in capacity getter/setter: " << e.what() << "\n";
		}
	}

	// These functions test operators.
	void testAssignmentOperator(MyStringVector& lhs, const MyStringVector& rhs) {
		try {
			lhs = rhs;
			bool passed = true;

			if (lhs.get_size() != rhs.get_size() || lhs.get_capacity() != rhs.get_capacity()) {
				passed = false;
			}
			else {
				for (size_t i = 0; i < rhs.get_size(); ++i) {
					if (lhs[i] != rhs[i]) {
						passed = false;
						break;
					}
				}
			}

			if (passed) {
				cout << "passed\n";
			}
			else {
				cerr << "failed: assignment incorrect\n";
			}
		}
		catch (const exception& e) {
			cerr << "exception in =operator: " << e.what() << "\n";
		}
	}
	void testOperatorIndex(MyStringVector& vec, size_t index) {
		try {
			if (index < vec.get_size()) {
				string value = vec[index];
				cout << "passed\n";
			}
			else {
				cerr << "failed: index out of range\n";
			}
		}
		catch (const out_of_range& e) {
			cerr << "exception in []operator: " << e.what() << "\n";
		}
		catch (const exception& e) {
			cerr << "exception in []operator: " << e.what() << "\n";
		}
	}
};

int main() {
	errTest test;  // Declared once here

	// !! Compile Test !!
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "         Compile Test         " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		// Default constructor tests
		cout << "========== Default Constructor ==========" << endl;
		test.testDefaultConstructor();
		cout << endl;

		// Capacity constructor tests
		cout << "========== Capacity Constructor ==========" << endl;
		test.testCapacityConstructor(10); // Expected to pass
		cout << endl;

		// Copy constructor tests
		cout << "========== Copy Constructor ==========" << endl;
		MyStringVector originalVec;
		originalVec.push_back("test");
		test.testCopyConstructor(originalVec); // Expected to pass
		cout << endl;

		// Shrink to fit tests
		cout << "========== Shrink to Fit ==========" << endl;
		MyStringVector vecForShrink(10);
		vecForShrink.push_back("item1");
		vecForShrink.push_back("item2");
		test.testShrinkToFit(vecForShrink); // Expected to pass
		cout << endl;

		// Reserve tests
		cout << "========== Reserve ==========" << endl;
		MyStringVector vecForReserve;
		test.testReserve(vecForReserve, 20);  // Expected to pass
		cout << endl;

		// Push back tests
		cout << "========== Push Back ==========" << endl;
		MyStringVector vecForPushBack;
		test.testPushBack(vecForPushBack, "hello"); // Expected to pass
		cout << endl;

		// Pop back tests
		cout << "========== Pop Back ==========" << endl;
		MyStringVector vecForPopBack;
		vecForPopBack.push_back("item");
		test.testPopBack(vecForPopBack); // Expected to pass
		test.testPopBack(vecForPopBack); // Expected to fail (cannot pop empty vector)
		cout << endl;

		// is_empty() tests
		cout << "========== Is Empty ==========" << endl;
		MyStringVector vecForEmpty;
		test.testIsEmpty(vecForEmpty); // Expected to pass (empty vector)
		vecForEmpty.push_back("item");
		test.testIsEmpty(vecForEmpty); // Expected to fail (vector is not empty)
		cout << endl;

		// clear() tests
		cout << "========== Clear ==========" << endl;
		MyStringVector vecForClear;
		vecForClear.push_back("item1");
		vecForClear.push_back("item2");
		test.testClear(vecForClear); // Expected to pass (vector should be cleared)
		cout << endl;

		// Size getter/setter tests
		cout << "========== Size Getter/Setter ==========" << endl;
		MyStringVector vecForSize(5);
		vecForSize.push_back("item1");
		test.testSizeGetterSetter(vecForSize, 1); // Expected to pass
		test.testSizeGetterSetter(vecForSize, 0); // Expected to pass (set size to 0)
		cout << endl;

		// Capacity getter/setter tests
		cout << "========== Capacity Getter/Setter ==========" << endl;
		MyStringVector vecForCapacity;
		test.testCapacityGetterSetter(vecForCapacity, 10); // Expected to pass
		cout << endl;

		// Assignment operator tests
		cout << "========== Assignment Operator ==========" << endl;
		MyStringVector lhsVec;
		MyStringVector rhsVec;
		rhsVec.push_back("data");
		test.testAssignmentOperator(lhsVec, rhsVec); // Expected to pass
		cout << endl;

		// Index operator tests
		cout << "========== Index Operator ==========" << endl;
		MyStringVector vecForIndexing;
		vecForIndexing.push_back("first");
		test.testOperatorIndex(vecForIndexing, 0);  // Expected to pass
		test.testOperatorIndex(vecForIndexing, 1);  // Expected to fail (index out of bounds)
		cout << endl;
	}

	// !! Output Test !!
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "          Output Test         " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		// Default Constructor Output Test
		{
			MyStringVector vec;
			cout << "========== Default Constructor Output Test ==========" << endl;
			cout << "Size: " << vec.get_size() << ", Capacity: " << vec.get_capacity() << endl;
			cout << endl;
		}

		// Shrink to Fit Output Test
		{
			MyStringVector vecForShrink(10);
			vecForShrink.push_back("item1");
			vecForShrink.push_back("item2");
			cout << "========== Shrink to Fit Output Test ==========" << endl;
			cout << "Before shrink_to_fit -> Size: " << vecForShrink.get_size() << ", Capacity: " << vecForShrink.get_capacity() << endl;
			vecForShrink.shrink_to_fit();
			cout << "After shrink_to_fit -> Size: " << vecForShrink.get_size() << ", Capacity: " << vecForShrink.get_capacity() << endl;
			cout << endl;
		}

		// Push Back Output Test
		{
			MyStringVector vecForPushBack;
			cout << "========== Push Back Output Test ==========" << endl;
			vecForPushBack.push_back("hello");
			cout << "After push_back -> Size: " << vecForPushBack.get_size() << ", Capacity: " << vecForPushBack.get_capacity() << endl;
			cout << endl;
		}

		// Pop Back Output Test
		{
			MyStringVector vecForPopBack;
			vecForPopBack.push_back("item");
			cout << "========== Pop Back Output Test ==========" << endl;
			cout << "Before pop_back -> Size: " << vecForPopBack.get_size() << endl;
			vecForPopBack.pop_back();
			cout << "After pop_back -> Size: " << vecForPopBack.get_size() << endl;
			cout << endl;
		}

		// Is Empty Output Test
		{
			MyStringVector vecForEmpty;
			cout << "========== Is Empty Output Test ==========" << endl;
			cout << "Is Empty: " << (vecForEmpty.is_empty() ? "Yes" : "No") << endl;
			vecForEmpty.push_back("item");
			cout << "Is Empty after adding item: " << (vecForEmpty.is_empty() ? "Yes" : "No") << endl;
			cout << endl;
		}

		// Clear Output Test
		{
			MyStringVector vecForClear;
			vecForClear.push_back("item1");
			vecForClear.push_back("item2");
			cout << "========== Clear Output Test ==========" << endl;
			cout << "Before clear -> Size: " << vecForClear.get_size() << endl;
			vecForClear.clear();
			cout << "After clear -> Size: " << vecForClear.get_size() << ", Capacity: " << vecForClear.get_capacity() << endl;
			cout << endl;
		}

		// Size Getter/Setter Output Test
		{
			MyStringVector vecForSize(5);
			cout << "========== Size Getter/Setter Output Test ==========" << endl;
			vecForSize.push_back("item1");
			cout << "Initial size: " << vecForSize.get_size() << endl;
			vecForSize.set_size(0);
			cout << "After set_size(0) -> Size: " << vecForSize.get_size() << endl;
			cout << endl;
		}

		// Capacity Getter/Setter Output Test
		{
			MyStringVector vecForCapacity;
			cout << "========== Capacity Getter/Setter Output Test ==========" << endl;
			cout << "Initial capacity: " << vecForCapacity.get_capacity() << endl;
			vecForCapacity.set_capacity(10);
			cout << "After set_capacity(10) -> Capacity: " << vecForCapacity.get_capacity() << endl;
			cout << endl;
		}

		// Assignment Operator Output Test
		{
			MyStringVector lhsVec;
			MyStringVector rhsVec;
			rhsVec.push_back("data");
			cout << "========== Assignment Operator Output Test ==========" << endl;
			lhsVec = rhsVec;
			cout << "LHS Size: " << lhsVec.get_size() << ", Capacity: " << lhsVec.get_capacity() << endl;
			cout << endl;
		}
	}

	// !! Additional Test !!
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "        Additional Test       " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		
		// Chaining Assignment Test
		{
			MyStringVector vec1, vec2, vec3;
			vec1.push_back("data1");
			vec2.push_back("data2");
			vec3.push_back("data3");

			cout << "========== Chaining Assignment Test ==========" << endl;

			// Perform chaining assignment
			vec1 = vec2 = vec3;

			// Output results
			cout << "vec1 -> Size: " << vec1.get_size() << ", Capacity: " << vec1.get_capacity() << ", First Element: " << vec1[0] << endl;
			cout << "vec2 -> Size: " << vec2.get_size() << ", Capacity: " << vec2.get_capacity() << ", First Element: " << vec2[0] << endl;
			cout << "vec3 -> Size: " << vec3.get_size() << ", Capacity: " << vec3.get_capacity() << ", First Element: " << vec3[0] << endl;
			cout << endl;
		}

		// Printing Error Message Test
		{
			cout << "========== Printing Error Message Test ==========" << endl;

			MyStringVector vecForErrorTest;
			vecForErrorTest.push_back("first");

			// Accessing an invalid index (this will terminate the program)
			cout << vecForErrorTest[5] << endl;  // This should cause an error message and terminate the program.

			cout << endl;
		}
	}

	return 0;
}
