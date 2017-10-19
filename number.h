#pragma once
#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <sstream>
//symbol(), value() and match()
using std::string;

class Number : public Term {
public:
	Number(double s) :_symbol(std::to_string(s)){
		ss << s;
		_value = ss.str();
	}
	
	string symbol() const {
		return _symbol;
	}
	string value() const {
		return _value;
	}

	bool match(Term &a) {
		_assignable = true;
		if (a.value().length() == 0)
			a.value() = _symbol;
		if (a.value() != _value)
			_assignable = false;
		return _assignable;
	}

private:
	std::stringstream ss;
	bool _assignable;
	string _value;
	string  _symbol;

};

#endif