/*
 * counter.h
 *
 *  Created on: 03 Apr 2012
 *      Author: simon
 */

#ifndef COUNTER_H_
#define COUNTER_H_

#include <iostream>
#include <string>
#include <typeinfo>

namespace sjp {

template <typename T>
class counter
{
public:
	static std::size_t created;
	static std::size_t alive;

	counter()
		{ ++created; ++alive; }

	static void print_counts(std::ostream & out, const std::string & type)
	{
		out << "Created " << created << ' ' << type << "(s). "
			<< alive << " still alive." << std::endl;
	}
protected:
	~counter() // objects should never be removed through pointers of this type
		{ --alive; }
};
template <typename T> std::size_t counter<T>::created( 0 );
template <typename T> std::size_t counter<T>::alive( 0 );

};

#endif /* COUNTER_H_ */
