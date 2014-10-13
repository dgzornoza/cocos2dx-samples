#include "StringUtils.h"

#include <unordered_map>
#include <regex>
#include <sstream>

//#include "VectorUtils.h"

namespace Toolkit {


/** Funcion para separar una cadena por los delimitadores especificados. */
std::vector<std::string> StringUtils::Split(const std::string& _string, const std::vector<std::string>& _delimiters)
{
	// unir todos los delimitadores para crear la expresion regular
	std::regex rgx(RegexScapeString(Join(_delimiters, "|")));
	// obtener el iterador del primer y ultimo elmento
	std::sregex_token_iterator first{ std::begin(_string), std::end(_string), rgx, -1 }, last;

	// crear un vector con el rango entre el primer y ultimo elemento encontrado en la expesion regular
	std::vector<std::string> result { first, last };
	return result;
}

/** Funcion para separar una cadena por el delimitadores especificados. */
std::vector<std::string> StringUtils::Split(const std::string & _string, const std::string & _delimiter)
{
	// crear un vector con la cadena e invocar la funcion sobrecargada
	std::vector<std::string> delimiters { _delimiter };
	return Split(_string, delimiters);
}

/** Funcion para unir un vector de cadenas en una unica cadena intercalando el delimitador especificado */
std::string StringUtils::Join(const std::vector<std::string> & _strings, const std::string & _delimiter)
{
	// crear un stream e insertar el primer elemento
	std::stringstream stream;
	stream << _strings.front();
	// recorrer el resto de elementos y separarlos por el delimitador
	std::for_each(std::begin(_strings) + 1, std::end(_strings), [&](const std::string &elem) { stream << _delimiter << elem; });

	// retornar la cadena
	return stream.str();
}

/** Funcion obtener el caracter de escape en expresiones regulares correpondiente al caracter de entrada */
std::string StringUtils::RegexScapeChar(char _char) 
{
	// caracteres de escape
	const std::unordered_map<char, std::string> ScapedSpecialCharacters = {
	  {'.', "\\."}, {'|', "\\|"}, {'*', "\\*"}, {'?', "\\?"},
	  {'+', "\\+"}, {'(', "\\("}, {')', "\\)"}, {'{', "\\{"},
	  {'}', "\\}"}, {'[', "\\["}, {']', "\\]"}, {'^', "\\^"},
	  {'$', "\\$"}, {'\\', "\\\\"}
	};

	// buscar el caracter	
	auto it = ScapedSpecialCharacters.find(_char);

	// retornar el caracter de escape si se ha encontrado, o el propio caracter si no se encuentra
	return it == ScapedSpecialCharacters.end() ? std::string(1, _char) : it->second;
}

/** Funcion codificar una cadena en caracteres de escape usados en expresiones regulares donde sean encontrados */
std::string StringUtils::RegexScapeString(const std::string & _string) 
{
	// crear un stream para ir codificando la cadena con caracteres de escape
	std::stringstream stream;
	// recorrer toda la cadena y codificarla
	for (auto& character : _string)
	{
		stream << RegexScapeChar(character);
	}

	return stream.str();
}


} // namespace Toolkit