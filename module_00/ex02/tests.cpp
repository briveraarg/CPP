// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

/*
int		main( void ) {                                   // 1) función principal: punto de entrada del programa

    typedef std::vector<Account::t>							  accounts_t;   // 2) alias: accounts_t == std::vector<Account>
    typedef std::vector<int>								  ints_t;       // 3) alias: ints_t == std::vector<int>
    typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // 4) alias: par de iteradores (uno para accounts, otro para ints)

    int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // 5) arreglo C de saldos iniciales
    size_t const			amounts_size( sizeof(amounts) / sizeof(int) );            // 6) tamaño del arreglo (nº elementos)
    accounts_t				accounts( amounts, amounts + amounts_size );             // 7) crea un vector<Account> usando el constructor rango:
                                                                                     //    desde &amounts[0] hasta &amounts[amounts_size-1]
    accounts_t::iterator	acc_begin	= accounts.begin();                             // 8) iterador al primer Account del vector
    accounts_t::iterator	acc_end		= accounts.end();                               // 9) iterador al justo después del último Account

    int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };             // 10) arreglo de depósitos a aplicar
    size_t const		d_size( sizeof(d) / sizeof(int) );                         // 11) tamaño del arreglo de depósitos
    ints_t				deposits( d, d + d_size );                               // 12) vector<int> inicializado con los depósitos
    ints_t::iterator	dep_begin	= deposits.begin();                              // 13) iterador al primer depósito
    ints_t::iterator	dep_end		= deposits.end();                                // 14) iterador al final de los depósitos

    int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };        // 15) arreglo de retiros a intentar
    size_t const		w_size( sizeof(w) / sizeof(int) );                         // 16) tamaño del arreglo de retiros
    ints_t				withdrawals( w, w + w_size );                           // 17) vector<int> con los valores de retiro
    ints_t::iterator	wit_begin	= withdrawals.begin();                           // 18) iterador al primer retiro
    ints_t::iterator	wit_end		= withdrawals.end();                             // 19) iterador al final de los retiros

    Account::displayAccountsInfos();                                               // 20) llamada a método estático:
                                                                                  //     muestra estadísticas globales (nb accounts, total amount, etc.)
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // 21) aplica displayStatus() a cada Account del vector
                                                                                  //     std::mem_fun_ref(&Account::displayStatus) es un adaptador
                                                                                  //     que llama a la función miembro en cada elemento (C++98 style)

    for ( acc_int_t it( acc_begin, dep_begin );                                    // 22) inicio de un for que recorre DOS contenedores en paralelo:
          it.first != acc_end && it.second != dep_end;                             //     condición: mientras NO llegue al final de accounts Y deposits
          ++(it.first), ++(it.second) ) {                                          //     en cada iteración avanza ambos iteradores
                                                                                  
        (*(it.first)).makeDeposit( *(it.second) );                                // 23) cuerpo del loop:
                                                                                  //     - *(it.first)  => objeto Account al que apunta el iterador
                                                                                  //     - *(it.second) => int (cantidad a depositar)
                                                                                  //     llama makeDeposit en la cuenta con ese monto
    }

    Account::displayAccountsInfos();                                               // 24) vuelve a mostrar estadísticas globales (tras depósitos)
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // 25) vuelve a mostrar el estado de cada cuenta (cada displayStatus)

    for ( acc_int_t it( acc_begin, wit_begin );                                    // 26) otro for paralelo: cuentas vs. lista de retiros
          it.first != acc_end && it.second != wit_end;
          ++(it.first), ++(it.second) ) {

        (*(it.first)).makeWithdrawal( *(it.second) );                             // 27) intenta retirar de cada cuenta la cantidad correspondiente;
                                                                                  //     makeWithdrawal devuelve bool (si succeed o no)
    }

    Account::displayAccountsInfos();                                               // 28) muestra estadísticas globales tras los retiros
    std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // 29) muestra estado final de cada cuenta

    return 0;                                                                      // 30) devuelve 0: ejecución correcta
}

*/