/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:22:13 by brivera           #+#    #+#             */
/*   Updated: 2026/01/21 14:38:59 by brivera          ###   ########.fr       */
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
		
		void	addNumber(int num);
		
};


#endif