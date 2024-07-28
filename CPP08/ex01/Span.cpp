#include "Span.hpp"

Span::Span() : _stack(), _size(0) {}

Span::Span(int N) : _stack(), _size(N) {}

Span::Span(const Span &rhs) {
	*this = rhs;
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_size = rhs._size;
		_stack = rhs._stack;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_stack.size() == _size)
		throw Span::FullStackException();
	_stack.push_back(num);
}

int Span::shortestSpan() {
	if (_stack.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> copy(_stack);
	std::sort(copy.begin(), copy.end());

	int shortestSpan = copy[1] - copy[0];
	for (size_t i = 2; i < copy.size(); i++) {
		int span = copy[i] - copy[i - 1];
		if (span < shortestSpan)
			shortestSpan = span;
	}

	return shortestSpan;
}

int Span::longestSpan() {
	if (_stack.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> copy(_stack);
	std::sort(copy.begin(), copy.end());

	int longestSpan = copy[1] - copy[0];
	for (size_t i = 2; i < copy.size(); i++) {
		int span = copy[i] - copy[i - 1];
		if (span > longestSpan)
			longestSpan = span;
	}

	return longestSpan;
}
