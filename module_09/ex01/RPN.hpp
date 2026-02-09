/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:50:56 by brivera           #+#    #+#             */
/*   Updated: 2026/02/09 17:13:42 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <climits>
#include <string>

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"

class RPN
{
	private:
		std::stack<int>		_pilaNumber;
		bool				_isOperator(char c) const;
		void				_performOperation(char op);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int	calculator(const std::string& input);
};

#endif