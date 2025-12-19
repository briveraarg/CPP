#ifndef SCALARPRINTER_HPP
#define SCALARPRINTER_HPP

#include <string>

bool	my_isnan(double x);
bool	my_isinf(double x);

std::string	formatFloatValue(float f);
std::string	formatDoubleValue(double d);

void	output_char_from_double(double value);
void	output_int_from_double(double value);
void	output_float_from_double(double value);
void	output_double_from_double(double value);

#endif
