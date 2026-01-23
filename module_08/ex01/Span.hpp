/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:22:13 by brivera           #+#    #+#             */
/*   Updated: 2026/01/23 14:26:46 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class	Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_v;
	
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		
		Span&	operator=(const Span& other);
		int		operator[](unsigned int index) const;
		
		~Span();
		
		class limitSizeExeption : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class notSpaceExeption : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class fillException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		void	addNumber(int num);

		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) > static_cast<long>(this->_size - this->_v.size()))
				throw Span::notSpaceExeption();
			this->_v.insert(this->_v.end(), begin, end);
		}

		int		shortestSpan() const;
		int		longestSpan() const;
};


#endif