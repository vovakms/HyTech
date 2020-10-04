#define _CRT_SECURE_NO_WARNINGS

#include "HyTech.h" 
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
 
std::string  Char2Hex     ( std::vector<char> i_chars , size_t i_size ) ;
static void  FormatBinary ( std::ostream &out, std::vector<char> *data, size_t sz, const bool raw ) ;

void main()
{
	    //setlocale(LC_ALL, "");
		 
	    CConnection Conect1 ; //
	    
		Conect1.Connect("tcpip:/localhost:13000" , "HTADMIN" , "PASSWORD");

		CStatement  Query1(Conect1, "fix all; select * from TAB4;")  ;   // ALARM   SKU
   
		size_t    cols = Query1.GetColumns() ;
		size_t    rows = Query1.GetRows()    ;

		auto masResult = Query1.ReadResults(0, Query1.GetRows());
		char        *p = masResult.data() ;
		 
		std::stringstream stream;
		 
		for (size_t i = 0; i < rows; ++i)//идем по строкам
		{
			
			for (size_t j = 0; j < cols; ++j)// идем по колонкам
			{

				 switch ( Query1.GetColumnsInfo(j)->type  )// в зависимости от типа колонки преобразовываем в соответствующий тип
				 {
					case HSCLI_ET_CHAR: // 0 ћассив символов длиной не более заданной
					{
					    std::string s(p, Query1.GetColumnsInfo(j)->len );
						stream << s.c_str() << " " ;
						 
				    }
					            break;

					case HSCLI_ET_ARRA: { // 1 ћассив байтов заданной длины 
					   std::vector<char>  arr(p, p + Query1.GetColumnsInfo(j)->len  ) ;
					  // FormatBinary( stream,  &arr, Query1.GetColumnsInfo(j)->len  , true);
                       stream << Char2Hex(arr, Query1.GetColumnsInfo(j)->len ) << " ";
				 	}
						         break;

					case HSCLI_ET_BYTE: {  // 2 Ёлемент - unsigned char (короткое целое)  short
						//std::cout << *reinterpret_cast<unsigned char *>(p) << "  ";
						stream << uint32_t(*reinterpret_cast<unsigned char *>(p)) << "  ";
					}
					 			 	break;

					case HSCLI_ET_INTR:  // 3 Ёлемент - signed short  
						stream << *reinterpret_cast<signed short *>(p) << "  " ;
					 				break;

					case HSCLI_ET_WORD:  // 4 Ёлемент - unsigned short  
						stream << *reinterpret_cast<unsigned short *>(p) << "  " ;
					 				break;

					case HSCLI_ET_DATE: {  // 5 ƒата    - unsigned short  
						    unsigned	 day=0, month = 0, year = 0;
							hcSqlUnpackDate(*reinterpret_cast<unsigned short *>(p), &day, &month, &year);
							stream << day  << "-" << month << "-" << year << "  ";
					}
					  		break;

					case HSCLI_ET_NMBR: {//6  Ќомер   - 3-х байтовое целое без знака  
										 // std::cout << *reinterpret_cast<  *>(p);
										 //dR[j] = ;
					}
										break;

					case HSCLI_ET_LONG:  //7 Ёлемент - long int 
						stream << *reinterpret_cast<long int *>(p) << "  ";
					 				break;

					case  HSCLI_ET_DWRD:   // 8 Ёлемент - unsigned long int  в Ѕƒ это dword          
						stream << *reinterpret_cast<unsigned long int *>(p) << "  ";
					 					 break;

					case HSCLI_ET_FLOA:  //	9  Ёлемент - float
						stream << *reinterpret_cast<float *>(p) << "  ";
					 					break;

					case HSCLI_ET_CURR:   //	10 ƒеньги (double)  
						stream << *reinterpret_cast<double *>(p) << "  ";
					 					break;

					case HSCLI_ET_DFLT:   // 11 Ёлемент - double  
						stream << *reinterpret_cast<double *>(p) << "  ";
					 					break;

					case HSCLI_ET_QINT:   //	12 Ёлемент - signed __int64 
						stream << *reinterpret_cast<signed __int64 *>(p) << "  ";
					 					break;

					case HSCLI_ET_QWRD:   //	13 Ёлемент - unsigned __int64 
						stream << *reinterpret_cast<unsigned __int64 *>(p) << "  ";
					 					break;
				 }
			     
				 p += Query1.GetColumnsInfo(j)->len;// сдвигаем указатель на длину пол€, чтобы указывал на начало следующего пол€

			}
			
			 stream   << std::endl;
		}
		
		std::cout << stream.str() << std::endl;

		std::system("pause") ; 
}  
 
std::string  Char2Hex(std::vector<char>  i_chars , size_t i_size)
{
	static char hex_array[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	std::string result;
	result.resize(i_size * 2);
	for (size_t i = 0; i < i_size; ++i)
	{
		result[2 * i] = hex_array[i_chars[i] / 16];
		result[2 * i + 1] = hex_array[i_chars[i] % 16];
	}
	return result;
}
 
static void FormatBinary(std::ostream &out, std::vector<char> *data, size_t sz , const bool raw )
{
	 
	if (!sz || !data)
		return;
  
	const size_t _n = (raw ? sizeof("'\\xXX',") : sizeof("XX")) - 1;
	//char buf[(sz * _n) + 1];
	char *buf = new char[(sz * _n) + 1];
	char *psz = buf;
	for (auto end = data + sz; data != end; ++data, psz += _n)
		 sprintf (psz, raw ? "'\\x%02X'," : "%02X", *data);

		out << psz;
}
