/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:01 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:02 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>


// verifier les exceptions et on est bon 
int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "not the good number of argument" << std::endl;
		return (1);
	}
	std::string _line;
	std::ifstream _file(av[1]);
	std::string _look = av[2];
	std::string _replace = av[3];
	std::string _final;
	std::string _outfileName = av[1];
	_outfileName += ".replace";
	std::ofstream _outfile(_outfileName);

	if (!_file.is_open())
	{
		std::cerr << "the file can t be opened" << std::endl;
		return (1);
	}

	if (!_outfile.is_open())
	{
		std::cerr << "the outfile can t be opened" << std::endl;
		return (1);
	}

	while (std::getline(_file, _line))
	{
		std::string new_line;
		size_t i = 0;
		while (i < _line.length())
		{
			if (_line.substr(i, _look.length()) == _look)
			// cherche occurence du mot
			{
				new_line += _replace; // nouvelle ligne ajoute replace
				i += _look.length();  // saute le mot qu on cherche
			}
			else
			{
				new_line += _line[i];
				// si on ne trouve pas la string on copie caractere
				i++;
			}
		}
		_final = new_line + "\n";
		_outfile << _final;
	}
	_file.close();
	_outfile.close();
	return (0);
}