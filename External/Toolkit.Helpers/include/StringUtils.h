#ifndef __STRING_UTILS_H__
#define __STRING_UTILS_H__

#include <string>
#include <vector>

namespace Toolkit {
	namespace Helpers {

		/** @brief clase con utilidades para trabajar con cadenas */
		class StringUtils
		{

		public:

			/** Funcion para separar una cadena por los delimitadores especificados.
			* @param _string cadena que donde sera realizada la operacion
			* @param _delimiters vector de delimitadores para separar la cadena
			* @return vector de cadenas que han sido separadas por el delimitador
			*/
			static std::vector<std::string> Split(const std::string & _string, const std::vector<std::string> & _delimiters);

			/** Funcion para separar una cadena por el delimitadores especificados.
			* @param _string cadena que donde sera realizada la operacion
			* @param _delimiter delimitador para separar la cadena
			* @return vector de cadenas que han sido separadas por el delimitador
			*/
			static std::vector<std::string> Split(const std::string & _string, const std::string & _delimiter);

			/** Funcion para unir un vector de cadenas en una unica cadena intercalando el delimitador especificado
			* @param _str cadena que donde sera realizada la operacion
			* @param _delimiter delimitador para intercalar entre las cadenas de entrada
			* @return cadenas con las cadenas de entrada unidas por el delimitador
			*/
			static std::string Join(const std::vector<std::string> & _strings, const std::string & _delimiter);

		private:

			/** Funcion obtener el caracter de escape en expresiones regulares correpondiente al caracter de entrada
			* @param _char caracter del cual se quiere obtener el caracter de escape para usar en una expresion regular
			* @return caracter de escape para usar en una expresion regular
			*/
			static std::string RegexScapeChar(char _char);

			/** Funcion codificar una cadena en caracteres de escape usados en expresiones regulares donde sean encontrados
			* @param _string cadena donde seran buscados los caracteres de escape usados en expresiones regulares
			* @return cadena codificada con los caracteres de escape para poder usarse en expresiones regulares
			*/
			static std::string RegexScapeString(const std::string& _string);

		};

	} //namespace Helpers
} // namespace Toolkit

#endif // __STRING_UTILS_H__

