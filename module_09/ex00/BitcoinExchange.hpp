/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:23:29 by brivera           #+#    #+#             */
/*   Updated: 2026/01/28 17:17:32 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string,float>		_dataBase;
		float							_stringToFloat(const std::string& str) const;
		bool							_isValidDate(const std::string& date) const;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		void	loadDataBase(const std::string& file);
		void	processInput(const	std::string& file) const;

		float	getExchangeRate(const std::string &date) const;
};


#endif