#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span {

private:
	std::vector<int>	_stack;
	size_t				_size;

public:
	Span();
	Span(int N);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &rhs);

	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();

	class FullStackException : public std::exception {
		virtual const char *what() const throw() {
			return "Exception: !Stack is full!";
		}
	};
	class NotEnoughNumbersException : public std::exception {
		virtual const char *what() const throw() {
			return "Exception: !Not enough numbers in the container!";
		}
	};

};

#endif