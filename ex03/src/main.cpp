/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schouite <schouite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:48:36 by schouite          #+#    #+#             */
/*   Updated: 2026/10/22 10:12:32 by schouite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

void	test(Point const a, Point const b, Point const c, Point const point,
		bool expected, const char *name)
{
	bool	flag;

	flag = bsp(a, b, c, point);
	std::cout << name << " : ";
	if (flag)
		std::cout << "point is IN";
	else
		std::cout << "point is OUT";
	if (flag == expected)
		std::cout << " -> OK";
	else
		std::cout << " -> ERREUR";
	std::cout << std::endl;
}

int	main(void)
{
	// 1. STANDARD : trois droites inclinees
	{
		std::cout << "\n--- STANDARD ---" << std::endl;
		Point a(0, 0);
		Point b(8, 4);
		Point c(4, 8);
		Point point_in(4, 4);
		Point point_out(8, 8);
		Point point_ab(4, 2);
		Point point_bc(6, 6);
		Point point_ac(2, 4);
		Point point_a(0, 0);
		Point point_b(8, 4);
		Point point_c(4, 8);
		test(a, b, c, point_in, true, "Interieur");
		test(a, b, c, point_out, false, "Exterieur");
		test(a, b, c, point_ab, false, "Arete AB");
		test(a, b, c, point_bc, false, "Arete BC");
		test(a, b, c, point_ac, false, "Arete AC");
		test(a, b, c, point_a, false, "Sommet A");
		test(a, b, c, point_b, false, "Sommet B");
		test(a, b, c, point_c, false, "Sommet C");
	}
	// 2. HORIZONTAL : AB est horizontale
	{
		std::cout << "\n--- HORIZONTAL ---" << std::endl;
		Point a(1, 1);
		Point b(7, 1);
		Point c(4, 6);
		Point point_in(4, 3);
		Point point_out(4, 0);
		Point point_edge(4, 1);
		Point point_vertex(1, 1);
		test(a, b, c, point_in, true, "Interieur");
		test(a, b, c, point_out, false, "Exterieur");
		test(a, b, c, point_edge, false, "Arete AB");
		test(a, b, c, point_vertex, false, "Sommet A");
	}
	// 3. VERTICAL : AB est verticale
	{
		std::cout << "\n--- VERTICAL ---" << std::endl;
		Point a(2, 1);
		Point b(2, 7);
		Point c(7, 4);
		Point point_in(4, 4);
		Point point_out(1, 4);
		Point point_edge(2, 4);
		Point point_vertex(2, 7);
		test(a, b, c, point_in, true, "Interieur");
		test(a, b, c, point_out, false, "Exterieur");
		test(a, b, c, point_edge, false, "Arete AB");
		test(a, b, c, point_vertex, false, "Sommet B");
	}
	// 4. TRIANGLE RECTANGLE : horizontal + vertical
	{
		std::cout << "\n--- TRIANGLE RECTANGLE ---" << std::endl;
		Point a(0, 0);
		Point b(6, 0);
		Point c(0, 6);
		Point point_in(2, 2);
		Point point_out(5, 5);
		Point point_ab(2, 0);
		Point point_ac(0, 2);
		Point point_bc(3, 3);
		test(a, b, c, point_in, true, "Interieur");
		test(a, b, c, point_out, false, "Exterieur");
		test(a, b, c, point_ab, false, "Arete horizontale");
		test(a, b, c, point_ac, false, "Arete verticale");
		test(a, b, c, point_bc, false, "Arete inclinee");
	}
	// 5. SENS INVERSE : sommets dans un autre ordre
	{
		std::cout << "\n--- SENS INVERSE ---" << std::endl;
		Point a(0, 0);
		Point b(4, 8);
		Point c(8, 4);
		Point point_in(4, 4);
		Point point_out(8, 8);
		test(a, b, c, point_in, true, "Interieur");
		test(a, b, c, point_out, false, "Exterieur");
	}
	// 6. COORDONNEES NEGATIVES
	{
		std::cout << "\n--- NEGATIF ---" << std::endl;
		Point a(-4, -2);
		Point b(4, -2);
		Point c(0, 6);
		Point point_in(0, 0);
		Point point_out(-5, 0);
		Point point_edge(0, -2);
		Point point_vertex(-4, -2);
		test(a, b, c, point_in, true, "Interieur");
		test(a, b, c, point_out, false, "Exterieur");
		test(a, b, c, point_edge, false, "Arete AB");
		test(a, b, c, point_vertex, false, "Sommet A");
	}
	// 7. COORDONNEES DECIMALES
	{
		std::cout << "\n--- DECIMAL ---" << std::endl;
		Point a(0, 0);
		Point b(4, 2);
		Point c(2, 4);
		Point point_in(1.5f, 1.5f);
		Point point_out(3.5f, 3.5f);
		Point point_edge(1.5f, 0.75f);
		test(a, b, c, point_in, true, "Interieur");
		test(a, b, c, point_out, false, "Exterieur");
		test(a, b, c, point_edge, false, "Arete AB");
	}
	return (0);
}
